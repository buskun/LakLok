#ifndef LAKLOK_CONTAINER_H
#define LAKLOK_CONTAINER_H

#include "../util/array.h"
#include "base.h"

class Container : virtual public Component {
protected:
	Array<Component *> *children = nullptr;
public:
	explicit Container(RendererController *rendererController, int renderIndex = 0,
	                   ComponentSize componentSize = { 0, 0 }, ComponentPosition componentPosition = { 0, 0, POSITION_ABSOLUTE });

	~Container( );

	// TODO re-append and re-prepend
	Container *append(Component *child);

	Container *prepend(Component *child);

	Container *insertByRenderIndex(Component *child);

	Array<Component *> *getChildren( );

	void click(ComponentPosition clickPosition, SDL_Event event) override;

	void unHover(ComponentPosition mousePosition, SDL_Event event) override;

	void hover(ComponentPosition mousePosition, SDL_Event event) override;

	void render(Renderer *renderer) override;
};

#endif //LAKLOK_CONTAINER_H
