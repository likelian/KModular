/*
  ==============================================================================

    KM_ParameterComboBox.h
    Created: 17 Jun 2021 4:56:06pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class KM_ParameterComboBox
: public juce::ComboBox
{
public:
    KM_ParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl,
                       const juce::String& parameterID);
    
    ~KM_ParameterComboBox();
    
private:
    
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    //std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KM_ParameterComboBox);
};
