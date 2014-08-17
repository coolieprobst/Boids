#pragma once

#include "ofMain.h"
#include "Bird.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void moveAllBirdsToNewPosition();
        ofVec2f rule1(Bird b);
        ofVec2f rule2(Bird b);
        ofVec2f rule3(Bird b);
        ofVec2f tendToPlaceRule(Bird b);
    
        ofVec2f placeToBe;

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        vector <Bird> birds;
};
