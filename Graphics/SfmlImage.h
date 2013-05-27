#ifndef AVOCADO_SFMLIMAGE_H
#define AVOCADO_SFMLIMAGE_H

#include "core/avocado-global.h"

#include <SFML/Graphics.hpp>

#include "core/Graphics/Image.h"

#include "SfmlCanvas.h"

namespace avo {

/**
 * @addtogroup Graphics
 * @{
 */

/**
 * SFML image SPI implementation (SPII). The SPII uses sf::RenderTexture to
 * implement the image operations.
 *
 * @ingroup Resources
 * @ingroup SFML
 */
class SfmlImage : public Image {

public:

	friend class SfmlFont;
	friend class SfmlWindow;

	/**
	 * Build a NULL sf::RenderTexture.
	 */
	SfmlImage();

	/**
	 * Load an sf::RenderTexture from a filename.
	 */
	SfmlImage(const boost::filesystem::path &uri);

	/**
	 * Destroy sf::RenderTexture.
	 */
	~SfmlImage();

	void display();

	int height() const;

	bool isValid() const { return width() != 0 && height() != 0; }

	void render(int x, int y, Canvas *destination, int alpha = 255, DrawMode mode = DrawMode_Blend, int sx = 0, int sy = 0, int sw = 0, int sh = 0) const AVOCADO_ENSURE_STACK_ALIGNED_FOR_SSE;

	int width() const;

	static AbstractFactory<SfmlImage> *factory;

private:

	sf::Texture *texture;

};

/**
 * @ingroup Manufacturing
 * @ingroup Resources
 * @ingroup SFML
 * @ingroup SPI
 */
template <>
class AbstractFactory<SfmlImage> : public AbstractFactory<Image> {

	virtual ~AbstractFactory<SfmlImage>() {}

	SfmlImage *create(const boost::filesystem::path &uri) {
		return new SfmlImage(uri);
	}

	SfmlImage *create() {
		return new SfmlImage();
	}

};

/**
 * @}
 */

}

#endif // AVOCADO_SFMLIMAGE_H
