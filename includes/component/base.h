#ifndef LAKLOK_BASE_H
#define LAKLOK_BASE_H

#include <functional>
#include <SDL.h>

#include "component_type.h"
#include "../renderer.h"

class Component {
protected:
	int renderIndex = 0;
	ComponentPosition position = {0, 0, POSITION_RELATIVE};
	ComponentSize size = {0, 0};
	COMPONENT_TYPE componentType = COMPONENT_TYPE_UNDEFINED;
	Component *parent = nullptr;
	RendererController *rendererController = nullptr;
	bool hovered = false;
	bool shown = true;

public:
	explicit Component(RendererController *rendererController, int renderIndex = 0,
	                   ComponentSize componentSize = {0, 0},
	                   ComponentPosition componentPosition = {0, 0, POSITION_RELATIVE},
	                   COMPONENT_TYPE componentType = COMPONENT_TYPE_UNDEFINED);

	RendererController *getRendererController();

	Component *setParent(Component *parent);

	Component *setRenderIndex(int index);

	Component *show(bool shown = true);

	Component *getParent();

	virtual Array<Component *> *getChildren();

	int getRenderIndex();

	ComponentPosition setPosition(ComponentPosition componentPosition);

	ComponentPosition getPosition();

	ComponentSize setSize(ComponentSize componentSize);

	ComponentSize getSize();

	bool isShown();

	bool isHovered();

	virtual void click(ComponentPosition clickPosition, SDL_Event event) {};

	virtual void hover(ComponentPosition mousePosition, SDL_Event event) = 0;

	virtual void unHover(ComponentPosition mousePosition, SDL_Event event) = 0;

	virtual void render(Renderer *renderer) = 0;

	ComponentPosition getAbsolutePosition();
};

#endif //LAKLOK_BASE_H
