#ifndef AVOCADO_SFMLSPRITE_H
#define AVOCADO_SFMLSPRITE_H

#include "core/avocado-global.h"

#define SFML_STATIC

#include <SFML/Graphics.hpp>

#include "core/Graphics/Canvas.h"
#include "core/Graphics/Sprite.h"
#include "core/Graphics/Window.h"

namespace avo {

/**
 * @addtogroup Graphics
 * @{
 */

/**
 * SFML Sprite SPI implementation (SPII).
 *
 * @ingroup SFML
 */
class SfmlSprite : public Sprite {

public:

	SfmlSprite();

	void renderTo(Canvas *destination) const;

	void renderTo(Window *destination) const;

	void setAlpha(double alpha);

	void setBlendMode(GraphicsService::BlendMode blendMode);

	void setPosition(int x, int y);

	void setRotation(double angle);

	void setScale(double factorX, double factorY);

	void setSourceRectangle(int x, int y, int w, int h);

private:

	mutable sf::Sprite _sprite;
	sf::RenderStates _renderStates;

};

/**
 * @ingroup Manufacturing
 * @ingroup SFML
 * @ingroup SPI
 */
template <>
class AbstractFactory<SfmlSprite> : public AbstractFactory<Sprite> {

	virtual ~AbstractFactory<SfmlSprite>() {}

	SfmlSprite *create() {
		return new SfmlSprite();
	}

};

/**
 * @}
 */

}

#endif // AVOCADO_SFMLSPRITE_H
