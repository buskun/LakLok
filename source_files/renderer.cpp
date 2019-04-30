#include "../includes/renderer.h"

Renderer::Renderer(int renderIndex, std::function<void(Renderer *)> &&renderFunction) {
	this->renderIndex = renderIndex;
	this->renderFunction = renderFunction;
}

void Renderer::callRenderFunction() {
	this->renderFunction(this);
}

int Renderer::getRenderIndex( ) {
	return this->renderIndex;
}

RendererController::RendererController(GameProp &&gameProp, Uint32 windowFlags, Uint32 rendererFlags) {
	this->rendererList = new Array<Renderer *>;

	this->SDLWindow = SDL_CreateWindow(gameProp.NAME.c_str(), gameProp.WINDOW.X, gameProp.WINDOW.Y,
	                             gameProp.WINDOW.WIDTH, gameProp.WINDOW.HEIGHT, windowFlags);
	if (!this->SDLWindow) SDL::logSDLError("CreateWindow", true);

	this->SDLRenderer = SDL_CreateRenderer(this->SDLWindow, 0, rendererFlags);
	if (!this->SDLRenderer) SDL::logSDLError("CreateRenderer", true);
}

RendererController::~RendererController( ) {
	delete this->rendererList;
	SDL_DestroyRenderer(this->SDLRenderer);
	SDL_DestroyWindow(this->SDLWindow);
}

RendererController* RendererController::addRenderer(int renderIndex, std::function<void(Renderer *)> &&renderFunction) {
	this->rendererList->insert(new Renderer(renderIndex, std::move(renderFunction)), renderIndex);
	return this;
}

Renderer* RendererController::removeRenderer(int ID) {
	return this->rendererList->removeByID(ID);
}

SDL_Renderer *RendererController::getSDLRenderer( ) {
	return this->SDLRenderer;
}

SDL_Window *RendererController::getSDLWindow( ) {
	return this->SDLWindow;
}

void RendererController::renderTick( ) {
	SDL_RenderClear(this->SDLRenderer);
	this->rendererList->forEach([&](int index, int id, Renderer *renderer) {
		renderer->callRenderFunction();
	});
	SDL_RenderPresent(this->SDLRenderer);
}