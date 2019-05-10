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

	Component *append(Component *child);

	Component *prepend(Component *child);

	Component *insertByRenderIndex(Component *child);

	Array<Component *> *getChildren() override;

	void click(ComponentPosition clickPosition, SDL_Event event) override;

	void unHover(ComponentPosition mousePosition, SDL_Event event) override;

	void hover(ComponentPosition mousePosition, SDL_Event event) override;

	void render(Renderer *renderer) override;
};

#endif //LAKLOK_CONTAINER_H
