/*
  ==============================================================================

    KM_VuMeter.cpp
    Created: 10 Aug 2021 4:26:54pm
    Author:  李克镰

  ==============================================================================
*/

#include "KM_VuMeter.h"


KM_VuMeter::KM_VuMeter(NewProjectAudioProcessor* inProcessor)
:   mCh0Level(0),
    mCh1Level(0),
    mParameterID(-1),
    mProcessor(inProcessor)
{
    mCh0Level = 0;
    mCh1Level = 0;
    
    startTimerHz(15);
}


KM_VuMeter::~KM_VuMeter()
{
    
}

void KM_VuMeter::paint(juce::Graphics& g)
{
    const int meter_width = getWidth() / 3;
    
    g.setColour(KMColour_6);
    
    g.fillRect(0, 0, meter_width, getHeight()); //left channel
    
    g.fillRect(meter_width*2, 0, meter_width, getHeight()); //right channel
    
    int ch0fill = getHeight() - (getHeight() * mCh0Level);
    if(ch0fill<0){
        ch0fill = 0;
    }
    
    int ch1fill = getHeight() - (getHeight() * mCh1Level);
    if(ch1fill<0){
        ch1fill = 0;
    }
    
    g.setColour(KMColour_7);
    g.fillRect(0, ch0fill, meter_width, getHeight());
    g.fillRect(meter_width*2, ch0fill, meter_width, getHeight());
    
    
}

void KM_VuMeter::timerCallback()
{
    float updatedCh0Level = 0.0f;
    float updatedCh1Level = 0.0f;
    
    switch(mParameterID)
    {
        case(KParameter_InputGain):{
            updatedCh0Level = mProcessor->getInputMeterLevel(0);
            updatedCh1Level = mProcessor->getInputMeterLevel(1);
        } break;
            
        case(KParameter_OutputGain):{
            updatedCh0Level = mProcessor->getOutputMeterLevel(0);
            updatedCh1Level = mProcessor->getOutputMeterLevel(1);
        }break;
    }
    
    
    if (updatedCh0Level > mCh0Level){
        mCh0Level = updatedCh0Level;
    }else{
        mCh0Level = KMeterSmoothingCoeff * (mCh0Level - updatedCh0Level) + updatedCh0Level;
    }
    
    if (updatedCh1Level > mCh1Level){
        mCh1Level = updatedCh1Level;
    }else{
        mCh1Level = KMeterSmoothingCoeff * (mCh1Level - updatedCh1Level) + updatedCh1Level;
    }
    
    mCh0Level = KM_denormalize(mCh0Level);
    mCh1Level = KM_denormalize(mCh1Level);
    
    if (mCh0Level && mCh1Level){ //both values are not zero
        repaint();
    }
    
    
    
}

void KM_VuMeter::setParameterID(int inParameterID)
{
    mParameterID = inParameterID;
    startTimer(15); //refresh rate in Hz
}



