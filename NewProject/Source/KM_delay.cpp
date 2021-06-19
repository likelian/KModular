/*
  ==============================================================================

    KM_delay.cpp
    Created: 12 May 2021 1:03:40pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_delay.h"
#include "JuceHeader.h"
#include "KM_helper.h"



KM_delay::KM_delay()//constructor
:   mSampleRate(-1), //make it crash if no sample rate set from the host
    mFeedbackSample(0.0),
    mTimeSmoothed(0.0),
    mDelayIndex(0)
    
{

}
KM_delay::~KM_delay()//destructor
{
    
}

void KM_delay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KM_delay::reset()
{
    mTimeSmoothed = 0.0f;
    juce::zeromem(mBuffer, (sizeof(double) * maxBufferDelaySize)); //reset the buffer to zero
}





void KM_delay::process(float* inAudio,
             float inTime,
             float inFeedback,
             float inWetDry,
             float inType,
             float* inModBuffer,
             float* outAudio,
             int inNumSamplesToRender
             )

{
    const float wet = inWetDry;
    const float dry = 1.0f - inWetDry;
    
    float feedbackMapped = 0;
    if ((int)inType==KM_DelayType_Delay){
        feedbackMapped = juce::jmap(inFeedback, 0.0f, 1.0f, 0.0f, 1.20f); //avoid an infinite feedback, though there are ways to avoid that and also keep the 100% mapping
    }
    //const float feedbackMapped = juce::jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f); //avoid an infinite feedback, though there are ways to avoid that and also keep the 100% mapping
    
    //const double delayTimeModulation = 0.003 + (0.002 * inModBuffer[0]);
    
    //mTimeSmoothed = mTimeSmoothed  - KParameterSmoothingCoeff_Generic * (mTimeSmoothed - inModBuffer[0]);

    
    for (int i = 0; i < inNumSamplesToRender; i++){
        
        if ((int)inType==KM_DelayType_Delay){
            mTimeSmoothed = mTimeSmoothed - KParameterSmoothingCoeff_Fine * (mTimeSmoothed - inTime);
        }else{
            const double delayTimeModulation = 0.003 + (0.002 * inModBuffer[i]);
            mTimeSmoothed = mTimeSmoothed - KParameterSmoothingCoeff_Fine * (mTimeSmoothed - delayTimeModulation);
        }
        
        const double delayTimeSamples = (mTimeSmoothed * mSampleRate);
        
        //const double delayTimeSamples = inTime * mSampleRate;
        
        const double sample = getInterpolatedSample(delayTimeSamples);
        
        //mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        mBuffer[mDelayIndex] = tanh_clip(inAudio[i] + (mFeedbackSample * feedbackMapped));
        
        
        mFeedbackSample = sample;
        
        outAudio[i] = inAudio[i] * dry + sample * wet;
        
        mDelayIndex = mDelayIndex + 1;
        if (mDelayIndex > maxBufferDelaySize){
            mDelayIndex = mDelayIndex - maxBufferDelaySize;
        }
        
    }
}



double KM_delay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
    if (readPosition < 0.0f){
        readPosition = readPosition + maxBufferDelaySize;
    };
    
    int index_y0 = (int)readPosition - 1;
    if (index_y0 <= 0){
        index_y0  = index_y0 + maxBufferDelaySize;
    };
    
    int index_y1 = readPosition;
    if (index_y1 >= maxBufferDelaySize){
        index_y1  = index_y1 - maxBufferDelaySize;
    };
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float t = readPosition - (int)readPosition;
    
    double outSample = KM_linear_interp(sample_y0, sample_y1, t);
    
    return outSample;
}
