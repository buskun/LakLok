//
// Created by Acer on 23/5/2562.
//
#include "scene_list.h"
#include <cstdlib>
#include <time.h>

void introGame2(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("introGame2");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
    const GameProp GAME_PROP = gameScenes->getGameProp();

    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    sceneContainer->append(new ImageView(SDLRendererController,
                                         SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/bgmaingame2.png"),
                                         1, {1600, 900}, {0, 0, POSITION_RELATIVE}));

    auto introBG = sceneContainer->append(new ImageView(SDLRendererController,
                                                        SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/howtoGame2.png"),
                                                        10, {1600, 900}, {0, 0, POSITION_RELATIVE}));
    auto button = sceneContainer->append(new Button(SDLRendererController,
                                                    "START", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                              {255, 255, 255}},
                                                    box,
                                                    [=](Touchable *button, ComponentPosition clickPosition,
                                                        SDL_Event event)mutable {
                                                        introBG->show(false);
                                                        button->show(false);

                                                            gameScenes->setCurrentSceneName("mainGame2");
                                                    },
                                                    16, {300, 100}, {1250, 750, POSITION_ABSOLUTE}));
    scene->onEnterScene([=](Scene *currentScene) {
        introBG->show(true);
        button->show(true);
    });
}
