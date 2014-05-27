#ifndef AVOCADO_SFMLTIMINGSERVICE_H
#define AVOCADO_SFMLTIMINGSERVICE_H

#include "avocado-global.h"

#define SFML_STATIC

#include "Timing/TimingService.h"

namespace avo {

/**
 * @addtogroup Timing
 * @{
 */

/**
 * @ingroup SFML
 * @ingroup SPI
 */
class SfmlTimingService : public TimingService {

public:

	SfmlTimingService();
	~SfmlTimingService();

	void close();

	void sleep(int ms);

	static AbstractFactory<SfmlTimingService> *factory;

};

/**
 * @ingroup SFML
 * @ingroup Manufacturing
 * @ingroup SPI
 */
template <>
class AbstractFactory<SfmlTimingService> : public AbstractFactory<TimingService> {

public:

	virtual ~AbstractFactory<SfmlTimingService>() {}

	SfmlTimingService *create() { return new SfmlTimingService(); }

};

/**
 * @}
 */

}

#endif // AVOCADO_SFMLTIMINGSERVICE_H
