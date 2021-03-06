#pragma once

enum class msg_id{
    BATTERY_VOLTAGE = 0,
    CTRL_SETPOINT,
    GAMEPAD,    
    IMU,
    WALL_SENSOR,
    WHEEL_ODOMETRY,
    POSITION_ESTIMATOR,
    GRAND_TRUTH
};

void publishMsg(msg_id msg_id, void* msg);
void copyMsg(msg_id msg_id, void* msg);
