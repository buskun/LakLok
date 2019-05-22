#include "scene_list.h"

void mainMenu(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("menu");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();

    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

    const GameProp GAME_PROP = gameScenes->getGameProp();
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bG_main.png");

    typedef struct {
        SDL_Texture *_1;
        SDL_Texture *_2;
        SDL_Texture *_3;
        SDL_Texture *_4;
    } Faces;
    Faces mainGame_1;

    typedef struct {
        SDL_Texture *_5;
        SDL_Texture *_6;
        SDL_Texture *_7;
    } World;
    World world1;

    mainGame_1._1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/mainGame_1.jpg");
    mainGame_1._2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/tu_a_04.jpg");
    mainGame_1._3 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/tu_a_16.jpg");
    mainGame_1._4 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/tu_a_19.jpg");
    world1._5 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/world1.png");
    world1._6 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/world2.png");
    world1._7 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/world3.png");
    SDL_Texture *mainGame_2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/mainGame_2.jpg");
    SDL_Texture *mainGame_3 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/mainGame_3.jpg");
    SDL_Texture *mainGame_4 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/mainGame_4.jpg");

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
    auto firstImage = new TouchableImage(SDLRendererController, mainGame_1._1,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             gameScenes->setCurrentSceneName("introGame1");
                                         },
                                         1, {200, 200}, {200, 150, POSITION_RELATIVE});
    sceneContainer->append(firstImage);
    sceneContainer->append(
            new ImageView(SDLRendererController, mainGame_2, 1, {200, 200}, {200, 600, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController, mainGame_2,
                                              [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  gameScenes->setCurrentSceneName("mainGame3");
                                              },
                                              1, {200, 200}, {200, 600, POSITION_RELATIVE}));
    sceneContainer->append(
            new ImageView(SDLRendererController, mainGame_3, 1, {200, 200}, {1225, 600, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController, mainGame_3,
                                              [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  gameScenes->setCurrentSceneName("mainGame4");
                                              },
                                              1, {200, 200}, {1225, 600, POSITION_RELATIVE}));
    sceneContainer->append(
            new ImageView(SDLRendererController, mainGame_4, 1, {200, 200}, {1225, 150, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController, mainGame_4,
                                              [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  gameScenes->setCurrentSceneName("mainGame2");
                                              },
                                              1, {200, 200}, {1225, 150, POSITION_RELATIVE}));
    int *imgState = new int{0},
            *imgState2 = new int{0};
    auto timer = new Timer();
    timer->setInterval([=]() {
        switch (*imgState2) {
            case 0:
                world->setHoverImage(world1._5);
                break;
            case 1:
                world->setHoverImage(world1._6);
                break;
            case 2:
                world->setHoverImage(world1._7);
                break;
            default:;
        }
        *imgState = (*imgState + 1) % 3;
    }, 500/*1 วิมีสองรูป*/);
    timer->setInterval([=]() {
        switch (*imgState) {
            case 0:
                firstImage->setHoverImage(mainGame_1._1);
                break;
            case 1:
                firstImage->setHoverImage(mainGame_1._2);
                break;
            case 2:
                firstImage->setHoverImage(mainGame_1._3);
                break;
            case 3:
                firstImage->setHoverImage(mainGame_1._4);
                break;
            default:;
        }
        *imgState = (*imgState + 1) % 4;
    }, 500/*1 วิมีสองรูป*/);

    scene->onGameTick([](Scene *currentScene) {
    });

	SDL::setSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
}