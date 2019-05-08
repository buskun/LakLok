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
    int bW, bH;
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bgmaingame4.jpg");
    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    SDL_Texture *gameTrue = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/true.png");
    SDL_Texture *gameFalse = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/false.png");
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    auto  A = new ImageView(SDLRendererController, box, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto B = new ImageView(SDLRendererController, box, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto C = new ImageView(SDLRendererController, box, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto D = new ImageView(SDLRendererController, box, 10, {300, 300}, {645, 300, POSITION_RELATIVE});
    auto boxA = new Button(SDLRendererController,
                              " ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                        {255, 255, 255}},
                              box,
                              [=](Touchable *button, ComponentPosition clickPosition,
                                  SDL_Event event) mutable {
                              },
                              50, {600, 200}, {200, 350, POSITION_ABSOLUTE});
    auto boxB = new Button(SDLRendererController,
                              "  ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                      {255, 255, 255}},
                              box,
                              [=](Touchable *button, ComponentPosition clickPosition,
                                  SDL_Event event) mutable {
                              },
                              50, {600, 200}, {200, 600, POSITION_ABSOLUTE});
    auto boxC = new Button(SDLRendererController,
                              " ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                          {255, 255, 255}},
                              box,
                              [=](Touchable *button, ComponentPosition clickPosition,
                                  SDL_Event event) mutable {
                              },
                              50, {600, 200}, {850, 600, POSITION_ABSOLUTE});
    auto boxD= new Button(SDLRendererController,
                              "  ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                                   {255, 255, 255}},
                              box,
                              [=](Touchable *button, ComponentPosition clickPosition,
                                  SDL_Event event) mutable {
                              },
                              50, {600, 200}, {850, 350, POSITION_ABSOLUTE});
    auto showNewQuestion = [=]() mutable {
        srand(time(nullptr));
        int randomQ = rand() % 29;
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
                boxA->show(true);
                break;
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                boxB->show(true);
                break;
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
                boxC->show(true);
                break;
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
                boxD->show(true);
                break;
            default:;
        }
    };
    showNewQuestion();
    /*sceneContainer->append(boxQ1->show(false));
    sceneContainer->append(boxQ1A1->show(false));
    sceneContainer->append(boxQ1A2->show(false));
    sceneContainer->append(boxQ1A3->show(false));
    sceneContainer->append(boxQ1A4->show(false));*/

}