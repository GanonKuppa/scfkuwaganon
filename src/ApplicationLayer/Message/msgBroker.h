#pragma once

enum class msg_id{
    BATTERY_VOLTAGE = 0,
    CTRL_SETPOINT,
    GAMEPAD,    
    IMU,
    WALL_SENSOR,
    WHEEL_ODOMETRY,
    POSITION_ESTIMATOR
};

void msgPublish(msg_id msg_id, const void* msg);
void msgCopy(msg_id msg_id, void* msg);

