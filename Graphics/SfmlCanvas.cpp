#include "core/avocado-global.h"

#include "SfmlCanvas.h"

namespace avo {

AbstractFactory<SfmlCanvas> *SfmlCanvas::factory = new AbstractFactory<SfmlCanvas>;

SfmlCanvas::SfmlCanvas()
	: Canvas()
	, renderTexture(new sf::RenderTexture())
{
}

SfmlCanvas::SfmlCanvas(int width, int height)
	: Canvas()
	, renderTexture(new sf::RenderTexture())
{
	if (!renderTexture->create(width, height)) throw std::runtime_error(
		"sf::RenderTexture::create(width, height) failed."
	);
	renderTexture->clear(sf::Color(0, 0, 0, 0));
	renderTexture->display();
}

SfmlCanvas::SfmlCanvas(const boost::filesystem::path &uri)
	: Canvas()
	, renderTexture(new sf::RenderTexture())
{

	sf::Texture texture;
	if (!texture.loadFromFile(uri.string().c_str())) throw std::runtime_error(
		"SfmlCanvas::SfmlCanvas(uri): loading failed."
	);
	sf::Vector2u vector = texture.getSize();
	renderTexture->create(vector.x, vector.y);
	renderTexture->clear();
	renderTexture->draw(
		sf::Sprite(texture),
		sf::RenderStates(sf::BlendNone)
	);
	renderTexture->display();

	setUri(uri);
}

SfmlCanvas::~SfmlCanvas() {
	if (renderTexture) delete renderTexture;
}

void SfmlCanvas::display() {
	renderTexture->display();
}

unsigned int SfmlCanvas::pixelAt(int x, int y) const {
	AVOCADO_UNUSED(x);
	AVOCADO_UNUSED(y);

	return 0;
}

void SfmlCanvas::drawCircle(int x, int y, int radius, int r, int g, int b, int a, DrawMode drawMode) {
	AVOCADO_UNUSED(drawMode);

	sf::CircleShape circle;
	circle.setRadius(radius);
	circle.setPointCount(60);
	circle.setFillColor(sf::Color(r, g, b, a));
	circle.setOutlineColor(sf::Color(r, g, b, a));
	circle.setOutlineThickness(1);
	circle.setPosition(x - radius, y - radius);

	renderTexture->draw(
		circle,
		sf::RenderStates(
			DrawMode_Blend == drawMode ?
				sf::BlendAlpha
			:
				sf::BlendNone
			)
	);
}

void SfmlCanvas::drawFilledBox(int x, int y, int w, int h, int r, int g, int b, int a, DrawMode drawMode) {
	AVOCADO_UNUSED(drawMode);

	sf::RectangleShape box;
	box.setSize(sf::Vector2f(w, h));
	box.setOutlineColor(sf::Color(r, g, b, a));
	box.setFillColor(sf::Color(r, g, b, a));
	box.setPosition(x, y);
	renderTexture->draw(box);
}

void SfmlCanvas::drawLine(int x1, int y1, int x2, int y2, int r, int g, int b, int a, DrawMode drawMode) {
	AVOCADO_UNUSED(drawMode);

	sf::VertexArray lines(sf::LinesStrip, 2);
	lines[0].position = sf::Vector2f(x1, y1);
	lines[0].color = sf::Color(r, g, b, a);
	lines[1].position = sf::Vector2f(x2, y2);
	lines[1].color = sf::Color(r, g, b, a);

	renderTexture->draw(lines);
}

void SfmlCanvas::drawLineBox(int x, int y, int w, int h, int r, int g, int b, int a, DrawMode drawMode) {
	AVOCADO_UNUSED(drawMode);

	sf::RectangleShape box;
	box.setSize(sf::Vector2f(w, h));
	box.setOutlineColor(sf::Color(r, g, b, a));
	box.setOutlineThickness(1);
	box.setFillColor(sf::Color(0, 0, 0, 0));
	box.setPosition(x, y);
	renderTexture->draw(box);
}

void SfmlCanvas::fill(int r, int g, int b, int a) {
	drawFilledBox(0, 0, width(), height(), r, g, b, a);
}

int SfmlCanvas::height() const {
	return renderTexture->getSize().y;
}

void SfmlCanvas::render(int x, int y, Canvas *destination, int alpha, DrawMode mode, int sx, int sy, int sw, int sh) const {

	sf::Sprite sprite;
	sprite.setTexture(renderTexture->getTexture());
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

	superCast<SfmlCanvas>(destination)->renderTexture->draw(
		sprite,
		renderStates
	);
}

void SfmlCanvas::saveToFile(const boost::filesystem::path &filename) {
	renderTexture->getTexture().copyToImage().saveToFile(filename.string());
}

void SfmlCanvas::setPixelAt(int x, int y, unsigned int pixel) {
	AVOCADO_UNUSED(x);
	AVOCADO_UNUSED(y);
	AVOCADO_UNUSED(pixel);
}

int SfmlCanvas::width() const {
	return renderTexture->getSize().x;
}

}
