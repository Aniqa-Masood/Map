
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

#include "wav.h"
#include <freeglut.h>

#include "RGBApixMap.h"
#include "Turtle.h"

void myInit(void)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glViewport(0, 0, 1300, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1300, 0, 600);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, 1.0);
	PlaySound("backmusic.wav", NULL, NULL);	
}

void text()
{
	char menu[80];
	strcpy_s(menu, "My Map : From My Sweet Home to UBIT (red line shows the direction)");
	int len;
	len = strlen(menu);

	glColor3f(0.4, 0, 0.8);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	gluOrtho2D(0, 1300, 0, 600);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();

	glRasterPos2i(310, 570);


	for (int i = 0; i < len; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, menu[i]);
	}

	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	RGBApixmap photo;
	photo.readBMPFile("map.bmp");
	photo.setChromaKey(192, 192, 192);
	glRasterPos2i(0.0, 0.0);
	photo.mDraw();

	text();

	
	string c = "llllllllllllllllffffllllllllbbbbbbbbbbbbbbbbbbbbbbrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrffffffffffffrrrrrffffrrr";
	glLineWidth(3.0f);
	glColor3f(1.0f, 0.1f, 0.0f);
	Point2 startPosition(540, 410);
	Turtle turtle(startPosition, 270);

	for (int i = 0; i < c.size(); i++) {
		switch (c[i])
		{
		case 'f':
			turtle.setAngle(90);
			turtle.forward(15, 1);
			Sleep(20);
			break;

		case 'l':
			turtle.setAngle(180);
			turtle.forward(15, 1);
			Sleep(20);
			
			break;

		case 'r':
			turtle.setAngle(0);
			turtle.forward(15, 1);
			Sleep(20);
			break;

		case 'b':
			turtle.setAngle(270);
			turtle.forward(15, 1);
			Sleep(20);
			break;

		default:
			break;
		}

		glutSwapBuffers();
	}
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1340, 600);
	glutInitWindowPosition(5, 40);
	glutCreateWindow("MY MAP");
	myInit();
	display();
	glutMainLoop();
}

