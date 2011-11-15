#pragma once

#include "Vector.h"
#include <vector>
#define StdVector std::vector

class SimpleDraw
{
public:

	// POINTS
	static void IdentifyPoint(const Vec3d& p, float r = 1.0, float g = 0.2f, float b = 0.2f, float pointSize = 10.0);
	static void IdentifyPoint2(Vec3d p);
	static void IdentifyPoints(StdVector<Vec3d> & points, float r = 1.0, float g = 0.2f, float b = 0.2f, float pointSize = 10.0);
	static void IdentifyConnectedPoints(StdVector<Vec3d> & points, float r = 0.4f, float g = 1.0, float b = 0.2f);
	static void IdentifyConnectedPoints2(StdVector<Vec3d> & points, float r = 0.4f, float g = 1.0, float b = 0.2f );

	// LINES
	static void IdentifyLine(const Vec3d& p1, const Vec3d& p2, bool showPoints = true);
	static void IdentifyLineRed(const Vec3d& p1, const Vec3d& p2, bool showPoints = true);
	static void IdentifyLine(const Vec3d& p1, const Vec3d& p2, float r, float g, float b, bool showPoints = true, float lineWidth = 3.0f);
	//static void IdentifyLines(StdVector<Line> & lines, float lineWidth = 1.0, float r = 1.0, float g = 0.6f, float b = 0);

	// Primitives
	static void DrawCube(const Vec3d& center, float length = 1.0);
	static void DrawSphere(const Vec3d& center, float radius = 1.0);
	static void DrawCylinder(const Vec3d& center, const Vec3d& direction = Vec3d(0,0,1), float height = 1.0, float radius = 1.0, float radius2 = -1);

	static void DrawBox(const Vec3d& center, float width, float length, float height, float r = 0, float g = 1.0, float b = 0);
	static void DrawSolidBox(const Vec3d& center, float width, float length, float height, float r = 0, float g = 1.0, float b = 0, float a = 1.0);
	static void DrawTriangle(const Vec3d& v1, const Vec3d& v2, const Vec3d& v3,float r = 0.2f, float g = 1.0, float b = 0.1f, float a = 1.0, bool isOpaque = true);
	static void DrawTriangles(const StdVector< StdVector<Vec3d> > & tris, float r = 0.2f, float g = 1.0, float b = 0.1f, float a = 1.0, bool isOpaque = true, bool isDrawPoints = true);

	static void DrawSquare(const Vec3d& v1, const Vec3d& v2, const Vec3d& v3, const Vec3d& v4, bool isOpaque = true, float r = 0.1f, float g = 0.2f, float b = 1.0, float a = 1.0);
	static void DrawSquares(const StdVector<StdVector<Vec3d> > & squares, bool isOpaque = true, float r = 0.1f, float g = 0.2f, float b = 1.0, float a = 1.0);
	static void DrawLineTick(const StdVector<Vec3d>& start, const  StdVector<Vec3d>& direction, float len = 0.25f, bool border = false, float r = 0.65f, float g = 0.6f, float b = 0.8f, float a = 0.9f);

	// ARROWS
	static void IdentifyArrow(const Vec3d& start, const Vec3d& end, float lineWidth = 2.0, float r = 1.0, float g = 0.2f, float b = 0.2f);
	static void IdentifyArrows(StdVector<Vec3d> & starts, StdVector<Vec3d> & ends, float lineWidth = 2.0, float r = 1.0, float g = 0.2f, float b = 0.2f);

	static void DrawArrow(Vec3d from, Vec3d to, bool isForward = true, bool isFilledBase = true);
	static void DrawArrowDirected(const Vec3d& pos, const Vec3d& normal, float height = 1.0, bool isForward = true, bool isFilledBase = true);
	static void DrawArrowDoubleDirected(const Vec3d& pos, const Vec3d& normal, float height = 1.0, bool isForward = true, bool isFilledBase = true);

	static void PointArrowAt(Vec3d point, float radius = 1.0);
	static void DrawBarChart(const StdVector<double> & data, int x, int y, double height = 100.0, double width = 300, int barWidth = 1.0);
	
	// Misc.
	static void drawCornerAxis(const double * cameraOrientation);

	static std::vector<Vec4d> RandomColors(int count);

};