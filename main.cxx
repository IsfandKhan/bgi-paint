// File: eyes.cpp
// Written by Grant Macklem
//      Grant.Macklem@Colorado.EDU
//              2:00 PM Recitation
// Last modified Nov 22, 1998
// Flicker-free eyes!

/*******************************************************************************
* eyes.exe  Flicker-free, mouse-following, customizably-colored eyes.
* Copyright (C) 1998 Grant Macklem
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
* You may contact me, the author by emailing Grant.Macklem@Colorado.EDU
*******************************************************************************/
#include <vector>
#include "graphics.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>                     // Provides exit
#include <ctype.h>                      // Provides toupper
using namespace std;





struct point
{
	int x;
	int y;
};

class Shape
{
protected:
	vector <point> pts;
	int id;
	int rad;
	point p;
	
public:
	virtual void draw() = 0;
	virtual void drawFor() = 0;
	virtual void drawBack() = 0;
	virtual void drawDown() = 0;
	virtual void drawUp() = 0;

	
	int getID()
	{
		return id;
	}
	friend ostream& operator << (ostream& out, Shape& obj);


};





class Circle : public Shape
{
public:
	void draw()
	{
		//(15);
		fillellipse(pts[0].x, pts[0].y, rad,rad);
	}

	void drawDown()
	{
		
		pts[0].y++;
		//(15);
		fillellipse(pts[0].x, pts[0].y, rad, rad);


	}
	void drawUp()
	{
		pts[0].y--;
		//(15);
		fillellipse(pts[0].x, pts[0].y, rad, rad);


	}



	void drawFor(){
		pts[0].x++;
		//(15);
		fillellipse(pts[0].x, pts[0].y, rad, rad);


	}
	void drawBack()
	{
	
		pts[0].x--;
		//(15);
		fillellipse(pts[0].x, pts[0].y, rad, rad);


	}
	Circle(point p, int radi)
	{
		pts.push_back(p);
		rad = radi;
		draw();
		id = 1;
	}

	
};
class triangle :public Shape
{
public:
	triangle(vector <point> p)
	{
		id = 2;
		pts = p;
		draw();
	}

	void drawDown()
	{


		pts[0].y++;
		pts[1].y++;
		pts[2].y++;

		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[2].x, pts[2].y);
		line(pts[2].x, pts[2].y, pts[0].x, pts[0].y);


	}
	void drawUp()
	{

		pts[0].y--;
		pts[1].y--;
		pts[2].y--;

		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[2].x, pts[2].y);
		line(pts[2].x, pts[2].y, pts[0].x, pts[0].y);


	}

	void draw()
	{
		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[2].x, pts[2].y);
		line(pts[2].x, pts[2].y, pts[0].x, pts[0].y );
	}
	void drawFor(){

		pts[0].x++;
		pts[1].x++;
		pts[2].x++;

		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[2].x, pts[2].y);
		line(pts[2].x, pts[2].y, pts[0].x, pts[0].y);


	}
	void drawBack()
	{

		pts[0].x--;
		pts[1].x--;
		pts[2].x--;

		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[2].x, pts[2].y);
		line(pts[2].x, pts[2].y, pts[0].x, pts[0].y);

		
	}
	

};



class Line : public Shape
{
public:

	void draw()
	{
		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);


	}
	void drawDown()
	{

		pts[0].y++;
		pts[1].y++;

		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);



	}
	void drawUp()
	{
		pts[0].y--;
		pts[1].y--;

		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);


	}

	void drawFor()
	{
		pts[0].x++;
		pts[1].x++;
		
		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);


	}
	void drawBack()
	{

		pts[0].x--;
		pts[1].x--;

		line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);


	}
	Line(vector<point> p)
	{
		id = 3;
		pts = p;
		draw();
	}
	

};


class Rectangles :public Shape
{

public:
	Rectangles(vector <point> p)
	{
		pts = p;
		id = 4;
		draw();
	}

	void drawFor(){

		
		pts[0].x++;

		pts[1].x++;
		line(pts[0].x, pts[0].y, pts[1].x, pts[0].y);
		line(pts[0].x, pts[0].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[1].x, pts[0].y);



	}


	void drawDown()
	{

		pts[0].y++;

		pts[1].y++;
		line(pts[0].x, pts[0].y, pts[1].x, pts[0].y);
		line(pts[0].x, pts[0].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[1].x, pts[0].y);


	}
	void drawUp()
	{
		pts[0].y--;

		pts[1].y--;
		line(pts[0].x, pts[0].y, pts[1].x, pts[0].y);
		line(pts[0].x, pts[0].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[1].x, pts[0].y);




	}


