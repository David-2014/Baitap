#include <stdio.h>
#include "setting.h"

void pump_control(Pump state)
{
    if (state == PUMP_ON) printf("[SETTING] Pump ON\n");
    else printf("[SETTING] Pump OFF\n");
}

void led(Mode mode)
{
    if (mode == MODE_AUTO) printf("[LED] Auto mode ON\n");
    else printf("[LED] Manual mode ON\n");
}