#ifndef WINDOW_HPP_
#define WINDOW_HPP_

/* En este archivo se describe e implementa un smob
 * para la clase RenderWindow de la libreria SFML 2.1
 */

#include <SFML/Graphics/RenderWindow.hpp>
#include <libguile.h>
#include "Vector.hpp"
#include "Color.hpp"
#include "Event.hpp"
#include "Rectangle.hpp"

struct WindowSmob
{
    sf::RenderWindow * ptr;
};

static scm_t_bits WindowTag;

WindowSmob * scmToWindow(SCM smob)
{
    scm_assert_smob_type(WindowTag, smob);
    return (WindowSmob *) SCM_SMOB_DATA(smob);
}

SCM markWindow(SCM smob)
{
    return SCM_BOOL_F;
}

size_t freeWindow(SCM smob)
{
    WindowSmob * s = scmToWindow(smob);
    delete s->ptr;
    scm_gc_free(s, sizeof(WindowSmob), "Window");
    return 0;
}

int printWindow(SCM smob, SCM port, scm_print_state * ps)
{
    scm_puts("#<Window>", port);
    
    return 1;
}

SCM windowMake(SCM w, SCM h, SCM bpp, SCM t)
{
    WindowSmob * s;
    s = (WindowSmob *)scm_gc_malloc(sizeof(WindowSmob),
				    "Window");
    s->ptr = new sf::RenderWindow(sf::VideoMode(scm_to_int(w),
						scm_to_int(h),
						scm_to_int(bpp)),
				  scm_to_locale_string(t));
    return scm_new_smob(WindowTag, (scm_t_bits)s);
}

SCM windowGetSize(SCM smob)
{
    WindowSmob * s = scmToWindow(smob);
    unsigned int car = s->ptr->getSize().x;
    unsigned int cdr = s->ptr->getSize().y;
    return vector2u(car, cdr);
}
SCM windowCreate(SCM smob, SCM w, SCM h, SCM bpp, SCM t)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->create(sf::VideoMode(scm_to_int(w),
				 scm_to_int(h),
				 scm_to_int(bpp)),
		   scm_to_locale_string(t));
    return SCM_UNSPECIFIED;
}
SCM windowClose(SCM smob)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->close();
    return SCM_UNSPECIFIED;
}
SCM windowIsOpen(SCM smob)
{
    WindowSmob * s = scmToWindow(smob);
    if(s->ptr->isOpen())
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}
SCM windowPollEvent(SCM smob, SCM event)
{
    WindowSmob * s = scmToWindow(smob);
    EventSmob * e = scmToEvent(event);
    if(s->ptr->pollEvent(*(e->ptr)))
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}
SCM windowWaitEvent(SCM smob, SCM event)
{
    WindowSmob * s = scmToWindow(smob);
    EventSmob * e = scmToEvent(event);
    if(s->ptr->waitEvent(*(e->ptr)))
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}
SCM windowGetPosition(SCM smob)
{
    WindowSmob * s = scmToWindow(smob);
    int car = s->ptr->getPosition().x;
    int cdr = s->ptr->getPosition().y;
    return vector2i(car, cdr);
}
SCM windowSetPosition(SCM smob, SCM x, SCM y)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setPosition(sf::Vector2i(scm_to_int(x),
				     scm_to_int(y)));
    return SCM_UNSPECIFIED;
}
SCM windowSetSize(SCM smob, SCM x, SCM y)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setSize(sf::Vector2u(scm_to_int(x),
				 scm_to_int(y)));
    return SCM_UNSPECIFIED;
}
SCM windowSetTitle(SCM smob, SCM title)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setTitle(scm_to_locale_string(title));
    return SCM_UNSPECIFIED;
}
SCM windowSetVisible(SCM smob, SCM visible)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setVisible(scm_is_true(visible));
    return SCM_UNSPECIFIED;
}
SCM windowSetVerticalSync(SCM smob, SCM sync)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setVerticalSyncEnabled(scm_is_true(sync));
    return SCM_UNSPECIFIED;
}
SCM windowSetMouseCursorVisible(SCM smob, SCM visible)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setMouseCursorVisible(scm_is_true(visible));
    return SCM_UNSPECIFIED;
}
SCM windowSetKeyRepeat(SCM smob, SCM rep)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setKeyRepeatEnabled(scm_is_true(rep));
    return SCM_UNSPECIFIED;
}
SCM windowSetFramerateLimit(SCM smob, SCM limit)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setFramerateLimit(scm_to_int(limit));
    return SCM_UNSPECIFIED;
}
SCM windowSetActive(SCM smob, SCM active)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->setActive(scm_is_true(active));
    return SCM_UNSPECIFIED;
}
SCM windowDisplay(SCM smob)
{
    WindowSmob * s = scmToWindow(smob);
    s->ptr->display();
    return SCM_UNSPECIFIED;
}
SCM windowClear(SCM smob, SCM color)
{
    WindowSmob * s = scmToWindow(smob);
    ColorSmob * c = scmToColor(color);
    s->ptr->clear(sf::Color(c->ptr->r,
			    c->ptr->g,
			    c->ptr->b,
			    c->ptr->a));
    return SCM_UNSPECIFIED;
}
SCM windowMapPixelToCoords(SCM smob, SCM x, SCM y)
{
    WindowSmob * s = scmToWindow(smob);
    double car = s->ptr->mapPixelToCoords(sf::Vector2i(scm_to_int(x),
						       scm_to_int(y))).x;
    double cdr = s->ptr->mapPixelToCoords(sf::Vector2i(scm_to_int(x),
						       scm_to_int(y))).y;
    return vector2f(car, cdr);
}
SCM windowMapCoordsToPixel(SCM smob, SCM x, SCM y)
{
    WindowSmob * s = scmToWindow(smob);
    int car = s->ptr->mapCoordsToPixel(sf::Vector2f(scm_to_double(x),
						    scm_to_double(y))).x;
    int cdr = s->ptr->mapCoordsToPixel(sf::Vector2f(scm_to_double(x),
						    scm_to_double(y))).y;
    return vector2i(car, cdr);
}
SCM windowDrawRectangle(SCM smob, SCM rectangle)
{
    WindowSmob * s = scmToWindow(smob);
    RectangleSmob * r = scmToRectangle(rectangle);
    s->ptr->draw(*(r->ptr));
    return SCM_UNSPECIFIED;
}

