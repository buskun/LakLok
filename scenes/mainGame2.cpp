#include "scene_list.h"

void mainGame2(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("mainGame2");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
    const GameProp GAME_PROP = gameScenes->getGameProp();
    GameProp gameProp = gameScenes->getGameProp();
    int bW, bH;
    int *wateron = new int{0};
    int *seedon = new int{0};
    int *composton = new int{0};
    int *watergetA = new int{0};
    int *seedgetA = new int{0};
    int *compostgetA = new int{0};
    int *watergetB = new int{0};
    int *seedgetB = new int{0};
    int *compostgetB = new int{0};
    int *watergetC = new int{0};
    int *seedgetC = new int{0};
    int *compostgetC = new int{0};
    int *watergetD = new int{0};
    int *seedgetD = new int{0};
    int *compostgetD = new int{0};
    int *checkLvOftree = new int{0};
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/bgmaingame2.png");
    SDL_Texture *compost = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/compost.png");
    SDL_Texture *lvone = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv1.png");
    SDL_Texture *lvtwo = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv2.png");
    SDL_Texture *lvthree = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv3.png");
    SDL_Texture *lvfour = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv4.png");
    SDL_Texture *seed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png");
    SDL_Texture *shopN = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/ShopNo.png");
    SDL_Texture *waterIng = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/watering.png");
    SDL_Texture *water = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/water.png");
    SDL_Texture *land = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/land.png");
    SDL_Texture *landWater = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landWater.png");
    SDL_Texture *goB = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Gob.png");
    SDL_Texture *landwSeed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwSeed.png");
    SDL_Texture *landwWaterwSeed = SDL::loadTexture(SDLRenderer,
                                                    GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwWaterwSeed.png");
    SDL_Texture *goB2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Gob2.png");
    int *money = new int{0};
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto lv1on1 = new ImageView(SDLRendererController, lvone, 100, {200, 200}, {290, 550, POSITION_RELATIVE});
    auto lv1on2 = new ImageView(SDLRendererController, lvone, 50, {50, 50}, {615, 550, POSITION_RELATIVE});
    auto lv1on3 = new ImageView(SDLRendererController, lvone, 50, {50, 50}, {940, 550, POSITION_RELATIVE});
    auto lv1on4 = new ImageView(SDLRendererController, lvone, 50, {50, 50}, {1265,550, POSITION_RELATIVE});
    auto landwaterseed1lv1 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                    /* SDL::useSystemCursor();
                                                     *compostgetA = 0;
                                                     if (*checkLvOftree == 0) {
                                                         lv1on1->show(true);

                                                     }
                                                     if (*checkLvOftree == 1) {
                                                         lv1on1->show(true);
                                                         *checkLvOftree = 2;
                                                         lv1on1->show(false);
                                                     }
                                                     if (*checkLvOftree == 2) {
                                                         lv1on1->show(true);
                                                         *checkLvOftree = 3;
                                                         lv1on1->show(false);
                                                     }
                                                     if (*checkLvOftree == 3) {
                                                         lv1on1->show(true);
                                                         *checkLvOftree = 4;
                                                         lv1on1->show(false);
                                                     }
                                                     if (*checkLvOftree == 4) {
                                                         lv1on1->show(true);
                                                         *checkLvOftree = 5;
                                                         lv1on1->show(false);
                                                     }
                                                     (*checkLvOftree)++ ;*/

                                                 }
                                             },
                                             1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landwaterseed2lv1 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetA = 1;
                                                     lv1on2->show(true);
                                                 }
                                             },
                                             1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landwaterseed3lv1 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetC = 1;
                                                     lv1on3->show(true);
                                                 }
                                             },
                                             1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landwaterseed4lv1 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetD = 1;
                                                     lv1on4->show(true);
                                                 }
                                             },
                                             1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});

    auto landseed1lv1 = new TouchableImage(SDLRendererController,
                                        landwSeed,
                                        [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                            if (SDL::isCustomCursor && *composton == 1) {
                                                SDL::useSystemCursor();
                                                *compostgetA = 1;
                                                *composton = 0;
                                            }
                                            if (SDL::isCustomCursor && *wateron == 1) {
                                                SDL::useSystemCursor();
                                                *watergetA = 1;
                                                *wateron = 0;
                                                landwaterseed1lv1->show(true);
                                                std::cout << "kuy";
                                                button->show(false);
                                            }
                                        },
                                        2, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landseed2lv1 = new TouchableImage(SDLRendererController,
                                        landwSeed,
                                        [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                            if (SDL::isCustomCursor && *composton == 1) {
                                                SDL::useSystemCursor();
                                                *compostgetB = 1;
                                                *composton = 0;
                                            }
                                            if (SDL::isCustomCursor && *wateron == 1) {
                                                SDL::useSystemCursor();
                                                *wateron = 0;
                                                landwaterseed2lv1->show(true);
                                                button->show(false);
                                            }
                                        },
                                        2, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landseed3lv1 = new TouchableImage(SDLRendererController,
                                        landwSeed,
                                        [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                            if (SDL::isCustomCursor && *composton == 1) {
                                                SDL::useSystemCursor();
                                                *compostgetC = 1;
                                                *composton = 0;
                                            }
                                            if (SDL::isCustomCursor && *wateron == 1) {
                                                SDL::useSystemCursor();
                                                *wateron = 0;
                                                landwaterseed3lv1->show(true);
                                                button->show(false);
                                            }
                                        },
                                        2, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landseed4lv1 = new TouchableImage(SDLRendererController,
                                        landwSeed,
                                        [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                            if (SDL::isCustomCursor && *composton == 1) {
                                                SDL::useSystemCursor();
                                                *compostgetD = 1;
                                                *composton = 0;
                                            }
                                            if (SDL::isCustomCursor && *wateron == 1) {
                                                SDL::useSystemCursor();
                                                *wateron = 0;
                                                landwaterseed4lv1->show(true);
                                                button->show(false);
                                            }
                                        },
                                        2, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto landwater1lv1 = new TouchableImage(SDLRendererController,
                                         landWater,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             if (SDL::isCustomCursor && *composton == 1) {
                                                 SDL::useSystemCursor();
                                                 *compostgetA = 1;
                                                 *composton = 0;
                                             }
                                             if (SDL::isCustomCursor && *seedon == 1) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed1lv1->show(true);
                                                 button->show(false);
                                             }
                                         },
                                         1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landwater2lv1 = new TouchableImage(SDLRendererController,
                                         landWater,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             if (SDL::isCustomCursor && *composton == 1) {
                                                 SDL::useSystemCursor();
                                                 *compostgetB = 1;
                                                 *composton = 0;
                                             }
                                             if (SDL::isCustomCursor && *seedon == 1) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed2lv1->show(true);
                                                 button->show(false);
                                             }
                                         },
                                         1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landwater3lv1 = new TouchableImage(SDLRendererController,
                                         landWater,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             if (SDL::isCustomCursor && *composton == 1) {
                                                 SDL::useSystemCursor();
                                                 *compostgetC = 1;
                                                 *composton = 0;
                                                 landwaterseed1lv1->show(true);
                                             }
                                             if (SDL::isCustomCursor && *seedon == 1) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed3lv1->show(true);
                                                 button->show(false);
                                             }
                                         },
                                         1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landwater4lv1 = new TouchableImage(SDLRendererController,
                                         landWater,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             if (SDL::isCustomCursor && *composton == 1) {
                                                 SDL::useSystemCursor();
                                                 *compostgetD = 1;
                                                 *composton = 0;
                                             }
                                             if (SDL::isCustomCursor && *seedon == 1) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed4lv1->show(true);
                                                 button->show(false);
                                             }
                                         },
                                         1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto land1lv1 = new TouchableImage(SDLRendererController,
                                    land,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            landwater1lv1->show(true);
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetA = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *seedon == 1) {
                                            landseed1lv1->show(true);
                                            SDL::useSystemCursor();
                                            *seedon = 0;
                                            *seedgetA = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetA = 1;
                                            *composton = 0;
                                        }
                                    },
                                    1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    sceneContainer->append(land1lv1->show(false));
    auto land2lv1 = new TouchableImage(SDLRendererController,
                                    land,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            landwater2lv1->show(true);
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetB = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *seedon == 1) {
                                            landseed2lv1->show(true);
                                            SDL::useSystemCursor();
                                            *seedon = 0;
                                            *seedgetB = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetB = 1;
                                            *composton = 0;
                                        }
                                    },
                                    1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto land3lv1 = new TouchableImage(SDLRendererController,
                                    land,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            landwater3lv1->show(true);
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetC = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *seedon == 1) {
                                            landseed3lv1->show(true);
                                            SDL::useSystemCursor();
                                            *seedon = 0;
                                            *seedgetC = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetC = 1;
                                            *composton = 0;
                                        }
                                    },
                                    1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto land4lv1 = new TouchableImage(SDLRendererController,
                                    land,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            landwater4lv1->show(true);
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetD = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *seedon == 1) {
                                            landseed4lv1->show(true);
                                            SDL::useSystemCursor();
                                            *seedon = 0;
                                            *seedgetD = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetD = 1;
                                            *composton = 0;
                                        }
                                    },
                                    1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
