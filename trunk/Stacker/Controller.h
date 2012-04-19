#pragma once

#include <QString>
#include <QVector>
#include <QMap>

#include "ShapeState.h"
#include "GraphicsLibrary/Mesh/SurfaceMesh/Vector.h"

class QSegMesh;
class Primitive;
class Group;
class EditingSuggestion;

class Controller
{
public:
	Controller(QSegMesh* mesh, bool useAABB = true);
	~Controller();

public:

	// Primitive GET's
	int numPrimitives();
	int numHotPrimitives();
	int getPrimitiveIdNum(QString stringId);
	QVector<QString> stringIds(QVector<int> numericalIds);

	void removePrimitive( Primitive * prim );
	void clearPrimitives();

	Primitive * getPrimitive( QString id );
	Primitive * getPrimitive( uint id );
	Primitive * getSelectedPrimitive();
	QVector<Primitive*> getPrimitives( QVector<QString> ids );
	QVector<Primitive*> getPrimitives( QVector<int> ids );
	QVector<Primitive*> getPrimitives();

	// Fitting
	void fitPrimitives();
	void fitOBBs(bool useAABB = true);	
	void convertToGC( QString primitiveId, bool isUsingSkeleton = true, int cuboidAxis = 0 );
	void convertToCuboid( QString primitiveId, bool useAABB = true, int fit_method = 0);

	// Interaction
	void select(int id);
	void select(QString id);
	bool selectPrimitivePart( int id );
	Vec3d getPrimPartPos();

	// Grouping
	QMap<QString, Group*> groups;
	QVector< Group * > groupsOf( QString id );

	// OpenGL stuff
	void draw();
	void drawNames(bool isDrawParts = false);

	// Shape state
	ShapeState getShapeState();
    void setShapeState( const ShapeState &shapeState );

	// Similarity between two shape state
	double similarity(ShapeState state1, ShapeState state2);
	
	// Flags
	void setSegmentsVisible(bool isVisible = true);
	void setPrimitivesFrozen(bool isFrozen = false);
	void setPrimitivesAvailable(bool isAvailable = true);

	// Distortion
	double volume();
	double originalVolume();
	double getDistortion();

	// Save and load
	void save(std::ofstream &outF);
	void load(std::ifstream &inF);
	
	// Debug items
	std::vector<Point> debugPoints;
	std::vector< std::vector<Point> > debugLines;
	QMap< QString, bool > getFrozenFlags();	

	// Mesh radius
	double meshRadius();

private:

	QSegMesh* m_mesh;

	QMap<QString, Primitive*> primitives;

	Vec3d original_bbmin, original_bbmax;

	QVector<QString> primTypeNames;

	QMap<int, QString> primitiveIdNum;

	void assignIds();
};

