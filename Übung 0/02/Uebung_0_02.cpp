#include <iostream>

int main() {
    const float pi = 3.14;

    std::cout << pi << "\n";

    const float* const ptrpi = &pi;
    std::cout << pi << "\n";
    std::cout << *ptrpi << "\n";

    int x = 10;
    int* const ptrx = &x;
    std::cout << x << "\n";
    std::cout << *ptrx << "\n";



    //Aenderungen
    //pi = 5.0 nicht erlaubt, pi constante nicht Aenderbar
    // Pointer auf Pi auch nciht 'nderbar da const.

    *ptrx = 20;
    std::cout << x << "\n";
    std::cout << *ptrx << "\n";


    x = 30;
    std::cout << x << "\n";
    std::cout << *ptrx << "\n";
    
    //Aber es muss x sein yb ptrx = &y geht nicht.

}