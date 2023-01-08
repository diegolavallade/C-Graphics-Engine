//
//	GraphikEngine For WindowsNT Console
//	Designed for: Un0
//	
//	Copyright: Diego Lavallade, 2023

#include <windows.h>
#include <iostream>
#include <fstream>
using namespace std;

string an="> ", coro ="color cf";
char cloro[9];

struct data{
	
	bool Delete(string nombre_archivo) {
	  // Creamos un objeto de archivo de entrada/salida
	  fstream archivo;
	
	  // Abrimos el archivo en modo de escritura
	  archivo.open(nombre_archivo, ios::out);
	
	  // Verificamos si el archivo se abrió correctamente
	  if (!archivo.is_open()) {
	    // Si no se pudo abrir el archivo, mostramos un mensaje de error
	    // y devolvemos false
	    cerr << "Error: no se pudo abrir el archivo '" << nombre_archivo << "'" << endl;
	    return false;
	  }
	
	  // Si el archivo se abrió correctamente, lo cerramos y lo borramos
	  archivo.close();
	  remove(nombre_archivo.c_str());
	}
	
	void Write(const string& file, const string& cadena, int linea) {
	    // Abrimos el archivo en modo de escritura y creacion
	    fstream archivo(file, ios::out | ios::app);
	
	    // Desplazamos el puntero de escritura al inicio de la columna especificada
	    archivo.seekp((linea - 0) * sizeof(string::value_type));
	
	    // Escribimos la cadena en el archivo
	    archivo << cadena << endl;
	
	    // Cerramos el archivo
	    archivo.close();
	}
	
	void Read(string& cadena,const string& file, int columna) {
	    // Abrimos el archivo en modo de lectura
	    fstream archivo(file, ios::in);
	
	    // Desplazamos el puntero de lectura al inicio de la columna especificada
	    archivo.seekg((columna - 0) * sizeof(string::value_type));
	
	    // Leemos la cadena del archivo y la guardamos en la variable "cadena"
	    getline(archivo, cadena);
	
	    // Cerramos el archivo
	    archivo.close();
	}
};

// Muestra una cadena de texto dada c/i en la consola de Windows, en la posición x, y especificadas.
void Put(string shw, int x, int y){
	
	// Obtiene un handle a la consola
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Establece la posición del cursor utilizando una estructura COORD
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;
	SetConsoleCursorPosition(hCon, dwpos);
	
	// Imprime la cadena de texto
	cout <<shw;
};

// Cambia el color del texto y el fondo de la consola de Windows.
void SetConsoleColors(int textColor, int bgColor) {
  // Obtiene un handle a la consola
  HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
  
   // Establece el atributo de color deseado utilizando la función SetConsoleTextAttribute
  int attrib = (bgColor << 4) | textColor | FOREGROUND_INTENSITY;
  SetConsoleTextAttribute(hconsole, attrib);
}

// Dibuja un pixel de un color específico en una posición x e y especificada.
void Pixel(int color, int x, int y){
	// Establece el color del texto y el fondo de la consola al mismo valor (el del pixel)
	SetConsoleColors(color, color);
	
	// Muestra un par de espacios en blanco en la posición deseada, creando el efecto de un pixel de un solo carácter de ancho y alto.
	Put("  ", x, y);
}


//void Lput(string shw, int x, int y) {
//  move(x, y);
//  printw("%s", shw);
//}

void uDraw(string lain[], int Largo_Sprite, int x, int y) {
	
  // Recorremos cada línea
  for (int i = 0; i < Largo_Sprite; i++) {
    string line = lain[i];
    int lineLength = line.length();

    // Recorremos cada caracter de la línea
    for (int j = 0; j < lineLength; j++) {
      // Si encontramos un par de '#', entonces llamamos a Pixel
       if (line[j] == '0' && line[j + 1] == '0') {
        // Saltamos el siguiente caracter '#' para evitar procesarlo de nuevo
			Pixel(0, x + j, y + i);
			j++;
		}else if (line[j] == '1' && line[j + 1] == '1') {
			Pixel(1, x + j, y + i);
			j++;
		}else if (line[j] == '2' && line[j + 1] == '2') {
			Pixel(2, x + j, y + i);
			j++;
		}else if (line[j] == '3' && line[j + 1] == '3') {
			Pixel(3, x + j, y + i);
			j++;
		}else if (line[j] == '4' && line[j + 1] == '4') {
			Pixel(4, x + j, y + i);
			j++;
		}else if (line[j] == '5' && line[j + 1] == '5') {
			Pixel(5, x + j, y + i);
			j++;
		}else if (line[j] == '6' && line[j + 1] == '6') {
			Pixel(6, x + j, y + i);
			j++;
		}else if (line[j] == '7' && line[j + 1] == '7') {
			Pixel(7, x + j, y + i);
			j++;
		}else if (line[j] == '8' && line[j + 1] == '8') {
			Pixel(8, x + j, y + i);
			j++;
		}else if (line[j] == '9' && line[j + 1] == '9') {
			Pixel(9, x + j, y + i);
			j++;
		}else if (line[j] == 'A' && line[j + 1] == 'A') {
			Pixel(10, x + j, y + i);
			j++;
		}else if (line[j] == 'B' && line[j + 1] == 'B') {
			Pixel(11, x + j, y + i);
			j++;
		}else if (line[j] == 'C' && line[j + 1] == 'C') {
			Pixel(12, x + j, y + i);
			j++;
		}else if (line[j] == 'D' && line[j + 1] == 'D') {
			Pixel(13, x + j, y + i);
			j++;
		}else if (line[j] == 'E' && line[j + 1] == 'E') {
			Pixel(14, x + j, y + i);
			j++;
		}else if (line[j] == 'F' && line[j + 1] == 'F') {
			Pixel(15, x + j, y + i);
			j++;
		}
    }
  }
  //Consultamos el color establecido por el programa principal
	if(coro == "color cf"){
	  SetConsoleColors(14,12);
	}else if (coro == "color 8e"){
	  SetConsoleColors(14,8);
	}else if (coro == "color 3f"){
	  SetConsoleColors(15,3);		
	}
}

