//
// Created by buskun0 on 07/04/19.
//

#ifndef LAKLOK_VIEW_LOADER_H
#define LAKLOK_VIEW_LOADER_H

#include <map>
#include <functional>

#include "../includes/type.h"
#include "../includes/renderer.h"
#include "../includes/component/container.h"

class Scene {
	const std::string _sceneName;
public:
	Scene(const std::string &&sceneName): _sceneName(sceneName) {
	}

	const std::string getSceneName( ) {
		return _sceneName;
	}
};

class GameScenes {
	std::map<const std::string, Scene *> sceneList;
	std::string currentScene;
public:
	GameScenes *addScene(Scene *scene) {
		sceneList.insert(std::pair<const std::string, Scene *>(scene->getSceneName(), scene));
		return this;
	}
};

#endif //LAKLOK_VIEW_LOADER_H
