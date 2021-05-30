/*
  ==============================================================================

    KModular_helper.h
    Created: 12 May 2021 1:00:56pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#define KParameterSmoothingCoeff_Generic 0.04
#define KParameterSmoothingCoeff_Fine 0.002

const static double KM_pi = 3.14159265359;
const static double KM_2pi = 6.28318530718;

const static int maxBufferDelaySize = 192000;

inline float KM_linear_interp(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}
