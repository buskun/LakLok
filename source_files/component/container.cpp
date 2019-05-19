#include "../../includes/component/component_type.h"

#include "../../includes/component/container.h"

Container::Container(RendererController *rendererController, int renderIndex, ComponentSize componentSize,
                     ComponentPosition componentPosition)
		: Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_CONTAINER) {
	this->children = new Array<Component *>;
}

Container::~Container() {
	delete this->children;
}

Array<Component *> *Container::getChildren() {
	return this->children;
}

void Container::click(ComponentPosition clickPosition, SDL_Event event) {
	for (Node<Component *> *currentComponent = this->children->getLastNode(); currentComponent;
	     currentComponent = *currentComponent - 1) {
		ComponentPosition absolutePosition = currentComponent->getNodeData()->getAbsolutePosition();
		ComponentSize size = currentComponent->getNodeData()->getSize();

		if (absolutePosition.x <= clickPosition.x && clickPosition.x <= absolutePosition.x + size.width
		    && absolutePosition.y <= clickPosition.y && clickPosition.y <= absolutePosition.y + size.height
		    && currentComponent->getNodeData()->isShown()) {
			currentComponent->getNodeData()->click(clickPosition, event);
			break;
		}

	}
}

void Container::unHover(ComponentPosition mousePosition, SDL_Event event) {
	this->hovered = false;
	this->children->forEach([&](int index, int id, Component *child) {
		child->unHover(mousePosition, event);
	});
}

void Container::hover(ComponentPosition mousePosition, SDL_Event event) {
	if (!this->shown) return;
	this->hovered = true;
	for (Node<Component *> *currentComponent = this->children->getLastNode(); currentComponent; currentComponent =
			                                                                                            *currentComponent -
			                                                                                            1) {
		ComponentPosition pos = currentComponent->getNodeData()->getAbsolutePosition();
		ComponentSize size = currentComponent->getNodeData()->getSize();
		if (pos.x < mousePosition.x && mousePosition.x < pos.x + size.width
		    && pos.y < mousePosition.y && mousePosition.y < pos.y + size.height) {
			currentComponent->getNodeData()->hover(mousePosition, event);
			break;
		}
	}
}

void Container::render(Renderer *renderer) {
	if (!this->shown) return;
	children->forEach([&](int index, int id, Component *child) {
		child->render(renderer);
	});
}