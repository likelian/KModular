/*
  ==============================================================================

    KM_PanelBase.cpp
    Created: 29 May 2021 9:53:27pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_PanelBase.h"

KM_PanelBase::KM_PanelBase(NewProjectAudioProcessor* inProcessor)
: mProcessor(inProcessor)
{
    
}

KM_PanelBase::~KM_PanelBase(){}



void KM_PanelBase:: paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::whitesmoke);
    g.fillAll();
    
    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight(), 2);
    
}
