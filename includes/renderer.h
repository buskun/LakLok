#ifndef LAKLOK_RENDERER_H
#define LAKLOK_RENDERER_H

#include <functional>
#include <malloc.h>
#include <SDL.h>

#include "util/array.h"

class Renderer {
	std::function<void(Renderer *, SDL_Renderer *, SDL_Window *)> renderFunction;
	int _renderIndex;
public:
	Renderer(int renderIndex, std::function<void(Renderer *, SDL_Renderer *, SDL_Window *)> _renderFunction);

	void callRenderFunction(SDL_Renderer *_renderer, SDL_Window *_window);

	int getRenderIndex();
};

class RendererController {
	Array<Renderer *> *rendererList;
	SDL_Renderer *SDLRenderer;
	SDL_Window *SDLWindow;
public:
	RendererController(SDL_Renderer *_renderer, SDL_Window *_window);

	void addRenderer(int renderIndex, std::function<void(Renderer *, SDL_Renderer *, SDL_Window *)> &&renderFunction);

	void removeRenderer(int id);

	SDL_Renderer *getSDLRenderer( );

	SDL_Window *getSDLWindow( );

	void tick( );
};

#endif//LAKLOK_RENDERER_H
