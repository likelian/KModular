/*
  ==============================================================================

    KM_delay.h
    Created: 12 May 2021 1:03:40pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "KM_helper.h"

enum KM_DelayType{
    KM_DelayType_Delay = 0,
    KM_DelayType_CHorus
};

class KM_delay
{
public:
    KM_delay();//constructor
    ~KM_delay();//destructor
    
    void setSampleRate(double inSampleRate); //host normally uses double to represent sample rate
    
    void reset();
    
    void process(float* inAudio,
                 float inTime,
                 float inFeedback,
                 float inWetDry,
                 float inType,
                 float* inModBuffer,
                 float* outAudio,
                 int inNumSamplesToRender
                 );

private:
    
    /** internal*/
    double getInterpolatedSample(float inDelayTimeInSamples);
    
    double mSampleRate; //m for member variables
    double mBuffer[maxBufferDelaySize]; //48000-sample delayline for now. It'll be dynamic
    double mFeedbackSample;
    
    float mTimeSmoothed; //smoothed version of inTime
    
    int mDelayIndex;
};
