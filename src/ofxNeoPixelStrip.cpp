//
//  ofxNeoPixelStrip.cpp
//
//  Created by David Haylock on 25/05/2014.
//

#include "ofxNeoPixelStrip.h"

//--------------------------------------------------------------
ofxNeoPixelStrip::ofxNeoPixelStrip()
{
    
}
//--------------------------------------------------------------
ofxNeoPixelStrip::~ofxNeoPixelStrip()
{
    
}
//--------------------------------------------------------------
ofxNeoPixelStrip::ofxNeoPixelStrip(int posx, int posy,int numberOfLeds,int spacing)
{
    // Setup Positioning
    size = numberOfLeds;
    offsetX = 5;
    offsetY = 5;
    _spacing = spacing;
    
    actualX = offsetX+posx;
    actualY = offsetY+posy;
    led_radius = 2;
    
    for (int i = 0; i < size; i++) {
        // Generate the position of the grabber points
        float rx = (offsetX+posx);
        float ry = (offsetY+posy) + (i*spacing);
        pos.push_back(ofVec2f(rx,ry));
    }
}

//--------------------------------------------------------------
ofxNeoPixelStrip::ofxNeoPixelStrip(int posx, int posy,int numberOfLeds,int spacing, float angle)
{
    // Setup Positioning
    size = numberOfLeds;
    _spacing = spacing;
    led_radius = 2;
    
    rotation_angle = angle;
    
    for ( int i = 0; i < size; i ++ ) {
        
        float rx = posx + ( i * spacing ) * sin ( angle );
        float ry = posy + ( i * spacing ) * cos ( angle );
    
        pos.push_back(ofVec2f(rx,ry));
    }
    
    cout <<  "pos: ( " << pos[ 0 ].x << ", " << pos[ 0 ].y << " )" << endl;
}
//--------------------------------------------------------------
void ofxNeoPixelStrip::setupLedStrip(int posx, int posy,int numberOfLeds,int spacing)
{
    // Setup Positioning
    size = numberOfLeds;
    offsetX = 5;
    offsetY = 5;
    _spacing = spacing;
    
    actualX = offsetX+posx;
    actualY = offsetY+posy;
    
    for (int i = 0; i < size; i++) {
        // Generate the position of the grabber points
        float rx = (offsetX+posx);
        float ry = (offsetY+posy) + ( i * spacing );
        pos.push_back(ofVec2f(rx,ry));
    }
}

//--------------------------------------------------------------
void ofxNeoPixelStrip::setupLedStrip(int posx, int posy,int numberOfLeds,int spacing, float angle)
{
    // Setup Positioning
    size = numberOfLeds;
    _spacing = spacing;
    led_radius = 2;
    
    rotation_angle = angle;
    
    for ( int i = 0; i < size; i ++ ) {
        
        float rx = posx + ( i * spacing ) * sin ( angle );
        float ry = posy + ( i * spacing ) * cos ( angle );
        
        pos.push_back(ofVec2f(rx,ry));
    }
    
    cout <<  "pos: ( " << pos[ 0 ].x << ", " << pos[ 0 ].y << " )" << endl;
}
//--------------------------------------------------------------
void ofxNeoPixelStrip::drawGrabRegion(bool hideArea)
{
    if (hideArea == true) {
        // Draw Interaction Area
        ofPushStyle();
        ofNoFill();
        ofSetLineWidth(1);
        ofSetColor(255, 255);
        ofPopStyle();
   
        // Visualise the Grabber
        ofSetColor(255, 175);
        ofNoFill();
    }
    else {
        // Visualise the Grabber
        ofSetColor(0, 175);
        ofNoFill();
    }
    
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    ofVertex( pos[ 0 ].x - _spacing, pos[ 0 ].y );
    ofVertex( pos[ 0 ].x + _spacing + led_radius / 2, pos[ 0 ].y);
    ofVertex( pos[ size - 1 ].x + _spacing + led_radius / 2, pos[ size - 1 ].y );
    ofVertex( pos[ size - 1 ].x - _spacing, pos[ size - 1 ].y );
    ofEndShape();
    
    for (int i = 0; i < pos.size(); i++) {
        ofDrawCircle(pos[i], led_radius);
    }
}
//--------------------------------------------------------------
void ofxNeoPixelStrip::ledStrip()
{
    ofFill();
    ofSetColor(100,175);
    
    //ofDrawRectangle(-offsetX,actualY-(offsetY/2), 10, size * _spacing);
    
    /*ofPushMatrix();
    ofRotate( rotation_angle * 180 / PI, pos[ 0 ].x - _spacing / 2, pos[ 0 ].y, 0 );
    //ofRotate(  );
    ofDrawRectangle( pos[ 0 ].x - _spacing / 2, pos[ 0 ].y, 10, size * _spacing );
    ofPopMatrix();*/
    
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    ofVertex( pos[ 0 ].x - _spacing, pos[ 0 ].y );
    ofVertex( pos[ 0 ].x + _spacing + led_radius / 2, pos[ 0 ].y);
    ofVertex( pos[ size - 1 ].x + _spacing + led_radius / 2, pos[ size - 1 ].y );
    ofVertex( pos[ size - 1 ].x - _spacing, pos[ size - 1 ].y );
    ofEndShape();

    
    for (int i = 0; i < size; i++)
    {
        ofFill();
        if (!colors.empty()) {
            
            /*if ( ofRandom( 100 ) > 20 ) {
                ofSetColor(colors[i]);
            }
            else {
                  ofSetColor( 0 );
            }*/
            
            ofSetColor( colors[ i ] );
        }
        else {
            ofSetColor(ofColor::red);
        }
        ofDrawCircle(pos[ i ].x,pos[ i ].y, led_radius);
    }
    
}
//--------------------------------------------------------------
void ofxNeoPixelStrip::draw(int x, int y)
{
    // Where to draw the Strip!
    ofPushMatrix();
    //ofTranslate(offsetX + x, y - pos[0].y);
    ofTranslate( 700, 0 );
    ledStrip();
    ofPopMatrix();
}