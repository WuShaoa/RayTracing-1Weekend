#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

void write_color(const int i, const int j, const int w, char* data, color pixel_color){
    data[(j*w+i)*3]   = static_cast<int>(255.999 * pixel_color.x());
    data[(j*w+i)*3+1] = static_cast<int>(255.999 * pixel_color.y());
    data[(j*w+i)*3+2] = static_cast<int>(255.999 * pixel_color.z());
}

#endif
