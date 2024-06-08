#include "locomotive.h"

void Locomotive::shift_x(int a) {
    body->shift_x(a);
    pipe->shift_x(a);
    cabine->shift_x(a);
    wheel1->shift_x(a);
    wheel2->shift_x(a);
    wheel3->shift_x(a);
    smoke->shift_x(a);
}

int Locomotive::get_left_x() {
    return body->get_left_x();
}

void Locomotive::reset_position_x(int x) {
    body->reset_position_x(x);
    pipe->reset_position_x(x);
    cabine->reset_position_x(x);
    wheel1->reset_position(x);
    wheel2->reset_position(x);
    wheel3->reset_position(x);
    smoke->reset_position_x(x);
}

