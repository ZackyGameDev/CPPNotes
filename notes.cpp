// PRE PROCESSOR STATEMENTS

// statements starting with an hash are called pre processor statements. they are
// executed before the actual processing and running of the code or anything like
// that happens. #include is one such statement which basically copy pastes the 
// mentioned library or c++ file into our current one.
#include <iostream>

#include <cstring> // just including this for memset funciton for pointers bit
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
inline void AnotherLog(const char* string_of_chracters_to_log) {
    std::cout << string_of_chracters_to_log << std::endl;
}

// now this function that i have just defined will work similarly to #include.
// while runtime, when this function is called, then the compilation line, instead of 
// going to the definition of the function and then execution happening there,
// the definition contents of the function will simply be copy pasted to where the function
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

void primitive_variables() {
    
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

    // minor last tidbit, bool is a 1 byte data type. but it only stores true or false, why does it need more than
    // 1 bit? well, it doesn't. it just uses 1 byte because its more easier to allocate than a single bit. 

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



// BRANCHING AND CONDITIONS 

// In C++ when we use stuff like if else, its called branches.
// because when our final compiled machine code is running, an if statement,
// kinda involves jumping from one place to another in memory where your entire program is loaded.
// thats why if statements are kinda slow, and using too many if statemtsn and branching is not ideal,
// but computers are fast so we dont need to worry about that at small scale.
// also we'll go into more detail about this some other time, right now lets just go over simple if statement.

int ifstatements() {
    int x = 5;
    // now i wanna cout something only of x is equal to 5. to check that we do something called
    // a COMPARISION.
    // its basically like python.
    bool conditionresult = x == 5;
    // the result of x == 5 will be stored into `condition` variable. double equal sign being equality operator.
    // remember, all operators under the hood are just functions. the reason the operator works the way it does is
    // because its been overloaded in the C standard library. in other words some dude must've written a function
    // like "im gonna accept two integers and check their memory to check if they're true, and if yes then i'll 
    // return true, else false." and that was equality operator.

    // now to finally plug it into an if statement,
    if (conditionresult == true) {} // you could do this, theres nothing wrong. 
    // but its kinda unnecessary because all `if` does is check if theres "true" in front of it or not.
    // if there isn't true or false or anythng, it evaluates whatever you give to it and then checks if after
    // evaluating it gets true or false. right now what would happen is if statement would evaluate (conditionresult == true)
    // and then get "true". but remember the conditionresult variable is already a boolean. it itself is true or false, so you can 
    // directly just type it without any extra comparision.
    if (conditionresult) {} // also works (lot clearner too)
    // now what to do after the condition is true? where to branch to? thats what you write in the curly bracket.

    if (conditionresult) {
        std::cout << "real";
    }

    // if condition is false, the lines insidee the curly brackets are completely skipped over.

    // a more in depth explanation at x86 assembly level can be found at:
    // https://youtu.be/qEgCT87KOfc?t=433

    
    // also if your if body is a single line, then you dont need curly brackets.

    if (conditionresult) std::cout << "This is single line if";

    if (conditionresult) 
        std::cout << "This is single line if";
    // both are okay, indentation doesnt matter in C++ whatsoever.


    // also behind the hood what if statement actually checks is "is the given value 0 or not". 0 is considered false, 
    // EVERYTHING ELSE is considered true. kinda non intuitive i know, but thats how it works at technical level.
    // for that exact reason, the following code is perfectly okay and the if statement condition check will succeed. 
    const char c = 'H';

    if (c) Log("Real");
    // this will log "Real" because ptr is not equal to 0. and hence the if statement will evaluate as true.

    // another common use of this property is to check if pointers are null or not. 
    const char* ptr = "Hello there";
    if (ptr) Log(ptr);
    // if pointer was null, ptr = 0, and would be false. dont worry too much we'll study pointers later in detail
    // some other time. 

    const char* ptr = "hello";
    if (ptr)    
        Log(ptr);
    else if (ptr == "hello")
        Log("ptr is hello!");
    else
        Log("Ptr is null!");
    
    // observe how above, the else if bit will never be executed cuz of the logic chain. 
    // also theres no "elif" in C++ like python, the else if here is actually cleverly hidden
    // syntax, we're basically putting another if statement branch in an else block
    // below is what the whole thing would look like if we used proper curly brackets for everything.
    const char* ptr = "hello";
    if (ptr) {    
        Log(ptr);
    } else {
        if (ptr == "hello") {
            Log("ptr is hello!");
        } else {
            Log("Ptr is null!");
        }
    } 
    
    // i have a feeling my way of writing `} else {` in a single line would make a C++ veteran really upset...

}



void loops() {

    // heres what a simple for loop looks like
    for (int i = 0; i < 5; i++) {
        Log("henlo");
    }

    // syntax:
    // for (pre; condition; post) {}
    // the "pre" is code to evaluate right before the first iteration. 
    // the 'condition' is evaluated right before the start of every iteration.
    // the 'post' is evaluated at the END of every iteration.
    // 'i' is used as convention theres no need to stick to that single letter. or any convention in general.
    // the way the loop works is firstly the 'pre' is executed. then the looping starts. and C++ will check if the 
    // 'condition' bit is false. if it is false/0, then it skips the iteration and jumps to 'post'. otherwise
    // the code inside the for loop is executed once, and then it checks again. the process repeats.
    // the for loop above is behavioraly same as the one below:
    int i = 0;
    for ( ; i < 5; ) {
        Log("henlo");
        i++;
    }
    
    // the for loop above is ALSO behavioraly same as the one below:
    int i = 0;
    bool condition = true;
    for ( ; condition; ) {
        Log("henlo");
        i++;
        if (!(i<5)) 
            condition = false;
    }
    // remember all for loop checks for the condition is if it is false or not. if you dont put anything there,
    // obviously that means you didnt put false there, and thus that counts as true. and the for loop will never stop.
    // and keep going infinitely.


    // WHILE LOOP
    // while loops are similar to for but without the pre and post bits.
    int i = 0;
    while (i < 5) {
        Log("henlo");
        i++;
    }
    // above while loop is behavioraly same as the for loop we wrote above.
    // so which one you wanna use depends on your style and preference and needs.
    // technically they both do the same thing, which is just loop over some code
    // with some given stop condition.

    // theres also do-while, which is similar to while, except the stop condition is checked AFTER the iteration.
    // so even if the condition is false from the start, the code body will run AT LEAST ONCE no matter what. 

    int i = 0;
    do {
        Log("hello");
        i++;
    } while (i < 5);
    // above will print "hello" FIVE TIMES, just like for and while above, however its different functionally because the 
    // checking is happening after the code. here i will be 1, 2, 3, 4, 5. for `for` and `while`, i was 0, 1, 2, 3, 4.

}


void controlFlow() {
    // theres continue, break and return. 

    // continue basically asks the loop to move on to the next iteration and skip whatever remaining code there
    // was in current iteration.
    // note that this does not skip the condition checking part or anything, its kinda just a "alright, we're done with
    // this iteration, move on from this one"

    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0)     
            continue;
        Log("checking continue");
    } // logs 1 and 3 only


    // `break` is the same except if you use break its like a complete stop. no consequent iterations happen
    // no matter how much looping was left. the moment you say `break`, its OVER for that loop. instant quit.

    // return works with functions, no loops. whenever you type return (something); the something value is returned by the funciton
    // im not gonna go into more details since its practically exact same as python.
    // only difference being if you type return without any value like `return;` then by default `void` is returned.

    // return can be written anywhere and it instantly ends the function.
}


