#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    
    placeToBe.x = ofGetWidth() / 2;
    placeToBe.y = ofGetHeight() / 2;
	
	int num = 50;
	birds.assign(num, Bird());
    
    for (unsigned int i = 0; i < birds.size(); ++i){
        birds[i].reset(i);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
    moveAllBirdsToNewPosition();
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(60, 60, 60), ofColor(10, 10, 10));
    
    ofSetColor(245, 245, 245);
    ofCircle(placeToBe.x, placeToBe.y, 20);
    
    for (unsigned int i = 0; i < birds.size(); ++i){
        birds[i].draw();
	}
}

void ofApp::moveAllBirdsToNewPosition() {
    ofVec2f v1, v2, v3, v4;
    float dt = 1.f / ofGetFrameRate();
    
    for (unsigned int i = 0; i < birds.size(); ++i){
        v1 = rule1(birds[i]);
        v2 = rule2(birds[i]);
        v3 = rule3(birds[i]);
        v4 = tendToPlaceRule(birds[i]);
        
        birds[i].vel = birds[i].vel + v1 + v2 + v3 + v4;
        birds[i].pos = birds[i].pos + (birds[i].vel * dt);
	}
}

ofVec2f ofApp::rule1(Bird b) {
    ofVec2f pcJ;
    
    for (unsigned int i = 0; i < birds.size(); ++i) {
        if (b.birdName != birds[i].birdName) {
            pcJ = pcJ + b.pos;
        }
    }
    
    pcJ = pcJ / (birds.size());

    return (pcJ - b.pos) / 100;
}

ofVec2f ofApp::rule2(Bird b) {
    ofVec2f c(0, 0);
    
    for (unsigned int i = 0; i < birds.size(); ++i) {
        if (b.birdName != birds[i].birdName) {
            // ofVec2f tmp = birds[i].pos - b.pos;
            //float length = birds[i].pos.squareDistance(b.pos);
            
            if ((birds[i].pos.squareDistance(b.pos)) < 100.0f) {
                c = c - (birds[i].pos - b.pos);
            }
        }
    }
    
    return c;
}

ofVec2f ofApp::rule3(Bird b) {
    ofVec2f pvJ;
    
    for (unsigned int i = 0; i < birds.size(); ++i) {
        if (b.birdName != birds[i].birdName) {
            pvJ = pvJ + b.vel;
        }
    }
    
    pvJ = pvJ / birds.size() - 1;
    
    return (pvJ - b.vel) / 8;
}

ofVec2f ofApp::tendToPlaceRule(Bird b) {
    return (placeToBe - b.pos) / 100;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == ' ') {
        for (unsigned int i = 0; i < birds.size(); ++i) {
            birds[i].reset(i);
        }
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    placeToBe.x = x;
    placeToBe.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
