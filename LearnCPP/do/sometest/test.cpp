#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "test.h"

using std::cout;

namespace ControllerPackingProblem
{
    static PackedInput GetPackedInput(const NewPlatformGamepadData &gamepadData)
    {
        PackedInput returnVal;
        // data[2] Packed value, buttons pressed or not. 0 or 1 
            // Value of A button stored in bit 3
        returnVal.a = (gamepadData.data[2] & 0x8) >> 3;
            // Value of B button stored in bit 2
        returnVal.b = (gamepadData.data[2] & 0x4) >> 2;
            // Value of X button stored in bit 1
        returnVal.x = (gamepadData.data[2] & 0x2) >> 1;
            // Value of Y button stored in bit 0
        returnVal.y = (gamepadData.data[2] & 0x1);
        // data[3] LeftTrigger from 0 to 15
        returnVal.leftTrigger = gamepadData.data[3];
        // data[4] RightTrigger from 0 to 15
        returnVal.rightTrigger = gamepadData.data[4];

        // data[0] LeftThumStick from 0 to 511
        // data[1] RightThumStick from 0 to 511
        returnVal.leftThumbstick = gamepadData.data[0];
        returnVal.rightThumbstick = gamepadData.data[1];

        returnVal.unused = 0;

        return returnVal;
    }
}

int main() {
    NewPlatformGamepadData gamepadData;
    gamepadData.data[0] = 100;
    gamepadData.data[1] = 200;
    gamepadData.data[2] = 0b1010;
    gamepadData.data[3] = 1;
    gamepadData.data[4] = 5;
    PackedInput packedInput = ControllerPackingProblem::GetPackedInput(gamepadData);
    return 0;
}