	void drawBack()
	{
		pts[0].x--;

		pts[1].x--;
		line(pts[0].x, pts[0].y, pts[1].x, pts[0].y);
		line(pts[0].x, pts[0].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[1].x, pts[0].y);


	

	}
	void draw()
	{
		line(pts[0].x, pts[0].y, pts[1].x, pts[0].y);
		line(pts[0].x, pts[0].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[0].x, pts[1].y);
		line(pts[1].x, pts[1].y, pts[1].x, pts[0].y);

	}
	


};

class Point1 :public Shape
{

public:
	Point1(point p)
	{
		id = 5;
		pts.push_back(p);
		draw();
	}

	void drawDown()
	{
		pts[0].y++;
		int poly[8];

		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[0].x + 5;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[0].x + 5;             /* first vertex */

		poly[5] = pts[0].y + 5;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[0].y + 5;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);







	}
	void drawUp()
	{
		pts[0].y--;
		int poly[8];

		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[0].x + 5;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[0].x + 5;             /* first vertex */

		poly[5] = pts[0].y + 5;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[0].y + 5;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);





	}


	void drawFor(){


		pts[0].x++;
		int poly[8];

		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[0].x + 5;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[0].x + 5;             /* first vertex */

		poly[5] = pts[0].y + 5;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[0].y + 5;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);




	}

	void draw()
	{
	
		/* our polygon array */

		int poly[8];



		/* initialize graphics and local variables */






		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[0].x+5;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[0].x + 5;             /* first vertex */

		poly[5] = pts[0].y+5;

		poly[6] = pts[0].x ;             /* first vertex */

		poly[7] = pts[0].y + 5;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);

		
	}
	void drawBack()
	{
		

		pts[0].x--;
		int poly[8];

		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[0].x + 5;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[0].x + 5;             /* first vertex */

		poly[5] = pts[0].y + 5;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[0].y + 5;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);





	}
	

};


class FilledRectangles :public Shape
{

public:
	FilledRectangles(vector <point> p)
	{
		pts = p;
		id = 6;
		draw();
	}
	void drawDown()
	{
		int poly[8];



		/* initialize graphics and local variables */


		pts[0].y++;
		pts[1].y++;


		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[1].x;             /* first vertex */

		poly[5] = pts[1].y;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[1].y;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);





	}
	void drawUp()
	{
		int poly[8];



		/* initialize graphics and local variables */


		pts[0].y--;
		pts[1].y--;


		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[1].x;             /* first vertex */

		poly[5] = pts[1].y;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[1].y;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);




	}


	void drawBack()
	{
		int poly[8];



		/* initialize graphics and local variables */


		pts[0].x--;
		pts[1].x--;


		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[1].x;             /* first vertex */

		poly[5] = pts[1].y;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[1].y;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);






	}
	void draw()
	{

		int poly[8];



		/* initialize graphics and local variables */





		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x ;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[1].x ;             /* first vertex */

		poly[5] = pts[1].y ;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[1].y ;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);




		
	}
	void drawFor()
	{

		int poly[8];



		/* initialize graphics and local variables */


		pts[0].x++;
		pts[1].x++;


		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[0].y;

		poly[4] = pts[1].x;             /* first vertex */

		poly[5] = pts[1].y;

		poly[6] = pts[0].x;             /* first vertex */

		poly[7] = pts[1].y;




		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(4, poly);





	}



};

class FilledTriangles :public Shape
{

public:
	FilledTriangles(vector <point> p)
	{
		pts = p;
		id = 7;
		draw();
	}
	
	
	void drawDown()
	{
		int poly[6];



		/* initialize graphics and local variables */



		pts[0].y++;

		pts[1].y++;
		pts[2].y++;


		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[1].y;

		poly[4] = pts[2].x;             /* first vertex */

		poly[5] = pts[2].y;





		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(3, poly);









	}
	void drawUp()
	{
		int poly[6];



		/* initialize graphics and local variables */



		pts[0].y--;

		pts[1].y--;
		pts[2].y--;


		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[1].y;

		poly[4] = pts[2].x;             /* first vertex */

		poly[5] = pts[2].y;





		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(3, poly);







	}


	
	void drawBack()
	{
	
		int poly[6];



		/* initialize graphics and local variables */



		pts[0].x--;

		pts[1].x--;
		pts[2].x--;


		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[1].y;

		poly[4] = pts[2].x;             /* first vertex */

		poly[5] = pts[2].y;





		/* loop through the fill patterns */


		//(15);

		/* draw a filled polygon */

		fillpoly(3, poly);









	}

	void drawFor()
	{

		int poly[6];



		/* initialize graphics and local variables */



		pts[0].x++;

		pts[1].x++;
		pts[2].x++;


		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[1].y;

		poly[4] = pts[2].x;             /* first vertex */

		poly[5] = pts[2].y;





		/* loop through the fill patterns */


		
		/* draw a filled polygon */

		fillpoly(3, poly);





	}

