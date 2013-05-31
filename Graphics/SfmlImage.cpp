#include "core/avocado-global.h"

#include "SfmlImage.h"

namespace avo {

AbstractFactory<SfmlImage> *SfmlImage::factory = new AbstractFactory<SfmlImage>;

SfmlImage::SfmlImage()
	: Image()
	, texture(new sf::Texture())
{
}

SfmlImage::SfmlImage(const boost::filesystem::path &uri)
	: Image()
	, texture(new sf::Texture())
{

	if (!texture->loadFromFile(uri.string().c_str())) throw std::runtime_error(
		"SfmlImage::SfmlImage(uri): SFML couldn't load image."
	);

	setUri(uri);
}

SfmlImage::~SfmlImage() {
	if (texture) delete texture;
}

int SfmlImage::height() const {
	return texture->getSize().y;
}

void SfmlImage::render(int x, int y, Canvas *destination, int alpha, DrawMode mode, int sx, int sy, int sw, int sh) const {

	sf::Sprite sprite;
	sprite.setTexture(*texture);
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setColor(sf::Color(255, 255, 255, alpha));
	sf::IntRect rect(sx, sy, sw, sh);
	if (0 == rect.width) {
		rect.width = width();
	}
	if (0 == rect.height) {
		rect.height = height();
	}
	sprite.setTextureRect(rect);

	sf::RenderStates renderStates;
	switch (mode) {
	case DrawMode_Replace:
		renderStates.blendMode = sf::BlendNone;
		break;
	default:
		break;
	}

	Canvas::superCast<SfmlCanvas>(destination)->renderTexture->draw(
		sprite,
		renderStates
	);
}

int SfmlImage::width() const {
	return texture->getSize().x;
}

}
