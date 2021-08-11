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
    
    int button_x = 15;
    int button_y = 10;
    int button_w = 55;
    int button_h = 25;
    
    mNewPreset = new juce::TextButton();
    mNewPreset->setButtonText("NEW");
    mNewPreset->setBounds(button_x, button_y, button_w, button_h);
    mNewPreset->addListener(this);
    addAndMakeVisible(mNewPreset);
    
    button_x = button_x + button_w;
    mSavePreset = new juce::TextButton();
    mSavePreset->setButtonText("SAVE");
    mSavePreset->setBounds(button_x, button_y, button_w, button_h);
    mSavePreset->addListener(this);
    addAndMakeVisible(mSavePreset);
    
    button_x = button_x + button_w;
    mSaveAsPreset = new juce::TextButton();
    mSaveAsPreset->setButtonText("SAVE AS");
    mSaveAsPreset->setBounds(button_x, button_y, button_w, button_h);
    mSaveAsPreset->addListener(this);
    addAndMakeVisible(mSaveAsPreset);
    
    
    const int comboBox_w = 200;
    const int comboBox_x = TOP_PANEL_WIDTH*0.5 - comboBox_w*0.5;
    
    mPresetDisplay = new juce::ComboBox();
    mPresetDisplay->setBounds(comboBox_x, button_y, comboBox_w, button_h);
    mPresetDisplay->addListener(this);
    addAndMakeVisible(mPresetDisplay);
    
    updatePresetComboBox();
}

KM_TopPanel::~KM_TopPanel()
{
    
}

void KM_TopPanel::paint(juce::Graphics& g)
{
    KM_PanelBase::paint(g);
    
    g.setColour(KMColour_1);
    g.setFont(font_2);
    
    const int label_w = 300;
    
    g.drawFittedText("Kadenze Audio Plugin", TOP_PANEL_WIDTH - label_w - 20, 0, label_w, getHeight(), juce::Justification::centredRight, 1);
    
}



void KM_TopPanel::buttonClicked (juce::Button* b)
{
    //std::shared_ptr<KM_PresentManager> presetManager = mProcessor->getPresetManager();
    KM_PresentManager* presetManager = mProcessor->getPresetManager();
    
    if (b == mNewPreset){
        presetManager->createNewPreset();
        updatePresetComboBox();
    }
    else if (b == mSavePreset){
        presetManager->savePreset();
    }
    else if (b == mSaveAsPreset){
        displaySaveAsPopup();
        
    }
}
    
void KM_TopPanel::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == mPresetDisplay)
    {
        KM_PresentManager* presetManager = mProcessor->getPresetManager();
        const int index = mPresetDisplay->getSelectedItemIndex();
        presetManager->loadPreset(index);
    }
}

void KM_TopPanel::displaySaveAsPopup()
{
    //std::unique_ptr<KM_PresentManager> presetManager = mProcessor->getPresetManager();
    KM_PresentManager* presetManager = mProcessor->getPresetManager();
    
    juce::String currentPresetName = presetManager->getCurrentPresetName();
    
    juce::AlertWindow window("Save As",
                             "Please enter a name for your preset",
                             juce::AlertWindow::NoIcon);
    
    window.centreAroundComponent(this, getWidth(), getHeight());
    
    window.addTextEditor("presetName", currentPresetName, "preset name: ");
    
    
    window.addButton("confirm", 1);
    window.addButton("cancel", 0);
    
    if (window.runModalLoop()) // 1 if confirm, 0 if cancel
    {
        juce::String presetName = window.getTextEditor("presetName")->getText();
        presetManager->saveAsPreset(presetName);
        
        updatePresetComboBox();
    }
    
    
}
    


void KM_TopPanel::updatePresetComboBox()
{
    //std::shared_ptr<KM_PresentManager> presetManager = mProcessor->getPresetManager();
    
    KM_PresentManager* presetManager = mProcessor->getPresetManager();
    juce::String presetName = presetManager->getCurrentPresetName();
    
    mPresetDisplay->clear(juce::dontSendNotification);
    
    const int numPresets = presetManager->getNumberOfPresets();
    
    for (int i = 0; i < numPresets; i++){
        mPresetDisplay->addItem(presetManager->getPresetName(i), (i+1));
    }
    
    mPresetDisplay->setText(presetManager->getCurrentPresetName());
}
