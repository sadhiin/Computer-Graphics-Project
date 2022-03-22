#ifndef CROSSHAIR_H_INCLUDED
#define CROSSHAIR_H_INCLUDED


void drawCrosshair()
{
    glPushMatrix();
    glViewport(0, 0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3ub(240, 240, 240);//white
    glLineWidth(2.0);

    int crossHair[8] =
    {
    GLUT_SCREEN_WIDTH / 2 - 7, GLUT_SCREEN_HEIGHT / 2, // horizontal line
    GLUT_SCREEN_WIDTH / 2 + 7, GLUT_SCREEN_HEIGHT / 2,

    GLUT_SCREEN_WIDTH / 2, GLUT_SCREEN_HEIGHT / 2 + 7, //vertical line
    GLUT_SCREEN_WIDTH / 2, GLUT_SCREEN_HEIGHT / 2 - 7
    };

    // activate vertext array state and assign pointer to vertext array data
    glEnableClientState(GL_VERTEX_ARRAY);

    //2 = number of coordinates per vertext we are doing 2d so I don't need the Z coordinate
    // GL_INT = data type held in array
    // crossHair = pointer to vertext data array


    glVertexPointer(2, GL_INT, 0, crossHair);

    //draw primitive GL_LINES starting at the first vertex, use 2 total vertices
    glDrawArrays(GL_LINES, 0, 2); //draw horizontal line
    //Same as above but start at second vertex
    glDrawArrays(GL_LINES, 2, 2); //draw vertical line

    // deactivate vertex array state after drawing
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();

}

void drawCrosshairOLD()
{
    glPushMatrix();
    glViewport(0, 0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3ub(240, 240, 240);//white
    glLineWidth(2.0);
    glBegin(GL_LINES);
    //horizontal line
    glVertex2i(GLUT_SCREEN_WIDTH / 2 - 7, GLUT_SCREEN_HEIGHT / 2);
    glVertex2i(GLUT_SCREEN_WIDTH / 2 + 7, GLUT_SCREEN_HEIGHT / 2);
    glEnd();
    //vertical line
    glBegin(GL_LINES);
    glVertex2i(GLUT_SCREEN_WIDTH / 2, GLUT_SCREEN_HEIGHT / 2 + 7);
    glVertex2i(GLUT_SCREEN_WIDTH / 2, GLUT_SCREEN_HEIGHT / 2 - 7);
    glEnd();

    glPopMatrix();
}


#endif // CROSSHAIR_H_INCLUDED
