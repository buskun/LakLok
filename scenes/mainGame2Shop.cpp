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
                                                 16, {300, 100}, {1250, 750, POSITION_ABSOLUTE}));

}
