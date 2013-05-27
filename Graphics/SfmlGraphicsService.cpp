#include "core/avocado-global.h"

#include "SfmlGraphicsService.h"

#include "SfmlCanvas.h"
#include "SfmlFont.h"
#include "SfmlImage.h"
#include "SfmlWindow.h"

namespace avo {

AbstractFactory<SfmlGraphicsService> *SfmlGraphicsService::factory = new AbstractFactory<SfmlGraphicsService>;

SfmlGraphicsService::SfmlGraphicsService() {
	Canvas::factoryManager.setInstance(SfmlCanvas::factory);
	Image::factoryManager.setInstance(SfmlImage::factory);
	Font::factoryManager.setInstance(SfmlFont::factory);
	Window::factoryManager.setInstance(SfmlWindow::factory);
}

SfmlGraphicsService::~SfmlGraphicsService() {
}

void SfmlGraphicsService::close() {
	GraphicsService::close();
}

}
