#ifndef LAKLOK_CONTAINER_H
#define LAKLOK_CONTAINER_H

#include "../util/array.h"
#include "base.h"

class Container : virtual public Component {
protected:
	Array<Component *> *children = nullptr;
public:
	explicit Container(RendererController *rendererController, int renderIndex = 0,
	                   ComponentSize componentSize = {0, 0},
	                   ComponentPosition componentPosition = {0, 0, POSITION_ABSOLUTE});

	~Container();

	template<typename ComponentType>
	ComponentType *append(ComponentType *child){
		if (child->getParent()) {
			child->getParent()->getChildren()->removeByValue(child);
		}
		this->children->push(child, child->getRenderIndex());
		child->setParent(this);
		return child;
	}

	template<typename ComponentType>
	ComponentType *prepend(ComponentType *child){
		if (child->getParent()) {
			child->getParent()->getChildren()->removeByValue(child);
		}
		this->children->unshift(child, child->getRenderIndex());
		child->setParent(this);
		return child;
	}

	template<typename ComponentType>
	ComponentType *insertByRenderIndex(ComponentType *child) {
		if (child->getParent()) {
			child->getParent()->getChildren()->removeByValue(child);
		}
		this->children->insert(child, child->getRenderIndex());
		child->setParent(this);
		return child;
	}

	Array<Component *> *getChildren() override;

	void click(ComponentPosition clickPosition, SDL_Event event) override;

	void unHover(ComponentPosition mousePosition, SDL_Event event) override;

	void hover(ComponentPosition mousePosition, SDL_Event event) override;

	void render(Renderer *renderer) override;
};

#endif //LAKLOK_CONTAINER_H
