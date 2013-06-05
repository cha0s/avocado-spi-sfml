#ifndef AVOCADO_SFMLIMAGE_H
#define AVOCADO_SFMLIMAGE_H

#include "core/avocado-global.h"

#define SFML_STATIC

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

	int width() const;

	sf::Texture *texture() const;

	static AbstractFactory<SfmlImage> *factory;

private:

	sf::Texture *_texture;

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
