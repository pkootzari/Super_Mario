#ifndef MARIO_H
#define MARIO_H

#include "rsdl.hpp"
#include "map.h"
#include "game.h"
#include <vector>
#include <string>
#include <iostream>

#define NORMAL_MARIO_SR "assets/sprites/mario/normal/standing-right.png"
#define NORMAL_MARIO_SL "assets/sprites/mario/normal/standing-left.png"
#define NORMAL_MARIO_SLICER "assets/sprites/mario/normal/sliding-right.png" 
#define NORMAL_MARIO_SLICEL "assets/sprites/mario/normal/sliding-left.png" 
#define GRAVITY 10
#define INIT_JUMP_SPD -50
#define INIT_MOVE_SPD 20
#define INIT_ACC 10

const std::vector<std::string> img_path_walking_right = {
    "assets/sprites/mario/normal/walking-right-1.png",
    "assets/sprites/mario/normal/walking-right-2.png",
    "assets/sprites/mario/normal/walking-right-3.png"
};

const std::vector<std::string> img_path_walking_left = {
    "assets/sprites/mario/normal/walking-left-1.png",
    "assets/sprites/mario/normal/walking-left-2.png",
    "assets/sprites/mario/normal/walking-left-3.png"
};


enum Pre_act {
    RIGHT,
    LEFT
};

typedef std::vector<std::string> Filemap;

class Game;

class Mario {
public:
    Mario(Filemap _filemap, Game* _game, int _wid_hight);
    void update(int offset);
    void draw_mario(int offset, Window* wid);
    void handle_key_press(char key);
    void handle_key_release(char key);
    void render_map();
    int x_getter();

private:
    void if_touches_ground();
    bool if_on_ground();
    void lose();
    Point coordinate;
    Game* game;
    int wid_hieght;
    double vx;
    double vy;
    double ay;
    int ax;
    int status;
    Pre_act pre_act;
    Filemap filemap;
};

#endif