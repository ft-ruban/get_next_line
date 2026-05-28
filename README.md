*This project has been created as part of the 42 curriculum by ldevoude*

# Project get_next_line

## Description
This project is about programming a function that return a line read from a file descriptor thanks to a static pointer.

## Elements of the project

### get_next_line.c
The goal of our function is to return a line (all char before '\n'(End of line) or EOF(end of file)) and save in a static buffer (that should be allocated dynamicaly) where we stopped on the file so that in the next use of get_next_line we get the next line and the tool can be used until reaching the end of our file.
To free the content of the static char ptr you can setup the fd parameter to -1, that shall clean it up.

### get_next_line_utils.c
Various tools (mostly for string manipulation) and a self-made calloc that the function depend on to work.

### get_next_line.h
Header where we define our functions and the size of our buffer. Feel free to change it depending of your tests. It was more of a restriction from the school subject than something that the project require to work to be honest.


### optional files (main.c + file.txt)
Was used to test my function, file.txt is created if does not exist in the folder. Feel free to modify the main and the txt accordingly to the tests you desire to make.


## Instructions
### Compilation
to try the function setup the main.c and file.txt accordingly then run:
```bash
cc get_next_line.c get_next_line_utils.c main.c
```
this shall generate an executable that you can launch using
```bash
./a.out
```

### Use of AI:

- `ldevoude`: None for the project as I had a lot of help from my peers at that moment when trying to handle the various leaks I had. Gdb was a useful tool for that project.


## Resources
- https://stackoverflow.com/questions/1286515/extern-and-static-pointers-in-c
- https://www.w3schools.com/
- https://stackoverflow.com/
- https://www.cs.toronto.edu/~krueger/csc209h/tut/gdb_tutorial.html
- https://perso.ens-lyon.fr/daniel.hirschkoff/C_Caml/docs/doc_gdb.pdf
