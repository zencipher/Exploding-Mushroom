#include "App.h"


static App* singleton;

int val = 1;

void explode(int value){
    
    if (!singleton->painting->done()){
        singleton->painting->advance();
        singleton->redraw();
        glutTimerFunc(32, explode, value);
    }
}

void move(int value){
    
    if (singleton->isMoving){
        singleton->painting->incY();
        singleton->redraw();
        glutTimerFunc(32, move, value);
    }
}

void App::destroy() {
	
		isMoving = false;
		explode(0);

		
}



App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    char* wall_file, painting_file;
    
    painting = new TexRect("mushroom.bmp", 1, 1, 0, 0.67, 0.5, 0.5);
    
    

}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    
    painting->draw();

	if (painting->contains(mx, my) && val == 1) {
		call();

	}
    
    //background->draw();
    
    glDisable(GL_TEXTURE_2D);
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::idle(){
    redraw();
}

void App::keyUp(unsigned char key) {

}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        
        //delete background;
        delete painting;
        
        exit(0);
    }
    else if (key == ' '){
        painting->reset();
        explode(0);
    }
    
    
}
