# C-Graphics-Engine
Engine to draw pixels in the Windows console, easily handle files, print text in specific parts of the console and more...

This is a graphics engine that I originally designed as a set of functions for the aesthetics of a school project and decided to continue and improve it, so I made this Engine to draw pixels in the Windows console, easily handle files, print in specific parts of the console (Something like the Gotoxy function, but something better), make dynamic sprites, save them as text and print them with pixels in console and things like that.

Here we have functions such as:
Pixel(): which has the function of drawing a pixel of a specific color in a specific position in the console
Put(): which has the function of printing a given string as input in a specific position in the console
uDraw(): from an array of strings, this is printed with pixels in a specified position. (More specific example in the attached videogame example)

and structures such as data to create, delete, read and write to files more easily
example of using data:

data File;
string str_Name = hola;
File.Write(Name.txt, str_Name , 1);
File.Read("hola", Name.txt, 1);
File.Delete(Name.txt);
