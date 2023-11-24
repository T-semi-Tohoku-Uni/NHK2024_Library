#ifndef __NHK2024_FILTER_H__
#define __NHK2024_FILTER_H__

#include <stdlib.h>

typedef struct NHK2024_Filter_Buffer {
    double* buf;
    int buf_size;
} NHK2024_Filter_Buffer;

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

#endif // __NHK2024_FILTER_H__