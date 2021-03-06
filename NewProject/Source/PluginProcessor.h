/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "KM_gain.h"
#include "KM_delay.h"
#include "KM_LFO.h"

#include "KM_PresentManager.h"



//==============================================================================
/**
*/
class NewProjectAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    NewProjectAudioProcessor();
    ~NewProjectAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    
    float getInputMeterLevel(int inChannel);
    float getOutputMeterLevel(int inChannel);

    KM_PresentManager* getPresetManager();
    
    juce::AudioProcessorValueTreeState parameters;
    
    
    //std::unique_ptr<KM_PresentManager> getPresetManager()
    //{
    //    return std::move(mPresetManager);
        //return mPresetManager;
    //}
    


private:
    /** internal function */
    
    void InitializeParameters();
    
    void InitializeDSP();
    
    
    
    //std::unique_ptr<KM_gain> mGain [2];
    std::unique_ptr<KM_gain> mInputGain [2];
    std::unique_ptr<KM_gain> mOutputGain [2];
    std::unique_ptr<KM_LFO> mLFO [2];
    std::unique_ptr<KM_delay> mDelay [2];
    
    std::unique_ptr<KM_PresentManager> mPresetManager;
    //juce::ScopedPointer<KM_PresentManager> mPresetManager;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessor)
};
