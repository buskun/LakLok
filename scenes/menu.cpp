#include "scene_list.h"

void mainMenu(GameScenes *gameScenes, Game *game) {
    Scene *scene = gameScenes->newScene("menu");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
    const GameProp GAME_PROP = gameScenes->getGameProp();
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bG_main.png");
    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    int *score = new int{0};
    *score = game->getScore();
    typedef struct {
        SDL_Texture *_1;
        SDL_Texture *_2;
        SDL_Texture *_3;
    } Faces;
    Faces Intomain1;

    typedef struct {
        SDL_Texture *_5;
        SDL_Texture *_6;
        SDL_Texture *_7;
    } World;
    World world1;

    typedef struct {
        SDL_Texture *_8;
        SDL_Texture *_9;
        SDL_Texture *_10;
    } IntomainA;
    IntomainA Intomain2;

    typedef struct {
        SDL_Texture *_11;
        SDL_Texture *_12;
        SDL_Texture *_13;
    } IntomainB;
    IntomainB Iotomain3;

    typedef struct {
        SDL_Texture *_14;
        SDL_Texture *_15;
        SDL_Texture *_16;
    } IntomainC;
    IntomainC Intomain4;

    Intomain1._1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game1 (1).png");
    Intomain1._2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game1 (2).png");
    Intomain1._3 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game1 (3).png");
    world1._5 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/world1.png");
    world1._6 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/world2.png");
    world1._7 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/world3.png");
    Intomain2._8 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game2 (1).png");
    Intomain2._9 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game2 (2).png");
    Intomain2._10 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game2 (3).png");
    Iotomain3._11 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game3 (1).png");
    Iotomain3._12 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game3 (2).png");
    Iotomain3._13 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game3 (3).png");
    Intomain4._14 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game4 (1).png");
    Intomain4._15 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game4 (2).png");
    Intomain4._16 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/Game4 (3).png");
    int bW, bH;
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    /*sceneContainer->append(new TouchableImage(SDLRendererController, imgTexture,
                                              [ ](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  std::cout << "Image clicked" << std::endl;
                                              },
                                              10, { iW, iH },
                                              { GAME_PROP.WINDOW.WIDTH / 2 - iW / 2, GAME_PROP.WINDOW.HEIGHT / 2 - iH / 2,
                                                POSITION_RELATIVE }));*/
    auto world = new ImageView(SDLRendererController, world1._5, 1, {1200, 700}, {200, 125, POSITION_RELATIVE});
    sceneContainer->append(world);
    auto background = new ImageView(SDLRendererController, bgTexture, 0, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);

    auto firstImage = new TouchableImage(SDLRendererController, Intomain1._1,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             gameScenes->setCurrentSceneName("introGame1");
                                         },
                                         1, {600, 400}, {50, 50, POSITION_RELATIVE});
    sceneContainer->append(firstImage);

    auto firstImageOfmain3 = sceneContainer->append(new TouchableImage(SDLRendererController, Iotomain3._11,
                                                                       [=](Touchable *button,
                                                                           ComponentPosition clickPosition,
                                                                           SDL_Event event) {
                                                                           gameScenes->setCurrentSceneName(
                                                                                   "introGame3");
                                                                       },
                                                                       1, {600, 400},
                                                                       {975, 50, POSITION_RELATIVE}));//1225.150

    auto firstImageOfmain4 = sceneContainer->append(new TouchableImage(SDLRendererController, Intomain4._14,
                                                                       [=](Touchable *button,
                                                                           ComponentPosition clickPosition,
                                                                           SDL_Event event) {
                                                                           gameScenes->setCurrentSceneName(
                                                                                   "introGame4");
                                                                       },
                                                                       1, {625, 500}, {950, 485, POSITION_RELATIVE}));

    auto firstImageOfmain2 = sceneContainer->append(new TouchableImage(SDLRendererController, Intomain2._8,
                                                                       [=](Touchable *button,
                                                                           ComponentPosition clickPosition,
                                                                           SDL_Event event) {
                                                                           gameScenes->setCurrentSceneName(
                                                                                   "introGame2");
                                                                       },
                                                                       1, {750, 500},
                                                                       {-20, 500, POSITION_RELATIVE}));//200.600
    int *imgState = new int{0}, *imgState2 = new int{0};
    int *imgState3 = new int{0};
    int *imgState4 = new int{0};
    int *imgState5 = new int{0};
    auto timer = new Timer();
    timer->setInterval([=]() {
        switch (*imgState2) {
            case 0:
                world->setImage(world1._5);
                break;
            case 1:
                world->setImage(world1._6);
                break;
            case 2:
                world->setImage(world1._7);
                break;
            default:;
        }
        *imgState2 = (*imgState2 + 1) % 3;
    }, 500/*1 วิมีสองรูป*/);
    timer->setInterval([=]() {
        switch (*imgState) {
            case 0:
                firstImage->setHoverImage(Intomain1._1);
                break;
            case 1:
                firstImage->setHoverImage(Intomain1._2);
                break;
            case 2:
                firstImage->setHoverImage(Intomain1._3);
                break;
            default:;
        }
        *imgState = (*imgState + 1) % 3;
    }, 500/*1 วิมีสองรูป*/);
    timer->setInterval([=]() {
        switch (*imgState5) {
            case 0:
                firstImageOfmain2->setHoverImage(Intomain2._8);
                break;
            case 1:
                firstImageOfmain2->setHoverImage(Intomain2._9);
                break;
            case 2:
                firstImageOfmain2->setHoverImage(Intomain2._10);
                break;
            default:;
        }
        *imgState5 = (*imgState5 + 1) % 3;
    }, 500/*1 วิมีสองรูป*/);
    timer->setInterval([=]() {
        switch (*imgState3) {
            case 0:
                firstImageOfmain3->setHoverImage(Iotomain3._11);
                break;
            case 1:
                firstImageOfmain3->setHoverImage(Iotomain3._12);
                break;
            case 2:
                firstImageOfmain3->setHoverImage(Iotomain3._13);
                break;
            default:;
        }
        *imgState3 = (*imgState3 + 1) % 3;
    }, 500/*1 วิมีสองรูป*/);
    timer->setInterval([=]() {
        switch (*imgState4) {
            case 0:
                firstImageOfmain4->setHoverImage(Intomain4._14);
                break;
            case 1:
                firstImageOfmain4->setHoverImage(Intomain4._15);
                break;
            case 2:
                firstImageOfmain4->setHoverImage(Intomain4._16);
                break;
            default:;
        }
        *imgState4 = (*imgState4 + 1) % 3;
    }, 500/*1 วิมีสองรูป*/);
    auto boxscore = sceneContainer->append(new Button(SDLRendererController,
                                                      "World score =  ",
                                                      {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                                       {255, 255, 255}},
                                                      box,
                                                      [=](Touchable *button, ComponentPosition clickPosition,
                                                          SDL_Event event) mutable {
                                                      },
                                                      50, {500, 100}, {575, 25, POSITION_ABSOLUTE}));
    *score = game->getScore();
    boxscore->getTextView()->changeText("World score =  "+std::to_string(*score));
    ComponentSize textSize = boxscore->getTextView()->getSize();
    boxscore->getTextView()->setPosition({(boxscore->getSize().width - textSize.width) / 2,
                                        (boxscore->getSize().height - textSize.height) / 2});
    scene->onGameTick([](Scene *currentScene) {
    });
    scene->onEnterScene([=](Scene *scene) {
        *score = game->getScore();
        boxscore->getTextView()->changeText("World score = "+std::to_string(*score));
        ComponentSize textSize = boxscore->getTextView()->getSize();
        boxscore->getTextView()->setPosition({(boxscore->getSize().width - textSize.width) / 2,
                                              (boxscore->getSize().height - textSize.height) / 2});
    });
    SDL::setSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
}