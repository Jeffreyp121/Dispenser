#ifndef _GPIO_H
#define _GPIO_H

#include <Arduino.h>
#include <stdint.h>
#include <stdexcept>


#include "GPIOStatus.h"


class GPIO_Pin
{
    private:
        uint8_t pinNumber;
        PIN_MODE pinModes;
        PIN_STATUS pinStatus;
        INTERRUPT_MODE intMode;
        static void DefaultInterruptHandler();
    public:
        GPIO_Pin(uint8_t pinNumber, PIN_MODE pinMode = PIN_MODE_OUTPUT, INTERRUPT_MODE intMode = INTERRUPT_NONE, InterruptHandler handler = DefaultInterruptHandler);
        uint8_t GetPinNumber() const;

        PIN_MODE GetPinMode() const;
        void SetPinMode(PIN_MODE mode);
        PIN_STATUS GetPinStatus();
        void SetPinStatus(PIN_STATUS status);
        INTERRUPT_MODE GetInterruptMode() const;
        bool SetInterrupt(INTERRUPT_MODE mode, void (*interruptHndler)());
        ~GPIO_Pin();
};



#endif 