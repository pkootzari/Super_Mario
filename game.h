#ifndef GAME_H
#define GAME_H

#include "rsdl.hpp"
#include "map.h"
#include "clay.h"
#include "mario.h"
#include "pipe.h"
#include "question.h"
#include "enemies.h"
#include <vector>
#include <string>
#include <iostream>

#define BACKGROUND "assets/background_image.png"
#define BRICK_DEBRIS "assets/sprites/objects/bricks_blocks/brick-debris.png"

#define MAP_SIZE 50
#define BLOCK_SIZE 35
#define WID_SIZE 1400
#define DELAY 50

//typedef sdt::vector<Caly> Clays;

class Mario;

class Game {
public:
    Game(Maapp* _map);
    void run();
    //int offset_getter();
    int what_is_benith_mario(Point mario_coordinate);
    
private:
    void draw_map();
    void update_objects();
    void process_event();
    //void render_map();
    void draw_bg();

    Window* wid;
    Maapp* map;
    Filemap maapp;
    bool game_running;
    int offset;
    int base_blocks;
    Clays* clays;
    Mario* mario;
    Pipes* pipes;
    Questions* questions;
    Enemies* enemies;
    //Clays clays;
};

#endif