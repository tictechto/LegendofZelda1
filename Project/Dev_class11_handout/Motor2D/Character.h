#ifndef _CHARACTER_
#define _CHARACTER_

#include "PugiXml/src/pugixml.hpp"
#include "p2Point.h"
#include "SDL\include\SDL.h"
#include  "p2SString.h"
#include "Animation.h"
#include "j1Textures.h"
#include <vector>
#include "p2Log.h"
#include "j1Object.h"


#define TILE_COL_ID 3845
#define CANT_PASS_COL_ID 3848
#define NOT_COLISION_ID 0

struct dir_tiles {
	uint i;
	uint j;
};

struct  adjacent_tiles {
	dir_tiles up;
	dir_tiles down;
	dir_tiles left;
	dir_tiles right;
};


enum player_event {
	move,
	idle,	
	jump,
	roll,
	pick,
	lifting,
	attack,	
	fall,
	throw_,
	backwards,
	/*
	.
	.
	.
	*/
};

enum direction {
	up,
	down,
	left,
	right
};

enum move_direction {
	move_idle,
	move_up,
	move_down,
	move_right,
	move_left,
	move_up_left,
	move_up_right,
	move_down_left,
	move_down_right
};

class P_Link;
class P_Zelda;

enum movement_animation;
enum key_state;

class Character : public Entity {
public:
	Character() {};
	~Character() {};
	
	
	virtual void Attack(float dt);
	void Move(float dt);
	void Jump(float dt);
	void Roll(float dt);
	void Throw(float dt);

	//Load the character animations in .xml. Recieves the path of the file
	//virtual void LoadAnimation(const char* path);

	//Get the actual player event
	virtual player_event GetEvent();

	//Executes the event
	virtual void ExecuteEvent(float);

	void GetAdjacents();

	//Takes the id of front tiles
	int GetLogic(int height, iPoint tilepos);


	uint GetLogicHeightPlayer();
	void ChangeLogicHeightPlayer(int);

	//Updates the front collider
	void UpdateColliderFront();
	virtual void Collision_Sword_EnemySword();
	virtual void ThrowFunction(float dt, int& pos, bool add, bool is_horitzontal);

private:
	//Diferent action functions
	bool MoveFunction(float dt, int& pos,int& other_pos, bool add, dir_tiles tiles, int side_tile_one, int side_tile_two, bool is_down = false);
	bool MoveDiagonalFunction(float dt, int& pos_one, int& pos_two, bool add_one, bool add_two, int front_tile, int side_tile, int diagonal_tile, bool is_down = false);
	void JumpFunction(float dt, int& pos, bool add);
	void RollFunction(float dt, int& pos, bool add);
	
	
public:
	
	j1Timer attack_timer;
	iPoint						pos;
	iPoint						tilepos;
	adjacent_tiles				adjacent;

	//Needed for player movement and events
	player_event				actual_event;
	direction					character_direction;
	move_direction				movement_direction;
	bool						can_move=false;
	bool						can_jump=false;

	//Diferent colliders
	Collider*	collision;
	Collider*	front_collider;
	Collider* attack_collider;

	bool		doing_script = false;


private:

	//For jump
	bool temp = false;
	 //Needed to save position only one time
};

#endif

