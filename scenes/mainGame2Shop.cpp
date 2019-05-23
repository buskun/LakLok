#include "scene_list.h"

void mainGame2Shop(GameScenes *gameScenes, Game *game) {
    Scene *scene = gameScenes->newScene("mainGame2Shop");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();
    const GameProp GAME_PROP = gameScenes->getGameProp();
    GameProp gameProp = gameScenes->getGameProp();
    int bW, bH;
    int *money = new int{0};
    int *seed = new int{0};
    int *numberOfItem = new int{0};
    *numberOfItem = game->getItem();
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
    auto itemshow = sceneContainer->append(new TextView(SDLRendererController,
                                                        "x1",
                                                        {100, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                                         {0, 0, 0}},
                                                        50, {400, 175, POSITION_ABSOLUTE}));
    sceneContainer->append(itemshow);
    itemshow->changeText("x" + std::to_string(game->getItem()));
    auto boxmoney = sceneContainer->append(new Button(SDLRendererController,
                                                      "Your money : ",
                                                      {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                       {0, 0, 0}},
                                                      goB,
                                                      [=](Touchable *button, ComponentPosition clickPosition,
                                                          SDL_Event event) mutable {
                                                      },
                                                      50, {750, 100}, {950, 50, POSITION_ABSOLUTE}));
    auto sellitem = sceneContainer->append(new Button(SDLRendererController,
                                                      "sell item ",
                                                      {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                       {255, 255, 255}},
                                                      box,
                                                      [=](Touchable *button, ComponentPosition clickPosition,
                                                          SDL_Event event) mutable {
                                                          if (game->getItem() > 0) {
                                                              numberOfItem -- ;
                                                              game->setItem(game->getItem()-1);
                                                              itemshow->changeText(
                                                                      "x" + std::to_string(game->getItem()));
                                                              *money += 100;
                                                              game->setMoney(*money + 100);
                                                              boxmoney->getTextView()->changeText(
                                                                      "Your money = " + std::to_string(*money));

                                                          }
                                                      },
                                                      50, {300, 100}, {100, 175, POSITION_ABSOLUTE}));
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
                                                      SDL_Event event) mutable {
                                                      if (*money >= 100) {
                                                          *money -= 100;
                                                          game->setMoney(*money);
                                                          game->setSeed(game->getSeed() + 1);
                                                          boxmoney->getTextView()->changeText(
                                                                  "Your money = " + std::to_string(*money));

                                                      }
                                                  },
                                                  16, {150, 100}, {670, 350, POSITION_ABSOLUTE}));
    auto pai2 = sceneContainer->append(new Button(SDLRendererController,
                                                  "250", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                          {255, 255, 255}},
                                                  box,
                                                  [=](Touchable *button, ComponentPosition clickPosition,
                                                      SDL_Event event)mutable {
                                                      if (*money >= 250) {
                                                          *money -= 250;
                                                          game->setMoney(*money);
                                                          game->setSeed(game->getSeed() + 3);
                                                          boxmoney->getTextView()->changeText(
                                                                  "Your money = " + std::to_string(*money));
                                                      }

                                                  },
                                                  16, {150, 100}, {970, 350, POSITION_ABSOLUTE}));
    auto pai3 = sceneContainer->append(new Button(SDLRendererController,
                                                  "400", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                          {255, 255, 255}},
                                                  box,
                                                  [=](Touchable *button, ComponentPosition clickPosition,
                                                      SDL_Event event)mutable {
                                                      if (*money >= 400) {
                                                          *money -= 400;
                                                          game->setMoney(*money);
                                                          game->setSeed(game->getSeed() + 5);
                                                          boxmoney->getTextView()->changeText(
                                                                  "Your money = " + std::to_string(*money));
                                                      }
                                                  },
                                                  16, {150, 100}, {1250, 350, POSITION_ABSOLUTE}));
    sceneContainer->append(new TouchableImage(SDLRendererController,
                                              SDL::loadTexture(SDLRenderer,
                                                               GAME_PROP.RESOURCE_PATH + "/img/maingame2/seed.png"),
                                              [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  if (*money >= 100) {
                                                      *money -= 100;
                                                      game->setMoney(*money);
                                                      game->setSeed(game->getSeed() + 1);
                                                      boxmoney->getTextView()->changeText(
                                                              "Your money = " + std::to_string(*money));
                                                  }
                                              },
                                              2, {300, 300}, {600, 520, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController,
                                              SDL::loadTexture(SDLRenderer,
                                                               GAME_PROP.RESOURCE_PATH + "/img/maingame2/Seed x3.png"),
                                              [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  if (*money >= 250) {
                                                      *money -= 250;
                                                      game->setMoney(*money);
                                                      game->setSeed(game->getSeed() + 3);
                                                      boxmoney->getTextView()->changeText(
                                                              "Your money = " + std::to_string(*money));
                                                  }
                                              },
                                              2, {300, 300}, {850, 480, POSITION_RELATIVE}));
    sceneContainer->append(new TouchableImage(SDLRendererController,
                                              SDL::loadTexture(SDLRenderer,
                                                               GAME_PROP.RESOURCE_PATH + "/img/maingame2/Seed x5.png"),
                                              [=](Touchable *button, ComponentPosition clickPosition, SDL_Event event) {
                                                  if (*money >= 400) {
                                                      *money -= 400;
                                                      game->setMoney(*money);
                                                      game->setSeed(game->getSeed() + 5);
                                                      boxmoney->getTextView()->changeText(
                                                              "Your money = " + std::to_string(*money));
                                                  }
                                              },
                                              2, {300, 300}, {1150, 470, POSITION_RELATIVE}));

    boxmoney->getTextView()->changeText("Your money = " + /*std::to_string(game->getMoney())*/std::to_string(*money));
    ComponentSize textSize = boxmoney->getTextView()->getSize();
    boxmoney->getTextView()->setPosition({(boxmoney->getSize().width - textSize.width) / 2 - 25,
                                          (boxmoney->getSize().height - textSize.height) / 2});

    scene->onEnterScene([=](Scene *scene) mutable {
        *money = game->getMoney();
        *seed = game->getSeed();
        *numberOfItem = game->getItem();
        boxmoney->getTextView()->changeText("Your money =" + std::to_string(*money));
        itemshow->changeText(
                "x" + std::to_string(game->getItem()));
    });
}
