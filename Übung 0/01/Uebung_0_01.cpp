#include <iostream>
#include <string>

void printHello(std::string name);

int main() {
    std::string name;
    std::cout << "Geben Sie einen Namen ein: ";
    std::getline(std::cin,name);

    if (name.empty()){
        name = "You";
    }
    printHello(name);
}

void printHello(std::string name){
    std::cout << "Hello " << name << "\n" <<"this is your first C++ programm..." << "\n" << "Congratulations!";
}