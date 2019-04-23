//
// Created by buskun0 on 07/04/19.
//

#ifndef LAKLOK_CONTAINER_H
#define LAKLOK_CONTAINER_H

#include "../util/array.h"
#include "base.h"

class Container : virtual public Component {
protected:
	Array<Component *> *_children;
public:
	explicit Container(RendererController rendererController, int renderIndex = 0)
			: Component(rendererController, renderIndex, { 0, 0 }, { 0, 0, POSITION_ABSOLUTE }, COMPONENT_TYPE_CONTAINER),
			  _children(new Array<Component *>) {
	}

	Container *append(Component *child) {
		_children->push(child, child->getRenderIndex());
		child->setParent(this);
		return this;
	}

	Container *prepend(Component *child) {
		_children->unshift(child, child->getRenderIndex());
		child->setParent(this);
		return this;
	}

	Container *insert(Component *child) {
		_children->insert(child, child->getRenderIndex());
		child->setParent(this);
		return this;
	}

	Array<Component *> *children( ) {
		return _children;
	}

	void click(ComponentPosition clickPosition, SDL_Event event) override {
		for (Node<Component *> *currentComponent = _children->getLast(); currentComponent; currentComponent = currentComponent->previousNode()) {
			ComponentPosition pos = Component::absolutePosition(currentComponent->getNodeData());
			ComponentSize size = currentComponent->getNodeData()->getSize();
			if (pos.x < clickPosition.x && clickPosition.x < pos.x + size.width
			    && pos.y < clickPosition.y && clickPosition.y < pos.y + size.height) {
				currentComponent->getNodeData()->click(clickPosition, event);
				break;
			}
		}
	}

	void unHover(ComponentPosition mousePosition, SDL_Event event) override {
		hovered = false;
		_children->forEach([=](int index, int id, Component *child) {
			child->unHover(mousePosition, event);
		});
	}

	void hover(ComponentPosition mousePosition, SDL_Event event) override {
		hovered = true;
		for (Node<Component *> *currentComponent = _children->getLast(); currentComponent; currentComponent = currentComponent->previousNode()) {
			ComponentPosition pos = Component::absolutePosition(currentComponent->getNodeData());
			ComponentSize size = currentComponent->getNodeData()->getSize();
			if (pos.x < mousePosition.x && mousePosition.x < pos.x + size.width
			    && pos.y < mousePosition.y && mousePosition.y < pos.y + size.height) {
				currentComponent->getNodeData()->hover(mousePosition, event);
				break;
			}
		}
	}

	void render(Renderer *renderer) override {
		_children->forEach([renderer](int index, int id, Component *child) {
			child->render(renderer);
		});
	}
};

#endif //LAKLOK_CONTAINER_H
