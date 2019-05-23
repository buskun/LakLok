#include "../../includes/component/component_type.h"
#include "../../includes/component/base.h"

Component::Component(RendererController *rendererController, int renderIndex,
                     ComponentSize componentSize, ComponentPosition componentPosition, COMPONENT_TYPE componentType) {
	this->position = componentPosition;
	this->size = componentSize;
	this->componentType = componentType;
	this->renderIndex = renderIndex;
	this->rendererController = rendererController;
	this->hovered = false;
	this->shown = true;
}

RendererController *Component::getRendererController() {
	return this->rendererController;
}

Component *Component::setParent(Component *parent) {
	this->parent = parent;
	return this;
}

Component *Component::setRenderIndex(int renderIndex) {
	this->renderIndex = renderIndex;
	return this;
}

Component *Component::show(bool shown) {
	this->shown = shown;
	return this;
}

Component *Component::getParent() {
	return this->parent;
}

int Component::getRenderIndex() {
	return this->renderIndex;
}

ComponentPosition Component::setPosition(ComponentPosition componentPosition) {
	if (componentPosition.x) this->position.x = componentPosition.x;
	if (componentPosition.y) this->position.y = componentPosition.y;
	if (componentPosition.positionFlag) this->position.positionFlag = componentPosition.positionFlag;
	return this->position;
}

ComponentPosition Component::getPosition() {
	return this->position;
}

ComponentSize Component::setSize(ComponentSize componentSize) {
	if (componentSize.width) this->size.width = componentSize.width;
	if (componentSize.height) this->size.height = componentSize.height;
	return this->size;
}

ComponentSize Component::getSize() {
	return this->size;
}

bool Component::isShown() {
	return this->shown;
}

bool Component::isHovered() {
	return this->hovered;
}

ComponentPosition Component::getAbsolutePosition() {
	if (this->position.positionFlag == POSITION_ABSOLUTE) return this->position;

	if (this->parent) {
		ComponentPosition tempPosition = this->parent->getAbsolutePosition();
		return {this->position.x + tempPosition.x, this->position.y + tempPosition.y, tempPosition.positionFlag};
	}

	return {0, 0, POSITION_ABSOLUTE};
}

Array<Component *> *Component::getChildren() {
	return nullptr;
}
