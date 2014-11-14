#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class water_centerApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void water_centerApp::setup()
{
}

void water_centerApp::mouseDown( MouseEvent event )
{
}

void water_centerApp::update()
{
}

void water_centerApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( water_centerApp, RendererGl )
