/*
  ==============================================================================

    KM_FxPanel.cpp
    Created: 29 May 2021 9:56:10pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_FxPanel.h"
#include "KM_Parameters.h"
#include "KM_HelperFunctions.h"

KM_FxPanel::KM_FxPanel(NewProjectAudioProcessor* inProcessor)
:   KM_PanelBase(inProcessor)
    //mStyle(KM_FxPanelStyle_Delay)
{
    setSize(FX_PANEL_WIDTH,
            FX_PANEL_HEIGHT);
    
    const int currentStyle = (int) mProcessor->getParameter(KParameter_DelayType);
    
    setFxPanelStyle((KM_FxPanelStyle) currentStyle);
    //setFxPanelStyle(KM_FxPanelStyle_chorus);
    
}

KM_FxPanel::~KM_FxPanel()
{
    
}


void KM_FxPanel::paint(juce::Graphics& g)
{
    KM_PanelBase::paint(g);
    
    switch (mStyle){
        case(KM_FxPanelStyle_Delay):
        {
            g.drawFittedText("DELAY", -7, -40, getWidth(), getHeight(), juce::Justification::centred, 1);
        } break;
    
        case(KM_FxPanelStyle_chorus):
        {
            g.drawFittedText("CHORUS", -7, -40, getWidth(), getHeight(), juce::Justification::centred, 1);
        } break;
        
        default:
        case(KM_FxPanelStyle_TotalNumStyles):
        {
            jassertfalse; //juce error assert
        } break;
    }
    
    //paint labels
    for (int i = 0; i < mSliders.size(); i++){
        paintComponent(g, mSliders[i]);
    }
        
}



void KM_FxPanel::setFxPanelStyle(KM_FxPanelStyle inStyle)
{
    mStyle = inStyle;
    
    mSliders.clear();
    
    const int slider_size = 56;
    int x = 130;
    int y = (getHeight()-slider_size)*0.5;
    
    switch (mStyle){
        case(KM_FxPanelStyle_Delay):
        {
            KM_ParameterSlider* time = new KM_ParameterSlider(mProcessor->parameters,
                                                              KM_ParamterID[KParameter_DelayTime]);
            time->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(time);
            mSliders.add(time);
            x += slider_size * 2;
            
            
            KM_ParameterSlider* feedback = new KM_ParameterSlider(mProcessor->parameters,
                                                            KM_ParamterID[KParameter_DelayFeedback]);
            feedback->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(feedback);
            mSliders.add(feedback);
            x += slider_size * 2;
            
            
            KM_ParameterSlider* wetDry = new KM_ParameterSlider(mProcessor->parameters,
                                                                KM_ParamterID[KParameter_DelayWetDry]);
            wetDry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetDry);
            mSliders.add(wetDry);

        } break;
    
        case(KM_FxPanelStyle_chorus):
        {
            KM_ParameterSlider* rate = new KM_ParameterSlider(mProcessor->parameters,
                                                              KM_ParamterID[ KParameter_ModulationRate]);
            rate->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(rate);
            mSliders.add(rate);
            x += slider_size * 2;
            
            
            KM_ParameterSlider* depth = new KM_ParameterSlider(mProcessor->parameters,
                                                              KM_ParamterID[ KParameter_ModulationDepth]);
            depth->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(depth);
            mSliders.add(depth);
            x += slider_size * 2;
            
            KM_ParameterSlider* wetDry = new KM_ParameterSlider(mProcessor->parameters,
                                                                KM_ParamterID[ KParameter_DelayWetDry]);
            wetDry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetDry);
            mSliders.add(wetDry);
            
        } break;
        
        default:
        case(KM_FxPanelStyle_TotalNumStyles):
        {
            jassertfalse; //juce error assert
        } break;
    }
    repaint();
}


void KM_FxPanel::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
    KM_FxPanelStyle style = (KM_FxPanelStyle)comboBoxThatHasChanged->getSelectedItemIndex();
    
    setFxPanelStyle(style);
}


    
