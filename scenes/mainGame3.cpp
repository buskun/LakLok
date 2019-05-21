#include "scene_list.h"
void mainGame3(GameScenes *gameScenes) {
    Scene *scene = gameScenes->newScene("mainGame3");
    gameScenes->addScene(scene);
    Container *sceneContainer = scene->getSceneContainer();
    auto *eventManager = gameScenes->getEventManager();
    RendererController *SDLRendererController = gameScenes->getRendererController();
    SDL_Renderer *SDLRenderer = SDLRendererController->getSDLRenderer();

    const GameProp GAME_PROP = gameScenes->getGameProp();

    GameProp gameProp = gameScenes->getGameProp();
    int bW, bH, score = 0;
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bgmaingame3.jpg");
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    auto *timer = new Timer();

   /*auto boxEnd = sceneContainer->append(new Button(SDLRendererController,
                                                    "Your score = ", {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                                      {255, 255, 255}},
                                                    box,
                                                    [=](Touchable *button, ComponentPosition clickPosition,
                                                        SDL_Event event) mutable {
                                                    },
                                                    50, {500, 300}, {600, 300, POSITION_ABSOLUTE}));
    boxEnd->show(false);

    auto backToMenu = sceneContainer->append(new Button(SDLRendererController,
                                                        "MENU",
                                                        {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                         {255, 255, 255}},
                                                        box,
                                                        [=](Touchable *button, ComponentPosition clickPosition,
                                                            SDL_Event event) mutable {
                                                            gameScenes->setCurrentSceneName("menu");
                                                        },
                                                        16, {300, 100}, {1250, 750, POSITION_ABSOLUTE}))->show(false);
    scene->onEnterScene([=](Scene *scene) mutable {
        //init();
        int imgState = 10;
        //textTime->changeText(std::to_string(imgState));
        timer->setInterval([=]() mutable {
            //textTime->changeText(std::to_string(--imgState));
            if (imgState <= 0) {
                boxEnd->getTextView()->changeText("Your score = " + std::to_string(*score));
                ComponentSize textSize = boxEnd->getTextView()->getSize();
                boxEnd->getTextView()->setPosition({(boxEnd->getSize().width - textSize.width) / 2,
                                                    (boxEnd->getSize().height - textSize.height) / 2});
                timer->stop();
            }
        }, 1000);
    });

    scene->onExitScene([=](Scene *scene) mutable {
        timer->stop();
    });
    */
}