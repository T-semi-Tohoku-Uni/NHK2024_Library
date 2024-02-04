#ifndef __CLIP_NUMBER_H__
#define __CLIP_NUMBER_H__

#include <stdlib.h>

/*
    * 整数のクリッピング
    *
    * @param val クリッピングする値
    * @param min 最小値
    * @param max 最大値
    * 
    * @return クリッピングされた値

*/
int clip_int_number(int val, int min, int max);

/*
    * 浮動小数点数のクリッピング
    *
    * @param val クリッピングする値
    * @param min 最小値
    * @param max 最大値
    * 
    * @return クリッピングされた値

*/
double clip_double_number(double val, double min, double max);

/*
    * 
    * 最小値を0, 最大値を1にクリッピング
    * 
    * @param val クリッピングする値
    * @param min 最小値 (0になる値)
    * @param max 最大値 (1になる値)
    * 
    * @return クリッピングされた値
*/
double clip_zero_one(double val, double min, double max);

#endif // __CLIP_NUMBER_H__