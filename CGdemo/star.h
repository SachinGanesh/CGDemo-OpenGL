
// Number of stars
const int STARS_COUNT = 100;

float STARS_VISIBLE_STATE = false;
float STARS_DISPLAY_NOW = false;


float RANDOM_POS_X[STARS_COUNT] = { 0 };
float RANDOM_POS_Y[STARS_COUNT] = { 0 };
float RANDOM_SIZE[STARS_COUNT] = {0};
bool STARS_ENABLE = false;

void drawStar();


/// <summary>
/// Draws the stars.
/// </summary>
void drawStars()
{
	if (STARS_ENABLE){
		glClearColor(0, 0, 0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		POINT Pos;
		POINT Scale;
		COLOR Color;
		for (int i = 0; i < STARS_COUNT; i++){
			Color.red = 1; Color.green = 1; Color.blue = 1;
			if (STARS_DISPLAY_NOW){				
				RANDOM_POS_X[i] = (rand() % 20);
				RANDOM_POS_Y[i] = (rand() % 20);
				
				Color.red = 0.9; Color.green = 0.9; Color.blue = 0.9;
				do{
					RANDOM_SIZE[i] = (rand() % 100)* 0.01;
				} while (RANDOM_SIZE[i] > 0.3);
			}
			
			Pos.x = RANDOM_POS_X[i]; Pos.y = RANDOM_POS_Y[i]; Pos.z = 0;
			Scale.x = RANDOM_SIZE[i] * 0.2; Scale.y = RANDOM_SIZE[i] * 0.2; Scale.z = 1;


			glPushMatrix();
			glScalef(Scale.x, Scale.y, Scale.z);
			glTranslatef(Pos.x, Pos.y, Pos.z);
			glColor3f(Color.red, Color.green, Color.blue);
			drawStar();
			glPopMatrix();
		}
		STARS_DISPLAY_NOW = false;
		//glutPostRedisplay();
	}
}

void drawStar()
{
	glPushMatrix();
	glScalef(0.6, 0.6, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0);
	glVertex2f(0.3, 0.45);
	glVertex2f(0.60, 0);
	glVertex2f(0, 0.30);
	glVertex2f(0.60, 0.30);
	glVertex2f(0.30, -0.15);
	glEnd();
	glPopMatrix();
}

