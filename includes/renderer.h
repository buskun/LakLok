#ifndef LAKLOK_RENDERER_H
#define LAKLOK_RENDERER_H

#include <functional>
#include <SDL.h>

#include "../includes/SDL_util.h"
#include "../includes/type.h"
#include "util/array.h"

class Renderer {
	std::function<void(Renderer *)> renderFunction;
	int renderIndex;
public:
	Renderer(int renderIndex, std::function<void(Renderer *)> &&renderFunction);

	void callRenderFunction();

	int getRenderIndex();
};

class RendererController {
	Array<Renderer *> *rendererList;
	SDL_Renderer *SDLRenderer;
	SDL_Window *SDLWindow;
public:
	RendererController(GameProp &&gameProp, Uint32 windowFlags, Uint32 rendererFlags);

	~RendererController( );

	RendererController* addRenderer(int renderIndex, std::function<void(Renderer *)> &&renderFunction);

	Renderer* removeRenderer(int id);

	SDL_Renderer *getSDLRenderer( );

	SDL_Window *getSDLWindow( );

	void renderTick( );
};

#endif//LAKLOK_RENDERER_H
