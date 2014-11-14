//
//  WaterdropCon.cpp
//  waterdrop
//
//  Created by john namu choi on 10/23/14.
//
//

#include "WaterdropCon.h"
#include "cinder/app/AppNative.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using std::list;

WaterdropCon::WaterdropCon()
{
}
WaterdropCon::WaterdropCon(int x)
{
}

void WaterdropCon::setup()
{
    if( ! img00 )
        img00 = gl::Texture::create( ci::loadImage( ci::app::loadResource( "WD001.png" ) ) );
    if( ! img01 )
        img01 = gl::Texture::create( ci::loadImage( ci::app::loadResource( "WD002.png" ) ) );
    
}

void WaterdropCon::update()
{
    for( list<Waterdrop>::iterator w = mWaterdrop.begin(); w != mWaterdrop.end(); ++w ){
        w->update();
//            list<Waterdrop>::iterator w2 = w;
//            for( ++w2; w2 != mWaterdrop.end(); ++w2 ){
//                Vec2f dir = w2->loc - w->loc;
//                float length = dir.length();
//                if(length < w->radius + w2->radius){
//                    w->acc += dir*-0.0002f;
//                    w2->acc += dir*0.0002f;
//            }
//        }
    }
}

void WaterdropCon::draw()
{
    for( list<Waterdrop>::iterator w = mWaterdrop.begin(); w != mWaterdrop.end(); ++w ){
        w->draw();
    }
    //std::cout<<mWaterdrop.size()<<std::endl;
}

void WaterdropCon::addWaterdrop()
{
    float x,y;
    y = getWindowBounds().getHeight()+ 107.0;
    
    {
        x = 704 + generator.nextGaussian()*2.0f;
        Vec2f loc = Vec2f(x,y);
        mWaterdrop.push_back( Waterdrop(img00, img01, loc));
    }
    {
        x = 1672 + generator.nextGaussian()*2.0f;
        Vec2f loc = Vec2f(x,y);
        mWaterdrop.push_back( Waterdrop(img00, img01, loc));
    }
    
}
void WaterdropCon::removeWaterdrop()
{

     for( list<Waterdrop>::iterator w = mWaterdrop.begin(); w != mWaterdrop.end(); ++w ){
         if(w->loc.y<0){
             w=mWaterdrop.erase(w);
         }
     }
}