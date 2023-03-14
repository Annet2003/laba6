#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <locale.h>
#include "Point2D.h"
#include "tmp.h"
#include "Characters.h"
#include "Arena.h"

using namespace std; 

int main() {
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");
    int z;
    cout << "Enter a name for your prey: ";
    string name, name1;
    cin >> name;
    cout << "Enter a name for your predator: ";
    cin >> name1;
    Prey prey(name, Point2D(1, 1));
    Predator predator(name1, Point2D(7, 1));
    cout << "За кого хотите играть? (0-жертва, 1-хищник)" << endl;
    cin >> z;

    Arena arena(10, 10, &prey, &predator);
    cout << arena << endl;

    while (1) {
        if (z == 0) // сторона, за которую играем
        {
            if (check(prey, predator)) 
            { // предатор делает движение
                predator.MoveTo(prey.getx(), prey.gety());

                cout << arena;
                cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
                return 0;
            }
            else {
                prey.AutoMove(arena, z);
                predator.AutoMove(arena, z);
                cout << arena << endl;
            }
        }
        else {
            if (check1(prey, predator)) {
                cout << "\n!!!!!! ХИЩНИК ПОБЕДИЛ !!!!!!" << endl;
                return 0;
            }
            else {
                prey.AutoMove(arena, z);
                predator.AutoMove(arena, z);
                cout << arena << endl;
            }
        }
    }

    return 0;
}