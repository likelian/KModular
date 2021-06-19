/*
  ==============================================================================

    KM_ParameterComboBox.cpp
    Created: 17 Jun 2021 4:56:06pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_ParameterComboBox.h"

KM_ParameterComboBox::KM_ParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl,
                                       const juce::String& parameterID)
:   juce::ComboBox(parameterID)
{
    mAttachment = new juce::AudioProcessorValueTreeState::ComboBoxAttachment(stateToControl, parameterID, *this);

}

KM_ParameterComboBox::~KM_ParameterComboBox()
{
    
}
