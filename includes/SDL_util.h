#ifndef LAKLOK_SDL_UTIL_H
#define LAKLOK_SDL_UTIL_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <functional>
#include <map>

#include "util/timercpp.h"
#include "util/array.h"

namespace SDL {
	extern bool isCustomCursor;
	extern SDL_Cursor *systemCursor;
	extern SDL_Cursor *customCursor;

	void logSDLError(const std::string &message, bool exitOnError);

	SDL_Texture *loadTexture(SDL_Renderer *SDLRenderer, const std::string &texturePath);

	void renderTexture(SDL_Renderer *SDLRenderer, SDL_Texture *texture, int posX, int posY);

	void renderTexture(SDL_Renderer *SDLRenderer, SDL_Texture *texture, int posX, int posY, int width, int height);

	void setSystemCursor(SDL_SystemCursor systemCursorID);

	void setCustomCursor(const std::string &surfacePath, int hot_x, int hot_y);

	void toggleCursor();

	void useCustomCursor();

	void useSystemCursor();
};

class EventManager {
	SDL_Event event = {};
	bool exitProgram = true;
	Timer *timer = nullptr;
	std::map<SDL_EventType, Array<std::function<void(SDL_Event)>> *> callbackList;
	std::map<SDL_EventType, Array<std::function<void(SDL_Event)>> *> gameTickCallbackList;
public:
	EventManager();

	EventManager *init(std::function<bool(SDL_Event)> &&callback);

	void exit();

	void gameTick();

	EventManager *on(SDL_EventType eventType, std::function<void(SDL_Event)> &&callback);

	EventManager *onGameTick(SDL_EventType eventType, std::function<void(SDL_Event)> &&callback);
};

#endif //LAKLOK_SDL_UTIL_H