#define LOG(x) std::cout << x << std::endl


// its time

void POINTERS() {


    // what memory is
    // - now, popular metaphor, you gotta imagine theres a street. 
    // the street has no branches or alternate paths or anything whatsoever.
    // its just a really really long street, with a start, and an end. 
    // now imagine on one, and ONLY one side of the street, has houses, many many houses,
    // all of them next to each other line by line, facing the street.
    // that's what computer memory is. memory is just a one dimensional really huge strip.
    // imagine each house represents one byte of memory. each of these houses have a unique
    // "address", and thats what a pointer is. its just an integer, which is the address to some byte in memory.

    // memory is super important cuz theres lots of writing and reading memory involved, basically in every program ever.
    // i mean when you run your program your entire program gets loaded into your memory to begin with.
    // a pointer, is just an address. its an integer, which holds a memory address.
    // "types" of pointers dont matter in technicality, they're completely meaningless fictional stuff we've
    // created to make our lives easier. just know a pointer is just AN INTEGER THAT HOLDS AN ADDRESS.

    // when we do give datatypes to our pointers, that just means that whatever value the pointer holds the address of,
    // is presumably the given datatype. but the pointers themselves are just integers. we just use types with pointers to
    // make our lives easier in syntax, but they dont change what the pointer itself is, its still just an integer that holds
    // an address.

    // lets make a pointer

    void* pointer = 0; //(void just means it points to a typeless value, or the type could be anything)
    // now make sure you know 0 is not an actual proper pointer, you cant actually access memory all the way at 0 position,
    // we've given this pointer a memory address of zero but memory addresses dont go all the way down to zero, its not a valid
    // memory address. but that's a perfectly acceptable state of being for a pointer, being invalid. its a null pointer.
    void* pointer = NULL; // also same as = 0 (NULL is literally #define NULL 0)
    void* pointer = nullptr; // introduced in later C++ versions, another alternate for creating a null pointer

    // now, lets do something more useful

    int my_var = 8;
    // now we have a variable.
    // now that variable must have some memory address. we can get it with a `&`
    void* ptr = &my_var; // now &my_var is the address of my_var

    LOG(ptr);  // gives 0x61ff08
    LOG(my_var); // gives 8

    // now the 0x61ff08 that the log spit out is actually the address to the my_var value 8.
    // if you open memory display in debug mode and navigate to the given number, you would see
    // the number "8" written there.

    // in the actual syntax, when you want to access some value stored at some given address, 
    // you simply use this thing syntax where you prefix the pointer with an aseterisk. and that will
    // give you the actual data stored at the given location that the pointer is holding the address to.

    int my_var = 8;
    //void* ptr = &my_var;
    //*ptr = 10; // here theres red error line because we've specified the pointer type as void
    // what that causes is that we've set the pointer as a void pointer. computer doesn't know what
    // pointer is, like how many bytes it is, what sort of value it allows, etc. thats why you 
    // give data types to pointers.
    int my_new_var = 8;
    int* new_pointer = &my_new_var;
    *new_pointer = 10;
    std::cout << my_new_var << std::endl;
    // now the above works because we've told the compiler that the given 
    // pointer is an integer.
    // if you now open the debug memory and try to check the value at the location
    // that the pointer holds the address to,  you will see hexadecimal 10
    // so we've basically just edited the value at that memory when we 
    // used the *pointer method to edit the variable value.



    // now as for how to actually add things up and stuff

    // "what I could do, is create a
    // variable on the Heap. or in other words, I
    // could ask our computer, 'hey I want you to
    // allocate some memory for me and I want
    // it to be a certain size'"

    char* buffer = new char[8];
    // here we've created a pointer buffer, which points to 8 bytes in memory.
    // how did we tell the compiler it is eight bytes? the char[8] means it is 
    // an array/sequence of 8 chars. and we know 1 char = 1 byte. thus, it 
    // comes to 8 bytes.

    // buffer actually points to the first byte of those eight bytes.

    memset(buffer, 0, 8); // #include <cstring> for this memset function
    // memset is a function which is used to fill in some place in memory 
    // memset(address_to_memory_ie_pointer, value_to_fill_with, howManyBytesToFill)

    // we'd say this data has been heap allocated
    // Here, heap memory refers to the unused memory space available for dynamic allocation
    // for a program, at runtime. They then allocate and de-allocate the memory   

    // and then you can deallocate or delete the thing using
    delete[] buffer;
    // C++ does also delete all these after the program ends.

    // you can also create pointers to a pointer.
    
    char** ptr_ptr = &buffer;
    // now ptr_ptr would point to a pointer which points to the actual
    // basically ptr_ptr is an integer variable which is the address
    // to another pointer which is address to the actual "buffer var"
    

}


