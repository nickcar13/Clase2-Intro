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

int main(int arg ,char* argv[]) {

	int posX = ((RESOLUTIONX / 2) - (WIDTH / 2));
	int posy = ((RESOLUTIONY / 2) - (HEIGHT / 2) - 40);

	glutInit(&arg, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(posX, posy);
	glutCreateWindow("Clase 2");
	glutDisplayFunc(Display);
	glutMainLoop();

	//TODO graficar la funcion seno

	return 0;
}