#include "core/avocado-global.h"

#include "SfmlCanvas.h"
#include "SfmlImage.h"
#include "SfmlSprite.h"
#include "SfmlWindow.h"

namespace avo {

SfmlSprite::SfmlSprite()
	: Sprite()
{

}

void SfmlSprite::renderTo(Canvas *destination) const {
	if (NULL == canvas() && NULL == image()) return;

	if (image()) {
		_sprite.setTexture(*Image::superCast<SfmlImage>(image())->texture());
	}
	else if (canvas()) {
		_sprite.setTexture(Canvas::superCast<SfmlCanvas>(canvas())->renderTexture()->getTexture());
	}

	Canvas::superCast<SfmlCanvas>(destination)->renderTexture()->draw(
		_sprite,
		_renderStates
	);
}

void SfmlSprite::renderTo(Window *destination) const {
	if (NULL == canvas() && NULL == image()) return;

	if (image()) {
		_sprite.setTexture(*Image::superCast<SfmlImage>(image())->texture());
	}
	else if (canvas()) {
		_sprite.setTexture(Canvas::superCast<SfmlCanvas>(canvas())->renderTexture()->getTexture());
	}

	SfmlWindow *window = Window::superCast<SfmlWindow>(destination);

	window->window()->clear();
	window->window()->draw(_sprite);
}

void SfmlSprite::setAlpha(double alpha) {
	_sprite.setColor(sf::Color(255, 255, 255, 255.0 * alpha));
}

void SfmlSprite::setBlendMode(GraphicsService::BlendMode blendMode) {

	switch (blendMode) {
	case GraphicsService::BlendMode_Replace:
		_renderStates.blendMode = sf::BlendNone;
		break;
	default:
		break;
	}
}

void SfmlSprite::setPosition(int x, int y) {
	_sprite.setPosition(sf::Vector2f(x, y));
}

void SfmlSprite::setRotation(double angle) {
	_sprite.setRotation(angle);
}

void SfmlSprite::setScale(double factorX, double factorY) {
	_sprite.setScale(factorX, factorY);
}

void SfmlSprite::setSourceRectangle(int x, int y, int w, int h) {

	sf::IntRect rect(x, y, w, h);
	if (0 == rect.width) {
		rect.width = canvas() ? canvas()->width() : image()->width();
	}
	if (0 == rect.height) {
		rect.height = canvas() ? canvas()->height() : image()->height();
	}
	_sprite.setTextureRect(rect);
}

}
