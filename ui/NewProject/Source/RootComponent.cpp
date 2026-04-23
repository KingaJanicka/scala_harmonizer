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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "RootComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
RootComponent::RootComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__slider1.reset (new juce::Slider ("pitchShifter1/pitchQuantizer/transp"));
    addAndMakeVisible (juce__slider1.get());
    juce__slider1->setRange (0, 10, 0);
    juce__slider1->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider1->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider1->addListener (this);

    juce__slider1->setBounds (8, 32, 72, 128);

    juce__slider2.reset (new juce::Slider ("delay1/dlyTimeSynced"));
    addAndMakeVisible (juce__slider2.get());
    juce__slider2->setRange (0, 10, 0);
    juce__slider2->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider2->addListener (this);

    juce__slider2->setBounds (88, 32, 72, 128);

    juce__slider3.reset (new juce::Slider ("shifterFilter1/cutoff"));
    addAndMakeVisible (juce__slider3.get());
    juce__slider3->setRange (0, 10, 0);
    juce__slider3->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider3->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider3->addListener (this);

    juce__slider3->setBounds (168, 32, 72, 128);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Delay 1\n")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (16, 8, 150, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("LP Freq\n")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (168, 168, 64, 24);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("Time\n")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (96, 168, 56, 24);

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS("Transpose")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (8, 168, 80, 24);

    juce__slider4.reset (new juce::Slider ("diffusion1/diffuseTime"));
    addAndMakeVisible (juce__slider4.get());
    juce__slider4->setRange (0, 10, 0);
    juce__slider4->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider4->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider4->addListener (this);

    juce__slider4->setBounds (248, 32, 72, 128);

    juce__label6.reset (new juce::Label ("new label",
                                         TRANS("Diffuse time")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredLeft);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (240, 168, 80, 24);

    juce__slider5.reset (new juce::Slider ("diffusion1/diffuseGain"));
    addAndMakeVisible (juce__slider5.get());
    juce__slider5->setRange (0, 10, 0);
    juce__slider5->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider5->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider5->addListener (this);

    juce__slider5->setBounds (328, 32, 72, 128);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("Diffuse gain\n")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (320, 168, 88, 24);

    juce__label7.reset (new juce::Label ("new label",
                                         TRANS("Delay 2\n")));
    addAndMakeVisible (juce__label7.get());
    juce__label7->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label7->setJustificationType (juce::Justification::centredLeft);
    juce__label7->setEditable (false, false, false);
    juce__label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label7->setBounds (16, 224, 150, 24);

    juce__label13.reset (new juce::Label ("new label",
                                          TRANS("Feedback Matrix\n")));
    addAndMakeVisible (juce__label13.get());
    juce__label13->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label13->setJustificationType (juce::Justification::centredLeft);
    juce__label13->setEditable (false, false, false);
    juce__label13->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label13->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label13->setBounds (424, 8, 150, 24);

    juce__slider7.reset (new juce::Slider ("feedbackMixer/1x1"));
    addAndMakeVisible (juce__slider7.get());
    juce__slider7->setRange (0, 10, 0);
    juce__slider7->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider7->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider7->addListener (this);

    juce__slider7->setBounds (488, 32, 72, 128);

    juce__label14.reset (new juce::Label ("new label",
                                          TRANS("1x1\n")));
    addAndMakeVisible (juce__label14.get());
    juce__label14->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label14->setJustificationType (juce::Justification::centredLeft);
    juce__label14->setEditable (false, false, false);
    juce__label14->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label14->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label14->setBounds (504, 176, 40, 16);

    juce__label17.reset (new juce::Label ("new label",
                                          TRANS("1x2\n")));
    addAndMakeVisible (juce__label17.get());
    juce__label17->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label17->setJustificationType (juce::Justification::centredLeft);
    juce__label17->setEditable (false, false, false);
    juce__label17->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label17->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label17->setBounds (584, 176, 56, 16);

    juce__slider6.reset (new juce::Slider ("feedbackMixer/dly1PrePost"));
    addAndMakeVisible (juce__slider6.get());
    juce__slider6->setRange (0, 10, 0);
    juce__slider6->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider6->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider6->addListener (this);

    juce__slider6->setBounds (408, 32, 72, 128);

    juce__label18.reset (new juce::Label ("new label",
                                          TRANS("Shimmer")));
    addAndMakeVisible (juce__label18.get());
    juce__label18->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label18->setJustificationType (juce::Justification::centredLeft);
    juce__label18->setEditable (false, false, false);
    juce__label18->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label18->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label18->setBounds (408, 168, 64, 24);

    juce__label20.reset (new juce::Label ("new label",
                                          TRANS("Volumes\n")));
    addAndMakeVisible (juce__label20.get());
    juce__label20->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label20->setJustificationType (juce::Justification::centredLeft);
    juce__label20->setEditable (false, false, false);
    juce__label20->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label20->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label20->setBounds (24, 424, 150, 24);

    juce__slider19.reset (new juce::Slider ("dly2Vol"));
    addAndMakeVisible (juce__slider19.get());
    juce__slider19->setRange (0, 10, 0);
    juce__slider19->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider19->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider19->addListener (this);

    juce__slider19->setBounds (184, 451, 72, 128);

    juce__label21.reset (new juce::Label ("new label",
                                          TRANS("Delay 2\n")));
    addAndMakeVisible (juce__label21.get());
    juce__label21->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label21->setJustificationType (juce::Justification::centredLeft);
    juce__label21->setEditable (false, false, false);
    juce__label21->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label21->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label21->setBounds (192, 592, 56, 16);

    juce__slider8.reset (new juce::Slider ("feedbackMixer/1x2"));
    addAndMakeVisible (juce__slider8.get());
    juce__slider8->setRange (0, 10, 0);
    juce__slider8->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider8->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider8->addListener (this);

    juce__slider8->setBounds (568, 32, 72, 128);

    juce__label22.reset (new juce::Label ("new label",
                                          TRANS("1x2\n")));
    addAndMakeVisible (juce__label22.get());
    juce__label22->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label22->setJustificationType (juce::Justification::centredLeft);
    juce__label22->setEditable (false, false, false);
    juce__label22->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label22->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label22->setBounds (584, 176, 56, 16);

    juce__slider18.reset (new juce::Slider ("dly1Vol"));
    addAndMakeVisible (juce__slider18.get());
    juce__slider18->setRange (0, 10, 0);
    juce__slider18->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider18->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider18->addListener (this);

    juce__slider18->setBounds (96, 448, 72, 128);

    juce__label23.reset (new juce::Label ("new label",
                                          TRANS("Delay 1\n")));
    addAndMakeVisible (juce__label23.get());
    juce__label23->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label23->setJustificationType (juce::Justification::centredLeft);
    juce__label23->setEditable (false, false, false);
    juce__label23->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label23->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label23->setBounds (104, 592, 56, 16);

    juce__slider17.reset (new juce::Slider ("dryVol"));
    addAndMakeVisible (juce__slider17.get());
    juce__slider17->setRange (0, 10, 0);
    juce__slider17->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider17->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider17->addListener (this);

    juce__slider17->setBounds (16, 448, 72, 128);

    juce__label24.reset (new juce::Label ("new label",
                                          TRANS("Dry\n")));
    addAndMakeVisible (juce__label24.get());
    juce__label24->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label24->setJustificationType (juce::Justification::centredLeft);
    juce__label24->setEditable (false, false, false);
    juce__label24->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label24->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label24->setBounds (24, 592, 56, 16);

    juce__label25.reset (new juce::Label ("new label",
                                          TRANS("Quantizer\n")));
    addAndMakeVisible (juce__label25.get());
    juce__label25->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label25->setJustificationType (juce::Justification::centredLeft);
    juce__label25->setEditable (false, false, false);
    juce__label25->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label25->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label25->setBounds (352, 424, 150, 24);

    juce__slider20.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider20.get());
    juce__slider20->setRange (0, 10, 0);
    juce__slider20->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider20->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider20->addListener (this);

    juce__slider20->setBounds (348, 456, 72, 128);

    juce__label28.reset (new juce::Label ("new label",
                                          TRANS("Scale Select\n")));
    addAndMakeVisible (juce__label28.get());
    juce__label28->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label28->setJustificationType (juce::Justification::centredLeft);
    juce__label28->setEditable (false, false, false);
    juce__label28->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label28->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label28->setBounds (348, 584, 88, 24);

    juce__slider21.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider21.get());
    juce__slider21->setRange (0, 10, 0);
    juce__slider21->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider21->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider21->addListener (this);

    juce__slider21->setBounds (444, 456, 72, 128);

    juce__label29.reset (new juce::Label ("new label",
                                          TRANS("Scale Transpose\n")));
    addAndMakeVisible (juce__label29.get());
    juce__label29->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label29->setJustificationType (juce::Justification::centredLeft);
    juce__label29->setEditable (false, false, false);
    juce__label29->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label29->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label29->setBounds (444, 584, 116, 24);

    juce__slider9.reset (new juce::Slider ("pitchShifter2/pitchQuantizer/transp"));
    addAndMakeVisible (juce__slider9.get());
    juce__slider9->setRange (0, 10, 0);
    juce__slider9->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider9->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider9->addListener (this);

    juce__slider9->setBounds (16, 248, 72, 128);

    juce__slider10.reset (new juce::Slider ("delay2/dlyTimeSynced"));
    addAndMakeVisible (juce__slider10.get());
    juce__slider10->setRange (0, 10, 0);
    juce__slider10->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider10->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider10->addListener (this);

    juce__slider10->setBounds (96, 248, 72, 128);

    juce__slider11.reset (new juce::Slider ("shifterFilter2/cutoff"));
    addAndMakeVisible (juce__slider11.get());
    juce__slider11->setRange (0, 10, 0);
    juce__slider11->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider11->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider11->addListener (this);

    juce__slider11->setBounds (176, 248, 72, 128);

    juce__label8.reset (new juce::Label ("new label",
                                         TRANS("LP Freq\n")));
    addAndMakeVisible (juce__label8.get());
    juce__label8->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label8->setJustificationType (juce::Justification::centredLeft);
    juce__label8->setEditable (false, false, false);
    juce__label8->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label8->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label8->setBounds (174, 386, 64, 24);

    juce__label9.reset (new juce::Label ("new label",
                                         TRANS("Time\n")));
    addAndMakeVisible (juce__label9.get());
    juce__label9->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label9->setJustificationType (juce::Justification::centredLeft);
    juce__label9->setEditable (false, false, false);
    juce__label9->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label9->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label9->setBounds (102, 386, 56, 24);

    juce__label10.reset (new juce::Label ("new label",
                                          TRANS("Transpose")));
    addAndMakeVisible (juce__label10.get());
    juce__label10->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label10->setJustificationType (juce::Justification::centredLeft);
    juce__label10->setEditable (false, false, false);
    juce__label10->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label10->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label10->setBounds (14, 386, 80, 24);

    juce__slider12.reset (new juce::Slider ("diffusion2/diffuseTime"));
    addAndMakeVisible (juce__slider12.get());
    juce__slider12->setRange (0, 10, 0);
    juce__slider12->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider12->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider12->addListener (this);

    juce__slider12->setBounds (256, 248, 72, 128);

    juce__label11.reset (new juce::Label ("new label",
                                          TRANS("Diffuse time")));
    addAndMakeVisible (juce__label11.get());
    juce__label11->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label11->setJustificationType (juce::Justification::centredLeft);
    juce__label11->setEditable (false, false, false);
    juce__label11->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label11->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label11->setBounds (246, 386, 80, 24);

    juce__slider13.reset (new juce::Slider ("diffusion2/diffuseGain"));
    addAndMakeVisible (juce__slider13.get());
    juce__slider13->setRange (0, 10, 0);
    juce__slider13->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider13->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider13->addListener (this);

    juce__slider13->setBounds (336, 248, 72, 128);

    juce__label12.reset (new juce::Label ("new label",
                                          TRANS("Diffuse gain\n")));
    addAndMakeVisible (juce__label12.get());
    juce__label12->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label12->setJustificationType (juce::Justification::centredLeft);
    juce__label12->setEditable (false, false, false);
    juce__label12->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label12->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label12->setBounds (326, 386, 88, 24);

    juce__slider15.reset (new juce::Slider ("feedbackMixer/2x1"));
    addAndMakeVisible (juce__slider15.get());
    juce__slider15->setRange (0, 10, 0);
    juce__slider15->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider15->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider15->addListener (this);

    juce__slider15->setBounds (496, 248, 72, 128);

    juce__label15.reset (new juce::Label ("new label",
                                          TRANS("2x1")));
    addAndMakeVisible (juce__label15.get());
    juce__label15->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label15->setJustificationType (juce::Justification::centredLeft);
    juce__label15->setEditable (false, false, false);
    juce__label15->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label15->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label15->setBounds (510, 394, 40, 16);

    juce__slider14.reset (new juce::Slider ("feedbackMixer/dly2PrePost"));
    addAndMakeVisible (juce__slider14.get());
    juce__slider14->setRange (0, 10, 0);
    juce__slider14->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider14->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider14->addListener (this);

    juce__slider14->setBounds (416, 248, 72, 128);

    juce__label19.reset (new juce::Label ("new label",
                                          TRANS("Shimmer")));
    addAndMakeVisible (juce__label19.get());
    juce__label19->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label19->setJustificationType (juce::Justification::centredLeft);
    juce__label19->setEditable (false, false, false);
    juce__label19->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label19->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label19->setBounds (414, 386, 64, 24);

    juce__slider16.reset (new juce::Slider ("feedbackMixer/2x2"));
    addAndMakeVisible (juce__slider16.get());
    juce__slider16->setRange (0, 10, 0);
    juce__slider16->setSliderStyle (juce::Slider::LinearVertical);
    juce__slider16->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider16->addListener (this);

    juce__slider16->setBounds (576, 248, 72, 128);

    juce__label30.reset (new juce::Label ("new label",
                                          TRANS("2x2")));
    addAndMakeVisible (juce__label30.get());
    juce__label30->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label30->setJustificationType (juce::Justification::centredLeft);
    juce__label30->setEditable (false, false, false);
    juce__label30->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label30->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label30->setBounds (584, 392, 56, 16);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

