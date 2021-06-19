/*
  ==============================================================================

    KM_LFO.h
    Created: 12 May 2021 1:02:31pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "KM_helper.h"

class   KM_LFO
{
public:
    KM_LFO();
    ~KM_LFO();
    
    void reset();
    
    void setSampleRate(double inSampleRate);
    
    void process(float inRate,
                 float inDepth, //scalar
                 int inNumSamplesToRender //block size
                );
    
    float* getBuffer();
    
private:
    double mSampleRate;
    float mPhase;
    float mLFOBuffer[maxBufferDelaySize]; //use the same memory location and rewrite the buffer, no need to allocate memeory each time
};
