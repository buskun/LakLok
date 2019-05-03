#include "scene_list.h"

void mainGame1(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("mainGame1");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = new EventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

    const GameProp GAME_PROP = gameScenes->getGameProp();

    GameProp gameProp = gameScenes->getGameProp();
    int bW, bH, score = 0;

    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bgmaingame1.jpg");
    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/box.png");
    SDL_Texture *canRed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/canRed.png");
    SDL_Texture *canBlue = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/canBlue.png");
    SDL_Texture *canYellow = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/canYellow.png");
    SDL_Texture *canGreen = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/canGreen.png");
    SDL_Texture *game1Q1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/game1Q1.png");
    SDL_Texture *gameTrue = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/true.png");
    SDL_Texture *gameFalse = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/false.png");
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    auto gameC = new ImageView(SDLRendererController, gameTrue, 10, {300, 300}, {300, 300, POSITION_RELATIVE});
    auto gameX = new ImageView(SDLRendererController, gameTrue, 0, {300, 300}, {300, 300, POSITION_RELATIVE});
    int imgState = 60;
    sceneContainer->append(background);
    sceneContainer->append(
            new ImageView(SDLRendererController, game1Q1, 2, {200, 200}, {675, 300, POSITION_RELATIVE}));
    sceneContainer->append(new ImageView(SDLRendererController, box, 2, {300, 100}, {645, 25, POSITION_RELATIVE}));
    auto textTime = new TextView(SDLRendererController,
                                 "",
                                 {50, gameProp.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                                 3, {675, 50, POSITION_ABSOLUTE});
    Timer().setInterval([=]() mutable {
        textTime->changeText(std::to_string(imgState--));
    }, 1000/*1 วิมีสองรูป*/);
    sceneContainer->append(textTime);
    auto canBlueA = sceneContainer->append(new TouchableImage(SDLRendererController, canBlue,
                                                              [=](Touchable *button, ComponentPosition clickPosition,
                                                                  SDL_Event event) {
                                                                  sceneContainer->append(gameC);
                                                              },
                                                              2, {200, 300}, {350, 600, POSITION_RELATIVE}));
    auto canRedB = sceneContainer->append(new TouchableImage(SDLRendererController, canRed,
                                                             [=](Touchable *button, ComponentPosition clickPosition,
                                                                 SDL_Event event) {
                                                                 std::cout << "Image clicked 4" << std::endl;
                                                             },
                                                             2, {200, 300}, {600, 600, POSITION_RELATIVE}));
    auto canGreenC = sceneContainer->append(new TouchableImage(SDLRendererController, canGreen,
                                                               [=](Touchable *button, ComponentPosition clickPosition,
                                                                   SDL_Event event) {
                                                                   std::cout << "Image clicked 4" << std::endl;
                                                               },
                                                               2, {200, 300}, {850, 600, POSITION_RELATIVE}));
    auto canYellowD = sceneContainer->append(new TouchableImage(SDLRendererController, canYellow,
                                                                [=](Touchable *button, ComponentPosition clickPosition,
                                                                    SDL_Event event) {
                                                                    std::cout << "Image clicked 4" << std::endl;
                                                                },
                                                                2, {200, 300}, {1100, 600, POSITION_RELATIVE}));

}