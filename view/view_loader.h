#ifndef LAKLOK_VIEW_LOADER_H
#define LAKLOK_VIEW_LOADER_H

#include <map>
#include <functional>

#include "../includes/type.h"
#include "../includes/renderer.h"
#include "../includes/component/container.h"

class Scene {
	const std::string _sceneName;
	Container *sceneContainer;
	RendererController *_rendererController;
	Array<std::function<void(Container *, RendererController *, Scene *)>> tick;

public:
	Scene(const std::string &&sceneName, RendererController *rendererController) : _sceneName(sceneName),
	                                                                               _rendererController(rendererController) {
		sceneContainer = new Container(_rendererController, 0, { 0, 0 }, { 0, 0, POSITION_ABSOLUTE });
	}

	const std::string getSceneName( ) {
		return _sceneName;
	}

	Scene *addTick(std::function<void(Container *, RendererController *, Scene *)> &&tickFunction) {
		tick.push(tickFunction);
		return this;
	}

	Scene *renderScene(Renderer *renderer) {
		sceneContainer->render(renderer);
		return this;
	}

	Scene *gameTick( ) {
		tick.forEach([=](int index, int id, std::function<void(Container *, RendererController *, Scene *)> &&tickFunction) {
			tickFunction(sceneContainer, _rendererController, this);
		});

		return this;
	}

	Container *getContainer( ) {
		return sceneContainer;
	}
};

class GameScenes {
	std::map<const std::string, Scene *> sceneList;
	std::string currentScene;
	Array<std::string> sceneNameList;
	RendererController *_rendererController;
	EventManager *_eventManager;
	const GameProp _gameProp;
public:
	GameScenes(RendererController *rendererController, EventManager *eventManager, GameProp &gameProp) :
			_rendererController(rendererController), _gameProp(gameProp), _eventManager(eventManager) {
	}

	const std::string getCurrentSceneName( ) {
		return currentScene;
	}

	GameScenes *setCurrentSceneName(std::string &&newSceneName) {
		bool foundKey = false;
		sceneNameList.forEach([&](int index, int id, std::string sceneName) {
			if (sceneName == newSceneName) foundKey = true;
		});
		if (foundKey) currentScene = newSceneName;
		return this;
	}

	GameScenes *addScene(Scene *scene) {
		sceneNameList.push(scene->getSceneName());
		sceneList.insert(std::pair<const std::string, Scene *>(scene->getSceneName(), scene));
		if(currentScene.empty())
			currentScene = scene->getSceneName();
		return this;
	}

	Scene *newScene(const std::string &&sceneName) {
		return new Scene(( const std::string && ) sceneName, _rendererController);
	}

	Scene *getScene(const std::string &&sceneName) {
		return sceneList[sceneName];
	}

	Scene *getCurrentScene( ) {
		return sceneList[currentScene];
	}

	RendererController *getRendererController( ) {
		return _rendererController;
	}

	const GameProp getGameProp( ) {
		return _gameProp;
	}

	EventManager *getEventManager( ) {
		return _eventManager;
	}
};

#endif //LAKLOK_VIEW_LOADER_H
