#include "View1.h"
#include <iostream>


View1::View1(Model1 &model) :
    model(model),
    background("background.png"),
    font("DroidSansMono.ttf", 18),
    vibrationData(model.getVibrationData())
{
//    vibrationData = model.getVibrationData();
    std::cout << "model: " << &model << std::endl;
    std::cout << "vibraitonData: " << &vibrationData << std::endl;
}

void View1::render() {
    background.draw(0, 0);

    std::string text = "Frequency low: " + std::to_string(vibrationData.freqLow);
    font.renderText(text, 50, 50);
    text = "Amplitude low: " + std::to_string(vibrationData.ampLow);
    font.renderText(text, 50, 75);
    text = "Frequency high: " + std::to_string(vibrationData.freqHigh);
    font.renderText(text, 50, 100);
    text = "Amplitude high: " + std::to_string(vibrationData.ampHigh);
    font.renderText(text, 50, 125);
}
