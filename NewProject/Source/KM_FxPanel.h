/*
  ==============================================================================

    KM_FxPanel.h
    Created: 29 May 2021 9:56:10pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "KM_PanelBase.h"
#include "KM_ParameterSlider.h"

enum KM_FxPanelStyle
{
    KM_FxPanelStyle_Delay,
    KM_FxPanelStyle_chorus,
    KM_FxPanelStyle_TotalNumStyles
};

class KM_FxPanel
: public KM_PanelBase,
  public juce::ComboBox::Listener
{
public:
    KM_FxPanel(NewProjectAudioProcessor* inProcessor);
    ~KM_FxPanel();
    
    void paint(juce::Graphics& g);
    void setFxPanelStyle(KM_FxPanelStyle inStyle);
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;

private:
    KM_FxPanelStyle mStyle;
    
    juce::OwnedArray<KM_ParameterSlider> mSliders;
};