	void draw()
	{

		int poly[6];



		/* initialize graphics and local variables */





		poly[0] = pts[0].x;             /* first vertex */

		poly[1] = pts[0].y;

		poly[2] = pts[1].x;      /* second vertex */

		poly[3] = pts[1].y;

		poly[4] = pts[2].x;             /* first vertex */

		poly[5] = pts[2].y;

		



		/* loop through the fill patterns */


		/* draw a filled polygon */

		fillpoly(3, poly);





	}
	


};






















const double XBORDER = 150.0;                                                   // X-border of the screen, cartesian
const double YBORDER = 112.5;                                                   // Y-border of the screen, cartesian

const double X_RAD = 2 * XBORDER / 10.0;                        // Width of eye ellipse, cartesian
const double Y_RAD = 2 * YBORDER / 12;                  // Height of eye, cartesian

const double LEFT_X = -1.5 * X_RAD;                     // X Coordinate of left eye, cartesian
const double LEFT_Y = 0;                                                // Y Coordinate of right eye, cartesian
const double RIGHT_X = 1.5 * X_RAD;                     // X Coordinate of left eye, cartesian
const double RIGHT_Y = 0;                                               // Y Coordinate of right eye, cartesian

const double I_RADIUS = X_RAD / 2.8;                                    // Radius of iris in cartesian
const double P_RADIUS = X_RAD / 10;                                             // Radius of pupil, cartesian

// Draws the new irises
void draw_iris(int x, int y);

int ytranslate
        (double y,                                              // Cartesian Coordinate to be translated into pixles
    double yborder);                            // Top and bottom Cartesian coordinate of the screen

int xtranslate
        (double x,                                              // Cartesian Coordinate to be translated into pixles
    double xborder);                            // Left and right Cartesian coordinate of the screen


// Draws the eye initially
void draw_eyes();
void change_left_color(int x, int y);
void change_right_color(int x, int y);
void check_keys(vector<Shape*>&shapes,bool show,int number,bool lock);

// Checks to see if the line from the ellipse center to the mouse is vertical
bool check_vertical
        (int x,                                                 // x location of the mouse
    int y,                                                      // y location of the mouse
    int x1,                                                     // x coordinate of ellipse center
    int y1,                                                     // y coordinate of ellispe center
    double& x_intersect,                        // Return value where iris x-intersects smaller ellipse
    double& y_intersect,                        // Return value where iris y-intersects smaller ellipse
    int small_ellipse_x_radius, // x coord of ellipse of center of iris an pupil
    int small_ellipse_y_radius);// y coord of ellipse of center of iris an pupil

// Returns the radius of the eyes in pixel coordinates
void get_radius_eyes(int& tx_rad, int& ty_rad);

void update_graphics
        (int left_x_intersect,          // x intersection of left iris and pupil
    int left_y_intersect,               // y intersection of left iris and pupil
    int right_x_intersect,              // x intersection of right iris and pupil
    int right_y_intersect,              // y intersection of right iris and pupil
    int ti_rad,                                 // Radius, in pixels, of iris
    int tp_rad,                                 // radius, in pixels, of pupil
    int& t);                                            // Graphics page

void get_radius_iris_pupil
        (int& ti_rad,                                   // Radius of iris, in pixels
    int& tp_rad);                                       // Radius of pupil, in pixels

void find_coordinates
        (int x,                                                 // x location of the mouse
    int y,                                                      // y location of the mouse
    int x1,                                                     // x coordinate of ellipse center
    int y1,                                                     // y coordinate of ellispe center
    double& x_intersect,                        // Return value where iris x-intersects smaller ellipse
    double& y_intersect,                        // Return value where iris y-intersects smaller ellipse
    int small_ellipse_x_radius, // x coord of ellipse of center of iris an pupil
    int small_ellipse_y_radius);// y coord of ellipse of center of iris an pupil


int left_color = GREEN;
int right_color = GREEN;









void outintxy(int x, int y, int value)

{

	char digit_string[20];

	sprintf(digit_string, "%d", value);

	outtextxy(x, y, digit_string);

}

