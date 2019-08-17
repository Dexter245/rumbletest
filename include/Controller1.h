#ifndef CONTROLLER1_H_
#define CONTROLLER1_H_

#include "Controller.h"
#include "Model1.h"
#include "Application.h"
#include "Vibration.h"
#include "Sixaxis.h"

class Controller1 : public dex::Controller {

private:
    const float MIN_FREQ = 10.0f;
    const float MAX_FREQ = 1000.0f;
    Model1 &model;
    SDL_GameController *gameController;
    dex::Vibration vibration;
    dex::Sixaxis sixaxis;
    dex::Vibration::VibrationData &vibrationData;
    bool vibrationActive = false;

    void handleEvents();

public:
    explicit Controller1(Model1 &model);

    ~Controller1() override;

    void update(float delta) override;

};


#endif