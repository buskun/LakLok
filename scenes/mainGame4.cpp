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
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    sceneContainer->append(new ImageView(SDLRendererController, box, 10, {600, 150}, {850, 650, POSITION_RELATIVE}));
    ImageView *choices[] = {
            new ImageView(SDLRendererController, box, 10, {600, 150}, {150, 450, POSITION_RELATIVE}),
            new ImageView(SDLRendererController, box, 10, {600, 150}, {850, 450, POSITION_RELATIVE}),
            new ImageView(SDLRendererController, box, 10, {600, 150}, {150, 650, POSITION_RELATIVE}),
            new ImageView(SDLRendererController, box, 10, {600, 150}, {850, 650, POSITION_RELATIVE})
    };

    sceneContainer->append(choices[0]);
    sceneContainer->append(choices[1]);
    sceneContainer->append(choices[2]);
    sceneContainer->append(choices[3]);
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
                choices[0]->show(true);
                break;
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                choices[1]->show(true);
                break;
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
                choices[2]->show(true);
                break;
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
                choices[3]->show(true);
                break;
            default:;
        }
    };
    showNewQuestion();
    auto Q1 = new TouchableText(SDLRendererController, "8;p8;p8;p8;p8;8p8;8;8p;8p8;;88;p;\nhuihuihiu",
                                {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                                [=](Touchable *touchable, ComponentPosition clickPosition, SDL_Event event) mutable{
                                    if (*answering) return;
                                    *answering = true;

                                    timer->setTimeout([=]() mutable {

                                        showNewQuestion();
                                        *answering = false;
                                    }, 1000);
                                },10,{ 150, 450, POSITION_RELATIVE });
    sceneContainer->append(Q1);
}