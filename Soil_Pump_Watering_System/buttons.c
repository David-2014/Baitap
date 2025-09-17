#include <stdio.h>
#include "buttons.h"

void check_button(System *state)
{
    char input;
    printf("Press 'm' to toggle mode: ");
    input = getchar();
    while (getchar() != '\n'); //clear buffet
    if (input == 'm')
    {
        state->mode = (state->mode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
        printf("[BUTTON] Mode switched!\n");
    }
}