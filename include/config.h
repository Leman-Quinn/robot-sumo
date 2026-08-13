#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
// ---------- GENERAL VARIABLES ----------//
constexpr float MAX_ENEMY_DISTANCE = 20;

// ---------- INFRARED PINS ----------

// ---------- ULTRASONIC PINS ----------
// LEFT SENSOR
constexpr uint8_t TRI_L = A0;
constexpr uint8_t ECHO_L = A1;
// FRONT LEFT SENSOR
constexpr uint8_t TRI_FL = A2;
constexpr uint8_t ECHO_FL = A3;
// FRONT RIGHT SENSOR
constexpr uint8_t TRI_FR = A4;
constexpr uint8_t ECHO_FR = A5;
// RIGHT SENSOR
constexpr uint8_t TRI_R = 6;
constexpr uint8_t ECHO_R = 7;

// ---------- DRIVER PINS ----------
constexpr uint8_t AIN1 = 2;
constexpr uint8_t AIN2 = 3;
constexpr uint8_t BIN1 = 4;
constexpr uint8_t BIN2 = 5;

#endif