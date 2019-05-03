#include "../../includes/component/component_type.h"

#include "../../includes/component/touchable.h"

void Touchable::click(Touchable *touchable, ComponentPosition clickPosition, SDL_Event event) {
    this->timer->setTimeout([=]() {
        this->touchFunction(touchable, clickPosition, event);
    }, 0);
}

Touchable::Touchable(RendererController *rendererController,
                     std::function<void(Touchable *, ComponentPosition, SDL_Event)> &&touchFunction, int renderIndex,
                     ComponentSize componentSize, ComponentPosition componentPosition)
        : Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_VIEW) {
    this->timer = new Timer();
    this->touchFunction = touchFunction;
}

Touchable::~Touchable() {
    delete timer;
}

void Touchable::click(ComponentPosition clickPosition, SDL_Event event) {
    this->click(this, clickPosition, event);
}

TouchableText::TouchableText(RendererController *rendererController,
                             std::string &&text, TextProp &&textProp,
                             std::function<void(Touchable *, ComponentPosition clickPosition,
                                                SDL_Event event)> &&touchFunction,
                             int renderIndex, ComponentPosition componentPosition)
        : Touchable(rendererController, std::move(touchFunction), renderIndex, {0, 0}, componentPosition),
          TextView(rendererController, std::move(text), (TextProp &&) textProp, renderIndex, componentPosition),
          Component(rendererController, renderIndex, {0, 0}, componentPosition, COMPONENT_TYPE_VIEW) {}

TouchableImage::TouchableImage(RendererController *rendererController,
                               SDL_Texture *imageTexture,
                               std::function<void(Touchable *, ComponentPosition clickPosition,
                                                  SDL_Event event)> &&touchFunction,
                               int renderIndex, ComponentSize componentSize, ComponentPosition componentPosition)
        : Touchable(rendererController, std::move(touchFunction), renderIndex, componentSize, componentPosition),
          ImageView(rendererController, imageTexture, renderIndex, componentSize, componentPosition),
          Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_VIEW) {}

Button::Button(RendererController *rendererController,
               std::string &&text, TextProp &&textProp, SDL_Texture *backgroundTexture,
               std::function<void(Touchable *, ComponentPosition clickPosition, SDL_Event event)> &&touchFunction,
               int renderIndex, ComponentSize componentSize, ComponentPosition componentPosition)
        : Touchable(rendererController, std::move(touchFunction), renderIndex, componentSize, componentPosition),
          Component(rendererController, renderIndex, componentSize, componentPosition, COMPONENT_TYPE_CONTAINER) {

    this->imageView = new ImageView(rendererController, backgroundTexture, 0, componentSize, {0, 0, POSITION_RELATIVE});
    this->textView = new TextView(rendererController, (std::string &&) text, (TextProp &&) textProp, 1,
                                  {0, 0, POSITION_RELATIVE});

    this->imageView->setParent(this);
    this->textView->setParent(this);

    ComponentSize textSize = textView->getSize();
    this->textView->setPosition({(this->size.width - textSize.width) / 2,
                                 (this->size.height - textSize.height) / 2});
}

Button::~Button() {
    delete textView;
    delete imageView;
}

TextView *Button::getTextView() {
    return this->textView;
}

ImageView *Button::getImageView() {
    return this->imageView;
}

void Button::render(Renderer *renderer) {
    if (!this->shown) return;
    this->imageView->render(renderer);
    this->textView->render(renderer);
}

void Button::click(ComponentPosition clickPosition, SDL_Event event) {
    Touchable::click(this, clickPosition, event);
}

void Button::unHover(ComponentPosition mousePosition, SDL_Event event) {
    this->hovered = false;
    this->imageView->unHover(mousePosition, event);
    this->textView->unHover(mousePosition, event);
}

void Button::hover(ComponentPosition mousePosition, SDL_Event event) {
    this->hovered = true;
    this->imageView->hover(mousePosition, event);
    this->textView->hover(mousePosition, event);
}
