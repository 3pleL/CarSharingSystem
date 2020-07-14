#ifndef LED_H
#define LED_H

class Led 
{
    private:
        int m_pin{};
        volatile bool m_state {};
        volatile bool m_state_blink{};
        volatile int m_ontime {};
        volatile unsigned long int m_last_update {}; 

    public:
        /**
         * Constructor of LED
         * @param int LED pin number
         **/
        Led(int);

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
#endif