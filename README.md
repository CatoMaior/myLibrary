# myLibrary

C library with some common tasks and data structures. I know the name is not the best but I have no imagination for names\
Project in active development, check [here](https://catomaior.github.io/myLibrary/) for the documentation and [here](https://github.com/CatoMaior/myLibrary/releases/tag/latest) to download latest build (64 bits only, but you can compile from source in order to support other architectures). 

## Table of contents
 - [Introduction and examples](#introduction-and-examples)
    - [ArrayLists](#arraylists)
    - [LinkedLists](#linkedlists)
    - [Stacks](#stacks)
    - [Queues](#queues)
 - [How to import](#how-to-import) 
    - [On Linux](#on-linux)
    - [On Visual Studio for Windows](#on-visual-studio-for-windows)
 - [How to compile from source](#how-to-compile-from-source)

## Introduction and examples
This library contains some useful data structure which are not supported by default in C, some frequently used functions and algorithms.\
As this library is written in C, almost every function needs you to specify as a function argument which type of data you are using it on through type and formatting specifiers. The convention used is the same used in standard C for `printf` and `scanf`. In order to make writing code a bit more lighter the library includes also some macros that automatically detect the type of arguments passed so you don't have to explicitly use format and type specifiers. However, these macros are supported only on C11 and newer compilers and using them in some development environments can cause warnings or errors reporting even though they are used correctly. See [macros.h](https://catomaior.github.io/myLibrary/macros_8h.html) in the docs for more. In order to be as inclusive as possibile, since this macros are not supported by every C compilers, in the following examples they are not used.\
The approach used by this library to handle errors with pointers is that every error is fatal: for example, when a pointer passed to a function is null and it should not be null, or some needed memory could not be allocated, the program prints where the error occurred and exits.

### ArrayLists
ArrayLists are dynamically growing and shrinking lists of data, which can be of `char`, `int`, `float`, `double` or pointer type. You can create an ArrayList from a C array or you can create a new empty ArrayList. You can append items at its end, insert items, change its items, get its items, sort it (only ascending order is currently supported), print it, merge it with another ArrayList and much more. See [arrayList.h](https://catomaior.github.io/myLibrary/arrayList_8h.html) in the docs for all the details.\
The difference with LinkedLists is in the implementation and hence in the time needed for accessing its item. For example, an ArrayList has constant time for accessing items, while a LinkedList takes linear time. If you are intrested in these topics I suggest you to search more information on the Internet, as LinkedList and ArrayList are very standard data structure and on the web you can find a lot of information.\
Here are some examples of ArrayList usage:

```cpp
#include "myLibrary.h"

int main() {
    // Create an empty ArrayList of int type
    ArrayList list1 = newAL("%i");

    // Print list1
    printAL("%i\n", list1);
    // Output:
    // Empty

    // Append two items to list1
    appendToAL(list1, 3);
    appendToAL(list1, 4);
    // Now list1 contains: 3, 4

    // Insert an item to list1 at index 1
    insertToAL(list1, 1, -1);
    // Now list1 contains: 3, -1, 4

    // Change value of item at index 1 in list1
    setALItem(list1, 1, -2);
    // Now list1 contains: 3, -2, 4

    // Remove item at index 1 from list1
    removeFromAL(list1, 1);
    // Now list1 contains: 3, 4

    int extracted;

    // Get item at index 1 from list1 and save it into extracted
    getFromAL(list1, 1, &extracted);
    // list1 still contains: 3, 4; extracted is now 4

    int myArray[] = {23, 4, 65, -5, 12};

    // Create an ArrayList of ints from the static array myArray which contains 5 elements
    ArrayList list2 = chooseNewALFromArray("%i", myArray, 5);
    // Now list2 contains: 23, 4, 65, -5, 12

    printAL("% i", list1);
    // Output:
    //  23 4 65 -5 12

    // Sort list2 using a quicksort algorithm
    quickSortAL(list2);
    // Now list2 contains: -5, 4, 12, 23, 65

    // Reverse an ArrayList
    reverseAL(list2);
    // Now list2 contains: 65, 23, 12, 4, -5

    // Get the index of 12 in list2
    int index = linearSearchAL(list2, 12);
    // index is now 2

    // Check if list1 and list2 have equal contents
    byte areEqual = areALEqual(list1, list2);
    // areListsEqual is now FALSE (See [macros.h](https://catomaior.github.io/myLibrary/macros_8h.html) docs for its numeric value)

    // Merge list1 and list2
    mergeAL(list1, list2);
    // list2 still contains: 65, 23, 12, 4, -5; list1 now contains 3, 4, 65, 23, 12, 4, -5

    // Get list1 length
    unsigned int list1Length = getALLength(list1);
    // list1Length is now 7

    // Delete list1 and list2
    deleteAL(list1);
    deleteAL(list2);
    // Memory used by list1 and list2 is now freed. In order to avoid memory leaks is always good practice to delete ArrayLists before they go out of their scope

    return 0;
}
```

### LinkedLists
LinkedLists are a quite standard implementation of linked lists, dynamically growing and shrinking lists of data, which can be of `char`, `int`, `float`, `double` or pointer type. You can create a LinkedList from a C array or you can create a new empty LinkedList. You can append items at its end, insert items, change its items, get its items, sort it (only ascending order is currently supported), print it, merge it with another LinkedList and much more. See [linkedList.h](https://catomaior.github.io/myLibrary/linkedList_8h.html) in the docs for all the details.\
The difference with ArrayLists is in the implementation and hence in the time needed for accessing its item. For example, a LinkedList has constant time for accessing items, while a LinkedList takes linear time. If you are intrested in these topics I suggest you to search more information on the Internet, as ArrayLists and LinkedList are very standard data structure and on the web you can find a lot of information. As for now, LinkedLists and ArrayLists have more or less the same functionalities except sorting and reversing, which are currently supported only on ArrayLists.\
Here are some examples of LinkedList usage:

```cpp
#include "myLibrary.h"

int main() {
    // Create an empty LinkedList of int type
    LinkedList list1 = newLL("%i");

    // Print list1
    printLL("%i\n", list1);
    // Output:
    // Empty

    // Append two items to list1
    appendToLL(list1, 3);
    appendToLL(list1, 4);
    // Now list1 contains: 3, 4

    // Insert an item to list1 at index 1
    insertToLL(list1, 1, -1);
    // Now list1 contains: 3, -1, 4

    // Change value of item at index 1 in list1
    setLLItem(list1, 1, -2);
    // Now list1 contains: 3, -2, 4

    // Remove item at index 1 from list1
    removeFromLL(list1, 1);
    // Now list1 contains: 3, 4

    int extracted;

    // Get item at index 1 from list1 and save it into extracted
    getFromLL(list1, 1, &extracted);
    // list1 still contains: 3, 4; extracted is now 4

    int myArray[] = {23, 4, 65, -5, 12};

    // Create a LinkedList of ints from the static array myArray which contains 5 elements
    LinkedList list2 = chooseNewLLFromArray("%i", myArray, 5);
    // Now list2 contains: 23, 4, 65, -5, 12

    printLL("% i", list1);
    // Output:
    //  23 4 65 -5 12

    // Get the index of 12 in list2
    int index = linearSearchLL(list2, 12);
    // index is now 2

    // Check if list1 and list2 have equal contents
    byte areEqual = areLLEqual(list1, list2);
    // areListsEqual is now FALSE (See [macros.h](https://catomaior.github.io/myLibrary/macros_8h.html) docs for its numeric value)

    // Merge list1 and list2
    mergeLL(list1, list2);
    // list2 still contains: 65, 23, 12, 4, -5; list1 now contains 3, 4, 65, 23, 12, 4, -5

    // Get list1 length
    unsigned int list1Length = getLLLength(list1);
    // list1Length is now 7

    // Delete list1 and list2
    deleteLL(list1);
    deleteLL(list2);
    // Memory used by list1 and list2 is now freed. In order to avoid memory leaks is always good practice to delete LinkedLists before they go out of their scope

    return 0;
}
```

### Stacks
Stacks are a quite standard implementation of LIFO stacks and can contain `char`, `int`, `float`, `double` or pointer data. You can create a Stack from a C array or you can create a new empty Stack. You can print its content, push items to its top, pop items from its top, peek from its top and much more. [stack.h](https://catomaior.github.io/myLibrary/stack_8h.html) in the docs for all the details.\
Here are some examples of Stack usage:

```cpp
#include "myLibrary.h"

int main() {
    // Create an empty Stack of int type
    Stack stack1 = newStack("%i");

    // Print stack1
    printStack("%i\n", stack1);
    // Output:
    // Empty

    // Push two items to stack1
    push(stack1, 3);
    push(stack1, 4);
    push(stack1, -1);
    // Now stack1 contains: -1, 4, 3

    int extracted;

    // Pop the item on top from stack1 and save it into extracted
    pop(stack1, &extracted);
    // Now stack1 contains: 4, 3; extracted is now -1

    // Peek the item on top from stack1 and save it into extracted
    peekStack(stack1, &extracted);
    // stack1 still contains: 4, 3; extracted is now 4

    int myArray[] = {23, 4, 65, -5, 12};

    // Create a Stack of ints from the static array myArray which contains 5 elements
    Stack stack2 = chooseNewStackFromArray("%i", myArray, 5);
    // Now stack2 contains: 12, -5, 65, 4, 23

    printStack("% i", stack1);
    // Output:
    //  12 -5 65 4 23

    // Check if stack1 and stack2 have equal contents
    byte areEqual = areStacksEqual(stack1, stack2);
    // areListsEqual is now FALSE (See [macros.h](https://catomaior.github.io/myLibrary/macros_8h.html) docs for its numeric value)

    // Delete an item from the top of stack2 without saving it
    deleteHeadFromStack(stack2);
    // Now stack2 contains: -5, 65, 4, 23

    // Get stack1 length
    unsigned int stack2Length = getStackLength(stack2);
    // stack1Length is now 4

    // Delete stack1 and stack2
    deleteStack(stack1);
    deleteStack(stack2);
    // Memory used by stack1 and stack2 is now freed. In order to avoid memory leaks deleting Stacks before they go out of their scope is always good practice

    return 0;
}
```

### Queues
Queues are a quite standard implementation of FIFO queues and can contain `char`, `int`, `float`, `double` or pointer data. You can create a Queue from a C array or you can create a new empty Queue. You can print its content, enqueue items to its end, dequeue items from its top, peek from its top and much more. [queue.h](https://catomaior.github.io/myLibrary/queue_8h.html) in the docs for all the details.\
Here are some examples of Queue usage:

```cpp
#include "myLibrary.h"

int main() {
    // Create an empty Queue of int type
    Queue queue1 = newQueue("%i");

    // Print queue1
    printQueue("%i\n", queue1);
    // Output:
    // Empty

    // Enqueue two items in queue1
    enqueue(queue1, 3);
    enqueue(queue1, 4);
    enqueue(queue1, -1);
    // Now queue1 contains: 3, 4, -1

    int extracted;

    // Dequeue the item on top from queue1 and save it into extracted
    dequeue(queue1, &extracted);
    // Now queue1 contains: 4, -1; extracted is now 3

    // Peek the item on top from queue1 and save it into extracted
    peekQueue(queue1, &extracted);
    // queue1 still contains: 4, -1 extracted is now 4

    int myArray[] = {23, 4, 65, -5, 12};

    // Create a Queue of ints from the static array myArray which contains 5 elements
    Queue queue2 = chooseNewQueueFromArray("%i", myArray, 5);
    // Now queue2 contains: 23, 4, 65, -5, 12

    printQueue("% i", queue1);
    // Output:
    //  23 4 65 -5 12

    // Check if queue1 and queue2 have equal contents
    byte areEqual = areQueuesEqual(queue1, queue2);
    // areListsEqual is now FALSE (See [macros.h](https://catomaior.github.io/myLibrary/macros_8h.html) docs for its numeric value)

    // Delete an item from the top of queue2 without saving it
    deleteHeadFromQueue(queue2);
    // Now queue2 contains: 4, 65, -5, 12

    // Get queue1 length
    unsigned int queue2Length = getQueueLength(queue2);
    // queue1Length is now 4

    // Delete queue1 and queue2
    deleteQueue(queue1);
    deleteQueue(queue2);
    // Memory used by queue1 and queue2 is now freed. In order to avoid memory leaks deleting Queues before they go out of their scope is always good practice

    return 0;
}
```


## How to import

### On Linux

Download the build for Linux, unzip it and place it somewhere. Consider the following code:

```cpp
#include "myLibrary.h"

int main() {
    byte myMatrix[][2] = {{42, 24}, {-24, 42}};
    printMatrix("%3hi", myMatrix, 2, 2);
    return 0;
}
```

Assuming it is saved in a file named `myFile.c` and you want to compile it using `gcc`, the correct command for compilation is:
```
gcc path/to/myFile.c -o path/to/myFileExecutable -I path/to/folder/with/myLibrary \
    path/to/folder/with/myLibrary/build/myLibrary_Linux.lib
```

Where:
 - `path/to/myFile.c` is the relative or absolute path to myFile.c
 - `path/to/myFileExecutable` is the relative or absolute path for the compiler output
 - `path/to/folder/with/myLibrary` is the relative or absolute path of extracted myLibrary folder
 - `path/to/folder/with/myLibrary/build/myLibrary_Linux.lib` is the path to the binary file of the library

### On Visual Studio for Windows

Download the build for Windows, unzip it and place it somewhere. Steps to import:
 - Open the solution where you want to use myLibrary
 - Ensure the source file where you want to import myLibrary has `.c` extension. If its extension is `.cpp`, change it to `.c`
 - Go to "Project" > "myProject Properties"
 - In "Configuration" choose "All Configurations"
 - In "Platform" choose "x64"
 - Go to "Configuration Properties" > "C/C++" > "General". In "Additional Include Directories" add the path of the myLibrary folder you extracted before
 - Go to "Configuration Properties" > "Linker" > "General". In "Additional Library Directories" add the path of the "build" folder inside the myLibrary folder you extracted before
 - Go to "Configuration Properties" > "Linker" > "Input". In "Additional Dependencies" add `myLibrary_Windows.lib;legacy_stdio_definitions.lib;legacy_stdio_wide_specifiers.lib;`
 - Click on "Ok" at the bottom of the window
 - Near to "Local Windows Debugger" choose "x64". Now you are ready to `#include "myLibrary.h"` and compile and run your code

## How to compile from source

Compilation from source is currently supported only on Linux. The only dependencies are `gcc` and `make`. Run:
```
git clone https://github.com/CatoMaior/myLibrary.git
cd myLibrary
make lib
```
The compiled binaries are `myLibrary_Linux.lib` and `myLibrary_Windows.lib` in the `build` folder. If you want a pdf version of the docs too run:
```
make docs
```
The pdf is now in the `docs` folder