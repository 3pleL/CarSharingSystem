/*Copyright 2021 3pleL*/
#ifndef SRC_VOLTAGEHELPER_HPP_
#define SRC_VOLTAGEHELPER_HPP_

/**
 * Analog input
 * @param int Pin to configure for voltage measurement
 * @return int 0 on success, negative on error
 **/
int measureInit(int);
/**
 * Take a reading of the configured analog input.
 * @param int Pin to use for voltage measurement
 * @return voltage in mV calculated for a resistor divider of 9k/1k
 **/
int measureVoltage(int);

#endif  // SRC_VOLTAGEHELPER_HPP_