#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
int x1,x2,y1,y2;

void Init()
{
    glClearColor(0,0,0,1);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,640,0,480);
}

void Read(){
printf("Enter the value of x1 : ");
scanf("%i",&x1);
printf("Enter the value of y1 : ");
scanf("%i",&y1);
printf("Enter the value of x2 : ");
scanf("%i",&x2);
printf("Enter the value of y2 : ");
scanf("%i",&y2);
}

void _point(int x, int y)
{
    glColor3f(1.0,1.0,1.0);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex3f(x, y,0);
    glEnd();
}
void _line(int x1, int x2, int y1, int y2)
{
int dx,dy,i,p,x_i, y_i, i_1, inc2,x,y;
dx = x2-x1;
dy = y2-y1;
if (dx < 0) dx = -dx;
if (dy < 0) dy = -dy;
x_i = 1;
if (x2 < x1) x_i = -1;
y_i = 1;
if (y2 < y1) y_i = -1;
x = x1; y = y1;
if (dx > dy)
{
_point(x, y);
p = 2 * dy-dx;
i_1 = 2*(dy-dx);
inc2 = 2*dy;
for (i=0; i<dx; i++)
{
if (p >= 0)
{
y += y_i;
p += i_1;
}
else
p += inc2;
x += x_i;
_point(x, y);
}
}

else
{
_point(x, y);
p = 2*dx-dy;
i_1 = 2*(dx-dy);
inc2 = 2*dx;
for (i=0; i<dy; i++)
{
if (p >= 0)
{
x += x_i;
p += i_1;
}
else
p += inc2;
y += y_i;
_point(x, y);
}
}
}
void display(void)
{
_line(x1, x2, y1, y2);
glFlush();
}


int main(int argc, char *argv[])
{
    Read();
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Bresenham’s line drawing algorithm");

    Init();
    glutDisplayFunc(display);


    glutMainLoop();

    return EXIT_SUCCESS;
}
