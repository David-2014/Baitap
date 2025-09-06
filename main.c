#include <stdio.h>
#include "led_driver.h"

int main(void)
{
    if (led_driver_init(10) != 0)
    {
        printf("khong the khoi tao LED\n");
        return -1;
    }  
    const uint32_t* buf = led_driver_get_buffer();
    size_t count = led_driver_get_pixel_count();

    int all_zero = 1;
    for (size_t i = 0; i < count; i++)
    {
        if (buf[i] != 0)
        {
            all_zero = 0;
            break;
        }
    }
    printf("Buffer ban dau %s tat ca la 0\n", all_zero ? "co" : "khong");

    led_driver_set_pixel_color(0, 255, 0, 0); // Do
    led_driver_set_pixel_color(9, 0, 0, 255); // Xanh la
    led_driver_set_pixel_color(4, 255, 255, 255); // Xanh duong

    printf("Pixel[0] = 0x%08X (expect 0x00FF0000)\n", buf[0]);
    printf("Pixel[4] = 0x%08X (expect 0x00FFFFFF)\n", buf[4]);
    printf("Pixel[9] = 0x%08X (expect 0x000000FF)\n", buf[9]);

    led_driver_fill(0, 255, 0); // Xanh la

    int ok_fill = 1;
    for (size_t i = 0; i < count; i++)
    {
        if (buf[i] != 0x00FF0000)
        {
            ok_fill = 0;
            break;
        }
    }
    printf("Fill xanh la %s\n", ok_fill ? "co" : "khong");

    led_driver_shutdown();
    return 0;
}
