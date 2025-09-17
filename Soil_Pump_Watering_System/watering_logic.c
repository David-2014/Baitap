#include <stdio.h>
#include "watering_logic.h"
#include "config.h"
#include "setting.h"

void watering_update(System *state)
{
    if (state->mode == MODE_AUTO)
    {
        if (state->sensors.moisture < MOISTURE_MIN)
        {
            state->pump = PUMP_ON;
        }else if (state->sensors.moisture >= MOISTURE_MAX)
        {
            state->pump = PUMP_OFF;
        }
    }
    pump_control(state->pump);
    led(state->mode);
}