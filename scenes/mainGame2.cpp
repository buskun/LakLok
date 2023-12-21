#include "scene_list.h"
#include <cstdlib>
#include <time.h>

void mainGame2(GameScenes *gameScenes, Game *game) {
    Scene *scene = gameScenes->newScene("mainGame2");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
    const GameProp GAME_PROP = gameScenes->getGameProp();
    GameProp gameProp = gameScenes->getGameProp();
    int bW, bH;
    int *score = new int{0};
    int *numberofseed = new int{1};
    *numberofseed = game->getSeed();
    int *wateron = new int{0};
    int *seedon = new int{0};
    int *composton = new int{0};
    int *Axeon = new int{0};
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
    int *numberofitem = new int{0};
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/bgmaingame2.png");
    SDL_Texture *compost = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/compost.png");
    SDL_Texture *lvone = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landlv1.png");
    SDL_Texture *lvonewater = SDL::loadTexture(SDLRenderer,
                                               GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwwaterlv1.png");
    SDL_Texture *lvtwo = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landlv2.png");
    SDL_Texture *lvtwowater = SDL::loadTexture(SDLRenderer,
                                               GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwwaterlv2.png");
    SDL_Texture *lvthree = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landlv3.png");
    SDL_Texture *lvthteewater = SDL::loadTexture(SDLRenderer,
                                                 GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwwaterlv3.png");
    SDL_Texture *lvfour = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landlv4.png");
    SDL_Texture *lvfourwater = SDL::loadTexture(SDLRenderer,
                                                GAME_PROP.RESOURCE_PATH + "/img/maingame2/landlv4wwater.png");
    SDL_Texture *lvfive = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv5.png");
    SDL_Texture *seed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png");
    SDL_Texture *shopN = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/ShopNo.png");
    SDL_Texture *water = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/water.png");
    SDL_Texture *land = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/land.png");
    SDL_Texture *landWater = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landWater.png");
    SDL_Texture *goB = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Gob.png");
    SDL_Texture *landwSeed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwSeed.png");
    SDL_Texture *landwWaterwSeed = SDL::loadTexture(SDLRenderer,
                                                    GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwWaterwSeed.png");
    SDL_Texture *goB2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Gob2.png");
    SDL_Texture *axe = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/ax.png");
    SDL_Texture *item = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/cabinet.png");
    SDL_Texture *item2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/chair.png");
    SDL_Texture *item3 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/itempaper.png");
    SDL_Texture *item4 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/table.png");
    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    auto Gotitem1 = new ImageView(SDLRendererController, item, 1, {400, 400}, {625, 100, POSITION_RELATIVE});
    auto Gotitem2 = new ImageView(SDLRendererController, item2, 1, {400, 400}, {625, 100, POSITION_RELATIVE});
    auto Gotitem3 = new ImageView(SDLRendererController, item3, 1, {400, 400}, {625, 85, POSITION_RELATIVE});
    auto Gotitem4 = new ImageView(SDLRendererController, item4, 1, {400, 400}, {625, 100, POSITION_RELATIVE});
    sceneContainer->append(Gotitem1->show(false));
    sceneContainer->append(Gotitem2->show(false));
    sceneContainer->append(Gotitem3->show(false));
    sceneContainer->append(Gotitem4->show(false));
    auto boxitem = sceneContainer->append(new Button(SDLRendererController,
                                                     "Your Got item ",
                                                     {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                      {255, 255, 255}},
                                                     box,
                                                     [=](Touchable *button, ComponentPosition clickPosition,
                                                         SDL_Event event) mutable {
                                                     },
                                                     50, {350, 100}, {650, 25, POSITION_ABSOLUTE}));
    sceneContainer->append(boxitem->show(false));
    int *money = new int{0};
    auto *timer = new Timer();
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto seedshow = sceneContainer->append(new TextView(SDLRendererController,
                                                        "x1",
                                                        {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                                         {0, 0, 0}},
                                                        50, {750, 775, POSITION_ABSOLUTE}));
    sceneContainer->append(seedshow);
    seedshow->changeText("x" + std::to_string(*numberofseed));
    auto boxmoney = sceneContainer->append(new Button(SDLRendererController,
                                                      "-",
                                                      {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                       {0, 0, 0}},
                                                      goB2,
                                                      [=](Touchable *button, ComponentPosition clickPosition,
                                                          SDL_Event event) mutable {
                                                      },
                                                      50, {750, 100}, {950, 50, POSITION_ABSOLUTE}));
    boxmoney->getTextView()->changeText("Your money = " + std::to_string(*money));
    ComponentSize textSize = boxmoney->getTextView()->getSize();
    boxmoney->getTextView()->setPosition({(boxmoney->getSize().width - textSize.width) / 2 - 50,
                                          (boxmoney->getSize().height - textSize.height) / 2});
    auto **land1 = new TouchableImage *;
    auto **land2 = new TouchableImage *;
    auto **land3 = new TouchableImage *;
    auto **land4 = new TouchableImage *;
    auto tree1 = new TouchableImage(SDLRendererController,
                                    lvfive,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetA = 1;
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetA = 1;
                                            *composton = 0;
                                        }
                                        if (SDL::isCustomCursor && *Axeon == 1) {
                                            SDL::useSystemCursor();
                                            *money += 100;
                                            button->show(false);
                                            *Axeon = 0;
                                            boxmoney->getTextView()->changeText(
                                                    "Your money = " + std::to_string(*money));
                                            game->setMoney(*money);
                                            srand(time(nullptr));
                                            *score += 500;
                                            game->setScore(*score);
                                            (*numberofitem)++;
                                            game->setItem(*numberofitem);
                                            int randomQ;
                                            randomQ = rand() % 4;
                                            switch (randomQ) {
                                                case 0 :
                                                    Gotitem1->show(true);
                                                    boxitem->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem1->show(false);
                                                    }, 3000);
                                                    break;
                                                case 1 :
                                                    Gotitem2->show(true);
                                                    boxitem->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem2->show(false);
                                                    }, 3000);
                                                    break;
                                                case 2:
                                                    Gotitem3->show(true);
                                                    boxitem->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem3->show(false);
                                                    }, 3000);
                                                    break;
                                                case 3:
                                                    Gotitem4->show(true);
                                                    boxitem->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem4->show(false);
                                                    }, 3000);
                                                    break;
                                            }
                                            (*land1)->show(true);
                                        }
                                    },
                                    1, {400, 600}, {150, 100, POSITION_ABSOLUTE});
    auto tree2 = new TouchableImage(SDLRendererController,
                                    lvfive,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetB = 1;
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetB = 1;
                                            *composton = 0;
                                        }
                                        if (SDL::isCustomCursor && *Axeon == 1) {
                                            SDL::useSystemCursor();
                                            *money += 100;
                                            button->show(false);
                                            *Axeon = 0;
                                            *score += 500;
                                            game->setScore(*score);
                                            boxmoney->getTextView()->changeText(
                                                    "Your money = " + std::to_string(*money));
                                            game->setMoney(*money);
                                            srand(time(nullptr));
                                            (*numberofitem)++;
                                            game->setItem(*numberofitem);
                                            int randomQ;
                                            randomQ = rand() % 4;
                                            switch (randomQ) {
                                                case 0 :
                                                    boxitem->show(true);
                                                    Gotitem1->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem1->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 1 :
                                                    boxitem->show(true);
                                                    Gotitem2->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem2->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 2:
                                                    boxitem->show(true);
                                                    Gotitem3->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem3->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 3:
                                                    boxitem->show(true);
                                                    Gotitem4->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem4->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                            }
                                            (*land2)->show(true);
                                        }
                                    },
                                    1, {400, 600}, {475, 100, POSITION_ABSOLUTE});
    auto tree3 = new TouchableImage(SDLRendererController,
                                    lvfive,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetC = 1;
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetC = 1;
                                            *composton = 0;
                                        }
                                        if (SDL::isCustomCursor && *Axeon == 1) {
                                            SDL::useSystemCursor();
                                            *money += 100;
                                            button->show(false);
                                            *Axeon = 0;
                                            *score += 500;
                                            game->setScore(*score);
                                            boxmoney->getTextView()->changeText(
                                                    "Your money = " + std::to_string(*money));
                                            game->setMoney(*money);
                                            srand(time(nullptr));
                                            (*numberofitem)++;
                                            game->setItem(*numberofitem);
                                            int randomQ;
                                            randomQ = rand() % 4;
                                            switch (randomQ) {

                                                case 0 :
                                                    boxitem->show(true);
                                                    Gotitem1->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem1->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 1 :
                                                    boxitem->show(true);
                                                    Gotitem2->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem2->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 2:
                                                    boxitem->show(true);
                                                    Gotitem3->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem3->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 3:
                                                    boxitem->show(true);
                                                    Gotitem4->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem4->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                            }
                                            (*land3)->show(true);
                                        }
                                    },
                                    1, {400, 600}, {800, 100, POSITION_ABSOLUTE});
    auto tree4 = new TouchableImage(SDLRendererController,
                                    lvfive,
                                    [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                        if (SDL::isCustomCursor && *wateron == 1) {
                                            SDL::useSystemCursor();
                                            *wateron = 0;
                                            *watergetD = 1;
                                        }
                                        if (SDL::isCustomCursor && *composton == 1) {
                                            SDL::useSystemCursor();
                                            *compostgetD = 1;
                                            *composton = 0;
                                        }
                                        if (SDL::isCustomCursor && *Axeon == 1) {
                                            SDL::useSystemCursor();
                                            *money += 100;
                                            button->show(false);
                                            *Axeon = 0;
                                            boxmoney->getTextView()->changeText(
                                                    "Your money = " + std::to_string(*money));
                                            game->setMoney(*money);
                                            srand(time(nullptr));
                                            (*numberofitem)++;
                                            game->setItem(*numberofitem);
                                            int randomQ;
                                            *score += 500;
                                            game->setScore(*score);
                                            randomQ = rand() % 4;
                                            switch (randomQ) {
                                                case 0 :
                                                    boxitem->show(true);
                                                    Gotitem1->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem1->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 1 :
                                                    boxitem->show(true);
                                                    Gotitem2->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem2->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 2:
                                                    boxitem->show(true);
                                                    Gotitem3->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem3->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                                case 3:
                                                    boxitem->show(true);
                                                    Gotitem4->show(true);
                                                    timer->setTimeout([=]() {
                                                        Gotitem4->show(false);
                                                        boxitem->show(false);
                                                    }, 3000);
                                                    break;
                                            }
                                            (*land4)->show(true);
                                        }
                                    },
                                    1, {400, 600}, {1100, 100, POSITION_ABSOLUTE});
    //------------------------------------------------------------------------------------------------------------------//
    //------------------------------------------------------------------------------------------------------------------//
    auto landwater1lv4 = new TouchableImage(SDLRendererController,
                                            lvfourwater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetA = 1;
                                                    *composton = 0;
                                                    tree1->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 400}, {200, 300, POSITION_ABSOLUTE});
    auto landwater2lv4 = new TouchableImage(SDLRendererController,
                                            lvfourwater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetB = 1;
                                                    *composton = 0;
                                                    tree2->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 400}, {525, 300, POSITION_ABSOLUTE});
    auto landwater3lv4 = new TouchableImage(SDLRendererController,
                                            lvfourwater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetC = 1;
                                                    *composton = 0;
                                                    tree3->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 400}, {850, 300, POSITION_ABSOLUTE});
    auto landwater4lv4 = new TouchableImage(SDLRendererController,
                                            lvfourwater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetD = 1;
                                                    *composton = 0;
                                                    tree4->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 400}, {1175, 300, POSITION_ABSOLUTE});
    auto land1lv4 = new TouchableImage(SDLRendererController,
                                       lvfour,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetA = 1;
                                               button->show(false);
                                               landwater1lv4->show(true);
                                           }
                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetA = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 400}, {200, 300, POSITION_ABSOLUTE});
    auto land2lv4 = new TouchableImage(SDLRendererController,
                                       lvfour,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {

                                               *wateron = 0;
                                               *watergetB = 1;
                                               SDL::useSystemCursor();
                                               button->show(false);
                                               landwater2lv4->show(true);
                                           }
                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetB = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 400}, {525, 300, POSITION_ABSOLUTE});
    auto land3lv4 = new TouchableImage(SDLRendererController,
                                       lvfour,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetC = 1;
                                               button->show(false);
                                               landwater3lv4->show(true);

                                           }

                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetC = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 400}, {850, 300, POSITION_ABSOLUTE});
    auto land4lv4 = new TouchableImage(SDLRendererController,
                                       lvfour,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetD = 1;
                                               button->show(false);
                                               landwater4lv4->show(true);
                                           }
                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetD = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 400}, {1175, 300, POSITION_ABSOLUTE});
    //------------------------------------------------------------------------------------------------------------------//
    //------------------------------------------------------------------------------------------------------------------//
    auto landwater1lv3 = new TouchableImage(SDLRendererController,
                                            lvthteewater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetA = 1;
                                                    *composton = 0;
                                                    land1lv4->show(true);
                                                    button->show(false);

                                                }
                                            },
                                            1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landwater2lv3 = new TouchableImage(SDLRendererController,
                                            lvthteewater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetB = 1;
                                                    *composton = 0;
                                                    land2lv4->show(true);
                                                    button->show(false);
                                                }

                                            },
                                            1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landwater3lv3 = new TouchableImage(SDLRendererController,
                                            lvthteewater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetC = 1;
                                                    *composton = 0;
                                                    land3lv4->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landwater4lv3 = new TouchableImage(SDLRendererController,
                                            lvthteewater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetD = 1;
                                                    *composton = 0;
                                                    land4lv4->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto land1lv3 = new TouchableImage(SDLRendererController,
                                       lvthree,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetA = 1;
                                               button->show(false);
                                               landwater1lv3->show(true);
                                           }

                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetA = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto land2lv3 = new TouchableImage(SDLRendererController,
                                       lvthree,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {

                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetB = 1;
                                               button->show(false);
                                               landwater2lv3->show(true);
                                           }

                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetB = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto land3lv3 = new TouchableImage(SDLRendererController,
                                       lvthree,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetC = 1;
                                               button->show(false);
                                               landwater3lv3->show(true);
                                           }

                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetC = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto land4lv3 = new TouchableImage(SDLRendererController,
                                       lvthree,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetD = 1;
                                               button->show(false);
                                               landwater4lv3->show(true);
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
    auto landwater1lv2 = new TouchableImage(SDLRendererController,
                                            lvtwowater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetA = 1;
                                                    *composton = 0;
                                                    land1lv3->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landwater2lv2 = new TouchableImage(SDLRendererController,
                                            lvtwowater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetB = 1;
                                                    *composton = 0;
                                                    land2lv3->show(true);
                                                    button->show(false);

                                                }
                                            },
                                            1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landwater3lv2 = new TouchableImage(SDLRendererController,
                                            lvtwowater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetC = 1;
                                                    *composton = 0;
                                                    land3lv3->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landwater4lv2 = new TouchableImage(SDLRendererController,
                                            lvtwowater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetD = 1;
                                                    *composton = 0;
                                                    land4lv3->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto land1lv2 = new TouchableImage(SDLRendererController,
                                       lvtwo,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetA = 1;
                                               button->show(false);
                                               landwater1lv2->show(true);
                                           }

                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetA = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 200}, {200, 500, POSITION_ABSOLUTE});

    auto land2lv2 = new TouchableImage(SDLRendererController,
                                       lvtwo,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {

                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetB = 1;
                                               button->show(false);
                                               landwater2lv2->show(true);
                                           }

                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetB = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto land3lv2 = new TouchableImage(SDLRendererController,
                                       lvtwo,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetC = 1;
                                               button->show(false);
                                               landwater3lv2->show(true);
                                           }

                                           if (SDL::isCustomCursor && *composton == 1) {
                                               SDL::useSystemCursor();
                                               *compostgetC = 1;
                                               *composton = 0;
                                           }
                                       },
                                       1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto land4lv2 = new TouchableImage(SDLRendererController,
                                       lvtwo,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetD = 1;
                                               button->show(false);
                                               landwater4lv2->show(true);
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
    auto landwater1lv1 = new TouchableImage(SDLRendererController,
                                            lvonewater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetA = 1;
                                                    *composton = 0;
                                                    land1lv2->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landwater2lv1 = new TouchableImage(SDLRendererController,
                                            lvonewater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetB = 1;
                                                    *composton = 0;
                                                    land2lv2->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landwater3lv1 = new TouchableImage(SDLRendererController,
                                            lvonewater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetC = 1;
                                                    *composton = 0;
                                                    land3lv2->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landwater4lv1 = new TouchableImage(SDLRendererController,
                                            lvonewater,
                                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                if (SDL::isCustomCursor && *composton == 1) {
                                                    SDL::useSystemCursor();
                                                    *compostgetD = 1;
                                                    *composton = 0;
                                                    land4lv2->show(true);
                                                    button->show(false);
                                                }
                                            },
                                            1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto land1lv1 = new TouchableImage(SDLRendererController,
                                       lvone,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               landwater1lv1->show(true);
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetA = 1;
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
                                       lvone,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               landwater2lv1->show(true);
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetB = 1;
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
                                       lvone,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               landwater3lv1->show(true);
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetC = 1;
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
                                       lvone,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           if (SDL::isCustomCursor && *wateron == 1) {
                                               landwater4lv1->show(true);
                                               SDL::useSystemCursor();
                                               *wateron = 0;
                                               *watergetD = 1;
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
                                                         button->show(false);
                                                         land1lv1->show(true);
                                                         *composton = 0;
                                                     }
                                                     (*checkLvOftree)++;
                                                 }
                                             },
                                             1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    auto landwaterseed2 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetA = 1;
                                                     land2lv1->show(true);
                                                     button->show(false);
                                                     *composton = 0;
                                                 }
                                             },
                                             1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    auto landwaterseed3 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetC = 1;
                                                     land3lv1->show(true);
                                                     button->show(false);
                                                     *composton = 0;
                                                 }
                                             },
                                             1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    auto landwaterseed4 = new TouchableImage(SDLRendererController,
                                             landwWaterwSeed,
                                             [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 if (SDL::isCustomCursor && *composton == 1) {
                                                     SDL::useSystemCursor();
                                                     *compostgetD = 1;
                                                     land4lv1->show(true);
                                                     button->show(false);
                                                     *composton = 0;
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
                                             if (SDL::isCustomCursor && *seedon == 1 && *numberofseed > 0) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed1->show(true);
                                                 button->show(false);
                                                 *seedon = 0;
                                                 (*numberofseed)--;
                                                 seedshow->changeText("x" + std::to_string(*numberofseed));
                                                 game->setSeed(game->getSeed() + *numberofseed);
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
                                             if (SDL::isCustomCursor && *seedon == 1 && *numberofseed > 0) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed2->show(true);
                                                 button->show(false);
                                                 *seedon = 0;
                                                 (*numberofseed)--;
                                                 seedshow->changeText("x" + std::to_string(*numberofseed));
                                                 game->setSeed(game->getSeed() + *numberofseed);
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
                                                 landwaterseed3->show(true);
                                             }
                                             if (SDL::isCustomCursor && *seedon == 1 && *numberofseed > 0) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed3->show(true);
                                                 button->show(false);
                                                 *seedon = 0;
                                                 (*numberofseed)--;
                                                 seedshow->changeText("x" + std::to_string(*numberofseed));
                                                 game->setSeed(game->getSeed() + *numberofseed);
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
                                             if (SDL::isCustomCursor && *seedon == 1 && *numberofseed > 0) {
                                                 SDL::useSystemCursor();
                                                 landwaterseed4->show(true);
                                                 button->show(false);
                                                 *seedon = 0;
                                                 (*numberofseed)--;
                                                 seedshow->changeText("x" + std::to_string(*numberofseed));
                                                 game->setSeed(game->getSeed() + *numberofseed);
                                             }
                                         },
                                         1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto background = new ImageView(SDLRendererController, bgTexture, -1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    *land1 = new TouchableImage(SDLRendererController,
                                land,
                                [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                    if (SDL::isCustomCursor && *wateron == 1) {
                                        landwater1->show(true);
                                        SDL::useSystemCursor();
                                        *wateron = 0;
                                        *watergetA = 1;
                                        button->show(false);
                                    }
                                    if (SDL::isCustomCursor && *seedon == 1 && *numberofseed > 0) {
                                        landseed1->show(true);
                                        SDL::useSystemCursor();
                                        *seedon = 0;
                                        *seedgetA = 1;
                                        button->show(false);
                                        (*numberofseed)--;
                                        seedshow->changeText("x" + std::to_string(*numberofseed));
                                        game->setSeed(*numberofseed);
                                    }
                                    if (SDL::isCustomCursor && *composton == 1) {
                                        SDL::useSystemCursor();
                                        *compostgetA = 1;
                                        *composton = 0;
                                    }

                                },
                                1, {200, 200}, {200, 500, POSITION_ABSOLUTE});
    *land2 = new TouchableImage(SDLRendererController,
                                land,
                                [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                    if (SDL::isCustomCursor && *wateron == 1) {
                                        landwater2->show(true);
                                        SDL::useSystemCursor();
                                        *wateron = 0;
                                        *watergetB = 1;
                                        button->show(false);
                                    }
                                    if (SDL::isCustomCursor && *seedon == 1 && *numberofseed > 0) {
                                        landseed2->show(true);
                                        SDL::useSystemCursor();
                                        *seedon = 0;
                                        *seedgetB = 1;
                                        button->show(false);
                                        (*numberofseed)--;
                                        seedshow->changeText("x" + std::to_string(*numberofseed));
                                        game->setSeed(*numberofseed);
                                    }
                                    if (SDL::isCustomCursor && *composton == 1) {
                                        SDL::useSystemCursor();
                                        *compostgetB = 1;
                                        *composton = 0;
                                    }
                                },
                                1, {200, 200}, {525, 500, POSITION_ABSOLUTE});
    *land3 = new TouchableImage(SDLRendererController,
                                land,
                                [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                    if (SDL::isCustomCursor && *wateron == 1) {
                                        landwater3->show(true);
                                        SDL::useSystemCursor();
                                        *wateron = 0;
                                        *watergetC = 1;
                                        button->show(false);
                                    }
                                    if (SDL::isCustomCursor && *seedon == 1 && *numberofseed > 0) {
                                        landseed3->show(true);
                                        SDL::useSystemCursor();
                                        *seedon = 0;
                                        *seedgetC = 1;
                                        button->show(false);
                                        (*numberofseed)--;
                                        seedshow->changeText("x" + std::to_string(*numberofseed));
                                        game->setSeed(*numberofseed);
                                    }
                                    if (SDL::isCustomCursor && *composton == 1) {
                                        SDL::useSystemCursor();
                                        *compostgetC = 1;
                                        *composton = 0;
                                    }
                                },
                                1, {200, 200}, {850, 500, POSITION_ABSOLUTE});
    *land4 = new TouchableImage(SDLRendererController,
                                land,
                                [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                    if (SDL::isCustomCursor && *wateron == 1) {
                                        landwater4->show(true);
                                        SDL::useSystemCursor();
                                        *wateron = 0;
                                        *watergetD = 1;
                                        button->show(false);
                                    }
                                    if (SDL::isCustomCursor && *seedon == 1 && *numberofseed > 0) {
                                        landseed4->show(true);
                                        SDL::useSystemCursor();
                                        *seedon = 0;
                                        *seedgetD = 1;
                                        button->show(false);
                                        (*numberofseed)--;
                                        seedshow->changeText("x" + std::to_string(*numberofseed));
                                        game->setSeed(*numberofseed);
                                    }
                                    if (SDL::isCustomCursor && *composton == 1) {
                                        SDL::useSystemCursor();
                                        *compostgetD = 1;
                                        *composton = 0;
                                    }
                                },
                                1, {200, 200}, {1175, 500, POSITION_ABSOLUTE});
    auto Axe = new TouchableImage(SDLRendererController,
                                  axe,
                                  [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                      SDL::setCustomCursor(GAME_PROP.RESOURCE_PATH + "/img/maingame2/ax.png",
                                                           50, 50);
                                      SDL::useCustomCursor();
                                      *Axeon = 1;
                                  },
                                  3, {150, 150}, {1400, 700, POSITION_RELATIVE});
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
    sceneContainer->append(*land1);
    sceneContainer->append(*land2);
    sceneContainer->append(*land3);
    sceneContainer->append(*land4);
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
    sceneContainer->append(Axe);
    //------------------------------------------------//
    sceneContainer->append(land1lv1->show(false));
    sceneContainer->append(land2lv1->show(false));
    sceneContainer->append(land3lv1->show(false));
    sceneContainer->append(land4lv1->show(false));
    sceneContainer->append(landwater1lv1);
    landwater1lv1->show(false);
    sceneContainer->append(landwater2lv1);
    landwater2lv1->show(false);
    sceneContainer->append(landwater3lv1);
    landwater3lv1->show(false);
    sceneContainer->append(landwater4lv1);
    landwater4lv1->show(false);
    //------------------------------------------------//
    sceneContainer->append(land1lv2->show(false));
    sceneContainer->append(land2lv2->show(false));
    sceneContainer->append(land3lv2->show(false));
    sceneContainer->append(land4lv2->show(false));
    sceneContainer->append(landwater1lv2);
    landwater1lv2->show(false);
    sceneContainer->append(landwater2lv2);
    landwater2lv2->show(false);
    sceneContainer->append(landwater3lv2);
    landwater3lv2->show(false);
    sceneContainer->append(landwater4lv2);
    landwater4lv2->show(false);
    //------------------------------------------------//
    sceneContainer->append(land1lv3->show(false));
    sceneContainer->append(land2lv3->show(false));
    sceneContainer->append(land3lv3->show(false));
    sceneContainer->append(land4lv3->show(false));
    sceneContainer->append(landwater1lv3);
    landwater1lv3->show(false);
    sceneContainer->append(landwater2lv3);
    landwater2lv3->show(false);
    sceneContainer->append(landwater3lv3);
    landwater3lv3->show(false);
    sceneContainer->append(landwater4lv3);
    landwater4lv3->show(false);
    //------------------------------------------------//
    sceneContainer->append(land1lv4->show(false));
    sceneContainer->append(land2lv4->show(false));
    sceneContainer->append(land3lv4->show(false));
    sceneContainer->append(land4lv4->show(false));
    sceneContainer->append(landwater1lv4);
    landwater1lv4->show(false);
    sceneContainer->append(landwater2lv4);
    landwater2lv4->show(false);
    sceneContainer->append(landwater3lv4);
    landwater3lv4->show(false);
    sceneContainer->append(landwater4lv4);
    landwater4lv4->show(false);
    //------------------------------------------------//
    sceneContainer->append(tree1->show(false));
    sceneContainer->append(tree2->show(false));
    sceneContainer->append(tree3->show(false));
    sceneContainer->append(tree4->show(false));
    auto backToMenu = sceneContainer->append(new Button(SDLRendererController,
                                                        "MENU",
                                                        {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                         {255, 255, 255}},
                                                        box,
                                                        [=](Touchable *button, ComponentPosition clickPosition,
                                                            SDL_Event event) mutable {
                                                            gameScenes->setCurrentSceneName("menu");
                                                        },
                                                        50, {300, 100}, {1100, 775, POSITION_ABSOLUTE}));
    auto reset = sceneContainer->append(new Button(SDLRendererController,
                                                   "reset",
                                                   {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                    {255, 255, 255}},
                                                   box,
                                                   [=](Touchable *button, ComponentPosition clickPosition,
                                                       SDL_Event event) mutable {
                                                       SDL::useSystemCursor();
                                                       *wateron = 0;
                                                       *seedon = 0;
                                                       *Axeon = 0;
                                                       *composton = 0;
                                                   },
                                                   50, {150, 100}, {1400, 550, POSITION_ABSOLUTE}));

    scene->onEnterScene([=](Scene *scene) {
        *score = game->getScore();
        *money = game->getMoney();
        *numberofseed = game->getSeed();
        *numberofitem = game->getItem();
        boxmoney->getTextView()->changeText("Your money =" + std::to_string(*money));
        seedshow->changeText("x" + std::to_string(*numberofseed));
    });
    scene->onExitScene([=](Scene *scene) {
        SDL::useSystemCursor();
        *wateron = 0;
        *seedon = 0;
        *Axeon = 0;
        *composton = 0;
    });
}