void drawCanvas(bool lock){
	cleardevice();
	setcolor(YELLOW);
	
	point p;
	p.x = 0;
	p.y = 0;


	point p2;
	p2.x = 5000;
	p2.y = 5000;

	point p3;
	p3.x = 80;
	p3.y = 100;

	vector<point>points;
	points.push_back(p);

	points.push_back(p2);

	setfillstyle(1, GREEN);

	FilledRectangles fil1(points);

	line(100, 0, 100, 15000);//separator

	points.clear();

	p.x = 0;
	p.y = 30;

	points.push_back(p);

	p.x = 100;
	p.y = 400;

	points.push_back(p);

	setfillstyle(1, LIGHTCYAN);
	FilledRectangles*filr = new FilledRectangles(points);
	
	points.clear();
	



	p.x = 40;
	p.y = 40;


	p2.x = 40;
	p2.y = 100;

	p3.x = 80;
	p3.y = 100;

	points.push_back(p);

	points.push_back(p2);

	points.push_back(p3);
	
	triangle triangles(points);
	line(00, 120, 100, 120);//separator


	rectangle(30, 150, 90, 200);


	line(00, 220, 100, 220);//separator


	line(30, 250, 90, 300);


	line(00, 320, 100, 320);//separator
	p.x = 50;
	p.y = 350;

	setfillstyle(1, YELLOW);
	Point1 p1(p);


	line(100, 90, 10000, 90);//separator
	
	

	if (lock)
	{
		points.clear();


		p.x = 100;
		p.y = 0;

		points.push_back(p);

		p.x = 510;
		p.y = 90;

		points.push_back(p);

		setfillstyle(1, LIGHTCYAN);
		FilledRectangles*filled = new FilledRectangles(points);




		points.clear();


		setfillstyle(1, YELLOW);

		p.x = 150;
		p.y = 40;

		Circle cir(p, 30);

		line(200, 0, 200, 90); //separator
		p.x = 230;
		p.y = 20;

		p2.x = 280;
		p2.y = 70;
		points.clear();
		points.push_back(p);
		points.push_back(p2);

		FilledRectangles fil(points);


		line(300, 0, 300, 90); //separator

		p.x = 350;
		p.y = 20;

		p2.x = 320;
		p2.y = 70;


		p3.x = 380;
		p3.y = 70;

		points.clear();
		points.push_back(p);
		points.push_back(p2);
		points.push_back(p3);
		FilledTriangles filo(points);

		line(400, 0, 400, 90); //separator

		setlinestyle(1, 1, 1);//setting to dotted line




		line(420, 20, 500, 20);


		line(420, 40, 500, 40);

		line(420, 60, 500, 60);







		setlinestyle(0, 1, 1);//resetting to solid line
	}
}
void drawCanvas1(bool lock){
	setcolor(YELLOW);

	point p;
	p.x = 0;
	p.y = 0;


	point p2;
	p2.x = 5000;
	p2.y = 5000;

	point p3;
	p3.x = 80;
	p3.y = 100;

	vector<point>points;
	points.push_back(p);

	points.push_back(p2);

	setfillstyle(1, GREEN);

	FilledRectangles fil1(points);

	line(100, 0, 100, 15000);//separator

	points.clear();

	p.x = 0;
	p.y = 30;

	points.push_back(p);

	p.x = 100;
	p.y = 400;

	points.push_back(p);

	setfillstyle(1, LIGHTCYAN);
	FilledRectangles*filr = new FilledRectangles(points);

	points.clear();




	p.x = 40;
	p.y = 40;


	p2.x = 40;
	p2.y = 100;

	p3.x = 80;
	p3.y = 100;

	points.push_back(p);

	points.push_back(p2);

	points.push_back(p3);

	triangle triangles(points);
	line(00, 120, 100, 120);//separator


	rectangle(30, 150, 90, 200);


	line(00, 220, 100, 220);//separator


	line(30, 250, 90, 300);


	line(00, 320, 100, 320);//separator
	p.x = 50;
	p.y = 350;

	setfillstyle(1, YELLOW);
	Point1 p1(p);


	line(100, 90, 10000, 90);//separator



	if (lock)
	{
		points.clear();

		p.x = 100;
		p.y = 0;

		points.push_back(p);

		p.x = 510;
		p.y = 90;

		points.push_back(p);

		setfillstyle(1, LIGHTCYAN);
		FilledRectangles*fils = new FilledRectangles(points);




		points.clear();



		setfillstyle(1, YELLOW);


		p.x = 150;
		p.y = 40;

		Circle cir(p, 30);

		line(200, 0, 200, 90); //separator
		p.x = 230;
		p.y = 20;

		p2.x = 280;
		p2.y = 70;
		points.clear();
		points.push_back(p);
		points.push_back(p2);

		FilledRectangles fil(points);


		line(300, 0, 300, 90); //separator

		p.x = 350;
		p.y = 20;

		p2.x = 320;
		p2.y = 70;


		p3.x = 380;
		p3.y = 70;

		points.clear();
		points.push_back(p);
		points.push_back(p2);
		points.push_back(p3);
		FilledTriangles filo(points);

		line(400, 0, 400, 90); //separator

		setlinestyle(1, 1, 1);//setting to dotted line




		line(420, 20, 500, 20);


		line(420, 40, 500, 40);

		line(420, 60, 500, 60);







		setlinestyle(0, 1, 1);//resetting to solid line
	}
}




