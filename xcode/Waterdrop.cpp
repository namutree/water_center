//
//  Waterdrop.cpp
//  waterdrop
//
//  Created by john namu choi on 10/23/14.
//
//

#include "Waterdrop.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Resources.h"
#include "cinder/app/AppNative.h"

using namespace ci;
using namespace ci::app;
using namespace std;


Waterdrop::Waterdrop()
{
}


Waterdrop::Waterdrop(const ci::gl::TextureRef &img00, const ci::gl::TextureRef &img01,ci::Vec2f pos) : myImage00(img00), myImage01(img01)
{
    Rand::randomize();
    
    loc = pos;
    radius = Rand::randInt(15.f,25.0f);
    
    vel = Vec2f( 0.0f, 0.0f );
    acc = Vec2f::zero();
    
    float randvalue = Rand::randFloat(2.0f);
    
    if(randvalue<1.0f)  thetaRan = Rand::randFloat(0.1f, - M_PI/2.5f);
    else                thetaRan = Rand::randFloat(M_PI , M_PI+M_PI/2.5f);

    thetaRanDenominator = Rand::randFloat(-M_PI/60, M_PI/60);

    randomImage = Rand::randFloat(1.f);
    
}

void Waterdrop::update()
{

    acc += Vec2f(cos(thetaRan), sin(thetaRan));
    thetaRan += thetaRanDenominator;
    
    //ascending value
    float asc = loc.y/getWindowHeight()*5+2;
    float ascending = Rand::randFloat(-asc, -asc+1);
    acc += Vec2f(0.0f,ascending);
  
    vel += acc;
    loc += vel;
    
    vel *= 0.5f;
    acc *= 0.0f;
}

void Waterdrop::draw()
{
    gl::color (1, 1, 1, 0.9);

    float sizeValue = (getWindowHeight()-loc.y)/getWindowHeight()*15;//lmap(loc.y, 0, getWindowHeight(), 5, 0);
    Vec2f Rad = Vec2f(radius+sizeValue,radius+sizeValue );
    if(randomImage<0.5)    gl::draw( myImage00, Rectf(loc-Rad,loc+Rad) );
    else        gl::draw(myImage01,Rectf(loc-Rad,loc+Rad));
    
}












