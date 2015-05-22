//
//  ColourSampler.cpp
//  colour
//
//  Created by Chris Mullany on 22/05/2015.
//
//

#include "ColourSampler.h"

ColourSampler::ColourSampler() {
    image = NULL;
    colCount = 2;
    rowCount = 2;
}

void ColourSampler::setup(ofImage* image, int rowCount, int colCount) {
    this->image = image;
    setGrid(rowCount, colCount);
}

void ColourSampler::update() {
    if (image == NULL) return;
}

void ColourSampler::draw(int x, int y, int w, int h) {
    // draw cells
    int imgW = image->getWidth();
    int imgH = image->getHeight();
    ofPushMatrix();
    ofTranslate(x, y);
    if (w > 0) {
        float scaleX = (float)w / (float)imgW;
        ofScale(scaleX, scaleX);
        width = w;
        height = floor(imgH * scaleX);
    } else {
        width = imgW;
        height = imgH;
    }
    //image->draw(0,0);
    ofSetColor(255);
    ofRect(0, 0, imgW, imgH);
    for(int i = 0; i < cellColours.size(); i++)
    {
        ofSetColor(cellColours[i], 255);
        ofRect(cells[i]);
    }
    ofSetColor(255);
    ofPopMatrix();
}

void ColourSampler::exit() {
}

//////////////////////////////////////////////////////////////////////////////////
// public
//////////////////////////////////////////////////////////////////////////////////
void ColourSampler::setGrid(int rowCount, int colCount){
    this->rowCount = rowCount;
    this->colCount = colCount;
    setupCells();
}
//////////////////////////////////////////////////////////////////////////////////
// protected
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// private
//////////////////////////////////////////////////////////////////////////////////
void ColourSampler::setupCells(){
    if (image == NULL) return;
    // prepare cells
    cellColours.clear();
    cells.clear();
    int imgW = image->getWidth();
    int imgH = image->getHeight();
    float cellW = (float)imgW / (float)colCount;
    float cellH = (float)imgH / (float)rowCount;
    for (int row=0; row<rowCount; row++) {
        for (int col=0; col<colCount; col++) {
            ofRectangle cell;
            cell.set(col*cellW, row*cellH, cellW, cellH);
            ofColor colour = getCellColour(cell);
            cellColours.push_back(colour);
            cells.push_back(cell);
        }
    }
}

ofColor ColourSampler::getCellColour(ofRectangle cell) {
    int r, g, b;
    r = g = b = 0;
    ofColor c;
    for (int y=cell.y; y<cell.getBottom(); y++) {
        for (int x=cell.x; x<cell.getRight(); x++) {
            c = image->getColor(x, y);
            r += c.r;
            g += c.g;
            b += c.b;
        }
    }
    int n = cell.height * cell.width;
    return ofColor(r/n, g/n, b/n);
}

//////////////////////////////////////////////////////////////////////////////////
// custom event handlers
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// oF event handlers
//////////////////////////////////////////////////////////////////////////////////

void ColourSampler::keyPressed (int key) {}

void ColourSampler::keyReleased (int key) {}

void ColourSampler::mouseMoved(int x, int y) {}

void ColourSampler::mouseDragged(int x, int y, int button) {}

void ColourSampler::mousePressed(int x, int y, int button) {}

void ColourSampler::mouseReleased(int x, int y, int button) {}

void ColourSampler::windowResized(int w, int h) {}

void ColourSampler::dragEvent(ofDragInfo dragInfo) {}

void ColourSampler::gotMessage(ofMessage msg) {}
