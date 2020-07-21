/*Copyright 2020 3pleL*/
#ifndef SRC_LED_HPP_
#define SRC_LED_HPP_

class Led {
 private:
    int m_pin{};
    volatile bool m_state{};
    volatile bool m_state_blink{};
    volatile int m_ontime{};
    volatile unsigned long int m_last_update{}; //NOLINT

 public:
    /**
         * Constructor of LED
         * @param int LED pin number
         **/
    explicit Led(int);

    /**
         * turn on the LED statically
         **/
    void switchOn();

    /**
         * turn off the LED and stop blinking
         **/
    void switchOff();

    /**
         * let the led blink
         * @param int interval in ms
         **/
    void blink(int);

    /**
         * update the LED hardware pin
         **/
    void update();
};
#endif  // SRC_LED_HPP_
