#include "ofApp.h"

//-------------------------------------------------------------- setup();
void ofApp::setup(){

    ofSetVerticalSync(true);
	ofSetCircleResolution(80);
	ofBackground(54, 54, 54);

	gui.setup("SEGMENTATION PARAMETERS");
	gui.add(sigma.setup("SIGMA", segmentation.sigma, 0, 2.0));
	gui.add(k.setup("K", segmentation.k, 0, 500));
	gui.add(min_size.setup("MIN SIZE", segmentation.min, 0, 50));
	
//	videoInput.initGrabber(320,240);
    
    ofDirectory dir;
    int nImages = dir.listDir("japan");
    for(int i=0; i<nImages; i++){
        ofImage img;
        img.loadImage(dir.getPath(i));
        images.push_back(img);
    }
    imagesI = 0;
    
}

//-------------------------------------------------------------- update();
void ofApp::update(){

	segmentation.sigma = sigma;
	segmentation.k = k;
	segmentation.min = min_size;

//	videoInput.update();
//	if(videoInput.isFrameNew()){
		segmentation.segment(images[imagesI].getPixelsRef());
		segmentedImage.setFromPixels(segmentation.getSegmentedPixels());
		segmentedImage.update();
//	}
}

//-------------------------------------------------------------- draw();
void ofApp::draw(){
	//images[imagesI].draw(0,0);
	if(segmentedImage.isAllocated()){
		//segmentedImage.draw(images[imagesI].getWidth(),0);
		//draw all the little masks below
		ofImage image;
        image.setFromPixels(segmentation.getSegmentMask(0));
        image.update();
        
        
        sampler.setup(&images[imagesI], &image, 20, 30);
        
        ofColor colour = getImageColour(&images[imagesI], &image);
        ofSetColor(colour);
        ofRect(160, 240, 160, 120);
        ofSetColor(255);
        
        sampler.draw(100, 100, 800);
        
//		for(int i = 0; i < segmentation.numSegments; i++){
//			image.setFromPixels(segmentation.getSegmentMask(i));
//			image.update();
//			image.draw((i+1)*160,240,160,120);
//		}
	}

	gui.draw();
}

ofColor ofApp::getImageColour(ofImage* img, ofImage * mask) {
    int r, g, b;
    r = g = b = 0;
    ofColor c;
    int n = 0;
    
    for (int y=0; y<mask->height; y++) {
        for (int x=0; x<mask->width; x++) {
            c = mask->getColor(x, y);
            if (c.r > 200) {
                c = img->getColor(x, y);
                if (c.r > 0 || c.g > 0 || c.b > 0) {
                    r += c.r;
                    g += c.g;
                    b += c.b;
                    n++;
                }
                
            }
        }
    }
    return ofColor(r/n, g/n, b/n);
}

//-------------------------------------------------------------- KeyBoard Events
void ofApp::keyPressed(int key){
    if (key==OF_KEY_RIGHT) {
        imagesI++;
    }
    else if (key==OF_KEY_LEFT) {
        imagesI--;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
