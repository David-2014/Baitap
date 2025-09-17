#ifndef TYPES_H
#define TYPES_H

typedef enum { MODE_AUTO, MODE_MANUAL} Mode;
typedef enum { PUMP_ON, PUMP_OFF } Pump;

typedef struct
{
    int moisture;
    float temp;
} Sensor_Data;

typedef struct
{
    Mode mode;
    Pump pump;
    Sensor_Data sensors;
} System;

#endif

