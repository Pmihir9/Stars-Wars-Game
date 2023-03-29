#ifndef CIRCLE_H
#define CIRCLE_H

using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include "shapeTwoD.h"

class circle : public shapeTwoD
{
	private:
	int minX;
	int minY;
	int maxX;
	int maxY;
	const double PI =3.142;
	int radius;
	double area=0;
	coord center;
	int shapeNum;
		
	public:
	circle();
	circle(string,bool);
	circle(const circle&);
	double computeArea() override;
	bool isPointInShape(int,int) override;
	bool isPointOnShape(int,int) override;
	void setCoord(coord) override;
	void setMinMax() override;
	double getArea() override;
	void setRadius(int) override;
	void setShapeNum(int) override;
	int getShapeNum() override;
	string toString() override;
	
};

#endif


























