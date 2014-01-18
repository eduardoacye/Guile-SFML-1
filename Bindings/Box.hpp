#ifndef BOX_HPP_
#define BOX_HPP_

/* En este archivo se describe e implementa un smob
 * para la clase FloatRect de la libreria SFML 2.1
 */

#include <SFML/Graphics/Rect.hpp>
#include <libguile.h>

struct BoxSmob
{
    sf::FloatRect * ptr;
};

static scm_t_bits BoxTag;

BoxSmob * scmToBox(SCM smob)
{
    scm_assert_smob_type(BoxTag, smob);
    return (BoxSmob *) SCM_SMOB_DATA(smob);
}

SCM markBox(SCM smob)
{
    return SCM_BOOL_F;
}

size_t freeBox(SCM smob)
{
    BoxSmob * s = scmToBox(smob);
    delete s->ptr;
    scm_gc_free(s, sizeof(BoxSmob), "Box");
    return 0;
}

int printBox(SCM smob, SCM port, scm_print_state * ps)
{
    scm_puts("#<Box>", port);
    return 1;
}

SCM equalpBox(SCM smob1, SCM smob2)
{
    BoxSmob * s1 = scmToBox(smob1);
    BoxSmob * s2 = scmToBox(smob2);
    if(*(s1->ptr) == *(s2->ptr))
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

SCM boxMake(SCM l, SCM t, SCM w, SCM h)
{
    BoxSmob * s;
    s = (BoxSmob *)scm_gc_malloc(sizeof(BoxSmob),
				 "Box");
    s->ptr = new sf::FloatRect(scm_to_double(l),
			       scm_to_double(t),
			       scm_to_double(w),
			       scm_to_double(h));
    return scm_new_smob(BoxTag, (scm_t_bits)s);
}

SCM boxGetLeft(SCM smob)
{
    BoxSmob * s = scmToBox(smob);
    return scm_from_double(s->ptr->left);
}

SCM boxGetTop(SCM smob)
{
    BoxSmob * s = scmToBox(smob);
    return scm_from_double(s->ptr->top);
}

SCM boxGetWidth(SCM smob)
{
    BoxSmob * s = scmToBox(smob);
    return scm_from_double(s->ptr->width);
}

SCM boxGetHeight(SCM smob)
{
    BoxSmob * s = scmToBox(smob);
    return scm_from_double(s->ptr->height);
}

SCM boxSetLeft(SCM smob, SCM l)
{
    BoxSmob * s = scmToBox(smob);
    s->ptr->left = scm_to_double(l);
    return SCM_UNSPECIFIED;
}

SCM boxSetTop(SCM smob, SCM t)
{
    BoxSmob * s = scmToBox(smob);
    s->ptr->top = scm_to_double(t);
    return SCM_UNSPECIFIED;
}

SCM boxSetWidth(SCM smob, SCM w)
{
    BoxSmob * s = scmToBox(smob);
    s->ptr->width = scm_to_double(w);
    return SCM_UNSPECIFIED;
}

SCM boxSetHeight(SCM smob, SCM h)
{
    BoxSmob * s = scmToBox(smob);
    s->ptr->height = scm_to_double(h);
    return SCM_UNSPECIFIED;
}

SCM boxContains(SCM smob, SCM x, SCM y)
{
    BoxSmob * s = scmToBox(smob);
    if(s->ptr->contains(scm_to_double(x),
			scm_to_double(y)))
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

SCM boxIntersects(SCM smob1, SCM smob2)
{
    BoxSmob * s1 = scmToBox(smob1);
    BoxSmob * s2 = scmToBox(smob2);
    if(s1->ptr->intersects(*(s2->ptr)))
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

void initBoxType()
{
    BoxTag = scm_make_smob_type("Box",
				sizeof(BoxSmob));
    scm_set_smob_mark(BoxTag, markBox);
    scm_set_smob_free(BoxTag, freeBox);
    scm_set_smob_print(BoxTag, printBox);
    scm_set_smob_equalp(BoxTag, equalpBox);

    scm_c_define_gsubr("box-make", 4, 0, 0,
		       (void*)boxMake);
    scm_c_define_gsubr("box-get-left", 1, 0, 0,
		       (void*)boxGetLeft);
    scm_c_define_gsubr("box-get-top", 1, 0, 0,
		       (void*)boxGetTop);
    scm_c_define_gsubr("box-get-width", 1, 0, 0,
		       (void*)boxGetWidth);
    scm_c_define_gsubr("box-get-height", 1, 0, 0,
		       (void*)boxGetHeight);
    scm_c_define_gsubr("box-set-left!", 2, 0, 0,
		       (void*)boxSetLeft);
    scm_c_define_gsubr("box-set-top!", 2, 0, 0,
		       (void*)boxSetTop);
    scm_c_define_gsubr("box-set-width!", 2, 0, 0,
		       (void*)boxSetWidth);
    scm_c_define_gsubr("box-set-height!", 2, 0, 0,
		       (void*)boxSetHeight);
    scm_c_define_gsubr("box-contains?", 3, 0, 0,
		       (void*)boxContains);
    scm_c_define_gsubr("box-intersects?", 2, 0, 0,
		       (void*)boxIntersects);
}

#endif // BOX_HPP_
