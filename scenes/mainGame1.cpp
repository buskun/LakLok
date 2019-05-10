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
    SDL_Texture *gameTrue = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/true.png");
    SDL_Texture *gameFalse = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/false.png");
    SDL_Texture *game1Q1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeBlue1.png");
    SDL_Texture *game1Q2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeBlue2.png");
    SDL_Texture *game1Q3 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeBlue3.png");
    SDL_Texture *game1Q4 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeGreen1.png");
    SDL_Texture *game1Q5 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeGreen2.png");
    SDL_Texture *game1Q6 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeGreen3.png");
    SDL_Texture *game1Q7 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeRed1.png");
    SDL_Texture *game1Q8 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeRed2.png");
    SDL_Texture *game1Q9 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeRed3.png");
    SDL_Texture *game1Q10 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeYellow1.png");
    SDL_Texture *game1Q11 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeYellow2.png");
    SDL_Texture *game1Q12 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/codeYellow3.png");
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
    auto q5 = new ImageView(SDLRendererController, game1Q5, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q6 = new ImageView(SDLRendererController, game1Q6, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q7 = new ImageView(SDLRendererController, game1Q7, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q8 = new ImageView(SDLRendererController, game1Q8, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q9 = new ImageView(SDLRendererController, game1Q9, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q10 = new ImageView(SDLRendererController, game1Q10, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q11= new ImageView(SDLRendererController, game1Q11, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto q12 = new ImageView(SDLRendererController, game1Q12, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto boxOfTime = new ImageView(SDLRendererController, box, 2, {300, 100}, {645, 25, POSITION_RELATIVE});
    sceneContainer->append(boxOfTime);
    sceneContainer->append(q1->show(false));
    sceneContainer->append(q2->show(false));
    sceneContainer->append(q3->show(false));
    sceneContainer->append(q4->show(false));
    sceneContainer->append(q5->show(false));
    sceneContainer->append(q6->show(false));
    sceneContainer->append(q7->show(false));
    sceneContainer->append(q8->show(false));
    sceneContainer->append(q9->show(false));
    sceneContainer->append(q10->show(false));
    sceneContainer->append(q11->show(false));
    sceneContainer->append(q12->show(false));
    auto textTime = new TextView(SDLRendererController,
                                 "",
                                 {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                                 3, {770, 50, POSITION_ABSOLUTE});
    sceneContainer->append(textTime);
    auto showNewQuestion = [=]() mutable {
        srand(time(nullptr));
        int randomQ = rand() % 13;
        q1->show(false);
        q2->show(false);
        q3->show(false);
        q4->show(false);
        q5->show(false);
        q6->show(false);
        q7->show(false);
        q8->show(false);
        q9->show(false);
        q10->show(false);
        q11->show(false);
        q12->show(false);
        std::cout<<"random = "<<randomQ<<std::endl;
        answer[0] = false;
        answer[1] = false;
        answer[2] = false;
        answer[3] = false;
        switch (randomQ) {
            case 0:answer[0] = true;
                q1->show(true);
                break;
            case 1:answer[0] = true;
                q2->show(true);
                break;
            case 2:
                answer[0] = true;
                q3->show(true);
                break;
            case 3:answer[1] = true;
                q4->show(true);
                break;
            case 4:
                answer[1] = true;
                q5->show(true);
                break;
            case 5:
                answer[1] = true;
                q6->show(true);
                break;
            case 6:answer[2] = true;
                q7->show(true);
                break;
            case 7:
                answer[2] = true;
                q8->show(true);
                break;
            case 8:
                answer[2] = true;
                q9->show(true);
                break;
            case 9:answer[3] = true;
                q10->show(true);
                break;
            case 10:
                answer[3] = true;
                q11->show(true);
                break;
            case 11:
                answer[3] = true;
                q12->show(true);
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
                                           *score += answer[0] ? 100 : 0;
                                           result->show(true);
                                           timer->setTimeout([=]() mutable {
                                               result->show(false);
                                               showNewQuestion();
                                               *answering = false;
                                           }, 1000);
                                       },
                                       2, {600, 600}, {50, 500, POSITION_RELATIVE});
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
                                      2, {600, 600}, {350, 500, POSITION_RELATIVE});
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
                                        2, {600, 600}, {650, 500, POSITION_RELATIVE});
    sceneContainer->append(canGreenC);
    auto canYellowD = new TouchableImage(SDLRendererController, canYellow,
                                         [=](Touchable *button, ComponentPosition clickPosition,
                                             SDL_Event event) mutable {
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
                                         },
                                         2, {600, 600}, {950, 500, POSITION_RELATIVE});
    sceneContainer->append(canYellowD);
    auto boxEnd = new Button(SDLRendererController,
                             "Your score = ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                               {255, 255, 255}},
                             box,
                             [=](Touchable *button, ComponentPosition clickPosition,
                                 SDL_Event event) mutable {
                             },
                             50, {500, 300}, {600, 300, POSITION_ABSOLUTE});
    boxEnd->show(false);
    sceneContainer->append(boxEnd);

    auto backToMenu = new Button(SDLRendererController,
                                 "MENU",
                                 {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                  {255, 255, 255}},
                                 box,
                                 [=](Touchable *button, ComponentPosition clickPosition,
                                     SDL_Event event) mutable {
                                     gameScenes->setCurrentSceneName("menu") ;
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
                boxOfTime->show(false);
                timer->stop();

            }
        }, 1000);
    });
    scene->onExitScene([=](Scene *scene) mutable {
        timer->stop();
    });
}