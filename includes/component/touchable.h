#ifndef LAKLOK_TOUCHABLE_H
#define LAKLOK_TOUCHABLE_H

#include <functional>
#include <SDL_ttf.h>

#include "base.h"
#include "view.h"
#include "../util/array.h"
#include "../util/timercpp.h"

class Touchable : virtual public Component {
	Timer *timer = nullptr;
protected:
	std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> touchFunction;

	void click(Touchable *touchable, ComponentPosition clickPosition, SDL_Event event);

public:
	Touchable(RendererController *rendererController,
	          std::function<void(Touchable *, ComponentPosition, SDL_Event)> &&touchFunction,
	          int renderIndex = 0, ComponentSize componentSize = { 0, 0 },
	          ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE });

	~Touchable( );

	void click(ComponentPosition clickPosition, SDL_Event event) override;
};

class TouchableText : public Touchable, public TextView {
public:
	TouchableText(RendererController *rendererController,
	              std::string &&text, TextProp &&textProp,
	              std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> &&touchFunction,
	              int renderIndex = 0, ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE });
};

class TouchableImage : public Touchable, public ImageView {
public:
	TouchableImage(RendererController *rendererController, SDL_Texture *imageTexture,
	               std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> &&touchFunction,
	               int renderIndex = 0, ComponentSize componentSize = { 0, 0 },
	               ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE });
};

class Button : public Touchable {
	TextView *textView = nullptr;
	ImageView *imageView = nullptr;
public:
	Button(RendererController *rendererController,
	       std::string &&text, TextProp &&textProp,
	       SDL_Texture *backgroundTexture,
	       std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> &&touchFunction,
	       int renderIndex = 0,
	       ComponentSize componentSize = { 0, 0 }, ComponentPosition componentPosition = { 0, 0, POSITION_ABSOLUTE });

	~Button( );

	TextView *getTextView( );

	ImageView *getImageView( );

	void render(Renderer *renderer) override;

	void click(ComponentPosition clickPosition, SDL_Event event) override;

	void unHover(ComponentPosition mousePosition, SDL_Event event) override;

	void hover(ComponentPosition mousePosition, SDL_Event event) override;
};

#endif //LAKLOK_TOUCHABLE_H