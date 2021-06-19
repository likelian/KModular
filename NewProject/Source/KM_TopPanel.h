/*
  ==============================================================================

    KM_TopPanel.h
    Created: 29 May 2021 9:57:02pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once
#include "KM_PanelBase.h"


class KM_TopPanel
: public KM_PanelBase
{
public:
    KM_TopPanel(NewProjectAudioProcessor* inProcessor);
    ~KM_TopPanel();
    
    void paint(juce::Graphics& g) override;

private:
};
