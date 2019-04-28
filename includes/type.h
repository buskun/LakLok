#ifndef LAKLOK_TYPE_H
#define LAKLOK_TYPE_H

typedef struct {
	int X;
	int Y;
	int WIDTH;
	int HEIGHT;
} ScreenProp;

typedef struct {
	std::string NAME;
	std::string RESOURCE_PATH;
	int FPS;
	int TICK_TIME;
	ScreenProp WINDOW;
} GameProp;

#endif //LAKLOK_TYPE_H
