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

namespace param_ids
{

// Be the same value as the "paramId" listed in the rnbo description.json.
inline constexpr auto dryVol { "dryVol" };
inline constexpr auto dly1Vol { "dly1Vol" };
inline constexpr auto dly2Vol { "dly2Vol" };
inline constexpr auto dly1DiffusionTime { "diffusion1/diffuseTime" };
inline constexpr auto dly1DiffusionGain { "diffusion1/diffuseGain" };
inline constexpr auto dly1ShifterFilterCutoff { "shifterFilter1/cutoff" };
inline constexpr auto dly1Transpose { "pitchShifter1/pitchQuantizer/transp" };
inline constexpr auto scaleTranspose { "scaleTransposeSt" };
inline constexpr auto scaleSelect { "scaleSelect" };
inline constexpr auto dly1Time { "delay1/dlyTimeSynced" };
inline constexpr auto feedback1x1 { "feedbackMixer/1x1" };
inline constexpr auto feedback1x2 { "feedbackMixer/1x2" };
inline constexpr auto feedback2x1 { "feedbackMixer/2x1" };
inline constexpr auto feedback2x2 { "feedbackMixer/2x2" };
inline constexpr auto dly1PrePost { "feedbackMixer/dly1PrePost" };
inline constexpr auto dly2PrePost { "feedbackMixer/dly2PrePost" };
inline constexpr auto dly2DiffusionTime { "diffusion2/diffuseTime" };
inline constexpr auto dly2DiffusionGain { "diffusion2/diffuseGain" };
inline constexpr auto dly2ShifterFilterCutoff { "shifterFilter2/cutoff" };
inline constexpr auto dly2Transpose { "pitchShifter2/pitchQuantizer/transp" };
inline constexpr auto dly2Time { "delay2/dlyTimeSynced" };

} // namespace ParamIDs
