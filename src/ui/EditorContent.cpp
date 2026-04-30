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

#include "EditorContent.h"
#include "../ParamIDs.h"

EditorContent::EditorContent (juce::AudioProcessorValueTreeState& apvts, juce::UndoManager& um)
    : dryVolDial (*apvts.getParameter (param_ids::dryVol), &um)
    , dly1VolDial (*apvts.getParameter (param_ids::dly1Vol), &um)
    , dly2VolDial (*apvts.getParameter (param_ids::dly2Vol), &um)
    , dly1DiffusionTimeDial (*apvts.getParameter (param_ids::dly1DiffusionTime), &um)
    , dly1DiffusionGainDial (*apvts.getParameter (param_ids::dly1DiffusionGain), &um)
    , dly1FilterDial (*apvts.getParameter (param_ids::dly1ShifterFilterCutoff), &um)
    , dly1TransposeDial (*apvts.getParameter (param_ids::dly1Transpose), &um)
    , scaleTransposeDial (*apvts.getParameter (param_ids::scaleTranspose), &um)
    , scaleSelectDial (*apvts.getParameter (param_ids::scaleSelect), &um)
    , dly1TimeDial (*apvts.getParameter (param_ids::dly1Time), &um)
    , feedback1x1Dial (*apvts.getParameter (param_ids::feedback1x1), &um)
    , feedback1x2Dial (*apvts.getParameter (param_ids::feedback1x2), &um)
    , feedback2x1Dial (*apvts.getParameter (param_ids::feedback2x1), &um)
    , feedback2x2Dial (*apvts.getParameter (param_ids::feedback2x2), &um)
    , dly1PrePostDial (*apvts.getParameter (param_ids::dly1PrePost), &um)
    , dly2PrePostDial (*apvts.getParameter (param_ids::dly2PrePost), &um)
    , dly2DiffusionTimeDial (*apvts.getParameter (param_ids::dly2DiffusionTime), &um)
    , dly2DiffusionGainDial (*apvts.getParameter (param_ids::dly2DiffusionGain), &um)
    , dly2FilterDial (*apvts.getParameter (param_ids::dly2ShifterFilterCutoff), &um)
    , dly2TransposeDial (*apvts.getParameter (param_ids::dly2Transpose), &um)
    , dly2TimeDial (*apvts.getParameter (param_ids::dly2Time), &um)
    
{
    setWantsKeyboardFocus (true);
    setFocusContainerType (FocusContainerType::keyboardFocusContainer);

    // Set interval of values changed by arrow keys or shift + arrow keys.

    addAndMakeVisible (dryVolDial);
    addAndMakeVisible (dly1VolDial);
    addAndMakeVisible (dly2VolDial);
    addAndMakeVisible (dly1DiffusionTimeDial);
    addAndMakeVisible (dly1DiffusionGainDial);
    addAndMakeVisible (dly1FilterDial);
    addAndMakeVisible (dly1TransposeDial);
    addAndMakeVisible (scaleTransposeDial);
    addAndMakeVisible (scaleSelectDial);
    addAndMakeVisible (dly1TimeDial);
    addAndMakeVisible (feedback1x1Dial);
    addAndMakeVisible (feedback1x2Dial);
    addAndMakeVisible (feedback2x1Dial);
    addAndMakeVisible (feedback2x2Dial);
    addAndMakeVisible (dly1PrePostDial);
    addAndMakeVisible (dly2PrePostDial);
    addAndMakeVisible (dly2DiffusionTimeDial);
    addAndMakeVisible (dly2DiffusionGainDial);
    addAndMakeVisible (dly2FilterDial);
    addAndMakeVisible (dly2TransposeDial);
    addAndMakeVisible (dly2TimeDial);
}

void EditorContent::resized()
{
    const auto topDialBounds = juce::Rectangle { 0, 30, 80, 95 };
    dly1TransposeDial.setBounds (topDialBounds.withX (30));
    dly1TimeDial.setBounds (topDialBounds.withX (130));
    dly1FilterDial.setBounds (topDialBounds.withX (230));
    dly1DiffusionTimeDial.setBounds (topDialBounds.withX (330));
    dly1DiffusionGainDial.setBounds (topDialBounds.withX (430));
    dly1PrePostDial.setBounds (topDialBounds.withX (530));
    feedback1x1Dial.setBounds (topDialBounds.withX (630));
    feedback1x2Dial.setBounds (topDialBounds.withX (730));
    

    const auto middleDialBounds = topDialBounds.withY (155);
    dly2TransposeDial.setBounds (middleDialBounds.withX (30));
    dly2TimeDial.setBounds (middleDialBounds.withX (130));
    dly2FilterDial.setBounds (middleDialBounds.withX (230));
    dly2DiffusionTimeDial.setBounds (middleDialBounds.withX (330));
    dly2DiffusionGainDial.setBounds (middleDialBounds.withX (430));
    dly2PrePostDial.setBounds (middleDialBounds.withX (530));
    feedback2x1Dial.setBounds (middleDialBounds.withX (630));
    feedback2x2Dial.setBounds (middleDialBounds.withX (730));

    const auto bottomDialBounds = topDialBounds.withY (310);

    dryVolDial.setBounds (bottomDialBounds.withX (30));
    dly1VolDial.setBounds (bottomDialBounds.withX (130));
    dly2VolDial.setBounds (bottomDialBounds.withX (230));

    scaleSelectDial.setBounds (bottomDialBounds.withX (430));
    scaleTransposeDial.setBounds (bottomDialBounds.withX (530));

}

bool EditorContent::keyPressed (const juce::KeyPress& k)
{
    if (k.isKeyCode (juce::KeyPress::tabKey) && hasKeyboardFocus (false))
    {
        dryVolDial.grabKeyboardFocus();
        return true;
    }

    return false;
}