void showGridLines(bool lock){
	cleardevice();
	






	drawCanvas1(lock);
	setlinestyle(1, 1, 1);//setting to dotted line


	line(200, 90, 200, 10000);

	line(300, 90, 300, 10000);

	line(400, 90, 400, 10000);

	line(500, 90, 500, 10000);

	line(600, 90, 600, 10000);



	line(100, 190, 10000, 190);

	line(100, 290, 10000, 290);

	line(100, 390, 10000, 390);

	line(100, 490, 10000, 490);

	line(100, 590, 10000, 590);


	setlinestyle(0, 1, 1);//resetting to solid line

	
}




void waitForMouse(point& p, vector<point>& points ){

	while (!ismouseclick(WM_LBUTTONUP));

	p.x = mousex();
	p.y = mousey();
	if (p.x < 100)
	{
		p.x = 110;
	}
	if (p.y < 90)
	{
		p.y = 100;
	}
	points.push_back(p);


	clearmouseclick(WM_LBUTTONUP);


}
void waitForMouseCircle(point& p, vector<point>& points){

	while (!ismouseclick(WM_LBUTTONUP));

	p.x = mousex();
	p.y = mousey();
	if (p.x < 100)
	{
		p.x = p.x+150;
	}
	if (p.y < 90)
	{
		p.y = p.y+180;
	}
	points.push_back(p);


	clearmouseclick(WM_LBUTTONUP);


}


int APIENTRY WinMain
( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

        cout << "Moving Eyes, Copyright (C) 1998 Grant Macklem.\n" << endl;
   cout << "Press 'Q' to quit" << endl;

   initwindow(601, 451);
   //line(22, 33, 89, 33);


   vector<point>points;
   point p;
   vector<Shape*>shapes;
   //shapes.push_back(new Circle(p, 10, 10));
   //shapes.push_back(new triangle(points, 10));
   
   
 //  shapes.push_back(new Line(points, 10,10));

   //shapes.push_back(new Rectangles(points,10));


   /* request autodetection */

  
   



   /* clean up */

   int number = -1;
   bool showGrid = false;
   int x;
   int y;
   bool lock=false;
   drawCanvas(lock);

   for (;;){


	   if (ismouseclick(WM_RBUTTONUP))
	   {

		   if (!lock)
			   lock = true;
		   else
			   lock = false;

		   if (showGrid)
			   showGridLines(lock);
		   else
		   drawCanvas(lock);


		   for (int i = 0; i < shapes.size(); i++)
		   {
			   shapes[i]->draw();
		   }
		   clearmouseclick(WM_RBUTTONUP);



	   }
	   else if (ismouseclick(WM_LBUTTONUP))
	   {
		   x = mousex();
		   y = mousey();


		   clearmouseclick(WM_LBUTTONUP);

		   if (x >= 0 && x <= 100 && y < 120)
		   {
			   //clearmouseclick();
	
			   waitForMouse(p,points);

	
	
			   waitForMouse(p, points);




			   waitForMouse(p, points);







			   shapes.push_back(new triangle(points));

			   points.clear();
			   

			   

		   }

		   else if (x >= 0 && x <= 100 && y > 120 && y < 220)
		   {

			   //clearmouseclick();
			   //while (ismouseclick(WM_LBUTTONDOWN));


			   waitForMouse(p, points);

			   waitForMouse(p, points);


			   shapes.push_back(new Rectangles(points));

			   points.clear();


			   

		   }

		   else if (x >= 0 && x <= 100 && y > 220 && y < 320)
		   {
			   //while (ismouseclick(WM_LBUTTONDOWN));
			   waitForMouse(p, points);

			   waitForMouse(p, points);

			   shapes.push_back(new Line(points));

			   points.clear();

			   

			   

		   }
		   else if (x >= 0 && x <= 100 && y > 320 && y<400 )
		   {
	
			   while (!ismouseclick(WM_LBUTTONUP));

			   p.x = mousex();
			   p.y = mousey();

			   if (p.x <= 100)
			   {
				   p.x = 120;
			   }
			   if (p.y <= 90)
			   {
				   p.y = 120;
			   }


			   clearmouseclick(WM_LBUTTONUP);

			   shapes.push_back(new Point1(p));




			   

		   }
		   if (lock)
		   {

		   if (x > 100 && x < 200 && y > 0 && y < 90)
		   {

			   waitForMouseCircle(p, points);

			   waitForMouseCircle(p, points);



			   int rad = (points[1].x - points[0].x) + (points[1].y - points[0].y);

			   if (p.x - rad <= 100)
			   {
				   rad = rad - 100;

				   p.x = p.x*p.x - 100;
			   }
			   if (p.y - rad <= 90)
			   {
				   rad = rad - 90;
				   p.y = p.y*p.y - 100;
			   }
			   if (p.x + rad <= 100)
			   {
				   rad = rad - 100;

				   p.x = p.x*p.x - 100;
			   }
			   if (p.y + rad <= 90)
			   {
				   rad = rad - 90;
				   p.y = p.y*p.y - 100;
			   }

			   shapes.push_back(new Circle(p, rad));
			   points.clear();


		   }
		   else if (x > 200 && x < 300 && y > 0 && y < 90)
		   {

			   waitForMouse(p, points);

			   waitForMouse(p, points);





			   shapes.push_back(new FilledRectangles(points));
			   points.clear();


		   }
		   else if (x > 300 && x < 400 && y > 0 && y < 90)
		   {

			   waitForMouse(p, points);

			   waitForMouse(p, points);

			   waitForMouse(p, points);




			   shapes.push_back(new FilledTriangles(points));
			   points.clear();


		   }
		   else if (x > 400 && x < 510 && y > 0 && y < 90)
		   {

			   if (!showGrid)
			   {
				   showGridLines(lock);

				   for (int i = 0; i < shapes.size(); i++)
				   {
					   shapes[i]->draw();
				   }
				   showGrid = true;
			   }
			   else
			   {
				   drawCanvas(lock);

				   for (int i = 0; i < shapes.size(); i++)
				   {
					   shapes[i]->draw();
				   }
				   showGrid = false;
			   }
		   }


		   }
			
	   }
	   check_keys(shapes,showGrid,number,lock);
   }

}

