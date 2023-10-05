# Fract-ol
<p align="center"><img src="https://cdn-images-1.medium.com/v2/resize:fit:1200/1*mb0KkzYAZDDSvdYC2MM5hg.jpeg" width="150" height="150" />

#
<h3><b>¤ Table of contents ¤</b></h3>

1) <b>How to use</b>
2) <b>Introduction</b>
3) <b>Instructions</b>
4) <b>Part 1: Parameters</b>
5) <b>Part 2: Example</b>

---
<h3><b>¤ How to use ¤</b></h3>

* Clone the git repository.
* Execute `make` in terminal.
* Execute `./fractol` in terminal and read the manual for possible uses of the program.

---
<h3><b>¤ Introduction ¤</b></h3>
<p align="center"> "fract-ol" is one of three graphical projects that we had access on this circle. As such, we have been introduced to our first graphical library "MiniLibX", which provides us with very basic functionalities. Other concepts that
we are being introduced to are the usage of complex numbers, optimization and event handling.</p>

---
<h3><b>¤ Instructions ¤</b></h3>

* Project must be written in C.

* Functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors.

* All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and Makefile must not relink.

* Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

---
<h3><b>¤ Part 1: Parameters ¤</b></h3>

* MiniLibX library MUST be used.

* Global variables are forbidden.

* Program must offer two fractol sets: Mandelbrot and Julia. In addition, Julia set must create different sets based on different parameters.

* The mouse wheel zooms in and out, almost infinitely (within the limits of the computer).

* A parameter is passed on the command line to define what type of fractal will be displayed in a window.

* Colors must be used to show the depth of each fractal.

* Program has to display the image in a window and it has to remain smooth durung run time (changing windows, minimizing, etc.).

* Pressing ESC must close the window and quit the program in a clean way, as well as clicing "X" on window's frame.

---
<h3><b>¤ Part 2: Example ¤</b></h3>

<p align="center"><img src=https://i.stack.imgur.com/O9kEL.gif" width="1000" height="800" />

Depicted above is the Mandelbrot fractol. 
