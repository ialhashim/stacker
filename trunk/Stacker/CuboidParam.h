#pragma once
#include <vector>
#include "Vector.h"
#include "PrimativeParam.h"

class CuboidParam : public CloneImpl<CuboidParam, PrimitiveParam>
{
public:
	// Constructor
	CuboidParam();

	// Ranges for each parameter
	void setRanges(std::vector< double > &new_ranges);

	// Step forward along i-th axis in the deformation space
	virtual bool stepForward(int i, double step);

	// Random sample in the deformation space
	void randomSample();

	// Set param directly
	bool setParam(int i, double val);
	bool setParams(std::vector< double > newParams);

	std::vector< double > getDefaulParam();

	virtual int numParams();
	
	// GETs
	Vec3d getT();
	Vec3d getR();
	Vec3d getS();

	// Print
	virtual void print();

private:
	// T(0:2) R(3:5) S(6:8)
	std::vector< double > params;
	std::vector< double > infs;
	std::vector< double > sups;

};