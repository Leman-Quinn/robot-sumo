#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
// ---------- GENERAL VARIABLES ----------//
constexpr float MAX_ENEMY_DISTANCE = 20;

// ---------- INFRARED ----------
constexpr uint8_t OUT_FL = 39;
constexpr uint8_t OUT_FR = 36;
constexpr uint8_t OUT_RL = 34;
constexpr uint8_t OUT_RR = 35;
// ---------- ULTRASONIC ----------
// LEFT SENSOR
constexpr uint8_t TRI_L = 32;
constexpr uint8_t ECHO_L = 33;

// FRONT LEFT SENSOR
constexpr uint8_t TRI_FL = 5;
constexpr uint8_t ECHO_FL = 18;

// FRONT RIGHT SENSOR
constexpr uint8_t TRI_FR = 2;
constexpr uint8_t ECHO_FR = 4;

// RIGHT SENSOR
constexpr uint8_t TRI_R = 16;
constexpr uint8_t ECHO_R = 17;

// ---------- DRIVER ----------
// A = left, B = right
constexpr uint8_t RPWM_A = 21;
constexpr uint8_t LPWM_A = 14;
constexpr uint8_t RPWM_B = 22;
constexpr uint8_t LPWM_B = 23;

#endif