#include "JointGroup.h"
#include "SimpleDraw.h"
#include "Voxeler.h"


void JointGroup::process( QVector< QString > segments, Vec3d joint )
{
	nodes.clear();

	addNodes(segments);

	// Set the joint position and coordinates in two primitives
	Primitive * a = getPrimitive(segments.first());
	Primitive * b = getPrimitive(segments.last());
	coordinates[segments.first()] = a->getCoordinate(joint);
	coordinates[segments.last()] = b->getCoordinate(joint);

	m_joint = joint;
}

void JointGroup::process( QVector< QString > segments )
{
	nodes.clear();

	addNodes(segments);
	m_joint = Point(0,0,0);
}

void JointGroup::draw()
{
	if(nodes.isEmpty()) return;

	// Show joints
	Primitive * a = getPrimitive(nodes.values().first());
	Primitive * b = getPrimitive(nodes.values().last());

	SimpleDraw::IdentifyPoint( a->fromCoordinate(coordinates[a->id]) );
	SimpleDraw::IdentifyPoint( b->fromCoordinate(coordinates[b->id]) );
}

QVector<QString> JointGroup::regroup()
{
	QVector<QString> result;

	Primitive * frozen = getPrimitive(nodes.values().first());
	Primitive * non_frozen = getPrimitive(nodes.values().last());

	if(frozen->isFrozen == non_frozen->isFrozen)
		return result;

	// Swap if needed
	if(!frozen->isFrozen) 
	{
		Primitive * temp = frozen;
		frozen = non_frozen;
		non_frozen = temp;
	}

	// The joint has been apart, try to join them again
	Vec3d newPos = frozen->fromCoordinate(coordinates[frozen->id]);
	Vec3d oldPos = non_frozen->fromCoordinate(coordinates[non_frozen->id]);
	non_frozen->movePoint(oldPos, newPos - oldPos);
	coordinates[non_frozen->id] = non_frozen->getCoordinate(newPos);

	// Fixed the joint
	non_frozen->addFixedPoint(newPos);
	result.push_back(non_frozen->id);

	return result;
}

void JointGroup::save( std::ofstream &outF )
{
	Group::save(outF);

	outF << m_joint;
}
