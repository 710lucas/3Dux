#pragma once

#include <citro2d.h>
#include <3ds.h>
#include <string>

void InitDuxRender();

class Dux{
    public:
        /**
         * @brief Initializes basic things needed for graphics and text
        */
        void init();

        /**
         * @brief Update the status of the buttons every frame usefull to check if a button has been pressed
        */
        void update_buttons();

        /**
         * @brief Check if a button has been pressed
         * @param key the value of a key, like KEY_A
        */
        bool pressed(u32 key);

        /**
         * @brief Check if a button is being held
         * @param key the value of a key, like KEY_A
        */
        bool held(u32 key);

        /**
         * @brief initializes the things needed to render
         * @param pos the position of the screen you'll draw on
         * @param pos "top" or "bottom"
         * @param pos default: top
        */
        void begin_render(std::string pos);
        void begin_render();

        /**
         * @brief end the render section of the code
        */
        void end_render();

        void end();

        void get_screen();

        C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    private:
        u32 kDown;
        u32 kHeld;
};

class Rectangle{
    public:
        Rectangle(float px, float py, float pz, float width, float height, u32 color_);
        /**
         * @brief Creates rectangle element
         * @param px x position of the rectangle
         * @param py y position of the rectangle
         * @param width width of the rectangle
         * @param height height of the rectangle
         * @param color_ color of the rectangle
        */
        Rectangle(float px, float py, float width, float height, u32 color_);
        Rectangle();

        void set_x(float px);
        void set_y(float py);
        void set_z(float pz);
        void set_width(float width);
        void set_height(float height);
        void set_color(u32 color);

        float get_x();
        float get_y();
        float get_z();
        float get_width();
        float get_height();
        u32 get_color();

        void render();
        void move(float px, float py);

        float x = 0;
        float y = 0;
        float z = 0;
        float w = 10;
        float h = 10;
        u32 color = C2D_Color32(0xff, 0xff, 0xff, 0xff);
};