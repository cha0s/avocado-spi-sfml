#include "core/avocado-global.h"

#include "SfmlWindow.h"

#include "SfmlImage.h"

using namespace std;

const double JoystickMagnitude = 100;

namespace avo {

AbstractFactory<SfmlWindow> *SfmlWindow::factory = new AbstractFactory<SfmlWindow>();

SfmlWindow::SfmlWindow()
	: Window()
	, _window(new sf::RenderWindow())
{
}

SfmlWindow::~SfmlWindow() {
	delete _window;
}

void SfmlWindow::display() {
	_window->display();
}

int keyCodeMap(sf::Keyboard::Key keyCode) {

	int mappedKeyCode;
	const std::map<std::string, int> &KeyCodes = Window::Event::KeyCodes();

	switch (keyCode) {

	case sf::Keyboard::A: mappedKeyCode = KeyCodes.at("A"); break;
	case sf::Keyboard::B: mappedKeyCode = KeyCodes.at("B"); break;
	case sf::Keyboard::C: mappedKeyCode = KeyCodes.at("C"); break;
	case sf::Keyboard::D: mappedKeyCode = KeyCodes.at("D"); break;
	case sf::Keyboard::E: mappedKeyCode = KeyCodes.at("E"); break;
	case sf::Keyboard::F: mappedKeyCode = KeyCodes.at("F"); break;
	case sf::Keyboard::G: mappedKeyCode = KeyCodes.at("G"); break;
	case sf::Keyboard::H: mappedKeyCode = KeyCodes.at("H"); break;
	case sf::Keyboard::I: mappedKeyCode = KeyCodes.at("I"); break;
	case sf::Keyboard::J: mappedKeyCode = KeyCodes.at("J"); break;
	case sf::Keyboard::K: mappedKeyCode = KeyCodes.at("K"); break;
	case sf::Keyboard::L: mappedKeyCode = KeyCodes.at("L"); break;
	case sf::Keyboard::M: mappedKeyCode = KeyCodes.at("M"); break;
	case sf::Keyboard::N: mappedKeyCode = KeyCodes.at("N"); break;
	case sf::Keyboard::O: mappedKeyCode = KeyCodes.at("O"); break;
	case sf::Keyboard::P: mappedKeyCode = KeyCodes.at("P"); break;
	case sf::Keyboard::Q: mappedKeyCode = KeyCodes.at("Q"); break;
	case sf::Keyboard::R: mappedKeyCode = KeyCodes.at("R"); break;
	case sf::Keyboard::S: mappedKeyCode = KeyCodes.at("S"); break;
	case sf::Keyboard::T: mappedKeyCode = KeyCodes.at("T"); break;
	case sf::Keyboard::U: mappedKeyCode = KeyCodes.at("U"); break;
	case sf::Keyboard::V: mappedKeyCode = KeyCodes.at("V"); break;
	case sf::Keyboard::W: mappedKeyCode = KeyCodes.at("W"); break;
	case sf::Keyboard::X: mappedKeyCode = KeyCodes.at("X"); break;
	case sf::Keyboard::Y: mappedKeyCode = KeyCodes.at("Y"); break;
	case sf::Keyboard::Z: mappedKeyCode = KeyCodes.at("Z"); break;
	case sf::Keyboard::Num0: mappedKeyCode = KeyCodes.at("0"); break;
	case sf::Keyboard::Num1: mappedKeyCode = KeyCodes.at("1"); break;
	case sf::Keyboard::Num2: mappedKeyCode = KeyCodes.at("2"); break;
	case sf::Keyboard::Num3: mappedKeyCode = KeyCodes.at("3"); break;
	case sf::Keyboard::Num4: mappedKeyCode = KeyCodes.at("4"); break;
	case sf::Keyboard::Num5: mappedKeyCode = KeyCodes.at("5"); break;
	case sf::Keyboard::Num6: mappedKeyCode = KeyCodes.at("6"); break;
	case sf::Keyboard::Num7: mappedKeyCode = KeyCodes.at("7"); break;
	case sf::Keyboard::Num8: mappedKeyCode = KeyCodes.at("8"); break;
	case sf::Keyboard::Num9: mappedKeyCode = KeyCodes.at("9"); break;
	case sf::Keyboard::Escape: mappedKeyCode = KeyCodes.at("Escape"); break;
	case sf::Keyboard::LControl: mappedKeyCode = KeyCodes.at("ControlLeft"); break;
	case sf::Keyboard::LShift: mappedKeyCode = KeyCodes.at("ShiftLeft"); break;
	case sf::Keyboard::LAlt: mappedKeyCode = KeyCodes.at("AltLeft"); break;
	case sf::Keyboard::LSystem: mappedKeyCode = KeyCodes.at("SystemLeft"); break;
	case sf::Keyboard::RControl: mappedKeyCode = KeyCodes.at("ControlRight"); break;
	case sf::Keyboard::RShift: mappedKeyCode = KeyCodes.at("ShiftRight"); break;
	case sf::Keyboard::RAlt: mappedKeyCode = KeyCodes.at("AltRight"); break;
	case sf::Keyboard::RSystem: mappedKeyCode = KeyCodes.at("SystemRight"); break;
	case sf::Keyboard::Menu: mappedKeyCode = KeyCodes.at("Menu"); break;
	case sf::Keyboard::LBracket: mappedKeyCode = KeyCodes.at("BracketLeft"); break;
	case sf::Keyboard::RBracket: mappedKeyCode = KeyCodes.at("BracketRight"); break;
	case sf::Keyboard::SemiColon: mappedKeyCode = KeyCodes.at("Semicolon"); break;
	case sf::Keyboard::Comma: mappedKeyCode = KeyCodes.at("Comma"); break;
	case sf::Keyboard::Period: mappedKeyCode = KeyCodes.at("Period"); break;
	case sf::Keyboard::Quote: mappedKeyCode = KeyCodes.at("QuotationMark"); break;
	case sf::Keyboard::Slash: mappedKeyCode = KeyCodes.at("Slash"); break;
	case sf::Keyboard::BackSlash: mappedKeyCode = KeyCodes.at("Backslash"); break;
	case sf::Keyboard::Tilde: mappedKeyCode = KeyCodes.at("Tilde"); break;
	case sf::Keyboard::Equal: mappedKeyCode = KeyCodes.at("EqualsSign"); break;
	case sf::Keyboard::Dash: mappedKeyCode = KeyCodes.at("Dash"); break;
	case sf::Keyboard::Space: mappedKeyCode = KeyCodes.at("Space"); break;
	case sf::Keyboard::Return: mappedKeyCode = KeyCodes.at("Enter"); break;
	case sf::Keyboard::BackSpace: mappedKeyCode = KeyCodes.at("Backspace"); break;
	case sf::Keyboard::Tab: mappedKeyCode = KeyCodes.at("Tab"); break;
	case sf::Keyboard::PageUp: mappedKeyCode = KeyCodes.at("PageUp"); break;
	case sf::Keyboard::PageDown: mappedKeyCode = KeyCodes.at("PageDown"); break;
	case sf::Keyboard::End: mappedKeyCode = KeyCodes.at("End"); break;
	case sf::Keyboard::Home: mappedKeyCode = KeyCodes.at("Home"); break;
	case sf::Keyboard::Insert: mappedKeyCode = KeyCodes.at("Insert"); break;
	case sf::Keyboard::Delete: mappedKeyCode = KeyCodes.at("Delete"); break;
	case sf::Keyboard::Add: mappedKeyCode = KeyCodes.at("Plus"); break;
	case sf::Keyboard::Subtract: mappedKeyCode = KeyCodes.at("Dash"); break;
	case sf::Keyboard::Multiply: mappedKeyCode = KeyCodes.at("Asterisk"); break;
	case sf::Keyboard::Divide: mappedKeyCode = KeyCodes.at("Slash"); break;
	case sf::Keyboard::Left: mappedKeyCode = KeyCodes.at("ArrowLeft"); break;
	case sf::Keyboard::Right: mappedKeyCode = KeyCodes.at("ArrowRight"); break;
	case sf::Keyboard::Up: mappedKeyCode = KeyCodes.at("ArrowUp"); break;
	case sf::Keyboard::Down: mappedKeyCode = KeyCodes.at("ArrowDown"); break;
	case sf::Keyboard::Numpad0: mappedKeyCode = KeyCodes.at("0"); break;
	case sf::Keyboard::Numpad1: mappedKeyCode = KeyCodes.at("1"); break;
	case sf::Keyboard::Numpad2: mappedKeyCode = KeyCodes.at("2"); break;
	case sf::Keyboard::Numpad3: mappedKeyCode = KeyCodes.at("3"); break;
	case sf::Keyboard::Numpad4: mappedKeyCode = KeyCodes.at("4"); break;
	case sf::Keyboard::Numpad5: mappedKeyCode = KeyCodes.at("5"); break;
	case sf::Keyboard::Numpad6: mappedKeyCode = KeyCodes.at("6"); break;
	case sf::Keyboard::Numpad7: mappedKeyCode = KeyCodes.at("7"); break;
	case sf::Keyboard::Numpad8: mappedKeyCode = KeyCodes.at("8"); break;
	case sf::Keyboard::Numpad9: mappedKeyCode = KeyCodes.at("9"); break;
	case sf::Keyboard::F1: mappedKeyCode = KeyCodes.at("F1"); break;
	case sf::Keyboard::F2: mappedKeyCode = KeyCodes.at("F2"); break;
	case sf::Keyboard::F3: mappedKeyCode = KeyCodes.at("F3"); break;
	case sf::Keyboard::F4: mappedKeyCode = KeyCodes.at("F4"); break;
	case sf::Keyboard::F5: mappedKeyCode = KeyCodes.at("F5"); break;
	case sf::Keyboard::F6: mappedKeyCode = KeyCodes.at("F6"); break;
	case sf::Keyboard::F7: mappedKeyCode = KeyCodes.at("F7"); break;
	case sf::Keyboard::F8: mappedKeyCode = KeyCodes.at("F8"); break;
	case sf::Keyboard::F9: mappedKeyCode = KeyCodes.at("F9"); break;
	case sf::Keyboard::F10: mappedKeyCode = KeyCodes.at("F10"); break;
	case sf::Keyboard::F11: mappedKeyCode = KeyCodes.at("F11"); break;
	case sf::Keyboard::F12: mappedKeyCode = KeyCodes.at("F12"); break;
	case sf::Keyboard::F13: mappedKeyCode = KeyCodes.at("F13"); break;
	case sf::Keyboard::F14: mappedKeyCode = KeyCodes.at("F14"); break;
	case sf::Keyboard::F15: mappedKeyCode = KeyCodes.at("F15"); break;
	case sf::Keyboard::Pause: mappedKeyCode = KeyCodes.at("Pause"); break;
	default: break;
	}

	return mappedKeyCode;
}

int mouseButtonMap(sf::Mouse::Button button) {

	int mappedButton;
	const std::map<std::string, int> &MouseButtons = Window::Event::MouseButtons();

	switch (button) {
	case sf::Mouse::Left: mappedButton = MouseButtons.at("ButtonLeft"); break;
	case sf::Mouse::Middle: mappedButton = MouseButtons.at("ButtonMiddle"); break;
	case sf::Mouse::Right: mappedButton = MouseButtons.at("ButtonRight"); break;
	case sf::Mouse::XButton1: mappedButton = MouseButtons.at("WheelUp"); break;
	case sf::Mouse::XButton2: mappedButton = MouseButtons.at("WheelDown"); break;
	default: mappedButton = -1; break;
	}

	return mappedButton;
}

Window::Event SfmlWindow::pollEvents() {

	Event event;
	sf::Event sfmlEvent;

	while (_window->pollEvent(sfmlEvent)) {

		switch (sfmlEvent.type) {

		case sf::Event::KeyPressed: {

			Event::KeyDown keyDown = {keyCodeMap(sfmlEvent.key.code)};
			event.keyDown.push_back(keyDown);

			break;
		}

		case sf::Event::KeyReleased: {

			Event::KeyUp keyUp = {keyCodeMap(sfmlEvent.key.code)};
			event.keyUp.push_back(keyUp);

			break;
		}

		case sf::Event::JoystickMoved: {

			Event::JoyAxis joyAxis = {
				static_cast<int>(sfmlEvent.joystickMove.joystickId),
				sfmlEvent.joystickMove.axis,
				sfmlEvent.joystickMove.position / JoystickMagnitude
			};

			deque<Event::JoyAxis>::iterator i = find(
				event.joyAxis.begin(),
				event.joyAxis.end(),
				joyAxis
			);

			if (event.joyAxis.end() == i) {
				event.joyAxis.push_back(joyAxis);
			}
			else {
				i->value = joyAxis.value;
			}

			break;
		}

		case sf::Event::JoystickButtonPressed: {

			Event::JoyButtonDown joyButtonDown = {
				static_cast<int>(sfmlEvent.joystickButton.joystickId),
				static_cast<int>(sfmlEvent.joystickButton.button)
			};

			deque<Event::JoyButtonDown>::iterator i = find(
				event.joyButtonDown.begin(),
				event.joyButtonDown.end(),
				joyButtonDown
			);

			if (event.joyButtonDown.end() == i) {
				event.joyButtonDown.push_back(joyButtonDown);
			}

			break;
		}

		case sf::Event::JoystickButtonReleased: {

			Event::JoyButtonUp joyButtonUp = {
				static_cast<int>(sfmlEvent.joystickButton.joystickId),
				static_cast<int>(sfmlEvent.joystickButton.button)
			};

			deque<Event::JoyButtonUp>::iterator i = find(
				event.joyButtonUp.begin(),
				event.joyButtonUp.end(),
				joyButtonUp
			);

			if (event.joyButtonUp.end() == i) {
				event.joyButtonUp.push_back(joyButtonUp);
			}

			break;
		}

		case sf::Event::MouseButtonPressed: {

			Event::MouseButtonDown mouseDown = {
				sfmlEvent.mouseButton.x,
				sfmlEvent.mouseButton.y,
				mouseButtonMap(sfmlEvent.mouseButton.button)
			};
			event.mouseButtonDown.push_back(mouseDown);

			break;
		}

		case sf::Event::MouseButtonReleased: {

			Event::MouseButtonUp mouseUp = {
				sfmlEvent.mouseButton.x,
				sfmlEvent.mouseButton.y,
				mouseButtonMap(sfmlEvent.mouseButton.button)
			};
			event.mouseButtonUp.push_back(mouseUp);

			break;
		}

		case sf::Event::MouseWheelMoved: {

			Event::MouseWheelMove mouseWheelMove = {
				sfmlEvent.mouseWheel.delta > 0 ? 1 : -1
			};
			event.mouseWheelMove.push_back(mouseWheelMove);

			break;
		}

		case sf::Event::MouseMoved: {

			Event::MouseMove mouseMove = {
				sfmlEvent.mouseMove.x,
				sfmlEvent.mouseMove.y
			};
			event.mouseMove.push_back(mouseMove);

			break;
		}

		case sf::Event::Closed: {

			event.quit = true;
			break;
		}

		case sf::Event::Resized: {

			event.resize.width = sfmlEvent.size.width;
			event.resize.height = sfmlEvent.size.height;

			Window::setSize(sfmlEvent.size.width, sfmlEvent.size.height);

			break;
		}

		default: {
			break;

		}

		}
	}

	return event;
}

void SfmlWindow::set() {

	// Translate Window flags to SFML flags.
	unsigned int sfmlStyle = sf::Style::Default;
	if (flags() & Flags_Fullscreen) sfmlStyle |= sf::Style::Fullscreen;

	_window->create(
		sf::VideoMode(width(), height()),
		m_title,
		sfmlStyle
	);

	_window->setKeyRepeatEnabled(false);
	_window->setVerticalSyncEnabled(true);
	_window->clear();
}

void SfmlWindow::setFlags(WindowFlags flags) {
	Window::setFlags(flags);

	set();
}

void SfmlWindow::setSize(int width, int height) {
	Window::setSize(width, height);

	set();
}

void SfmlWindow::setMouseVisibility(bool visible) {
	_window->setMouseCursorVisible(visible);
}

void SfmlWindow::setWindowTitle(const std::string &title, const std::string &iconified) {
	AVOCADO_UNUSED(iconified);

	m_title = title;

	_window->setTitle(m_title);
}

sf::RenderWindow *SfmlWindow::window() {
	return _window;
}

}

