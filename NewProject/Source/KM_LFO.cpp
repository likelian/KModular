/*
  ==============================================================================

    KM_LFO.cpp
    Created: 12 May 2021 1:02:31pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_LFO.h"
#include "JuceHeader.h"


KM_LFO::KM_LFO()
{
    reset();
}

KM_LFO::~KM_LFO()
{
    
}

void KM_LFO::reset()
{
    mPhase = 0.0f;
    juce::zeromem(mLFOBuffer, sizeof(float) * maxBufferDelaySize);
}


void KM_LFO::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}


void KM_LFO::process(float inRate,
                     float inDepth, //scalar
                     int inNumSamplesToRender //block size
                    )
{
    const float rate = juce::jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for (int i = 0; i < inNumSamplesToRender; i++){
        
        mPhase = mPhase + (rate / mSampleRate);
        
        if (mPhase >= 1.0f){
            mPhase = mPhase - 1.0f;
        }
        
        const float LFO_val = sinf(mPhase * KM_2pi) * inDepth;
        mLFOBuffer[i] = LFO_val;
    
    }
}


float* KM_LFO::getBuffer(){
    return mLFOBuffer;
}
