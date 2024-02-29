#include "pid.h"
#include <stdio.h>

// 積分器のプラントをシュミレートする関数
double plant(
    double input, 
    double *integral, 
    double dt
) {
    *integral += input * dt;
    return *integral;
}

int main() {
    // テキストファイルを開く. PIDの出力を書き込みため.
    FILE *fp = fopen("pid_output.csv", "w");
    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    // PID制御器の初期化
    PID pid;
    pid_init(&pid, 0.01, 1.0, 0.0, 0.0, 1.0, -5, 5); 

    double plant_output = 0.0; // プラントの出力初期化
    double integrator_state = 0.0; // 積分器の状態初期化
    double pid_output = 0.0; // PIDの出力初期化

    for (int i = 0; i < 1000; i++ ) {
        pid_output = pid_compute(&pid, plant_output);
        plant_output = plant(pid_output, &integrator_state, pid.control_cycle);

        fprintf(fp, "%d,%f\n", i, plant_output); // テキストファイルに書き込み
    }

    fclose(fp); // テキストファイルを閉じる
    return 0;
}