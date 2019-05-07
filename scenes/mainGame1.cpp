#include "scene_list.h"
#include <cstdlib>
#include <time.h>

void mainGame1(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("mainGame1");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

    auto *timer = new Timer();
    const GameProp GAME_PROP = gameScenes->getGameProp();
    int bW, bH, score = 0;

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
    sceneContainer->setPosition({0, 0});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    auto gameC = new ImageView(SDLRendererController, gameTrue, 10, {300, 300}, {300, 300, POSITION_RELATIVE});
    gameC->show(false);
    sceneContainer->append(gameC);
    auto gameX = new ImageView(SDLRendererController, gameFalse, 10, {300, 300}, {300, 300, POSITION_RELATIVE});
    gameX->show(false);
    sceneContainer->append(gameX);
    int imgState = 10;
    int *answer = new int[4];
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
    auto textscore = new TextView(SDLRendererController,
                                 "",
                                 {200, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                                 20, {675, 50, POSITION_ABSOLUTE});

    auto showNewQuestion = [=]() mutable {
        srand(time(nullptr));
        int randomQ = rand() % 29;
        q1->show(false);
        q2->show(false);
        q3->show(false);
        q4->show(false);
        answer[0] = 0;
        answer[1] = 0;
        answer[2] = 0;
        answer[3] = 0;
        std::cout << randomQ << std::endl;
        switch (randomQ) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                q1->show(true);
                answer[0] = 1;
                break;
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                q2->show(true);
                answer[1] = 1;
                break;
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
                q3->show(true);
                answer[2] = 1;
                break;
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
                q4->show(true);
                answer[3] = 1;
                break;
            default:;
        }
    };

    showNewQuestion();

    sceneContainer->append(textTime);
    auto canBlueA = sceneContainer->append(new TouchableImage(SDLRendererController, canBlue,
                                                              [=](Touchable *button, ComponentPosition clickPosition,
                                                                  SDL_Event event) mutable {
                                                                  auto result = answer[0] ? gameC : gameX;
                                                                  score += answer[0] ? 100 : 0;
                                                                  result->show(true);
                                                                  timer->setTimeout([=]() mutable {
                                                                      result->show(false);
                                                                      showNewQuestion();
                                                                  }, 1000);
                                                              },
                                                              2, {200, 300}, {350, 600, POSITION_RELATIVE}));
    auto canRedB = sceneContainer->append(new TouchableImage(SDLRendererController, canRed,
                                                             [=](Touchable *button, ComponentPosition clickPosition,
                                                                 SDL_Event event) mutable {
                                                                 auto result = answer[1] ? gameC : gameX;
                                                                 score += answer[1] ? 100 : 0;
                                                                 result->show(true);
                                                                 timer->setTimeout([=]() mutable {
                                                                     result->show(false);
                                                                     showNewQuestion();
                                                                 }, 1000);
                                                             },
                                                             2, {200, 300}, {600, 600, POSITION_RELATIVE}));
    auto canGreenC = sceneContainer->append(new TouchableImage(SDLRendererController, canGreen,
                                                               [=](Touchable *button, ComponentPosition clickPosition,
                                                                   SDL_Event event) mutable {
                                                                   auto result = answer[2] ? gameC : gameX;
                                                                   score += answer[2] ? 100 : 0;
                                                                   result->show(true);
                                                                   timer->setTimeout([=]() mutable {
                                                                       result->show(false);
                                                                       showNewQuestion();
                                                                   }, 1000);
                                                               },
                                                               2, {200, 300}, {850, 600, POSITION_RELATIVE}));
    auto canYellowD = sceneContainer->append(new TouchableImage(SDLRendererController, canYellow,
                                                                [=](Touchable *button, ComponentPosition clickPosition,
                                                                    SDL_Event event) mutable {
                                                                    auto result = answer[3] ? gameC : gameX;
                                                                    score += answer[3] ? 100 : 0;
                                                                    result->show(true);
                                                                    timer->setTimeout([=]() mutable {
                                                                        result->show(false);
                                                                        showNewQuestion();
                                                                    }, 1000);
                                                                },
                                                                2, {200, 300}, {1100, 600, POSITION_RELATIVE}));
    auto boxend = sceneContainer->append(new Button(SDLRendererController,
                                                    "", {200, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                         {255, 255, 255}},
                                                    box,
                                                    [=](Touchable *button, ComponentPosition clickPosition,
                                                        SDL_Event event)mutable {
                                                        textscore->changeText(std::to_string(score));
                                                        sceneContainer->append(textscore);
                                                    },
                                                    16, {300, 100}, {1250, 750, POSITION_ABSOLUTE}))->show(false);

    auto backToMenu = sceneContainer->append(new Button(SDLRendererController,
                                      "MENU", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                               {255, 255, 255}},
                                      box,
                                      [=](Touchable *button, ComponentPosition clickPosition,
                                          SDL_Event event)mutable {

                                      },
                                      16, {300, 100}, {1250, 750, POSITION_ABSOLUTE}))->show(false);

    timer->setInterval([=]() mutable {
        textTime->changeText(std::to_string(imgState--));
        if(imgState<=0) {
            canBlueA->show(false);
            canRedB->show(false);
            canGreenC->show(false);
            canYellowD->show(false);
            boxend->show(true);
            backToMenu->show(true);
        }
    }, 1000);


}