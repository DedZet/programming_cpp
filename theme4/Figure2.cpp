#include "Figure2.h"

std::ostream& operator<<(std::ostream& os, const Figure2& figure) {
    figure.print(os);
    return os;
}
