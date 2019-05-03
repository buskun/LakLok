#ifndef NDEBUG
#define DEBUG true
#else
#define DEBUG false
#endif

#include <iostream>
#include <SDL.h>
#include <map>

#include "includes/SDL_util.h"
#include "includes/renderer.h"
#include "includes/util/array.h"
#include "includes/component/container.h"
#include "includes/util/timercpp.h"
#include "includes/scene.h"

#include "scenes/scene_list.h"

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900

int WinMain(int argc, char *argv[]) {
    int errorCode = 0;

    if ((errorCode = SDL_Init(SDL_INIT_EVERYTHING)) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return errorCode;
    }

    if ((errorCode = TTF_Init()) < 0) {
        std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return errorCode;
    }

    GameProp gameProp = {};
    gameProp.NAME = "LakLok";
    gameProp.FPS = 144;
    gameProp.TICK_TIME = 100;
    gameProp.RESOURCE_PATH = (std::string) SDL_GetBasePath() + (DEBUG ? "../resources" : "resources");

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    gameProp.WINDOW.HEIGHT = WINDOW_HEIGHT;
    gameProp.WINDOW.WIDTH = WINDOW_WIDTH;

    gameProp.WINDOW.X = (DM.w - WINDOW_WIDTH) / 2;
    gameProp.WINDOW.Y = (DM.h - WINDOW_HEIGHT) / 2;

    auto SDLRendererController = new RendererController((GameProp &&) gameProp,
                                                        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI,
                                                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    auto *eventManager = new EventManager();

    auto *gameScene = new GameScenes(SDLRendererController, eventManager, (GameProp &&) gameProp);

    // Scenes
    mainMenu(gameScene);
    mainGame1(gameScene);
    mainGame2(gameScene);
    mainGame3(gameScene);
    mainGame4(gameScene);
    eventManager->on(SDL_MOUSEBUTTONDOWN, [&](SDL_Event event) {
        ComponentPosition clickPosition = {0, 0, POSITION_ABSOLUTE};
        SDL_GetMouseState(&clickPosition.x, &clickPosition.y);
        gameScene->getCurrentScene()->getSceneContainer()->click(clickPosition, event);
    });

    Scene *lastHoveredScene = nullptr;

    eventManager->on(SDL_MOUSEMOTION, [&](SDL_Event event) {
        ComponentPosition mousePosition = {0, 0, POSITION_ABSOLUTE};
        SDL_GetMouseState(&mousePosition.x, &mousePosition.y);
        if (lastHoveredScene) {
            lastHoveredScene->getSceneContainer()->unHover(mousePosition, event);
            lastHoveredScene = nullptr;
        }
        gameScene->getCurrentScene()->getSceneContainer()->hover(mousePosition, event);
        lastHoveredScene = gameScene->getCurrentScene();
    });

    SDLRendererController->addRenderer(0, [&](Renderer *renderer) {
        gameScene->getCurrentScene()->renderScene(renderer);
    });

    auto timer = new Timer();
    timer->setInterval([=]() {
        if (gameScene->getCurrentScene()) {
            gameScene->getCurrentScene()->getSceneContainer()->getChildren()->sort(
                    [](Node<Component *> *fNode, Node<Component *> *sNode) {
                        return fNode->getNodeData()->getRenderIndex() <= sNode->getNodeData()->getRenderIndex();
                    });
        }
        SDLRendererController->renderTick();
    }, 1 /*s*/ * (1000 /*ms*/ / 1 /*s*/) * (1 /*s*/ / gameProp.FPS /*frames*/));

    timer->setInterval([&]() {
        eventManager->gameTick();
        gameScene->getCurrentScene()->gameTick();
    }, gameProp.TICK_TIME);

    eventManager->init([](SDL_Event event) {
        switch (event.type) {
            case SDL_QUIT:
                return true;
            case SDL_KEYUP:
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    return true;
            default:
                return false;
        }
    });

    timer->stop();

    return 0;
}