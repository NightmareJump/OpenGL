/***********************************************************************************************

	File:			Assignment1.c

	Description:	A complete OpenGL program to draw a M and it can change to 5-pointed star,
					generate a sparkle and has toggle button

	Author:			Yanyue Meng

	Stduent ID:		B00797115

**********************************************************************************************/


/* include the library header files */
#include <freeglut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265	//define PI
#define DEG_TO_RAD PI/180.0		//define DEG_TO_RAD as PI/180

// angle of rotation
GLfloat theta = 0;
// distinguish different sparkle way
GLint moveEdge = 0;
//mouse position in OpenGL coordinates
GLfloat mouseX, mouseY;	
//the height of window
GLint windowHeight = 900;
//the width of window
GLint windowWidth = 900;
//midpoint of the sparlke move
GLfloat midPointX[] = { 0 };
GLfloat midPointY[] = { 0 };
// a point data type
typedef GLfloat pointM[2];
// a couple points to interpolate
// a couple points to interpolate
pointM point1A = { 1.5,1 }; // a M point
pointM point1B = { 2.1,1.4 };// a 5-ponted star

pointM point2A = { 1.5,1.7 };// a M point
pointM point2B = { 1.5,1.7 };// a 5-ponted star

pointM point3A = { 1.5,2 };// a M point
pointM point3B = { 2.2,1.7 };// a 5-ponted star

pointM point4A = { 1.7,1 };// a M point
pointM point4B = { 2,1 };// a 5-ponted star

pointM point5A = { 1.7,1.7 };// a M point
pointM point5B = { 2.5,1.3 };// a 5-ponted star

pointM point6A = { 1.7,2 };// a M point
pointM point6B = { 2.2,1.7 };// a 5-ponted star

pointM point7A = { 2.5,1 };// a M point
pointM point7B = { 2.5,1.3 };// a 5-ponted star

pointM point8A = { 2.5,1.3 };// a M point
pointM point8B = { 2.5,2 };// a 5-ponted star

pointM point9A = { 3.3,1 };// a M point
pointM point9B = { 3,1 };// a 5-ponted star

pointM point10A = { 3.3,1.7 };// a M point
pointM point10B = { 2.5,1.3 };// a 5-ponted star

pointM point11A = { 3.3,2 };// a M point
pointM point11B = { 2.8,1.7 };// a 5-ponted star

pointM point12A = { 3.5,1 };// a M point
pointM point12B = { 2.9,1.4 };// a 5-ponted star

pointM point13A = { 3.5,1.7 };// a M point
pointM point13B = { 3.5,1.7 };// a 5-ponted star

pointM point14A = { 3.5,2 };// a M point
pointM point14B = { 2.8,1.7 };// a 5-ponted star
// interpolation variable
// if 0 then at A
// if 1 then at B
GLfloat interp = 0.0;
//judge whether star need to come back to M
GLint interpJudge = 0;
//interpolation variable
GLfloat traceJudge = 0.0;
//judge in which part of star or M
GLint count = 0;

// frequency in different part of star or M
GLfloat sparkFrequncy1 = 0; // speed in one of part of star or M
GLfloat sparkFrequncy2 = 0;// speed in one of part of star or M
GLfloat sparkFrequncy3 = 0;// speed in one of part of star or M
GLfloat sparkFrequncy4 = 0;// speed in one of part of star or M
GLfloat sparkFrequncy5 = 0;// speed in one of part of star or M
GLfloat sparkFrequncy6 = 0;// speed in one of part of star or M
GLfloat sparkFrequncy7 = 0;// speed in one of part of star or M
GLfloat sparkFrequncy8 = 0;// speed in one of part of star or M
GLfloat sparkFrequncy9 = 0;// speed in one of part of star or M
GLfloat sparkFrequncy10 = 0;// speed in one of part of star or M
GLfloat sakuraSpeed = 0;

// sparkle switch
int sparkle = 0;
//sparks switch
int sparks = 0;
//	morph switch
int morph = 0;
//	sakuraRain switch
int sakuraRain = 0;
// Random variables for the spark speeds, colors, and direction
float randColor1; //one of random color
float randColor2; //one of random color
float randColor3; //one of random color
float randX; //give a random position
float randY;//give a random position
int direction = 0; //judge whether has this spark line


float randColor1_2; //one of random color
float randColor2_2; //one of random color
float randColor3_2; //one of random color
float randX_2;//give a random position
float randY_2;//give a random position
int direction2 = 0;//judge whether has this spark line

float randColor1_3; //one of random color
float randColor2_3;//one of random color
float randColor3_3;//one of random color
float randX_3;//give a random position
float randY_3;//give a random position
int direction3 = 0;//judge whether has this spark line

float randColor1_4;//one of random color
float randColor2_4;//one of random color
float randColor3_4;//one of random color
float randX_4;//give a random position
float randY_4;//give a random position
int direction4 = 0;//judge whether has this spark line

float randColor1_5;//one of random color
float randColor2_5;//one of random color
float randColor3_5;//one of random color
float randX_5;//give a random position
float randY_5;//give a random position
int direction5 = 0;//judge whether has this spark line

float randColor1_6;//one of random color
float randColor2_6;//one of random color
float randColor3_6;//one of random color
float randX_6;//give a random position
float randY_6;//give a random position
int direction6 = 0;//judge whether has this spark line

float randColor1_7;//one of random color
float randColor2_7;//one of random color
float randColor3_7;//one of random color
float randX_7;//give a random position
float randY_7;//give a random position
int direction7 = 0;//judge whether has this spark line

float randColor1_8;//one of random color
float randColor2_8;//one of random color
float randColor3_8;//one of random color
float randX_8;//give a random position
float randY_8;//give a random position
int direction8 = 0;//judge whether has this spark line

float randColor1_9;//one of random color
float randColor2_9;//one of random color
float randColor3_9;//one of random color
float randX_9;//give a random position
float randY_9;//give a random position
int direction9 = 0;//judge whether has this spark line

