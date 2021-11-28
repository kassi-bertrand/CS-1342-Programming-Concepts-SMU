`Author(s)`: Billy-Bertrand

`Project Description`:

The purpose of this program is to familiarize yourself with pointer and memory buffer operations 
in C++. In this assignment, you implement a program that renders fireworks using the ASCII art 
technique. The technique uses ASCII characters, represented by the char data type in C++, to 
compose and print images. Consider the following four examples of ASCII firework art “images”
as the inputs.

1)

```
.* *.
*..*
 *
```

2)

```
 ^,^,^
^,^,^,^,^
^,^,^,^,^
 ^,^,^
```

3)

```
`o`o`
o`o`o`o
`o`o`
```

4)

```
 ~@~*~@~
~*~@~*~@~*~
~*~@$#$@~*~
~*~@~*~@~*~
 ~@~*~@~
```

The program randomly generates a scene using the fireworks and “renders” the buffer by printing it into the console (std::cout).

`Why this project?`:

This was a programming project proposed in one of my programming class. I enjoyed working on it, so I thought it would be nice to archive it here.

`Program Specifications`:

- The rendering buffer must be implemented as a dynamically allocated array of type char*

- The rendering buffer must be deallocated before the program exits

- The rendering buffer initialization with the white space must be implemented as a function.

- Copying of a firework art into the rendering buffer must be implemented as a function. Introduce a function for each firework art type

- Copying of a firework trace into the rendering buffer must be implemented as a function.

- Each of the four firework arts must be at least partially visible in the scene. There should  be no missing fireworks.

- Printing the rendering buffer into the console (std::cout) must be implemented as a function

`Result`:

```
Do you want to see the fireworks? (y|n)
y

                                            `o`o`
    .* *.                                   o`o`o`o
     *..*                                   `o`o`
       *                                       /
        \                                     /
         \             ^,^,^                 /
          \           ^,^,^,^,^             /
           \          ^,^,^,^,^              ~@~@~
            \          ^,^,^              ~*~@~*~@~*~
             \             \             /~*~@$#$@~*~
              \             \           / ~*~@~*~@~*~
               \             \         /     ~@~@~
                \             \       /         /
                 \             \     /         /
                  \             \   /         /
                   \             \ /         /
                    \             /         /
                     \           / \       /
                      \         /   \     /
```

`Complications`:

- The functions in charge of copying images to the rendering buffer was often off-bound, causing the whole program to crash with a `Segmentation fault`.

`Potential Improvements`:

- Implement Ascii animations. Instead of just being printed out as a whole to `std::out`, the fireworks can be displayed in an animated-like fashion, adding more realism to our little projects.

`Useful Resources`:

N/A
