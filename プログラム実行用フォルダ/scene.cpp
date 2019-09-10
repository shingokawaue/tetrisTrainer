#include "scene.h"

//change scene
void Scene::changeScene(int _scene) {
	currentScene = _scene;
	for (size_t i = 0; i < dmenu.size(); i++) {
		if (dmenu[i]->getScene() == currentScene) {
			dmenuIndex = i;
			break;
		}
	}
}
