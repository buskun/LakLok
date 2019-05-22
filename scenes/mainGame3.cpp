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
    int bW, bH;
    SDL_Texture *bgTexture = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bgmaingame3.jpg");
    SDL_Texture *box = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame1/box.png");
    SDL_Texture *flask = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame3/Flask.png");
    SDL_Texture *iron = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame3/iron.png");
    SDL_Texture *light = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame3/light.png");
    SDL_Texture *notebook = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame3/notebook.png");
    SDL_Texture *tv = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame3/tv.png");
    SDL_Texture *key = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/maingame3/key.png");
    SDL_Texture *bg2 = SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH + "/img/bG_main.png");
    SDL_QueryTexture(bgTexture, nullptr, nullptr, &bW, &bH);
    sceneContainer->setPosition({0, 0});
    auto endBg = new ImageView(SDLRendererController, bg2, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(endBg->show(false));
    auto background = new ImageView(SDLRendererController, bgTexture, 1, {1600, 900}, {0, 0, POSITION_RELATIVE});
    sceneContainer->append(background);
    int *score = new int{0};
    auto *timer = new Timer();
    int *checkA = new int{0};
    int *checkB = new int{0};
    int *checkC = new int{0};
    int *checkD = new int{0};
    int *checkF = new int{0};
    auto keyQ = new ImageView(SDLRendererController, key, 1, {1200, 600}, {200, 150, POSITION_RELATIVE});
    sceneContainer->append(keyQ);
    /*flask*/  auto gameC1 = sceneContainer->append(new ImageView(SDLRendererController,
                                                      SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH +
                                                                                 "/img/maingame1/true.png"),
                                                      10, {200, 200}, {225, 270, POSITION_RELATIVE}))->show(false);
    /*iron*/ auto gameC2 = sceneContainer->append(new ImageView(SDLRendererController,
                                                       SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH +
                                                                                     "/img/maingame1/true.png"),
                                                       10, {200, 200}, {600, 450, POSITION_RELATIVE}))->show(false);
    /*light*/ auto gameC3 = sceneContainer->append(new ImageView(SDLRendererController,
                                                       SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH +
                                                                                     "/img/maingame1/true.png"),
                                                       10, {200, 200}, {890, 25, POSITION_RELATIVE}))->show(false);
    /*notebook*/ auto gameC4 = sceneContainer->append(new ImageView(SDLRendererController,
                                                       SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH +
                                                                                     "/img/maingame1/true.png"),
                                                       10, {200, 200}, {875, 325, POSITION_RELATIVE}))->show(false);
    /*tv*/  auto gameC5 = sceneContainer->append(new ImageView(SDLRendererController,
                                                       SDL::loadTexture(SDLRenderer, GAME_PROP.RESOURCE_PATH +
                                                                                     "/img/maingame1/true.png"),
                                                       10, {200, 200}, {1350, 350, POSITION_RELATIVE}))->show(false);
    auto boxOfTime = sceneContainer->append(
            new ImageView(SDLRendererController, box, 2, {300, 100}, {1250, 25, POSITION_RELATIVE}));
    auto textTime = sceneContainer->append(new TextView(SDLRendererController,
                                                        "-",
                                                        {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                         {255, 255, 255}},
                                                        3, {1325, 50, POSITION_ABSOLUTE}));
    auto Answer = sceneContainer->append(new Button(SDLRendererController,
                                                    "เฉลย",
                                                    {50, GAME_PROP.RESOURCE_PATH + "/fonts/PrintAble4U.ttf",
                                                     {255, 255, 255}},
                                                    box,
                                                    [=](Touchable *button, ComponentPosition clickPosition,
                                                        SDL_Event event) mutable {
                                                    },
                                                    50, {400, 100}, {200, 150, POSITION_ABSOLUTE}))->show(false);
    auto boxEnd = sceneContainer->append(new Button(SDLRendererController,
                                                    "Your score = ",
                                                    {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                     {255, 255, 255}},
                                                    box,
                                                    [=](Touchable *button, ComponentPosition clickPosition,
                                                        SDL_Event event) mutable {
                                                    },
                                                    50, {400, 100}, {670, 20, POSITION_ABSOLUTE}));
    auto backToMenu = sceneContainer->append(new Button(SDLRendererController,
                                                        "MENU",
                                                        {50, GAME_PROP.RESOURCE_PATH + "/fonts/Roboto-Regular.ttf",
                                                         {255, 255, 255}},
                                                        box,
                                                        [=](Touchable *button, ComponentPosition clickPosition,
                                                            SDL_Event event) mutable {
                                                            gameScenes->setCurrentSceneName("menu");
                                                        },
                                                        50, {300, 100}, {1250, 775, POSITION_ABSOLUTE}))->show(false);
    auto Q1 = sceneContainer->append(new TouchableImage(SDLRendererController,
                                                        flask,
                                                        [=](Touchable *button, ComponentPosition clickPosition,
                                                            SDL_Event event) {
                                                            *checkA +=1;
                                                            if (*checkA ==1 ){
                                                                (*score)++;
                                                                gameC1->show(true);
                                                            }
                                                        },
                                                        1, {200, 200}, {40, 270, POSITION_ABSOLUTE}))->show(false);
    auto Q2 = sceneContainer->append(new TouchableImage(SDLRendererController,
                                                        iron,
                                                        [=](Touchable *button, ComponentPosition clickPosition,
                                                            SDL_Event event) {
                                                            *checkB +=1;
                                                            if (*checkB ==1 ){
                                                                (*score)++;
                                                                gameC2->show(true);
                                                            }
                                                        },
                                                        1, {400, 400}, {400, 600, POSITION_ABSOLUTE}))->show(false);
    auto Q3 = sceneContainer->append(new TouchableImage(SDLRendererController,
                                                        light,
                                                        [=](Touchable *button, ComponentPosition clickPosition,
                                                            SDL_Event event) {
                                                            *checkC +=1;
                                                            if (*checkC ==1 ){
                                                                (*score)++;
                                                                gameC3->show(true);
                                                            }
                                                        },
                                                        1, {200, 200}, {750, -30, POSITION_ABSOLUTE}))->show(false);
    auto Q4 = sceneContainer->append(new TouchableImage(SDLRendererController,
                                                        notebook,
                                                        [=](Touchable *button, ComponentPosition clickPosition,
                                                            SDL_Event event) {
                                                            *checkD +=1;
                                                            if (*checkD ==1 ){
                                                                (*score)++;
                                                                gameC4->show(true);
                                                            }
                                                        },
                                                        1, {200, 200}, {825, 500, POSITION_ABSOLUTE}))->show(false);
    auto Q5 = sceneContainer->append(new TouchableImage(SDLRendererController,
                                                        tv,
                                                        [=](Touchable *button, ComponentPosition clickPosition,
                                                            SDL_Event event) {
                                                            *checkF +=1;
                                                            if (*checkF ==1 ){
                                                                (*score)++;
                                                                gameC5->show(true);
                                                            }
                                                        },
                                                        1, {400, 400}, {1150, 500, POSITION_ABSOLUTE}))->show(false);
    boxEnd->show(false);

    auto init = [=]() mutable {
        *score = 0;
        textTime->setPosition({1380, 50});
        background->show(true);
        boxEnd->show(false);
        backToMenu->show(false);
        endBg->show(false);
        Answer->show(false);
        Q1->show(true);
        Q2->show(true);
        Q3->show(true);
        Q4->show(true);
        Q5->show(true);
        gameC1->show(false);
        gameC2->show(false);
        gameC3->show(false);
        gameC4->show(false);
        gameC5->show(false);
        keyQ->show(false);
    };
    scene->onEnterScene([=](Scene *scene) mutable {
        init();
        int imgState = 30;
        textTime->changeText(std::to_string(imgState));
        timer->setInterval([=]() mutable {
            textTime->changeText(std::to_string(--imgState));
            if (imgState <= 0 || *score >=5) {
                boxEnd->getTextView()->changeText(std::to_string(*score) + "/5");
                ComponentSize textSize = boxEnd->getTextView()->getSize();
                boxEnd->getTextView()->setPosition({(boxEnd->getSize().width - textSize.width) / 2,
                                                    (boxEnd->getSize().height - textSize.height) / 2});
                textTime->changeText("TIMEUP");
                textTime->setPosition({1320, 45});
                timer->stop();
                boxEnd->show(true);
                backToMenu->show(true);
                keyQ->show(true);
                endBg->show(true);
                Answer->show(true);
                Q1->show(false);
                Q2->show(false);
                Q3->show(false);
                Q4->show(false);
                Q5->show(false);
                gameC1->show(false);
                gameC2->show(false);
                gameC3->show(false);
                gameC4->show(false);
                gameC5->show(false);
                background->show(false);
            }
        }, 1000);
    });
    scene->onExitScene([=](Scene *scene) mutable {
        timer->stop();
    });
}