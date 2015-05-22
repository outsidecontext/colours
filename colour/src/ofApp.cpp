#include "ofApp.h"


void ofApp::setup(){
    gui.setup();
    gui.add(colCountSlider.setup("Columns", 2, 1, 20));
    gui.add(rowCountSlider.setup("Rows", 2, 1, 20));
    gui.setPosition(700, 0);
    
    ofEnableAlphaBlending();
    rowCount = 4;
    colCount = 6;
    
    ofDirectory dir;
    int nImages = dir.listDir("japan");
    for(int i=0; i<nImages; i++){
        ofImage img;
        img.loadImage(dir.getPath(i));
        images.push_back(img);
    }
    ofLog() << nImages;
    
    for (int i=0; i<nImages; i++) {
        ColourSampler sampler;
        sampler.setup(&images[i], rowCount, colCount);
        samplers.push_back(sampler);
    }
}


void ofApp::update(){
}



void ofApp::draw(){
//    sampler.draw(0, 0, 1000);
    float w = ofGetWidth() / 12;
    float x = 0;
    float y = 0;
    for (int i=0; i<samplers.size(); i++) {
        if (x > ofGetWidth() - w) {
            x = 0;
            y += samplers[i-1].height;
        }
        samplers[i].draw(x, y, w);
        x += samplers[i].width;
    }
    
//    gui.draw();
}


void ofApp::keyPressed(int key){
    switch (key) {
            case 'f':
            ofToggleFullscreen();
            break;
            case OF_KEY_UP:
            rowCount++;
            break;
            case OF_KEY_DOWN:
            rowCount--;
            break;
            case OF_KEY_LEFT:
            colCount--;
            break;
            case OF_KEY_RIGHT:
            colCount++;
            break;
        default:
            break;
    }
    for (int i=0; i<samplers.size(); i++) {
        samplers[i].setGrid(rowCount, colCount);
    }

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
