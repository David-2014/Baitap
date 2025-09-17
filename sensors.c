#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensors.h"

void read_sensors(Sensor_Data *data)
{
    data->moisture = rand() % 101;
    data->temp = (rand() % 351) / 10.0 +10.0;
    printf("[SENSORS] Moisture: %d%%, Temp: %.1f Độ C\n", data->moisture, data->temp);
}