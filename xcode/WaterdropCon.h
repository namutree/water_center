//
//  WaterdropCon.h
//  waterdrop
//
//  Created by john namu choi on 10/23/14.
//
//
#pragma once
#include "cinder/Rand.h"
#include "cinder/Channel.h"
#include "Waterdrop.h"
#include <list>

class WaterdropCon {
public:
    WaterdropCon();
    WaterdropCon(int x);
    void setup();
    void update();
    void draw();
    void addWaterdrop();
    void removeWaterdrop();
    
    std::list<Waterdrop> mWaterdrop;
    cinder::Rand generator;
    
    ci::gl::TextureRef img00, img01;
    
    
};
