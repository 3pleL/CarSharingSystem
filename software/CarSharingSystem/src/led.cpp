/*Copyright 2020 3pleL*/
#include "led.hpp"
#include <Arduino.h>

Led::Led(int pin) {
  m_pin = pin;
  pinMode(m_pin, OUTPUT);
  m_state = 0;
  m_state_blink = 0;
  digitalWrite(m_pin, m_state);
}

void Led::switchOff() {
  m_state = 0;
  m_state_blink = 0;
}

void Led::switchOn() { m_state = 1; }

void Led::update() {
  if (m_state_blink) {
    unsigned long int currentMillis = millis(); //NOLINT
    if (currentMillis - m_last_update > m_ontime) {
      m_last_update = currentMillis;
      m_state = !m_state;
    }
  }
  digitalWrite(m_pin, m_state);
}

void Led::blink(int ontime) {
  m_ontime = ontime;
  m_state_blink = 1;
}
