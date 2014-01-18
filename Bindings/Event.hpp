#ifndef EVENT_HPP_
#define EVENT_HPP_

/* En este archivo se describe e implementa un smob
 * para la clase Event de la libreria SFML 2.1
 */

#include <SFML/Window/Event.hpp>
#include <libguile.h>

struct EventSmob
{
    sf::Event * ptr;
};

static scm_t_bits EventTag;

EventSmob * scmToEvent(SCM smob)
{
    scm_assert_smob_type(EventTag, smob);
    return (EventSmob *) SCM_SMOB_DATA(smob);
}

SCM markEvent(SCM smob)
{
    return SCM_BOOL_F;
}

size_t freeEvent(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    delete s->ptr;
    scm_gc_free(s, sizeof(EventSmob), "Event");
    return 0;
}

int printEvent(SCM smob, SCM port, scm_print_state * ps)
{
    scm_puts("#<Event>", port);
    return 1;
}

SCM eventMake()
{
    EventSmob * s;
    s = (EventSmob *)scm_gc_malloc(sizeof(EventSmob),
				   "Event");
    s->ptr = new sf::Event();
    return scm_new_smob(EventTag, (scm_t_bits)s);
}

SCM eventType(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    switch(s->ptr->type){
    case sf::Event::Closed:
	return scm_from_locale_symbol("Closed");
	break;
    case sf::Event::Resized:
	return scm_from_locale_symbol("Resized");
	break;
    case sf::Event::LostFocus:
	return scm_from_locale_symbol("LostFocus");
	break;
    case sf::Event::GainedFocus:
	return scm_from_locale_symbol("GainedFocus");
	break;
    case sf::Event::TextEntered:
	return scm_from_locale_symbol("TextEntered");
	break;
    case sf::Event::KeyPressed:
	return scm_from_locale_symbol("KeyPressed");
	break;
    case sf::Event::KeyReleased:
	return scm_from_locale_symbol("KeyReleased");
	break;
    case sf::Event::MouseWheelMoved:
	return scm_from_locale_symbol("MoseWheelMoved");
	break;
    case sf::Event::MouseButtonPressed:
	return scm_from_locale_symbol("MouseButtonPressed");
	break;
    case sf::Event::MouseButtonReleased:
	return scm_from_locale_symbol("MouseButtonReleased");
	break;
    case sf::Event::MouseMoved:
	return scm_from_locale_symbol("MouseMoved");
	break;
    case sf::Event::MouseEntered:
	return scm_from_locale_symbol("MouseEntered");
	break;
    case sf::Event::MouseLeft:
	return scm_from_locale_symbol("MouseLeft");
	break;
    case sf::Event::JoystickButtonPressed:
	return scm_from_locale_symbol("JoystickButtonPressed");
	break;
    case sf::Event::JoystickButtonReleased:
	return scm_from_locale_symbol("JoystickButtonReleased");
	break;
    case sf::Event::JoystickMoved:
	return scm_from_locale_symbol("JoystickMoved");
	break;
    case sf::Event::JoystickConnected:
	return scm_from_locale_symbol("JoystickConnected");
	break;
    case sf::Event::JoystickDisconnected:
	return scm_from_locale_symbol("JoystickDisconnected");
	break;
    case sf::Event::Count:
	return scm_from_locale_symbol("Count");
	break;
    default:
	break;
    }
    return SCM_BOOL_F;
}

SCM eventSizeWidth(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_unsigned_integer(s->ptr->size.width);
}

SCM eventSizeHeight(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_unsigned_integer(s->ptr->size.height);
}

