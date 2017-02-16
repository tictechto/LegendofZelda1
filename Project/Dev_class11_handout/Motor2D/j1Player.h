#ifndef _J1PLAYER_
#define _J1PLAYER_

#include "j1Module.h"
#include "p2Point.h"
#include "MainScene.h"
#include "P_Link.h"

class P_Link;

enum Character {
	link,
	zelda
};

class j1Player :public j1Module {
public:
	bool Awake(pugi::xml_node&);
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();

	void Draw();

	void Move();
	void Change_Player();
	void Chase();


public:
	//p2Point<float>* pos;
	MainScene* actual_scene;
	int live;
	Character selected_character;
	P_Link* Link;
};



#endif
