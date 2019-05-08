#include "scene_list.h"
void mainGame2(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("mainGame2");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

    const GameProp GAME_PROP = gameScenes->getGameProp();

    GameProp gameProp = gameScenes->getGameProp();
    int bW, bH;
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/bgmaingame2.jpg");
    SDL_Texture *compost = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/compost.png");
    SDL_Texture *lvone = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv1.png");
    SDL_Texture *lvtwo = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv2.png");
    SDL_Texture *lvthree = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv3.png");
    SDL_Texture *lvfour = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv4.png");
    SDL_Texture *lvfive = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv5.png");
    SDL_Texture *seed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png");
    SDL_Texture *shop = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/shop.png");
    SDL_Texture *watering = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/watering.png");
    SDL_Texture *land = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/land.png");
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);

    auto land1 = new Button(SDLRendererController,
                                                   "", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
                                                   land,
                                                   [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                   },
                                                   1, { 200, 200 }, { 100, 400, POSITION_ABSOLUTE });
    auto land2 = new Button(SDLRendererController,
                                                   "", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
                                                   land,
                                                   [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                   },
                                                   1, { 200, 200 }, { 300, 400, POSITION_ABSOLUTE });
    auto land3 = new Button(SDLRendererController,
                                                   "", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
                                                   land,
                                                   [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                   },
                                                   1, { 200, 200 }, { 500, 400, POSITION_ABSOLUTE });
    auto land4 = new Button(SDLRendererController,
                                                 "", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
                                                 land,
                                                 [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 },
                                                 1, { 200, 200 }, { 700, 400, POSITION_ABSOLUTE });
    auto btnshop = new Button(SDLRendererController,
                          "", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
                          shop,
                          [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                          },
                          3, { 300, 200 }, { 100, 700, POSITION_ABSOLUTE });
    auto btnwater = new Button(SDLRendererController,
                                                 "", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
                                                 watering,
                                                 [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 },
                                                 3, { 300, 200 }, { 410, 700, POSITION_ABSOLUTE });
    auto btnseed = new Button(SDLRendererController,
                                                 "", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
                                                 seed,
                                                 [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 },
                                                 3, { 300, 200 }, { 720, 700, POSITION_ABSOLUTE });
    auto btncompost = new Button(SDLRendererController,
                                                 "", { 18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", { 255, 255, 255 }},
                                                 compost,
                                                 [&](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                 },
                                                 3, { 300, 200 }, { 1030, 700, POSITION_ABSOLUTE });

}