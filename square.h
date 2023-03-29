#ifndef SQUARE_H
#define SQUARE_H

using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include "shapeTwoD.h"

class square: public shapeTwoD
{
	private:
		int minX;
		int minY;
		int maxX;
		int maxY;
		double length;
		double breath;
		double area = 0;
		vector<coord>vcS;
		int shapeNum;
	public:
		square();
		square(string, bool);
		double getArea();
		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		void setCoord(coord) override;
		void setMinMax() override;
		bool findCoord(int, int);
		string toString() override;
		void setShapeNum(int) override;
		int getShapeNum() override;
};

#endif
