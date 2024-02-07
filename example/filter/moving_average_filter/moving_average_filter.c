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

/*
    *移動平均フィルタの使い方
    *1. 初期化 moving_average_filter_init
    *2. 更新   moving_average_filter_update
*/
int main() {
    FILE *fp = fopen("moving_average_filter_output.csv", "w");
    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        return 1;
    }

    //1. 初期化
    //  引数1: 初期値
    //  引数2: バッファサイズ
    //  この例では, 初期値を0.0, バッファサイズを10としている
    NHK2024_Filter_Buffer* buf = moving_average_filter_init(0.0, 10);

    for(int i = 0; i < 1000; i++ ){
        double sensor_value = output_sensor_value(); // ノイズが入ったセンサの値
        //2. 更新
        //  引数1: フィルタのバッファ
        //  引数2: フィルタに入力する値
        //  この例では, フィルタのバッファをbuf, フィルタに入力する値をoutput_sensor_value()としている
        double filterd_value = moving_average_filter_update(buf, sensor_value);

        // テキストファイルに書き込み, グラフを後で表示させるためなので気にしない
        fprintf(fp, "%d,%f,%f\n", i, sensor_value, filterd_value); 
    }

    return 0;
}