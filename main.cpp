#include <iostream>

void Log(const char* m);


// this function is declared but not defined anywhere. 
// but observe how as long as its not called anywhere,
// we dont get a "definition not found" linking error.
int lmao(const char* this_is_a_prank); 


int main() {
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

    std::cin.get();

}