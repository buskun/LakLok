//
// Created by buskun0 on 23/04/19.
//

#ifndef LAKLOK_TYPE_H
#define LAKLOK_TYPE_H

typedef struct {
	const int WIDTH;
	const int HEIGHT;
} ScreenProp;

typedef struct {
	const std::string RESOURCE_PATH;
	const int FPS;
	const int TICK_TIME;
	const ScreenProp WINDOW;
} GameProp;

#endif //LAKLOK_TYPE_H
