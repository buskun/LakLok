#include "scene_list.h"

void menu(GameScenes *gameScenes) {
	Scene *scene = gameScenes->newScene("menu");
	Container *sceneContainer = scene->getSceneContainer();

	RendererController *rendererController = gameScenes->getRendererController();
	EventManager *eventManager = gameScenes->getEventManager();

	GameProp gameProp = gameScenes->getGameProp();

	auto text = new TextView(rendererController,
	                         "Hello world!",
	                         {24, gameProp.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}});
	text->setHoverText("Hella world!", {24, gameProp.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}});
	sceneContainer->append(text);

	SDL::setCustomCursor(gameProp.RESOURCE_PATH + "/img/image.bmp", 0, 0);
	SDL::setSystemCursor(SDL_SYSTEM_CURSOR_ARROW);

	eventManager->on(SDL_MOUSEBUTTONDOWN, [=](SDL_Event event) {
		text->show(!text->isShown());
		SDL::toggleCursor();
	});

	scene->onGameTick([](Scene *currentScene) {
	});
}