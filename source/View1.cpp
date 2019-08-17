#include "View1.h"
#include <iostream>
#include <string>
#include <sstream>


View1::View1(Model1 &model) :
    model(model),
    background("background.png"),
    font("DroidSansMono.ttf", 32),
    vibrationData(model.getVibrationData())
{

}

void View1::render() {
    background.draw(0, 0);

    std::string text;

    text = "First Motor";
    font.renderText(text, 50, 50);

    text = "Frequency: " + std::to_string(vibrationData.freqLow);
    font.renderText(text, 50, 120);
    text = "Amplitude: " + std::to_string(vibrationData.ampLow);
    font.renderText(text, 50, 170);

    text = "Second Motor";
    font.renderText(text, 800, 50);

    text = "Frequency: " + std::to_string(vibrationData.freqHigh);
    font.renderText(text, 800, 120);
    text = "Amplitude: " + std::to_string(vibrationData.ampHigh);
    font.renderText(text, 800, 170);

    text = "Hold R to activate Vibration.";
    font.renderText(text, 50, 400);
    text = "Use the analog sticks to change the values.";
    font.renderText(text, 50, 450);
    text = "X-axis is frequency, Y-Axis is amplitude.";
    font.renderText(text, 50, 500);
}
