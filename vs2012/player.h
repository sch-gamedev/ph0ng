#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player{

private:

	//enum fajta { sima , hajlott };   // ha szeretnén tobb felet csinalni
 	int x;
	int y;
	int alfa;  // mennyire van elfordulva FOKban

public:

	Player();   //konstruktor
  
	lmove(); // balra mozgatas

	rmove(); //jobbra mozgatas

	draw();  //kirajzolas MEGBESZELNI!!!!!
}
#endif