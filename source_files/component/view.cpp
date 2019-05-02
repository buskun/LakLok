#include "../../includes/component/component_type.h"

#include "../../includes/component/view.h"

View::View(RendererController *rendererController, int renderIndex, ComponentSize componentSize,
           ComponentPosition componentPosition)
        : Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_VIEW) {
}

View::~View() {
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(hoverTexture);
}

void View::render(Renderer *renderer) {
    if (!this->shown) return;

    ComponentPosition absolutePosition = this->getAbsolutePosition();

    SDL::renderTexture(this->rendererController->getSDLRenderer(),
                       this->hoverTexture && this->hovered ? this->hoverTexture : this->texture,
                       absolutePosition.x, absolutePosition.y, this->size.width, this->size.height);
}

void View::hover(ComponentPosition mousePosition, SDL_Event event) {
    this->hovered = true;
}

void View::unHover(ComponentPosition mousePosition, SDL_Event event) {
    this->hovered = false;
}

ImageView::ImageView(RendererController *rendererController,
                     SDL_Texture *imageTexture,
                     int renderIndex, ComponentSize componentSize, ComponentPosition componentPosition)
        : View(rendererController, renderIndex, componentSize, componentPosition),
          Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_VIEW) {
    this->texture = imageTexture;
}

ImageView *ImageView::setHoverImage(SDL_Texture *imageTexture) {
    this->hoverTexture = imageTexture;
    return this;
}

TextView::TextView(RendererController *rendererController,
                   std::string &&text, TextProp &&textProp,
                   int renderIndex, ComponentPosition componentPosition)
        : View(rendererController, renderIndex, {0, 0}, componentPosition),
          Component(rendererController, renderIndex, {0, 0}, componentPosition, COMPONENT_TYPE_VIEW) {
    this->text = text;
    this->textProp = textProp;
    this->font = TTF_OpenFont(this->textProp.fontName.c_str(), this->textProp.fontSize);

    TTF_SizeText(this->font, this->text.c_str(),
                 &this->size.width, &this->size.height);

    this->texture = SDL_CreateTextureFromSurface(this->rendererController->getSDLRenderer(),
                                                 TTF_RenderText_Solid(this->font, this->text.c_str(),
                                                                      this->textProp.fontColor));
}

TextView::~TextView() {
    TTF_CloseFont(font);
    TTF_CloseFont(hoverFont);
}

TextView *TextView::changeText(std::string &&newText) {
    this->text = newText;

    TTF_SizeText(this->font, this->text.c_str(),
                 &this->size.width, &this->size.height);

    this->texture = SDL_CreateTextureFromSurface(this->rendererController->getSDLRenderer(),
                                                 TTF_RenderText_Solid(this->font, this->text.c_str(),
                                                                      this->textProp.fontColor));
    return this;
}

TextView *TextView::setHoverText(std::string &&hoverText, TextProp &&hoverTextProp) {
    this->hoverTextProp = hoverTextProp;
    this->hoverText = hoverText;

    this->hoverFont = TTF_OpenFont(this->hoverTextProp.fontName.c_str(), this->hoverTextProp.fontSize);

    this->hoverTexture = SDL_CreateTextureFromSurface(this->rendererController->getSDLRenderer(),
                                                      TTF_RenderText_Solid(this->hoverFont, this->hoverText.c_str(),
                                                                           this->hoverTextProp.fontColor));
    return this;
}

const std::string &TextView::getText() {
    return this->text;
}