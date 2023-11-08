#ifndef __PID_H__
#define __PID_H__

typedef struct PID {
    double control_cycle; // 制御周期
    double kp, kd, ki; // PID parameters
    double setpoint; // 目標値
    double integral; // 積分値
    double last_error; // 前回の偏差
} PID;

/*
    * PID制御器の初期化
    * 
    * PID型を宣言した後は必ず行う.
    * 
    * @param pid PID制御器
    * @param control_cycle 制御周期
    * @param kp, kd, ki PIDパラメータ
    * @param setpoint 目標値
    * 
    * @return void
*/
void pid_init(
    PID *pid,
    double control_cycle,
    double kp, float kd, float ki,
    double setpoint
);

/*
    * PID制御器の計算
    * 
    * @param pid PID制御器
    * @param input 入力値
    * 
    * @return double 出力値
*/
double pid_compute(
    PID *pid,
    double input
);

#endif // __PID_H__