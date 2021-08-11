/*
  ==============================================================================

    KM_LookAndFeel.h
    Created: 8 Aug 2021 4:05:50pm
    Author:  李克镰

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "KM_InterfaceDefines.h"

class KM_LookAndFeel
: public juce::LookAndFeel_V4
{
public:
    KM_LookAndFeel()
    {
        //Store Image Assets
        
        mSliderImage = juce::ImageCache::getFromMemory(BinaryData::kadenze_knob_png,
                                                       BinaryData::kadenze_knob_pngSize);
        
        //ComboBox colours
        setColour(juce::ComboBox::backgroundColourId, KMColour_3);
        setColour(juce::ComboBox::outlineColourId, KMColour_2);
        setColour(juce::ComboBox::arrowColourId, KMColour_1);
        setColour(juce::ComboBox::textColourId, KMColour_1);
        
        // button text colours
        
        setColour(juce::TextButton::buttonColourId, KMColour_1);
        setColour(juce::TextButton::textColourOnId, KMColour_1);
        setColour(juce::TextButton::textColourOffId, KMColour_1);
        
    }
    virtual ~KM_LookAndFeel(){}
    
    
    
    
    /* Buttons */
    juce::Font getTextButtonFont (juce::TextButton&, int buttonHeight) override
    {
        return font_1;
    }
    
    void drawButtonBackground (juce::Graphics& g,
                               juce::Button& button,
                               const juce::Colour& backgroundColour,
                               bool isMouseOverButton,
                               bool isButtonDown) override
    {
        juce::Colour fillColour;
        
        if(isButtonDown){
            fillColour = KMColour_6;
        } else if(isMouseOverButton){
            fillColour = KMColour_3;
        } else {
            fillColour = KMColour_5;
        }
        
        const float cornerSize = 6.0f;
        const juce::Rectangle<float> bounds = button.getLocalBounds().toFloat().reduced(0.5f,0.5f);
        
        g.setColour(fillColour);
        g.fillRoundedRectangle(bounds.reduced(1), cornerSize);
    };
    
    
    
    
    
    /* ComboBoxes */
    juce::Font getLabelFont (juce::Label&) override
    {
        return font_1;
    }
    
    void drawPopupMenuBackground(juce::Graphics &g, int width, int height) override
    {
        g.setColour(KMColour_4);
        g.fillRect(0,0,width,height);
    }
    
    void drawPopupMenuItem (juce::Graphics& g,
                            const juce::Rectangle<int>& area,
                            bool isSeparator,
                            bool isActive,
                            bool isHighlighted,
                            bool isTicked,
                            bool hasSubMenu,
                            const juce::String& text,
                            const juce::String& shortcutKeyText,
                            const juce::Drawable* icon,
                            const juce::Colour* textColour) override
    {
        juce::Rectangle<int> r (area);
        
        juce::Colour fillColour = (isHighlighted) ? KMColour_6 : KMColour_4;
        g.setColour(fillColour);
        g.fillRect(r.getX(), r.getY(), r.getWidth(), r.getHeight()-1);
        
        juce::Colour myTextColour = (isTicked) ? KMColour_7 : KMColour_1;
        g.setColour(myTextColour);
        g.setFont(font_1);
        
        r.setLeft(10);
        r.setY(1);
        g.drawFittedText(text, r, juce::Justification::left, 1);
    }
        
        
    void drawComboBox (juce::Graphics& g,
                        int width,
                        int height,
                        bool isButtonDown,
                        int buttonX,
                        int buttonY,
                        int buttonW,
                        int buttonH,
                        juce::ComboBox& box) override
    {
        const float cornerSize = 3.0f;
        const juce::Rectangle<int> boxBounds (0, 0, width, height);
        
        g.setColour(KMColour_3);
        g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);
        
        juce::Rectangle<int> arrow (width - 30, 0, 20, height);
        
        juce::Path path;
        
        path.startNewSubPath(arrow.getX() + 3.0f, arrow.getCentreY()- 2.0f);
        path.lineTo(arrow.toFloat().getCentreX(), arrow.toFloat().getCentreY() + 3.0f);
        path.lineTo(arrow.toFloat().getRight() - 3.0f, arrow.toFloat().getCentreY() - 2.0f);
        
        juce::Colour arrowColour = box.findColour(juce::ComboBox::arrowColourId).withAlpha((box.isEnabled)()? 0.9f : 0.2f);
        g.setColour(arrowColour);
        g.strokePath(path, juce::PathStrokeType(2.0f));
    }

    
    
    
    /* Sliders */
    void drawRotarySlider (juce::Graphics& g,
                           int x,
                           int y,
                           int width,
                           int height,
                           float sliderPos,
                           const float rotaryStartAngle,
                           const float rotaryEndAngle,
                           juce::Slider& slider) override
    {
        const int numFrames = mSliderImage.getHeight() / mSliderImage.getWidth();
        const int frameIndex = (int)std::ceil(sliderPos * (numFrames - 1));
        
        const float radius = juce::jmin(width*0.5, height*0.5);
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        
        g.drawImage(mSliderImage,
                    rx,
                    ry,
                    2*radius,
                    2*radius,
                    0,
                    frameIndex*mSliderImage.getWidth(),
                    mSliderImage.getWidth(),
                    mSliderImage.getWidth());
    }
    
    
    
    
    
private:
    juce::Image mSliderImage;
    
};
