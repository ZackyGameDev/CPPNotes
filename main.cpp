#include <iostream>
#include <cstring>
#include "log.h"
#define LOG(x) std::cout << x << std::endl

void Log(const char* m);


// this function is declared but not defined anywhere. 
// but observe how as long as its not called anywhere,
// we dont get a "definition not found" linking error.
int lmao(const char* this_is_a_prank); 

void generalStuff() {
    std::cout << "What am I even doing at this point" << std::endl;

    Log("This log function is defined in the log.cpp file");

    int x = 5;

    bool comparisionResult = x == 5;

    if (comparisionResult) {
        Log("Real");
    }


    const char* ptr = "hello";
    const char* nptr = nullptr;

    if (ptr) Log(ptr);
    if (nptr) Log(nptr);
    else Log("nptr is null");
}

void pointerLore() {
    int my_var = 8764;
    // now we have a variable.
    // now that variable must have some memory address. we can get it with a `&`
    void* ptr = &my_var; // now &my_var is the address of my_var

    LOG(ptr);
    LOG(my_var);

    LOG("HEAP STACK BIT");
    char* pointer = new char[8];
    LOG(pointer);
    memset(pointer, 0, 8);
    LOG(pointer);
    delete[] pointer;
    LOG(pointer);

}

struct Entity {
    int x, y;

    void Print() {
        std::cout << x << ", " << y << std::endl;
    }

};

void staticstuff() { 
    Entity e;
    e.x = 2;
    e.y = 3;

    Entity e2 = { 4, 5};
    e.Print();
    e2.Print();
}

void enums() {
    Logger log;
    log.setLevel(Logger::LevelInfo);
    log.warn("Lamo");
    log.error("error");
    log.info("Info");
}

int main() {
    // generalStuff();
    enums();

    
    sizeof("testing");
    int lma = "testing";
    
    std::cin.get();
}
