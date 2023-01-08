#include "Un0 Engine.cp"
#include "Sprites.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>
	
	string Pipe[30]{};
	
void RandPipe(){
	srand(time(0)); // Inicializa la semilla para la función rand()
	int numeroA = (rand() % 8) + 1; // Genera un número aleatorio entre 1 y 8
	
	switch (numeroA){
		case 1:
			for (int i = 0; i < 30; i++) {
			Pipe[i] = Tubo1[i];
			}	
			break;
		case 2:
			for (int i = 0; i < 30; i++) {
			Pipe[i] = Tubo2[i];
			}
			break;
		case 3:
			for (int i = 0; i < 30; i++) {
			Pipe[i] = Tubo3[i];
			}
			break;
		case 4:
			for (int i = 0; i < 30; i++) {
			Pipe[i] = Tubo4[i];
			}
			break;
		case 5:
			for (int i = 0; i < 30; i++) {
			Pipe[i] = Tubo5[i];
			}
			break;
		case 6:
			for (int i = 0; i < 30; i++) {
			Pipe[i] = Tubo6[i];
			}
			break;
		case 7:
			for (int i = 0; i < 30; i++) {
			Pipe[i] = Tubo7[i];
			}
			break;
		case 8:
			for (int i = 0; i < 30; i++) {
			Pipe[i] = Tubo8[i];
			}
			break;
	}
}	
	
int main(){
	system("pause");
	
	int score = 0; //Puntuacion
    int birdVelocityY = 1; // Velocidad en y del pájaro
    int birdGravity = 1; // Gravedad del pájaro
    int birdY = 1; // posicion del pájaro
	
	int PipeX = 90;
	int PipeY = 0;
	
	system("color 3f");
	coro = "color 3f";//Configuaramos el menu de inicio
	system("cls");
	
	bool gameover; //Creamos un estado para saber si se acabó el juego o no
	uDraw(Grass, 1, 0, 29);//dibujamos el piso para que se vea bonito
		RandPipe();
	
	while(!gameover){//Blucle principal del Juego
		string Score = to_string(score);
		Put("Score: "+Score,100,2);
		
		if (birdY >= 30){//Comprobamos si el pajaro se cayó y termina el juego
			gameover = true;
		}
		if ((PipeX == 42 || PipeX == 39|| PipeX == 36) && (birdY != 11 && birdY != 12 && birdY != 13 && birdY != 14 && birdY != 15 && birdY != 16 && birdY != 17 && birdY != 18)){
		//Comprobamos si el pajaró entro en la posicion del tubo (Chocó) y termina el juego
			gameover = true;
		}else{
			
		}
		uDraw(unBird, 3, 40,birdY);//Se borra el pajaro de su pocision anterior
		
		if (_kbhit() && getch() == 32) {//Detecta si se presiona 'espacio'
			birdVelocityY = -3.7; // Hace que el pájaro suba
		}
		// Aplica la gravedad al pájaro
		birdVelocityY += birdGravity;
		// Aumenta la posición en y del pájaro en la velocidad en y
		birdY += birdVelocityY;
		//Se dibuja el pajaro
		uDraw(Bird, 3, 40,birdY);
		
		Sleep(15); //interpolacion de frames / Pausa por ciclo
		
		if (PipeX != 15){
			uDraw(unPipe, 30, PipeX, PipeY);
		}
		else if (PipeX == 15){
		RandPipe();
			uDraw(unPipe, 30, 15, PipeY);
			PipeX = 90;
		}
		
		if (PipeX != 15){
			PipeX -= 3;
			uDraw(Pipe, 30, PipeX, PipeY);
		}
		if (PipeX == 33){
			score += 1;
		}
	}

	Put("game over\n", 40, 20);
	main();
}
