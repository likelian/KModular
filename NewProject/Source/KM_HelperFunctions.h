/*
  ==============================================================================

    KM_HelperFunctions.h
    Created: 18 Jun 2021 5:58:12pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "KM_InterfaceDefines.h"

inline void paintComponent(juce::Graphics& g, juce::Component* inComponent)
{
    const int x = inComponent->getX() - (inComponent->getWidth()*0.25);
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth()*1.5;
    const int h = 20;
    const float cornerSize = 3.0f;
    
    const juce::String label = inComponent->getName();
    g.setColour(KMColour_3);
    g.fillRoundedRectangle(x, y, w, h, cornerSize);
    
    //g.setColour(juce::Colours::darkgrey);
    g.setColour(KMColour_1);
    g.setFont(font_1);
    
    g.setColour(juce::Colours::darkgrey);
    g.drawFittedText(label, x, y, w, h, juce::Justification::centred, 1);
}


