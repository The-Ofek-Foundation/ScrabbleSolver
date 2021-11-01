# BoggleSolver

This project is meant to solve the game of Boggle, as played on [this website](https://serpentinegame.com/). The dictionary used is the SOWPODS dictionary, which is a superset of the dictionary used in the aforementioned website. Different dictionaries can be trivially substituted.

In this version, there are no standalone Q squares, rather there are only 'Qu' squares.

## Running

This program is written in C++, and can be compiled and executed using the makefile, with `make run`. It currently uses g++-11 to compile the program, but can probably be compiled on older compilers with slight modifications to the code (the program has a minor reliance on c++17 features).

This program was designed to cheat in the above online boggle game, so there is a feature to not only list out the legal words, but to also type out the words and press enter after each one. This feature is currently only designed to work on linux systems, and will not work on Windows and likely neither on MacOS. Again, some minor code modifications will probably suffice to address this. It may not compile without this.

### User input

First, the user inputs the minimum word length for the game. Then, they input whether they want the program to write the words out using their keyboard, or just print them. Afterwords, they input the dimensions of the board. Finally, they input the board itself, letter by letter, row by row. Each letter should be on its own line. Again, standalone 'Q' squares are not supported. 'Qu' squares should be inputted as just 'q'. All letters should be lowercase.

# Minor maths

Some minor maths and a lot more explanation can be found on [my blog](https://blog.theofekfoundation.org/general-computer-programming/2021/10/31/boggle-maths/).