float randColor1_10;//one of random color
float randColor2_10;//one of random color
float randColor3_10;//one of random color
float randX_10;//give a random position
float randY_10;//give a random position
int direction10 = 0;//judge whether has this spark line

/************************************************************************************************

	Function:		initializeGL
	
	Description:	Initializes the OpenGL rendering context for display.

*************************************************************************************************/
void initializeGL(void)
{
	//set background color to be black
	glClearColor(0, 0, 0, 1.0);
	// set martrix mode as GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//set window mode to 2D orthographic and set the drawing coordinates
	gluOrtho2D(0,5,0,2.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	

}

/*************************************************************************************************

	Function:		myIdle

	Description:	Updates the animation when idle
**************************************************************************************************/
void myIdle(void)
{
	sparkFrequncy1 += 0.0005; //set the speed of sparkFrequncy1
	sparkFrequncy2 += 0.0005; //set the speed of sparkFrequncy2
	sparkFrequncy3 += 0.0005; //set the speed of sparkFrequncy3
	sparkFrequncy4 += 0.0005; //set the speed of sparkFrequncy4
	sparkFrequncy5 += 0.0005; //set the speed of sparkFrequncy5
	sparkFrequncy6 +=0.0005; //set the speed of sparkFrequncy6
	sparkFrequncy7 += 0.0005; //set the speed of sparkFrequncy7
	sparkFrequncy8 += 0.0005; //set the speed of sparkFrequncy8
	sparkFrequncy9 += 0.0005; //set the speed of sparkFrequncy9
	sparkFrequncy10 += 0.0005; //set the speed of sparkFrequncy10
	
	//judge whether the sakura switch is on
	if (sakuraRain == 1)
	{
		sakuraSpeed += 0.05; // set the speed of sakuraRain
		if (sakuraSpeed >= 45) // if sakuraSpeed larger than 45, then cycle
			sakuraSpeed = 0;
	}
	
	if (sparkFrequncy1 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3 = (float)rand() / (RAND_MAX); // give a random B number
		randX = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY = (rand() % 10) *(((rand() % 3) - 1)); //give a random Y position
		direction = rand() % 2; // give a random 0 or 1 to judge whether has this line
	}
	if (sparkFrequncy1 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy1 = 0.0; // make it come back to 0
	}

	if (sparkFrequncy2 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_2 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_2 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_2 = (float)rand() / (RAND_MAX); // give a random B number
		randX_2 = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY_2 = (rand() % 10) *(((rand() % 3) - 1));//give a random Y position
		direction2 = rand() % 2; // give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy2 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy2 = 0.0;  // make it come back to 0
	}

	if (sparkFrequncy3 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_3 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_3 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_3 = (float)rand() / (RAND_MAX); // give a random B number
		randX_3 = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY_3 = (rand() % 10) *(((rand() % 3) - 1)); //give a random Y position
		direction3 = rand() % 2; // give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy3 >= 1.0) {// judge whether sparkfrenquecy larger than 1 
		sparkFrequncy3 = 0.0;  // make it come back to 0
	}

	if (sparkFrequncy4 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_4 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_4 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_4 = (float)rand() / (RAND_MAX); // give a random B number
		randX_4 = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY_4 = (rand() % 10) *(((rand() % 3) - 1)); //give a random Y position
		direction4 = rand() % 2; // give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy4 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy4 = 0.0;  // make it come back to 0
	}

	if (sparkFrequncy5 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_5 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_5 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_5 = (float)rand() / (RAND_MAX); // give a random B number
		randX_5 = (rand() % 10) * ((rand() % 3) - 1);//give a random X position
		randY_5 = (rand() % 10) *(((rand() % 3) - 1)); //give a random Y position
		direction5 = rand() % 2;// give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy5 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy5 = 0.0; // make it come back to 0
	}

	if (sparkFrequncy6 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_6 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_6 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_6 = (float)rand() / (RAND_MAX); // give a random B number
		randX_6 = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY_6 = (rand() % 10) *(((rand() % 3) - 1));//give a random Y position
		direction6 = rand() % 2;// give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy6 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy6 = 0.0; // make it come back to 0
	}

	if (sparkFrequncy7 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_7 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_7 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_7 = (float)rand() / (RAND_MAX); // give a random B number
		randX_7 = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY_7 = (rand() % 10) *(((rand() % 3) - 1));//give a random Y position
		direction7 = rand() % 2;// give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy7 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy7 = 0.0; // make it come back to 0
	}

	if (sparkFrequncy8 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_8 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_8 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_8 = (float)rand() / (RAND_MAX); // give a random B number
		randX_8 = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY_8 = (rand() % 10) *(((rand() % 3) - 1));//give a random Y position
		direction8 = rand() % 2;// give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy8 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy8 = 0.0; // make it come back to 0
	}

	if (sparkFrequncy9 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_9 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_9 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_9 = (float)rand() / (RAND_MAX); // give a random B number
		randX_9 = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY_9 = (rand() % 10) *(((rand() % 3) - 1));//give a random Y position
		direction9 = rand() % 2;// give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy9 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy9 = 0.0; // make it come back to 0
	}

	if (sparkFrequncy10 >= (float)rand() / (RAND_MAX)) { // give sparkle a random position 
		randColor1_10 = (float)rand() / (RAND_MAX); //give a random R number
		randColor2_10 = (float)rand() / (RAND_MAX); //give a random G number
		randColor3_10 = (float)rand() / (RAND_MAX); // give a random B number
		randX_10 = (rand() % 10) * ((rand() % 3) - 1); //give a random X position
		randY_10 = (rand() % 10) *(((rand() % 3) - 1)); //give a random Y position
		direction10 = rand() % 2;// give a random 0 or 1 to judge whether has this line
	}

	if (sparkFrequncy10 >= 1.0) { // judge whether sparkfrenquecy larger than 1 
		sparkFrequncy10 = 0.0; // make it come back to 0
	}
	
	if (morph == 0) //judge whether need to morph
	{
		interp = 0; //make the M static 
	}
		// judge whether need to become star
	else 
	{
		if (interpJudge == 1)
			// increase the number of interp to change position of the point
			interp += 0.005;
		// judge whether need to come back to M
		else if (interpJudge == 0)
			// decrease the vaule of interp to change position of the point
			interp -= 0.005;
		// if has become a star, make it come back to M
		if (interp >= 1.0 && interpJudge == 1) {
			// make the interp<1
			interp = 0.9999;
			// to make it do the instruction of becoming M
			interpJudge = 0;
		}
		// if it is a M , make ti become star
		else if (interp <= 0.0 && interpJudge == 0) {
			// make the interp >0
			interp = 0.0001;
			//to make it do the instruction of becoming star
			interpJudge = 1;
		}
	}
	//jugdge whether sparkle is on
	if (sparkle == 1)
	{
		traceJudge += 0.005; //update the move of sparkle
		// update the angle of rotation 
		theta += 0.5;
		if (traceJudge >= 1.0 && count == 14) { //judge whether sparkle has finish a cycle
			traceJudge = 0.0; //initialize traceJudge
			count = 0; // initialize count
		}
		else if (traceJudge >= 1.0) { // judge whether finish a part of M or star
			traceJudge = 0.0; //initialize the traceJudge
			count++; //increase the number of count
		}

		// if we have done a full turn, start at zero again
		if (theta >= 360.0)
			theta -= 360.0;
	}
	else
	{
		traceJudge = 0;
		// update the angle of rotation 
		theta = 0;
	}
	// now force OpenGL to redraw the change
	glutPostRedisplay();


}


/*************************************************************************************************

	Function:		display

	Description:	Dispaly shape of M

**************************************************************************************************/
void display(void)
{
	// clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	// set the drawing to be white
	glColor3f(1, 1, 1);

	
		//draw a polygon
		glBegin(GL_POLYGON);
		// set the drawing to be red
		glColor3f(1, 0, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point1A[0] + interp * point1B[0],
			(1 - interp) * point1A[1] + interp * point1B[1]);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point4A[0] + interp * point4B[0],
			(1 - interp) * point4A[1] + interp * point4B[1]);
		// set the drawing to be reddish
		glColor3f(0.7, 0.7, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point5A[0] + interp * point5B[0],
			(1 - interp) * point5A[1] + interp * point5B[1]);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point2A[0] + interp * point2B[0],
			(1 - interp) * point2A[1] + interp * point2B[1]);
		glEnd();

		// draw a polygon
		glBegin(GL_POLYGON);
		// set the drawing to be reddish
		glColor3f(0.7, 0.7, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point5A[0] + interp * point5B[0],
			(1 - interp) * point5A[1] + interp * point5B[1]);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point2A[0] + interp * point2B[0],
			(1 - interp) * point2A[1] + interp * point2B[1]);
		// set the drawing to be yellow
		glColor3f(1, 1, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point3A[0] + interp * point3B[0],
			(1 - interp) * point3A[1] + interp * point3B[1]);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point6A[0] + interp * point6B[0],
			(1 - interp) * point6A[1] + interp * point6B[1]);
		glEnd();

		//draw a polygon
		glBegin(GL_POLYGON);
		// set the drawing to be yellow
		glColor3f(1, 1, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point6A[0] + interp * point6B[0],
			(1 - interp) * point6A[1] + interp * point6B[1]);
		// set the drawing to be reddish
		glColor3f(0.7, 0.7, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point5A[0] + interp * point5B[0],
			(1 - interp) * point5A[1] + interp * point5B[1]);
		// set the drawing to be red
		glColor3f(1, 0, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point7A[0] + interp * point7B[0],
			(1 - interp) * point7A[1] + interp * point7B[1]);
		// set the drawing to be reddish
		glColor3f(1, 0.5, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point8A[0] + interp * point8B[0],
			(1 - interp) * point8A[1] + interp * point8B[1]);
		glEnd();

		// draw a polygon
		glBegin(GL_POLYGON);
		// set the drawing to be red
		glColor3f(1, 0, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point7A[0] + interp * point7B[0],
			(1 - interp) * point7A[1] + interp * point7B[1]);
		// set the drawing to be reddish
		glColor3f(1, 0.5, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point8A[0] + interp * point8B[0],
			(1 - interp) * point8A[1] + interp * point8B[1]);
		// set the drawing to be yellow
		glColor3f(1, 1, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point11A[0] + interp * point11B[0],
			(1 - interp) * point11A[1] + interp * point11B[1]);
		// set the drawing to be yellow
		glColor3f(0.7, 0.7, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point10A[0] + interp * point10B[0],
			(1 - interp) * point10A[1] + interp * point10B[1]);
		glEnd();

		// draw a polygon
		glBegin(GL_POLYGON);
		// set the drawing to be yellow 
		glColor3f(1, 1, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point11A[0] + interp * point11B[0],
			(1 - interp) * point11A[1] + interp * point11B[1]);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point14A[0] + interp * point14B[0],
			(1 - interp) * point14A[1] + interp * point14B[1]);
		// set the drawing to be yellow
		glColor3f(0.7, 0.7, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point13A[0] + interp * point13B[0],
			(1 - interp) * point13A[1] + interp * point13B[1]);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point10A[0] + interp * point10B[0],
			(1 - interp) * point10A[1] + interp * point10B[1]);
		glEnd();

		// draw a polygon
		glBegin(GL_POLYGON);
		// set the drawing to be yellow 
		glColor3f(1, 0, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point12A[0] + interp * point12B[0],
			(1 - interp) * point12A[1] + interp * point12B[1]);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point9A[0] + interp * point9B[0],
			(1 - interp) * point9A[1] + interp * point9B[1]);
		//set the drawing to be a little yellow
		glColor3f(0.7, 0.7, 0);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point10A[0] + interp * point10B[0],
			(1 - interp) * point10A[1] + interp * point10B[1]);
		//set one of the point of the graphic
		glVertex2f((1 - interp) * point13A[0] + interp * point13B[0],
			(1 - interp) * point13A[1] + interp * point13B[1]);
		glEnd();
	
	// turn on smooth make line smooth
	glEnable(GL_SMOOTH);
	//make line smooth
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	// turn on transparency blending
	glEnable(GL_BLEND);
	// set the blending mode to be controlled by ALPHA
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// set the width of line as 2
	glLineWidth(2);
	//judge whether sparkle is on
	if (sparkle == 1)
	{
		if (count == 0) { //judge whether is the first part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point3A[0] + (interp)*point3B[0])) + (traceJudge*((1 - interp)*point6A[0] + (interp)*point6B[0])) - 1.5; //set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point3A[1] + (interp)*point3B[1]))) + (traceJudge*(((1 - interp)*point6A[1] + (interp)*point6B[1]))) - 2;//set the y value of moving spark
		} 
		if (count == 1) {//judge whether is the second part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point6A[0] + (interp)*point6B[0])) + (traceJudge*((1 - interp)*point8A[0] + (interp)*point8B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point6A[1] + (interp)*point6B[1]))) + (traceJudge*(((1 - interp)*point8A[1] + (interp)*point8B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 2) {//judge whether is the third part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point8A[0] + (interp)*point8B[0])) + (traceJudge*((1 - interp)*point11A[0] + (interp)*point11B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point8A[1] + (interp)*point8B[1]))) + (traceJudge*(((1 - interp)*point11A[1] + (interp)*point11B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 3) {//judge whether is the forth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point11A[0] + (interp)*point11B[0])) + (traceJudge*((1 - interp)*point14A[0] + (interp)*point14B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point11A[1] + (interp)*point11B[1]))) + (traceJudge*(((1 - interp)*point14A[1] + (interp)*point14B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 4) {//judge whether is the fifth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point14A[0] + (interp)*point14B[0])) + (traceJudge*((1 - interp)*point13A[0] + (interp)*point13B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point14A[1] + (interp)*point14B[1]))) + (traceJudge*(((1 - interp)*point13A[1] + (interp)*point13B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 5) {//judge whether is the sixth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point13A[0] + (interp)*point13B[0])) + (traceJudge*((1 - interp)*point12A[0] + (interp)*point12B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point13A[1] + (interp)*point13B[1]))) + (traceJudge*(((1 - interp)*point12A[1] + (interp)*point12B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 6) {//judge whether is the seventh part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point12A[0] + (interp)*point12B[0])) + (traceJudge*((1 - interp)*point9A[0] + (interp)*point9B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point12A[1] + (interp)*point12B[1]))) + (traceJudge*(((1 - interp)*point9A[1] + (interp)*point9B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 7) {//judge whether is the eighth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point9A[0] + (interp)*point9B[0])) + (traceJudge*((1 - interp)*point10A[0] + (interp)*point10B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point9A[1] + (interp)*point9B[1]))) + (traceJudge*(((1 - interp)*point10A[1] + (interp)*point10B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 8) {//judge whether is the ninth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point10A[0] + (interp)*point10B[0])) + (traceJudge*((1 - interp)*point7A[0] + (interp)*point7B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point10A[1] + (interp)*point10B[1]))) + (traceJudge*(((1 - interp)*point7A[1] + (interp)*point7B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 9) {//judge whether is the tenth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point7A[0] + (interp)*point7B[0])) + (traceJudge*((1 - interp)*point5A[0] + (interp)*point5B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point7A[1] + (interp)*point7B[1]))) + (traceJudge*(((1 - interp)*point5A[1] + (interp)*point5B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 10) {//judge whether is the eleventh part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point5A[0] + (interp)*point5B[0])) + (traceJudge*((1 - interp)*point5A[0] + (interp)*point5B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point5A[1] + (interp)*point5B[1]))) + (traceJudge*(((1 - interp)*point5A[1] + (interp)*point5B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 11) {//judge whether is the twelveth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point5A[0] + (interp)*point5B[0])) + (traceJudge*((1 - interp)*point4A[0] + (interp)*point4B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point5A[1] + (interp)*point5B[1]))) + (traceJudge*(((1 - interp)*point4A[1] + (interp)*point4B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 12) {//judge whether is the thirteenth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point4A[0] + (interp)*point4B[0])) + (traceJudge*((1 - interp)*point1A[0] + (interp)*point1B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point4A[1] + (interp)*point4B[1]))) + (traceJudge*(((1 - interp)*point1A[1] + (interp)*point1B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 13) {//judge whether is the forthteenth part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point1A[0] + (interp)*point1B[0])) + (traceJudge*((1 - interp)*point2A[0] + (interp)*point2B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point1A[1] + (interp)*point1B[1]))) + (traceJudge*(((1 - interp)*point2A[1] + (interp)*point2B[1]))) - 2;//set the y value of moving spark
		}
		if (count == 14) {//judge whether is the last part
			midPointX[0] = (GLfloat)((1 - traceJudge)*((1 - interp)*point2A[0] + (interp)*point2B[0])) + (traceJudge*((1 - interp)*point3A[0] + (interp)*point3B[0])) - 1.5;//set the x value of moving spark
			midPointY[0] = (GLfloat)((1 - traceJudge)*(((1 - interp)*point2A[1] + (interp)*point2B[1]))) + (traceJudge*(((1 - interp)*point3A[1] + (interp)*point3B[1]))) - 2;//set the y value of moving spark
		}
		// enter GL_MODELVIEW mode so that we can change the 2D coordinates 
		glMatrixMode(GL_MODELVIEW);
		// clear the projection matrix
		glLoadIdentity(); //load matrix
		glPushMatrix();//push data into matrix 
		glTranslatef(midPointX[0], midPointY[0], 0); //translate point
		
		// draw a partly transparent line
		glBegin(GL_LINES);
		// set the drawing to be non-transparent white
		glColor4f(1, 1, 1, 1);
		// draw one vertex
		glVertex2f(1.5, 2);
		glColor4f(1, 1, 1, 0);// set the drawing to be transparent white
		glVertex2f(0.1*cos(DEG_TO_RAD * (theta + 180)) + 1.4, 0.1*sin(DEG_TO_RAD * (theta + 180)) + 2);//draw a rotative vertex
		
		// draw a partly transparent line
		glBegin(GL_LINES);
		// set the drawing to be non-transparent white
		glColor4f(1, 1, 1, 1);
		glVertex2f(1.5, 2);// draw one vertex
		glColor4f(1, 1, 1, 0);// set the drawing to be transparent white
		glVertex2f(0.1*cos(DEG_TO_RAD * theta) + 1.6, 0.1*sin(DEG_TO_RAD * theta) + 2);//draw a rotative vertex
		
		// draw a partly transparent line
		glBegin(GL_LINES);
		// set the drawing to be non-transparent white
		glColor4f(1, 1, 1, 1);
		glVertex2f(1.5, 2);// draw one vertex
		glColor4f(1, 1, 1, 0);// set the drawing to be transparent white
		glVertex2f(0.1*cos(DEG_TO_RAD * (theta + 90)) + 1.5, 0.1*sin(DEG_TO_RAD * (theta + 90)) + 2.1);//draw a rotative vertex
		
		// draw a partly transparent line
		glBegin(GL_LINES);
		// set the drawing to be non-transparent white
		glColor4f(1, 1, 1, 1);
		glVertex2f(1.5, 2);// draw one vertex
		glColor4f(1, 1, 1, 0);// set the drawing to be transparent white
		glVertex2f(0.1*cos(DEG_TO_RAD * (theta + 270)) + 1.5, 0.1*sin(DEG_TO_RAD * (theta + 270)) + 1.9);//draw a rotative vertex
		
		// draw a partly transparent line
		glBegin(GL_LINES);
		// set the drawing to be non-transparent white
		glColor4f(1, 1, 1, 1);
		glVertex2f(1.5, 2);	// draw one vertex
		glColor4f(1, 1, 1, 0);// set the drawing to be transparent white
		glVertex2f(0.1*cos(DEG_TO_RAD * (theta + 135)) + 1.4, 0.1*sin(DEG_TO_RAD * (theta + 135)) + 2.1);//draw a rotative vertex
		
		// draw a partly transparent line
		glBegin(GL_LINES);
		// set the drawing to be non-transparent white
		glColor4f(1, 1, 1, 1);
		glVertex2f(1.5, 2);	// draw one vertex
		glColor4f(1, 1, 1, 0);// set the drawing to be transparent white
		glVertex2f(0.1*cos(DEG_TO_RAD * (theta + 225)) + 1.4, 0.1* sin(DEG_TO_RAD * (theta + 225)) + 1.9);//draw a rotative vertex
		
		// draw a partly transparent line
		glBegin(GL_LINES);
		// set the drawing to be non-transparent white
		glColor4f(1, 1, 1, 1);
		glVertex2f(1.5, 2);	// draw one vertex
		glColor4f(1, 1, 1, 0);// set the drawing to be transparent white
		glVertex2f(0.1*cos(DEG_TO_RAD * (theta + 45)) + 1.6, 0.1*sin(DEG_TO_RAD *(theta + 45)) + 2.1);//draw a rotative vertex
		
		// draw a partly transparent line
		glBegin(GL_LINES);
		// set the drawing to be non-transparent white
		glColor4f(1, 1, 1, 1);
		glVertex2f(1.5, 2);	// draw one vertex
		glColor4f(1, 1, 1, 0);// set the drawing to be transparent white
		glVertex2f(0.1*cos(DEG_TO_RAD * (theta + 315)) + 1.6, 0.1*sin(DEG_TO_RAD * (theta + 315)) + 1.9);//draw a rotative vertex

		glEnd();
		glPopMatrix(); //pop the matrix
	}
	
	glLineWidth(2.0); //make the line width as 2.0
	if (sparks == 1 && sparkle ==1) //judge whether sparks and sparkle is on
	{

		if (direction) { //judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1, randColor2, randColor3, 0);//set a random color
			glVertex2f(1.5, 2); // set a vertex
			glColor4f(randColor1, randColor2, randColor3, 1.0);//set a random color
			glVertex2f((sparkFrequncy1)*randX, (sparkFrequncy1)*randY + 1); //set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
		if (direction2) { //judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_2, randColor2_2, randColor3_2, 0);//set a random color
			glVertex2f(1.5, 2);// set a vertex
			glColor4f(randColor1_2, randColor2_2, randColor3_2, 1.0);//set a random color
			glVertex2f((sparkFrequncy2)*randX_2, (sparkFrequncy2)*randY_2);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
		if (direction3) {//judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_3, randColor2_3, randColor3_3, 0);//set a random color
			glVertex2f(1.5, 2);// set a vertex
			glColor4f(randColor1_3, randColor2_3, randColor3_3, 1.0);//set a random color
			glVertex2f((sparkFrequncy3)*randX_3, (sparkFrequncy3)*randY_3);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
		if (direction4) {//judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_4, randColor2_4, randColor3_4, 0);//set a random color
			glVertex2f(1.5, 2);// set a vertex
			glColor4f(randColor1_4, randColor2_4, randColor3_4, 1.0);//set a random color
			glVertex2f((sparkFrequncy4)*randX_4, (sparkFrequncy4)*randY_4);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
		if (direction5) {//judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_5, randColor2_5, randColor3_5, 0);//set a random color
			glVertex2f(1.5, 2);// set a vertex
			glColor4f(randColor1_5, randColor2_5, randColor3_5, 1.0);//set a random color
			glVertex2f((sparkFrequncy5)*randX_5, (sparkFrequncy5)*randY_5);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
		if (direction6) {//judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_6, randColor2_6, randColor3_6, 0);//set a random color
			glVertex2f(1.5, 2);// set a vertex
			glColor4f(randColor1_6, randColor2_6, randColor3_6, 1.0);//set a random color
			glVertex2f((sparkFrequncy6)*randX_6, (sparkFrequncy6)*randY_6);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
		if (direction7) {//judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_7, randColor2_7, randColor3_7, 0);//set a random color
			glVertex2f(1.5, 2);// set a vertex
			glColor4f(randColor1_7, randColor2_7, randColor3_7, 1.0);//set a random color
			glVertex2f((sparkFrequncy7)*randX_7, (sparkFrequncy7)*randY_7);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
		if (direction8) {//judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_8, randColor2_8, randColor3_8, 0);//set a random color
			glVertex2f(1.5, 2);// set a vertex
			glColor4f(randColor1_8, randColor2_8, randColor3_8, 1.0);//set a random color
			glVertex2f((sparkFrequncy8)*randX_8, (sparkFrequncy8)*randY_8);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}

		if (direction9) {//judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_9, randColor2_9, randColor3_9, 0);//set a random color
			glVertex2f(1.5, 2);
			glColor4f(randColor1_9, randColor2_9, randColor3_9, 1.0);//set a random color
			glVertex2f((sparkFrequncy9)*randX_9, (sparkFrequncy9)*randY_9);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
		if (direction10) {//judge whether it is true
			glPushMatrix();//push data into matrix
			glTranslatef(midPointX[0], midPointY[0], 0);//translate the point
			glBegin(GL_LINES);//draw a line
			glColor4f(randColor1_10, randColor2_10, randColor3_10, 0);//set a random color
			glVertex2f(1.5, 2);
			glColor4f(randColor1_10, randColor2_10, randColor3_10, 1.0);//set a random color
			glVertex2f((sparkFrequncy10)*randX_10, (sparkFrequncy10)*randY_10);//set a random vertex
			glEnd();
			glPopMatrix();//pop the matrix
		}
	}

	glShadeModel(GL_SMOOTH); //enable the shademodel smooth
	
	if (morph == 0) //judge the state of morph button
	{
		glColor4f(1, 0, 0, 1); //set a non-transparent color
		glBegin(GL_QUADS); //draw a quads
		glVertex2f(0.5, 0.45); //set a vertex of button
		glVertex2f(1.7, 0.45);//set a vertex of button
		glVertex2f(1.7, 0.65);//set a vertex of button
		glVertex2f(0.5, 0.65);//set a vertex of button
		glEnd();

		glBegin(GL_LINE_STRIP);//draw a line strip
		glVertex2f(0.5, 0.45);//set a vertex of strip
		glVertex2f(1.7, 0.45);//set a vertex of strip
		glVertex2f(1.7, 0.65);//set a vertex of strip
		glVertex2f(0.5, 0.65);//set a vertex of strip
		glEnd();
	}
	else {
		glColor4f(1, 0, 0, 0.5f);//set a transparent color
		glBegin(GL_QUADS);//draw a quads
		glVertex2f(0.5, 0.45);//set a vertex of button
		glVertex2f(1.7, 0.45);//set a vertex of button
		glVertex2f(1.7, 0.65);//set a vertex of button
		glVertex2f(0.5, 0.65);//set a vertex of button
		glEnd();

		glBegin(GL_LINE_STRIP);//draw a line strip
		glVertex2f(0.5, 0.45);//set a vertex of strip
		glVertex2f(1.7, 0.45);//set a vertex of strip
		glVertex2f(1.7, 0.65);//set a vertex of strip
		glVertex2f(0.5, 0.65);//set a vertex of strip
		glEnd();
	}

	if (sparkle == 0)
	{
		glBegin(GL_QUADS);//draw a quads
		glColor4f(0, 1, 0, 1);//set a non-transparent color
		glVertex2f(1.9, 0.45);//set a vertex of button
		glVertex2f(1.9, 0.65);//set a vertex of button
		glVertex2f(3.1, 0.65);//set a vertex of button
		glVertex2f(3.1, 0.45);//set a vertex of button
		glEnd();

		glBegin(GL_LINE_STRIP);//draw a line strip
		glVertex2f(1.9, 0.45);//set a vertex of strip
		glVertex2f(1.9, 0.65);//set a vertex of strip
		glVertex2f(3.1, 0.65);//set a vertex of strip
		glVertex2f(3.1, 0.45);//set a vertex of strip
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);//draw a quads
		glColor4f(0, 1, 0, 0.5f);//set a transparent color
		glVertex2f(1.9, 0.45);//set a vertex of button
		glVertex2f(1.9, 0.65);//set a vertex of button
		glVertex2f(3.1, 0.65);//set a vertex of button
		glVertex2f(3.1, 0.45);//set a vertex of button
		glEnd();

		glBegin(GL_LINE_STRIP);//draw a line strip
		glVertex2f(1.9, 0.45);//set a vertex of strip
		glVertex2f(1.9, 0.65);//set a vertex of strip
		glVertex2f(3.1, 0.65);//set a vertex of strip
		glVertex2f(3.1, 0.45);//set a vertex of strip
		glEnd();
	}
	if (sparks == 0 && sparkle == 0)
	{
		glBegin(GL_QUADS);//draw a quads
		glColor4f(0, 0, 1, 1);//set a non-transparent color
		glVertex2f(3.3, 0.45);//set a vertex of button
		glVertex2f(3.3, 0.65);//set a vertex of button
		glVertex2f(4.5, 0.65);//set a vertex of button
		glVertex2f(4.5, 0.45);//set a vertex of button
		glEnd();

		glBegin(GL_LINE_STRIP);//draw a line strip
		glVertex2f(3.3, 0.45);//set a vertex of strip
		glVertex2f(3.3, 0.65);//set a vertex of strip
		glVertex2f(4.5, 0.65);//set a vertex of strip
		glVertex2f(4.5, 0.45);//set a vertex of strip
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);//draw a quads
		glColor4f(0, 0, 1, 0.5f);//set a transparent color
		glVertex2f(3.3, 0.45);//set a vertex of button
		glVertex2f(3.3, 0.65);//set a vertex of button
		glVertex2f(4.5, 0.65);//set a vertex of button
		glVertex2f(4.5, 0.45);//set a vertex of button
		glEnd();

		glBegin(GL_LINE_STRIP);//draw a line strip
		glVertex2f(3.3, 0.45);//set a vertex of strip
		glVertex2f(3.3, 0.65);//set a vertex of strip
		glVertex2f(4.5, 0.65);//set a vertex of strip
		glVertex2f(4.5, 0.45);//set a vertex of strip
		glEnd();
	}
	if (sakuraRain == 0)
	{
		glBegin(GL_QUADS);//draw a quads
		glColor4f(0, 1, 1, 1);//set a non-transparent color
		glVertex2f(1.9, 0.2);//set a vertex of button
		glVertex2f(1.9, 0.4);//set a vertex of button
		glVertex2f(3.1, 0.4);//set a vertex of button
		glVertex2f(3.1, 0.2);//set a vertex of button
		glEnd();

		glBegin(GL_LINE_STRIP);//draw a line strip
		glVertex2f(1.9, 0.2);//set a vertex of strip
		glVertex2f(1.9, 0.4);//set a vertex of strip
		glVertex2f(3.1, 0.4);//set a vertex of strip
		glVertex2f(3.1, 0.2);//set a vertex of strip
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);//draw a quads
		glColor4f(0, 1, 1, 0.5f);//set a transparent color
		glVertex2f(1.9, 0.2);//set a vertex of button
		glVertex2f(1.9, 0.4);//set a vertex of button
		glVertex2f(3.1, 0.4);//set a vertex of button
		glVertex2f(3.1, 0.2);//set a vertex of button
		glEnd();

		glBegin(GL_LINE_STRIP);//draw a line strip
		glVertex2f(1.9, 0.2);//set a vertex of strip
		glVertex2f(1.9, 0.4);//set a vertex of strip
		glVertex2f(3.1, 0.4);//set a vertex of strip
		glVertex2f(3.1, 0.2);//set a vertex of strip
		glEnd();
	}

	if (sakuraRain == 1) //judge whether sakuraRain is on
	{
		glPushMatrix(); //push data into matrix
		glRotatef(sakuraSpeed, 0.0f, 0.0f, -1.0f); //set rotation
		glBegin(GL_POLYGON);//draw a polygon
		glColor3f(1, 0.75, 0.79); //set a pink color
		glVertex2f(2.5, 2.4);//set a vertex
		glVertex2f(2.45, 2.37);//set a vertex
		glVertex2f(2.5, 2.35);//set a vertex
		glVertex2f(2.55, 2.37);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.5, 2.4);//set a vertex
		glVertex2f(1.45, 2.37);//set a vertex
		glVertex2f(1.5, 2.35);//set a vertex
		glVertex2f(1.55, 2.37);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.7, 2.4);//set a vertex
		glVertex2f(1.65, 2.37);//set a vertex
		glVertex2f(1.7, 2.35);//set a vertex
		glVertex2f(1.75, 2.37);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.6 + 3, 2.4);//set a vertex
		glVertex2f(1.55 + 3, 2.37);//set a vertex
		glVertex2f(1.6 + 3, 2.35);//set a vertex
		glVertex2f(1.65 + 3, 2.37);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.4 + 2.5, 2.4);//set a vertex
		glVertex2f(1.35 + 2.5, 2.37);//set a vertex
		glVertex2f(1.4 + 2.5, 2.35);//set a vertex
		glVertex2f(1.45 + 2.5, 2.37);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.3 + 2, 2.4);//set a vertex
		glVertex2f(1.25 + 2, 2.37);//set a vertex
		glVertex2f(1.3 + 2, 2.35);//set a vertex
		glVertex2f(1.35 + 2, 2.37);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.2 - 0.4, 2.4 - 0.12);//set a vertex
		glVertex2f(1.15 - 0.4, 2.37 - 0.12);//set a vertex
		glVertex2f(1.2 - 0.4, 2.35 - 0.12);//set a vertex
		glVertex2f(1.25 - 0.4, 2.37 - 0.12);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.0 + 1, 2.4 + 0.3);//set a vertex
		glVertex2f(0.95 + 1, 2.37 + 0.3);//set a vertex
		glVertex2f(1.0 + 1, 2.35 + 0.3);//set a vertex
		glVertex2f(1.05 + 1, 2.37 + 0.3);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.8 - 0.2, 2.4 - 0.3);//set a vertex
		glVertex2f(1.75 - 0.2, 2.37 - 0.3);//set a vertex
		glVertex2f(1.8 - 0.2, 2.35 - 0.3);//set a vertex
		glVertex2f(1.85 - 0.2, 2.37 - 0.3);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(1.9 + 0.4, 2.4 - 0.1);//set a vertex
		glVertex2f(1.85 + 0.4, 2.37 - 0.1);//set a vertex
		glVertex2f(1.9 + 0.4, 2.35 - 0.1);//set a vertex
		glVertex2f(1.95 + 0.4, 2.37 - 0.1);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(2.0 + 0.3, 2.4 - 0.6);//set a vertex
		glVertex2f(1.95 + 0.3, 2.37 - 0.6);//set a vertex
		glVertex2f(2.0 + 0.3, 2.35 - 0.6);//set a vertex
		glVertex2f(2.05 + 0.3, 2.37 - 0.6);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(2.1 + 0.5, 2.4 - 1);//set a vertex
		glVertex2f(2.05 + 0.5, 2.37 - 1);//set a vertex
		glVertex2f(2.1 + 0.5, 2.35 - 1);//set a vertex
		glVertex2f(2.05 + 0.5, 2.37 - 1);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glVertex2f(0.9 - 0.6, 2.4);//set a vertex
		glVertex2f(0.85 - 0.6, 2.37);//set a vertex
		glVertex2f(0.9 - 0.6, 2.35);//set a vertex
		glVertex2f(0.95 - 0.6, 2.37);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glColor3f(1, 0.75, 0.79);//set a pink color
		glVertex2f(2.5 - 2, 2.4 - 0.4);//set a vertex
		glVertex2f(2.45 - 2, 2.37 - 0.4);//set a vertex
		glVertex2f(2.5 - 2, 2.35 - 0.4);//set a vertex
		glVertex2f(2.55 - 2, 2.37 - 0.4);//set a vertex
		glEnd();
		glBegin(GL_POLYGON);//draw a polygon
		glColor3f(1, 0.75, 0.79);//set a pink color
		glVertex2f(2.5 + 1.67, 2.4 - 0.35);//set a vertex
		glVertex2f(2.45 + 1.67, 2.37 - 0.35);//set a vertex
		glVertex2f(2.5 + 1.67, 2.35 - 0.35);//set a vertex
		glVertex2f(2.55 + 1.67, 2.37 - 0.35);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glColor3f(1, 0.75, 0.79);//set a pink color
		glVertex2f(2.5 - 2.33, 2.4 - 0.58);//set a vertex
		glVertex2f(2.45 - 2.33, 2.37 - 0.58);//set a vertex
		glVertex2f(2.5 - 2.33, 2.35 - 0.58);//set a vertex
		glVertex2f(2.55 - 2.33, 2.37 - 0.58);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glColor3f(1, 0.75, 0.79);//set a pink color
		glVertex2f(2.5 - 2.1, 2.4 - 0.1);//set a vertex
		glVertex2f(2.45 - 2.1, 2.37 - 0.1);//set a vertex
		glVertex2f(2.5 - 2.1, 2.35 - 0.1);//set a vertex
		glVertex2f(2.55 - 2.1, 2.37 - 0.1);//set a vertex
		glEnd();

		glBegin(GL_POLYGON);//draw a polygon
		glColor3f(1, 0.75, 0.79);//set a pink color
		glVertex2f(2.5 + 1.23, 2.4 - 0.54);//set a vertex
		glVertex2f(2.45 + 1.23, 2.37 - 0.54);//set a vertex
		glVertex2f(2.5 + 1.23, 2.35 - 0.54);//set a vertex
		glVertex2f(2.55 + 1.23, 2.37 - 0.54);//set a vertex
		glEnd();

		glPopMatrix(); //pop the matrix
	}
		
		glColor3f(1, 1, 1); //set the white color
	Font(GLUT_BITMAP_HELVETICA_18, "Red is Morph, Green is sparkle, Blue is spark£¬Sky is sakuraRain",700,800 );//show the font on the screen
	
	// swap the frame buffers
	glutSwapBuffers();
}
/*****************************************************************************

	Function:		Font
	Description:	Show the font on the screen

******************************************************************************/
int Font(void *font, char *txt, float x, float y)
{

	glRasterPos2i(x, y); //set the font positon
	while (*txt != '\0') //judge not null
	{
		glutBitmapCharacter(font, *txt);//input font
		++txt;//increase the txt number
	}
}

