// PRE PROCESSOR STATEMENTS

// statements starting with an hash are called pre processor statements. they are
// executed before the actual processing and running of the code or anything like
// that happens. #include is one such statement which basically copy pastes the 
// mentioned library or c++ file into our current one.
#include <iostream>

// if the log function is defined in some other file, and it is going to be available to 
// use after linking process of the building stage. Then you can declare such functions
// in your current file so the C++ linter or whatever knows that these functions are
// real and do exist just in some other file. 
void Log(const char* message_to_log); // we're gonnna get to what a const char* is, in some other time.

// C++ needs to have an entry point function. And by default its called "main". I think 
// you can name it something else too, but `main` is the default.
int main() {
    Log("Hello chat"); 
}

// declaring the log function at the start just helps when you're compiling this file by
// itself. to tell the compiler "hey, don't fret this function will be wired and linked up"
// to a definition from some other file during the actual build.
// whether the function is actually defined somewhere or not is not of the matter to the compiler.
// such problems are headache for the linker.

// if the function is not defined anywhere else. linking would fail. you'd get an error.
// although if you dont call the log function. then the linker doesn't bother tryina find its 
// definition.
// this function is declared but not defined anywhere. 
// but observe how as long as its not called anywhere,
// we dont get a "definition not found" linking error.
int lmao(const char* this_is_a_prank); 


int Multiply(int a, int b) {
    Log("Multiplying");
    return a*b;
}

// take the above function definition. assume that this multiply function is not called.
// and the log function is not defined anywhere in any file. even if multiply is never called,
// the linker would still complain about log not being defined because even though we're not 
// calling the multiply function here in this file, it thinks "what if it will be necessary in 
// some other file?" and thus complains about the log function in the definition not being defined.
// you would get a linking error. it doesn't just remove the function entirely because its "dead 
// code that isn't used."

// what if we could tell the linker "hey this multiply function is only declared for this translation unit
// so dont bother making room for call of multiply function in other files." you can! use ths static keyword

static int multiply(int a, int b) {
    Log("Multiplying");
    return a*b;
}

// do note. if the return type of declaration vs definition is different it doesn't seem to be a problem.
// but if the parameters taken by the function are different then there will be a linking error. 
// - names of parameters can be different but the type and amount and stuff technical jargon must match.



// FROM HERE ASSUME LOG FUNCTION IS PUT IN A log.h NAMED FILE
// other type of linking error super common is when we have duplicate symbols. i.e. same functions 
// or variables with same name and same signature. so two identically named functions with 
// same return and parameters.

// it appears compilers work before linkers. so first every translation unit (file) is first compiled 
// individually and then the linker does its wiring. so if the duplicate definition is in the same
// file then the compiler will weed it out and save you before the linking happens. but if the same
// function is defined in multiple translation units, then during the linking process the linker 
// will spit out an error since it doesn't know which compiled file has the correct definition.

// such a problem would also have showed up if you used #include to simply bring in the log definition
// into whatever file you need to use it. cuz remember #include is just copy paste. so if you used 
// #include "log.cpp" or "log.h" or whatever, then the definition would just get copy pasted into
// your file. and you're going to have multiple definitions.

// to fix this you can add `static` in the definition. cuz the static function basically then becomes
// a function strictly confined to the translation unit, and all its linking would happen internally. 
// so multiple files having the same function defined doesn't ache if they're static.

// another such keyword is `inline`. 


// IMAGINE THIS FUNCTION DEFINITION WAS IN LOG.CPP, NOT HERE.
inline int AnotherLog(const char* string_of_chracters_to_log) {
    std::cout << string_of_chracters_to_log << std::endl;
}

// now this function that i have just defined will work similarly to #include.
// while runtime, when this function is called, then the compilation line, instead of 
// going to the definition of the function and then execution happening there,
// the definition contents of the function will simply be cophy pasted to where the function
// was called and then the execution will happen in that place.
// "it simply takes our function body and replaces the call with it"

// and it seems for some reason that doesn't give any errors either 


// im back
// okay so it seems header files are not actually included in the compilation or linking process. 
// they exist purely to be `#include`'d into some cpp file of yours. 

// the ideal way to deal with this dupe problem potential, or at least the standard convention,
// is to simply declare the function in the header file and then later put the actual definition
// in some cpp file. so in our case, put a declaration in `log.h`, actual defintion in `log.cpp`. and
// then (tutorial or main).cpp and log.cpp can both #include the log.h header file. and what they'd include
// would simply be the declaration. and same declarations across multiple files dont cause problems (obviously)
// the actual definition will be found by the linker in the log.cpp file.








// VARIABLES
// im sure you already know what a variable is, we're gonna jump straight to data types in c++ 
// "Really the only main difference between variable primitive data tpyes is how much memory they occupy"
// cuz in C++ theres no set rules, you can be very flexible with what sort of data type you choose to use
// for what sort of data. but still lets look at some exmaples of variable types;

