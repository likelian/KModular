/*
  ==============================================================================

    KM_gain.h
    Created: 12 May 2021 1:03:31pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

class KM_gain
{
public:
    
    KM_gain();//constructor
    ~KM_gain();//deconstructor
    
    void process(float* inAudio,
                 float inGain,            //gain control
                 float* outAudio,
                 int inNumSamplesToRender //block size
                 );//process functinon
    
    float getMeterLevel();

private:
    float mOutputSmoothed;
    
};
