#include <iostream>
#include <SDL.h>
#include <map>

#include "includes/SDL_util.h"
#include "includes/renderer.h"
#include "includes/util/array.h"
#include "includes/component/container.h"
#include "includes/util/timercpp.h"
#include "view/view_loader.h"

#include "includes/test.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define RESOURCE_PATH "A:/Projects/LakLok/resources"
#define FPS 144

int WinMain(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	TTF_Init();

	SDL_Window *SDLWindow = createWindow("LakLok", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer *SDLRenderer = createRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	RendererController SDLRendererController(SDLRenderer, SDLWindow);

	std::string currentScene = "menu";

	std::map<const std::string, Container *> sceneList;

	auto *EventManager = new Event();

	sth(SDLRendererController, EventManager, sceneList, currentScene, RESOURCE_PATH, SCREEN_WIDTH, SCREEN_HEIGHT);

	EventManager->on(SDL_MOUSEBUTTONDOWN, [&](SDL_Event event) {
		if (!sceneList[currentScene]) return;
		ComponentPosition clickPosition = { 0, 0, POSITION_ABSOLUTE };
		SDL_GetMouseState(&clickPosition.x, &clickPosition.y);
		sceneList[currentScene]->click(clickPosition, event);
	});

	Component *lastHoveredScene = nullptr;

	EventManager->on(SDL_MOUSEMOTION, [&](SDL_Event event) {
		ComponentPosition mousePosition = { 0, 0, POSITION_ABSOLUTE };
		SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
		if (lastHoveredScene) {
			lastHoveredScene->unHover(mousePosition, event);
			lastHoveredScene = nullptr;
		}
		if (sceneList[currentScene]) {
			sceneList[currentScene]->hover(mousePosition, event);
			lastHoveredScene = sceneList[currentScene];
		}
	});

	SDLRendererController.addRenderer(0, [&](Renderer *renderer, SDL_Renderer *SDLRenderer, SDL_Window *SDLWindow) {
		if (sceneList[currentScene]) sceneList[currentScene]->render(renderer);
	});

	auto timer = new Timer();
	timer->setInterval([&]( ) {
		if (sceneList[currentScene]) {
			sceneList[currentScene]->children()->sort([ ](Node<Component *> *fNode, Node<Component *> *sNode) {
				return fNode->getNodeData()->getRenderIndex() <= sNode->getNodeData()->getRenderIndex();
			});
		}
		SDLRendererController.tick();
	}, 1 /*s*/ * ( 1000 /*ms*/ / 1 /*s*/) * ( 1 /*s*/ / FPS /*frames*/));

	EventManager->init([ ](SDL_Event event) {
		return event.type == SDL_QUIT;
	});

	timer->stop();

	cleanupSDL(SDLRenderer, SDLWindow);

	return 0;
}