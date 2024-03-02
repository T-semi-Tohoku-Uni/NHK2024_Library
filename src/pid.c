#include "pid.h"
#include <stdio.h>

void pid_init(
    PID *pid,
    double control_cycle,
    double kp, float kd, float ki,
    double setpoint,
    double integral_min, double integral_max
) {
    pid -> control_cycle = control_cycle;
    pid -> kp = kp;
    pid -> kd = kd;
    pid -> ki = ki;
    pid -> setpoint = setpoint;
    pid -> integral_max = integral_max;
    pid -> integral_min = integral_min;
    pid -> integral = 0;
    pid -> last_error = 0;
}

double pid_compute(
    PID *pid,
    double input
) {
    double error = pid -> setpoint - input;
    pid -> integral += error * pid -> control_cycle;

    // アンチワインドアップ
    if (pid -> integral > pid -> integral_max) {
        pid -> integral = pid -> integral_max;
    } else if (pid -> integral < pid -> integral_min) {
        pid -> integral = pid -> integral_min;
    }

    double derivative = (error - pid->last_error) / pid -> control_cycle;

    // PID出力の計算
    double output = (pid -> kp * error) + (pid -> ki * pid -> integral) + (pid -> kd * derivative);

    // 更新
    pid -> last_error = error;

    return output;
}