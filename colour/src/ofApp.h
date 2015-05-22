#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    ofColor getCellColour(ofRectangle cell);
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage image;
    int rowCount;
    int colCount;
    vector<ofRectangle> cells;
    vector<ofColor> cellColours;
    
    ofxPanel gui;
    ofxIntSlider colCountSlider;
    ofxIntSlider rowCountSlider;
    
};
