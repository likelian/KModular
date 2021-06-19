/*
  ==============================================================================

    KM_ParameterSlider.cpp
    Created: 17 Jun 2021 4:55:43pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_ParameterSlider.h"

KM_ParameterSlider::KM_ParameterSlider(juce::AudioProcessorValueTreeState& stateToControl,
                                       const juce::String& parameterID)
:   juce::Slider(parameterID)
{
    setSliderStyle(RotaryHorizontalVerticalDrag);
    setTextBoxStyle(TextEntryBoxPosition::TextBoxBelow, false, 0, 0); //invisible text, 0 0
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment =
    new juce::AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterID, *this);
    
    }

KM_ParameterSlider::~KM_ParameterSlider()
{
    
}
