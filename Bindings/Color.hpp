#ifndef COLOR_HPP_
#define COLOR_HPP_

/* En este archivo se describe e implementa un smob
 * para la clase Color de la libreria SFML 2.1
 */

#include <SFML/Graphics/Color.hpp>
#include <libguile.h>
#include <sstream>

struct ColorSmob
{
    sf::Color * ptr;
};

static scm_t_bits ColorTag;

ColorSmob * scmToColor(SCM smob)
{
    scm_assert_smob_type(ColorTag, smob);
    return (ColorSmob *) SCM_SMOB_DATA(smob);
}

SCM markColor(SCM smob)
{
    return SCM_BOOL_F;
}

size_t freeColor(SCM smob)
{
    ColorSmob * s = scmToColor(smob);
    delete s->ptr;
    scm_gc_free(s, sizeof(ColorSmob), "Color");
    return 0;
}

int printColor(SCM smob, SCM port, scm_print_state * ps)
{
    ColorSmob * s = scmToColor(smob);

    std::ostringstream str;
    str << "#<Color r:" << (int)s->ptr->r
	<< " g:" << (int)s->ptr->g
	<< " b:" << (int)s->ptr->b
	<< " a:" << (int)s->ptr->a << ">";

    scm_puts(str.str().data(), port);
    
    return 1;
}

