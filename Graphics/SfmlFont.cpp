#include "SfmlFont.h"

namespace avo {

AbstractFactory<Font> *SfmlFont::factory = new AbstractFactory<SfmlFont>;

SfmlFont::SfmlFont()
	: font(new sf::Font())
{
	setSize(12);
}

SfmlFont::SfmlFont(const boost::filesystem::path &uri)
	: font(new sf::Font())
{

	if (!font->loadFromFile(uri.string().c_str())) throw std::runtime_error(
		"sf::Font::loadFromFile(uri) failed."
	);
	
	setSize(12);
}

SfmlFont::~SfmlFont() {

	// Bug?
//	delete font;
}

void SfmlFont::render(int x, int y, const std::string &text, Canvas *destination, int r, int g, int b, double a) const {

	sf::Text sfmlText = sf::Text(text, *font, size);
	sfmlText.setColor(sf::Color(r, g, b, a * 255.0));
	sfmlText.setPosition(sf::Vector2f(x, y));

	Canvas::superCast<SfmlCanvas>(destination)->renderTexture()->draw(
		sfmlText
	);
}

void SfmlFont::setSize(int size) {
	this->size = size;
}

void SfmlFont::setStyle(FontStyle style) {

	sfmlStyle = sf::Text::Regular;

	if (FontStyle_Bold & style) {
		sfmlStyle = static_cast<sf::Text::Style>(sfmlStyle | sf::Text::Bold);
	}
	if (FontStyle_Italic & style) {
		sfmlStyle = static_cast<sf::Text::Style>(sfmlStyle | sf::Text::Italic);
	}
	if (FontStyle_Underline & style) {
		sfmlStyle = static_cast<sf::Text::Style>(sfmlStyle | sf::Text::Underlined);
	}
}

int SfmlFont::textHeight(const std::string &text) {
	sf::Text sfmlText = sf::Text(text, *font, size);
	return sfmlText.getGlobalBounds().height * 2;
}

int SfmlFont::textWidth(const std::string &text) {
	sf::Text sfmlText = sf::Text(text, *font, size);
	return sfmlText.getGlobalBounds().width;
}

}
