#include "SDL_util.h"

using namespace std;

void logSDLError(const string &message) {
	cout << message << " Error: " << SDL_GetError() << endl;
}

SDL_Window *createWindow(const char *windowName, int posX, int posY, int screenWidth, int screenHeight, SDL_WindowFlags flags) {
	SDL_Window *window = SDL_CreateWindow(windowName, posX, posY, screenWidth, screenHeight, flags);
	if (!window) logSDLError("CreateWindow");
	return window;
}

SDL_Renderer *createRenderer(SDL_Window *window, int index, Uint32 flags) {
	SDL_Renderer *renderer = SDL_CreateRenderer(window, index, flags);
	if (!renderer) logSDLError("CreateRenderer");
	return renderer;
}

SDL_Texture *loadTexture(SDL_Renderer *renderer, const std::string &texturePath) {
	SDL_Texture *loadedTexture = IMG_LoadTexture(renderer, texturePath.c_str());

	if (!loadedTexture) logSDLError("LoadTexture");
	return loadedTexture;
}

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int posX, int posY) {
	SDL_Rect pos;
	pos.x = posX;
	pos.y = posY;
	SDL_QueryTexture(texture, nullptr, nullptr, &pos.w, &pos.h);
	SDL_RenderCopy(renderer, texture, nullptr, &pos);
}

void renderTexture(SDL_Renderer *renderer, SDL_Texture *texture, int posX, int posY, int width, int height) {
	SDL_Rect pos;
	pos.x = posX;
	pos.y = posY;
	pos.w = width;
	pos.h = height;
	SDL_RenderCopy(renderer, texture, nullptr, &pos);
}

void cleanupSDL(SDL_Renderer *renderer, SDL_Window *window) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

Event::Event( ) : _end(true) { }

// TODO event

Event *Event::init(std::function<bool(SDL_Event)> &&callback) {
	_end = false;
	while (!_end) {
		while (SDL_PollEvent(&event)) {
			if (!( _end = callback(event))) {
				if (callbackList[( SDL_EventType ) event.type])
					callbackList[( SDL_EventType ) event.type]->forEach([&](int index, int id, std::function<void(SDL_Event)> &&_callback) {
						timer.setTimeout([=]( ) { _callback(event); }, 0);
					});
			}
		}
	}

	return this;
}

Event *Event::on(SDL_EventType eventType, std::function<void(SDL_Event)> &&callback) {
	if (!callbackList[eventType]) callbackList[eventType] = new Array<std::function<void(SDL_Event)>>;
	callbackList[eventType]->push(callback);
	return this;
}

void Event::exit( ) {
	_end = true;
}