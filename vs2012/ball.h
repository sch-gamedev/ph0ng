#ifndef _BALL_H_
#define _BALL_H_

class Ball{

private:

	int x, oldx;
	int y, oldy;
	int speed;  

	colldet(); // collision detection UPDATE hivja
public:

	Ball();   //konstruktor
  
	update(); //csinálja a labda dolgait
	draw();

}
#endif