#ifndef LAKLOK_SCENE_LIST_H
#define LAKLOK_SCENE_LIST_H

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

void mainMenu(GameScenes *gameScenes);
void mainGame1(GameScenes *gameScenes);
void mainGame2(GameScenes *gameScenes);
void mainGame3(GameScenes *gameScenes);
void mainGame4(GameScenes *gameScenes);
void introGame1(GameScenes *gameScenes);
#endif //LAKLOK_SCENE_LIST_H
