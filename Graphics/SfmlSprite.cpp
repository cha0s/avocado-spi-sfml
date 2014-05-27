#include "avocado-global.h"

#include "SfmlCanvas.h"
#include "SfmlImage.h"
#include "SfmlSprite.h"
#include "SfmlWindow.h"

namespace avo {

AbstractFactory<SfmlSprite> *SfmlSprite::factory = new AbstractFactory<SfmlSprite>;

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

	sf::Vector2f origin = _sprite.getOrigin();
	sf::Vector2f position = _sprite.getPosition();

	if (_rotationOrientation != sf::Vector2f(0, 0)) {
		_sprite.setOrigin(_rotationOrientation);
		_sprite.move(_rotationOrientation);
	}
	
	SfmlCanvas *destinationCanvas = Canvas::superCast<SfmlCanvas>(destination);

	destinationCanvas->renderTexture()->draw(
		_sprite,
		_renderStates
	);

	destinationCanvas->renderTexture()->display();

	_sprite.setOrigin(origin);
	_sprite.setPosition(position);
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

	sf::Vector2f origin = _sprite.getOrigin();
	sf::Vector2f position = _sprite.getPosition();

	if (_rotationOrientation != sf::Vector2f(0, 0)) {
		_sprite.setOrigin(_rotationOrientation);
		_sprite.move(_rotationOrientation);
	}

	window->window()->draw(_sprite);

	_sprite.setOrigin(origin);
	_sprite.setPosition(position);

	window->window()->display();
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

void SfmlSprite::setRotation(double angle, int orientX, int orientY) {
	_sprite.setRotation(angle);
	_rotationOrientation = sf::Vector2f(orientX, orientY);
}

void SfmlSprite::setScale(double factorX, double factorY) {
	_sprite.setScale(factorX, factorY);
}

void SfmlSprite::setSourceRectangle(int x, int y, int w, int h) {

	sf::IntRect rect(x, y, w, h);
	if (0 == rect.width) {
		rect.width = canvas() ? canvas()->width() : (image() ? image()->width() : 0);
	}
	if (0 == rect.height) {
		rect.height = canvas() ? canvas()->height() : (image() ? image()->height() : 0);
	}
	_sprite.setTextureRect(rect);
}

}
