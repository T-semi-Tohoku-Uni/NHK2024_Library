#include "filter.h"

NHK2024_Filter_Buffer* moving_average_filter_init(
    double init_val,
    int buf_size
) {
    NHK2024_Filter_Buffer* buf = (NHK2024_Filter_Buffer*)malloc(sizeof(NHK2024_Filter_Buffer));
    buf->buf = (double*)malloc(sizeof(double) * buf_size);
    buf->buf_size = buf_size;
    for (int i = 0; i < buf_size; i++) {
        buf->buf[i] = init_val;
    }
    return buf;
}

double moving_average_filter_update(
    NHK2024_Filter_Buffer* buf,
    double val
) {
    for (int i = 0; i < buf->buf_size - 1; i++) {
        buf->buf[i] = buf->buf[i + 1];
    }
    buf->buf[buf->buf_size - 1] = val;

    double sum = 0.0;
    for (int i = 0; i < buf->buf_size; i++) {
        sum += buf->buf[i];
    }
    return sum / buf->buf_size;
}