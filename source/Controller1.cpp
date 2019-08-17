#include "Controller1.h"
#include <iostream>
#include <Application.h>
#include <Controller1.h>


Controller1::Controller1(Model1 &model) :
        model(model),
        vibrationData(model.getVibrationData())
{
    gameController = SDL_GameControllerOpen(0);
}

Controller1::~Controller1() {
    SDL_GameControllerClose(gameController);
}

void Controller1::update(float delta) {

//    std::cout << "controller1 update" << std::endl;

    SDL_GameControllerUpdate();
    handleEvents();

    float x1 = SDL_GameControllerGetAxis(gameController, SDL_CONTROLLER_AXIS_LEFTX);
    float y1 = SDL_GameControllerGetAxis(gameController, SDL_CONTROLLER_AXIS_LEFTY);
    float x2 = SDL_GameControllerGetAxis(gameController, SDL_CONTROLLER_AXIS_RIGHTX);
    float y2 = SDL_GameControllerGetAxis(gameController, SDL_CONTROLLER_AXIS_RIGHTY);

    //clamp from [-32768; 32768] to [0; 1]
    float axisMax = 32768;
    x1 = ((x1+axisMax) / (2*axisMax));
    y1 = ((y1+axisMax) / (2*axisMax));
    x2 = ((x2+axisMax) / (2*axisMax));
    y2 = ((y2+axisMax) / (2*axisMax));

    float freqDiff = MAX_FREQ - MIN_FREQ;
    vibrationData.freqLow = MIN_FREQ + freqDiff * x1;
    vibrationData.ampLow = 1.0f - y1;
    vibrationData.freqHigh = MIN_FREQ + freqDiff * x2;
    vibrationData.ampHigh = 1.0f - y2;

//    std::cout << "x1: " << x1 << ", y1: " << y1 << ", x2: " << x2 << ", y2: " << y2 << ", ";
//    std::cout << "freqLow: " << vibrationData.freqLow << ", ampLow: " << vibrationData.ampLow <<
//        ", freqHigh: " << vibrationData.freqHigh << ", ampHigh: " << vibrationData.ampHigh << std::endl;

    if(vibrationActive){
        vibration.setVibration(vibrationData);
    }else{
        vibration.stopVibration();
    }

}

void Controller1::handleEvents() {

    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_KEYDOWN){
            std::cout << "keydown" << std::endl;
            if(e.key.keysym.sym == SDLK_ESCAPE){
                std::cout << "escape pressed" << std::endl;
                dex::Application::instance().end();
            }
        }else if(e.type == SDL_CONTROLLERBUTTONDOWN) {
            if (e.jbutton.button == SDL_CONTROLLER_BUTTON_START) {
                std::cout << "buttondown" << std::endl;
                dex::Application::instance().end();
            }
            else if (e.jbutton.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
                vibrationActive = true;
                std::cout << "vibration activated" << std::endl;
            }
        }else if(e.type == SDL_CONTROLLERBUTTONUP){
            if (e.jbutton.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
                vibrationActive = false;
                std::cout << "vibration deactivated" << std::endl;
            }
        }
    }

}


