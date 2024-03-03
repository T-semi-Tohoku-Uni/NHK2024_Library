#include "i_pd.h"
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
    // テキストファイルを開く. I-PDの出力を書き込みため.
    FILE *fp = fopen("i_pd_output.csv", "w");
    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    // I-PD制御器の初期化
    I_PD i_pd;
    i_pd_init(&i_pd, 0.01, 10.0, 0, 1.0, 1.0, -5, 5); 

    double plant_output = 0.0; // プラントの出力初期化
    double integrator_state = 0.0; // 積分器の状態初期化
    double i_pd_output = 0.0; // I-PDの出力初期化

    for (int i = 0; i < 100; i++ ) {
        i_pd_output = i_pd_compute(&i_pd, plant_output);
        plant_output = plant(i_pd_output, &integrator_state, i_pd.control_cycle);

        fprintf(fp, "%d,%f\n", i, plant_output); // テキストファイルに書き込み
    }

    fclose(fp); // テキストファイルを閉じる
    return 0;
}