//
//  Bird.h
//  Boids
//
//  Created by Stefan Probst on 16.08.14.
//
//

#ifndef __Boids__Bird__
#define __Boids__Bird__

#include <iostream>
#include "ofMain.h"

class Bird {
public:    
    void reset(int name);
    void update();
    void draw();
    
    int birdName;
    ofVec2f pos;
    ofPoint vel;
};

#endif /* defined(__Boids__Bird__) */
