#include <iostream>
#include <string>

void printHello(std::string name);

int main() {
    std::string name = "Anna";
    printHello(name);
}

void printHello(std::string name){
    std::cout << "Hello " << name << " this is your first C++ programm... Congratulations!";
}