RootComponent::~RootComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__slider1 = nullptr;
    juce__slider2 = nullptr;
    juce__slider3 = nullptr;
    juce__label = nullptr;
    juce__label2 = nullptr;
    juce__label3 = nullptr;
    juce__label4 = nullptr;
    juce__slider4 = nullptr;
    juce__label6 = nullptr;
    juce__slider5 = nullptr;
    juce__label5 = nullptr;
    juce__label7 = nullptr;
    juce__label13 = nullptr;
    juce__slider7 = nullptr;
    juce__label14 = nullptr;
    juce__label17 = nullptr;
    juce__slider6 = nullptr;
    juce__label18 = nullptr;
    juce__label20 = nullptr;
    juce__slider19 = nullptr;
    juce__label21 = nullptr;
    juce__slider8 = nullptr;
    juce__label22 = nullptr;
    juce__slider18 = nullptr;
    juce__label23 = nullptr;
    juce__slider17 = nullptr;
    juce__label24 = nullptr;
    juce__label25 = nullptr;
    juce__slider20 = nullptr;
    juce__label28 = nullptr;
    juce__slider21 = nullptr;
    juce__label29 = nullptr;
    juce__slider9 = nullptr;
    juce__slider10 = nullptr;
    juce__slider11 = nullptr;
    juce__label8 = nullptr;
    juce__label9 = nullptr;
    juce__label10 = nullptr;
    juce__slider12 = nullptr;
    juce__label11 = nullptr;
    juce__slider13 = nullptr;
    juce__label12 = nullptr;
    juce__slider15 = nullptr;
    juce__label15 = nullptr;
    juce__slider14 = nullptr;
    juce__label19 = nullptr;
    juce__slider16 = nullptr;
    juce__label30 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void RootComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void RootComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void RootComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == juce__slider1.get())
    {
        //[UserSliderCode_juce__slider1] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider1]
    }
    else if (sliderThatWasMoved == juce__slider2.get())
    {
        //[UserSliderCode_juce__slider2] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider2]
    }
    else if (sliderThatWasMoved == juce__slider3.get())
    {
        //[UserSliderCode_juce__slider3] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider3]
    }
    else if (sliderThatWasMoved == juce__slider4.get())
    {
        //[UserSliderCode_juce__slider4] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider4]
    }
    else if (sliderThatWasMoved == juce__slider5.get())
    {
        //[UserSliderCode_juce__slider5] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider5]
    }
    else if (sliderThatWasMoved == juce__slider7.get())
    {
        //[UserSliderCode_juce__slider7] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider7]
    }
    else if (sliderThatWasMoved == juce__slider6.get())
    {
        //[UserSliderCode_juce__slider6] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider6]
    }
    else if (sliderThatWasMoved == juce__slider19.get())
    {
        //[UserSliderCode_juce__slider19] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider19]
    }
    else if (sliderThatWasMoved == juce__slider8.get())
    {
        //[UserSliderCode_juce__slider8] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider8]
    }
    else if (sliderThatWasMoved == juce__slider18.get())
    {
        //[UserSliderCode_juce__slider18] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider18]
    }
    else if (sliderThatWasMoved == juce__slider17.get())
    {
        //[UserSliderCode_juce__slider17] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider17]
    }
    else if (sliderThatWasMoved == juce__slider20.get())
    {
        //[UserSliderCode_juce__slider20] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider20]
    }
    else if (sliderThatWasMoved == juce__slider21.get())
    {
        //[UserSliderCode_juce__slider21] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider21]
    }
    else if (sliderThatWasMoved == juce__slider9.get())
    {
        //[UserSliderCode_juce__slider9] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider9]
    }
    else if (sliderThatWasMoved == juce__slider10.get())
    {
        //[UserSliderCode_juce__slider10] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider10]
    }
    else if (sliderThatWasMoved == juce__slider11.get())
    {
        //[UserSliderCode_juce__slider11] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider11]
    }
    else if (sliderThatWasMoved == juce__slider12.get())
    {
        //[UserSliderCode_juce__slider12] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider12]
    }
    else if (sliderThatWasMoved == juce__slider13.get())
    {
        //[UserSliderCode_juce__slider13] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider13]
    }
    else if (sliderThatWasMoved == juce__slider15.get())
    {
        //[UserSliderCode_juce__slider15] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider15]
    }
    else if (sliderThatWasMoved == juce__slider14.get())
    {
        //[UserSliderCode_juce__slider14] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider14]
    }
    else if (sliderThatWasMoved == juce__slider16.get())
    {
        //[UserSliderCode_juce__slider16] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider16]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="RootComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="pitchShifter1/pitchQuantizer/transp" id="51e517705afb505e"
          memberName="juce__slider1" virtualName="" explicitFocusOrder="0"
          pos="8 32 72 128" min="0.0" max="10.0" int="0.0" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="delay1/dlyTimeSynced" id="3ad34897213d204d" memberName="juce__slider2"
          virtualName="" explicitFocusOrder="0" pos="88 32 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="shifterFilter1/cutoff" id="52f346eab11047ce" memberName="juce__slider3"
          virtualName="" explicitFocusOrder="0" pos="168 32 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="f88c9c3dc38c45e6" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="16 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay 1&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="880c968503e08be4" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="168 168 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LP Freq&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2a211c28ac5aad75" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="96 168 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b0a53b2b7c13e772" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="8 168 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Transpose" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="diffusion1/diffuseTime" id="b593b58b11cc2f17" memberName="juce__slider4"
          virtualName="" explicitFocusOrder="0" pos="248 32 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="ae030bde6438c864" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="240 168 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Diffuse time" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="diffusion1/diffuseGain" id="1686296a84131db6" memberName="juce__slider5"
          virtualName="" explicitFocusOrder="0" pos="328 32 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="f8b10cd5e3329a7" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="320 168 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Diffuse gain&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="9f1a201160647653" memberName="juce__label7"
         virtualName="" explicitFocusOrder="0" pos="16 224 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay 2&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8de5ab8ce7e7e353" memberName="juce__label13"
         virtualName="" explicitFocusOrder="0" pos="424 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback Matrix&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="feedbackMixer/1x1" id="542769b8d18c6dd7" memberName="juce__slider7"
          virtualName="" explicitFocusOrder="0" pos="488 32 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="7c55add4cb9a38ad" memberName="juce__label14"
         virtualName="" explicitFocusOrder="0" pos="504 176 40 16" edTextCol="ff000000"
         edBkgCol="0" labelText="1x1&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b1efd588d558e6f8" memberName="juce__label17"
         virtualName="" explicitFocusOrder="0" pos="584 176 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="1x2&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="feedbackMixer/dly1PrePost" id="42a6b9b999b90fc6" memberName="juce__slider6"
          virtualName="" explicitFocusOrder="0" pos="408 32 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="bdcd949338d01863" memberName="juce__label18"
         virtualName="" explicitFocusOrder="0" pos="408 168 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Shimmer" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="94c7e88e3b6e4dd3" memberName="juce__label20"
         virtualName="" explicitFocusOrder="0" pos="24 424 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Volumes&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="dly2Vol" id="f16e1acf1258889" memberName="juce__slider19"
          virtualName="" explicitFocusOrder="0" pos="184 451 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="fdbdcf33b6e787c1" memberName="juce__label21"
         virtualName="" explicitFocusOrder="0" pos="192 592 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay 2&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="feedbackMixer/1x2" id="d6a0625494f831fd" memberName="juce__slider8"
          virtualName="" explicitFocusOrder="0" pos="568 32 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="7af3b6f54bf2f24d" memberName="juce__label22"
         virtualName="" explicitFocusOrder="0" pos="584 176 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="1x2&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="dly1Vol" id="5023253a14b5969b" memberName="juce__slider18"
          virtualName="" explicitFocusOrder="0" pos="96 448 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="77914cc06fa6ab78" memberName="juce__label23"
         virtualName="" explicitFocusOrder="0" pos="104 592 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay 1&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="dryVol" id="7c31d4ef59151694" memberName="juce__slider17"
          virtualName="" explicitFocusOrder="0" pos="16 448 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="adfa3872c517f28c" memberName="juce__label24"
         virtualName="" explicitFocusOrder="0" pos="24 592 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="92aac82546082353" memberName="juce__label25"
         virtualName="" explicitFocusOrder="0" pos="352 424 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Quantizer&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="ee38b1703e63e2" memberName="juce__slider20"
          virtualName="" explicitFocusOrder="0" pos="348 456 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="f593c5b446f1230e" memberName="juce__label28"
         virtualName="" explicitFocusOrder="0" pos="348 584 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale Select&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="f479afc89d3037be" memberName="juce__slider21"
          virtualName="" explicitFocusOrder="0" pos="444 456 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="4241a6f4bd45d7a7" memberName="juce__label29"
         virtualName="" explicitFocusOrder="0" pos="444 584 116 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale Transpose&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="pitchShifter2/pitchQuantizer/transp" id="af7966d2b3a27ac8"
          memberName="juce__slider9" virtualName="" explicitFocusOrder="0"
          pos="16 248 72 128" min="0.0" max="10.0" int="0.0" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="delay2/dlyTimeSynced" id="b8ee3950d2d01f27" memberName="juce__slider10"
          virtualName="" explicitFocusOrder="0" pos="96 248 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="shifterFilter2/cutoff" id="db76a9a947d67c71" memberName="juce__slider11"
          virtualName="" explicitFocusOrder="0" pos="176 248 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="5838b25714761eae" memberName="juce__label8"
         virtualName="" explicitFocusOrder="0" pos="174 386 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="LP Freq&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="df49098d2b2ac78" memberName="juce__label9"
         virtualName="" explicitFocusOrder="0" pos="102 386 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a3aaeb067dc8e90d" memberName="juce__label10"
         virtualName="" explicitFocusOrder="0" pos="14 386 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Transpose" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="diffusion2/diffuseTime" id="2e10d5b60f0652a0" memberName="juce__slider12"
          virtualName="" explicitFocusOrder="0" pos="256 248 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="5a1f5e22d662591e" memberName="juce__label11"
         virtualName="" explicitFocusOrder="0" pos="246 386 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Diffuse time" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="diffusion2/diffuseGain" id="fd3b53947fbf1fd8" memberName="juce__slider13"
          virtualName="" explicitFocusOrder="0" pos="336 248 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="e75c5958c1861b58" memberName="juce__label12"
         virtualName="" explicitFocusOrder="0" pos="326 386 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Diffuse gain&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="feedbackMixer/2x1" id="e4d081c6d603dcef" memberName="juce__slider15"
          virtualName="" explicitFocusOrder="0" pos="496 248 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="6541f05a8f80a891" memberName="juce__label15"
         virtualName="" explicitFocusOrder="0" pos="510 394 40 16" edTextCol="ff000000"
         edBkgCol="0" labelText="2x1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="feedbackMixer/dly2PrePost" id="673846ed4d07b9a5" memberName="juce__slider14"
          virtualName="" explicitFocusOrder="0" pos="416 248 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="3f9bcfeb832ff367" memberName="juce__label19"
         virtualName="" explicitFocusOrder="0" pos="414 386 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Shimmer" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="feedbackMixer/2x2" id="d15575ecabd757c1" memberName="juce__slider16"
          virtualName="" explicitFocusOrder="0" pos="576 248 72 128" min="0.0"
          max="10.0" int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="b457ceadd205e22" memberName="juce__label30"
         virtualName="" explicitFocusOrder="0" pos="584 392 56 16" edTextCol="ff000000"
         edBkgCol="0" labelText="2x2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