void references() {
    // references are sort of like pointers in terms of what the computer
    // actually does. semantically though in terms of how we use them, theres
    // some differences.
    
    // references are a way for us to refer to an existing variable.
    // null references arent a thing like null pointers.
    // references themselves arent new variables, just a reference, they dont
    // actually occupy new memory.

    int a = 5;
    int& ref = a; // & is part of type, not like &a
    // we can now use ref as if it was a.
    ref = 2;
    LOG(ref);
    // prints 2. we've sorta aliased 'a'

    void Increment(int value) {
        value++;
    }
    int a = 5;
    Increment(a);
    LOG(a); // prints 5. why doesnt a actually change? cuz 
    // the function argument is just copy pasted into the function.
    // thats what using a reference would fix.
    // if we could somehow pass the memory address to the functino instead,
    // that would allow the function the actual value of a.
    // lets rewrite our code for that
    void BetterIncrement(int* value){
        //value++; // doesnt work, the address will be incremented not the value at it
        // *value++; // doesnt work, the order of operations makes increment happen before * ptr dereferencing.
        (*value)++; // correct.
    }
    BetterIncreament(&a);


    // by using reference we can make it even less verbose.
    void BestIncrement(int& value){
        value++;
    }
    BestIncrement(a);

    // internally, better and best are technically the same thing, 
    // but for us they are less syntactic and more bloat free. cleaner.

    // note, once reference is declared you cant change what it references.
    

}



