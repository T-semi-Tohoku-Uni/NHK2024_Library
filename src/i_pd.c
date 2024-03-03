#include "i_pd.h"
#include <stdio.h>

void i_pd_init(
    I_PD *i_pd,
    double control_cycle,
    double kp, double kd, double ki,
    double setpoint,
    double integral_min, double integral_max
) {
    i_pd -> control_cycle = control_cycle;
    i_pd -> kp = kp;
    i_pd -> kd = kd;
    i_pd -> ki = ki;
    i_pd -> setpoint = setpoint;
    i_pd -> integral_max = integral_max;
    i_pd -> integral_min = integral_min;
    i_pd -> integral = 0;
    i_pd -> last_input = 0;
}

double i_pd_compute(
    I_PD *i_pd,
    double input
) {
    double error = i_pd -> setpoint - input;
    i_pd -> integral += error * i_pd -> control_cycle;

    // アンチワインドアップ
    if (i_pd->integral > i_pd->integral_max) {
        i_pd -> integral = i_pd -> integral_max;
    } else if (i_pd->integral < i_pd->integral_min) {
        i_pd->integral = i_pd->integral_min;
    }

    double derivative = (input - i_pd->last_input) / i_pd->control_cycle;

    // I-PD出力の計算
    double output = (i_pd->kp * error) + (i_pd->ki * i_pd->integral) + (i_pd->kd * derivative);

    // 更新
    i_pd->last_input = input;

    return output;
}