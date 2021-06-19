/*
  ==============================================================================

    KM_CenterPanelMenuBar.cpp
    Created: 29 May 2021 9:56:21pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_CenterPanelMenuBar.h"
#include "KM_Parameters.h"

KM_CenterPanelMenuBar::KM_CenterPanelMenuBar(NewProjectAudioProcessor* inProcessor)
:   KM_PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_MENU_BAR_WIDTH,
            CENTER_PANEL_MENU_BAR_HEIGHT);
    
    const int width = 85;
    
    mFxTypeComboBox = new KM_ParameterComboBox(mProcessor->parameters, KM_ParamterID[KParameter_DelayType]);
    
    mFxTypeComboBox->setBounds(getWidth()-width, 0, width, getHeight());
    //getWidth() only work after setSize()
    mFxTypeComboBox->addItem("DELAY", 1);
    mFxTypeComboBox->addItem("CHORUS", 2);
    mFxTypeComboBox->setSelectedItemIndex((int)mProcessor->getParameter(KParameter_DelayType),                                                 juce::dontSendNotification);
    addAndMakeVisible(mFxTypeComboBox);
    
}

KM_CenterPanelMenuBar::~KM_CenterPanelMenuBar()
{
    
}


void KM_CenterPanelMenuBar::addFxTypeComboBoxListener(juce::ComboBox::Listener* inListener)
{
    mFxTypeComboBox->addListener (inListener);
}

void KM_CenterPanelMenuBar::removeFxTypeComboBoxListener(juce::ComboBox::Listener* inListener)
{
    mFxTypeComboBox->removeListener (inListener);
}