void draw_eyes()
{
   int x1 = xtranslate(LEFT_X, XBORDER);
   int y1 = ytranslate(LEFT_Y, YBORDER);
   int x2 = xtranslate(RIGHT_X, XBORDER);
   int y2 = ytranslate(RIGHT_Y, YBORDER);
   int tx_rad = xtranslate(X_RAD, XBORDER) - xtranslate(0, XBORDER);
   int ty_rad = ytranslate(Y_RAD, YBORDER) - ytranslate(0, YBORDER);

        //(WHITE);
        fillellipse (x1, y1, tx_rad, ty_rad);
   fillellipse (x2, y2, tx_rad, ty_rad);
}

void change_left_color(int x, int y)
{
        left_color ++;                  // Increase color by one
        left_color %= 15;                       // Don't allow white as iris color, since that is eye
                                                                // color.  Also makes sure color is between 0 and 15.
        draw_iris(mousex(),mousey());
}

void change_right_color(int x, int y)
{
        right_color ++;                         // Increase color by one
        right_color %= 15;              // Don't allow white as iris color, since that is eye
                                                                // color.  Also makes sure color is between 0 and 15.
        draw_iris(mousex(),mousey());
}

void draw_iris(int x, int y)
{
   int tx_rad, ty_rad, ti_rad, tp_rad;
   static int t = 0;            // Graphics screen
   // The following are in pixel coordinates of the iris ellipse
   double small_ellipse_x_radius;
   double small_ellipse_y_radius;

        // Center of each eye in pixel coordinates.
   int x1 = xtranslate(LEFT_X, XBORDER);
   int y1 = ytranslate(LEFT_Y, YBORDER);
   int x2 = xtranslate(RIGHT_X, XBORDER);
   int y2 = ytranslate(RIGHT_Y, YBORDER);
        // These variables tell where the line from the center of the eye to the mouse
   // intersects the smaller ellipse (where to draw the iris)
   double left_x_intersect, left_y_intersect, right_x_intersect, right_y_intersect;

   get_radius_eyes(tx_rad, ty_rad);
   get_radius_iris_pupil(ti_rad, tp_rad);

        small_ellipse_x_radius = tx_rad - ti_rad;
        small_ellipse_y_radius = ty_rad - ti_rad;

        // Left Iris
        find_coordinates(x, y, x1, y1, left_x_intersect, left_y_intersect,
        small_ellipse_x_radius, small_ellipse_y_radius);
   // Right Iris
        find_coordinates(x, y, x2, y2, right_x_intersect, right_y_intersect,
        small_ellipse_x_radius, small_ellipse_y_radius);

   update_graphics(left_x_intersect, left_y_intersect, right_x_intersect,
                                         right_y_intersect, ti_rad, tp_rad, t);

}


