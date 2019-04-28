#ifndef LAKLOK_COMPONENT_TYPE_H
#define LAKLOK_COMPONENT_TYPE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

typedef enum {
	POSITION_ABSOLUTE,
	POSITION_RELATIVE
} POSITION_FLAG;

typedef enum {
	COMPONENT_TYPE_UNDEFINED,
	COMPONENT_TYPE_VIEW,
	COMPONENT_TYPE_CONTAINER
} COMPONENT_TYPE;

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
