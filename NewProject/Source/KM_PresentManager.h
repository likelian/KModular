/*
  ==============================================================================

    KM_PresentManager.h
    Created: 10 Jul 2021 4:29:34pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"


#define PRESET_FILE_EXTENSION ".kpf"


class KM_PresentManager
{
public:
    KM_PresentManager(juce::AudioProcessor* inProcessor); //the juce AudioProcessor as input
                                                          //so it can work with other plugins as well
    ~KM_PresentManager();
    
    void getXmlForPreset(juce::XmlElement* inElement); //XmlElement is the format JUCE stores parameters
    void loadPresetForXml(juce::XmlElement* inElement);
    
    int getNumberOfPresets();
    juce::String getPresetName(int inPresetIndex);
    void createNewPreset();
    void savePreset();
    void saveAsPreset(juce::String inPresetName);
    void loadPreset(int inPresetIndex);
    bool getIsCurrentPresetSaved(); //save as if not saved
    juce::String getCurrentPresetName();
    
    

private:
    
    void storeLocalPreset(); //only KM_PresentManager knows this function by purpose
    
    bool mCurrentPresetSaved;
    
    juce::File mCurrentlyLoadedPreset;
    
    juce::Array<juce::File> mLocalPresets;
    
    juce::String mCurrentPresetName;
    
    juce::String mPresetDirectory;
    
    
    
    juce::XmlElement* mCurrentPresetXml;
    juce::AudioProcessor* mProcessor;

};

