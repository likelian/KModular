/*
  ==============================================================================

    KM_MainPanel.h
    Created: 29 May 2021 9:55:32pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once
#include "KM_PanelBase.h"

#include "KM_TopPanel.h"
#include "KM_GainPanel.h"
#include "KM_CenterPanel.h"



class KM_MainPanel
: public KM_PanelBase
{
public:
    KM_MainPanel(NewProjectAudioProcessor* inProcessor);
    ~KM_MainPanel();

private:
    juce::ScopedPointer<KM_TopPanel> mTopPanel;
    juce::ScopedPointer<KM_GainPanel> mInputGainPanel;
    juce::ScopedPointer<KM_GainPanel> mOutputGainPanel;
    juce::ScopedPointer<KM_CenterPanel> mCenterPanel;

};
