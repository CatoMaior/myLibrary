# myLibrary
C library with common tasks or types. I know the name is not the best but I have no imagination for names

Project in active development, check [here](https://catomaior.github.io/myLibrary/) for the documentation and [here](https://github.com/CatoMaior/myLibrary/releases/tag/latest) to download latest build.

## How to import
### On Linux
Download the build for Linux, unzip it and place it somewhere. Consider the following code:
```c
#include "myLibrary.h"

int main() {
    byte myMatrix[][2] = {{42, 24}, {-24, 42}};
    printMatrix("%3hi", myMatrix, 2, 2);
    return 0;
}
```

Assuming it is saved in a file named `myFile.c` and you want to compile it using `gcc`, the correct command for compilation is:
```bash
gcc path/to/myFile.c -o path/to/myFileExecutable -I path/to/folder/with/myLibrary path/to/folder/with/myLibrary/build/myLibrary_Linux.lib
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
 - Go to "Configuration Properties" > "Linker" > "Input". In "Additional Dependencies" add `myLibrary_Windows.lib;legacy_stdio_definitions.lib;legacy_stdio_wide_specifiers.lib`;
 - Click on "Ok" at the bottom of the window
 - Near to "Local Windows Debugger" choose "x64". Now you are ready to `#include "myLibrary.h"`{:.c} and compile and run your code