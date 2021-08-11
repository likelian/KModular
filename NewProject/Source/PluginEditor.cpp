/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "KM_LookAndFeel.h"


//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(MAIN_PANEL_WIDTH,
            MAIN_PANEL_HEIGHT);
    
    mMainPanel = new KM_MainPanel(&audioProcessor);
    addAndMakeVisible(mMainPanel);
    
    //mLookAndFeel = std::unique_ptr<KM_LookAndFeel>(new KM_LookAndFeel);
    //auto mLookAndFeel = std::make_unique<KM_LookAndFeel>();
    //mLookAndFeel = std::make_unique<KM_LookAndFeel>(&processor);
    
    mLookAndFeel = new KM_LookAndFeel();
    setLookAndFeel(mLookAndFeel);
    juce::LookAndFeel::setDefaultLookAndFeel(mLookAndFeel);
    
    mBackgroundImage = juce::ImageCache::getFromMemory(BinaryData::kadenze_bg_png, BinaryData::kadenze_bg_pngSize);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.drawImage(mBackgroundImage, getLocalBounds().toFloat());
    
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