int primitive_variables() {
    
    int an_integer_variable = 8; // int data type is 4 bytes large typically. but it depends on the compiler. 
    // this is a signed integer. you can go from about -2b to +2b

    std::cout << an_integer_variable << std::endl;
    an_integer_variable = 20;
    std::cout << an_integer_variable << std::endl;

    // signed integers are 4 bytes -> 32 bits. one bit reserved for sign, thus only 31 bits remaining for the 
    // actual number. 2.1... something billion is the biggest number you can store in 31 bits, thus the limit.
    // you can however use all 32 bits if you choose to make the integer an unsigned integer. 

    unsigned int unsigned_number;
    unsigned_number = 2200000000; // wont give error. we have full 32 bits, thus a bigger limit

    // anyway so how many types are there? as far as int we have:
    char one; // one byte of data.
    short two; // two bytes
    int three; // four
    long four; // also four usually depending on compiler
    long long five; // eight bytes of data. 
    // you can also use "unsigned" with any one of these.

    // char is also traditionally used for storing characters not just numbers. 
    // so other than numbers like 12 you can also store characters like 'A';
    // you can assign character to other integers too. cuz remember,
    // characters are also just numbers for computers you know. (eg. 'A' = 65) 
    // so why is it called char? well its for programmer assumptions 
    // if we set 
    char one = 65;
    // now if we print it out using cout, you wont get the number, but the actual
    // character. similarly if we assign 'A' to a short or int, it will print out
    // 65 the number. so thats what chars are for. you can assign anything to any
    // type so long as the memory is enough. the datatype just defines what sort of 
    // memory it is assumed to be. 

    // DECIMALS
    // for that we have
    float one; // occupies four bytes of data 
    double two; // eight bytes.

    float one = 43.2f; // in C++ you have to suffix the number with 'f' otherwise C++ sees it as double not float.
    double two = 34.2;

    // these were the primitive types. thats because all other data types are created using these.
    // you can also create your own datatypes using these. they're the building blocks, the base.
    

    // points and references
    // suffix data type with asterisk for pointer, ampersand for reference.
    //int* lmao;
    //float& what; // gives error
    //char& what = 1; this may be wrong. we'll go into details some other time for these two concepts
    // (they're way too deep)

}



// FUNCTIONS
// functions are basically blocks of codes. in classes they would be called methods but we'll talk about them later
// functions just help avoid the need to copy paste too much 

int functionreal(int a, int b) {
    // im pretty sure most of this is intuitive so i wont blabber.
    return a * b;
}

int main() {
    int x = functionreal(2, 4);
}


// although remember having functions are not for every line of code. when you call a function, beneath the hood,
// theres like some call stack or something created and paramters are passed and it all takes slightly extra
// processing time.

// a function which is supposed to reutrn something (eg int) must return that thing back. otherwise you'll get error.
// main functiono is the only function exempt from this, if you dont return anything C++ assumes it returns 0.


// HEADER FILES

// Header files are basically just C++ files which purely exist for the fate of being included in the primary file. 
// traditionally they're used for storing the declarations of functions and variables and such.
// actual definitions being in some cpp file, and its declaration in some header file so the header file 
// can be included into other cpp files.

// e.g. let the following code belong to a file named "log.h"

void InitLog();
void Log(const char* message_to_log);

struct Player {};

int death;

// now you can include this log.h into your main.cpp and maybe define the functions initlog, log, 
// in some other file named "other.cpp" or something. at build, first compiling happens.
// so when main.cpp is compiled, and it calls functions like "log" which are defined in other.cpp, 
// it would give error if no declaration of log() is found in the file main.cpp. thus we could include
// log.h in main.cpp so the declarations are there, and the compiling succeeds. then once both main.cpp
// and other.cpp are compiled, the linker will link the definitions in other.cpp to the declarations in
// main.cpp which were added due to the include of log.h.

// we also use this `#pragma once` pre processor statement in header files. it basically ensures that the
// header file is not accidentally included twice in the same file. it does NOT prevent us from including it 
// in multiple files, just from including it more than once in the same file.
/*
#pragma once

void InitLog();
void Log(const char* message_to_log);

struct Player {};

int death;
*/

// before `#pragma once`, another popular method of achieving this security was
// using a preprocessor statement called "ifndef" which basically checks if a 
// variable is defined or not. as following:
/*

#ifndef _LOG_H
#define _LOG_H

void InitLog();
void Log(const char* message_to_log);

struct Player {};

int death;

#endif

*/ 
// what this will do is it will check if some definition named "_LOG_H" exists in the file or not. 
// if it does not, it defines the definition and then the declarations happen.
// however, if it does not exist, then `#ifndef _LOG_H` will become false, and what it will do is 
// completely ignore all lines of code between the if and endif. effectively rendering the declarations
// gone. removed.

// (remember pre-processor statements work right before the compilation step happens), and so far their 
// job is just to decide whether given lines of code get included in the compilation process or not.

// ifndef and pragma are both technically the same in their purpose but pragma once looks cleaner.


// another thing is sometimes we use quotes while including and sometimes we use triangle brackets.
// #include 'Log.h'
// #include <iostream>
// well, stuff like 'iostream' and some other common libraries and header files come with your C++ installation.
// and these files are stored somewhere when you install C++ compiler on your computer. that location is called
// "includepath"
// so you use angular brackets when you want to include stuff form that includepath. however if you have another file
// that you made yourself along side the current main.cpp or whatever, in the "current working directory", then
// you use quotes to include the file. 
// you can also use relative paths in quotes. (e.g. `#include ""../headers/help.h"`)
// something interesting is `#include "iostream"` also works, you can also put in relative paths to the includepath,
// so technically quotes work for everything, but triangle brackets are used by convention for includepath stuff (it seems)
// idk we'll go into more details on include rules some other time.

// also why dont we type iostream.h when including it? well because the file itself is just named iostream, without the h.
// it seems like some convention. these "standard library" files for C++ lack the .h suffix. but the ones for C do have the
// .h suffix, so i guess its like some soft way to differentiate the two standard library files. (e.g. 'stdlib.h' is of C, but
// 'iostream' is of C++)
