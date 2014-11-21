#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIO.h"
#include "cinder/gl/Texture.h"
#include "cinder/Vector.h"
#include "WaterdropCon.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class water_centerApp : public AppNative {
public:
    void prepareSettings( Settings *settings );
    void setup();
    void mouseMove( MouseEvent event );
    void update();
    void draw();
    
    WaterdropCon mWaterdropCon;
    float a[2];
    bool signal;
    float waterLifeSpan01,waterLifeSpan02;
};

void water_centerApp::prepareSettings( Settings *settings){
    settings->setWindowSize( 3840, 1080 );
    settings->setFrameRate( 60.0f );
}

void water_centerApp::setup()
{
    //setFullScreen( true );
    
    gl::enableAlphaBlending(true);
    gl::enableAdditiveBlending();
    
    a[0]=0;
    a[1]=0;
    mWaterdropCon.setup();
}

void water_centerApp::mouseMove( MouseEvent event )
{
    //event.getY()에다가 OSC신호 넣고
    //300을 원하는 threshold로 설정하삼
    a[0] = a[1];
    a[1] = event.getY();
    if(a[0]>300 && a[1] <= 300){
        
        signal=true;
        waterLifeSpan01= getElapsedSeconds()*100.f;
    }
}

void water_centerApp::update()
{
    mWaterdropCon.update();
    mWaterdropCon.removeWaterdrop();
    if (signal) {
        waterLifeSpan02 = getElapsedSeconds()*100.f;
        float loopSignal = waterLifeSpan02-waterLifeSpan01;
        if ((int) loopSignal%95 < 30){
            mWaterdropCon.addWaterdrop();
        }
    }
}

void water_centerApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    
    
    mWaterdropCon.draw();
    
    //cout << getAverageFps() <<endl;
}

CINDER_APP_NATIVE( water_centerApp, RendererGl )
