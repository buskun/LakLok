#ifndef NDEBUG
#define DEBUG true
#else
#define DEBUG false
#endif

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

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900
#define FPS 144
#define TICK_TIME 100

int WinMain(int argc, char *argv[]) {
	int errorCode = 0;

	if (( errorCode = SDL_Init(SDL_INIT_EVERYTHING)) < 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return errorCode;
	}

	if (( errorCode = TTF_Init()) < 0) {
		std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
		return errorCode;
	}

	const std::string RESOURCE_PATH = ( std::string ) SDL_GetBasePath() + ( DEBUG ? "../resources" : "resources" );

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);

	auto ScreenWidth = DM.w;
	auto ScreenHeight = DM.h;

	const GameProp gameProp = {
			RESOURCE_PATH,
			FPS,
			TICK_TIME,
			{ WINDOW_WIDTH, WINDOW_HEIGHT }
	};

	SDL_Window *SDLWindow = createWindow("LakLok", ( ScreenWidth - WINDOW_WIDTH ) / 2, ( ScreenHeight - WINDOW_HEIGHT ) / 2,
	                                     WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer *SDLRenderer = createRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	auto SDLRendererController = new RendererController(SDLRenderer, SDLWindow);

	auto *eventManager = new EventManager();

	auto *gameScene = new GameScenes(SDLRendererController, eventManager, ( const GameProp && ) gameProp);

	menu(gameScene);

	eventManager->on(SDL_MOUSEBUTTONDOWN, [&](SDL_Event event) {
		ComponentPosition clickPosition = { 0, 0, POSITION_ABSOLUTE };
		SDL_GetMouseState(&clickPosition.x, &clickPosition.y);
		gameScene->getCurrentScene()->getContainer()->click(clickPosition, event);
	});

	Scene *lastHoveredScene = nullptr;

	eventManager->on(SDL_MOUSEMOTION, [&](SDL_Event event) {
		ComponentPosition mousePosition = { 0, 0, POSITION_ABSOLUTE };
		SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
		if (lastHoveredScene) {
			lastHoveredScene->getContainer()->unHover(mousePosition, event);
			lastHoveredScene = nullptr;
		}
		gameScene->getCurrentScene()->getContainer()->hover(mousePosition, event);
		lastHoveredScene = gameScene->getCurrentScene();
	});

	SDLRendererController->addRenderer(0, [&](Renderer *renderer, SDL_Renderer *SDLRenderer, SDL_Window *SDLWindow) {
		gameScene->getCurrentScene()->renderScene(renderer);
	});

	auto timer = new Timer();
	timer->setInterval([=]( ) {
		if (gameScene->getCurrentScene()) {
			gameScene->getCurrentScene()->getContainer()->children()->sort([ ](Node<Component *> *fNode, Node<Component *> *sNode) {
				return fNode->getNodeData()->getRenderIndex() <= sNode->getNodeData()->getRenderIndex();
			});
		}
		SDLRendererController->tick();
	}, 1 /*s*/ * ( 1000 /*ms*/ / 1 /*s*/) * ( 1 /*s*/ / FPS /*frames*/));

	timer->setInterval([&]( ) {
		eventManager->gameTick();
		gameScene->getCurrentScene()->gameTick();
	}, TICK_TIME);

	eventManager->init([ ](SDL_Event event) {
		return event.type == SDL_QUIT;
	});

	timer->stop();

	return 0;
}