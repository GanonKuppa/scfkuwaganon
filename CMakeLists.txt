cmake_minimum_required(VERSION 2.8)

# message(cmake -G "MinGW Makefiles" ..) windowsでは以下でcmakeを叩くこと

message(STATUS  "======== scfkuwaganon sils cmake ========")
set(CMAKE_C_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-sjlj-rt_v6-rev0/mingw64/bin/gcc")
set(CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-sjlj-rt_v6-rev0/mingw64/bin/g++")
set(CMAKE_CXX_STANDARD, 14)

file(GLOB_RECURSE APP_ACTIVITY_H src/ApplicationLayer/*.h)
file(GLOB_RECURSE APP_ACTIVITY_CPP src/ApplicationLayer/*.cpp)

set(EIGEN_DIR src/ApplicationLayer/Lib/Eigen)

message(STATUS ${MY_SOURCE})
#include_directories(${APP_ACTIVITY_H})
#                    src/HardwareAbstractionLayer 
#                    src/PeriferalDriver)

include_directories(src/ApplicationLayer/Lib/Eigen)

#target_link_libraries(main -lboost_system -lboost_filesystem)

add_executable(sils_main src/sils_main.cpp)
target_link_libraries(sils_main wsock32 ws2_32)
