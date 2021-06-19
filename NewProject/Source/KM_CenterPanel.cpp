/*
  ==============================================================================

    KM_CenterPanel.cpp
    Created: 29 May 2021 9:56:30pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_CenterPanel.h"

KM_CenterPanel::KM_CenterPanel(NewProjectAudioProcessor* inProcessor)
:   KM_PanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH,
            CENTER_PANEL_HEIGHT);
    
    mMenuBar = new KM_CenterPanelMenuBar(inProcessor);
    mMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(mMenuBar);
    
    mKM_FxPanel = new KM_FxPanel(inProcessor);
    mKM_FxPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(mKM_FxPanel);
    
    mMenuBar->addFxTypeComboBoxListener(mKM_FxPanel);
    
}

KM_CenterPanel::~KM_CenterPanel()
{
    mMenuBar->removeFxTypeComboBoxListener(mKM_FxPanel);
}
