#pragma once
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

#include <vector>

class Waterdrop {
public:
    Waterdrop();
    Waterdrop(const ci::gl::TextureRef &img00, const ci::gl::TextureRef &img01,ci::Vec2f pos);
    void update();
    void draw();
    
    ci::Vec2f loc;
    ci::Vec2f vel;
    ci::Vec2f acc;
    float radius;
    
    float thetaRan, thetaRanDenominator;
    float randomImage;
    
    cinder::gl::TextureRef myImage00, myImage01;
};