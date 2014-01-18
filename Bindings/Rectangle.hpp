#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

/* En este archivo se describe e implementa un smob
 * para la clase RectangleShape de la libreria SFML 2.1
 */

#include <SFML/Graphics/RectangleShape.hpp>
#include <libguile.h>
#include "Vector.hpp"
#include "Box.hpp"
#include "Color.hpp"

struct RectangleSmob
{
    sf::RectangleShape * ptr;
};

static scm_t_bits RectangleTag;

RectangleSmob * scmToRectangle(SCM smob)
{
    scm_assert_smob_type(RectangleTag, smob);
    return (RectangleSmob *) SCM_SMOB_DATA(smob);
}

SCM markRectangle(SCM smob)
{
    return SCM_BOOL_F;
}

size_t freeRectangle(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    delete s->ptr;
    scm_gc_free(s, sizeof(RectangleSmob), "Rectangle");
    return 0;
}

int printRectangle(SCM smob, SCM port, scm_print_state * ps)
{
    scm_puts("#<Rectangle>", port);
    return 1;
}

SCM rectangleMake(SCM w, SCM h)
{
    RectangleSmob * s;
    s = (RectangleSmob *)scm_gc_malloc(sizeof(RectangleSmob),
				       "Rectangle");
    float width = scm_to_double(w);
    float height = scm_to_double(h);
    s->ptr = new sf::RectangleShape(sf::Vector2f(width,height));
    return scm_new_smob(RectangleTag, (scm_t_bits)s);
}

SCM rectangleGetSize(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    //SCM width = scm_from_double(s->ptr->getSize().x);
    //SCM height = scm_from_double(s->ptr->getSize().y);
    //return vectorMake(width, height);
    return vector2f(s->ptr->getSize().x,s->ptr->getSize().y);
}

SCM rectangleSetSize(SCM smob, SCM w, SCM h)
{
    RectangleSmob * s = scmToRectangle(smob);
    float width = scm_to_double(w);
    float height = scm_to_double(h);
    s->ptr->setSize(sf::Vector2f(width, height));
    return SCM_UNSPECIFIED;
}

SCM rectangleGetPointCount(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    unsigned int pc = s->ptr->getPointCount();
    return scm_from_unsigned_integer(pc);
}

SCM rectangleGetPoint(SCM smob, SCM index)
{
    RectangleSmob * s = scmToRectangle(smob);
    unsigned int i = scm_to_int(index);
    //SCM x = scm_from_double(s->ptr->getPoint(i).x);
    //SCM y = scm_from_double(s->ptr->getPoint(i).y);
    //return vectorMake(x, y);
    return vector2f(s->ptr->getPoint(i).x,
		    s->ptr->getPoint(i).y);
}

SCM rectangleSetFillColor(SCM smob, SCM color)
{
    RectangleSmob * s = scmToRectangle(smob);
    ColorSmob * c = scmToColor(color);

    s->ptr->setFillColor(sf::Color(c->ptr->r,
				   c->ptr->g,
				   c->ptr->b,
				   c->ptr->a));
    
    return SCM_UNSPECIFIED;
}

SCM rectangleSetOutlineColor(SCM smob, SCM color)
{
    RectangleSmob * s = scmToRectangle(smob);
    ColorSmob * c = scmToColor(color);

    s->ptr->setOutlineColor(sf::Color(c->ptr->r,
				      c->ptr->g,
				      c->ptr->b,
				      c->ptr->a));
    
    return SCM_UNSPECIFIED;
}

SCM rectangleSetOutlineThickness(SCM smob, SCM num)
{
    RectangleSmob * s = scmToRectangle(smob);
    s->ptr->setOutlineThickness(scm_to_double(num));
    return SCM_UNSPECIFIED;
}

