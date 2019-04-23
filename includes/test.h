//
// Created by buskun0 on 06/04/19.
//

#ifndef LAKLOK_TEST_H
#define LAKLOK_TEST_H

#include <fstream>

#include "renderer.h"
#include "SDL_util.h"
#include "util/json.hpp"

#include "util/array.h"
#include "component/view.h"
#include "component/container.h"
#include "component/touchable.h"

int sth(RendererController &SDLRendererController, Event *EventManager,
        std::map<const std::string, Container *> &sceneList, std::string &sceneName,
    const std::string &RESOURCE_PATH, const int &SCREEN_WIDTH, const int &SCREEN_HEIGHT) {

	SDL_Renderer *SDLRenderer = SDLRendererController.getSDLRenderer();
	SDL_Texture *bgtexture = loadTexture(SDLRenderer, RESOURCE_PATH + "/img/background.bmp");
	SDL_Texture *imgtexture = loadTexture(SDLRenderer, RESOURCE_PATH + "/img/image.bmp");
	int bW, bH;
	SDL_QueryTexture(bgtexture, nullptr, nullptr, &bW, &bH);
	int iW, iH;
	SDL_QueryTexture(imgtexture, nullptr, nullptr, &iW, &iH);

	auto *MainContainer = new Container(SDLRendererController);
	MainContainer->setPosition(10, 10);
	MainContainer->append(new TouchableImage(SDLRendererController, imgtexture,
	                                         [ ](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
		                                         std::cout << "Image clicked" << std::endl;
	                                         },
	                                         10, { iW, iH },
	                                         { SCREEN_WIDTH / 2 - iW / 2, SCREEN_HEIGHT / 2 - iH / 2, POSITION_RELATIVE }));
	MainContainer->append(new ImageView(SDLRendererController, bgtexture, 0, { bW, bH }, { 0, 0, POSITION_RELATIVE }));
	MainContainer->append(new ImageView(SDLRendererController, bgtexture, 0, { bW, bH }, { bW, 0, POSITION_RELATIVE }));
	MainContainer->append(new ImageView(SDLRendererController, bgtexture, 0, { bW, bH }, { 0, bH, POSITION_RELATIVE }));
	MainContainer->append(new ImageView(SDLRendererController, bgtexture, 0, { bW, bH }, { bW, bH, POSITION_RELATIVE }));
	auto btn = new Button(SDLRendererController,
	                      "Hello", { 18, RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
	                      bgtexture,
	                      [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
		ComponentPosition currentPos = button->getPosition();
		button->setPosition(currentPos.x + 10, currentPos.y + 10);
	                      },
	                      0, { bW, bH }, { bW, bH, POSITION_ABSOLUTE });
	btn->getTextView()->setHoverText("Bird", { 18, RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }});
	MainContainer->append(btn);
/*	MainContainer->append(( new Container(SDLRendererController))
			                      ->append(new ImageView(SDLRendererController, bgtexture, 0, { 10, 10 }))
			                      ->append(new TouchableText(SDLRendererController,
			                                                 "Hello", 18, RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 },
			                                                 [ ](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
				                                                 cout << (( Button * ) button )->getTextView()->getText() << endl;
			                                                 }, 20)));*/

	MainContainer->children()->sort([ ](Node<Component *> *fNode, Node<Component *> *sNode) {
		return fNode->getNodeData()->getRenderIndex() <= sNode->getNodeData()->getRenderIndex();
	});

	sceneList.insert(std::pair<const std::string, Container *>("menu", MainContainer));

/*	SDLRendererController.addRenderer(0, [=](Renderer *renderer, SDL_Renderer *SDLRenderer, SDL_Window *SDLWindow) {
		MainContainer->render(renderer);
	});*/
//	SDL_Window *SDLWindow = SDLRendererController.getSDLWindow();

/*	SDLRendererController.addRenderer(0, [=](Renderer *renderer, SDL_Renderer *&SDLRenderer, SDL_Window *&SDLWindow) {
		int bW, bH;
		SDL_QueryTexture(bgtexture, nullptr, nullptr, &bW, &bH);
		renderTexture(SDLRenderer, bgtexture, 0, 0);
		renderTexture(SDLRenderer, bgtexture, bW, 0);
		renderTexture(SDLRenderer, bgtexture, 0, bH);
		renderTexture(SDLRenderer, bgtexture, bW, bH);

		int iW, iH;
		SDL_QueryTexture(imgtexture, nullptr, nullptr, &iW, &iH);
		int x = SCREEN_WIDTH / 2 - iW / 2;
		int y = SCREEN_HEIGHT / 2 - iH / 2;
		renderTexture(SDLRenderer, imgtexture, x, y);
	});*/

/*	std::string data, temp;
	std::ifstream file;
	file.open("A:/Projects/LakLok/01.json");
	while (!file.eof()) {
		getline(file, temp);
		data += temp;
	}
	auto j = nlohmann::json::parse(data);
	cout << j[0]["action"]["name"] << endl;*/

/*	Array<int> a;

	a.push(1);
	a.push(5);
	a.unshift(10);
	a.forEach([ ](int index, int id, int Data) {
		cout << index << ":" << id << "->" << Data << endl;
	});
	cout << a.pop() << endl;
	cout << a.shift() << endl;
	cout << a.shift() << endl;
	cout << a.shift() << endl;*/

	return 0;
}

#endif //LAKLOK_TEST_H
