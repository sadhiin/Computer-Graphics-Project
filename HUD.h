#ifndef HUD_H_INCLUDED
#define HUD_H_INCLUDED

void renderBitmapString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

	char *c;
	glRasterPos3f(x, y,z);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void setOrthographicProjection(int w, int h) {

	// switch to projection mode
	glMatrixMode(GL_PROJECTION);

	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();

	// reset matrix
	glLoadIdentity();

	// set a 2D orthographic projection
	gluOrtho2D(0, w, h, 0);

	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}


void restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	// restore previous projection matrix
	glPopMatrix();

	// get back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void drawCrosshair(int w, int h) {

	setOrthographicProjection(w, h);

	glPushMatrix();
	glLoadIdentity();
//	renderBitmapString(5,30,GLUT_BITMAP_HELVETICA_18,"Lighthouse3D");

    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    //horizontal line
    glVertex2i(w / 2 - 7, h / 2);
    glVertex2i(w / 2 + 7, h / 2);
    glEnd();
    //vertical line
    glBegin(GL_LINES);
    glVertex2i(w / 2, h / 2 + 7);
    glVertex2i(w / 2, h / 2 - 7);
    glEnd();



	glPopMatrix();

	restorePerspectiveProjection();

	glutSwapBuffers();
}


#endif // HUD_H_INCLUDED
