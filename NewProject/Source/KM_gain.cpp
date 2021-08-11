/*
  ==============================================================================

    KM_gain.cpp
    Created: 12 May 2021 1:03:31pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_gain.h"
#include "JuceHeader.h"
#include "KM_Helper.h"



KM_gain::KM_gain()//constructor
: mOutputSmoothed(0)
{
    
};

KM_gain::~KM_gain()//deconstructor
{
    
};

void KM_gain::process(float* inAudio,
             float inGain,            //gain control
             float* outAudio,
             int inNumSamplesToRender //block size
             )//process functinon
{
    
    float gainMapped = juce::jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = juce::Decibels::decibelsToGain(gainMapped, -24.0f); //-24.0f is the negative infinity
    
    for (int i = 0; i < inNumSamplesToRender; i++){
        outAudio[i] = inAudio[i] * gainMapped;
    };
    
    float absValue = fabs(outAudio[0]);
    mOutputSmoothed = KMeterSmoothingCoeff * (mOutputSmoothed - absValue) + absValue;
};

float KM_gain::getMeterLevel()
{
    return mOutputSmoothed;
};
