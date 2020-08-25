#include <GL/glut.h>
#include <iostream>
#include <math.h>

//variables globales
float WIDTH = 500, HEIGHT = 500;
static int RESOLUTIONX = 1366, RESOLUTIONY = 768;
float colors[3] = {};

float* RGBToFloat(float red, float green, float blue) {
	red = red / 255;
	green = green / 255;
	blue = blue / 255;

	colors[0] = red;
	colors[1] = green;
	colors[2] = blue;

	return (colors);
}

void Display() {
	glFlush();
}

void pantalla(float red, float green, float blue)
{
	//tamaño del punto usado en px
	glPointSize(5);
	float* ColorFondo = RGBToFloat(red, green, blue);
	//Configuracion del color de borrado o color de fondo
	glClearColor(*ColorFondo, *(ColorFondo + 1), *(ColorFondo + 2), 1);
	//Organizacion de los ejes en funcion de una vista ortogonal
	
	//limpieza inicial de la pantalla con el color predefinido anteriormente
	glClear(GL_COLOR_BUFFER_BIT);
}

void ejes(float red, float green, float blue, int x, int y) {
	glOrtho(-x, x, -y, y, -1, 1);

	glColor3fv(RGBToFloat(red, green, blue));

	glBegin(GL_LINES);
	glVertex2d(0, -y);
	glVertex2d(0, y);
	glVertex2d(-x, 0);
	glVertex2d(x, 0);
	glEnd();
}

int main(int arg, char* argv[]) {

	float posX = ((RESOLUTIONX / 2) - (WIDTH / 2));
	float posy = ((RESOLUTIONY / 2) - (HEIGHT / 2) - 40);

	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(posX, posy);
	glutCreateWindow("Clase 2");
	glutDisplayFunc(Display);

	pantalla(84, 84, 84);
	ejes(233, 255, 249, 250, 250);

	glutMainLoop();


	//TODO graficar la funcion seno

	return 0;
}