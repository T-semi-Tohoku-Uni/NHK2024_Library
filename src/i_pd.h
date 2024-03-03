#ifndef __I_PD_H__
#define __I_PD_H__

typedef struct I_PD {
    double control_cycle; // 制御周期
    double kp, kd, ki; // I-PD parameters
    double setpoint; // 目標値
    double integral; // 積分値
    double integral_max; // 積分値の最大値
    double integral_min; // 積分値の最小値
    double last_input; // 前回のプラントの出力
}I_PD;

/*
    * I-PD制御器の初期化
    * 
    * I-PD型を宣言した後は必ず行う.
    * 
    * @param i_pd I-PD制御器
    * @param control_cycle 制御周期
    * @param kp, kd, ki I-PDパラメータ
    * @param setpoint 目標値
    * @param integral_max 積分値の最大値
    * @param integral_min 積分値の最小値
    * 
    * @return void
*/

void i_pd_init(
    I_PD *i_pd,
    double control_cycle,
    double kp, double kd, double ki,
    double setpoint,
    double integral_min, double integral_max
);

/*
    * I-PD制御器の計算
    * 
    * @param i_pd I-PD制御器
    * @param input 入力値
    * 
    * @return double 出力値
*/
double i_pd_compute(
    I_PD *i_pd,
    double input
);

#endif // __I_PD_H__