SCM eventKeyCode(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    switch(s->ptr->key.code){
    case sf::Keyboard::Unknown:
	return scm_from_locale_symbol("Unknown");
	break;
    case sf::Keyboard::A:
	return scm_from_locale_symbol("A");
	break;
    case sf::Keyboard::B:
	return scm_from_locale_symbol("B");
	break;
    case sf::Keyboard::C:
	return scm_from_locale_symbol("C");
	break;
    case sf::Keyboard::D:
	return scm_from_locale_symbol("D");
	break;
    case sf::Keyboard::E:
	return scm_from_locale_symbol("E");
	break;
    case sf::Keyboard::F:
	return scm_from_locale_symbol("F");
	break;
    case sf::Keyboard::G:
	return scm_from_locale_symbol("G");
	break;
    case sf::Keyboard::H:
	return scm_from_locale_symbol("H");
	break;
    case sf::Keyboard::I:
	return scm_from_locale_symbol("I");
	break;
    case sf::Keyboard::J:
	return scm_from_locale_symbol("J");
	break;
    case sf::Keyboard::K:
	return scm_from_locale_symbol("K");
	break;
    case sf::Keyboard::L:
	return scm_from_locale_symbol("L");
	break;
    case sf::Keyboard::M:
	return scm_from_locale_symbol("M");
	break;
    case sf::Keyboard::N:
	return scm_from_locale_symbol("N");
	break;
    case sf::Keyboard::O:
	return scm_from_locale_symbol("O");
	break;
    case sf::Keyboard::P:
	return scm_from_locale_symbol("P");
	break;
    case sf::Keyboard::Q:
	return scm_from_locale_symbol("Q");
	break;
    case sf::Keyboard::R:
	return scm_from_locale_symbol("R");
	break;
    case sf::Keyboard::S:
	return scm_from_locale_symbol("S");
	break;
    case sf::Keyboard::T:
	return scm_from_locale_symbol("T");
	break;
    case sf::Keyboard::U:
	return scm_from_locale_symbol("U");
	break;
    case sf::Keyboard::V:
	return scm_from_locale_symbol("V");
	break;
    case sf::Keyboard::W:
	return scm_from_locale_symbol("W");
	break;
    case sf::Keyboard::X:
	return scm_from_locale_symbol("X");
	break;
    case sf::Keyboard::Y:
	return scm_from_locale_symbol("Y");
	break;
    case sf::Keyboard::Z:
	return scm_from_locale_symbol("Z");
	break;
    case sf::Keyboard::Num0:
	return scm_from_locale_symbol("Num0");
	break;
    case sf::Keyboard::Num1:
	return scm_from_locale_symbol("Num1");
	break;
    case sf::Keyboard::Num2:
	return scm_from_locale_symbol("Num2");
	break;
    case sf::Keyboard::Num3:
	return scm_from_locale_symbol("Num3");
	break;
    case sf::Keyboard::Num4:
	return scm_from_locale_symbol("Num4");
	break;
    case sf::Keyboard::Num5:
	return scm_from_locale_symbol("Num5");
	break;
    case sf::Keyboard::Num6:
	return scm_from_locale_symbol("Num6");
	break;
    case sf::Keyboard::Num7:
	return scm_from_locale_symbol("Num7");
	break;
    case sf::Keyboard::Num8:
	return scm_from_locale_symbol("Num8");
	break;
    case sf::Keyboard::Num9:
	return scm_from_locale_symbol("Num9");
	break;
    case sf::Keyboard::Escape:
	return scm_from_locale_symbol("Escape");
	break;
    case sf::Keyboard::LControl:
	return scm_from_locale_symbol("LControl");
	break;
    case sf::Keyboard::LShift:
	return scm_from_locale_symbol("LShift");
	break;
    case sf::Keyboard::LAlt:
	return scm_from_locale_symbol("LAlt");
	break;
    case sf::Keyboard::LSystem:
	return scm_from_locale_symbol("LSystem");
	break;
    case sf::Keyboard::RControl:
	return scm_from_locale_symbol("RControl");
	break;
    case sf::Keyboard::RShift:
	return scm_from_locale_symbol("RShift");
	break;
    case sf::Keyboard::RAlt:
	return scm_from_locale_symbol("RAlt");
	break;
    case sf::Keyboard::RSystem:
	return scm_from_locale_symbol("RSystem");
	break;
    case sf::Keyboard::Menu:
	return scm_from_locale_symbol("Menu");
	break;
    case sf::Keyboard::LBracket:
	return scm_from_locale_symbol("LBracket");
	break;
    case sf::Keyboard::RBracket:
	return scm_from_locale_symbol("RBracket");
	break;
    case sf::Keyboard::SemiColon:
	return scm_from_locale_symbol("SemiColon");
	break;
    case sf::Keyboard::Comma:
	return scm_from_locale_symbol("Comma");
	break;
    case sf::Keyboard::Period:
	return scm_from_locale_symbol("Period");
	break;
    case sf::Keyboard::Quote:
	return scm_from_locale_symbol("Quote");
	break;
    case sf::Keyboard::Slash:
	return scm_from_locale_symbol("Slash");
	break;
    case sf::Keyboard::BackSlash:
	return scm_from_locale_symbol("BackSlash");
	break;
    case sf::Keyboard::Tilde:
	return scm_from_locale_symbol("Tilde");
	break;
    case sf::Keyboard::Equal:
	return scm_from_locale_symbol("Equal");
	break;
    case sf::Keyboard::Dash:
	return scm_from_locale_symbol("Dash");
	break;
    case sf::Keyboard::Space:
	return scm_from_locale_symbol("Space");
	break;
    case sf::Keyboard::Return:
	return scm_from_locale_symbol("Return");
	break;
    case sf::Keyboard::BackSpace:
	return scm_from_locale_symbol("BackSpace");
	break;
    case sf::Keyboard::Tab:
	return scm_from_locale_symbol("Tab");
	break;
    case sf::Keyboard::PageUp:
	return scm_from_locale_symbol("PageUp");
	break;
    case sf::Keyboard::PageDown:
	return scm_from_locale_symbol("PageDown");
	break;
    case sf::Keyboard::End:
	return scm_from_locale_symbol("End");
	break;
    case sf::Keyboard::Home:
	return scm_from_locale_symbol("Home");
	break;
    case sf::Keyboard::Insert:
	return scm_from_locale_symbol("Insert");
	break;
    case sf::Keyboard::Delete:
	return scm_from_locale_symbol("Delete");
	break;
    case sf::Keyboard::Add:
	return scm_from_locale_symbol("Add");
	break;
    case sf::Keyboard::Subtract:
	return scm_from_locale_symbol("Subtract");
	break;
    case sf::Keyboard::Multiply:
	return scm_from_locale_symbol("Multiply");
	break;
    case sf::Keyboard::Divide:
	return scm_from_locale_symbol("Divide");
	break;
    case sf::Keyboard::Left:
	return scm_from_locale_symbol("Left");
	break;
    case sf::Keyboard::Right:
	return scm_from_locale_symbol("Right");
	break;
    case sf::Keyboard::Up:
	return scm_from_locale_symbol("Up");
	break;
    case sf::Keyboard::Down:
	return scm_from_locale_symbol("Down");
	break;
    case sf::Keyboard::Numpad0:
	return scm_from_locale_symbol("Numpad0");
	break;
    case sf::Keyboard::Numpad1:
	return scm_from_locale_symbol("Numpad1");
	break;
    case sf::Keyboard::Numpad2:
	return scm_from_locale_symbol("Numpad2");
	break;
    case sf::Keyboard::Numpad3:
	return scm_from_locale_symbol("Numpad3");
	break;
    case sf::Keyboard::Numpad4:
	return scm_from_locale_symbol("Numpad4");
	break;
    case sf::Keyboard::Numpad5:
	return scm_from_locale_symbol("Numpad5");
	break;
    case sf::Keyboard::Numpad6:
	return scm_from_locale_symbol("Numpad6");
	break;
    case sf::Keyboard::Numpad7:
	return scm_from_locale_symbol("Numpad7");
	break;
    case sf::Keyboard::Numpad8:
	return scm_from_locale_symbol("Numpad8");
	break;
    case sf::Keyboard::Numpad9:
	return scm_from_locale_symbol("Numpad9");
	break;
    case sf::Keyboard::F1:
	return scm_from_locale_symbol("F1");
	break;
    case sf::Keyboard::F2:
	return scm_from_locale_symbol("F2");
	break;
    case sf::Keyboard::F3:
	return scm_from_locale_symbol("F3");
	break;
    case sf::Keyboard::F4:
	return scm_from_locale_symbol("F4");
	break;
    case sf::Keyboard::F5:
	return scm_from_locale_symbol("F5");
	break;
    case sf::Keyboard::F6:
	return scm_from_locale_symbol("F6");
	break;
    case sf::Keyboard::F7:
	return scm_from_locale_symbol("F7");
	break;
    case sf::Keyboard::F8:
	return scm_from_locale_symbol("F8");
	break;
    case sf::Keyboard::F9:
	return scm_from_locale_symbol("F9");
	break;
    case sf::Keyboard::F10:
	return scm_from_locale_symbol("F10");
	break;
    case sf::Keyboard::F11:
	return scm_from_locale_symbol("F11");
	break;
    case sf::Keyboard::F12:
	return scm_from_locale_symbol("F12");
	break;
    case sf::Keyboard::F13:
	return scm_from_locale_symbol("F13");
	break;
    case sf::Keyboard::F14:
	return scm_from_locale_symbol("F14");
	break;
    case sf::Keyboard::F15:
	return scm_from_locale_symbol("F15");
	break;
    case sf::Keyboard::Pause:
	return scm_from_locale_symbol("Pause");
	break;
    case sf::Keyboard::KeyCount:
	return scm_from_locale_symbol("KeyCount");
	break;
    }
    return SCM_UNSPECIFIED;
}

