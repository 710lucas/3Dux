#include "3dux.h"

Rectangle::Rectangle(float px, float py, float pz, float width, float height, u32 color_){
    x = px;
    y = py;
    z = pz;
    w = width;
    h = height;
    color = color_;
}

Rectangle::Rectangle(float px, float py, float width, float height, u32 color_){
    x = px;
    y = py;
    w = width;
    h = height;
    color = color_;
}

Rectangle::Rectangle(){;}

void Rectangle::set_x(float px){
    x = px;
}

void Rectangle::set_y(float py){
    y = py;
}

void Rectangle::set_z(float pz){
    z = pz;
}

void Rectangle::set_width(float width){
    w = width;
}

void Rectangle::set_height(float height){
    h = height;
}

void Rectangle::set_color(u32 color_){
    color = color_;
}

u32 Rectangle::get_color() { return color; }
float Rectangle::get_x() { return x; }
float Rectangle::get_y() { return y; }
float Rectangle::get_z() { return z; }
float Rectangle::get_width() { return w; }
float Rectangle::get_height() { return h; }

void Rectangle::render(){
    C2D_DrawRectSolid(x, y, z, w, h, color);
}

void Rectangle::move(float px, float py){
    x = x+px;
    y = y-py;
}