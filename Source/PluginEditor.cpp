/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TriTapDelayAudioProcessorEditor::TriTapDelayAudioProcessorEditor (TriTapDelayAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    //gain sliders
    mInputGainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    mInputGainSlider.setRange(-60.0f, 12.0f, 0.01f);
    mInputGainSlider.setValue(0.0f);
    mInputGainSlider.addListener(this);
    addAndMakeVisible(mInputGainSlider);
    
    mDryGainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    mDryGainSlider.setRange(-60.0f, 12.0f, 0.01f);
    mDryGainSlider.setValue(-12.0f);
    mDryGainSlider.addListener(this);
    addAndMakeVisible(mDryGainSlider);
    
    mWetGainSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    mWetGainSlider.setRange(-60.0f, 12.0f, 0.01f);
    mWetGainSlider.setValue(0.0f);
    addAndMakeVisible(mWetGainSlider);
    
    mHighPassFilterCutOffSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    mHighPassFilterCutOffSlider.setRange(20.0f, 250.0f, 1.0f);
    mHighPassFilterCutOffSlider.setValue(20.0f);
    mHighPassFilterCutOffSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 1, 1);
    mHighPassFilterCutOffSlider.addListener(this);
    addAndMakeVisible(mHighPassFilterCutOffSlider);
    
    setSize (800, 300);
}

TriTapDelayAudioProcessorEditor::~TriTapDelayAudioProcessorEditor()
{
}

//==============================================================================
void TriTapDelayAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.drawText("Input Level", getWidth() / 12 - 50, getHeight()/4 - 25, 100, 13, juce::Justification::centredTop);
    g.drawText("HighPass", getWidth() / 12 + 40, getHeight()/4 - 25, 100, 13, juce::Justification::centredTop);

}

void TriTapDelayAudioProcessorEditor::resized()
{
    //gain slider positions
    mInputGainSlider.setBounds(getWidth() / 12-20, getHeight()/4, 50, 150);
    mDryGainSlider.setBounds(getWidth() / 12 * 10, getHeight()/4, 50, 150);
    mWetGainSlider.setBounds(getWidth() / 12* 11, getHeight()/4, 50, 150);
    
    //filter dial positions
    mHighPassFilterCutOffSlider.setBounds(getWidth() / 4 - 90, getHeight() / 6 + 25, 75, 75);

}

void TriTapDelayAudioProcessorEditor::sliderValueChanged(juce::Slider * slider){
    if(slider == & mInputGainSlider)
        audioProcessor.mInputGain = mInputGainSlider.getValue();
    if(slider == & mDryGainSlider)
        audioProcessor.mDryGain = mDryGainSlider.getValue();
    if(slider ==& mHighPassFilterCutOffSlider)
        audioProcessor.mHighPassFilterCutOff = mHighPassFilterCutOffSlider.getValue();
}
