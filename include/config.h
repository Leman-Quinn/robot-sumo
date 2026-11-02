#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
// ---------- GENERAL VARIABLES ----------//
constexpr float MAX_ENEMY_DISTANCE = 20;

// ---------- INFRARED ----------

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
constexpr uint8_t AIN1 = 2;
constexpr uint8_t AIN2 = 3;
constexpr uint8_t PWMA = 9;
constexpr uint8_t BIN1 = 4;
constexpr uint8_t BIN2 = 5;
constexpr uint8_t PWMB = 10;

#endif