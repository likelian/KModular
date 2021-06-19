/*
  ==============================================================================

    KM_CenterPanelMenuBar.h
    Created: 29 May 2021 9:56:21pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once
#include "KM_PanelBase.h"
#include "KM_ParameterComboBox.h"

class KM_CenterPanelMenuBar
: public KM_PanelBase
{
public:
    KM_CenterPanelMenuBar(NewProjectAudioProcessor* inProcessor);
    ~KM_CenterPanelMenuBar();
    
    void addFxTypeComboBoxListener(juce::ComboBox::Listener* inListener);
    void removeFxTypeComboBoxListener(juce::ComboBox::Listener* inListener);
    
    
    //void paint(juce::Graphics& g) override;

private:
    juce::ScopedPointer<KM_ParameterComboBox> mFxTypeComboBox;
    //std::unique_ptr<KM_ParameterComboBox> mFxTypeComboBox;
    
};
