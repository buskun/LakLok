#include <utility>

#include <utility>

//
// Created by buskun0 on 14/04/19.
//

#ifndef LAKLOK_TOUCHABLE_H
#define LAKLOK_TOUCHABLE_H

#include <functional>
#include <SDL_ttf.h>

#include "base.h"
#include "view.h"
#include "../util/array.h"
#include "../util/timercpp.h"

class Touchable : virtual public Component {
	Timer timer;
protected:
	std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> _touchFunction;

	void click(Touchable *_this, ComponentPosition clickPosition, SDL_Event event) {
		timer.setTimeout([=]( ) {
			_touchFunction(_this, clickPosition, event);
		}, 0);
	}

public:
	Touchable(RendererController &rendererController,
	          function<void(Touchable *, ComponentPosition, SDL_Event)> &touchFunction,
	          int renderIndex = 0, ComponentSize componentSize = { 0, 0 },
	          ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE })
			: Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_VIEW),
			  _touchFunction(touchFunction) {
	}

	void click(ComponentPosition clickPosition, SDL_Event event) override {
		click(this, clickPosition, event);
	}
};

class TouchableText : public Touchable, public TextView {
public:
	TouchableText(RendererController &rendererController,
	              std::string &&text, TextProp &&textProp,
	              std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> &&touchFunction,
	              int renderIndex = 0, ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE }) :
			Touchable(rendererController, touchFunction, renderIndex, { 0, 0 }, componentPosition),
			TextView(rendererController, ( std::string && ) text, ( TextProp && ) textProp,
			         renderIndex, componentPosition),
			Component(rendererController, renderIndex, { 0, 0 }, componentPosition, COMPONENT_TYPE_VIEW) { }
};

class TouchableImage : public Touchable, public ImageView {
public:
	TouchableImage(RendererController &rendererController, SDL_Texture *imageTexture,
	               std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> &&touchFunction,
	               int renderIndex = 0, ComponentSize componentSize = { 0, 0 },
	               ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE }) :
			Touchable(rendererController, touchFunction, renderIndex, componentSize, componentPosition),
			ImageView(rendererController, imageTexture, renderIndex, componentSize, componentPosition),
			Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_VIEW) { }
};

class Button : public Touchable {
	TextView *textView = nullptr;
	ImageView *imageView = nullptr;
public:
	Button(RendererController &rendererController,
	       std::string &&text, TextProp &&textProp,
	       SDL_Texture *backgroundTexture,
	       std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> &&touchFunction,
	       int renderIndex = 0,
	       ComponentSize componentSize = { 0, 0 }, ComponentPosition componentPosition = { 0, 0, POSITION_ABSOLUTE }) :
			Touchable(rendererController, touchFunction, renderIndex, componentSize, componentPosition),
			Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_CONTAINER) {
		imageView = new ImageView(rendererController, backgroundTexture, 0, componentSize, { 0, 0, POSITION_RELATIVE });
		textView = new TextView(rendererController,
		                        ( std::string && ) text, ( TextProp && ) textProp,
		                        1, { 0, 0, POSITION_RELATIVE });
		imageView->setParent(this);
		textView->setParent(this);
		ComponentSize textSize = textView->getSize();
		textView->setPosition(( componentSize.width - textSize.width ) / 2,
		                      ( componentSize.height - textSize.height ) / 2,
		                      POSITION_RELATIVE);
	}

	TextView *getTextView( ) {
		return textView;
	}

	ImageView *getImageView( ) {
		return imageView;
	}

	void render(Renderer *renderer) override {
		imageView->render(renderer);
		textView->render(renderer);
	}

	void click(ComponentPosition clickPosition, SDL_Event event) override {
		Touchable::click(this, clickPosition, event);
	}

	void unHover(ComponentPosition mousePosition, SDL_Event event) override {
		hovered = false;
		imageView->unHover(mousePosition, event);
		textView->unHover(mousePosition, event);
	}

	void hover(ComponentPosition mousePosition, SDL_Event event) override {
		hovered = true;
		imageView->hover(mousePosition, event);
		textView->hover(mousePosition, event);
	}
};

#endif //LAKLOK_TOUCHABLE_H
