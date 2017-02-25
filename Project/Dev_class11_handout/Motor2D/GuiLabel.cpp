#include "j1Gui.h"
#include "GuiLabel.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Fonts.h"

GuiLabel::GuiLabel(iPoint position, std::string* str, bool movable, AddGuiTo addto) : Gui(position, GuiType::gui_label, movable, addto),
LabelString(*str), font(App->font->default)
{
	CalculateGui_Collider();
}

GuiLabel::~GuiLabel()
{

}

void GuiLabel::Draw()
{
	if (this->visible == true)
	{
		if (LabelString != empty_char)
		{
			SDL_Texture* texture_to_blit = App->font->Print(LabelString.c_str(), { 255, 255, 255, 255 }, font);
			App->render->Blit(texture_to_blit, position.x - App->render->camera.x, position.y - App->render->camera.y, NULL, 1.0f, 0, INT_MAX, INT_MAX, false);
			SDL_DestroyTexture(texture_to_blit);
		}
		if (App->gui->Gui_DebugDraw_isactive())
			this->DebugDraw();
	}
}

void GuiLabel::DebugDraw() const
{
	App->render->DrawQuad(Gui_Collider, LightSeaGreen(0), LightSeaGreen(1), LightSeaGreen(2), DEBUG_DRAW_ALPHA, true, false);
}

const std::string* GuiLabel::GetLabelStr() const
{
	return &LabelString;
}

void GuiLabel::EditLabelStr(std::string* newstr)
{
	LabelString = *newstr;
	CalculateGui_Collider();
}

void GuiLabel::SetFont(_TTF_Font* newfont)
{
	font = newfont;
	CalculateGui_Collider();
}

_TTF_Font* GuiLabel::GetFont()
{
	return font;
}

void GuiLabel::Clear()
{
	LabelString.clear();
	CalculateGui_Collider();
}

void GuiLabel::CalculateGui_Collider()
{
	int w, h = 0;
	App->font->CalcSize(LabelString.c_str(), w, h, font);
	Gui_Collider = { position.x, position.y, w, h };
}