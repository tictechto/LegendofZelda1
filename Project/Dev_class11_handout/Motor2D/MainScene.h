#ifndef _MAINSCENE_
#define _MAINSCENE_

#include "j1App.h"

#include "j1Input.h"
#include "SDL\include\SDL.h"
#include "p2Log.h"

#include <vector>

enum Scene_ID {
	inventory,
	map,
	world,
	dungeon,

	//Main menu
	gamestart,
	//chooselanguage,
	mainmenu,
	campain,
	options,
	credits,
	quitgame
};

enum GuiEvent;
class Gui;
struct Command;
struct CVar;

class MainScene {
public:

	MainScene() {};
	~MainScene() {};

	virtual bool Start() {
		return true;
	};
	
	virtual bool PreUpdate() {
		return true;
	};
	virtual bool Update() {
		return true;
	};
	virtual bool PostUpdate() {
		return true;
	};
	virtual bool Clean() {
		return true;
	}
	virtual void OnGui(Gui* ui, GuiEvent event)
	{
	}
	virtual void OnConsoleCommand(const Command* command, const std::vector<std::string>& commandarguments)
	{
	}
	virtual void OnConsoleCVar(const CVar* cvar)
	{
	}
public:
	Scene_ID scene_name;
	SDL_Texture* atlas;
	
	/*
	Map
	Textures
	Enemies
	.
	.
	.
	*/
};

#endif // !_MAINSCENE_