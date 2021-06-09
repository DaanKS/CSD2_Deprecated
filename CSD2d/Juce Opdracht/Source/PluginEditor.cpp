/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(slider_1);
        slider_1.setSliderStyle(juce::Slider::SliderStyle::Rotary);
        slider_1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 10);
    slider_1.setLookAndFeel(&otherLookAndFeel);
        slider_1.setRange(1,30);
        slider_1.setValue(audioProcessor.waveshaper->getDrive());
        slider_1.onValueChange = [this]{
            audioProcessor.waveshaper->setDrive(slider_1.getValue());
    };
    addAndMakeVisible(button_1);
        button_1.setClickingTogglesState(true);
        button_1.onClick = [&]() {
            const auto message = button_1.getToggleState() ? "Tanh " : " Sine ";
            int type = button_1.getToggleState() ? 1 : 0 ;
            button_1.setButtonText (message);
                if(type == 1){
                    audioProcessor.waveshaper = new Tanh;
                    slider_1.setValue(audioProcessor.waveshaper->getDrive());
                    slider_2.setValue(audioProcessor.waveshaper->getPostGain());
                } else {
                    audioProcessor.waveshaper = new Sinus;
                    slider_1.setValue(audioProcessor.waveshaper->getDrive());
                    slider_2.setValue(audioProcessor.waveshaper->getPostGain());
                }
            
    };
    addAndMakeVisible(slider_2);
    slider_2.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    slider_2.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 10);
    slider_2.setLookAndFeel(&otherLookAndFeel);
    slider_2.setRange(0, 1);
    slider_2.setValue(audioProcessor.waveshaper->getPostGain());
    slider_2.onValueChange = [this]{
        audioProcessor.waveshaper->setPostGain(slider_2.getValue());
    };
        
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (320, 730);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::hotpink);

    g.setColour (juce::Colours::cyan);
    g.setFont (30.0f);
    g.drawFittedText ("please shape me", getLocalBounds().translated(0, -70), juce::Justification::centred, 1);
}

void NewProjectAudioProcessorEditor::resized()
{
    slider_1.setBounds(20, getHeight() / 2 - 45, 150, 110);
    slider_2.setBounds(150, getHeight() / 2 - 45, 150, 110);
    button_1.setBounds(getWidth() / 2 - 50, getHeight() / 2 + 70, 100, 50);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
