#include "../includes/scene.h"

Scene::Scene(std::string &&sceneName, RendererController *rendererController) {
	this->sceneName = sceneName;
	this->rendererController = rendererController;
	this->sceneContainer = new Container(this->rendererController, 0, {0, 0}, {0, 0, POSITION_ABSOLUTE});
	this->gameTickCallback = new Array<std::function<void(Scene *)>>();
}

const std::string &Scene::getSceneName() {
	return this->sceneName;
}

Scene *Scene::onGameTick(std::function<void(Scene *)> &&callback) {
	this->gameTickCallback->push(callback);
	return this;
}

Scene *Scene::onEnterScene(std::function<void(Scene *)> &&callback) {
	this->enterSceneCallback = callback;
	return this;
}

Scene* Scene::onExitScene(std::function<void(Scene *)> &&callback) {
    this->enterSceneCallback = callback;
    return this;
}

Scene *Scene::renderScene(Renderer *renderer) {
	this->sceneContainer->render(renderer);
	return this;
}

Scene *Scene::gameTick() {
	this->gameTickCallback->forEach([&](int index, int id, std::function<void(Scene *)> &&callback) {
		callback(this);
	});

	return this;
}

Scene *Scene::enterScene() {
	enterSceneCallback(this);
	return this;
}

Scene* Scene::exitScene() {
    exitSceneCallback(this);
    return this;
}

Container *Scene::getSceneContainer() {
	return this->sceneContainer;
}

GameScenes::GameScenes(RendererController *rendererController, EventManager *eventManager, GameProp &&gameProp) {
	this->rendererController = rendererController;
	this->gameProp = gameProp;
	this->eventManager = eventManager;
	this->sceneNameList = new Array<std::string>();
}

const std::string &GameScenes::getCurrentSceneName() {
	return this->currentScene;
}

GameScenes *GameScenes::setCurrentSceneName(std::string &&newSceneName) {
	bool foundKey = false;
	this->sceneNameList->forEach([&](int index, int id, std::string sceneName) {
		if (sceneName == newSceneName) foundKey = true;
	});
	if (foundKey) {
	    this->sceneList[this->currentScene]->exitScene();
		this->currentScene = newSceneName;
		this->sceneList[this->currentScene]->enterScene();
	}
	return this;
}

GameScenes *GameScenes::addScene(Scene *scene) {
	this->sceneNameList->push(scene->getSceneName());
	this->sceneList.insert(std::pair<std::string, Scene *>(scene->getSceneName(), scene));
	if (this->currentScene.empty()) this->currentScene = scene->getSceneName();
	return this;
}

Scene *GameScenes::newScene(std::string &&sceneName) {
	return this
			->addScene(new Scene((std::string &&) sceneName, this->rendererController))
			->getScene((const std::string) sceneName);
}

Scene *GameScenes::getScene(const std::string &&sceneName) {
	return this->sceneList[sceneName];
}

Scene *GameScenes::getCurrentScene() {
	return this->sceneList[this->currentScene];
}

RendererController *GameScenes::getRendererController() {
	return this->rendererController;
}

const GameProp &GameScenes::getGameProp() {
	return this->gameProp;
}

EventManager *GameScenes::getEventManager() {
	return this->eventManager;
}
