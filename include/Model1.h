#ifndef MODEL1_H_
#define MODEL1_H_

#include "Vibration.h"

class Model1 {

private:
    dex::Vibration::VibrationData vibrationData;

public:
    Model1();
    ~Model1();

    dex::Vibration::VibrationData &getVibrationData() { return vibrationData; };

//    void setVibrationData(const dex::Vibration::VibrationData &vibrationData);


};

#endif