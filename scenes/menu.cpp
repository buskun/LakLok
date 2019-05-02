#include "scene_list.h"

void mainMenu(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("menu");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = new EventManager();

    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

    const GameProp GAME_PROP = gameScenes->getGameProp();

    GameProp gameProp = gameScenes->getGameProp();

    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bG_main.jpg");

    typedef struct {
        SDL_Texture *_1;
        SDL_Texture *_2;
        SDL_Texture *_3;
        SDL_Texture *_4;
    } Faces;
    Faces mainGame_1;

    mainGame_1._1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/mainGame_1.jpg");
    mainGame_1._2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/tu_a_04.jpg");
    mainGame_1._3 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/tu_a_16.jpg");
    mainGame_1._4 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/tu_a_19.jpg");

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
    auto background = new ImageView(SDLRendererController, bgTexture, 0, {bW, bH}, {-200, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    auto firstImage = new TouchableImage(SDLRendererController, mainGame_1._1,
                                         [](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             std::cout << "Image clicked 1" << std::endl;
                                         },
                                         1, {200, 200}, {200, 150, POSITION_RELATIVE});
    sceneContainer->append(firstImage);
    sceneContainer->append(
            new ImageView(SDLRendererController, mainGame_2, 1, {200, 200}, {200, 600, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController, mainGame_2,
                                              [](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  std::cout << "Image clicked 2" << std::endl;
                                              },
                                              1, {200, 200}, {200, 600, POSITION_RELATIVE}));
    sceneContainer->append(
            new ImageView(SDLRendererController, mainGame_3, 1, {200, 200}, {1225, 600, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController, mainGame_3,
                                              [](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  std::cout << "Image clicked 3" << std::endl;
                                              },
                                              1, {200, 200}, {1225, 600, POSITION_RELATIVE}));
    sceneContainer->append(
            new ImageView(SDLRendererController, mainGame_4, 1, {200, 200}, {1225, 150, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController, mainGame_4,
                                              [](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  std::cout << "Image clicked 4" << std::endl;
                                              },
                                              1, {200, 200}, {1225, 150, POSITION_RELATIVE}));
    int imgState = 0;
    Timer().setInterval([=, &imgState]() {
        switch (imgState) {
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
        imgState = (imgState + 1) % 4;
    }, 500/*1 วิมีสองรูป*/);
    /*auto text = new TextView(rendererController,
                             "Hello world!",
                             {24, gameProp.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}});
    text->setHoverText("Hella world!", {24, gameProp.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}});
    sceneContainer->append(text);

    eventManager->on(SDL_MOUSEBUTTONDOWN, [](SDL_Event event) {
        std::cout << "A" << std::endl;
    });

    scene->onGameTick([](Scene *currentScene) {
    });*/
}