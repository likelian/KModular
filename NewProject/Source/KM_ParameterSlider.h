/*
  ==============================================================================

    KM_ParameterSlider.h
    Created: 17 Jun 2021 4:55:43pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KM_ParameterSlider
: public juce::Slider
{
public:
    KM_ParameterSlider(juce::AudioProcessorValueTreeState& stateToControl,
                       const juce::String& KM_ParamterID,
                       const juce::String& KM_ParamterID_Space);
    
    ~KM_ParameterSlider();
    
private:
    
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    //std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KM_ParameterSlider);
};

