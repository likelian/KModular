/*
  ==============================================================================

    KM_CenterPanel.h
    Created: 29 May 2021 9:56:30pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "KM_PanelBase.h"
#include "KM_CenterPanelMenuBar.h"
#include "KM_FxPanel.h"

class KM_CenterPanel
: public KM_PanelBase
{
public:
    KM_CenterPanel(NewProjectAudioProcessor* inProcessor);
    ~KM_CenterPanel();
    
    //void paint(juce::Graphics& g) override;

private:
    juce::ScopedPointer<KM_CenterPanelMenuBar> mMenuBar;
    juce::ScopedPointer<KM_FxPanel> mKM_FxPanel;
};
