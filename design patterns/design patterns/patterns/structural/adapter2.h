// Adapter \ Wrapper 
#pragma once
#include <iostream>

typedef int Coordinate;
typedef int Demension;
	
class Rectangle
{
public:
	virtual void draw() = 0;
};

class LegacyRectangle
{
public:
	LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2)
	{
		x1_ = x1;
		x2_ = x2;
		y1_ = y1;
		y2_ = y2;

		std::cout << "LegacyRectangle::ctor\n"
			"(" << x1_ << ", " << y1_ << ") => (" << x2_ << ", " << y2_ << ")\n";
	}

	void oldDraw()
	{
		std::cout << "LegacyRectangle::oldDraw()\n"
			"(" << x1_ << ", " << y1_ << ") => (" << x2_ << ", " << y2_ << ")\n";
	}

private:
	Coordinate x1_;
	Coordinate x2_;
	Coordinate y1_;
	Coordinate y2_;
};

class RectangleAdapter : public Rectangle, private LegacyRectangle
{
public:
	RectangleAdapter(Coordinate x, Coordinate y, Demension w, Demension h) : LegacyRectangle(x, y, x + w, y + h)
	{
		std::cout << "RectangleAdapter::ctor\n"
			"(" << x << ", " << y << "), width = " << w << ", height = " << h << "\n";
	}

	virtual void draw()
	{
		std::cout << "RectangleAdapter::draw()\n";
		oldDraw();
	}
};