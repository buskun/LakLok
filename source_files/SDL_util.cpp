#include "../includes/SDL_util.h"

bool SDL::isCustomCursor = false;
SDL_Cursor *SDL::systemCursor = nullptr;
SDL_Cursor *SDL::customCursor = nullptr;

void SDL::logSDLError(const std::string &message, bool exitOnError = false) {
	std::cout << message << " Error: " << SDL_GetError() << std::endl;
	if (exitOnError) exit(EXIT_FAILURE);
}

SDL_Texture *SDL::loadTexture(SDL_Renderer *SDLRenderer, const std::string &texturePath) {
	SDL_Texture *loadedTexture = IMG_LoadTexture(SDLRenderer, texturePath.c_str());
	if (!loadedTexture) logSDLError("LoadTexture", false);

	return loadedTexture;
}

void SDL::renderTexture(SDL_Renderer *SDLRenderer, SDL_Texture *texture, int posX, int posY) {
	SDL_Rect pos;
	pos.x = posX;
	pos.y = posY;
	SDL_QueryTexture(texture, nullptr, nullptr, &pos.w, &pos.h);
	SDL_RenderCopy(SDLRenderer, texture, nullptr, &pos);
}

void SDL::renderTexture(SDL_Renderer *SDLRenderer, SDL_Texture *texture, int posX, int posY, int width, int height) {
	SDL_Rect pos;
	pos.x = posX;
	pos.y = posY;
	pos.w = width;
	pos.h = height;
	SDL_RenderCopy(SDLRenderer, texture, nullptr, &pos);
}

void SDL::setSystemCursor(SDL_SystemCursor systemCursorID) {
	SDL::systemCursor = SDL_CreateSystemCursor(systemCursorID);
	if (!SDL::systemCursor) return logSDLError("CreateCursor");
}

void SDL::setCustomCursor(const std::string &surfacePath, int hot_x, int hot_y) {
	SDL_Surface *cursorSurface = IMG_Load(surfacePath.c_str());
	if (!cursorSurface) return logSDLError("LoadSurface");

	SDL::customCursor = SDL_CreateColorCursor(cursorSurface, hot_x, hot_y);
	if (!SDL::customCursor) return logSDLError("CreateCursor");
}

void SDL::toggleCursor() {
	if (SDL::isCustomCursor) SDL::useSystemCursor();
	else SDL::useCustomCursor();
}

void SDL::useSystemCursor() {
	if (!SDL::systemCursor) return;
	SDL_SetCursor(SDL::systemCursor);
	SDL::isCustomCursor = false;
}

void SDL::useCustomCursor() {
	if (!SDL::customCursor) return;
	SDL_SetCursor(SDL::customCursor);
	SDL::isCustomCursor = true;
}

EventManager::EventManager() {
	this->exitProgram = true;
	this->timer = new Timer();
}

EventManager *EventManager::init(std::function<bool(SDL_Event)> &&callback) {
	this->exitProgram = false;
	while (!this->exitProgram) {
		while (SDL_PollEvent(&this->event)) {
			if (!(this->exitProgram = callback(this->event))) {
				if (this->callbackList[(SDL_EventType) this->event.type])
					this->callbackList[(SDL_EventType) this->event.type]->forEach(
							[&](int index, int id, std::function<void(SDL_Event)> &&eventCallback) {
								this->timer->setTimeout([=]() { eventCallback(this->event); }, 0);
							});
			}
		}
	}

	return this;
}

EventManager *EventManager::on(SDL_EventType eventType, std::function<void(SDL_Event)> &&callback) {
	if (!this->callbackList[eventType]) this->callbackList[eventType] = new Array<std::function<void(SDL_Event)>>;
	this->callbackList[eventType]->push(callback);
	return this;
}

EventManager *EventManager::onGameTick(SDL_EventType eventType, std::function<void(SDL_Event)> &&callback) {
	if (!this->gameTickCallbackList[eventType])
		this->gameTickCallbackList[eventType] = new Array<std::function<void(SDL_Event)>>;
	this->gameTickCallbackList[eventType]->push(callback);
	return this;
}

void EventManager::gameTick() {
	if (this->gameTickCallbackList[(SDL_EventType) this->event.type]) {
		this->gameTickCallbackList[(SDL_EventType) this->event.type]->forEach(
				[&](int index, int id, std::function<void(SDL_Event)> &&tickCallback) {
					this->timer->setTimeout([=]() { tickCallback(this->event); }, 0);
				});
	}
}

void EventManager::exit() {
	this->exitProgram = true;
}