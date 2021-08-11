/*
  ==============================================================================

    KM_GainPanel.cpp
    Created: 29 May 2021 9:56:01pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_GainPanel.h"
#include "KM_Parameters.h"
#include "KM_HelperFunctions.h"

KM_GainPanel::KM_GainPanel(NewProjectAudioProcessor* inProcessor)
:   KM_PanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH,
            GAIN_PANEL_HEIGHT);
    
    const int meter_width = 64;
    mKM_VuMeter = std::make_unique<KM_VuMeter>(mProcessor);
    mKM_VuMeter->setBounds((getWidth() - meter_width)*0.5,
                            getHeight()*0.55 - meter_width*0.5,
                            meter_width,
                            getHeight()*0.45);
    
    addAndMakeVisible(mKM_VuMeter.get());
    
    
}

KM_GainPanel::~KM_GainPanel()
{
    
}

void KM_GainPanel::setParameterID(int inParameterID)
{
    mSlider = new KM_ParameterSlider(mProcessor->parameters, KM_ParamterID[inParameterID], KM_ParamterID_Space[inParameterID]);
    
    const int slider_size = 54;
    mSlider->setBounds((getWidth()-slider_size)*0.5,
                       (getHeight()*0.5-slider_size)*0.5 - 10,
                       slider_size,
                       slider_size);
    
    addAndMakeVisible(mSlider);
    
    mKM_VuMeter->setParameterID(inParameterID);
    
    
}

void KM_GainPanel::paint(juce::Graphics& g)
{
    KM_PanelBase::paint(g);
    if(mSlider){
    paintComponent(g, mSlider);
    }
}
