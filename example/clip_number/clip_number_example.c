#include "clip_number.h"
#include <stdio.h>

int main() {
    int val = 10;
    int min = 0;
    int max = 5;
    /*
        最大値が5, 最小値が0
        10は最大値を超えているので, 5にクリッピングされる
    */
    // Output: clip_int_number(10, 0, 5) = 5 
    printf("clip_int_number(%d, %d, %d) = %d\n", val, min, max, clip_int_number(val, min, max));

    double val2 = 10.0;
    double min2 = 0.0;
    double max2 = 5.0;
    /*
        最大値が5, 最小値が0
        10は最大値を超えているので, 5にクリッピングされる
    */
    // Output: clip_double_number(10.000000, 0.000000, 5.000000) = 5.000000
    printf("clip_double_number(%f, %f, %f) = %f\n", val2, min2, max2, clip_double_number(val2, min2, max2));

    double val3 = 10.0;
    double min3 = 0.0;
    double max3 = 5.0;
    /*
        最大値が5, 最小値が0
        10は最大値を超えているので, 1にクリッピングされる
    */
    // Output: clip_zero_one(10.000000, 0.000000, 5.000000) = 1.000000
    printf("clip_zero_one(%f, %f, %f) = %f\n", val3, min3, max3, clip_zero_one(val3, min3, max3));

    double val4 = 2.5;
    double min4 = 0.0;
    double max4 = 5.0;
    /*
        最大値が5, 最小値が0
        2.5は0.5にクリッピングされる
    */
    // Output: clip_zero_one(2.500000, 0.000000, 5.000000) = 0.500000
    printf("clip_zero_one(%f, %f, %f) = %f\n", val4, min4, max4, clip_zero_one(val4, min4, max4));

    return 0;
}