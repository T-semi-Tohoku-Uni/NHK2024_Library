#include "filter.h"
#include <stdio.h>
#include <math.h>

// ノイズが入ったセンサの値をシュミレートする関数
// 純粋なsin関数をノイズが乗っていないセンサの値として, 高周波のノイズを加えている
double output_sensor_value(void) {
    static double t = 0.0;
    t += 0.01;
    return sin(t) + 0.1 * sin(100.0 * t);
}

int main() {
    FILE *fp = fopen("low_pass_filter_output.csv", "w");
    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    /*
        1. 初期化
        引数1: サンプリング周期（制御周期）
        引数2: カットオフ周波数

        サンプリング周期が0.01, カットオフ周期が0.0001としている
        もうちょいゲインを小さくしたい所存
    */
    Low_Pass_Filter_Settings* settings = low_pass_filter_init(0.01, 1e-03);

    for(int i = 0; i < 1000; i++ ) {
        double sensor_value = output_sensor_value(); // ノイズが入ったセンサの値
        /*
            更新
            引数1: フィルタの設定（上で初期化したやつ）
            引数2: フィルタに入力する値
            出力値: フィルタを通した後の値
        */
        double filterd_value = low_pass_filter_update(settings, sensor_value);

        // テキストファイルに書き込み, グラフを後で表示させるためなので気にしない
        // fprintf(fp, "%d,%f,%f\n", i, sensor_value, filterd_value);
        fprintf(fp, "%d,%f,%f\n", i, sensor_value, filterd_value);
    }
    
    return 0;
}