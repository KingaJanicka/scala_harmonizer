/*
  ==============================================================================

   Copyright 2022 Suzuki Kengo

   JR-Granular is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
 
   JR-Granular is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with JR-Granular. If not, see <http://www.gnu.org/licenses/>.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "juce_audio_processors/juce_audio_processors.h"
#include "juce_core/juce_core.h"
#include "ParamIDs.h"
#include "PluginEditor.h"

static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    // Format the number to always display three digits like "10.0 ms", "100 ms".
    const auto ms = [] (auto value, auto)
    {
        constexpr auto unit = " ms";

        if (auto v { std::round (value * 10.0f) / 10.0f }; v < 100.0f)
            return juce::String { v, 1 } + unit;

        return juce::String { std::round (value) } + unit;
    };


    // Format the number to always display three digits like "0.01 %", "10.0 %", "100 %".
    const auto percentage = [] (auto value, auto)
    {
        constexpr auto unit = " %";

        if (auto v { std::round (value * 100.0f) / 100.0f }; v < 10.0f)
            return juce::String { v, 2 } + unit;

        if (auto v { std::round (value * 10.0f) / 10.0f }; v < 100.0f)
            return juce::String { v, 1 } + unit;

        return juce::String { std::round (value) } + unit;
    };

    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dryVol, 1 },
        "Dry Vol",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f }, //low bound range, high bound range, snapping interval, skew factor
        100.0f, //default value
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage))); //unit

    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly1Vol, 1 },
        "Delay 1 Vol",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly2Vol, 1 },
        "Delay 2 Vol",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f, 
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly1DiffusionTime, 1 },
        "Diff Time",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly1DiffusionGain, 1 },
        "Diff Gain",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly1ShifterFilterCutoff, 1 },
        "LP",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly1Transpose, 1 },
        "Transp.",
        juce::NormalisableRange { -24.0f, 24.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
        

    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::scaleTranspose, 1 },
        "Scale Root",
        juce::NormalisableRange { 0.0f, 11.0f, 1.0f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
    
    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::scaleSelect, 1 },
        "Scale",
        juce::NormalisableRange { 1.0f, 2.0f, 1.0f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
        
    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly1Time, 1 },
        "Time",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
    
    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::feedback1x1, 1 },
        "1x1",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
        
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::feedback1x2, 1 },
        "1x2",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
        
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::feedback2x1, 1 },
        "2x1",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
        
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::feedback2x2, 1 },
        "2x2",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
        
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly1PrePost, 1 },
        "Shimmer",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly2PrePost, 1 },
        "Shimmer",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
        

    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly2DiffusionTime, 1 },
        "Diff Time",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly2DiffusionGain, 1 },
        "Diff Gain",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly2ShifterFilterCutoff, 1 },
        "LP",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));

    
    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly2Transpose, 1 },
        "Transp.",
        juce::NormalisableRange { -24.0f, 24.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
        

    layout.add (std::make_unique<juce::AudioParameterFloat> (
        juce::ParameterID { param_ids::dly2Time, 1 },
        "Time",
        juce::NormalisableRange { 0.0f, 1.0f, 0.01f, 1.0f },
        100.0f,
        juce::AudioParameterFloatAttributes().withStringFromValueFunction (percentage)));
    
    
        
    return layout;
}

PluginProcessor::PluginProcessor()
    : AudioProcessor (BusesProperties()
                          .withInput ("Input", juce::AudioChannelSet::stereo(), true)
                          .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
    , apvts (*this, &undoManager, "Parameters", createParameterLayout())
{
    for (RNBO::ParameterIndex i = 0; i < rnboObject.getNumParameters(); ++i)
    {
        RNBO::ParameterInfo info;
        rnboObject.getParameterInfo (i, &info);

        if (info.visible)
        {
            auto paramID = juce::String (rnboObject.getParameterId (i));

            // Each apvts parameter id and range must be the same as the rnbo param object's.
            // If you hit this assertion then you need to fix the incorrect id in param_ids.h.
            jassert (apvts.getParameter (paramID) != nullptr);

            // If you hit these assertions then you need to fix the incorrect apvts
            // parameter range in createParameterLayout().
            jassert (juce::approximatelyEqual (static_cast<float> (info.min), apvts.getParameterRange (paramID).start));
            jassert (juce::approximatelyEqual (static_cast<float> (info.max), apvts.getParameterRange (paramID).end));

            apvtsParamIdToRnboParamIndex[paramID] = i;

            apvts.addParameterListener (paramID, this);
            rnboObject.setParameterValue (i, apvts.getRawParameterValue (paramID)->load());
        }
    }
}

const juce::String PluginProcessor::getName() const { return JucePlugin_Name; }

bool PluginProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool PluginProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool PluginProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double PluginProcessor::getTailLengthSeconds() const { return 0.0; }

int PluginProcessor::getNumPrograms()
{
    return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
        // so this should be at least 1, even if you're not really implementing programs.
}

int PluginProcessor::getCurrentProgram() { return 0; }

void PluginProcessor::setCurrentProgram (int index) { juce::ignoreUnused (index); }

const juce::String PluginProcessor::getProgramName (int index)
{
    juce::ignoreUnused (index);
    return {};
}

void PluginProcessor::changeProgramName (int index, const juce::String& newName)
{
    juce::ignoreUnused (index, newName);
}

void PluginProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    rnboObject.prepareToProcess (sampleRate, static_cast<size_t> (samplesPerBlock));
}

void PluginProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool PluginProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainInputChannelSet() == juce::AudioChannelSet::disabled()
        || layouts.getMainOutputChannelSet() == juce::AudioChannelSet::disabled())
        return false;

    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    return layouts.getMainInputChannelSet() == layouts.getMainOutputChannelSet();
}

void PluginProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused (midiMessages);
    rnboObject.process (buffer.getArrayOfWritePointers(),
                        static_cast<RNBO::Index> (buffer.getNumChannels()),
                        buffer.getArrayOfWritePointers(),
                        static_cast<RNBO::Index> (buffer.getNumChannels()),
                        static_cast<RNBO::Index> (buffer.getNumSamples()));
}

bool PluginProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* PluginProcessor::createEditor()
{
    return new PluginEditor (*this, apvts, undoManager); // NOLINT
}

void PluginProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    juce::MemoryOutputStream mos (destData, true);
    apvts.state.writeToStream (mos);
}

void PluginProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    if (const auto tree = juce::ValueTree::readFromData (data, static_cast<size_t> (sizeInBytes)); tree.isValid())
        apvts.replaceState (tree);
}

void PluginProcessor::parameterChanged (const juce::String& parameterID, float newValue)
{
    rnboObject.setParameterValue (apvtsParamIdToRnboParamIndex[parameterID], newValue);
}

// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor(); // NOLINT
}
