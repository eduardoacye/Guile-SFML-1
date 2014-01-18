#ifndef VECTOR_HPP_
#define VECTOR_HPP_

/* En este archivo se describe e implementa un smob
 * para la clase Vector2f de la libreria SFML 2.1
 */

#include <SFML/System/Vector2.hpp>
#include <libguile.h>
#include <sstream>

SCM vector2i(int x, int y)
{
    SCM car = scm_from_int(x);
    SCM cdr = scm_from_int(y);
    return scm_cons(car, cdr);
}

SCM vector2f(int x, int y)
{
    SCM car = scm_from_double(x);
    SCM cdr = scm_from_double(y);
    return scm_cons(car, cdr);
}

SCM vector2u(int x, int y)
{
    SCM car = scm_from_unsigned_integer(x);
    SCM cdr = scm_from_unsigned_integer(y);
    return scm_cons(car, cdr);
}
/*
struct VectorSmob
{
    sf::Vector2f * ptr;
};

static scm_t_bits VectorTag;

VectorSmob * scmToVector(SCM smob)
{
    scm_assert_smob_type(VectorTag, smob);
    return (VectorSmob *) SCM_SMOB_DATA(smob);
}

SCM markVector(SCM smob)
{
    return SCM_BOOL_F;
}

size_t freeVector(SCM smob)
{
    VectorSmob * s = scmToVector(smob);
    delete s->ptr;
    scm_gc_free(s, sizeof(VectorSmob), "Vector");
    return 0;
}

int printVector(SCM smob, SCM port, scm_print_state * ps)
{
    VectorSmob * s = scmToVector(smob);

    std::ostringstream str;
    str << "#<Vector x:" << s->ptr->x
	<< " y:" << s->ptr->y << ">";

    scm_puts(str.str().data(), port);

    scm_remember_upto_here_1(smob);
    return 1;
}

SCM equalpVector(SCM smob1, SCM smob2)
{
    VectorSmob * s1 = scmToVector(smob1);
    VectorSmob * s2 = scmToVector(smob2);

    if(*(s1->ptr) == *(s2->ptr))
	return SCM_BOOL_T;
    else
	return SCM_BOOL_F;
}

SCM vectorMake(SCM x, SCM y)
{
    VectorSmob * s;
    s = (VectorSmob *)scm_gc_malloc(sizeof(VectorSmob),
				    "Vector");
    s->ptr = new sf::Vector2f(scm_to_double(x),
			      scm_to_double(y));
    return scm_new_smob(VectorTag, (scm_t_bits)s);
}

SCM vectorGetX(SCM smob)
{
    VectorSmob * s = scmToVector(smob);
    return scm_from_double(s->ptr->x);
}

SCM vectorGetY(SCM smob)
{
    VectorSmob * s = scmToVector(smob);
    return scm_from_double(s->ptr->y);
}

SCM vectorSetX(SCM smob, SCM x)
{
    VectorSmob * s = scmToVector(smob);
    s->ptr->x = scm_to_double(x);
    return SCM_UNSPECIFIED;
}

SCM vectorSetY(SCM smob, SCM y)
{
    VectorSmob * s = scmToVector(smob);
    s->ptr->y = scm_to_double(y);
    return SCM_UNSPECIFIED;
}

SCM vectorAdditiveInverse(SCM smob)
{
    VectorSmob * s = scmToVector(smob);
    SCM x = scm_from_double(-(s->ptr->x));
    SCM y = scm_from_double(-(s->ptr->y));
    return vectorMake(x, y);
}

SCM vectorAddition(SCM smob1, SCM smob2)
{
    VectorSmob * s1 = scmToVector(smob1);
    VectorSmob * s2 = scmToVector(smob2);
    SCM x = scm_from_double(s1->ptr->x +
			    s2->ptr->x);
    SCM y = scm_from_double(s1->ptr->y +
			    s2->ptr->y);
    return vectorMake(x, y);
}

SCM vectorSubtraction(SCM smob1, SCM smob2)
{
    VectorSmob * s1 = scmToVector(smob1);
    VectorSmob * s2 = scmToVector(smob2);
    SCM x = scm_from_double(s1->ptr->x -
			    s2->ptr->x);
    SCM y = scm_from_double(s1->ptr->y -
			    s2->ptr->y);
    return vectorMake(x, y);
}

SCM vectorMultiplication(SCM smob, SCM num)
{
    VectorSmob * s = scmToVector(smob);
    SCM x = scm_from_double(s->ptr->x *
			    scm_to_double(num));
    SCM y = scm_from_double(s->ptr->y *
			    scm_to_double(num));
    return vectorMake(x, y);
}

SCM vectorDivision(SCM smob, SCM num)
{
    VectorSmob * s = scmToVector(smob);
    SCM x = scm_from_double(s->ptr->x /
			    scm_to_double(num));
    SCM y = scm_from_double(s->ptr->y /
			    scm_to_double(num));
    return vectorMake(x, y);
}
*/

void initVectorType()
{
    /*
    VectorTag = scm_make_smob_type("Vector",
				   sizeof(VectorSmob));
    scm_set_smob_mark(VectorTag, markVector);
    scm_set_smob_free(VectorTag, freeVector);
    scm_set_smob_print(VectorTag, printVector);
    scm_set_smob_equalp(VectorTag, equalpVector);
    
    scm_c_define_gsubr("vector-make", 2, 0, 0,
		       (void*)vectorMake);
    scm_c_define_gsubr("vector-get-x", 1, 0, 0,
		       (void*)vectorGetX);
    scm_c_define_gsubr("vector-get-y", 1, 0, 0,
		       (void*)vectorGetY);
    scm_c_define_gsubr("vector-set-x!", 2, 0, 0,
		       (void*)vectorSetX);
    scm_c_define_gsubr("vector-set-y!", 2, 0, 0,
		       (void*)vectorSetY);
    scm_c_define_gsubr("vector-opposite", 1, 0, 0,
		       (void*)vectorAdditiveInverse);
    scm_c_define_gsubr("vector-add", 2, 0, 0,
		       (void*)vectorAddition);
    scm_c_define_gsubr("vector-sub", 2, 0, 0,
		       (void*)vectorSubtraction);
    scm_c_define_gsubr("vector-mul", 2, 0, 0,
		       (void*)vectorMultiplication);
    scm_c_define_gsubr("vector-div", 2, 0, 0,
		       (void*)vectorDivision);
    
    scm_c_define_gsubr("vector2i", 2, 0, 0,
		       (void*)vector2i);
    scm_c_define_gsubr("vector2f", 2, 0, 0,
		       (void*)vector2f);
    scm_c_define_gsubr("vector2u", 2, 0, 0,
		       (void*)vector2u);
    */
}

#endif // VECTOR_HPP_
