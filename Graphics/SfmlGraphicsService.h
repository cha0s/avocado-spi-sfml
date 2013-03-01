#ifndef AVOCADO_SFMLGRAPHICSSERVICE_H
#define AVOCADO_SFMLGRAPHICSSERVICE_H

#include "main/avocado-global.h"

#include "SPI/Abstract/Graphics/GraphicsService.h"

namespace avo {

/**
 * @addtogroup Graphics
 * @{
 */

/**
 * @ingroup SFML
 */
class SfmlGraphicsService : public GraphicsService {

public:

	SfmlGraphicsService();
	~SfmlGraphicsService();

	void close();

	SpecialKeyCodes specialKeyCodes();

	static AbstractFactory<SfmlGraphicsService> *factory;

};

/**
 * @ingroup Manufacturing
 * @ingroup SFML
 * @ingroup SPI
 */
template <>
class AbstractFactory<SfmlGraphicsService> : public AbstractFactory<GraphicsService> {

public:

	virtual ~AbstractFactory<SfmlGraphicsService>() {}

	/**
	 * Create a concrete GraphicsService.
	 */
	SfmlGraphicsService *create() { return new SfmlGraphicsService(); }

};

/**
 * @}
 */

}

#endif // AVOCADO_SFMLGRAPHICSSERVICE_H