// class is short of classification i believe. 
// i'll skip the details cuz the theory is same as python
// but its basically a way to create blueprints for proper objects.

class Player {
public: // if we dont specify this, it would be considered private. 
// and private means that only other methods and stuff in this class 
// will be able to access it.
    int x, y;
    int speed;
    
    void move(int xamount, int yamount) {
        x += xamount * speed;
        y += yamount * speed;
    }
};

// example of function that works on an object but outisde class.
void movePlayer(Player& player, int xamount, int yamount) {
    player.x += xamount * player.speed;
    player.y += yamount * player.speed;
}

void classes() {
    Player player;
    player.x = 5; // dot is to access something inside player
    // if `x` wasnt under `public:` it would be considered private
    // and you wouldn't be able to access and change it.

    player.move(1, -1);
}

// structs are also basically the same as classes at a technical level
// only small difference being classes are by default private and 
// structs being public.
// then why have structs? to maintain backwards compatibility with C.
// structs are a C thing. 
// the real difference comes in where we use them. 
// if there is no difference when do i use struct vs class?
// should i just use struct when i dont wanna type public:? 
// yes. it sorta is basically that, but since theres no other rules
// people kinda define for themselves what counts as a struct 
// and what counts as class.

// the guy i am learning from says he uses structs
// for structures or representations of data like vectors or such
// which are not like stuff like a player which has a lot of functionality and stuff
// he also says he'd rather not use structs when inheritance is involved.

// lets create an actual class for this

class Logger {
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
private:
    int m_LogLevel = LogLevelInfo; // m_ tells its a class member variable or private.
public:
    void setLevel(int level) {
        m_LogLevel = level;
    }

