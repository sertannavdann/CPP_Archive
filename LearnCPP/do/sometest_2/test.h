/*
\brief Structure used to pass input over the internet

Normalizes platform specific input to ranges the game cares about.
*/
#include <stdio.h>
#include <string.h>

struct PackedInput
{
    unsigned int rightTrigger : 4;	// 0-15
    unsigned int leftTrigger : 4;	// 0-15
    unsigned int unused : 4;		// Reserved for future use
    unsigned int a : 1;			// On/off
    unsigned int b : 1;			// On/off
    unsigned int x : 1;			// On/off
    unsigned int y : 1;			// On/off
    unsigned int rightThumbstick : 8;	// 0-255
    unsigned int leftThumbstick : 8;	// 0-255

    PackedInput() { memset(this, 0xFF, sizeof(*this)); }
}; // sizeof(PackedInput) == sizeof(uint32_t)

struct NewPlatformGamepadData
{
    uint32_t	data[5];
};