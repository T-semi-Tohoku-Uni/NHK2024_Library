//
// Created by Yoshi on 2024/03/08.
//

#ifndef NHK2024_LIBRARY_MECHANUM_KINEMATICS_H
#define NHK2024_LIBRARY_MECHANUM_KINEMATICS_H
//robot wheel parameters with struct
typedef struct robotParams{
    double wheelDiameter;
    double treadLen;
    double wheelBaseLen;
    double gearRatio;
}robotParams;

// mechanum wheel robot inverseKinematics
// input: robotParams and velocity of robot {vx, vy, omega}
// output: wheel angle velocity {w1, w2, w3, w4}
void inverseKinematics(struct robotParams *params, double *velocity, double *wheelAngleVelocity);

// mechanum wheel robot forwardKinematics
// input: robotParams and wheel angle velocity {w1, w2, w3, w4}
// output: velocity of robot {vx, vy, omega}
void forwardKinematics(struct robotParams *params, double *wheelAngleVelocity, double *velocity);

// Initialize robotParams
void initRobotParams(struct robotParams *params, double wheelDiameter, double treadLen, double wheelBaseLen);

#endif //NHK2024_LIBRARY_MECHANUM_KINEMATICS_H