    void error(const char* message) {
        if (m_LogLevel >= LogLevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }
    void warn(const char* message) {
        if (m_LogLevel >= LogLevelWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }
    void info(const char* message) {
        if (m_LogLevel >= LogLevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }
};



// static keyword

// outside classes/structs, a static variable just means that that
// variable is only defined for the translation file it is in. 
// it wont be able to be accessed by other translation units.

static int variable = 5;
// even if `int variable= 4;` is defined in another file, 
// it wont give any errors because this variable is static 
// and fully internal to this file
// its kinda like setting a var private in a class,
// no other file will be able to see this and linker wont see it in global scope.

// opposite of this is 
extern int other_var;
// this means this needs to be found in another translation file.


// in classes and structs, when you define a static variable,
// that basically means that that variable will be common across
// all of the instances of the class. that variable will be common 
// domain, or all instances will access the same bit of memory.
// if one of the instances changes that variable, the change is reflected everywhere.

// static methods are similar where static methods can be called without a 
// class instances. and inside static methods you cannot write code in a way that
// refers to the class instance. 

struct Entity {

    static int x, y;

    static void Print() {
        std::cout << x << ", " << y << std::endl;
    }

};

int Entity::x;
int Entity::y;

// we have to define these separately because using static makes it so the bit in struct
// is just a declaration, not a definitino 

void staticstuff() { 
    Entity e;
    e.x = 2;
    e.y = 3;

    Entity e2;
    e2.x = 5;
    e2.y = 6;
    
    e.Print();
    e2.Print();
    // output will be 5, 6 twice.
    // because x and y are static
    // to change them you could also just do
    Entity::x = 3;
    Entity::y = 4;
    // as if we just defined x and y in the Entity namespace.
    // because technically that is what we did.
    // they dont *reeaalllyyy* belong to the class.
    // but they can also be private and public so they are also still sorta part of the class,
    // but for all intensive purposes they are just part of a namespace and dont have anything to
    // do with instance creation for the class.

    // of course this is very useful when you want to have a variable commmon across classes.

    // if we call the method static, we can also do that with thr method itself

    Entity::Print();
    // this is also the same and in fact the correct way of doing things when static is involved.


    // NOW SPECIFIC CASE: VARIABLES X AND Y ARE NOT STATIC BUT PRINT FUNCTION IS. 
    // we wuold get error because static methods cannot access variables that are
    // local to the instances.

    // some lore is that behind the hood the way classes work is that 
    // the methods just get the instance as an argument into the function.
    // and thats how the non static methods can access it.
    // the static methods do not get the instance as an argument and it cant
    // access the variables and stuff on the instance.
    // so methods i guess inthat way are just regular functions wiht a 
    // secret parameter

    std::cin.get();

}


void enums(){
    // enums are basically used to name things and states in programming.
    // so instead of state1 = 0, state2= 1, etc and checking if state == state1
    // or stuff like that, we can have actual named stuff which is more convinient.

    enum Example {
        A, B, C // by default these will have values 0, 1, 2 respectively
    };

    enum ExampleOhter {
        X=3, Y, Z // here Y and Z will by default get 4 and 5 respectively.
    };

    // you can also specify the type of the integer that the enum will
    // be to conserve some memory.

    enum OneMoreExample : unsigned char {
        L, M, N
    };

    Example value = B; 

}


// constructors
class Test {
public: 
    int x, y;

    Test() {
        x = 0.0f;
        y = 0.0f;
    }

    Test(float _x, float _y) {
        x = _y;
        y = _y;
    }


private:
    void print() {
        std::cout << x << ", " << y << std::endl;
    }
};

void anotherone () {
    Test t;

    // now if you try to access t.x or t.y you will get error
    // and if you use t.print() it will print some random ahh
    // values. the reason for that is because x and y are given space
    // in the memory but that place in memory is not cleaned, 
    // whatever data was there, that is still there and it is not 
    // refreshed back to zero when we declare x and y.
    // thus we say x and y have not been initialized.
    
    // that is what the Test() function fixes, ti is called an init function.
    // that function will be run when you create a new instance of that class.
    // it is called a constructor.

    // in stuff like java primitive types are pre set to zero but that is not the 
    // case for c++, in C++ you gotta do that yourself.
    
    // alsp apparently in C++ you can define multiple functions with the same name 
    // as long as the parameters are different thus differentiating their signature.
    // hence so you can also do with constructor funcitons. you can create multiple 
    // constructor memthods.

}


// if you want to create  a class which can only be used for its 
// public methods and not allow any instances to be created out of it. 
// you can either put the constructor in a private region. or 
// more simply you can simply delete the default constructor that is provided
// by the C++ commpiler itself.
class Log {
public:
    Log() = delete; // and now the constructor will be deleted and you
    // will no longer be able to create any instances
    
};



// destructors time

class Pwease {
public:
    int x, y;

    Pwease() { // constructor 
        x = 0.0f;
        y = 0.0f;
        std::cout << "Constructed entity!" << std::endl;
    }

    ~Pwease() { // deconstructor, signified by the tilda.
        std::cout << "Deconstructed entity!" << std::endl;
    }

    void print() {
        std::cout << x << ", " << y << std::endl;
    }
};

void deconstructors() {
    Pwease p;
    p.print();
    
}

int _main() {
    deconstructors();
    // and now when deconstructors is over, the deconstructor function will run
    // because once the scope dies all local namespace is deleted. gone. or so i think.
    // you can also call the deconstructor function manually but it still runs 
    // automatically at the end of the scope so liek why would you do that theres
    // never any point in it. 
    // p.~Pwease();
}

// inheritance time

class GameEntity {
public:
    float x, y;

    void move(float hsp, float vsp) {
        x += hsp;
        y += vsp;
    }
};

class Player : public GameEntity {
public: 
    const char* name;
    void printname() {
        std::cout << name << std::endl;
    }
};

// Player player would not just be type Player but also GameEntity. inheritence here
// is kinda similar to how it was in python so im not gonna go into details here.


// note other than private and public theres also "protected:" which basically means
// private except the subclasses can also access that bit.

void arrays() {

    int lister[5];
    //and now lister is an array of integers of size 5.
    lister[0] = 432;
    lister[4] = 223;
    
    int a = lister[0];

    // THeSE WOULD CAUSE MEMORY ACCESS VIOLATIONS
    // lister[-1] = 83;
    // lister[5] = 61;
    // these will give error only in debug mode.
    // in release, they dont give any error. 
    // so if you try to access beyond the bounds,
    // you might end up writing in addresses which
    // belonged to other variables or something.
    // not ideal.
    // memory for arrays is allocated at consecutive addresses.

    std::cout << lister[0] << std::endl;
    std::cout << lister << std::endl; // this would just print an address. lister itself is like a pointer. 

    // lister itself is an integer pointer
    int* ptr = lister; // wont give any errors
    // what lister[i] = 2 means is that we're basically writing
    // some value at an offset of i bytes from the address that the pointer
    // is pointing at.
    lister[2] = 5;  // both of these are 
    *(ptr + 2) = 5;  // the same thing

    // STACK AND HEAP
    // variables and stuff created on the stack: means typical
    // declaration, the kind which will be deleted automatically
    // by C++ once the scope dies. 
    // creating variables or something on heap means manually 
    // allocating space and it will not be handled automatically
    // by the C++ compiler. E.g. if you create a new variable
    // on the heap you iwll have to manually delete it later.

    int example[5]; // declaration on the stack
    for (int i = 0; i < 5; i++) 
        example[i] = 2;
    
    int* another = new int[5]; // on heap.
    for (int i = 0; i < 5; i++) 
        another[i] = 2;
    delete[] another; 

    // both are identical in funcitoning.
    // so why would you allocate dynamically with `new` keyword rather
    // than the regular way?
    // biggest reason is lifetimes. anything made with new is around till you decide to delete it.
    


    // another thing to note is with new you cant tell the size of the array once it has been defined.
    // with stack arrays you can use sizeof(array) / sizeof(datatype) to get length
    // this is however kinda inconsistent and shoddy so just dont rely on it.
    // reason it wont work with heap arrays is because sizeof(array) would just give size of the integer pointer
    // instead of the space it points to,

    // best is to just maintain a variable urself
}
// like this
class real {
public:
    // static const int exampleSize = 5;
    // int example[exampleSize]; // this could give error because when you allocate array on stack, it needs to be a compile time known constant.
    // // theres ways around it obviously cuz this is C++ but you can fix it by using constexpr keyword

    static const int examplesize = 5;
    int example[examplesize];
};

// C++ 11 introduced standard array datatype which has internal bound checking and stuff too

#include <array>

int standardarrays () {
    std::array<int, 5> another; // <type, size> 
}

// strins
int strings() {
    const char* my_new_string = "This is a string"; // DOUBLE QUOTES MEANS CHAR POINTER (STRING) AND SINGLE QUOTES MEANS CHAR
    // in C++ strings are basically sort of like an
    // array of chars 
    // by the way we have not talked about new and delete keywords much yet
    // for now just keep in mind that if you didnt use new dont use delete
    // we type it as const because once we allocate the space for string we 
    // dont wanna edit that again, strings should be immutable. 
    // i mean if you do wanna be able to modify the string you can remove the const
    // keyword thats fine too.
    // also in memory, remember string is an array of characters. 
    // at the end of the sequence theres a 00 byte, meant to represent the end of the string

    // doing this manually

    char string2[6] = {'L', 'M', 'A', 'O'};
    std::cout << string2 << std::endl;
    // this will print LMAOut4893jg84(with some garble)
    // because cout will keep reading the bytes from that memory statring point
    // until it hits one of those 00 termination bytes.

    char string2[6] = {'L', 'M', 'A', 'O', '\0'}; // this would properly work with std::cout.

    // the standard library actually has classes called string and basicstring. basicstring is a template class
    // and the std::string is a templated version of the template class which is templated with a char (????) 
    // its the template specializatino of the basic string class with char as the template parameter
    // that means char is the underlying data type.

    // note that the operator overload definition for using std::string with cout for << operator is also contained in 
    // the string library. so if you dont inclued that, std::cout << (std::string) wont work.
}

#include <string> 

void actual_string() {
    std::string name = "My String";

    // now the nice thing about using the string data type is it has several in built methods

    // name.size();
    // name.(...) and so on
    // for traditional char pointer strings you have strlen() and strcpy() functions 

    // also stuff like the following wont work
    std::string mystringlma = "Helloo" + " There!"; // because you're here tryina add two string char ARRAYS.
    // i know they look like string in code, but like under the hood those values writte nthere in quotes
    // are evaluated as string char arrays. or const char pointers. ITS NOT AN ACTUAL STRING if that makes any sense

    name += " gaming"; // this would work because string class has overloaded operator definitino for the += operator.
    // while addition operator between two const char arrays doesnt work, the std::string objects do support addition 
    // with another string or char arrays.

    std::string mystringproper = std::string("hello") + " there";

    // you could also use this work around for that

    // you can then do stuff like 
    bool contains = name.find("gami") != std::string::npos; // npos is basically like, it stands for 'illegal position' basically.    


}



// now lets talk about passing strings to other functions 

void PrintString(std::string string) {
    std::cout << string << std::endl;
}
// we dont do the above thing becausef then the argument string passed into function
// will just be a duplicate. the string passed in will be made a copy of and 
// the functino will then proceed to use that copy 


// better way is
void printstring(const std::string& string) {
    std::cout << string << std::endl;
}
// this is better because here the string is not copied all over again for no reason.
// copying strings is slow and thus doing it this way is more efficient too
// also const is just there as a "i swurre i wont be editing this string"
// not gonna discuess it in detail right now

#include <stdlib.h> // just including some standard c functionos for now 

void string_literal() {
    // a string literal is just a string of characters in between double quotes.
    "Test"; // if you hover over this with cursor you see that it is gonna be a const char array of size 5
    // why 5? because theres also that ending terminating character which signifies the end of the string
    // in the memory. it is 0, or else '\0'
    "Te\0st"; // this is the reason why this string here would act quirky 

    const char test[6] = "Te\0st";

    std::cout << strlen(test) << std::endl;
    std::cin.get();
    // this would print string length to be 2. however our string is obviously more than 2 characters
    // the reason it gave string was because for C++ when it read the memory location where the string was,
    // immediately the moment it saw the '\0' it was like "alright the string ends here"

    // now at its core its a const char array[]
    // however we can also assign to be a const char* pointer. that works too

    const char* mystring = "hehehehaha";
    // whether or not you can edit 'const' variables later is something called an 'undefined convention'
    // basically that means there is no set rule in C++ on that and some compilers let you do that
    // while others will throw a fit, so yeah basically just dont do that/

    char* anotherstring = "Testing"; // undefined behavioru 
    anotherstring[2] = 'a'; // wont work cuz 'string literals are stored in a const region' or something

    char anotherstring[] = "Testing";
    anotherstring[2] = 'a'; // works 

    // another datatype
    const wchar_t* name2 = L"Gamer"; // it is called a wide character. `l` prefix needed to signify it

    // another one
    const char16_t* name3 = u"Text"; // char16 is likek 16 bits per character
    const char32_t* name4 = U"Test"; // for 32 bits per character (for newer unicode.)
    // for const char* you can use u8 optionally
    const char* otheroneone = u8"test";

    // you can also append to strings using this thing introduced in C++14 
    using namespace std::string_literals; //
    std::string name0 = "Gaming"s + " Hello"; // the 's' is the secret sauce, its basically a operator which converts the pointer to a std::string object if that makes any sense.
    // different prefixes also work with the std::string. theres also std::wstring, std::u32string, etc. with appropriate prefixes for the literals of course.

    const char* exampele = R"(the R here basically manes
ignore the escape characters. the brackets are also important
this is basically like triple quotes in python i suppose
but you can still use ''quotes'' and stuff it seems)";

    // last thing
    // string literals are always stored in read only memory.
    // the reason defining strings as lists and then editing it works
    // and not just const char* definition altering, is because 
    // with const char* we're just creating a pointer whicch points to where
    // the string literal is stored. and remember string literals are always 
    // stored in read only memory. but with char test[] = "gaming"; 
    // the array definition; when we do that, the literal is actually copied into
    // the array. a new copy of the string literal is created into the variable 
    // which can be then edited. 


}


void const_keyword() {
    // something interesting about const is that it is sort of like a fake keyword
    // because it doesn't really do much or change much to the code generated.
    // its more like a mechanism we use to make our code a little more cleaner 
    // and force some rules on developers with the code. `const` is more like a promise 
    // than a hard and fast rule. you dont really have to keep the promise it if you dont want to.
    // but still following the promise has some advantages 

    const int a = 5;

    // a = 2; // directly changing is kinda no no it seems. the compiler seems to be throwing a red line 

    // new idea
    int* b = new int;
    *b = 2;

    b = (int*)&a; // this is one of those ways to break the const promise. allegedly this is frowned upon cuz it MIGHT have some complications NOT SURE. 
    std::cout << *b << std::endl;

    // now lets put const everywhere
    const int MAX_AGE = 90;

    const int* z = new int;

    *z = 23; // this here gives error. 
    // putting const before the int* means the content of the pointer cannot be changed. 
    // basically you cannot change the value at the memory address that the pointer points to
    // you can still go ahead and change the pointer address itself if you want like the below line
    z = (int*)MAX_AGE;

    std::cout << z << std::endl;

    
    int* const y = new int;

    *y = 23; // this time this wont give any error.   
    y = (int*)MAX_AGE; // however this is not allowed. 
    // with const keyword after the data type, you can change the contents of the pointer,
    // but you cannot change the actual memory address that the pointer is pointing to.

    int const* x = new int;
    // this is the exact same as writing `const int* x = new int;`

    const int* const w = new int;
    // and of course, this is correct too. where both the address and data are not allowed to be changed.

}

// theres also other ways to use const than jsut vairables

class SomeEntity {
private:
    int m_x, m_y;
public:
    int getX() const { // here this just means this function doesnt actually change any variavles or anything in the class. 
        // m_X = 2 // you cant do this
        return m_x;
    }

    // IF m_x was a int*. i.e. it was like int* x, *y;, you would use this signature for the function definition.
    // the consts on the left of the name just mean it returns an int* whose data nor address can be modified.
    // and the const at the end just means that the function itself doenst modify anything of the class.
    const int* const pointerGetX() const {
        return m_x;
    }

    // setters could not be set to const for this exact reason 
    void setX(int x) {
        m_x = x; 
    }

    // why would you choose to make functions const though? 
    // if we had out entity in our main class...
};

// bro what is going on this doesnt make any sense 
void printEntity(const SomeEntity&  e) { // again, reference cuz we want to not copy while argument passage. 
    // here you cannot modify the entity, you cannot reasign it to something else.
    // cuz it doesnt work like pointers, if you reassign the reference, you're actually changing
    // the object itself not some other object. basically its because with pointers there's separation between
    // pointer and the contents of the pointer, with references you *are* the entity. 
    std::cout << e.getX() << std::endl;
    // now the interesting thing here is that if getX() was not defined as a const function,
    // you wouldn't be able to call it here since the function doesn't gaurantee that the 
    // function is not going to touch the entity. (cuz we specfied e as const SomeEntity&)
    // thus this is why sometimes you see two versions of the same function sometimes where one is 
    // specified as const and the other is not. 
    // in this case if there were two getX() functions, the one with const will be called 
}

// if this was a pointer
void printEntity(const SomeEntity* e) {
    // i can modify what its pointing towards
    // so i can set
    e = nullptr;
    // but modifying the contents of it is another matter  
}

void somemain() {
    SomeEntity e;
} 

// if you have a function which is marked as const but you just REAALLY wanna touch a variable
// and like modify some variable while in that functiono, there is a way. just mark whatever variable you
// wish to be able to edit by marking it as `mutable`.
//e.g.
// mutable int var;

// mutable keyword
// its basically something that can be changed. like its like something which is const, but can also change (???)
// lets just see it used

class MEntity {
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;
public:
    // a getter
    const std::string& getName() const { 
        m_DebugCount++; // what if you wanted to do this even if the function is const? thats why you use mutable
        return m_Name;
    }
};

void someothermain() {
    const MEntity e;
    // if getName() was not const, calling it would not be possible here
    e.getName();

    // another use of mutable keyword is with lambda.
    // now we havent studied lambda yet so we'll keep this brief.
    int x = 8;
    auto f = [=]() mutable {
        x++; // this gives an error without the mutable.
        std::cout << x << std::endl;
    };
    // a lambda is basically a quick throw away function you can assign to a variable
    // will go into lambda some other time  

}

