#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"
#include "sensors.h"
#include "buttons.h"
#include "watering_logic.h"

int main()
{
    srand(time(NULL));
    System system = { MODE_AUTO, PUMP_OFF, {0, 0.0} };

    while (1)
    {
        read_sensors(&system.sensors);
        check_button(&system);
        watering_update(&system);
        printf("-----------------------------\n");
    }
    
    return 0;
}