// Checks to see if the line from the ellipse center to the mouse is vertical
bool check_vertical
        (int x,                                                 // x location of the mouse
    int y,                                                      // y location of the mouse
    int x1,                                                     // x coordinate of ellipse center
    int y1,                                                     // y coordinate of ellispe center
    double& x_intersect,                        // Return value where iris x-intersects smaller ellipse
    double& y_intersect,                        // Return value where iris y-intersects smaller ellipse
    int small_ellipse_y_radius) // y coord of ellipse of center of iris an pupil
{
        // Center of each eye in pixel coordinates.
        if (x == x1)
   {
      x_intersect = x;

                if (abs(y1 - y) >= small_ellipse_y_radius)
      { // Point1er is outside the eye
        if ((y1 - y) > 0)
                y_intersect = y1 - small_ellipse_y_radius;
         else
                y_intersect = y1 + small_ellipse_y_radius;
      }
      else      // Point1er is in the eye
        y_intersect = y;

      return true;
   }
   return false;
}

void find_coordinates
        (int x,                                                 // x location of the mouse
    int y,                                                      // y location of the mouse
    int x1,                                                     // x coordinate of ellipse center
    int y1,                                                     // y coordinate of ellispe center
    double& x_intersect,                        // Return value where iris x-intersects smaller ellipse
    double& y_intersect,                        // Return value where iris y-intersects smaller ellipse
    int small_ellipse_x_radius, // x coord of ellipse of center of iris an pupil
    int small_ellipse_y_radius) // y coord of ellipse of center of iris an pupil
{
        bool vertical;
        // Fraction variables to calculate intersection points
   double numerator, denominator, slope;

        vertical = check_vertical(x, y, x1, y1, x_intersect, y_intersect,
        small_ellipse_y_radius);
   if (!vertical)
        {       // Find slope of line from center of eye to mouse pointer, pixel coords
                slope = ((double)(y1 - y)) / ((double)(x - x1));

                // Pixel coords
                numerator = pow(small_ellipse_x_radius, 2.0) * pow(small_ellipse_y_radius, 2.0);
           denominator = pow(small_ellipse_y_radius, 2.0) + pow(small_ellipse_x_radius, 2.0) * pow(slope, 2.0);

                x_intersect = sqrt(numerator / denominator);
           y_intersect = slope * x_intersect;

           if (x < x1)
                x_intersect = -(abs(x_intersect));
           else
                   x_intersect = abs(x_intersect);

           if (y < y1)
                y_intersect = -(abs(y_intersect));
           else
                   y_intersect = abs(y_intersect);

                x_intersect += x1;
                y_intersect += y1;

           if ( (pow(x - x1,2.0) / pow(small_ellipse_x_radius, 2.0) + pow(y1 - y, 2.0) / pow(small_ellipse_y_radius, 2.0)) < 1)
           {    // Point1 is inside the eye ellipse
                x_intersect = x;
              y_intersect = y;
           }
   }    // end if not vertical
}


void get_radius_eyes(int& tx_rad, int& ty_rad)
{
        // Radii of the eyes in pixel coordinates
   tx_rad = xtranslate(X_RAD, XBORDER) - xtranslate(0, XBORDER);
   ty_rad = ytranslate(0, YBORDER) - ytranslate(Y_RAD, YBORDER);
}

void get_radius_iris_pupil(int& ti_rad, int& tp_rad)
{
        // Radii of the iris and pupil, respectively, in pixel coordinates
   ti_rad = xtranslate(I_RADIUS, XBORDER) - xtranslate(0, XBORDER);
   tp_rad = xtranslate(P_RADIUS, XBORDER) - xtranslate(0, XBORDER);
}


void update_graphics(int left_x_intersect, int left_y_intersect,
        int right_x_intersect, int right_y_intersect, int ti_rad, int tp_rad, int& t)
{
        int active_page = t % 2;

        setactivepage(active_page);
        clearviewport();
        setfillstyle( SOLID_FILL, WHITE );
   draw_eyes();
        // Left Iris
   // (left_color);
   setfillstyle( SOLID_FILL, left_color );
   fillellipse(left_x_intersect, left_y_intersect, ti_rad, ti_rad);

   // Left Pupil
   // (BLACK);
   setfillstyle( SOLID_FILL, BLACK );
   fillellipse(left_x_intersect, left_y_intersect, tp_rad, tp_rad);

        // Right Iris
   // (right_color);
   setfillstyle( SOLID_FILL, right_color );
   fillellipse(right_x_intersect, right_y_intersect, ti_rad, ti_rad);

   // Right Pupil
   // (BLACK);
   setfillstyle( SOLID_FILL, BLACK );
   fillellipse(right_x_intersect, right_y_intersect, tp_rad, tp_rad);

   t++;
   setvisualpage(active_page);
}


