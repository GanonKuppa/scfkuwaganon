
#pragma once

namespace sim{

void initSimConnection();
void finalizeSimConnection();
void setRobotPos(float x, float y, float ang, float v);
void setTargetPos(float x, float y, float ang);
void setMazeWall(uint32_t* walls_vertical, uint32_t* walls_horizontal);
void setNeedle(float x, float y);
void setReload();
void setNumberSqure(float num, float x, float y);

}