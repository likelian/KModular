/*
  ==============================================================================

    KM_PanelBase.h
    Created: 29 May 2021 9:53:27pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KM_InterfaceDefines.h"

class KM_PanelBase
: public juce::Component
{
public:
    KM_PanelBase(NewProjectAudioProcessor* inProcessor);
    ~KM_PanelBase();
    
    void paint(juce::Graphics& g) override;
    
    void mouseEnter (const juce::MouseEvent& event) override;
    
    void mouseExit (const juce::MouseEvent& event) override;
    

protected:
    NewProjectAudioProcessor* mProcessor;
    
};