void deleteShapes(int number,vector<Shape*>&shapes,bool show,bool lock)
{
	cleardevice();

	vector<Shape*>replace;
	for (int i = 0; i < shapes.size();i++)
	{
		if (!(shapes[i]->getID() == number))
		{
			//shapes.erase(shapes.begin()+i);
			replace.push_back(shapes[i]);
		}
	}
	
	if (show)
		showGridLines(lock);
	
	else
		drawCanvas(lock);
	
	for (int i = 0; i < replace.size(); i++)
	{
		replace[i]->draw();
	}
	shapes = replace;

}


void moveShapes(int no, vector<Shape*>&shapes, bool show,bool lock){
	
	if (show)
	{
		showGridLines(lock);
	}
	else
	{
		drawCanvas(lock);

	}
	for (int i = 0; i < shapes.size(); i++)
	{
		
		if (no==1)
		shapes[i]->drawFor();
		else if (no==2)
		shapes[i]->drawBack();
		else if (no == 3)
		{
			shapes[i]->drawDown();
		}
		else if (no == 4)
			shapes[i]->drawUp();

	}




}

void check_keys(vector<Shape*>&shapes,bool show,int number,bool lock)
{
        int command;


        if (kbhit()== true)
   {
      command = toupper(getch());
	  if (char(command) == 27)
        {
        cout << "Exiting..." << endl;
        exit (EXIT_SUCCESS);
		}
		else if (char(command) == ' ')
		{
			cleardevice();

			while (!shapes.empty())
			{
				shapes.pop_back();
			}
			if (show)
			{
				showGridLines(lock);
			}
			else
			{
				drawCanvas(lock);

			}
		}
		else if (char(command) == 'C')
		{
			deleteShapes(1,shapes,show,lock);

		}

		else if (char(command) == 'T')
		{
			deleteShapes(2,shapes,show,lock);

			deleteShapes(7, shapes,show,lock);//filled Triangles

	


		}
		else if (char(command) == 'L')
		{
			
			deleteShapes(3, shapes,show,lock);


		}
		else if (char(command) == 'R')
		{

			deleteShapes(4, shapes,show,lock);

			deleteShapes(6, shapes,show,lock);//filled Rectangles



		}
		else if (char(command) == 'P')
		{

			deleteShapes(5, shapes,show,lock);


		}
		else if (char(command) == 77)
		{
			moveShapes(1,shapes,show,lock);
		}
		else if (char(command) == 75)
		{
			
			moveShapes(2, shapes, show,lock);
		}
		else if (char(command) == 80)
		{
			
			moveShapes(3, shapes, show,lock);
		}
		else if (char(command) == 72)
		{

			moveShapes(4, shapes, show,lock);
		}



   }
}


// ******************** User X-Coordinate Translate Function *******************
// Translate the user inputted x-coordinate to a screen coordinate
int xtranslate (double x, double xborder)
{
        // This function assumes that you want to plot horizontal values that range from
   // -xborder (on the left of the graphics screen) to +xborder (on the right of
   // the graphics screen).
   // The return value of this function tells the x-pixel value that corresponds
   // to the parameter x.

   double percent;              // Percent of x-hemisphere (positive or negative) where
                                                        // user defined coordinate is located
        int maxx = getmaxx();
   int x_value;                 // Corresponding graphical x-value

   percent = x / xborder;       // Finds, percentagewise, how far the user defined
                                                                // coordinate is located from the y-axis.

   // Calculates the graphical x-value by adding to the x-value at the center of
   // the screen the percentage further that the user defined x is located.  Note
   // that if percentage is negative (meaning the user x-coorinate was negative)
   // that the following step will be a subtraction.
   x_value = maxx/2 + percent * (maxx/2);

   return (int)x_value;
}


// ******************** User Y-Coordinate Translate Function *******************
// Translate the user inputted y-coordinate to a screen coordinate
int ytranslate (double y, double yborder)
{
        // This function assumes that you want to plot vertical values that range from
   // -yborder (on the bottom of the graphics screen) to +yborder (on the topof
   // the graphics screen).
   // The return value of this function tells the y-pixel value that corresponds
   // to the parameter y.

   float percent;               // Percent of y-hemisphere (positive or negative) where
                                                // user defined coordinate is located
        int maxy = getmaxy();
   int y_value;         // Corresponding graphical y-value

   percent = -y / yborder;      // Finds, percentagewise, how far the user defined
                                                                // coordinate is located from the x-axis.  Since the
                           // y-values run opposite from expected, the negative
                           // sign is necessary.

   // Calculates the graphical y-value by adding to the y-value at the center of
   // the screen the percentage further that the user defined y is located.  Note
   // that if percentage is negative (meaning the user y-coorinate was negative)
   // that the following step will be a subtraction.
   y_value = maxy/2 + percent * (maxy/2);

   return (int)y_value;
}