/*****************************************************************************

	Function:		myMouse

	Description:	Grabs the postion of a mouse click

******************************************************************************/
void myMouseButton(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) //judge mouse is clicked down
	{
			// convert x from Mouse coordinates to OpenGL coordinates
		mouseX = ((GLfloat)x / (GLfloat)windowWidth)*5;
		printf_s("%f ", mouseX);//print the value of mousex
		// convert y from Mouse coordinates to OpenGL coordinates
		mouseY = (GLfloat)windowHeight - (GLfloat)y;  // first invert mouse Y position
		mouseY = (mouseY / (GLfloat)windowHeight)*2.5;//second invert mouse Y position
		printf_s("%f ",mouseY);//pirnt the value of mousey
		if (mouseX >0.5 && mouseX <1.7 && mouseY >0.45 && mouseY < 0.65 && morph == 0)//judge whether click morph button and it was off
		{
			morph = 1; //turn on the switch
		}
		else if (mouseX > 0.5 && mouseX <1.7 && mouseY >0.45 && mouseY < 0.65 && morph == 1)//judge whether click morph button and it was on
		{
			morph = 0;//turn off the switch
		}
		if (mouseX > 1.9 && mouseX <3.1 && mouseY >0.45 && mouseY < 0.65 && sparkle == 0)//judge whether click sparkle button and it was off
		{
			sparkle = 1;//turn on the switch
		}
		else if (mouseX > 1.9 && mouseX <3.1 && mouseY >0.45 && mouseY < 0.65 && sparkle == 1)//judge whether click sparkle button and it was on
		{
			sparkle = 0;//turn off the switch
		}
		if (mouseX > 3.3 && mouseX <4.5 && mouseY >0.45 && mouseY < 0.65 && sparks == 0 && sparkle == 1)//judge whether click spark button and it was off
		{
			sparks = 1;//turn on the switch
		}
		else if (mouseX > 3.3 && mouseX <4.5 && mouseY >0.45 && mouseY < 0.65 &sparks == 1)//judge whether click sparks button and it was on
		{
			sparks = 0;//turn off the switch
		}
		if (mouseX > 1.9 && mouseX <3.1 && mouseY >0.2 && mouseY < 0.4 && sakuraRain == 0)//judge whether click sakuraRain button and it was off
		{
			sakuraRain = 1;//turn on the switch
		}
		else if (mouseX > 1.9 && mouseX <3.1 && mouseY >0.2 && mouseY < 0.4 && sakuraRain == 1)//judge whether click sakuraRain button and it was on
		{
			sakuraRain = 0;//turn off the switch
		}
	}
	// now force OpenGL to redraw the change
	glutPostRedisplay();
}

/*****************************************************************************

	Function:		main

	Description:	Sets up the openGL rendering context and the windowing
					system, then begins the display loop

******************************************************************************/
void main(int argc, char** argv)
{
	//initialize the toolkit
	glutInit(&argc, argv);
	// set display mode
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	// set window size
	glutInitWindowSize(windowWidth,windowHeight);
	//set window position on screen
	glutInitWindowPosition(0, 0);
	//open the screen window
	glutCreateWindow("assignment 1 - Yanyue Meng");
	//register redraw function
	glutDisplayFunc(display);
	//register the mouse function
	glutMouseFunc(myMouseButton);
	//register the idle function
	glutIdleFunc(myIdle);
	//initialize the rendering context
	initializeGL();
	//go into a perpetual loop
	glutMainLoop();
}