SCM eventKeyAltPressed(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    if(s->ptr->key.alt)
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

SCM eventKeyControlPressed(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    if(s->ptr->key.control)
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

SCM eventKeyShiftPressed(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    if(s->ptr->key.shift)
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

SCM eventKeySystemPressed(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    if(s->ptr->key.system)
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

SCM eventMouseButtonCode(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    switch(s->ptr->mouseButton.button){
    case sf::Mouse::Left:
	return scm_from_locale_symbol("Left");
	break;
    case sf::Mouse::Right:
	return scm_from_locale_symbol("Right");
	break;
    case sf::Mouse::Middle:
	return scm_from_locale_symbol("Middle");
	break;
    case sf::Mouse::XButton1:
	return scm_from_locale_symbol("XButton1");
	break;
    case sf::Mouse::XButton2:
	return scm_from_locale_symbol("XButton2");
	break;
    case sf::Mouse::ButtonCount:
	return scm_from_locale_symbol("ButtonCount");
	break;
    default:
	break;
    }
    return SCM_UNSPECIFIED;
}

SCM eventMouseButtonX(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_int(s->ptr->mouseButton.x);
}

SCM eventMouseButtonY(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_int(s->ptr->mouseButton.y);
}

SCM eventMouseMoveX(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_int(s->ptr->mouseMove.x);
}

SCM eventMouseMoveY(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_int(s->ptr->mouseMove.y);
}

SCM eventMouseWheelTicks(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_int(s->ptr->mouseWheel.delta);
}

SCM eventMouseWheelX(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_int(s->ptr->mouseWheel.x);
}

SCM eventMouseWheelY(SCM smob)
{
    EventSmob * s = scmToEvent(smob);
    return scm_from_int(s->ptr->mouseWheel.y);
}

void initEventType()
{
    EventTag = scm_make_smob_type("Event",
				   sizeof(EventSmob));
    scm_set_smob_mark(EventTag, markEvent);
    scm_set_smob_free(EventTag, freeEvent);
    scm_set_smob_print(EventTag, printEvent);

    scm_c_define_gsubr("event-make", 0, 0, 0,
		       (void *)eventMake);
    scm_c_define_gsubr("event-type", 1, 0, 0,
		       (void *)eventType);
    scm_c_define_gsubr("event-size-width", 1, 0, 0,
		       (void *)eventSizeWidth);
    scm_c_define_gsubr("event-size-height", 1, 0, 0,
		       (void *)eventSizeHeight);
    scm_c_define_gsubr("event-key-code", 1, 0, 0,
		       (void *)eventKeyCode);
    scm_c_define_gsubr("event-key-alt-pressed?", 1, 0, 0,
		       (void *)eventKeyAltPressed);
    scm_c_define_gsubr("event-key-control-pressed?", 1, 0, 0,
		       (void *)eventKeyControlPressed);
    scm_c_define_gsubr("event-key-shift-pressed?", 1, 0, 0,
		       (void *)eventKeyShiftPressed);
    scm_c_define_gsubr("event-key-system-pressed?", 1, 0, 0,
		       (void *)eventKeySystemPressed);
    scm_c_define_gsubr("event-mouse-button-code", 1, 0, 0,
		       (void *)eventMouseButtonCode);
    scm_c_define_gsubr("event-mouse-button-x", 1, 0, 0,
		       (void *)eventMouseButtonX);
    scm_c_define_gsubr("event-mouse-button-y", 1, 0, 0,
		       (void *)eventMouseButtonY);
    scm_c_define_gsubr("event-mouse-move-x", 1, 0, 0,
		       (void *)eventMouseMoveX);
    scm_c_define_gsubr("event-mouse-move-y", 1, 0, 0,
		       (void *)eventMouseMoveY);
    scm_c_define_gsubr("event-mouse-wheel-ticks", 1, 0, 0,
		       (void *)eventMouseWheelTicks);
    scm_c_define_gsubr("event-mouse-wheel-x", 1, 0, 0,
		       (void *)eventMouseWheelX);
    scm_c_define_gsubr("event-mouse-wheel-y", 1, 0, 0,
		       (void *)eventMouseWheelY);
}

#endif // EVENT_HPP_
