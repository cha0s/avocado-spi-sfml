#include "avocado-global.h"

#include "SfmlImage.h"

namespace avo {

AbstractFactory<SfmlImage> *SfmlImage::factory = new AbstractFactory<SfmlImage>;

SfmlImage::SfmlImage()
	: Image()
	, _texture(new sf::Texture())
{
}

SfmlImage::SfmlImage(const boost::filesystem::path &uri)
	: Image()
	, _texture(new sf::Texture())
{

	if (!_texture->loadFromFile(uri.string().c_str())) throw std::runtime_error(
		"SfmlImage::SfmlImage(uri): SFML couldn't load image."
	);

	setUri(uri);
}

SfmlImage::~SfmlImage() {
	if (_texture) delete _texture;
}

int SfmlImage::height() const {
	return _texture->getSize().y;
}

int SfmlImage::width() const {
	return _texture->getSize().x;
}

sf::Texture *SfmlImage::texture() const {
	return _texture;
}

}
