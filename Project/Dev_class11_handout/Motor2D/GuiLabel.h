#ifndef __GUILABEL_H__
#define __GUILABEL_H__

#include "Gui.h"
#include "j1Fonts.h"

class GuiLabel : public Gui
{
	//friend class GuiInputText;
public:
	GuiLabel(iPoint position, std::string* str, bool movable, AddGuiTo addto);
	~GuiLabel();

	void Draw();
	const std::string* GetLabelStr() const;
	void EditLabelStr(std::string* newstr);
	void SetFont(_TTF_Font* newfont);
	_TTF_Font* GetFont();
	void Clear();

private:
	void DebugDraw() const;
	void CalculateGui_Collider();

private:
	std::string LabelString;
	_TTF_Font*  font;
};

#endif // __GUILABEL_H__