SCM getMousePosition(SCM smob)
{
    WindowSmob * s = scmToWindow(smob);
    sf::Vector2i v = sf::Mouse::getPosition(*(s->ptr));
    return vector2i(v.x, v.y);
}

void initWindowType()
{
    WindowTag = scm_make_smob_type("Window",
				   sizeof(WindowSmob));
    scm_set_smob_mark(WindowTag, markWindow);
    scm_set_smob_free(WindowTag, freeWindow);
    scm_set_smob_print(WindowTag, printWindow);
    
    scm_c_define_gsubr("window-make", 4, 0, 0,
		       (void *)windowMake);
    scm_c_define_gsubr("window-get-size", 1, 0, 0,
		       (void *)windowGetSize);
    scm_c_define_gsubr("window-create", 5, 0, 0,
		       (void *)windowCreate);
    scm_c_define_gsubr("window-close", 1, 0, 0,
		       (void *)windowClose);
    scm_c_define_gsubr("window-open?", 1, 0, 0,
		       (void *)windowIsOpen);
    scm_c_define_gsubr("window-poll-event!", 2, 0, 0,
		       (void *)windowPollEvent);
    scm_c_define_gsubr("window-wait-event!", 2, 0, 0,
		       (void *)windowWaitEvent);
    scm_c_define_gsubr("window-get-position", 1, 0, 0,
		       (void *)windowGetPosition);
    scm_c_define_gsubr("window-set-position!", 3, 0, 0,
		       (void *)windowSetPosition);
    scm_c_define_gsubr("window-set-size!", 3, 0, 0,
		       (void *)windowSetSize);
    scm_c_define_gsubr("window-set-title!", 2, 0, 0,
		       (void *)windowSetTitle);
    scm_c_define_gsubr("window-set-visible!", 2, 0, 0,
		       (void *)windowSetVisible);
    scm_c_define_gsubr("window-set-vertical-sync!", 2, 0, 0,
		       (void *)windowSetVerticalSync);
    scm_c_define_gsubr("window-set-mouse-cursor-visible!", 2, 0, 0,
		       (void *)windowSetMouseCursorVisible);
    scm_c_define_gsubr("window-set-key-repeated!", 2, 0, 0,
		       (void *)windowSetKeyRepeat);
    scm_c_define_gsubr("window-set-framerate-limit!", 2, 0, 0,
		       (void *)windowSetFramerateLimit);
    scm_c_define_gsubr("window-set-active!", 2, 0, 0,
		       (void *)windowSetActive);
    scm_c_define_gsubr("window-display!", 1, 0, 0,
		       (void *)windowDisplay);
    scm_c_define_gsubr("window-clear!", 2, 0, 0,
		       (void *)windowClear);
    scm_c_define_gsubr("window-map-pixel-to-coords", 3, 0, 0,
		       (void *)windowMapPixelToCoords);
    scm_c_define_gsubr("window-map-coords-to-pixel", 3, 0, 0,
		       (void *)windowMapCoordsToPixel);
    scm_c_define_gsubr("window-draw-rectangle!", 2, 0, 0,
		       (void *)windowDrawRectangle);
    scm_c_define_gsubr("mouse-position", 1, 0, 0,
		       (void *)getMousePosition);
}

#endif	// WINDOW_HPP_
