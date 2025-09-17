#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "led_driver.h"

static uint32_t *g_buffer = NULL;
static size_t g_num_pixels = 0;

int led_driver_init(size_t num_pixels)
{
    if (g_buffer != NULL) {
        free(g_buffer);
        g_buffer = NULL;
        g_num_pixels = 0;
    }
    
    if (num_pixels == 0) return -1;

    g_buffer = (uint32_t *)malloc(num_pixels * sizeof(uint32_t));
    if (g_buffer == NULL)
    {
        g_num_pixels = 0;
        return -1;
    }

    g_num_pixels = num_pixels;
    return 0;
}

void led_driver_shutdown(void)
{
    if (g_buffer) {
        free(g_buffer);
        g_buffer = NULL;
    }
    g_num_pixels = 0;
}

void led_driver_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b)
{
    if (g_buffer == NULL) return;
    if (index >= g_num_pixels) return;

    uint32_t color = ((uint32_t)g << 16) | ((uint32_t)r << 8) | (uint32_t)b;
    g_buffer[index] = color;
}

void led_driver_fill(uint8_t r, uint8_t g, uint8_t b)
{
    if (g_buffer == NULL) return;

    uint32_t color = ((uint32_t)g << 16) | ((uint32_t)r << 8) | (uint32_t)b;
    for (size_t i = 0; i < g_num_pixels; i++) {
        g_buffer[i] = color;
    }
}

void led_driver_clear(void)
{
    if (g_buffer == NULL) return;

    memset(g_buffer, 0, g_num_pixels * sizeof(uint32_t));
}

const uint32_t* led_driver_get_buffer(void)
{
    return g_buffer;
}

size_t led_driver_get_pixel_count(void)
{
    return g_num_pixels;
}