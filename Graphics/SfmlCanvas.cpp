#include "core/avocado-global.h"

#include "SfmlCanvas.h"

namespace avo {

AbstractFactory<SfmlCanvas> *SfmlCanvas::factory = new AbstractFactory<SfmlCanvas>;

SfmlCanvas::SfmlCanvas()
	: Canvas()
	, _renderTexture(new sf::RenderTexture())
{
}

SfmlCanvas::SfmlCanvas(int width, int height)
	: Canvas()
	, _renderTexture(new sf::RenderTexture())
{
	if (!_renderTexture->create(width, height)) throw std::runtime_error(
		"sf::RenderTexture::create(width, height) failed."
	);
	_renderTexture->clear(sf::Color(0, 0, 0, 0));
	_renderTexture->display();
}

SfmlCanvas::SfmlCanvas(const boost::filesystem::path &uri)
	: Canvas()
	, _renderTexture(new sf::RenderTexture())
{

	sf::Texture texture;
	if (!texture.loadFromFile(uri.string().c_str())) throw std::runtime_error(
		"SfmlCanvas::SfmlCanvas(uri): loading failed."
	);
	sf::Vector2u vector = texture.getSize();
	_renderTexture->create(vector.x, vector.y);
	_renderTexture->clear();
	_renderTexture->draw(
		sf::Sprite(texture),
		sf::RenderStates(sf::BlendNone)
	);
	_renderTexture->display();

	setUri(uri);
}

SfmlCanvas::~SfmlCanvas() {
	if (_renderTexture) delete _renderTexture;
}

void SfmlCanvas::display() {
	_renderTexture->display();
}

unsigned int SfmlCanvas::pixelAt(int x, int y) const {
	AVOCADO_UNUSED(x);
	AVOCADO_UNUSED(y);

	return 0;
}

void SfmlCanvas::drawCircle(int x, int y, int radius, int r, int g, int b, double a, GraphicsService::BlendMode blendMode) {

	sf::CircleShape circle;
	circle.setRadius(radius);
	circle.setPointCount(30);
	circle.setFillColor(sf::Color(r, g, b, a * 255.0));
	circle.setOutlineColor(sf::Color(r, g, b, a * 255.0));
	circle.setOutlineThickness(1);
	circle.setPosition(x - radius, y - radius);

	_renderTexture->draw(
		circle,
		sf::RenderStates(
			GraphicsService::BlendMode_Blend == blendMode ?
				sf::BlendAlpha
			:
				sf::BlendNone
		)
	);
}

void SfmlCanvas::drawFilledBox(int x, int y, int w, int h, int r, int g, int b, double a, GraphicsService::BlendMode blendMode) {

	sf::RectangleShape box;
	box.setSize(sf::Vector2f(w, h));
	box.setOutlineColor(sf::Color(r, g, b, a * 255.0));
	box.setFillColor(sf::Color(r, g, b, a * 255.0));
	box.setPosition(x, y);
	_renderTexture->draw(
		box,
		sf::RenderStates(
			GraphicsService::BlendMode_Blend == blendMode ?
				sf::BlendAlpha
			:
				sf::BlendNone
		)
	);
}

void SfmlCanvas::drawLine(int x1, int y1, int x2, int y2, int r, int g, int b, double a, GraphicsService::BlendMode blendMode) {
	AVOCADO_UNUSED(blendMode);

	sf::VertexArray lines(sf::LinesStrip, 2);
	lines[0].position = sf::Vector2f(x1, y1);
	lines[0].color = sf::Color(r, g, b, a * 255.0);
	lines[1].position = sf::Vector2f(x2, y2);
	lines[1].color = sf::Color(r, g, b, a * 255.0);

	_renderTexture->draw(lines);
}

void SfmlCanvas::drawLineBox(int x, int y, int w, int h, int r, int g, int b, double a, GraphicsService::BlendMode blendMode) {
	AVOCADO_UNUSED(blendMode);

	sf::RectangleShape box;
	box.setSize(sf::Vector2f(w, h));
	box.setOutlineColor(sf::Color(r, g, b, a * 255.0));
	box.setOutlineThickness(1);
	box.setFillColor(sf::Color(0, 0, 0, 0));
	box.setPosition(x, y);
	_renderTexture->draw(box);
}

void SfmlCanvas::fill(int r, int g, int b, double a) {
	if (0 == a) {
		_renderTexture->clear(sf::Color(r, g, b, 0));
	}
	else {
		drawFilledBox(0, 0, width(), height(), r, g, b, a, GraphicsService::BlendMode_Blend);
	}
}

int SfmlCanvas::height() const {
	return _renderTexture->getSize().y;
}

void SfmlCanvas::saveToFile(const boost::filesystem::path &filename) {
	_renderTexture->getTexture().copyToImage().saveToFile(filename.string());
}

void SfmlCanvas::setPixelAt(int x, int y, unsigned int pixel) {
	AVOCADO_UNUSED(x);
	AVOCADO_UNUSED(y);
	AVOCADO_UNUSED(pixel);
}

int SfmlCanvas::width() const {
	return _renderTexture->getSize().x;
}

sf::RenderTexture *SfmlCanvas::renderTexture() {
	return _renderTexture;
}

}
