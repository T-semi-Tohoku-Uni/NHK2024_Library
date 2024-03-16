#ifndef __NHK2024_FILTER_H__
#define __NHK2024_FILTER_H__

#include <stdlib.h>

/*
    * フィルタのバッファ
    *
    * @param buf フィルタのバッファ
    * @param buf_size バッファサイズ
    * 
*/
typedef struct NHK2024_Filter_Buffer {
    double* buf;
    int buf_size;
} NHK2024_Filter_Buffer;


/*
    * ローパスフィルタの設定
    * 
    * @param cutoff_freq カットオフ周波数
    * @param control_cycle 制御周期
    * @param last_val 前回の値
*/
typedef struct Low_Pass_Filter_Settings {
    double cutoff_freq;
    double control_cycle;
    double last_input_val;
    double last_output_val;
} Low_Pass_Filter_Settings;

/*
    * 移動平均フィルタの初期化
    *
    * @param buf フィルタのバッファ
    * @param init_val フィルタの初期値
    * @param buf_size バッファサイズ
    * 
    * @return フィルタのバッファ
*/
NHK2024_Filter_Buffer* moving_average_filter_init(
    double init_val,
    int buf_size
);

/*
    * 移動平均フィルタの更新
    *
    * @param buf フィルタのバッファ
    * @param val フィルタに入力する値
    * 
    * @return フィルタを通した後の値
*/
double moving_average_filter_update(
    NHK2024_Filter_Buffer* buf,
    double val
);


/*
    * ローパスフィルタの初期化
    *
    * @param cutoff_freq カットオフ周波数
    * @param control_cycle 制御周期
    * 
    * @return フィルタの設定
*/
Low_Pass_Filter_Settings* low_pass_filter_init(
    double cutoff_freq,
    double control_cycle
);

/*
    * ローパスフィルタの更新
    *
    * @param settings フィルタの設定
    * @param val フィルタに入力する値
    * 
    * @return フィルタを通した後の値
*/
double low_pass_filter_update(
    Low_Pass_Filter_Settings* settings,
    double input_val
);

#endif // __NHK2024_FILTER_H__