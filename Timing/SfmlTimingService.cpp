#include "avocado-global.h"

#include "SfmlTimingService.h"

#include <SFML/System/Sleep.hpp>

namespace avo {

AbstractFactory<SfmlTimingService> *SfmlTimingService::factory = new AbstractFactory<SfmlTimingService>;

SfmlTimingService::SfmlTimingService() {
}

SfmlTimingService::~SfmlTimingService() {
}

void SfmlTimingService::sleep(int ms) {
	sf::sleep(sf::milliseconds(ms));
}

void SfmlTimingService::close() {
	TimingService::close();
}

}
