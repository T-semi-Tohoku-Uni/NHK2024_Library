//
// Created by YYcri on 2024/03/08.
//

#include "mecanum_kinematics.h"
//y+: forward, x+: right, omega: counter clockwise

// mecanum wheel robot inverseKinematics
// input: robotParams and velocity of robot {vx, vy, omega}
// output: wheel angle velocity {w1, w2, w3, w4}
void inverseKinematics(struct robotParams *params, double *velocity, double *wheelAngleVelocity) {
    double vx = velocity[0];
    double vy = velocity[1];
    double omega = velocity[2];
    double wheelDiameter = params->wheelDiameter;
    double treadLen = params->treadLen;
    double wheelBaseLen = params->wheelBaseLen;
    double wheelParam = (treadLen + wheelBaseLen) / 2;

    //convert matrix
    double wheelMatrix[4][3] = {
        {-1,  1, wheelParam},
        {-1, -1, wheelParam},
        { 1, -1, wheelParam},
        { 1,  1, wheelParam}
    };

    //calculate wheel angle velocity
    for (int i = 0; i < 4; i++) {
        wheelAngleVelocity[i] = wheelMatrix[i][0] * vx + wheelMatrix[i][1] * vy + wheelMatrix[i][2] * omega;
        wheelAngleVelocity[i] = wheelAngleVelocity[i] / wheelDiameter;
    }
}

// mecanum wheel robot forwardKinematics
// input: robotParams and wheel angle velocity {w1, w2, w3, w4}
// output: velocity of robot {vx, vy, omega}
void forwardKinematics(struct robotParams *params, double *wheelAngleVelocity, double *velocity) {
    double wheelDiameter = params->wheelDiameter;
    double treadLen = params->treadLen;
    double wheelBaseLen = params->wheelBaseLen;
    double wheelParam = (treadLen + wheelBaseLen) / 2;

    //convert matrix
    const float wheelMatrix[3][4] = {
    {-1, -1, 1, 1},
    {1, -1, -1, 1},
    {1/wheelParam, 1/wheelParam, 1/wheelParam, 1/wheelParam}
    };

    //calculate velocity
    for (int i = 0; i < 3; i++) {
        velocity[i] = wheelMatrix[i][0] * wheelAngleVelocity[0] + wheelMatrix[i][1] * wheelAngleVelocity[1] + wheelMatrix[i][2] * wheelAngleVelocity[2] + wheelMatrix[i][3] * wheelAngleVelocity[3];
        velocity[i] = velocity[i] * wheelDiameter / 4;
    }
}

// Initialize robotParams
void initRobotParams(struct robotParams *params, double wheelDiameter, double treadLen, double wheelBaseLen) {
    params->wheelDiameter = wheelDiameter;
    params->treadLen = treadLen;
    params->wheelBaseLen = wheelBaseLen;
}
