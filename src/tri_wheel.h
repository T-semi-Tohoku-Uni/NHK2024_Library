#ifdef __TRIWHEEL_H__
#define __TRIWHEEL_H__

/*
    三輪オムニの各種パラメータの構造体
    @param r ロボット中心から車輪までの距離
    @param v_x x軸方向の速度
    @param v_y y軸方向の速度
    @param omega 角速度
*/
typedef struct TriWheel {
    double r;   // ロボット中心から車輪までの距離
    double v_x; // 速度
    double v_y; // 速度
    double omega; // 角速度
} TriWheel;

/*
void caculate_ (
    int 
)
*/

/*
    三輪オムニの状態（速度, 角速度）を計算する関数
    @param state 三輪オムニの状態
    @param speed_1, speed_2, speed_3 それぞれの車輪の速度

    @return void
*/
void caculate_speed_speed_and_spin (
    TriWheel *state,
    double speed_1,
    double speed_2,
    double speed_3
);

#endif // __TRIWHEEL_H__