
#include <iostream>
#include <string>
#include <vector>
#include "MyPainter2D.h"
#include <list>

MyPainter2D Obj_2D;

class GeomericObject {
public:

	int a_;
	int center_x = 275, center_y = 150;
	int r_radius = 60;
	int center_x_ = 75, center_y_ = 375;
	int x_edge = 50, y_edge = 50;

	void(GeomericObject::*callback_)(void) = 0;
	void exe()
	{
		(this->*callback_)();
	}

	void drawCircle()
	{
		std::cout << "Draw Circle" << a_ << std::endl;
		for (int a = 0; a <= 2 * r_radius; a++)
		{
			for (int b = 0; b <= 2 * r_radius; b++)
			{
				int f = (r_radius - b)*(r_radius - b) + (r_radius - a)*(r_radius - a) - r_radius*r_radius;
				if (f < 0 && -200 < f)
				{
					Obj_2D.drawPixel(center_x - r_radius + b, center_y - r_radius + a, 0.0f, 0.0f, 0.0f);
				}
			}
		}
	}

	void drawBox()
	{
		std::cout << "Draw Box" << a_ << std::endl;
		Obj_2D.drawLine(center_x_ - x_edge / 2, center_y_ - y_edge / 2, center_x_ + x_edge / 2, center_y_ - y_edge / 2, 0.0f, 0.0f, 0.0f);
		Obj_2D.drawLine(center_x_ + x_edge / 2, center_y_ - y_edge / 2, center_x_ + x_edge / 2, center_y_ + y_edge / 2, 0.0f, 0.0f, 0.0f);
		Obj_2D.drawLine(center_x_ - x_edge / 2, center_y_ + y_edge / 2, center_x_ + x_edge / 2, center_y_ + y_edge / 2, 0.0f, 0.0f, 0.0f);
		Obj_2D.drawLine(center_x_ - x_edge / 2, center_y_ - y_edge / 2, center_x_ - x_edge / 2, center_y_ + y_edge / 2, 0.0f, 0.0f, 0.0f);
	}

};

int main() {

	Obj_2D.initialize();

	while (Obj_2D.Close())
	{
		Obj_2D.preprocessing();

		GeomericObject my_box1, my_box3, my_box2, my_circle2;

		my_box1.center_x_ = 275;
		my_box1.center_y_ = 375;
		my_box1.x_edge = 70;
		my_box1.y_edge = 70;
		my_box1.callback_ = &GeomericObject::drawBox;

		my_box2.center_x_ = 275;
		my_box2.center_y_ = 375;
		my_box2.x_edge = 50;
		my_box2.y_edge = 50;
		my_box2.callback_ = &GeomericObject::drawBox;


		my_box3.center_x_ = 275;
		my_box3.center_y_ = 150;
		my_box3.x_edge = 50;
		my_box3.y_edge = 50;
		my_box3.callback_ = &GeomericObject::drawBox;

		my_circle2.center_x = 275;
		my_circle2.center_y = 150;
		my_circle2.r_radius = 60;
		my_circle2.callback_ = &GeomericObject::drawCircle;

		my_box1.exe();
		my_box2.exe();
		my_box3.exe();
		my_circle2.exe();

		Obj_2D.postprocessiong();
	}
	return 0;
}