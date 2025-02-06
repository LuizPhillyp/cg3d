#pragma once
#include <stdio.h>
#include <string.h>
#include <GL/gl.h>

struct rgbColor {
    GLfloat r, g, b;
    char colorString[7];

    rgbColor() = default;
    rgbColor(const char* string){
        if (string[0] == '#' && strlen(string) == 7) {

            strcpy(colorString, string);

            int rr, gg, bb; 
            if (sscanf(string + 1, "%2x%2x%2x", &rr, &gg, &bb) == 3) {
                r = rr / 255.0f;
                g = gg / 255.0f;
                b = bb / 255.0f;

                return;
            }
        }
    }
};