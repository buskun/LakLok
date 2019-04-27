//
// Created by buskun0 on 06/04/19.
//

#ifndef LAKLOK_TEST_H
#define LAKLOK_TEST_H

#include <fstream>

#include "renderer.h"
#include "SDL_util.h"

#include "util/array.h"
#include "component/view.h"
#include "component/container.h"
#include "component/touchable.h"

int menu(GameScenes *gameScenes) {
	Scene *scene = gameScenes->newScene("menu");
	gameScenes->addScene(scene);

	Container *sceneContainer = scene->getContainer();

	RendererController *SDLRendererController = gameScenes->getRendererController();
	SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

	const GameProp GAME_PROP = gameScenes->getGameProp();

	SDL_Texture *bgTexture = loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/background.bmp");
	SDL_Texture *imgTexture = loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/image.bmp");
	int bW, bH;
	SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
	int iW, iH;
	SDL_QueryTexture(imgTexture, nullptr, nullptr, &iW, &iH);

	sceneContainer->setPosition(10, 10);
	sceneContainer->append(new TouchableImage(SDLRendererController, imgTexture,
	                                          [ ](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
		                                          std::cout << "Image clicked" << std::endl;
	                                          },
	                                          10, { iW, iH },
	                                          { GAME_PROP.WINDOW.WIDTH / 2 - iW / 2, GAME_PROP.WINDOW.HEIGHT / 2 - iH / 2,
	                                            POSITION_RELATIVE }));
	sceneContainer->append(new ImageView(SDLRendererController, bgTexture, 0, { bW, bH }, { 0, 0, POSITION_RELATIVE }));
	sceneContainer->append(new ImageView(SDLRendererController, bgTexture, 0, { bW, bH }, { bW, 0, POSITION_RELATIVE }));
	sceneContainer->append(new ImageView(SDLRendererController, bgTexture, 0, { bW, bH }, { 0, bH, POSITION_RELATIVE }));
	sceneContainer->append(new ImageView(SDLRendererController, bgTexture, 0, { bW, bH }, { bW, bH, POSITION_RELATIVE }));

	auto btn = new Button(SDLRendererController,
	                      "Hello", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
	                      bgTexture,
	                      [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
		                      ComponentPosition currentPos = button->getPosition();
		                      button->setPosition(currentPos.x + 10, currentPos.y + 10);
	                      },
	                      0, { bW, bH }, { bW, bH, POSITION_ABSOLUTE });
	btn->getTextView()->setHoverText("Bird", { 18, GAME_PROP.RESOURCE_PATH  + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }});
	sceneContainer->append(btn);

	scene->addTick([ ](Container *container, RendererController *rendererController, Scene *scene) {
	});

	sceneContainer->children()->sort([ ](Node<Component *> *fNode, Node<Component *> *sNode) {
		return fNode->getNodeData()->getRenderIndex() <= sNode->getNodeData()->getRenderIndex();
	});

	return 0;
}

#endif //LAKLOK_TEST_H
