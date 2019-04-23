#ifndef LAKLOK_SDL_UTIL_H
#define LAKLOK_SDL_UTIL_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <functional>
#include <map>

#include "util/timercpp.h"
#include "util/array.h"

void logSDLError(const std::string &message);

SDL_Window *createWindow(const char *windowName, int posX, int posY, int screenWidth, int screenHeight, SDL_WindowFlags flags);

SDL_Renderer *createRenderer(SDL_Window *window, int index, Uint32 flags);

SDL_Texture *loadTexture(SDL_Renderer *renderer, const std::string &texturePath);

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int posX, int posY);

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int posX, int posY, int width, int height);

void cleanupSDL(SDL_Renderer *renderer, SDL_Window *window);

class Event {
	SDL_Event event;
	bool _end;
	Timer timer;
	std::map<SDL_EventType, Array<std::function<void(SDL_Event)>> *> callbackList;
public:
	Event( );

	Event *init(std::function<bool(SDL_Event)> &&callback);

	void exit( );

	Event *on(SDL_EventType eventType, std::function<void(SDL_Event)> &&callback);
};

#endif //LAKLOK_SDL_UTIL_H
