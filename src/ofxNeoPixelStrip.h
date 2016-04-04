//
//  ofxNeoPixelStrip.h
//
//  Created by David Haylock on 25/05/2014.
//

#include <iostream>
#include "ofMain.h"
#include "ofxNeoPixelObject.h"

class ofxNeoPixelStrip : public ofxNeoPixelObject {
    public:
        ofxNeoPixelStrip();
        virtual ~ofxNeoPixelStrip();
    
        //! Constructor
        ofxNeoPixelStrip(int posx, int posy,int numberOfLeds,int spacing);
        ofxNeoPixelStrip(int posx, int posy,int numberOfLeds,int spacing, float angle);

    
        //! Setup Strip
        void setupLedStrip(int posx, int posy,int numberOfLeds,int spacing);
        void setupLedStrip(int posx, int posy,int numberOfLeds,int spacing, float angle);

    
        void drawGrabRegion(bool hideArea);
        void draw(int x, int y);
    
        float rotation_angle;
        int led_radius;
    

    private:
    
    
        // Draw Unit
        void ledStrip();
};
