///<summary> Custom library to draw basic OpenGl shapes </summary>
///<usage> inlcude "draw.h"</usage>
///<dependency> cgl.h, const.h, math.h, string.h</dependency>
///<author> Sachin Ganesh [sachinganesh@outlook.com]</author>

#include<math.h>
#include<string.h>

GLUquadricObj *IDquadric;

/// <summary>
/// Draws the rectangle at given 4 vertices (array)
/// </summary>
/// <param name="v0">vertice v0.</param>
/// <param name="v1">vertice v1.</param>
/// <param name="v2">vertice v2.</param>
/// <param name="v3">vertice v3.</param>
/// <param name="fillType">Type of the fill.</param>
/// <usage>drawRectangleAt(v[0], v[1], v[2],v[3],GL_QUADS)</usage>

void drawRectangleAt(float *v0, float *v1, float *v2, float *v3, GLfloat fillType)
{
	glBegin(fillType);
	glVertex3f(v0[0], v0[1], v0[2]);
	glVertex3f(v1[0], v1[1], v1[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glVertex3f(v3[0], v3[1], v3[2]);
	glEnd();
}

/// <summary>
/// Draws the shaded rectangle at given 4 vertices
/// </summary>
/// <param name="v0">The v0.</param>
/// <param name="v1">The v1.</param>
/// <param name="v2">The v2.</param>
/// <param name="v3">The v3.</param>
/// <param name="fillType">Type of the fill.</param>
/// <param name="colRed">The col red.</param>
/// <param name="colGreen">The col green.</param>
/// <param name="colBlue">The col blue.</param>
/// <usage>drawRectangleAt(v[0], v[1], v[2], v[3], GL_QUADS,0.1,0.1,0.1)< / usage>
void drawShadedRectangleAt(float *v0, float *v1, float *v2, float *v3, GLfloat fillType,float colRed,float colGreen,float colBlue)
{
	glColor3f(colRed, colGreen -0.3, colBlue - 0.5);
	glBegin(fillType);
	glVertex3f(v0[0], v0[1], v0[2]);
	glColor3f(colRed, colGreen, colBlue);
	glVertex3f(v1[0], v1[1], v1[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glVertex3f(v3[0], v3[1], v3[2]);
	glEnd();
}


/// <summary>
/// Draws the rectangle at given 4 vertices (X,Y,Z)
/// </summary>
/// <param name="p0X">The p0 x.</param>
/// <param name="p0Y">The p0 y.</param>
/// <param name="p0Z">The p0 z.</param>
/// <param name="p1X">The p1 x.</param>
/// <param name="p1Y">The p1 y.</param>
/// <param name="p1Z">The p1 z.</param>
/// <param name="p2X">The p2 x.</param>
/// <param name="p2Y">The p2 y.</param>
/// <param name="p2Z">The p2 z.</param>
/// <param name="p3X">The p3 x.</param>
/// <param name="p3Y">The p3 y.</param>
/// <param name="p3Z">The p3 z.</param>
/// <param name="fillType">Type of the fill.</param>
void drawRectangleAtV(float p0X, float p0Y, float p0Z, float p1X, float p1Y, float p1Z, float p2X, float p2Y, float p2Z, float p3X, float p3Y, float p3Z, GLfloat fillType)
{
	glBegin(fillType);
	glVertex3f(p0X, p0Y, p0Z);
	glVertex3f(p1X, p1Y, p1Z);
	glVertex3f(p2X, p2Y, p2Z);
	glVertex3f(p3X, p3Y, p3Z);
	glEnd();
}


/// <summary>
/// Draws the rectangle for passed RECT object.
/// </summary>
/// <param name="rect">RECT struct</param>
/// <param name="fillType">Type of the fill.</param>
/// <usage>RECTANGLE rect;
/// rect.posX = 0;
/// rect.posY = 0;
/// rect.posZ = 0;
/// rect.width = 0.5;
/// rect.height = 0.9;
/// drawRectangleAtPos(rect, GL_QUADS);</usage>
void drawRectangleAtPos(RECTANGLE rect, GLfloat fillType)
{
	glBegin(fillType);
	glVertex3f(rect.posX, rect.posY, rect.posZ);
	glVertex3f(rect.posX + rect.width, rect.posY, rect.posZ);
	glVertex3f(rect.posX + rect.width, rect.posY + rect.height, rect.posZ);
	glVertex3f(rect.posX, rect.posY + rect.height, rect.posZ);
	glEnd();
}

/// <summary>
/// Draws the cuboid at given 8 vertices (array)
/// </summary>
/// <param name="v0">The v0.</param>
/// <param name="v1">The v1.</param>
/// <param name="v2">The v2.</param>
/// <param name="v3">The v3.</param>
/// <param name="v4">The v4.</param>
/// <param name="v5">The v5.</param>
/// <param name="v6">The v6.</param>
/// <param name="v7">The v7.</param>
/// <param name="fillType">Type of the fill.</param>
/// <usage>drawCuboidAt(v2[0], v2[1], v2[2], v2[3], v2[4], v2[5], v2[6], v2[7], GL_POLYGON);< / usage>
void drawCuboidAt(float *v0, float *v1, float *v2, float *v3, float *v4, float *v5, float *v6, float *v7, GLfloat fillType)
{	
	drawRectangleAt(v0, v3, v2, v1, fillType);
	glColor3f(1.0, 0.5, 0.6);
	drawRectangleAt(v3, v7, v6, v2, fillType);
	glColor3f(1.0, 0.5, 1);
	drawRectangleAt(v7, v4, v5, v6, fillType);
	glColor3f(0, 0.5, 0.8);
	drawRectangleAt(v4, v0, v1, v5, fillType);
	glColor3f(1.0, 0.5, 0.9);
	drawRectangleAt(v1, v2, v6, v5, fillType);
	glColor3f(0, 0.5, 0.4);
	drawRectangleAt(v0, v3, v7, v4, fillType);
}



/// <summary>
/// Draws the cuboid at gibven position by making use of CUBE object.
/// </summary>
/// <param name="cube">The cube.</param>
/// <param name="fillType">Type of the fill.</param>
/// <usage> CUBE cube;
/// cube.posX = 0;
/// cube.posY = 0;
/// cube.posZ = 0;
/// cube.width = 0.8;
/// cube.height = 0.7;
/// cube.breadth = 0.2;
/// drawCuboidAtPos(cube, GL_QUADS);</usage>
void drawCuboidAtPos(CUBE cube, GLfloat fillType)
{
	glColor3f(1.0, 0.7, 0.1);
	drawRectangleAtV(cube.posX, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY + cube.height, cube.posZ, cube.posX, cube.posY + cube.height, cube.posZ, fillType);
	glColor3f(1.0, 0.5, 0.6);
	drawRectangleAtV(cube.posX + cube.width, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY, cube.posZ + cube.breadth, cube.posX + cube.width, cube.posY + cube.height, cube.posZ + cube.breadth, cube.posX + cube.width, cube.posY + cube.height, cube.posZ, fillType);
	glColor3f(1.0, 0, 1);
	drawRectangleAtV(cube.posX + cube.width, cube.posY, cube.posZ + cube.breadth, cube.posX , cube.posY, cube.posZ + cube.breadth, cube.posX, cube.posY + cube.height, cube.posZ + cube.breadth, cube.posX + cube.width, cube.posY + cube.height, cube.posZ + cube.breadth, fillType);
	glColor3f(0, 0.5, 0.1);
	drawRectangleAtV(cube.posX, cube.posY, cube.posZ + cube.breadth, cube.posX, cube.posY, cube.posZ, cube.posX, cube.posY + cube.height, cube.posZ, cube.posX, cube.posY + cube.height, cube.posZ + cube.breadth, fillType);
	glColor3f(1.0, 0.5, 0.2);
	drawRectangleAtV(cube.posX, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY, cube.posZ, cube.posX + cube.width, cube.posY, cube.posZ + cube.breadth, cube.posX, cube.posY, cube.posZ + cube.breadth, fillType);
	glColor3f(0, 0.5, 0.4);
	drawRectangleAtV(cube.posX, cube.posY + cube.height, cube.posZ, cube.posX + cube.width, cube.posY + cube.height, cube.posZ, cube.posX + cube.width, cube.posY + cube.height, cube.posZ + cube.breadth, cube.posX, cube.posY + cube.height, cube.posZ + cube.breadth, fillType);
}


/// <summary>
/// Draws the circle using given CIRCLE object
/// </summary>
/// <param name="circle">The CIRCLE object</param>
/// <param name="fillType">Type of the fill.</param>
/// <usage>CIRCLE c;
/// c.radius = 0.4;
/// c.transX = 0;
/// c.transY = 0;
/// c.transZ = 0;
///drawCircleUsing(c, GL_LINES);</usage>
void drawCircleUsing(CIRCLE circle,GLfloat fillType)
{
	glBegin(fillType);
	for (int i = 0; i < 180; i++)
	{
		circle.posX = circle.radius * cos((float)i);
		circle.posY = circle.radius * sin((float)i);
		glVertex3f(circle.posX + circle.transX, circle.posY + circle.transY, circle.transZ);

		circle.posX = circle.radius * cos(i + 0.1);
		circle.posY = circle.radius * sin(i + 0.1);
		glVertex3f(circle.posX + circle.transX, circle.posY + circle.transY, circle.transZ);
	}
	glEnd();

}

/// <summary>
/// Draws the cylinder using given CYLINDER object
/// </summary>
/// <param name="cylinder">The CYLINDER Object</param>
/// <param name="fillCaps">if set to <c>true</c> draws complete cylinder with filled caps. else hollow cylinder.</param>
/// <usage>CYLINDER cylinder;
/// cylinder.baseRadius = 0.15;
/// cylinder.topRadius = 0.1;
/// cylinder.height = 0.4;
/// cylinder.slices = 32;
/// cylinder.stacks = 32;
/// drawShadedCylinderUsing(cylinder, true, 1, 0.6, 0.4);</usage>
void drawCylinderUsing(CYLINDER cylinder,bool fillCaps)
{
	CIRCLE circle;
	IDquadric = gluNewQuadric();      // Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(IDquadric, GLU_SMOOTH);  // Create Smooth Normals ( NEW )
	gluQuadricTexture(IDquadric, GL_TRUE);    // Create Texture Coords ( NEW )

	gluCylinder(IDquadric,cylinder.baseRadius,cylinder.topRadius, cylinder.height, cylinder.slices, cylinder.stacks);
	if (fillCaps)
	{
		circle.radius = cylinder.baseRadius;
		circle.transX = 0;
		circle.transY = 0;
		circle.transZ = 0;
		glColor3f(1.0, 0.6, 1);
		drawCircleUsing(circle, GL_POLYGON);
		circle.radius = cylinder.topRadius;
		circle.transX = 0;
		circle.transY = 0;
		circle.transZ = cylinder.height;
		glColor3f(1.0, 0.6, 1);
		drawCircleUsing(circle, GL_POLYGON);
	}

}

void drawShadedCylinderUsing(CYLINDER cylinder, bool fillCaps, float colRed, float colGreen, float colBlue)
{
	CIRCLE circle;
	IDquadric = gluNewQuadric();      // Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(IDquadric, GLU_SMOOTH);  // Create Smooth Normals ( NEW )
	gluQuadricTexture(IDquadric, GL_TRUE);    // Create Texture Coords ( NEW )
	glColor3f(colRed, colGreen, colBlue);
	gluCylinder(IDquadric, cylinder.baseRadius, cylinder.topRadius, cylinder.height, cylinder.slices, cylinder.stacks);
	if (fillCaps)
	{
		circle.radius = cylinder.baseRadius;
		circle.transX = 0;
		circle.transY = 0;
		circle.transZ = 0;
		glColor3f(colRed - 0.05, colGreen -0.15, colBlue-0.15);
		drawCircleUsing(circle, GL_POLYGON);
		circle.radius = cylinder.topRadius;
		circle.transX = 0;
		circle.transY = 0;
		circle.transZ = cylinder.height;
		glColor3f(colRed -0.05, colGreen -0.15, colBlue-0.15);
		drawCircleUsing(circle, GL_POLYGON);
	}

}


/// <summary>
/// Draws the cubic bezire curve using CURVE object
/// </summary>
/// <param name="curve">The CURVE object</param>
/// <param name="fillType">Type of the fill.</param>
/// <usage>CURVE curve;
/// curve.p1.x = 0; curve.p1.y = 0.2; curve.p1.z = -0.1;
/// curve.p2.x = 0.8; curve.p2.y = 0.8; curve.p2.z = -0.1;
/// curve.p3.x = 1.5; curve.p3.y = 0.0; curve.p3.z = -0.1;
/// curve.p4.x = 0; curve.p4.y = -0.4; curve.p4.z = -0.1;
/// drawCubicCurveUsing(curve, GL_POLYGON);</usage>
void drawCubicCurveUsing(CURVE curve,  GLfloat fillType)
{
	glBegin(fillType);
	for (float t = 0; t <= 1; t += 0.01) 
	{
		float x = (1 - t)*(1 - t)*(1 - t)*curve.p1.x + 3 * (1 - t)*(1 - t)*t*curve.p2.x + 2 * (1 - t)* t*t*curve.p3.x + t*t*t*curve.p4.x;
		float y = (1 - t)*(1 - t)*(1 - t)*curve.p1.y + 3 * (1 - t)*(1 - t)*t*curve.p2.y + 2 * (1 - t)* t*t*curve.p3.y + t*t*t*curve.p4.y;
		float z = (1 - t)*(1 - t)*(1 - t)*curve.p1.z + 3 * (1 - t)*(1 - t)*t*curve.p2.z + 2 * (1 - t)* t*t*curve.p3.z + t*t*t*curve.p4.z;
		glVertex3f(x, y, z);
	}glEnd();
}


/// <summary>
/// Draws the cubic bezire curve using CURVE object
/// </summary>
/// <param name="curve">The CURVE object</param>
/// <param name="fillType">Type of the fill.</param>
/// <usage>CURVE curve;
/// curve.p1.x = 0; curve.p1.y = 0.2; curve.p1.z = -0.1;
/// curve.p2.x = 0.8; curve.p2.y = 0.8; curve.p2.z = -0.1;
/// curve.p3.x = 1.5; curve.p3.y = 0.0; curve.p3.z = -0.1;
/// drawQuadraticCurveUsing(curve, GL_POLYGON);</usage>

void drawQuadraticCurveUsing(CURVE curve, GLfloat fillType)
{
	glBegin(fillType);
	for (float t = 0; t <= 1; t += 0.05)
	{
		float x = (1 - t)*(1 - t)*curve.p1.x + 2 * (1 - t)*t*curve.p2.x + t*t*curve.p3.x;
		float y = (1 - t)*(1 - t)*curve.p1.y + 2 * (1 - t)*t*curve.p2.y + t*t*curve.p3.y;
		float z = (1 - t)*(1 - t)*curve.p1.z + 2 * (1 - t)*t*curve.p2.z + t*t*curve.p3.z;
		glVertex3f(x, y, z);
	}glEnd();
}

void drawTextUsing(STRING s, float x, float y, float z)
{
	glRasterPos3f(x, y, z);	
	for (unsigned int i = 0; i < strlen(s.text); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s.text[i]);
	}
}