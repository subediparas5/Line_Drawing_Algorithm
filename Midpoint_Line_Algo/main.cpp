#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
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

void _point(float x,float y){
        glPointSize(5);
    glBegin(GL_POINTS);
    glVertex3f(round_off(x),round_off(y),0);
    glEnd();
}

void Midpoint(){
    float dx = x2 - x1;
    float dy = y2 - y1;

    if(dy<=dx){
        float d = dy - (dx/2);
        float x = x1, y = y1;
    while (x < x2){
        x++;
        if (d < 0){
          d = d + dy;
        }
        else{
            d += (dy - dx);
            y++;
        }
            glColor3f(1,1,1);
            _point(x,y);
    }



    }
      else{
        float d = dx - (dy/2);
        float x = x1, y = y1;
        while (y < y2){
            y++;
            if (d < 0){
               d = d + dx;
            }
        else{
            d += (dx - dy);
            x++;
        }
            _point(x,y);
    }

  }
glFlush();
}


void display(void)
{
    Midpoint();
    glFlush();
}

int main(int argc, char *argv[])
{
    Read();
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Midpoint Line Drawing Algorithm");
    Init();
    glutDisplayFunc(display);

    glutMainLoop();

    return EXIT_SUCCESS;
}
