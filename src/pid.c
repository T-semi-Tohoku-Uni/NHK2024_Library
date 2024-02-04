#include "pid.h"
#include <stdio.h>

int main() {
    PID pid;
    pid_init(&pid, 0.01, 1.0, 0.1, 0.1, 0.0);
    printf("pid_compute(10.0) = %f\n", pid_compute(&pid, 10.0));
}

void pid_init(
    PID *pid,
    double control_cycle,
    double kp, float kd, float ki,
    double setpoint
) {
    pid -> control_cycle = control_cycle;
    pid -> kp = kp;
    pid -> kd = kd;
    pid -> ki = ki;
    pid -> setpoint = setpoint;
}

double pid_compute(
    PID *pid,
    double input
) {
    double error = pid -> setpoint - input;
    pid -> integral += error * pid -> control_cycle;
    double derivative = (error - pid->last_error) / pid -> control_cycle;

    // PID出力の計算
    double output = (pid -> kp * error) + (pid -> ki * pid -> integral) + (pid -> kd * derivative);

    // 更新
    pid -> last_error = error;

    return output;
}