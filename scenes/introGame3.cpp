//
// Created by Acer on 23/5/2562.
//
#include "scene_list.h"
#include <cstdlib>
#include <time.h>

void introGame3(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("introGame3");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
    auto *timer = new Timer();
    const GameProp GAME_PROP = gameScenes->getGameProp();

    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    sceneContainer->append(new ImageView(SDLRendererController,
                                         SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bG_main.png"),
                                         1, {1600, 900}, {0, 0, POSITION_RELATIVE}));
    auto textTime = sceneContainer->append(new TextView(SDLRendererController,
                                                        "-",
                                                        {200, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                                                        50, {750, 300, POSITION_ABSOLUTE}));
    textTime->show(false);
    auto introBG = sceneContainer->append(new ImageView(SDLRendererController,
                                                        SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame3/howtoGame3.png"),
                                                        10, {1600, 900}, {0, 0, POSITION_RELATIVE}));
    auto boxC = sceneContainer->append(new ImageView(SDLRendererController, box, 10, {200, 250}, {705, 290, POSITION_RELATIVE}))->show(false);
    auto button = sceneContainer->append(new Button(SDLRendererController,
                                                    "START", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                              {255, 255, 255}},
                                                    box,
                                                    [=](Touchable *button, ComponentPosition clickPosition,
                                                        SDL_Event event)mutable {
                                                        textTime->show(true);
                                                        introBG->show(false);
                                                        button->show(false);

                                                        int count = 3;
                                                        textTime->changeText(std::to_string(count--));
                                                        timer->setInterval([=]() mutable {
                                                            textTime->changeText(std::to_string(count--));
                                                        }, 1000);
                                                        timer->setTimeout([=]() {
                                                            gameScenes->setCurrentSceneName("mainGame3");
                                                            timer->stop();
                                                        }, 3000);
                                                        boxC->show(true);
                                                    },
                                                    16, {300, 100}, {1250, 750, POSITION_ABSOLUTE}));
    scene->onEnterScene([=](Scene *currentScene) {
        introBG->show(true);
        textTime->show(false);
        button->show(true);
        boxC->show(false);
    });
}

