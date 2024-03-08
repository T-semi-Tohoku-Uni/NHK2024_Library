//
// Created by Yoshi on 2024/03/08.
//

//example code for mechanum_kinematics
#include "mechanum_kinematics.h"
//y+: forward, x+: right, omega: counter clockwise
//declare robotParams
struct robotParams params;

int main() {
    //initialize robotParams
    initRobotParams(&params, 100, 200, 300);
    double velocity[3] = {1, 1, 1};
    double wheelAngleVelocity[4];
    inverseKinematics(&params, velocity, wheelAngleVelocity);
    double velocity2[3];
    forwardKinematics(&params, wheelAngleVelocity, velocity2);
    return 0;
}
