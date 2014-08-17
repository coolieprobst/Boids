//
//  Bird.cpp
//  Boids
//
//  Created by Stefan Probst on 16.08.14.
//
//

#include "Bird.h"
#include "ofMain.h"

void Bird::reset(int name) {
    birdName = name;
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    
    float velocity = 200.0f;
    vel.x = ofRandom(-velocity, velocity);
    vel.y = ofRandom(-velocity, velocity);
}

void Bird::update() {
    
}

void Bird::draw() {
    ofSetColor(255, 63, 180);
    ofCircle(pos.x, pos.y, 4.0);
}