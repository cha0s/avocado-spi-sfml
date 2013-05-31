#ifndef AVOCADO_SFMLCANVAS_H
#define AVOCADO_SFMLCANVAS_H

#include "core/avocado-global.h"

#define SFML_STATIC

#include <SFML/Graphics.hpp>

#include "core/Graphics/Canvas.h"

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

	friend class SfmlImage;
	friend class SfmlFont;
	friend class SfmlWindow;

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

	void drawCircle(int x, int y, int radius, int r, int g, int b, int a = 255, DrawMode drawMode = DrawMode_Blend);

	void drawFilledBox(int x, int y, int w, int h, int r, int g, int b, int a = 255, DrawMode drawMode = DrawMode_Blend);

	void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b, int a = 255, DrawMode drawMode = DrawMode_Blend);

	void drawLineBox(int x, int y, int w, int h, int r, int g, int b, int a = 255, DrawMode drawMode = DrawMode_Blend);

	void fill(int r, int g, int b, int a = 255);

	int height() const;

	bool isValid() const { return width() != 0 && height() != 0; }

	unsigned int pixelAt(int x, int y) const;

	void render(int x, int y, Canvas *destination, int alpha = 255, DrawMode mode = DrawMode_Blend, int sx = 0, int sy = 0, int sw = 0, int sh = 0) const AVOCADO_ENSURE_STACK_ALIGNED_FOR_SSE;

	void saveToFile(const boost::filesystem::path &filename);

	void setPixelAt(int x, int y, unsigned int pixel);

	int width() const;

	static AbstractFactory<SfmlCanvas> *factory;

private:

	sf::RenderTexture *renderTexture;

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
