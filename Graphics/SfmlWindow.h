#ifndef AVOCADO_SFMLWINDOW_H
#define AVOCADO_SFMLWINDOW_H

#include "core/avocado-global.h"

#include <string>

#include "core/Graphics/Window.h"

#include <SFML/Graphics.hpp>

namespace avo {

/**
 * @addtogroup Graphics
 * @{
 */

/**
 * Represents the screen buffers and operations.
 *
 * @ingroup SFML
 */
class SfmlWindow : public Window {

public:

	SfmlWindow();
	~SfmlWindow();

	void display();

	Event pollEvents();

	void render(Canvas *working, int x, int y, int w, int h);

	void render(Image *working, int x, int y, int w, int h);

	void setFlags(WindowFlags flags = Flags_Default);

	void setSize(int width, int height);

	void setMouseVisibility(bool visible);

	void setWindowTitle(const std::string &title, const std::string &iconified = "");

	static AbstractFactory<SfmlWindow> *factory;

private:

	void set();

	sf::RenderWindow *window;

	std::string m_title;
};

/**
 * @ingroup Manufacturing
 * @ingroup SFML
 * @ingroup SPI
 */
template <>
class AbstractFactory<SfmlWindow> : public AbstractFactory<Window> {

public:

	virtual ~AbstractFactory<SfmlWindow>() {}

	SfmlWindow *create() {
		return new SfmlWindow();
	}

};

/**
 * @}
 */

}

#endif // AVOCADO_SFMLWINDOW_H