SCM rectangleGetFillColor(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    int r = s->ptr->getFillColor().r;
    int g = s->ptr->getFillColor().g;
    int b = s->ptr->getFillColor().b;
    int a = s->ptr->getFillColor().a;
    
    return colorMake(scm_from_int(r),
		     scm_from_int(g),
		     scm_from_int(b),
		     scm_from_int(a));
}

SCM rectangleGetOutlineColor(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    int r = s->ptr->getOutlineColor().r;
    int g = s->ptr->getOutlineColor().g;
    int b = s->ptr->getOutlineColor().b;
    int a = s->ptr->getOutlineColor().a;
    
    return colorMake(scm_from_int(r),
		     scm_from_int(g),
		     scm_from_int(b),
		     scm_from_int(a));
}

SCM rectangleGetOutlineThickness(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    return scm_from_double(s->ptr->getOutlineThickness());
}

SCM rectangleGetLocalBounds(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    sf::FloatRect r = s->ptr->getLocalBounds();
    
    return boxMake(scm_from_double(r.left),
		   scm_from_double(r.top),
		   scm_from_double(r.width),
		   scm_from_double(r.height));
}

SCM rectangleGetGlobalBounds(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    sf::FloatRect r = s->ptr->getGlobalBounds();
    
    return boxMake(scm_from_double(r.left),
		   scm_from_double(r.top),
		   scm_from_double(r.width),
		   scm_from_double(r.height));
}

SCM rectangleSetPosition(SCM smob, SCM x, SCM y)
{
    RectangleSmob * s = scmToRectangle(smob);
    s->ptr->setPosition(scm_to_double(x),
			scm_to_double(y));
    return SCM_UNSPECIFIED;
}

SCM rectangleSetRotation(SCM smob, SCM angle)
{
    RectangleSmob * s = scmToRectangle(smob);
    s->ptr->setRotation(scm_to_double(angle));
    return SCM_UNSPECIFIED;
}

SCM rectangleSetScale(SCM smob, SCM x, SCM y)
{
    RectangleSmob * s = scmToRectangle(smob);
    s->ptr->setScale(scm_to_double(x),
		     scm_to_double(y));
    return SCM_UNSPECIFIED;
}

SCM rectangleSetOrigin(SCM smob, SCM x, SCM y)
{
    RectangleSmob * s = scmToRectangle(smob);
    s->ptr->setOrigin(scm_to_double(x),
		      scm_to_double(y));
    return SCM_UNSPECIFIED;
}

SCM rectangleGetPosition(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    //SCM x = scm_from_double(s->ptr->getPosition().x);
    //SCM y = scm_from_double(s->ptr->getPosition().y);
    //return vectorMake(x, y);
    return vector2f(s->ptr->getPosition().x,
		    s->ptr->getPosition().y);
}

SCM rectangleGetRotation(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    return scm_from_double(s->ptr->getRotation());
}

SCM rectangleGetScale(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    //SCM x = scm_from_double(s->ptr->getScale().x);
    //SCM y = scm_from_double(s->ptr->getScale().y);
    //return vectorMake(x, y);
    return vector2f(s->ptr->getScale().x,
		    s->ptr->getScale().y);
}

SCM rectangleGetOrigin(SCM smob)
{
    RectangleSmob * s = scmToRectangle(smob);
    //SCM x = scm_from_double(s->ptr->getOrigin().x);
    //SCM y = scm_from_double(s->ptr->getOrigin().y);
    //return vectorMake(x, y);
    return vector2f(s->ptr->getOrigin().x,
		    s->ptr->getOrigin().y);
}

SCM rectangleMove(SCM smob, SCM x, SCM y)
{
    RectangleSmob * s = scmToRectangle(smob);
    s->ptr->move(scm_to_double(x), scm_to_double(y));
    return SCM_UNSPECIFIED;
}

SCM rectangleRotate(SCM smob, SCM angle)
{
    RectangleSmob * s = scmToRectangle(smob);
    s->ptr->rotate(scm_to_double(angle));
    return SCM_UNSPECIFIED;
}

