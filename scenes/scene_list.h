#ifndef LAKLOK_SCENE_LIST_H
#define LAKLOK_SCENE_LIST_H

#include <functional>

#include "../includes/SDL_util.h"
#include "../includes/renderer.h"
#include "../includes/scene.h"
#include "../includes/type.h"
#include "../includes/util/array.h"
#include "../includes/util/timercpp.h"
#include "../includes/component/component_type.h"
#include "../includes/component/view.h"
#include "../includes/component/touchable.h"
#include "../includes/component/container.h"
#include "../includes/Game.h"

void mainMenu(GameScenes *gameScenes, Game *game);
void mainGame1(GameScenes *gameScenes, Game *game);
void mainGame2(GameScenes *gameScenes, Game *game);
void mainGame3(GameScenes *gameScenes, Game *game);
void mainGame4(GameScenes *gameScenes, Game *game);
void introGame1(GameScenes *gameScenes, Game *game);
void introGame3(GameScenes *gameScenes, Game *game);
void introGame4(GameScenes *gameScenes, Game *game);
void introGame2(GameScenes *gameScenes, Game *game);
void mainGame2Shop(GameScenes *gameScenes, Game *game);

#endif //LAKLOK_SCENE_LIST_H
