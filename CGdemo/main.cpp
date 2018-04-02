///<summary> CG Assignment - C program to demonstrate Butterfly,Table fan, breaking News & Stars using OpenGL </summary>
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

///Libraries to Create Custom Graphics
#include"const.h"
#include"cgl.h"
#include"draw.h"
#include"butterfly.h"
#include"tablefan.h"
#include"star.h"



void disp();
void idle();
void displayStars(int);
void keyboard(unsigned char, int, int);
void passiveMouse(int,int);


int main()
{
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_DOUBLE  | GLUT_DEPTH);
	glutCreateWindow("CG Demo");
	glutDisplayFunc(disp);
	glutPassiveMotionFunc(passiveMouse);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	// Stars will be displayed with some delay
	glutTimerFunc(100, displayStars, 1);
	glutMainLoop();
}

 /// <summary>
/// Disps this instance.
/// </summary>
void disp()
{
	/// Intialize Window Properties 
	CGL_Init3D(-HALF_SCREEN_WIDTH, HALF_SCREEN_WIDTH, -HALF_SCREEN_HEIGHT, HALF_SCREEN_HEIGHT, 0, 10);

	//Draw Stars
	glPushMatrix();
	glTranslatef(-1, -1, 0.2);
	glScalef(5, 5, 1);
	drawStars();
	glPopMatrix();


	// Draw Table fan
	glDepthMask(GL_TRUE);
	glPushMatrix();	
	// Set the Position & Rotation
	glRotatef(20,-1, 1, 0);
	glTranslatef(0, 0, 0.2);
	// Set the size of the Table fan
	glScalef(0.8, 0.8, 0.8);
	
	drawTableFan();
	glPopMatrix();

	// Draw Butterfly
	glDepthMask(GL_FALSE);
	glPushMatrix();
	// Set the Position, Rotation & Size of Butterfly
	glTranslatef(BUTTERFLY_TRANSLATE_X, BUTTERFLY_TRANSLATE_Y,-0.5);
	glScalef(0.25, 0.25, 0.5);
	glRotatef(45, 1, 0, 1);
	drawButterfly();
	glPopMatrix();

	// Draw Instruction (aka Breaking News)
	if (INSTRUCTION_POS > 4)INSTRUCTION_POS = -1;
	else INSTRUCTION_POS += 0.0005;
	STRING instruction;
	instruction.text = "Press R to show/hide stars";
	glPushMatrix();
	drawTextUsing(instruction, INSTRUCTION_POS, -0.95, -0.61);
	glPopMatrix();

	glDepthMask(GL_TRUE);
	glFlush();
	glutSwapBuffers();
}


/// <summary>
/// Passive Mouse Function
/// </summary>
/// <param name="x">Mouse x.</param>
/// <param name="y">Mouse y.</param>
void passiveMouse(int x, int y)
{
	BUTTERFLY_TRANSLATE_Y = ((float)(HALF_SCREEN_HEIGHT-y)/ (HALF_SCREEN_HEIGHT));
	BUTTERFLY_TRANSLATE_X = ((float)(x - HALF_SCREEN_WIDTH)/ (HALF_SCREEN_WIDTH));
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'R' || key == 'r')
	{
		if (STARS_ENABLE == false){
			STARS_ENABLE = true;
			STARS_DISPLAY_NOW = true;
		}
		else STARS_ENABLE = false;
	}
}

void displayStars(int val)
{
	glutTimerFunc(150, displayStars, 10);
	STARS_DISPLAY_NOW = true;
	glutPostRedisplay();
}

/// <summary>
/// Called when CPU is idle
/// </summary>
void idle()
{
	glutPostRedisplay();
}


