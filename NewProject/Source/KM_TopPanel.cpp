/*
  ==============================================================================

    KM_TopPanel.cpp
    Created: 29 May 2021 9:57:02pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_TopPanel.h"

KM_TopPanel::KM_TopPanel(NewProjectAudioProcessor* inProcessor)
:   KM_PanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH,
            TOP_PANEL_HEIGHT);
}

KM_TopPanel::~KM_TopPanel()
{
    
}

void KM_TopPanel::paint(juce::Graphics& g)
{
    KM_PanelBase::paint(g);
    
    g.drawFittedText("Kadenze Audio Plugin", 0, 0, getWidth()-10, getHeight(), juce::Justification::centredRight, 1);
    
}


