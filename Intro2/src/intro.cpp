#include <GL/glut.h>
#include <iostream>

//variables globales
GLsizei WIDTH = 500, HEIGHT = 500;
static int RESOLUTIONX = 1366, RESOLUTIONY = 768;
float colors[3] = {};
float ejeX = WIDTH / 2, ejeY = HEIGHT / 2;

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
	glPointSize(10);
	float* ColorFondo = RGBToFloat(red, green, blue);
	//Configuracion del color de borrado o color de fondo
	glClearColor(*ColorFondo, *(ColorFondo + 1), *(ColorFondo + 2), 1);
	//Organizacion de los ejes en funcion de una vista ortogonal
	glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
	//limpieza inicial de la pantalla con el color predefinido anteriormente
	glClear(GL_COLOR_BUFFER_BIT);
}

void cuadricula(float red, float green, float blue) {
	glColor3fv(RGBToFloat(red, green, blue));

	glBegin(GL_LINES);
	// ciclo para generacion de las lineas cada 10 pixeles para concordancia con el tamaño usado
	for (int i = 10; i < WIDTH; i = i + 10) {
		glVertex2d(0, i);
		glVertex2d(HEIGHT, i);
		for (int j = 10; j < HEIGHT; j = j + 10) {
			glVertex2d(j, 0);
			glVertex2d(j, WIDTH);
		}
	}
	glEnd();
}

int main(int arg ,char* argv[]) {

	int posX = ((RESOLUTIONX / 2) - (WIDTH / 2));
	int posy = ((RESOLUTIONY / 2) - (HEIGHT / 2) - 40);

	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(posX, posy);
	glutCreateWindow("Clase 2");
	glutDisplayFunc(Display);

	pantalla(84, 84, 84);
	cuadricula(233, 255, 249);

	glutMainLoop();


	//TODO graficar la funcion seno

	return 0;
}