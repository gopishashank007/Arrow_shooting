#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<GL/glut.h>
int maxy=500, count=0, maxx=500, n=1, m=3,r,q,score=0;
int x,y=50.0,i=1,j=0,k=0,arx=20,ary=250,flag=1;
int check1=0;
char buffer[10];
bool keystates[200];
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};
void disa1();
void disa();
void arrow();

void output(int x, int y, const char *string)
{
  int len, i;

  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void drawString (void * font, char *s, float x, float y){
     unsigned int i;
     glRasterPos2f(x, y);
     for (i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
}

void b_color()
{
    i=rand() % 2;
    j=rand() % 2;
    k=rand() % 2;
    if(i==0 && j==0 && k==0 )
    {
        i=1;
        j=0;
        k=0;
    }
}

void id1()
{
    y+=n;

    Sleep(10);
    if(y>maxy)
    {
        y=0;
        check1 = rand() % 3;
        b_color();
    }
    glutPostRedisplay();
}

void starter()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);

	output(95,450,"DAYANANDA SAGAR ACADEMY OF TECHNOLOGY AND MANAGEMENT");
	glColor3f(0.5,0.5,0.5);
	output(200,425,"CG MINI PROJECT");
	output

(0,420,"_____________________________________________________________________________________________________________________________________");



	glColor3f(0,0.7,0.7);
	output(220,370,"PROJECT ON");

	glColor3f(0.5,0.7,0.5);
	output(200,345,"ARROW SHOOTING 2.0");
	output(0,325,"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - --- - - - - - - - - - - - ");


	glColor3f(0.5,0.5,0.5);
	output(200,260,"");
	output(0,255,"______________________________________________________________________________________________________________________________________________________");

	glColor3f(0.9,0.3,0.7);
	output(380,220,"K GOPI SHASHANK");
	glColor3f(1.0,1.0,1.0);
	output(55,200,"1DT12CS013");
	output(382,200,"1DT12CS022");
	glColor3f(1,1,0);
	output(210,70,"Right click for instructions");
	glColor3f(1,1,1);
	output(225,100,"Press c to continue");
	glFlush();

}


void KeyUpPress(unsigned char key, int x, int y )
{
    switch(key)
    {
    case 'w':
        keystates['w'] = false;
        break;
    case 's':
        keystates['s'] = false;
        break;
    case 'r':
        keystates['r'] = true;
        break;
    case 'c':
        flag=0;
        glutPostRedisplay();
        break;
//        glutIdleFunc(id);
//        break;
    case 'q':
        exit(0);

    }
}

void KeyDownPress(unsigned char key, int x, int y )
{
    switch(key)
    {
    case 'w':
        keystates['w'] = true;
        break;

    case 's':
        keystates['s'] = true;
        break;
    case 'r':
        keystates['r'] = false;
        break;
    case 'q':
        exit(0);

    }

}

void disa1()
{
    y=0;
//    glBegin(GL_POLYGON);
 //   glColor3f(0.0, 0.0, 0.0);
//    glVertex2f(x - 6, y - 21);
//    glVertex2f(x - 12, y - 18);
//    glVertex2f(x - 17, y - 10);
//    glVertex2f(x - 20, y);
//    glVertex2f(x - 20, y + 10);
//    glVertex2f(x - 16, y + 18);
 //   glVertex2f(x - 10, y + 22);
 //   glVertex2f(x, y + 25);
  //  glVertex2f(x + 15, y + 22);
 //   glVertex2f(x + 20, y + 20);
 //   glVertex2f(x + 24, y + 10);
  //  glVertex2f(x + 25, y);
  //  glVertex2f(x + 23, y - 10);
 //   glVertex2f(x + 19, y - 18);
 //   glVertex2f(x + 10, y - 21);
 //   glVertex2f(x, y - 22);
 //   glEnd();
 //   glLineWidth(2);
 //   glBegin(GL_LINES);
 //   glColor3f(0.0,0.0,0.0);
 //   glVertex2f(x + 18, y - 18);
 //   glVertex2f(x + 18, y - 60);
  //  glEnd();
    check1 = rand() % 3;
    b_color();
}

void disa()
{
    if((arx+50 >= x-6) && (arx+50 <= x+25) &&  (ary >= y-22) && (ary <= y+22))
    {
        score=score+10;
            arx = 20;
            ary = 250;
        disa1();
        keystates['r'] = false;
    }
}

void updateGame(int value)
{
    glutTimerFunc(20, updateGame, 0);
    if(keystates['w'] == true)
    {
        ary = ary + 4;

        if(ary >= 500)
            ary = ary - 500 ;
    }


    if(keystates['s'] == true)
    {
        ary = ary - 4;

        if(ary < 0)
            ary = ary + 500;
    }
    if(keystates['r'] == true)
    {
        arx = arx + 12;

        if(arx >= maxx)
        {
            arx = 20;
            ary = 250;
            keystates['r'] = false;
        }

    }
}

