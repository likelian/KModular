#pragma once

#include "JuceHeader.h"



///** KAP max buffer size. */
//#define kMaxChannelBufferSize 192000
//
///** KAP max num channels. */
//#define kMaxNumChannels 8


#define KParameterSmoothingCoeff_Generic 0.04

#define KParameterSmoothingCoeff_Fine 0.002

#define KMeterSmoothingCoeff 0.7

const static double KM_pi = 3.14159265359;
const static double KM_2pi = 6.28318530718;

const static int maxBufferDelaySize = 192000;


static inline float dBToNormalizedGain(float inValue)
{
    float inValuedB = juce::Decibels::gainToDecibels(inValue + 0.00001f);
    inValuedB = (inValuedB + 96.0f) / 96.0f;
    
    return inValuedB;
    
}

inline float KM_linear_interp(float v0, float v1, float t)
{
    return (1 - t ) * v0 + t * v1;
}

inline float KM_denormalize(float inValue)
{
    float absValue = fabs(inValue);
    if (absValue < 1e-15){
        return 0;
    }else
    {
        return inValue;
    }
}

inline double tanh_clip(double x)
{
    return x * (27 + x * x) / (27 + 9 * x * x);
}


