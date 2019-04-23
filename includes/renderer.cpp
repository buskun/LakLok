#include <utility>

#include "renderer.h"

Renderer::Renderer(int renderIndex, std::function<void(Renderer *, SDL_Renderer *&, SDL_Window *&)> _renderFunction) : renderFunction(
		std::move(_renderFunction)), _renderIndex(renderIndex) { }

void Renderer::callRenderFunction(SDL_Renderer *&_renderer, SDL_Window *&_window) {
	renderFunction(this, _renderer, _window);
}

int Renderer::getRenderIndex( ) {
	return _renderIndex;
}

RendererController::RendererController(SDL_Renderer *&_renderer, SDL_Window *&_window) :
		SDLRenderer(_renderer), SDLWindow(_window), rendererList(new Array<Renderer *>) { }

void RendererController::addRenderer(int renderIndex, std::function<void(Renderer *, SDL_Renderer *&, SDL_Window *&)> &&renderFunction) {
	Renderer *_renderer = new Renderer(renderIndex, renderFunction);
	rendererList->insert(_renderer, renderIndex);
}

void RendererController::removeRenderer(int id) {
	rendererList->removeByID(id);
}

SDL_Renderer *RendererController::getSDLRenderer( ) {
	return SDLRenderer;
}

SDL_Window *RendererController::getSDLWindow( ) {
	return SDLWindow;
}

void RendererController::tick( ) {
	SDL_RenderClear(SDLRenderer);
	rendererList->forEach([&](int index, int id, Renderer *renderer) {
		renderer->callRenderFunction(SDLRenderer, SDLWindow);
	});
	SDL_RenderPresent(SDLRenderer);
}