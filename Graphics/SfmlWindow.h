#ifndef AVOCADO_SFMLWINDOW_H
#define AVOCADO_SFMLWINDOW_H

#include "core/avocado-global.h"

#define SFML_STATIC

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

	void setFlags(WindowFlags flags = Flags_Default);

	void setSize(int width, int height);

	void setMouseVisibility(bool visible);

	void setWindowTitle(const std::string &title, const std::string &iconified = "");

	sf::RenderWindow *window();

	static AbstractFactory<SfmlWindow> *factory;

private:

	void set();

	sf::RenderWindow *_window;

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
