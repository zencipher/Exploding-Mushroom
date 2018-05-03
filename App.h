#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "TexRect.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
	int val = 1;

public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void keyUp(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    void idle();

	
	
	void destroy();
	void call() {
		painting = new TexRect("fireball.bmp", 6, 6, 0, 0.67, 0.5, 0.5);
		destroy();
		idle();
		val = 0;
	}
    bool isMoving;
    
    TexRect* painting;
    //TexRect* background;
};

#endif
