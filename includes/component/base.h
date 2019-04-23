//
// Created by buskun0 on 07/04/19.
//

#ifndef LAKLOK_BASE_H
#define LAKLOK_BASE_H

#include <functional>
#include <SDL.h>

#include "component_type.h"
#include "../renderer.h"

class Component {
protected:
	int _renderIndex = 0;
	ComponentPosition position = { 0, 0, POSITION_RELATIVE };
	ComponentSize size = { 0, 0 };
	Component *_parent = nullptr;
	COMPONENT_TYPE _componentType = COMPONENT_TYPE_UNDEFINED;
	RendererController &_rendererController;
	bool hovered = false;

public:
	explicit Component(RendererController &rendererController, int renderIndex = 0,
	                   ComponentSize componentSize = { 0, 0 },
	                   ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE },
	                   COMPONENT_TYPE componentType = COMPONENT_TYPE_UNDEFINED)
			: position(componentPosition), size(componentSize), _componentType(componentType), _renderIndex(renderIndex),
			  _rendererController(rendererController) {
	}

	int getRenderIndex( ) {
		return _renderIndex;
	}

	RendererController &getRendererController( ) {
		return _rendererController;
	}

	Component *setParent(Component *parent) {
		_parent = parent;
		return this;
	}

	Component *setRenderIndex(int index) {
		_renderIndex = index;
		return this;
	}

	ComponentPosition setPosition(int x, int y, POSITION_FLAG positionFlag) {
		position.x = x;
		position.y = y;
		position.positionFlag = positionFlag;
		return position;
	}

	ComponentPosition setPosition(int x, int y) {
		return setPosition(x, y, position.positionFlag);
	}

	ComponentPosition setPosX(int x) {
		return setPosition(x, position.y);
	}

	ComponentPosition setPosY(int y) {
		return setPosition(position.x, y);
	}

	ComponentPosition getPosition() {
		return position;
	}

	ComponentSize getSize( ) {
		return size;
	}

	ComponentSize setSize(ComponentSize componentSize) {
		if (componentSize.width) size.width = componentSize.width;
		if (componentSize.height) size.height = componentSize.height;
		return size;
	}

	virtual void click(ComponentPosition clickPosition, SDL_Event event) { }

	virtual void hover(ComponentPosition mousePosition, SDL_Event event) { }

	virtual void unHover(ComponentPosition mousePosition, SDL_Event event) { }

	virtual void render(Renderer *renderer) { }

	static ComponentPosition absolutePosition(Component *component) {
		if (!component) return ( ComponentPosition ) { 0, 0, POSITION_ABSOLUTE };
		if (( component->position ).positionFlag == POSITION_ABSOLUTE) return component->position;
		ComponentPosition temp = absolutePosition(component->_parent);
		return ( ComponentPosition ) { component->position.x + temp.x, component->position.y + temp.y, POSITION_ABSOLUTE };
	}
};

#endif //LAKLOK_BASE_H
