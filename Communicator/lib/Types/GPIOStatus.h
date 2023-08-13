#ifndef _GPIO_STATUS_H
#define _GPIO_STATUS_H

typedef enum
{
    PIN_MODE_INPUT,
    PIN_MODE_OUTPUT,
    PIN_MODE_INTERNAL_PULLUP, 
    PIN_MODE_INTERNAL_PULLDOWN,
}PIN_MODE;

typedef enum
{
    OFF,
    ON,
}PIN_STATUS;

typedef enum
{
    INTERRUPT_NONE,
    INTERRUPT_HIGH,
    INTERRUPT_LOW,
    INTERRUPT_CHANGE,
    INTERRUPT_RISING,
    INTERRUPT_FALLING, 
} INTERRUPT_MODE;

typedef void (*InterruptHandler)();
#endif 