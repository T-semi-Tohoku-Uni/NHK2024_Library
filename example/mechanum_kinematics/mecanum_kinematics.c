//
// Created by Yoshi on 2024/03/08.
//

//example code for mecanum_kinematics
#include "mecanum_kinematics.h"
#include <stdio.h>
//y+: forward, x+: right, omega: counter clockwise
//declare robotParams
struct robotParams params;

int main() {
    //initialize robotParams
    initRobotParams(&params, 100, 200, 300);
    double velocity[3] = {1, 1, 1};
    double wheelAngleVelocity[4];
    inverseKinematics(&params, velocity, wheelAngleVelocity);
    printf("wheelAngleVelocity: %f, %f, %f, %f\n", wheelAngleVelocity[0], wheelAngleVelocity[1], wheelAngleVelocity[2], wheelAngleVelocity[3]);
    double velocity2[3];
    forwardKinematics(&params, wheelAngleVelocity, velocity2);
    printf("velocity: %f, %f, %f\n", velocity2[0], velocity2[1], velocity2[2]);
    return 0;
}
