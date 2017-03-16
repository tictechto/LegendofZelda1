#include "j1App.h"
#include "j1Render.h"
#include "p2Log.h"
#include "j1Camera.h"
#include "j1Player.h"
#include "j1Window.h"

j1Camera::j1Camera()
{
	name.create("camera");
}

j1Camera::~j1Camera()
{

}

// Called before render is available
bool j1Camera::Awake(pugi::xml_node&)
{
	LitleEllipse.ellipsecentre = { 0,0 };
	LitleEllipse.semimajoraxis = 160;
	LitleEllipse.semiminoraxis = 90;

	BigEllipse.ellipsecentre = { 0,0 };
	BigEllipse.semimajoraxis = 320;
	BigEllipse.semiminoraxis = 180;

	return true;
}

// Called before the first frame
bool j1Camera::Start()
{
	int w, h = 0;
	SDL_GetRendererOutputSize(App->render->renderer, &w, &h);
	Half_w = (int)(w * 0.5f);
	Half_h = (int)(h * 0.5f);
	return true;
}

// Called each loop iteration
bool j1Camera::PreUpdate()
{
	//Calculate camera centre
	if (App->input->GetKey(SDL_SCANCODE_L) == KEY_REPEAT) App->win->scale += 0.005;
	if (App->input->GetKey(SDL_SCANCODE_K) == KEY_REPEAT) App->win->scale -= 0.005;
	float Scale = App->win->GetScale();
	App->render->camera.x = ((-1) * (int)(((App->player->Link->pos.x + App->player->Zelda->pos.x) * 0.5f) * Scale)) + Half_w;
	App->render->camera.y = ((-1) * (int)(((App->player->Link->pos.y + App->player->Zelda->pos.y) * 0.5f) * Scale)) + Half_h;
	LitleEllipse.ellipsecentre = BigEllipse.ellipsecentre = { App->render->camera.x - Half_w,App->render->camera.y - Half_h };
	return true;
}

// Called each loop iteration
bool j1Camera::Update(float dt)
{
	/*
	App->player->Link->pos;
	App->player->Zelda->pos;
	LitleEllipse.InsideEllipse();
	LitleEllipse.InsideEllipseValue();
	BigEllipse.InsideEllipse();
	BigEllipse.InsideEllipseValue();
	*/

	return true;
}

// Called each loop iteration
bool j1Camera::PostUpdate()
{
	return true;
}

// Called before quitting
bool j1Camera::CleanUp()
{
	LOG("Freeing camera");
	return true;
}

void j1Camera::OnGui(Gui* ui, GuiEvent event)
{

}

void j1Camera::OnConsoleCommand(const Command* command, const std::vector<std::string>& commandarguments)
{

}

void j1Camera::OnConsoleCVar(const CVar* cvar)
{

}