//------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------//
    auto landwaterseed1 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetA = 0;
                                                     if (*checkLvOftree == 0) {
                                                         lv1on1->show(true);
                                                         button->show(false);
                                                         land1lv1->show(true);
                                                     }
                                                     if (*checkLvOftree == 1) {
                                                         lv1on1->show(true);
                                                         *checkLvOftree = 2;
                                                         lv1on1->show(false);
                                                     }
                                                     if (*checkLvOftree == 2) {
                                                         lv1on1->show(true);
                                                         *checkLvOftree = 3;
                                                         lv1on1->show(false);
                                                     }
                                                     if (*checkLvOftree == 3) {
                                                         lv1on1->show(true);
                                                         *checkLvOftree = 4;
                                                         lv1on1->show(false);
                                                     }
                                                     if (*checkLvOftree == 4) {
                                                         lv1on1->show(true);
                                                         *checkLvOftree = 5;
                                                         lv1on1->show(false);
                                                     }
                                                     (*checkLvOftree)++ ;

                                                 }
                                             },
                                             1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landwaterseed2 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetA = 1;
                                                     lv1on2->show(true);
                                                 }
                                             },
                                             1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landwaterseed3 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetC = 1;
                                                     lv1on3->show(true);
                                                 }
                                             },
                                             1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landwaterseed4 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetD = 1;
                                                     lv1on4->show(true);
                                                 }
                                             },
                                             1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});

    auto landseed1 = new TouchableImage(SDLRendererController,
                                        landwSeed,
                                        [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                            if (SDL::isCustomCursor && *composton == 1) {
                                                SDL::useSystemCursor();
                                                *compostgetA = 1;
                                                *composton = 0;
                                            }
                                            if (SDL::isCustomCursor && *wateron == 1) {
                                                SDL::useSystemCursor();
                                                *watergetA = 1;
                                                *wateron = 0;
                                                landwaterseed1->show(true);
                                                std::cout << "kuy";
                                                button->show(false);
                                            }
                                        },
                                        2, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landseed2 = new TouchableImage(SDLRendererController,
                                        landwSeed,
                                        [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                            if (SDL::isCustomCursor && *composton == 1) {
                                                SDL::useSystemCursor();
                                                *compostgetB = 1;
                                                *composton = 0;
                                            }
                                            if (SDL::isCustomCursor && *wateron == 1) {
                                                SDL::useSystemCursor();
                                                *wateron = 0;
                                                landwaterseed2->show(true);
                                                button->show(false);
                                            }
                                        },
                                        2, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landseed3 = new TouchableImage(SDLRendererController,
                                        landwSeed,
                                        [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                            if (SDL::isCustomCursor && *composton == 1) {
                                                SDL::useSystemCursor();
                                                *compostgetC = 1;
                                                *composton = 0;
                                            }
                                            if (SDL::isCustomCursor && *wateron == 1) {
                                                SDL::useSystemCursor();
                                                *wateron = 0;
                                                landwaterseed3->show(true);
                                                button->show(false);
                                            }
                                        },
                                        2, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landseed4 = new TouchableImage(SDLRendererController,
                                        landwSeed,
                                        [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                            if (SDL::isCustomCursor && *composton == 1) {
                                                SDL::useSystemCursor();
                                                *compostgetD = 1;
                                                *composton = 0;
                                            }
                                            if (SDL::isCustomCursor && *wateron == 1) {
                                                SDL::useSystemCursor();
                                                *wateron = 0;
                                                landwaterseed4->show(true);
                                                button->show(false);
                                            }
                                        },
                                        2, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto waterIcon = new ImageView(SDLRendererController, water, 2, {200, 200}, {100, 400, POSITION_RELATIVE});
    auto landwater1 = new TouchableImage(SDLRendererController,
                                         landWater,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             if (SDL::isCustomCursor && *composton == 1) {
                                                 SDL::useSystemCursor();
                                                 *compostgetA = 1;
                                                 *composton = 0;

                                             }
                                             if (SDL::isCustomCursor && *seedon == 1) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed1->show(true);
                                                 button->show(false);
                                             }
                                         },
                                         1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landwater2 = new TouchableImage(SDLRendererController,
                                         landWater,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             if (SDL::isCustomCursor && *composton == 1) {
                                                 SDL::useSystemCursor();
                                                 *compostgetB = 1;
                                                 *composton = 0;
                                             }
                                             if (SDL::isCustomCursor && *seedon == 1) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed2->show(true);
                                                 button->show(false);
                                             }
                                         },
                                         1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landwater3 = new TouchableImage(SDLRendererController,
                                         landWater,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             if (SDL::isCustomCursor && *composton == 1) {
                                                 SDL::useSystemCursor();
                                                 *compostgetC = 1;
                                                 *composton = 0;
                                                 landwaterseed1->show(true);
                                             }
                                             if (SDL::isCustomCursor && *seedon == 1) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed3->show(true);
                                                 button->show(false);
                                             }
                                         },
                                         1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landwater4 = new TouchableImage(SDLRendererController,
                                         landWater,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             if (SDL::isCustomCursor && *composton == 1) {
                                                 SDL::useSystemCursor();
                                                 *compostgetD = 1;
                                                 *composton = 0;
                                             }
                                             if (SDL::isCustomCursor && *seedon == 1) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed4->show(true);
                                                 button->show(false);
                                             }
                                         },
                                         1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    auto land1 = new TouchableImage(SDLRendererController,
                                    land,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            landwater1->show(true);
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetA = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *seedon == 1) {
                                            landseed1->show(true);
                                            SDL::useSystemCursor();
                                            *seedon = 0;
                                            *seedgetA = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetA = 1;
                                            *composton = 0;
                                        }

                                    },
                                    1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto land2 = new TouchableImage(SDLRendererController,
                                    land,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            landwater2->show(true);
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetB = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *seedon == 1) {
                                            landseed2->show(true);
                                            SDL::useSystemCursor();
                                            *seedon = 0;
                                            *seedgetB = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetB = 1;
                                            *composton = 0;
                                        }
                                    },
                                    1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto land3 = new TouchableImage(SDLRendererController,
                                    land,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            landwater3->show(true);
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetC = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *seedon == 1) {
                                            landseed3->show(true);
                                            SDL::useSystemCursor();
                                            *seedon = 0;
                                            *seedgetC = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetC = 1;
                                            *composton = 0;
                                        }
                                    },
                                    1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto land4 = new TouchableImage(SDLRendererController,
                                    land,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            landwater4->show(true);
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetD = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *seedon == 1) {
                                            landseed4->show(true);
                                            SDL::useSystemCursor();
                                            *seedon = 0;
                                            *seedgetD = 1;
                                            button->show(false);
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetD = 1;
                                            *composton = 0;
                                        }
                                    },
                                    1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});

    auto btnshop = new TouchableImage(SDLRendererController,
                                      shopN,
                                      [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                          gameScenes->setCurrentSceneName("mainGame2Shop");
                                      },
                                      3, {150, 100}, {100, 25, POSITION_RELATIVE});
    auto btnwater = new TouchableImage(SDLRendererController,
                                       water,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           SDL::setCustomCursor(GAME_PROP.RESOURCE_PATH + "/img/maingame2/watering.png",
                                                                50, 50);
                                           SDL::useCustomCursor();
                                           *wateron = 1;
                                       },
                                       3, {150, 100}, {105, 20, POSITION_RELATIVE});
    auto btnseed = new TouchableImage(SDLRendererController,
                                      seed,
                                      [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                          SDL::setCustomCursor(GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png",
                                                               50, 50);
                                          SDL::useCustomCursor();
                                          *seedon = 1;
                                      },
                                      3, {150, 150}, {110, 0, POSITION_RELATIVE});
    auto btncompost = new TouchableImage(SDLRendererController,
                                         compost,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             SDL::setCustomCursor(
                                                     GAME_PROP.RESOURCE_PATH + "/img/maingame2/compost.png",
                                                     50, 50);
                                             SDL::useCustomCursor();
                                             *composton = 1;
                                         },
                                         3, {100, 100}, {125, 25, POSITION_RELATIVE});
    auto boxmoney = sceneContainer->append(new Button(SDLRendererController,
                                                      "Your score = ",
                                                      {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                       {0, 0, 0}},
                                                      goB2,
                                                      [=](Touchable *button, ComponentPosition clickPosition,
                                                          SDL_Event event) mutable {
                                                      },
                                                      50, {625, 100}, {1000, 50, POSITION_ABSOLUTE}));
    boxmoney->getTextView()->changeText("Your money = " + std::to_string(*money));
    ComponentSize textSize = boxmoney->getTextView()->getSize();
    boxmoney->getTextView()->setPosition({(boxmoney->getSize().width - textSize.width) / 2,
                                          (boxmoney->getSize().height - textSize.height) / 2});
    auto icon1Container = new Container(SDLRendererController, 2, {360, 150}, {25, 700, POSITION_ABSOLUTE});
    icon1Container->append(new ImageView(SDLRendererController, goB, 2, {360, 150}, {0, 0, POSITION_RELATIVE}));
    icon1Container->append(btnshop);
    sceneContainer->append(icon1Container);
    auto icon2Container = new Container(SDLRendererController, 2, {360, 150}, {275, 700, POSITION_ABSOLUTE});
    icon2Container->append(new ImageView(SDLRendererController, goB, 2, {360, 150}, {0, 0, POSITION_RELATIVE}));
    icon2Container->append(btnwater);
    sceneContainer->append(icon2Container);
    auto icon3Container = new Container(SDLRendererController, 2, {360, 150}, {525, 700, POSITION_ABSOLUTE});
    icon3Container->append(new ImageView(SDLRendererController, goB, 2, {360, 150}, {0, 0, POSITION_RELATIVE}));
    icon3Container->append(btnseed);
    sceneContainer->append(icon3Container);
    auto icon4Container = new Container(SDLRendererController, 2, {360, 150}, {775, 700, POSITION_ABSOLUTE});
    icon4Container->append(new ImageView(SDLRendererController, goB, 2, {360, 150}, {0, 0, POSITION_RELATIVE}));
    icon4Container->append(btncompost);
    sceneContainer->append(icon4Container);
    sceneContainer->append(land2);
    sceneContainer->append(land3);
    sceneContainer->append(land4);
    sceneContainer->append(landwaterseed1);
    landwaterseed1->show(false);
    sceneContainer->append(landwaterseed2);
    landwaterseed2->show(false);
    sceneContainer->append(landwaterseed3);
    landwaterseed3->show(false);
    sceneContainer->append(landwaterseed4);
    landwaterseed4->show(false);
    waterIcon->show(false);
    sceneContainer->append(landwater1);
    landwater1->show(false);
    sceneContainer->append(landwater2);
    landwater2->show(false);
    sceneContainer->append(landwater3);
    landwater3->show(false);
    sceneContainer->append(landwater4);
    landwater4->show(false);
    sceneContainer->append(landseed1);
    landseed1->show(false);
    sceneContainer->append(landseed2);
    landseed2->show(false);
    sceneContainer->append(landseed3);
    landseed3->show(false);
    sceneContainer->append(landseed4);
    landseed4->show(false);
    sceneContainer->append(lv1on1->show(false));
    sceneContainer->append(lv1on2->show(false));
    sceneContainer->append(lv1on3->show(false));
    sceneContainer->append(lv1on4->show(false));
    sceneContainer->append(land1);
    //------------------------------------------------//
    sceneContainer->append(land2lv1);
    sceneContainer->append(land3lv1);
    sceneContainer->append(land4lv1);
    sceneContainer->append(landwaterseed1lv1);
    landwaterseed1lv1->show(false);
    sceneContainer->append(landwaterseed2lv1);
    landwaterseed2lv1->show(false);
    sceneContainer->append(landwaterseed3lv1);
    landwaterseed3lv1->show(false);
    sceneContainer->append(landwaterseed4lv1);
    landwaterseed4lv1->show(false);
    sceneContainer->append(landwater1lv1);
    landwater1lv1->show(false);
    sceneContainer->append(landwater2lv1);
    landwater2lv1->show(false);
    sceneContainer->append(landwater3lv1);
    landwater3lv1->show(false);
    sceneContainer->append(landwater4lv1);
    landwater4lv1->show(false);
    sceneContainer->append(landseed1lv1);
    landseed1lv1->show(false);
    sceneContainer->append(landseed2lv1);
    landseed2lv1->show(false);
    sceneContainer->append(landseed3lv1);
    landseed3lv1->show(false);
    sceneContainer->append(landseed4lv1);
    landseed4lv1->show(false);
    sceneContainer->append(land1lv1);



}