SCM equalpColor(SCM smob1, SCM smob2)
{
    ColorSmob * s1 = scmToColor(smob1);
    ColorSmob * s2 = scmToColor(smob2);
    if(*(s1->ptr) == *(s2->ptr))
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

SCM colorMake(SCM r, SCM g, SCM b, SCM a)
{
    ColorSmob * s;
    s = (ColorSmob *)scm_gc_malloc(sizeof(ColorSmob),
				   "Color");
    s->ptr = new sf::Color(scm_to_int(r),
			   scm_to_int(g),
			   scm_to_int(b),
			   scm_to_int(a));
    return scm_new_smob(ColorTag, (scm_t_bits)s);
}

SCM colorGetR(SCM smob)
{
    ColorSmob * s = scmToColor(smob);
    return scm_from_int(s->ptr->r);
}

SCM colorGetG(SCM smob)
{
    ColorSmob * s = scmToColor(smob);
    return scm_from_int(s->ptr->g);
}

SCM colorGetB(SCM smob)
{
    ColorSmob * s = scmToColor(smob);
    return scm_from_int(s->ptr->b);
}

SCM colorGetA(SCM smob)
{
    ColorSmob * s = scmToColor(smob);
    return scm_from_int(s->ptr->a);
}

SCM colorSetR(SCM smob, SCM r)
{
    ColorSmob * s = scmToColor(smob);
    s->ptr->r = scm_to_int(r);
    return SCM_UNSPECIFIED;
}

SCM colorSetG(SCM smob, SCM g)
{
    ColorSmob * s = scmToColor(smob);
    s->ptr->g = scm_to_int(g);
    return SCM_UNSPECIFIED;
}

SCM colorSetB(SCM smob, SCM b)
{
    ColorSmob * s = scmToColor(smob);
    s->ptr->b = scm_to_int(b);
    return SCM_UNSPECIFIED;
}

SCM colorSetA(SCM smob, SCM a)
{
    ColorSmob * s = scmToColor(smob);
    s->ptr->a = scm_to_int(a);
    return SCM_UNSPECIFIED;
}

SCM colorAddition(SCM smob1, SCM smob2)
{
    ColorSmob * s1 = scmToColor(smob1);
    ColorSmob * s2 = scmToColor(smob2);
    sf::Color c = *(s1->ptr) + *(s2->ptr);
    return colorMake(scm_from_int(c.r),
		     scm_from_int(c.g),
		     scm_from_int(c.b),
		     scm_from_int(c.a));
}

SCM colorSubtraction(SCM smob1, SCM smob2)
{
    ColorSmob * s1 = scmToColor(smob1);
    ColorSmob * s2 = scmToColor(smob2);
    sf::Color c = *(s1->ptr) - *(s2->ptr);
    return colorMake(scm_from_int(c.r),
		     scm_from_int(c.g),
		     scm_from_int(c.b),
		     scm_from_int(c.a));
}

SCM colorModulation(SCM smob1, SCM smob2)
{
    ColorSmob * s1 = scmToColor(smob1);
    ColorSmob * s2 = scmToColor(smob2);
    sf::Color c = *(s1->ptr) * *(s2->ptr);
    return colorMake(scm_from_int(c.r),
		     scm_from_int(c.g),
		     scm_from_int(c.b),
		     scm_from_int(c.a));
}

SCM colorBlack()
{
    SCM r = scm_from_int(0);
    SCM g = scm_from_int(0);
    SCM b = scm_from_int(0);
    SCM a = scm_from_int(255);
    return colorMake(r, g, b, a);
}

SCM colorWhite()
{
    SCM r = scm_from_int(255);
    SCM g = scm_from_int(255);
    SCM b = scm_from_int(255);
    SCM a = scm_from_int(255);
    return colorMake(r, g, b, a);
}

SCM colorRed()
{
    SCM r = scm_from_int(255);
    SCM g = scm_from_int(0);
    SCM b = scm_from_int(0);
    SCM a = scm_from_int(255);
    return colorMake(r, g, b, a);
}

SCM colorGreen()
{
    SCM r = scm_from_int(0);
    SCM g = scm_from_int(255);
    SCM b = scm_from_int(0);
    SCM a = scm_from_int(255);
    return colorMake(r, g, b, a);
}

SCM colorBlue()
{
    SCM r = scm_from_int(0);
    SCM g = scm_from_int(0);
    SCM b = scm_from_int(255);
    SCM a = scm_from_int(255);
    return colorMake(r, g, b, a);
}

SCM colorYellow()
{
    SCM r = scm_from_int(255);
    SCM g = scm_from_int(255);
    SCM b = scm_from_int(0);
    SCM a = scm_from_int(255);
    return colorMake(r, g, b, a);
}

SCM colorMagenta()
{
    SCM r = scm_from_int(255);
    SCM g = scm_from_int(0);
    SCM b = scm_from_int(255);
    SCM a = scm_from_int(255);
    return colorMake(r, g, b, a);
}

SCM colorCyan()
{
    SCM r = scm_from_int(0);
    SCM g = scm_from_int(255);
    SCM b = scm_from_int(255);
    SCM a = scm_from_int(255);
    return colorMake(r, g, b, a);
}

SCM colorTransparent()
{
    SCM r = scm_from_int(0);
    SCM g = scm_from_int(0);
    SCM b = scm_from_int(0);
    SCM a = scm_from_int(0);
    return colorMake(r, g, b, a);
}

void initColorType()
{
    ColorTag = scm_make_smob_type("Color",
				   sizeof(ColorSmob));
    scm_set_smob_mark(ColorTag, markColor);
    scm_set_smob_free(ColorTag, freeColor);
    scm_set_smob_print(ColorTag, printColor);
    scm_set_smob_equalp(ColorTag, equalpColor);
    
    scm_c_define_gsubr("color-make", 4, 0, 0,
		       (void *)colorMake);
    scm_c_define_gsubr("color-get-r", 1, 0, 0,
		       (void *)colorGetR);
    scm_c_define_gsubr("color-get-g", 1, 0, 0,
		       (void *)colorGetG);
    scm_c_define_gsubr("color-get-b", 1, 0, 0,
		       (void *)colorGetB);
    scm_c_define_gsubr("color-get-a", 1, 0, 0,
		       (void *)colorGetA);
    scm_c_define_gsubr("color-set-r!", 2, 0, 0,
		       (void *)colorSetR);
    scm_c_define_gsubr("color-set-g!", 2, 0, 0,
		       (void *)colorSetG);
    scm_c_define_gsubr("color-set-b!", 2, 0, 0,
		       (void *)colorSetB);
    scm_c_define_gsubr("color-set-a!", 2, 0, 0,
		       (void *)colorSetA);
    scm_c_define_gsubr("color-add", 2, 0, 0,
		       (void *)colorAddition);
    scm_c_define_gsubr("color-sub", 2, 0, 0,
		       (void *)colorSubtraction);
    scm_c_define_gsubr("color-mod", 2, 0, 0,
		       (void *)colorModulation);
    scm_c_define_gsubr("black", 0, 0, 0,
		       (void *)colorBlack);
    scm_c_define_gsubr("white", 0, 0, 0,
		       (void *)colorWhite);
    scm_c_define_gsubr("red", 0, 0, 0,
		       (void *)colorRed);
    scm_c_define_gsubr("green", 0, 0, 0,
		       (void *)colorGreen);
    scm_c_define_gsubr("blue", 0, 0, 0,
		       (void *)colorBlue);
    scm_c_define_gsubr("yellow", 0, 0, 0,
		       (void *)colorYellow);
    scm_c_define_gsubr("magenta", 0, 0, 0,
		       (void *)colorMagenta);
    scm_c_define_gsubr("cyan", 0, 0, 0,
		       (void *)colorCyan);
    scm_c_define_gsubr("transparent", 0, 0, 0,
		       (void *)colorTransparent);
}

#endif // COLOR_HPP_
