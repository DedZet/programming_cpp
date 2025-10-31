#include "Figure3.h"

std::ostream& operator<<(std::ostream& os, const Figure3& figure) {
    figure.print(os);
    return os;
}

bool Figure3::operator<(Figure3 & figure) {
    return volume() < figure.volume();
}

bool Figure3::operator>(Figure3& figure) {
    return volume() > figure.volume();
}

bool Figure3::operator==(Figure3& figure) {
    return volume() == figure.volume();
}