void arrow()
{
    glColor3f(0,1,1);
    glBegin(GL_LINES);
    glVertex2d(arx,ary);
    glVertex2d(arx+50,ary);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2d(arx,ary+2);
    glVertex2d(arx+50,ary-2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(arx,ary-2);
    glVertex2d(arx+50,ary-2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2d (arx+50,ary+3);
    glVertex2d(arx+60,ary);
    glVertex2d(arx+50,ary-3);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2d(arx,ary+3);
    glVertex2d(arx,ary-3);
    glVertex2d(arx-10,ary-5);
    glVertex2d(arx-10,ary+5);
    glEnd();
    disa();
}

void disp(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if(flag==1)
    {
        starter();
    }
    else
    {
    drawString(GLUT_BITMAP_HELVETICA_18, "score:", 350, 470);
	itoa(score, buffer, 10);
	drawString(GLUT_BITMAP_HELVETICA_18, buffer, 410, 470);
    arrow();
    if(check1 == 0)
    {
        x=300;
        glBegin(GL_POLYGON);
        glColor3d(i, j, k);
        glVertex2f(x - 6, y - 21);
        glVertex2f(x - 12, y - 18);
        glVertex2f(x - 17, y - 10);
        glVertex2f(x - 20, y);
        glVertex2f(x - 20, y + 10);
        glVertex2f(x - 16, y + 18);
        glVertex2f(x - 10, y + 22);
        glVertex2f(x, y + 25);
        glVertex2f(x + 15, y + 22);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x + 24, y + 10);
        glVertex2f(x + 25, y);
        glVertex2f(x + 23, y - 10);
        glVertex2f(x + 19, y - 18);
        glVertex2f(x + 10, y - 21);
        glVertex2f(x, y - 22);
        glEnd();
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(x + 18, y - 18);
        glVertex2f(x + 18, y - 60);
        glEnd();
        //	Sleep(100);
        glFlush();
    }
    else if (check1 == 1)
    {
        x=400;
        glBegin(GL_POLYGON);
        glColor3d(i, j, k);
        glVertex2f(x - 6, y - 21);
        glVertex2f(x - 12, y - 18);
        glVertex2f(x - 17, y - 10);
        glVertex2f(x - 20, y);
        glVertex2f(x - 20, y + 10);
        glVertex2f(x - 16, y + 18);
        glVertex2f(x - 10, y + 22);
        glVertex2f(x, y + 25);
        glVertex2f(x + 15, y + 22);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x + 24, y + 10);
        glVertex2f(x + 25, y);
        glVertex2f(x + 23, y - 10);
        glVertex2f(x + 19, y - 18);
        glVertex2f(x + 10, y - 21);
        glVertex2f(x, y - 22);
        glEnd();
        glBegin(GL_LINES);
        glLineWidth(2);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(x , y - 22);
        glVertex2f(x , y - 64);
        glEnd();
        //Sleep(50);
        glFlush();

    }
    else
    {
        x=450;
        glBegin(GL_POLYGON);
        glColor3d(i, j, k);
        glVertex2f(x - 6, y - 21);
        glVertex2f(x - 12, y - 18);
        glVertex2f(x - 17, y - 10);
        glVertex2f(x - 20, y);
        glVertex2f(x - 20, y + 10);
        glVertex2f(x - 16, y + 18);
        glVertex2f(x - 10, y + 22);
        glVertex2f(x, y + 25);
        glVertex2f(x + 15, y + 22);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x + 24, y + 10);
        glVertex2f(x + 25, y);
        glVertex2f(x + 23, y - 10);
        glVertex2f(x + 19, y - 18);
        glVertex2f(x + 10, y - 21);
        glVertex2f(x, y - 22);
        glEnd();
        glBegin(GL_LINES);
        glLineWidth(2);
        glColor3f(1.0,1.0,1.0);
        glVertex2f(x - 17, y - 10);
        glVertex2f(x - 17, y - 60);
        glEnd();
        //Sleep(25);
        glFlush();

    }
    }
    glutSwapBuffers();
}

void init()
{
    glClearColor(0,0,0,1);
    glColor3f(1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}
void demo(int i)
{
switch(i)
{
case 9:
case 10:
case 11:break;
}
}
void game(int id)
{
switch(id);
{
}
}


void demo_menu(int i)
{
switch(i)
{
case 5:
case 6:
case 7:
case 8:break;
}
}

int main(int argc,char **argv)
{
    int sub_menu;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutCreateWindow("ARROW SHOOTING GAME ARCHERY");
    glutDisplayFunc(disp);
    sub_menu=glutCreateMenu(demo_menu);
    glutAddMenuEntry("Press 'w' to move arrow up",5);
    glutAddMenuEntry("Press 's' to move arrow down",6);
    glutAddMenuEntry("Press 'r' to release arrow",7);
    glutAddMenuEntry("Press 'q' to quit",8);
    glutCreateMenu(game);
    glutAddSubMenu("INSTRUCTIONS",sub_menu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutIdleFunc(id1);
    glutKeyboardFunc(KeyDownPress);
    glutKeyboardUpFunc(KeyUpPress);
    init();
    glutTimerFunc(10, updateGame, 0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

