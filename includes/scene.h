#ifndef LAKLOK_SCENE_H
#define LAKLOK_SCENE_H

#include <map>
#include <functional>

#include "type.h"
#include "renderer.h"
#include "component/container.h"

class Scene {
	std::string sceneName;
	Container *sceneContainer = nullptr;
	RendererController *rendererController = nullptr;
	Array<std::function<void(Scene *)>> *gameTickCallback = nullptr;
	std::function<void(Scene *)> enterSceneCallback;
	std::function<void(Scene *)> exitSceneCallback;

public:
	Scene(std::string &&sceneName, RendererController *rendererController);

	const std::string &getSceneName();

	Scene *onGameTick(std::function<void(Scene *)> &&callback);

	Scene *onEnterScene(std::function<void(Scene *)> &&callback);

	Scene *onExitScene(std::function<void(Scene *)> &&callback);

	Scene *renderScene(Renderer *renderer);

	Scene *gameTick();

	Scene *enterScene();

	Scene *exitScene();

	Container *getSceneContainer();
};

class GameScenes {
	std::map<std::string, Scene *> sceneList;
	std::string currentScene;
	Array<std::string> *sceneNameList = nullptr;
	RendererController *rendererController = nullptr;
	EventManager *eventManager = nullptr;
	GameProp gameProp = {};
public:
	GameScenes(RendererController *rendererController, EventManager *eventManager, GameProp &&gameProp);

	const std::string &getCurrentSceneName();

	GameScenes *setCurrentSceneName(std::string &&newSceneName);

	GameScenes *addScene(Scene *scene);

	Scene *newScene(std::string &&sceneName);

	Scene *getScene(const std::string &&sceneName);

	Scene *getCurrentScene();

	RendererController *getRendererController();

	const GameProp &getGameProp();

	EventManager *getEventManager();
};

#endif //LAKLOK_SCENE_H
