//
// Created by buskun0 on 14/04/19.
//

#ifndef LAKLOK_COMPONENT_TYPE_H
#define LAKLOK_COMPONENT_TYPE_H

#include <SDL.h>
#include <SDL_ttf.h>

enum POSITION_FLAG {
	POSITION_ABSOLUTE,
	POSITION_RELATIVE
};

enum COMPONENT_TYPE {
	COMPONENT_TYPE_UNDEFINED,
	COMPONENT_TYPE_VIEW,
	COMPONENT_TYPE_CONTAINER
};

typedef struct {
	int x;
	int y;
	POSITION_FLAG positionFlag;
} ComponentPosition;

typedef struct {
	int width;
	int height;
} ComponentSize;

typedef struct {
	int fontSize;
	std::string fontName;
	SDL_Color fontColor;
} TextProp;

#endif //LAKLOK_COMPONENT_TYPE_H
