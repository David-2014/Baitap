#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>

int led_driver_init(size_t num_pixels);

void led_driver_shutdown(void);

void led_driver_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b);

void led_driver_fill(uint8_t r, uint8_t g, uint8_t b);

void led_driver_clear(void);

const uint32_t* led_driver_get_buffer(void);

size_t led_driver_get_pixel_count(void);

#endif