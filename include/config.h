#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ---------- INFRARED PINS ----------

// ---------- ULTRASONIC PINS ----------
// LEFT SENSOR
constexpr uint8_t TRI_L = A4;
constexpr uint8_t ECHO_L = A5;
// FRONT LEFT SENSOR
constexpr uint8_t TRI_FL = A2;
constexpr uint8_t ECHO_FL = A3;
// FRONT RIGHT SENSOR
constexpr uint8_t TRI_FR = A0;
constexpr uint8_t ECHO_FR = A1;
// RIGHT SENSOR
constexpr uint8_t TRI_R = 8;
constexpr uint8_t ECHO_R = 9;

// ---------- MOTOR PINS ----------
// LEFT MOTOR
constexpr uint8_t IN3 = 12;
constexpr uint8_t IN4 = 13;
// RIGHT MOTOR
constexpr uint8_t IN1 = 10; 
constexpr uint8_t IN2 = 11;

#endif