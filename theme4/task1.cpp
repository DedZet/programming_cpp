#include <iostream>
#include "figure2.h"
#include "figures.h"

using namespace std;

int main()
{
    int const SIZE = 3;
    Figure2* figs[SIZE];

    figs[0] = new Triangle(3, 4, 5);
    figs[1] = new Circle(3);
    figs[2] = new Rectangle(3, 5);

    for (int i = 0; i < SIZE; ++i) {
        cout << *figs[i] << endl;
        cout << figs[i]->perim() << endl;
        cout << figs[i]->square() << endl;
        cout << endl;
    }

    return 0;
}
