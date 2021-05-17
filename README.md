# myLibrary
C library with common tasks or types. I know the name is not the best but I have no imagination for names

Project in active development, check [here](https://catomaior.github.io/myLibrary/) for the documentation and [here](https://github.com/CatoMaior/myLibrary/releases/tag/latest) to download latest build.

## How to import
### Linux
Download the build for Linux, unzip it and place it somewhere. Consider the following code:

    #include "myLibrary.h"

    int main() {
        byte myMatrix[][2] = {{42, 24}, {-24, 42}};
        printMatrix("%3hi", myMatrix, 2, 2);
        return 0;
    }

Assuming it is saved in a file named `myFile.c` and you want to compile it using `gcc`, the correct command for compilation is:

    gcc path/to/myFile.c -o path/to/myFileExecutable -I path/to/folder/with/myLibrary path/to/folder/with/myLibrary/build/myLibrary_Linux.lib

Where:
 - `path/to/myFile.c` is the relative or absolute path to myFile.c
 - `path/to/myFileExecutable` is the relative or absolute path for the compiler output
 - `path/to/folder/with/myLibrary` is the relative or absolute path of the folder you extracted myLibrary to
- `path/to/folder/with/myLibrary/build/myLibrary_Linux.lib` is the path to the binary file of the library
