#include "scene_list.h"
#include <cstdlib>
#include <time.h>

void mainGame1(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("mainGame1");
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

    auto *timer = new Timer();
    const GameProp GAME_PROP = gameScenes->getGameProp();
    int bW, bH, *score = new int;
    *score = 0;
    bool *answering = new bool;
    *answering = false;

    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/bgmaingame1.jpg");
    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    SDL_Texture *newbox = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    SDL_Texture *backmain = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    SDL_Texture *canRed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/canRed.png");
    SDL_Texture *canBlue = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/canBlue.png");
    SDL_Texture *canYellow = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/canYellow.png");
    SDL_Texture *canGreen = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/canGreen.png");
    SDL_Texture *game1Q1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/game1Q1.png");
    SDL_Texture *gameTrue = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/true.png");
    SDL_Texture *gameFalse = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/false.png");
    SDL_Texture *game1Q2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/mainGame_2.jpg");
    SDL_Texture *game1Q3 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/mainGame_3.jpg");
    SDL_Texture *game1Q4 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/mainGame_4.jpg");
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    auto gameC = new ImageView(SDLRendererController, gameTrue, 10, {300, 300}, {300, 300, POSITION_RELATIVE});
    gameC->show(false);
    sceneContainer->append(gameC);
    auto gameX = new ImageView(SDLRendererController, gameFalse, 10, {300, 300}, {300, 300, POSITION_RELATIVE});
    gameX->show(false);
    sceneContainer->append(gameX);
    bool *answer = new bool[4];
    sceneContainer->append(background);
    auto q1 = new ImageView(SDLRendererController, game1Q1, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q2 = new ImageView(SDLRendererController, game1Q2, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q3 = new ImageView(SDLRendererController, game1Q3, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q4 = new ImageView(SDLRendererController, game1Q4, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    sceneContainer->append(new ImageView(SDLRendererController, box, 2, {300, 100}, {645, 25, POSITION_RELATIVE}));
    sceneContainer->append(q1->show(false));
    sceneContainer->append(q2->show(false));
    sceneContainer->append(q3->show(false));
    sceneContainer->append(q4->show(false));
    auto textTime = new TextView(SDLRendererController,
                                 "",
                                 {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                                 3, {675, 50, POSITION_ABSOLUTE});
    sceneContainer->append(textTime);

    auto showNewQuestion = [=]() mutable {
        srand(time(nullptr));
        int randomQ = rand() % 29;
        q1->show(false);
        q2->show(false);
        q3->show(false);
        q4->show(false);
        answer[0] = false;
        answer[1] = false;
        answer[2] = false;
        answer[3] = false;
        switch (randomQ) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                answer[0] = true;
                q1->show(true);
                break;
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                answer[1] = true;
                q2->show(true);
                break;
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
                answer[2] = true;
                q3->show(true);
                break;
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
                answer[3] = true;
                q4->show(true);
                break;
            default:;
        }
    };
    showNewQuestion();
    auto canBlueA = new TouchableImage(SDLRendererController, canBlue,
                                       [=](Touchable *button, ComponentPosition clickPosition,
                                           SDL_Event event) mutable {
                                           if (*answering) return;
                                           *answering = true;
                                           auto result = answer[0] ? gameC : gameX;
                                           score += answer[0] ? 100 : 0;
                                           result->show(true);
                                           timer->setTimeout([=]() mutable {
                                               result->show(false);
                                               showNewQuestion();
                                               *answering = false;
                                           }, 1000);
                                       },
                                       2, {200, 300}, {350, 600, POSITION_RELATIVE});
    sceneContainer->append(canBlueA);
    auto canRedB = new TouchableImage(SDLRendererController, canRed,
                                      [=](Touchable *button, ComponentPosition clickPosition,
                                          SDL_Event event) mutable {
                                          if (*answering) return;
                                          *answering = true;
                                          auto result = answer[1] ? gameC : gameX;
                                          *score += answer[1] ? 100 : 0;
                                          result->show(true);
                                          timer->setTimeout([=]() mutable {
                                              result->show(false);
                                              showNewQuestion();
                                              *answering = false;
                                          }, 1000);
                                      },
                                      2, {200, 300}, {600, 600, POSITION_RELATIVE});
    sceneContainer->append(canRedB);
    auto canGreenC = new TouchableImage(SDLRendererController, canGreen,
                                        [=](Touchable *button, ComponentPosition clickPosition,
                                            SDL_Event event) mutable {
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
                                        },
                                        2, {200, 300}, {850, 600, POSITION_RELATIVE});
    sceneContainer->append(canGreenC);
    auto canYellowD = new TouchableImage(SDLRendererController, canYellow,
                                         [=](Touchable *button, ComponentPosition clickPosition,
                                             SDL_Event event) mutable {
                                             if (*answering) return;
                                             *answering = true;
                                             auto result = answer[3] ? gameC : gameX;
                                             score += answer[3] ? 100 : 0;
                                             result->show(true);
                                             timer->setTimeout([=]() mutable {
                                                 result->show(false);
                                                 showNewQuestion();
                                                 *answering = false;
                                             }, 1000);
                                         },
                                         2, {200, 300}, {1100, 600, POSITION_RELATIVE});
    sceneContainer->append(canYellowD);
    auto boxEnd = new Button(SDLRendererController,
                             "Your score = ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                               {255, 255, 255}},
                             box,
                             [=](Touchable *button, ComponentPosition clickPosition,
                                 SDL_Event event) mutable {
                             },
                             50, {500, 300}, {645, 300, POSITION_ABSOLUTE});
    boxEnd->show(false);
    sceneContainer->append(boxEnd);

    auto backToMenu = new Button(SDLRendererController,
                                 "MENU",
                                 {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                  {255, 255, 255}},
                                 box,
                                 [=](Touchable *button, ComponentPosition clickPosition,
                                     SDL_Event event) mutable {

                                 },
                                 16, {300, 100}, {1250, 750, POSITION_ABSOLUTE});
    backToMenu->show(false);
    sceneContainer->append(backToMenu);

    scene->onEnterScene([=](Scene *scene) mutable {
        int imgState = 10;
        textTime->changeText(std::to_string(imgState));
        timer->setInterval([=]() mutable {
            textTime->changeText(std::to_string(--imgState));
            if (imgState <= 0) {
                boxEnd->getTextView()->changeText("Your score = " + std::to_string(*score));
                ComponentSize textSize = boxEnd->getTextView()->getSize();
                boxEnd->getTextView()->setPosition({(boxEnd->getSize().width - textSize.width) / 2,
                                                    (boxEnd->getSize().height - textSize.height) / 2});
                q1->show(false);
                q2->show(false);
                q3->show(false);
                q4->show(false);
                gameC->show(false);
                gameX->show(false);
                canBlueA->show(false);
                canRedB->show(false);
                canGreenC->show(false);
                canYellowD->show(false);
                textTime->show(false);
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