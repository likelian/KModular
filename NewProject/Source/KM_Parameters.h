/*
  ==============================================================================

    KM_Parameters.h
    Created: 16 Jun 2021 5:12:30pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

enum KM_Parameter
{
    KParameter_InputGain = 0,
    KParameter_DelayTime,
    KParameter_DelayFeedback,
    KParameter_DelayWetDry,
    KParameter_DelayType, //chorus or delay
    KParameter_OutputGain,
    KParameter_ModulationRate,
    KParameter_ModulationDepth,
    KParameter_TotalNumParameters,
};

static juce::String KM_ParamterID [KParameter_TotalNumParameters] =
{
    "Input Gain",
    "Delay Time",
    "Delay Feedback",
    "Wet/Dry",
    "Delay Type",
    "Output Gain",
    "Modulation Rate",
    "Modulation Depth"
};
