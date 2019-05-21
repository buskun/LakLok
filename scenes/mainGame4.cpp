
#include "scene_list.h"
#include <cstdlib>
#include <time.h>

void mainGame4(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("mainGame4");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
    const GameProp GAME_PROP = gameScenes->getGameProp();
    GameProp gameProp = gameScenes->getGameProp();
    auto *timer = new Timer();
    int bW, bH, *score = new int;
    *score = 0;
    bool *answering = new bool;
    *answering = false;
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bgmaingame4.jpg");
    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    SDL_Texture *gameTrue = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/true.png");
    SDL_Texture *gameFalse = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/false.png");
    SDL_Texture *kob1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame4/kob.png");
    SDL_Texture *kob2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame4/Kob 2.png");
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    sceneContainer->append(new ImageView(SDLRendererController, box, 10, {600, 150}, {850, 650, POSITION_RELATIVE}));
    auto gameC = new ImageView(SDLRendererController, gameTrue, 10, {300, 300}, {300, 300, POSITION_RELATIVE});
    gameC->show(false);
    sceneContainer->append(gameC);
    auto gameX = new ImageView(SDLRendererController, gameFalse, 10, {300, 300}, {300, 300, POSITION_RELATIVE});
    gameX->show(false);
    sceneContainer->append(gameX);
    bool *answer = new bool[4];
    auto Q1C1 = new Button(SDLRendererController,
                           "สวัสดี1", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                       {255, 255, 255}},
                           box,
                           [=](Touchable *button, ComponentPosition clickPosition,
                               SDL_Event event)mutable {
                           },
                           16, {500, 150}, {300, 450, POSITION_ABSOLUTE});
    auto Q1C2 = new Button(SDLRendererController,
                           "สวัสดี2", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                       {255, 255, 255}},
                           box,
                           [=](Touchable *button, ComponentPosition clickPosition,
                               SDL_Event event)mutable {
                               *answering = true;
                           },
                           16, {500, 150}, {1000, 450, POSITION_ABSOLUTE});
    auto Q1C3 = new Button(SDLRendererController,
                           "สวัสดี3", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                       {255, 255, 255}},
                           box,
                           [=](Touchable *button, ComponentPosition clickPosition,
                               SDL_Event event)mutable {

                               *answering = true;
                           },
                           16, {500, 150}, {300, 650, POSITION_ABSOLUTE});
    auto Q1C4 = new Button(SDLRendererController,
                           "สวัสดี4", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                       {255, 255, 255}},
                           box,
                           [=](Touchable *button, ComponentPosition clickPosition,
                               SDL_Event event)mutable {

                               *answering = true;
                           },
                           16, {500, 150}, {1000, 650, POSITION_ABSOLUTE});
    auto  Q2C1 = new Button(SDLRendererController,
                            "สวัสดี5", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                        {255, 255, 255}},
                            box,
                            [=](Touchable *button, ComponentPosition clickPosition,
                                SDL_Event event)mutable {


                                *answering = true;
                            },
                            16, {500, 150}, {300, 450, POSITION_ABSOLUTE});
    auto Q2C2 = new Button(SDLRendererController,
                           "สวัสดี6", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                       {255, 255, 255}},
                           box,
                           [=](Touchable *button, ComponentPosition clickPosition,
                               SDL_Event event)mutable {


                               *answering = true;
                           },
                           16, {500, 150}, {1000, 450, POSITION_ABSOLUTE});
    auto Q2C3 = new Button(SDLRendererController,
                           "สวัสดี7", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                       {255, 255, 255}},
                           box,
                           [=](Touchable *button, ComponentPosition clickPosition,
                               SDL_Event event)mutable {


                               *answering = true;
                           },
                           16, {500, 150}, {300, 650, POSITION_ABSOLUTE});
    auto Q2C4 = new Button(SDLRendererController,
                           "สวัสดี8", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                       {255, 255, 255}},
                           box,
                           [=](Touchable *button, ComponentPosition clickPosition,
                               SDL_Event event)mutable {
                               *answering = true;
                           },
                           16, {500, 150}, {1000, 650, POSITION_ABSOLUTE});
    auto A = new Button(SDLRendererController,
                        "", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                             {255, 255, 255}},
                        box,
                        [=](Touchable *button, ComponentPosition clickPosition,
                            SDL_Event event)mutable {
                            if (*answering) return;
                            *answering = true;
                            auto result = answer[0] ? gameC : gameX;
                            *score += answer[0] ? 100 : 0;
                            result->show(true);
                            timer->setTimeout([=]() mutable {
                                result->show(false);
                                *answering = false;
                            }, 1000);
                        },
                        10, {600, 150}, {150, 450, POSITION_ABSOLUTE});
    auto B = new Button(SDLRendererController,
                        "", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                             {255, 255, 255}},
                        box,
                        [=](Touchable *button, ComponentPosition clickPosition,
                            SDL_Event event)mutable {
                            *answering = true;

                        },
                        10, {600, 150}, {850, 450, POSITION_ABSOLUTE});

    auto C = new Button(SDLRendererController,
                        "", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                             {255, 255, 255}},
                        box,
                        [=](Touchable *button, ComponentPosition clickPosition,
                            SDL_Event event)mutable {
                            *answering = true;

                        },
                        10, {600, 150}, {150, 650, POSITION_ABSOLUTE});

    auto D = new Button(SDLRendererController,
                        "", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                             {255, 255, 255}},
                        box,
                        [=](Touchable *button, ComponentPosition clickPosition,
                            SDL_Event event)mutable {
                            *answering = true;
                        },
                        10, {600, 150}, {850, 650, POSITION_ABSOLUTE});
    auto boxEnd = new Button(SDLRendererController,
                             "Your score = ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                               {255, 255, 255}},
                             box,
                             [=](Touchable *button, ComponentPosition clickPosition,
                                 SDL_Event event) mutable {
                             },
                             50, {500, 300}, {600, 300, POSITION_ABSOLUTE});

    int randomQ = 0;
    auto showNewQuestion = [=]() mutable {
        srand(time(nullptr));
        //int randomQ = rand() % 29;
        sceneContainer->append(Q1C1->show(false));
        sceneContainer->append(Q1C2->show(false));
        sceneContainer->append(Q1C3->show(false));
        sceneContainer->append(Q1C4->show(false));
        sceneContainer->append(Q2C1->show(false));
        sceneContainer->append(Q2C2->show(false));
        sceneContainer->append(Q2C3->show(false));
        sceneContainer->append(Q2C4->show(false));
        answer[0] = false;
        answer[1] = false;
        answer[2] = false;
        answer[3] = false;
        randomQ++;
        std::cout << randomQ << std::endl;
        switch (randomQ) {
            case 0:
            case 1:Q1C1->show(true);
                Q1C2->show(true);
                Q1C3->show(true);
                Q1C4->show(true);
                answer[0] = true;
                break;
            case 2: Q2C1->show(true);
                Q2C2->show(true);
                Q2C3->show(true);
                Q2C4->show(true);
                answer[1] = true;
                break;
            case 3:Q2C1->show(true);
                Q2C2->show(true);
                Q2C3->show(true);
                Q2C4->show(true);
                answer[2] = true;
                break;
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            default:;
        }
    };
    showNewQuestion();
    //auto Q1Container = new Container(SDLRendererController, 2, {1600, 450}, {0, 450, POSITION_ABSOLUTE});
    int c=16;
    boxEnd = sceneContainer->append(new Button(SDLRendererController,
                                               "Your score = ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                                 {255, 255, 255}},
                                               box,
                                               [=](Touchable *button, ComponentPosition clickPosition,
                                                   SDL_Event event) mutable {
                                               },
                                               50, {500, 100}, {20, 20, POSITION_ABSOLUTE}));
    A = new Button(SDLRendererController,
                   "A", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                         {255, 255, 255}},
                   box,
                   [=](Touchable *button, ComponentPosition clickPosition,
                       SDL_Event event)mutable {
                       if (*answering) return;
                       *answering = true;
                       auto result = answer[0] ? gameC : gameX;
                       *score += answer[0] ? 100 : 0;
                       result->show(true);
                       timer->setTimeout([=]() mutable {
                           result->show(false);
                           showNewQuestion();
                           *answering = false;
                       }, 1000);
                       boxEnd->getTextView()->changeText("Your score = " + std::to_string(*score));
                   },
                   10, {150, 150}, {150, 450, POSITION_ABSOLUTE});
    sceneContainer->append(A);
    B = new Button(SDLRendererController,
                   "B", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                         {255, 255, 255}},
                   box,
                   [=](Touchable *button, ComponentPosition clickPosition,
                       SDL_Event event)mutable {
                       if (*answering) return;
                       *answering = true;
                       auto result = answer[1] ? gameC : gameX;
                       *score += answer[1] ? 100 : 0;
                       result->show(true);
                       timer->setTimeout([=]() mutable {
                                             result->show(false);
                                             showNewQuestion();
                                             *answering = false;
                                         }
                               , 1000);
                       boxEnd->getTextView()->changeText("Your score = " + std::to_string(*score));
                   },
                   10, {150, 150}, {850, 450, POSITION_ABSOLUTE});
    sceneContainer->append(B);
    C = new Button(SDLRendererController,
                   "C", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                         {255, 255, 255}},
                   box,
                   [=](Touchable *button, ComponentPosition clickPosition,
                       SDL_Event event)mutable {
                       if (*answering) return;
                       *answering = true;
                       auto result = answer[2] ? gameC : gameX;
                       *score += answer[2] ? 100 : 0;
                       result->show(true);
                       timer->setTimeout([=]() mutable {
                           result->show(false);
                           showNewQuestion();
                           *answering = false;
                       }, 1000);
                       boxEnd->getTextView()->changeText("Your score = " + std::to_string(*score));
                   },

                   10, {150, 150}, {150, 650, POSITION_ABSOLUTE});
    sceneContainer->append(C);
    D = new Button(SDLRendererController,
                   "D", {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                         {255, 255, 255}},
                   box,
                   [=](Touchable *button, ComponentPosition clickPosition,
                       SDL_Event event)mutable {
                       if (*answering) return;
                       *answering = true;
                       auto result = answer[3] ? gameC : gameX;
                       *score += answer[3] ? 100 : 0;
                       result->show(true);
                       timer->setTimeout([=]() mutable {
                           result->show(false);
                           showNewQuestion();
                           *answering = false;
                       }, 1000);
                       boxEnd->getTextView()->changeText("Your score = " + std::to_string(*score));
                   },
                   10, {150, 150}, {850, 650, POSITION_ABSOLUTE});
    sceneContainer->append(D);

}