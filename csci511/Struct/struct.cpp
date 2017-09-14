#include <iostream>
#include <math.h>

using namespace std;

struct Triangle {
	char color;
	char shade;
	short base;
	short height;
};

struct Circle {
	char color;
	char shade;
	short radius;
};

void setCircle(struct Circle* x, char col, char sha, short rad){
	x->color = col;
	x->shade = sha;
	x->radius = rad;
}

void drawCircle(struct Circle* x){

	string s, c;
	if (x->shade == 'b'){
		s = "dark";
	}
	if (x->color == 'g'){
		c = "red";
	}

	cout << s << " " << c << " circle , radius=" << x->radius << endl;
}


float areaCircle(struct Circle* x){
	return (x->radius*pow(3.1415,2));
}

void setTriangle(struct Triangle* x, char col, char sha, short b, short h){
	x->color = col;
	x->shade = sha;
	x->base = b;
	x->height = h;
}


void drawTriangle(struct Triangle* x){

	string s, c;
	if (x->shade == 'l'){
		s = "light";
	}
	if (x->color == 'b'){
		c = "blue";
	}

	cout << s << " " << c << " triangle , base=";
	cout << x->height << ", height=" << x->height << endl;
}




int main(){
	Circle c;
	setCircle(&c, 'g', 'b', 3);
	drawCircle(&c);	


	Triangle t;
	setTriangle(&t, 'b', 'l', 4, 2);
	drawTriangle(&t);	

}

