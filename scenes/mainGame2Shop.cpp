#include "scene_list.h"

void mainGame2Shop(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("mainGame2Shop");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
    const GameProp GAME_PROP = gameScenes->getGameProp();
    GameProp gameProp = gameScenes->getGameProp();
    int bW, bH, score = 0;
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Inshop.png");
    SDL_Texture *goB = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Gob.png");
    SDL_Texture *item1 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png");
    SDL_Texture *item2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Seed x3.png");
    SDL_Texture *item3 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Seed x5.png");
    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    auto btn = sceneContainer->append(new Button(SDLRendererController,
                                                 "back", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                          {0, 0, 0}},
                                                 goB,
                                                 [=](Touchable *button, ComponentPosition clickPosition,
                                                     SDL_Event event)mutable {
                                                     gameScenes->setCurrentSceneName("mainGame2");
                                                 },
                                                 16, {300, 100}, {1250, 780, POSITION_ABSOLUTE}));
    auto pai1 = sceneContainer->append(new Button(SDLRendererController,
                                                  "100", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                          {255, 255, 255}},
                                                  box,
                                                  [=](Touchable *button, ComponentPosition clickPosition,
                                                      SDL_Event event)mutable {
                                                      std::cout << "buy";
                                                  },
                                                  16, {150, 100}, {670, 350, POSITION_ABSOLUTE}));
    auto pai2 = sceneContainer->append(new Button(SDLRendererController,
                                                  "250", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                          {255, 255, 255}},
                                                  box,
                                                  [=](Touchable *button, ComponentPosition clickPosition,
                                                      SDL_Event event)mutable {
                                                      std::cout << "buy";
                                                  },
                                                  16, {150, 100}, {970, 350, POSITION_ABSOLUTE}));
    auto pai3 = sceneContainer->append(new Button(SDLRendererController,
                                                  "400", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                          {255, 255, 255}},
                                                  box,
                                                  [=](Touchable *button, ComponentPosition clickPosition,
                                                      SDL_Event event)mutable {
                                                      std::cout << "buy";
                                                  },
                                                  16, {150, 100}, {1250, 350, POSITION_ABSOLUTE}));
    sceneContainer->append(new TouchableImage(SDLRendererController,
                                              SDL::loadTexture(SDLRenderer,
                                                               GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png"),
                                              {
                                              },
                                              2, {300, 300}, {600, 520, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController,
                                              SDL::loadTexture(SDLRenderer,
                                                               GAME_PROP.RESOURCE_PATH + "/img/maingame2/Seed x3.png"),
                                              {

                                              },
                                              2, {300, 300}, {850, 480, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController,
                                              SDL::loadTexture(SDLRenderer,
                                                               GAME_PROP.RESOURCE_PATH + "/img/maingame2/Seed x5.png"),
                                              {

                                              },
                                              2, {300, 300}, {1150, 470, POSITION_RELATIVE}));


}
