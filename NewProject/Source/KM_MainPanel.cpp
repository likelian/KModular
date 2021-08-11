/*
  ==============================================================================

    KM_MainPanel.cpp
    Created: 29 May 2021 9:55:32pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_MainPanel.h"
#include "KM_Parameters.h"



KM_MainPanel::KM_MainPanel(NewProjectAudioProcessor* inProcessor)
:   KM_PanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH,
            MAIN_PANEL_HEIGHT);
    
    mTopPanel = new KM_TopPanel(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel);
    
    mInputGainPanel = new KM_GainPanel(inProcessor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    mInputGainPanel->setParameterID(KParameter_InputGain);
    addAndMakeVisible(mInputGainPanel);
    
    mOutputGainPanel = new KM_GainPanel(inProcessor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    mOutputGainPanel->setParameterID(KParameter_OutputGain);
    addAndMakeVisible(mOutputGainPanel);
    
    mCenterPanel = new KM_CenterPanel(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCenterPanel);

    
    
    
    
}

KM_MainPanel::~KM_MainPanel()
{
    
}
