/*
  ==============================================================================

    KM_ParameterSlider.cpp
    Created: 17 Jun 2021 4:55:43pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_ParameterSlider.h"

KM_ParameterSlider::KM_ParameterSlider(juce::AudioProcessorValueTreeState& stateToControl,
                                       const juce::String& KM_ParamterID,
                                       const juce::String& KM_ParamterID_Space)
:   juce::Slider(KM_ParamterID_Space)
{
    setSliderStyle(RotaryHorizontalVerticalDrag);
    setTextBoxStyle(TextEntryBoxPosition::TextBoxBelow, false, 0, 0); //invisible text, 0 0
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment =
    new juce::AudioProcessorValueTreeState::SliderAttachment(stateToControl, KM_ParamterID, *this);
    
    }

KM_ParameterSlider::~KM_ParameterSlider()
{
    
}