SCM rectangleScale(SCM smob, SCM x, SCM y)
{
    RectangleSmob * s = scmToRectangle(smob);
    s->ptr->scale(scm_to_double(x),scm_to_double(y));
    return SCM_UNSPECIFIED;
}

void initRectangleType()
{
    RectangleTag = scm_make_smob_type("Rectangle",
				   sizeof(RectangleSmob));
    scm_set_smob_mark(RectangleTag, markRectangle);
    scm_set_smob_free(RectangleTag, freeRectangle);
    scm_set_smob_print(RectangleTag, printRectangle);
    //scm_set_smob_equalp(RectangleTag, equalpRectangle);

    scm_c_define_gsubr("rectangle-make", 2, 0, 0,
		       (void *)rectangleMake);
    scm_c_define_gsubr("rectangle-get-size", 1, 0, 0,
		       (void *)rectangleGetSize);
    scm_c_define_gsubr("rectangle-set-size!", 3, 0, 0,
		       (void *)rectangleSetSize);
    scm_c_define_gsubr("rectangle-get-point-count", 1, 0, 0,
		       (void *)rectangleGetPointCount);
    scm_c_define_gsubr("rectangle-get-point", 2, 0, 0,
		       (void *)rectangleGetPoint);
    scm_c_define_gsubr("rectangle-set-fill-color!", 2, 0, 0,
		       (void *)rectangleSetFillColor);
    scm_c_define_gsubr("rectangle-set-outline-color!", 2, 0, 0,
		       (void *)rectangleSetOutlineColor);
    scm_c_define_gsubr("rectangle-set-outline-thickness!", 2, 0, 0,
		       (void *)rectangleSetOutlineThickness);
    scm_c_define_gsubr("rectangle-get-fill-color", 1, 0, 0,
		       (void *)rectangleGetFillColor);
    scm_c_define_gsubr("rectangle-get-outline-color", 1, 0, 0,
		       (void *)rectangleGetOutlineColor);
    scm_c_define_gsubr("rectangle-get-outline-thickness", 1, 0, 0,
		       (void *)rectangleGetOutlineThickness);
    scm_c_define_gsubr("rectangle-get-local-bounds", 1, 0, 0,
		       (void *)rectangleGetLocalBounds);
    scm_c_define_gsubr("rectangle-get-global-bounds", 1, 0, 0,
		       (void *)rectangleGetGlobalBounds);
    scm_c_define_gsubr("rectangle-set-position!", 3, 0, 0,
		       (void *)rectangleSetPosition);
    scm_c_define_gsubr("rectangle-set-rotation!", 2, 0, 0,
		       (void *)rectangleSetRotation);
    scm_c_define_gsubr("rectangle-set-scale!", 3, 0, 0,
		       (void *)rectangleSetScale);
    scm_c_define_gsubr("rectangle-set-origin!", 3, 0, 0,
		       (void *)rectangleSetOrigin);
    scm_c_define_gsubr("rectangle-get-position", 1, 0, 0,
		       (void *)rectangleGetPosition);
    scm_c_define_gsubr("rectangle-get-rotation", 1, 0, 0,
		       (void *)rectangleGetRotation);
    scm_c_define_gsubr("rectangle-get-scale", 1, 0, 0,
		       (void *)rectangleGetScale);
    scm_c_define_gsubr("rectangle-get-origin", 1, 0, 0,
		       (void *)rectangleGetOrigin);
    scm_c_define_gsubr("rectangle-move!", 3, 0, 0,
		       (void *)rectangleMove);
    scm_c_define_gsubr("rectangle-rotate!", 2, 0, 0,
		       (void *)rectangleRotate);
    scm_c_define_gsubr("rectangle-scale!", 3, 0, 0,
		       (void *)rectangleScale);
}

#endif // RECTANGLE_HPP_
