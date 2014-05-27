#ifndef AVOCADO_SFMLCANVAS_H
#define AVOCADO_SFMLCANVAS_H

#include "avocado-global.h"

#define SFML_STATIC

#include <SFML/Graphics.hpp>

#include "Graphics/Canvas.h"

namespace avo {

/**
 * @addtogroup Graphics
 * @{
 */

/**
 * SFML canvas SPI implementation (SPII). The SPII uses sf::RenderTexture to
 * implement the canvas operations.
 *
 * @ingroup Resources
 * @ingroup SFML
 */
class SfmlCanvas : public Canvas {

public:

	/**
	 * Build a NULL sf::RenderTexture.
	 */
	SfmlCanvas();

	/**
	 * Load an sf::RenderTexture from a filename.
	 */
	SfmlCanvas(const boost::filesystem::path &uri);

	/**
	 * Build an sf::RenderTexture to given width/height specifications.
	 */
	SfmlCanvas(int width, int height);

	/**
	 * Destroy sf::RenderTexture.
	 */
	~SfmlCanvas();

	void display();

	void drawCircle(int x, int y, int radius, int r, int g, int b, double a, GraphicsService::BlendMode blendMode);

	void drawFilledBox(int x, int y, int w, int h, int r, int g, int b, double a, GraphicsService::BlendMode blendMode);

	void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b, double a, GraphicsService::BlendMode blendMode);

	void drawLineBox(int x, int y, int w, int h, int r, int g, int b, double a, GraphicsService::BlendMode blendMode);

	void fill(int r, int g, int b, double a);

	int height() const;

	bool isValid() const { return width() != 0 && height() != 0; }

	unsigned int pixelAt(int x, int y) const;

	void saveToFile(const boost::filesystem::path &filename);

	void setPixelAt(int x, int y, unsigned int pixel);

	int width() const;

	sf::RenderTexture *renderTexture();

	static AbstractFactory<SfmlCanvas> *factory;

private:

	sf::RenderTexture *_renderTexture;

};

/**
 * @ingroup Manufacturing
 * @ingroup Resources
 * @ingroup SFML
 * @ingroup SPI
 */
template <>
class AbstractFactory<SfmlCanvas> : public AbstractFactory<Canvas> {

	virtual ~AbstractFactory<SfmlCanvas>() {}

	SfmlCanvas *create(const boost::filesystem::path &uri) {
		return new SfmlCanvas(uri);
	}

	SfmlCanvas *create(int width, int height) {
		return new SfmlCanvas(width, height);
	}

	SfmlCanvas *create() {
		return new SfmlCanvas();
	}

};

/**
 * @}
 */

}

#endif // AVOCADO_SFMLCANVAS_H
