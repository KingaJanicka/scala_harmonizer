/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class RootComponent  : public juce::Component,
                       public juce::Slider::Listener
{
public:
    //==============================================================================
    RootComponent ();
    ~RootComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> juce__slider1;
    std::unique_ptr<juce::Slider> juce__slider2;
    std::unique_ptr<juce::Slider> juce__slider3;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Slider> juce__slider4;
    std::unique_ptr<juce::Label> juce__label6;
    std::unique_ptr<juce::Slider> juce__slider5;
    std::unique_ptr<juce::Label> juce__label5;
    std::unique_ptr<juce::Label> juce__label7;
    std::unique_ptr<juce::Label> juce__label13;
    std::unique_ptr<juce::Slider> juce__slider7;
    std::unique_ptr<juce::Label> juce__label14;
    std::unique_ptr<juce::Label> juce__label17;
    std::unique_ptr<juce::Slider> juce__slider6;
    std::unique_ptr<juce::Label> juce__label18;
    std::unique_ptr<juce::Label> juce__label20;
    std::unique_ptr<juce::Slider> juce__slider19;
    std::unique_ptr<juce::Label> juce__label21;
    std::unique_ptr<juce::Slider> juce__slider8;
    std::unique_ptr<juce::Label> juce__label22;
    std::unique_ptr<juce::Slider> juce__slider18;
    std::unique_ptr<juce::Label> juce__label23;
    std::unique_ptr<juce::Slider> juce__slider17;
    std::unique_ptr<juce::Label> juce__label24;
    std::unique_ptr<juce::Label> juce__label25;
    std::unique_ptr<juce::Slider> juce__slider20;
    std::unique_ptr<juce::Label> juce__label28;
    std::unique_ptr<juce::Slider> juce__slider21;
    std::unique_ptr<juce::Label> juce__label29;
    std::unique_ptr<juce::Slider> juce__slider9;
    std::unique_ptr<juce::Slider> juce__slider10;
    std::unique_ptr<juce::Slider> juce__slider11;
    std::unique_ptr<juce::Label> juce__label8;
    std::unique_ptr<juce::Label> juce__label9;
    std::unique_ptr<juce::Label> juce__label10;
    std::unique_ptr<juce::Slider> juce__slider12;
    std::unique_ptr<juce::Label> juce__label11;
    std::unique_ptr<juce::Slider> juce__slider13;
    std::unique_ptr<juce::Label> juce__label12;
    std::unique_ptr<juce::Slider> juce__slider15;
    std::unique_ptr<juce::Label> juce__label15;
    std::unique_ptr<juce::Slider> juce__slider14;
    std::unique_ptr<juce::Label> juce__label19;
    std::unique_ptr<juce::Slider> juce__slider16;
    std::unique_ptr<juce::Label> juce__label30;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RootComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

