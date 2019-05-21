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
    int *selectionState = new int{0};
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/bgmaingame2.png");
    SDL_Texture *compost = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/compost.png");
    SDL_Texture *lvone = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv1.png");
    SDL_Texture *lvtwo = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv2.png");
    SDL_Texture *lvthree = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv3.png");
    SDL_Texture *lvfour = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/lv4.png");
    SDL_Texture *seed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png");
    SDL_Texture *shopN = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/ShopNo.png");
    SDL_Texture *waterIng = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/watering.png");
    SDL_Texture *water = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/water.png");
    SDL_Texture *land = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/land.png");
    SDL_Texture *landWater = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landWater.png");
    SDL_Texture *goB = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Gob.png");
    SDL_Texture *landwSeed = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwSeed.png");
    SDL_Texture *landwWaterwSeed = SDL::loadTexture(SDLRenderer,
                                                    GAME_PROP.RESOURCE_PATH + "/img/maingame2/landwWaterwSeed.png");
    SDL_Texture *goB2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame2/Gob2.png");
    int *money = new int{0};
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto landseed = new ImageView(SDLRendererController, landwSeed, 2, {200, 200}, {100, 400, POSITION_RELATIVE});
    auto landwaterseed = new ImageView(SDLRendererController, landwWaterwSeed, 2, {200, 200},
                                       {100, 400, POSITION_RELATIVE});
    auto waterIcon = new ImageView(SDLRendererController, water, 2, {200, 200}, {100, 400, POSITION_RELATIVE});
    auto landwater1 = new ImageView(SDLRendererController, landWater, 2, {300, 300}, {100, 400, POSITION_RELATIVE});
    auto landwater2 = new ImageView(SDLRendererController, landWater, 2, {300, 300}, {400, 400, POSITION_RELATIVE});
    auto landwater3 = new ImageView(SDLRendererController, landWater, 2, {300, 300}, {800, 400, POSITION_RELATIVE});
    auto landwater4 = new ImageView(SDLRendererController, landWater, 2, {300, 300}, {1100, 400, POSITION_RELATIVE});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    auto land1 = new Button(SDLRendererController,
                            "", {18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                            land,
                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                if (SDL::isCustomCursor && *selectionState == 1) {
                                    landwater1->show(true);
                                    SDL::useSystemCursor();
                                    *selectionState = 0;
                                }
                            },
                            1, {300, 300}, {100, 400, POSITION_ABSOLUTE});
    auto land2 = new Button(SDLRendererController,
                            "", {18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                            land,
                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                if (SDL::isCustomCursor && *selectionState == 2) {
                                    landwater2->show(true);
                                    SDL::useSystemCursor();
                                    *selectionState = 0;
                                }
                            },
                            1, {300, 300}, {400, 400, POSITION_ABSOLUTE});
    auto land3 = new Button(SDLRendererController,
                            "", {18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                            land,
                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                if (SDL::isCustomCursor && *selectionState == 3) {
                                    landwater3->show(true);
                                    SDL::useSystemCursor();
                                    *selectionState = 0;
                                }
                            },
                            1, {300, 300}, {800, 400, POSITION_ABSOLUTE});
    auto land4 = new Button(SDLRendererController,
                            "", {18, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf", {255, 255, 255}},
                            land,
                            [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                if (SDL::isCustomCursor) {
                                    landwater4->show(true);
                                    SDL::useSystemCursor();
                                    *selectionState = 0;
                                }
                            },
                            1, {300, 300}, {1100, 400, POSITION_ABSOLUTE});
    auto btnshop = new TouchableImage(SDLRendererController,
                                      shopN,
                                      [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                          gameScenes->setCurrentSceneName("mainGame2Shop");
                                      },
                                      3, {100, 100}, {0, 0, POSITION_RELATIVE});
    auto btnwater = new TouchableImage(SDLRendererController,
                                       water,
                                       [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                           SDL::setCustomCursor(GAME_PROP.RESOURCE_PATH + "/img/maingame2/watering.png",
                                                                50, 50);
                                           SDL::useCustomCursor();
                                           *selectionState = 1;
                                           *money +=100;
                                       },
                                       3, {150, 150}, {0, 0, POSITION_RELATIVE});
    auto btnseed = new TouchableImage(SDLRendererController,
                                      seed,
                                      [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                          SDL::setCustomCursor(GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png",
                                                               0, 0);//todo
                                          SDL::useCustomCursor();
                                          *selectionState = 2;
                                      },
                                      3, {150, 150}, {0, 0, POSITION_RELATIVE});
    auto btncompost = new TouchableImage(SDLRendererController,
                                         compost,
                                         [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                             SDL::setCustomCursor(GAME_PROP.RESOURCE_PATH + "", 0, 0);
                                             btnseed->show(false);
                                             *selectionState = 3;
                                         },
                                         3, {150, 150}, {0, 0, POSITION_RELATIVE});
    auto boxmoney = sceneContainer->append(new Button(SDLRendererController,
                                                    "Your score = ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                                      {0, 0, 0}},
                                                                      goB2,
                                                    [=](Touchable *button, ComponentPosition clickPosition,
                                                        SDL_Event event) mutable {
                                                    },
                                                    50, {625, 100}, {1000, 50, POSITION_ABSOLUTE}));
    boxmoney->getTextView()->changeText("Your money = " + std::to_string(*money));
    ComponentSize textSize = boxmoney->getTextView()->getSize();
    boxmoney->getTextView()->setPosition({(boxmoney->getSize().width - textSize.width) / 2,
                                        (boxmoney->getSize().height - textSize.height) / 2});

    auto icon1Container = new Container(SDLRendererController, 2, {360, 150}, {25, 700, POSITION_ABSOLUTE});
    icon1Container->append(new ImageView(SDLRendererController, goB, 2, {360, 150}, {0, 0, POSITION_RELATIVE}));
    icon1Container->append(btnshop);
    sceneContainer->append(icon1Container);
    auto icon2Container = new Container(SDLRendererController, 2, {360, 150}, {275, 700, POSITION_ABSOLUTE});
    icon2Container->append(new ImageView(SDLRendererController, goB, 2, {360, 150}, {0, 0, POSITION_RELATIVE}));
    icon2Container->append(btnwater);
    sceneContainer->append(icon2Container);
    auto icon3Container = new Container(SDLRendererController, 2, {360, 150}, {525, 700, POSITION_ABSOLUTE});
    icon3Container->append(new ImageView(SDLRendererController, goB, 2, {360, 150}, {0, 0, POSITION_RELATIVE}));
    icon3Container->append(btnseed);
    sceneContainer->append(icon3Container);
    auto icon4Container = new Container(SDLRendererController, 2, {360, 150}, {775, 700, POSITION_ABSOLUTE});
    icon4Container->append(new ImageView(SDLRendererController, goB, 2, {360, 150}, {0, 0, POSITION_RELATIVE}));
    icon4Container->append(btncompost);
    sceneContainer->append(icon4Container);
    sceneContainer->append(land1);
    sceneContainer->append(land2);
    sceneContainer->append(land3);
    sceneContainer->append(land4);
    sceneContainer->append(landseed);
    landseed->show(false);
    sceneContainer->append(landwaterseed);
    landwaterseed->show(false);
    waterIcon->show(false);
    sceneContainer->append(landwater1);
    landwater1->show(false);
    sceneContainer->append(landwater2);
    landwater2->show(false);
    sceneContainer->append(landwater3);
    landwater3->show(false);
    sceneContainer->append(landwater4);
    landwater4->show(false);
}