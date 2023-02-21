#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1, Rect R2){
	double diffx = R1.x - R2.x;
	if(diffx < 0) diffx *= -1;

	double diffy = R1.y - R2.y;
	if(diffy < 0) diffy *= -1;

	if(diffx > R1.w || diffx > R2.w) return 0;
	if(diffy > R1.h || diffy > R2.h) return 0;

	//แกน x ด้านซ้าย
	double maxX;
	if(R1.x > R2.x) maxX = R1.x;
	else maxX = R2.x;
	//แกน x ด้านขวา
	double minX;
	if((R1.x + R1.w) < (R2.x + R2.w)) minX = R1.x + R1.w;
	else minX = R2.x + R2.w;
	double Lx = minX - maxX;

	//แกน y บน
	double maxY;double minY;
	if(R1.y > R2.y) minY = R2.y;
	else minY = R1.y;
	//ด้านล่าง
	if((R1.y - R1.h) < (R2.y - R2.h)) maxY = R2.y - R2.h;
	else maxY = R1.y - R1.h;
	double Ly = minY - maxY;
	return Lx*Ly;

}