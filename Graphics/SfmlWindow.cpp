#include "core/avocado-global.h"

#include "SfmlWindow.h"

#include "SfmlImage.h"

using namespace std;

const double JoystickMagnitude = 100;

namespace avo {

AbstractFactory<SfmlWindow> *SfmlWindow::factory = new AbstractFactory<SfmlWindow>();

SfmlWindow::SfmlWindow()
	: Window()
	, window(new sf::RenderWindow())
{
}

SfmlWindow::~SfmlWindow() {
	delete window;
}

void SfmlWindow::display() {
	window->display();
}

int keyCodeMap(sf::Keyboard::Key keyCode) {

	int mappedKeyCode;
	const std::map<std::string, int> &KeyCodes = Window::Event::KeyCodes();

	switch (keyCode) {

	case sf::Keyboard::A: mappedKeyCode = KeyCodes["A"]; break;
	case sf::Keyboard::B: mappedKeyCode = KeyCodes["B"]; break;
	case sf::Keyboard::C: mappedKeyCode = KeyCodes["C"]; break;
	case sf::Keyboard::D: mappedKeyCode = KeyCodes["D"]; break;
	case sf::Keyboard::E: mappedKeyCode = KeyCodes["E"]; break;
	case sf::Keyboard::F: mappedKeyCode = KeyCodes["F"]; break;
	case sf::Keyboard::G: mappedKeyCode = KeyCodes["G"]; break;
	case sf::Keyboard::H: mappedKeyCode = KeyCodes["H"]; break;
	case sf::Keyboard::I: mappedKeyCode = KeyCodes["I"]; break;
	case sf::Keyboard::J: mappedKeyCode = KeyCodes["J"]; break;
	case sf::Keyboard::K: mappedKeyCode = KeyCodes["K"]; break;
	case sf::Keyboard::L: mappedKeyCode = KeyCodes["L"]; break;
	case sf::Keyboard::M: mappedKeyCode = KeyCodes["M"]; break;
	case sf::Keyboard::N: mappedKeyCode = KeyCodes["N"]; break;
	case sf::Keyboard::O: mappedKeyCode = KeyCodes["O"]; break;
	case sf::Keyboard::P: mappedKeyCode = KeyCodes["P"]; break;
	case sf::Keyboard::Q: mappedKeyCode = KeyCodes["Q"]; break;
	case sf::Keyboard::R: mappedKeyCode = KeyCodes["R"]; break;
	case sf::Keyboard::S: mappedKeyCode = KeyCodes["S"]; break;
	case sf::Keyboard::T: mappedKeyCode = KeyCodes["T"]; break;
	case sf::Keyboard::U: mappedKeyCode = KeyCodes["U"]; break;
	case sf::Keyboard::V: mappedKeyCode = KeyCodes["V"]; break;
	case sf::Keyboard::W: mappedKeyCode = KeyCodes["W"]; break;
	case sf::Keyboard::X: mappedKeyCode = KeyCodes["X"]; break;
	case sf::Keyboard::Y: mappedKeyCode = KeyCodes["Y"]; break;
	case sf::Keyboard::Z: mappedKeyCode = KeyCodes["Z"]; break;
	case sf::Keyboard::Num0: mappedKeyCode = KeyCodes["0"]; break;
	case sf::Keyboard::Num1: mappedKeyCode = KeyCodes["1"]; break;
	case sf::Keyboard::Num2: mappedKeyCode = KeyCodes["2"]; break;
	case sf::Keyboard::Num3: mappedKeyCode = KeyCodes["3"]; break;
	case sf::Keyboard::Num4: mappedKeyCode = KeyCodes["4"]; break;
	case sf::Keyboard::Num5: mappedKeyCode = KeyCodes["5"]; break;
	case sf::Keyboard::Num6: mappedKeyCode = KeyCodes["6"]; break;
	case sf::Keyboard::Num7: mappedKeyCode = KeyCodes["7"]; break;
	case sf::Keyboard::Num8: mappedKeyCode = KeyCodes["8"]; break;
	case sf::Keyboard::Num9: mappedKeyCode = KeyCodes["9"]; break;
	case sf::Keyboard::Escape: mappedKeyCode = KeyCodes["Escape"]; break;
	case sf::Keyboard::LControl: mappedKeyCode = KeyCodes["ControlLeft"]; break;
	case sf::Keyboard::LShift: mappedKeyCode = KeyCodes["ShiftLeft"]; break;
	case sf::Keyboard::LAlt: mappedKeyCode = KeyCodes["AltLeft"]; break;
	case sf::Keyboard::LSystem: mappedKeyCode = KeyCodes["SystemLeft"]; break;
	case sf::Keyboard::RControl: mappedKeyCode = KeyCodes["ControlRight"]; break;
	case sf::Keyboard::RShift: mappedKeyCode = KeyCodes["ShiftRight"]; break;
	case sf::Keyboard::RAlt: mappedKeyCode = KeyCodes["AltRight"]; break;
	case sf::Keyboard::RSystem: mappedKeyCode = KeyCodes["SystemRight"]; break;
	case sf::Keyboard::Menu: mappedKeyCode = KeyCodes["Menu"]; break;
	case sf::Keyboard::LBracket: mappedKeyCode = KeyCodes["BracketLeft"]; break;
	case sf::Keyboard::RBracket: mappedKeyCode = KeyCodes["BracketRight"]; break;
	case sf::Keyboard::SemiColon: mappedKeyCode = KeyCodes["Semicolon"]; break;
	case sf::Keyboard::Comma: mappedKeyCode = KeyCodes["Comma"]; break;
	case sf::Keyboard::Period: mappedKeyCode = KeyCodes["Period"]; break;
	case sf::Keyboard::Quote: mappedKeyCode = KeyCodes["QuotationMark"]; break;
	case sf::Keyboard::Slash: mappedKeyCode = KeyCodes["Slash"]; break;
	case sf::Keyboard::BackSlash: mappedKeyCode = KeyCodes["Backslash"]; break;
	case sf::Keyboard::Tilde: mappedKeyCode = KeyCodes["Tilde"]; break;
	case sf::Keyboard::Equal: mappedKeyCode = KeyCodes["EqualsSign"]; break;
	case sf::Keyboard::Dash: mappedKeyCode = KeyCodes["Dash"]; break;
	case sf::Keyboard::Space: mappedKeyCode = KeyCodes["Space"]; break;
	case sf::Keyboard::Return: mappedKeyCode = KeyCodes["Enter"]; break;
	case sf::Keyboard::BackSpace: mappedKeyCode = KeyCodes["Backspace"]; break;
	case sf::Keyboard::Tab: mappedKeyCode = KeyCodes["Tab"]; break;
	case sf::Keyboard::PageUp: mappedKeyCode = KeyCodes["PageUp"]; break;
	case sf::Keyboard::PageDown: mappedKeyCode = KeyCodes["PageDown"]; break;
	case sf::Keyboard::End: mappedKeyCode = KeyCodes["End"]; break;
	case sf::Keyboard::Home: mappedKeyCode = KeyCodes["Home"]; break;
	case sf::Keyboard::Insert: mappedKeyCode = KeyCodes["Insert"]; break;
	case sf::Keyboard::Delete: mappedKeyCode = KeyCodes["Delete"]; break;
	case sf::Keyboard::Add: mappedKeyCode = KeyCodes["Plus"]; break;
	case sf::Keyboard::Subtract: mappedKeyCode = KeyCodes["Dash"]; break;
	case sf::Keyboard::Multiply: mappedKeyCode = KeyCodes["Asterisk"]; break;
	case sf::Keyboard::Divide: mappedKeyCode = KeyCodes["Slash"]; break;
	case sf::Keyboard::Left: mappedKeyCode = KeyCodes["ArrowLeft"]; break;
	case sf::Keyboard::Right: mappedKeyCode = KeyCodes["ArrowRight"]; break;
	case sf::Keyboard::Up: mappedKeyCode = KeyCodes["ArrowUp"]; break;
	case sf::Keyboard::Down: mappedKeyCode = KeyCodes["ArrowDown"]; break;
	case sf::Keyboard::Numpad0: mappedKeyCode = KeyCodes["0"]; break;
	case sf::Keyboard::Numpad1: mappedKeyCode = KeyCodes["1"]; break;
	case sf::Keyboard::Numpad2: mappedKeyCode = KeyCodes["2"]; break;
	case sf::Keyboard::Numpad3: mappedKeyCode = KeyCodes["3"]; break;
	case sf::Keyboard::Numpad4: mappedKeyCode = KeyCodes["4"]; break;
	case sf::Keyboard::Numpad5: mappedKeyCode = KeyCodes["5"]; break;
	case sf::Keyboard::Numpad6: mappedKeyCode = KeyCodes["6"]; break;
	case sf::Keyboard::Numpad7: mappedKeyCode = KeyCodes["7"]; break;
	case sf::Keyboard::Numpad8: mappedKeyCode = KeyCodes["8"]; break;
	case sf::Keyboard::Numpad9: mappedKeyCode = KeyCodes["9"]; break;
	case sf::Keyboard::F1: mappedKeyCode = KeyCodes["F1"]; break;
	case sf::Keyboard::F2: mappedKeyCode = KeyCodes["F2"]; break;
	case sf::Keyboard::F3: mappedKeyCode = KeyCodes["F3"]; break;
	case sf::Keyboard::F4: mappedKeyCode = KeyCodes["F4"]; break;
	case sf::Keyboard::F5: mappedKeyCode = KeyCodes["F5"]; break;
	case sf::Keyboard::F6: mappedKeyCode = KeyCodes["F6"]; break;
	case sf::Keyboard::F7: mappedKeyCode = KeyCodes["F7"]; break;
	case sf::Keyboard::F8: mappedKeyCode = KeyCodes["F8"]; break;
	case sf::Keyboard::F9: mappedKeyCode = KeyCodes["F9"]; break;
	case sf::Keyboard::F10: mappedKeyCode = KeyCodes["F10"]; break;
	case sf::Keyboard::F11: mappedKeyCode = KeyCodes["F11"]; break;
	case sf::Keyboard::F12: mappedKeyCode = KeyCodes["F12"]; break;
	case sf::Keyboard::F13: mappedKeyCode = KeyCodes["F13"]; break;
	case sf::Keyboard::F14: mappedKeyCode = KeyCodes["F14"]; break;
	case sf::Keyboard::F15: mappedKeyCode = KeyCodes["F15"]; break;
	case sf::Keyboard::Pause: mappedKeyCode = KeyCodes["Pause"]; break;
	default: break;
	}

	return mappedKeyCode;
}
int mouseButtonMap(sf::Mouse::Button button) {

	int mappedButton;
	const std::map<std::string, int> &MouseButtons = Window::Event::MouseButtons();

	switch (button) {
	case sf::Mouse::Left: mappedButton = MouseButtons["ButtonLeft"]; break;
	case sf::Mouse::Middle: mappedButton = MouseButtons["ButtonMiddle"]; break;
	case sf::Mouse::Right: mappedButton = MouseButtons["ButtonRight"]; break;
	case sf::Mouse::XButton1: mappedButton = MouseButtons["WheelUp"]; break;
	case sf::Mouse::XButton2: mappedButton = MouseButtons["WheelDown"]; break;
	default: break;
	}

	return mappedButton;
}

Window::Event SfmlWindow::pollEvents() {

	Event event;
	sf::Event sfmlEvent;

	while (window->pollEvent(sfmlEvent)) {

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
				sfmlEvent.joystickMove.joystickId,
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
				sfmlEvent.joystickButton.joystickId,
				sfmlEvent.joystickButton.button
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
				sfmlEvent.joystickButton.joystickId,
				sfmlEvent.joystickButton.button
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

void SfmlWindow::render(Image *working, int x, int y, int w, int h) {
	AVOCADO_UNUSED(x);
	AVOCADO_UNUSED(y);
	AVOCADO_UNUSED(w);
	AVOCADO_UNUSED(h);
	sf::Sprite sprite(
		Image::superCast<SfmlImage>(working)->renderTexture->getTexture()
	);
	window->clear();
	window->draw(sprite);
}

void SfmlWindow::set() {

	// Translate Window flags to SFML flags.
	unsigned int sfmlStyle = sf::Style::Default;
	if (flags() & Flags_Fullscreen) sfmlStyle |= sf::Style::Fullscreen;

	window->create(
		sf::VideoMode(width(), height()),
		m_title,
		sfmlStyle
	);

	window->setKeyRepeatEnabled(false);
	window->setVerticalSyncEnabled(true);
	window->clear();
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
	window->setMouseCursorVisible(visible);
}

void SfmlWindow::setWindowTitle(const std::string &title, const std::string &iconified) {
	AVOCADO_UNUSED(iconified);

	m_title = title;

	window->setTitle(m_title);
}

}

