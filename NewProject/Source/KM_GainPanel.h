/*
  ==============================================================================

    KM_GainPanel.h
    Created: 29 May 2021 9:56:01pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once
#include "KM_PanelBase.h"
#include "KM_ParameterSlider.h"


class KM_GainPanel
: public KM_PanelBase
{
public:
    KM_GainPanel(NewProjectAudioProcessor* inProcessor);
    ~KM_GainPanel();
    
    void setParameterID(int inParameterID);
    void paint(juce::Graphics& g) override;

private:
    juce::ScopedPointer<KM_ParameterSlider> mSlider;
    //std::unique_ptr<KM_ParameterSlider> mSlider;
};
