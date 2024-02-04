#include "clip_number.h"

int clip_int_number(int val, int min, int max) {
    if (val < min) {
        return min;
    } else if (val > max) {
        return max;
    } else {
        return val;
    }
}

double clip_double_number(double val, double min, double max) {
    if (val < min) {
        return min;
    } else if (val > max) {
        return max;
    } else {
        return val;
    }
}

double clip_zero_one(double val, double min, double max) {
    if (val < min) {
        return 0.0;
    } else if (val > max) {
        return 1.0;
    } else {
        return (val - min) / (max - min);
    }
    
}