#include <iostream>
#include "Figure3.h"
#include "volumetric_figures.h"

using namespace std;

int main()
{
    int const SIZE = 3;
    Figure3* figs[SIZE];

    figs[0] = new Cube(2);
    figs[1] = new Sphere(3);
    figs[2] = new Cylinder(4, 5);

    for (int i = 0; i < SIZE; ++i) {
        cout << *figs[i] << endl;
        cout << "V = " << figs[i]->volume() << endl;
        cout << "S = " << figs[i]->surface() << endl;
        cout << endl;
    }

    cout << *figs[0] << " < " << *figs[1] << endl;
    if (figs[0] < figs[1]) cout << "True\n";
    else cout << "False\n";

    return 0;
}
