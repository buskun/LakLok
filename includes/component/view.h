#ifndef LAKLOK_VIEW_H
#define LAKLOK_VIEW_H

#include <SDL.h>
#include <functional>

#include "../SDL_util.h"
#include "base.h"

class View : virtual public Component {
protected:
	SDL_Texture *texture = nullptr;
	SDL_Texture *hoverTexture = nullptr;

public:
	explicit View(RendererController *rendererController, int renderIndex = 0,
	              ComponentSize componentSize = { 0, 0 },
	              ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE });

	~View( );

	void render(Renderer *renderer) override;

	void hover(ComponentPosition mousePosition, SDL_Event event) override;

	void unHover(ComponentPosition mousePosition, SDL_Event event) override;
};

class ImageView : public View {
public:
	ImageView(RendererController *rendererController, SDL_Texture *imageTexture, int renderIndex = 0,
	          ComponentSize componentSize = { 0, 0 },
	          ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE });

	ImageView *setHoverImage(SDL_Texture *imageTexture);
};

class TextView : public View {
protected:
	TextProp textProp = { };
	TextProp hoverTextProp = { };
	TTF_Font *font = nullptr;
	TTF_Font *hoverFont = nullptr;
	std::string text;
	std::string hoverText;
public:
	TextView(RendererController *rendererController,
	         std::string &&text, TextProp &&textProp,
	         int renderIndex = 0, ComponentPosition componentPosition = { 0, 0, POSITION_RELATIVE });

	~TextView( );

	TextView *changeText(std::string &&text);

	TextView *setHoverText(std::string &&hoverText, TextProp &&hoverTextProp);

	const std::string &getText( );
};

#endif //LAKLOK_VIEW_H
