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

#pragma once

#include "Dial.h"
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>

class EditorContent final : public juce::Component
{
public:
    EditorContent (juce::AudioProcessorValueTreeState& apvts, juce::UndoManager& um);

    void resized() override;
    bool keyPressed (const juce::KeyPress& k) override;

private:
    Dial dryVolDial;
    Dial dly1VolDial;
    Dial dly2VolDial;
    Dial dly1DiffusionTimeDial;
    Dial dly1DiffusionGainDial;
    Dial dly1FilterDial;
    Dial dly1TransposeDial;
    Dial scaleTransposeDial;
    Dial scaleSelectDial;
    Dial dly1TimeDial;
    Dial feedback1x1Dial;
    Dial feedback1x2Dial;
    Dial feedback2x1Dial;
    Dial feedback2x2Dial;
    Dial dly1PrePostDial;
    Dial dly2PrePostDial;
    Dial dly2DiffusionTimeDial;
    Dial dly2DiffusionGainDial;
    Dial dly2FilterDial;
    Dial dly2TransposeDial;
    Dial dly2TimeDial;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EditorContent)
};
