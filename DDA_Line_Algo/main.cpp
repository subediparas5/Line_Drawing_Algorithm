#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;

void Init()
{
    glClearColor(0,0,0,1);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,640,0,480);
}

int round_off(float a){
    return (a-int(a))>=0.5?int(a)+1:int(a);
}

void display()
{
float dy,dx,step,x,y,k,Xin,Yin;
dx=x2-x1;
dy=y2-y1;

if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);

Xin = dx/step;
Yin = dy/step;

x= x1;
y=y1;
glColor3f(1.0,1.0,1.0);
    glPointSize(2);
glBegin(GL_POINTS);
glVertex2i(round_off(x),round_off(y));
glEnd();

for (k=1 ;k<=step;k++)
{
x= x + Xin;
y= y + Yin;
//glColor3f(1.0,1.0,1.0);
  //  glPointSize(10);
glBegin(GL_POINTS);
glVertex3f(round_off(x),round_off(y),0);
glEnd();
}


glFlush();
}

void Read(){
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y1);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);
}

int main(int argc, char *argv[])
{
    Read();
    glutInit(&argc, argv);
    glutInitWindowSize(680,480);
    glutInitWindowPosition (50,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Digital Differential Analyzer(DDA) Line Drawing Algorithm");

    Init();
    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}
