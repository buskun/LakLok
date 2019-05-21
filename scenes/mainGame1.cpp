#include "scene_list.h"
#include <cstdlib>
#include <time.h>

void mainGame1(GameScenes *gameScenes) {
	Scene *scene = gameScenes->newScene("mainGame1");
	Container *sceneContainer = scene->getSceneContainer();
	RendererController *SDLRendererController = gameScenes->getRendererController();
	SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
	const GameProp GAME_PROP = gameScenes->getGameProp();
	auto *timer = new Timer();
	SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");

	sceneContainer->append(new ImageView(SDLRendererController,
	                                     SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/bgmaingame1.jpg"),
	                                     -1, {1600, 900}, {0, 0, POSITION_RELATIVE}));
	ImageView *game1Q[12];
	for (int i = 1; i <= 12; i++) {
		if (1 <= i && i <= 3)
			game1Q[i - 1] = new ImageView(SDLRendererController,
			                              SDL::loadTexture(SDLRenderer,
			                                               GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeBlue" + std::to_string(i) + ".png"),
			                              10, {300, 300}, {645, 300, POSITION_RELATIVE});
		if (4 <= i && i <= 6)
			game1Q[i - 1] = new ImageView(SDLRendererController,
			                              SDL::loadTexture(SDLRenderer,
			                                               GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeRed" + std::to_string(i - 3) + ".png"),
			                              10, {300, 300}, {645, 300, POSITION_RELATIVE});
		if (7 <= i && i <= 9)
			game1Q[i - 1] = new ImageView(SDLRendererController,
			                              SDL::loadTexture(SDLRenderer,
			                                               GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeGreen" + std::to_string(i - 6) + ".png"),
			                              10, {300, 300}, {645, 300, POSITION_RELATIVE});
		if (10 <= i && i <= 12)
			game1Q[i - 1] = new ImageView(SDLRendererController,
			                              SDL::loadTexture(SDLRenderer,
			                                               GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeYellow" + std::to_string(i - 9) + ".png"),
			                              10, {300, 300}, {645, 300, POSITION_RELATIVE});
		sceneContainer->append(game1Q[i - 1]->show(false));
	}
	auto gameC = sceneContainer->append(new ImageView(SDLRendererController,
	                                                  SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/true.png"),
	                                                  10, {300, 300}, {300, 300, POSITION_RELATIVE}))->show(false);
	auto gameX = sceneContainer->append(new ImageView(SDLRendererController,
	                                                  SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/false.png"),
	                                                  10, {300, 300}, {300, 300, POSITION_RELATIVE}))->show(false);
	auto boxOfTime = sceneContainer->append(new ImageView(SDLRendererController, box, 2, {300, 100}, {645, 25, POSITION_RELATIVE}));
	auto textTime = sceneContainer->append(new TextView(SDLRendererController,
	                                                    "-",
	                                                    {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
	                                                    3, {770, 50, POSITION_ABSOLUTE}));

	bool *answer = new bool[4]{false, false, false, false};
	int *lastQuestion = new int{-1};
	auto showNewQuestion = [=]() mutable {
		srand(time(nullptr));
		int randomQ;

		do randomQ = rand() % 12;
		while (randomQ == *lastQuestion);
		*lastQuestion = randomQ;

		for (auto &question : game1Q) question->show(false);
		for (int i = 0; i < 4; i++) answer[i] = false;

		game1Q[randomQ]->show(true);
		answer[randomQ / 3] = true;
	};
	int *score = new int{0};
	bool *answering = new bool{false};
	auto canClickFunction = [=](int index) mutable {
		return [=](Touchable *button, ComponentPosition clickPosition,
		           SDL_Event event) mutable {
			if (*answering) return;
			*answering = true;
			auto result = answer[index] ? gameC : gameX;
			*score += answer[index] ? 100 : 0;
			result->show(true);
			timer->setTimeout([=]() mutable {
				result->show(false);
				showNewQuestion();
				*answering = false;
			}, 1000);
		};
	};
	auto canBlueA = sceneContainer->append(new TouchableImage(SDLRendererController,
	                                                          SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/canBlue.png"),
	                                                          canClickFunction(0),
	                                                          2, {600, 600}, {50, 500, POSITION_RELATIVE}));
	auto canRedB = sceneContainer->append(new TouchableImage(SDLRendererController,
	                                                         SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/canRed.png"),
	                                                         canClickFunction(1),
	                                                         2, {600, 600}, {350, 500, POSITION_RELATIVE}));
	auto canGreenC = sceneContainer->append(new TouchableImage(SDLRendererController,
	                                                           SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/canGreen.png"),
	                                                           canClickFunction(2),
	                                                           2, {600, 600}, {650, 500, POSITION_RELATIVE}));
	auto canYellowD = sceneContainer->append(new TouchableImage(SDLRendererController,
	                                                            SDL::loadTexture(SDLRenderer,
	                                                                             GAME_PROP.RESOURCE_PATH + "/img/maingame1/canYellow.png"),
	                                                            canClickFunction(3),
	                                                            2, {600, 600}, {950, 500, POSITION_RELATIVE}));
	auto boxEnd = sceneContainer->append(new Button(SDLRendererController,
	                                                "Your score = ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
	                                                                  {255, 255, 255}},
	                                                box,
	                                                [=](Touchable *button, ComponentPosition clickPosition,
	                                                    SDL_Event event) mutable {
	                                                },
	                                                50, {500, 300}, {600, 300, POSITION_ABSOLUTE}));
	boxEnd->show(false);

	auto backToMenu = sceneContainer->append(new Button(SDLRendererController,
	                                                    "MENU",
	                                                    {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
	                                                     {255, 255, 255}},
	                                                    box,
	                                                    [=](Touchable *button, ComponentPosition clickPosition,
	                                                        SDL_Event event) mutable {
		                                                    gameScenes->setCurrentSceneName("menu");
	                                                    },
	                                                    16, {300, 100}, {1250, 750, POSITION_ABSOLUTE}))->show(false);
	auto init = [=]() mutable {
		*lastQuestion = -1;
		*score = 0;
		*answering = false;
		for (int i = 0; i < 4; i++) answer[i] = false;
		for (auto &question : game1Q) question->show(false);
		boxOfTime->show(true);
		textTime->show(true);
		canBlueA->show(true);
		canRedB->show(true);
		canGreenC->show(true);
		canYellowD->show(true);
		boxEnd->show(false);
		backToMenu->show(false);
		showNewQuestion();
	};

	scene->onEnterScene([=](Scene *scene) mutable {
		init();
		int imgState = 60;
		textTime->changeText(std::to_string(imgState));
		timer->setInterval([=]() mutable {
			textTime->changeText(std::to_string(--imgState));
			if (imgState <= 0) {
				boxEnd->getTextView()->changeText("Your score = " + std::to_string(*score));
				ComponentSize textSize = boxEnd->getTextView()->getSize();
				boxEnd->getTextView()->setPosition({(boxEnd->getSize().width - textSize.width) / 2,
				                                    (boxEnd->getSize().height - textSize.height) / 2});
				for (auto &question : game1Q) question->show(false);
				gameC->show(false);
				gameX->show(false);
				boxOfTime->show(false);
				textTime->show(false);
				canBlueA->show(false);
				canRedB->show(false);
				canGreenC->show(false);
				canYellowD->show(false);
				boxEnd->show(true);
				backToMenu->show(true);
				timer->stop();
			}
		}, 1000);
	});

	scene->onExitScene([=](Scene *scene) mutable {
		timer->stop();
	});
}