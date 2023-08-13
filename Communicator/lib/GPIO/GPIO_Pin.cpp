#include "GPIO_Pin.h"



void GPIO_Pin::DefaultInterruptHandler()
{
    // nothing to do here just a default handler not needed;
}

GPIO_Pin::GPIO_Pin(uint8_t pinNumber, PIN_MODE pinMode, INTERRUPT_MODE intMode, InterruptHandler handler)
    :pinNumber(pinNumber)
{
    SetPinMode(pinMode);
    if(!SetInterrupt(intMode, handler))
    {
        throw std::invalid_argument("pin interrupt handler is empty");
    }
}

uint8_t GPIO_Pin::GetPinNumber() const
{
    return GPIO_Pin::pinNumber;
}

PIN_MODE GPIO_Pin::GetPinMode() const
{
    return GPIO_Pin::pinModes;
}

void GPIO_Pin::SetPinMode(PIN_MODE mode)
{
    GPIO_Pin::pinModes = mode;
    switch(pinModes)
    {
        case PIN_MODE_INPUT:
        pinMode(GPIO_Pin::pinNumber, INPUT);
        break;

        case PIN_MODE_OUTPUT:
        Serial.print(pinNumber);
        
        pinMode(GPIO_Pin::pinNumber, OUTPUT);
        break;

        case PIN_MODE_INTERNAL_PULLUP:
        pinMode(GPIO_Pin::pinNumber, PULLUP);
        break;

        case PIN_MODE_INTERNAL_PULLDOWN:
        pinMode(GPIO_Pin::pinNumber, PULLDOWN);
        break;

        default:
        break;
    }
}

PIN_STATUS GPIO_Pin::GetPinStatus()
{
    GPIO_Pin::pinStatus = (digitalRead(GPIO_Pin::pinNumber) == HIGH) ? ON : OFF;
    return GPIO_Pin::pinStatus;
}

void GPIO_Pin::SetPinStatus(PIN_STATUS status)
{
    GPIO_Pin::pinStatus = status;
    switch(pinStatus)
    {
        case ON:
        digitalWrite(GPIO_Pin::pinNumber, HIGH);
        break;

        case OFF:
        digitalWrite(GPIO_Pin::pinNumber, LOW);
        break;

        default:
        break;
    }
}

INTERRUPT_MODE GPIO_Pin::GetInterruptMode() const
{
    return GPIO_Pin::intMode;
}

bool GPIO_Pin::SetInterrupt(INTERRUPT_MODE mode, void (*interruptHndler)())
{
    if(interruptHndler == nullptr)
    {
        return false;
    }
    GPIO_Pin::intMode = mode;

    switch(GPIO_Pin::intMode)
    {
        case INTERRUPT_HIGH:
        attachInterrupt(GPIO_Pin::pinNumber, interruptHndler, HIGH);
        break;

        case INTERRUPT_LOW:
        attachInterrupt(GPIO_Pin::pinNumber, interruptHndler, LOW);
        break;

        case INTERRUPT_CHANGE:
        attachInterrupt(GPIO_Pin::pinNumber, interruptHndler, CHANGE);
        break;

        case INTERRUPT_RISING:
        attachInterrupt(GPIO_Pin::pinNumber, interruptHndler, RISING);
        break;

        case INTERRUPT_FALLING:
        attachInterrupt(GPIO_Pin::pinNumber, interruptHndler, FALLING);
        break;

        default:
        break;
    }

    return true;
}
