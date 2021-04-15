/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TriTapDelayAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                        public juce::Slider::Listener
{
public:
    TriTapDelayAudioProcessorEditor (TriTapDelayAudioProcessor&);
    ~TriTapDelayAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider * slider) override;

private:
    //gain sliders
    juce::Slider mInputGainSlider;
    juce::Slider mDryGainSlider;
    juce::Slider mWetGainSlider;
    
    //filter cutoff dials
    juce::Slider mHighPassFilterCutOffSlider;
    juce::Slider mLowPassFilterCutOffSlider;
    
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TriTapDelayAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TriTapDelayAudioProcessorEditor)
};
