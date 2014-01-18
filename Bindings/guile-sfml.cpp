#include <iostream>
#include <libguile.h>

#include "Vector.hpp"
#include "Color.hpp"
#include "Box.hpp"
#include "Rectangle.hpp"
#include "Event.hpp"
#include "Window.hpp"

extern "C" {
void init_sfml()
{
    initVectorType();
    initColorType();
    initBoxType();
    initRectangleType();
    initEventType();
    initWindowType();
}
}
