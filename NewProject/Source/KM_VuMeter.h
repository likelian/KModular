/*
  ==============================================================================

    KM_VuMeter.h
    Created: 10 Aug 2021 4:26:54pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KM_InterfaceDefines.h"
#include "KM_Parameters.h"
#include "KM_helper.h"

class KM_VuMeter
: public juce::Component,
  public juce::Timer
{
public:
    KM_VuMeter(NewProjectAudioProcessor* inProcessor);
    ~KM_VuMeter();
    
    void paint(juce::Graphics& g) override;
    
    virtual void timerCallback() override;
    
    void setParameterID(int inParameterID);
    
private:
    
    
    float mCh0Level;
    float mCh1Level;
    
    int mParameterID;
    
    NewProjectAudioProcessor* mProcessor;
    
    
};
