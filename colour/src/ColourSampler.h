//
//  ColourSampler.h
//  colour
//
//  Created by Chris Mullany on 22/05/2015.
//
//

#pragma once
#include "ofMain.h"

class ColourSampler {
public:
    ColourSampler();
    
	void setup(ofImage* image, int rowCount, int colCount);
    void update();
    void draw(int x=0, int y=0, int w=0, int h=0);
    void setGrid(int rowCount, int colCount);
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int width;
    int height;

protected:  
private:
    void setupCells();
    ofColor getCellColour(ofRectangle cell);
    int rowCount;
    int colCount;
    ofImage* image;
    vector<ofRectangle> cells;
    vector<ofColor> cellColours;
    
};