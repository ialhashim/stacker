#pragma once
#include <vector>
#include <QVector>
#include <QString>
#include "Group.h"

class Primitive;

class JointGroup : public Group{
public:
	JointGroup(Controller * controller, GroupType newType) : Group(controller, newType){}

	void process(QVector< QString > segments){}

	void process(QVector< QString > segments, Vec3d joint);

	void draw();	

	Vec3d jointPos;
	QVector<std::vector<double>> coordinates;
};
