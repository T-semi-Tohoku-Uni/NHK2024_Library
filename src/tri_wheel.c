#include "tri_wheel.h"
#include "math.h"

void caculate_speed_speed_and_spin (
    TriWheel *state,
    double speed_1,
    double speed_2,
    double speed_3
) {
    state -> v_x = (2 * speed_1 - speed_2 - speed_3) / 3;               // x軸方向の速度
    state -> v_y = (speed_2 - speed_3) / sqrt(3);                       // y軸方向の速度
    state -> omega = (speed_1 + speed_2 + speed_3) / (3 * state -> r);  // 角速度
}