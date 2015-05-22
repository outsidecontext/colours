#include "ofApp.h"


void ofApp::setup(){
    gui.setup();
    gui.add(colCountSlider.setup("Columns", 2, 1, 20));
    gui.add(rowCountSlider.setup("Rows", 2, 1, 20));
    gui.setPosition(700, 0);
    
    ofEnableAlphaBlending();
    image.loadImage("test.jpg");
}


void ofApp::update(){
    // gui
    colCount = colCountSlider;
    rowCount = rowCountSlider;
    // cells
    cellColours.clear();
    cells.clear();
    int imgW = image.getWidth();
    int imgH = image.getHeight();
    int cellW = imgW / colCount;
    int cellH = imgH / rowCount;
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


ofColor ofApp::getCellColour(ofRectangle cell) {
    int r, g, b;
    r = g = b = 0;
    ofColor c;
    for (int y=cell.y; y<cell.getBottom(); y++) {
        for (int x=cell.x; x<cell.getRight(); x++) {
            c = image.getColor(x, y);
            r += c.r;
            g += c.g;
            b += c.b;
        }
    }
    int n = cell.height * cell.width;
    return ofColor(r/n, g/n, b/n);
}


void ofApp::draw(){
    ofPushMatrix();
    ofScale(0.5, 0.5);
    image.draw(0,0);
    for(int i = 0; i < cellColours.size(); i++)
    {
        ofSetColor(cellColours[i], 250);
        ofRect(cells[i]);
    }
    ofSetColor(255);
    ofPopMatrix();
    gui.draw();
}


void ofApp::keyPressed(int key){

}


void ofApp::keyReleased(int key){

}


void ofApp::mouseMoved(int x, int y ){

}


void ofApp::mouseDragged(int x, int y, int button){

}


void ofApp::mousePressed(int x, int y, int button){

}


void ofApp::mouseReleased(int x, int y, int button){

}


void ofApp::windowResized(int w, int h){

}


void ofApp::gotMessage(ofMessage msg){

}


void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
