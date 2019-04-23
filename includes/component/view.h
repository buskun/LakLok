//
// Created by buskun0 on 07/04/19.
//

#ifndef LAKLOK_VIEW_H
#define LAKLOK_VIEW_H

#include <SDL.h>
#include <functional>

#include "../SDL_util.h"
#include "base.h"

class View : virtual public Component {
protected:
	SDL_Texture *sdlTexture = nullptr;
	SDL_Texture *sdlHoverTexture = nullptr;

public:
	explicit View(RendererController &rendererController, int renderIndex = 0,
	              ComponentSize componentSize = { 0, 0 },
	              ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE })
			: Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_VIEW) {
	}

	void render(Renderer *renderer) override {
		ComponentPosition absolutePosition = Component::absolutePosition(this);
		renderTexture(_rendererController.getSDLRenderer(),
		              sdlHoverTexture && hovered ? sdlHoverTexture : sdlTexture,
		              absolutePosition.x, absolutePosition.y, size.width, size.height);
	};

	void hover(ComponentPosition mousePosition, SDL_Event event) override {
		hovered = true;
	}

	void unHover(ComponentPosition mousePosition, SDL_Event event) override {
		hovered = false;
	}
};

class ImageView : public View {
public:
	ImageView(RendererController &rendererController, SDL_Texture *imageTexture, int renderIndex = 0,
	          ComponentSize componentSize = { 0, 0 },
	          ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE })
			: View(rendererController, renderIndex, componentSize, componentPosition),
			  Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_VIEW) {
		sdlTexture = imageTexture;
	}

	ImageView *setHoverImage(SDL_Texture *imageTexture) {
		sdlHoverTexture = imageTexture;
		return this;
	}
};

class TextView : public View {
protected:
	TextProp _textProp = { };
	TextProp _hoverTextProp = { };
	TTF_Font *ttfFont = nullptr;
	TTF_Font *hoverTtfFont = nullptr;
	std::string _text;
	std::string _hoverText;
public:
	TextView(RendererController &rendererController,
	         std::string &&text, TextProp &&textProp,
	         int renderIndex = 0, ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE })
			: View(rendererController, renderIndex, { 0, 0 }, componentPosition),
			  Component(rendererController, renderIndex, { 0, 0 }, componentPosition, COMPONENT_TYPE_VIEW),
			  _text(text), _textProp(textProp) {
		ttfFont = TTF_OpenFont(_textProp.fontName.c_str(), _textProp.fontSize);
		TTF_SizeText(ttfFont, _text.c_str(), &size.width, &size.height);
		sdlTexture = SDL_CreateTextureFromSurface(_rendererController.getSDLRenderer(),
		                                          TTF_RenderText_Solid(ttfFont, _text.c_str(), _textProp.fontColor));
	}

	TextView *changeText(std::string &&text) {
		_text = text;
		TTF_SizeText(ttfFont, _text.c_str(), &size.width, &size.height);
		sdlTexture = SDL_CreateTextureFromSurface(_rendererController.getSDLRenderer(),
		                                          TTF_RenderText_Solid(ttfFont, _text.c_str(), _textProp.fontColor));
		return this;
	}

	TextView *setHoverText(std::string &&text, TextProp &&textProp) {
		_hoverTextProp = textProp;
		_hoverText = text;
		hoverTtfFont = TTF_OpenFont(_hoverTextProp.fontName.c_str(), _hoverTextProp.fontSize);
		sdlHoverTexture = SDL_CreateTextureFromSurface(_rendererController.getSDLRenderer(),
		                                               TTF_RenderText_Solid(hoverTtfFont, _hoverText.c_str(), _hoverTextProp.fontColor));
		return this;
	}

	const std::string getText( ) {
		return _text;
	}
};

#endif //LAKLOK_VIEW_H
