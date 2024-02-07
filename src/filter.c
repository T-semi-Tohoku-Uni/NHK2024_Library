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

NHK2024_Low_Pass_Filter_Settings* low_pass_filter_init(
    double cutoff_freq,
    double control_cycle
) {
    NHK2024_Low_Pass_Filter_Settings* settings = (NHK2024_Low_Pass_Filter_Settings*)malloc(sizeof(NHK2024_Low_Pass_Filter_Settings));
    settings->cutoff_freq = cutoff_freq;
    settings->control_cycle = control_cycle;
    settings->last_input_val = 0.0;
    settings->last_output_val = 0.0;
    return settings;
}

double low_pass_filter_update(
    NHK2024_Low_Pass_Filter_Settings* settings,
    double input_val
) {
    double T = settings->control_cycle;
    double tau = settings->cutoff_freq;

    // Update
    double output_val = (T / (T + 2 * tau)) * (input_val + settings->last_input_val) - (T - 2 * tau) / (T + 2 * tau) * settings->last_output_val;
    
    // Set new Parameter
    settings->last_input_val = input_val;
    settings->last_output_val = output_val;

    return output_val;
}