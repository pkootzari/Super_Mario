#ifndef ENEMIES_H
#define ENEMIES_H

#include <vector>
#include <string>
#include "rsdl.hpp"

#define MAP_SIZE 50
#define BLOCK_SIZE 35
#define WID_SIZE 1400
#define DELAY 50
#define MOVE_SPD -5

const std::vector<std::string> gomba_walking = {
    "assets/sprites/enemies/little_goomba/walking-1.png",
    "assets/sprites/enemies/little_goomba/walking-2.png"
};

const std::vector<std::string> kompa_walking_right = {
    "assets/sprites/enemies/koopa_troopa/walking-right-1.png",
    "assets/sprites/enemies/koopa_troopa/walking-right-2.png"
}; 

const std::vector<std::string> kompa_walking_left = {
    "assets/sprites/enemies/koopa_troopa/walking-left-1.png",
    "assets/sprites/enemies/koopa_troopa/walking-left-2.png"
}; 

typedef std::vector<std::string> Filemap;

class Gomba {
public:
    Gomba(Point _coordinate);
    void draw_gomba(int offset, Window* wid);
    void update(int offset);
private:
    Point coordinate;
    int status;
    int vx;
};

class Kompa {
public:
    Kompa(Point _coordinate);
    void draw_kompa(int offset, Window* wid);
    void update(int offset);
private:
    Point coordinate;
    int status;
    int vx;
};

class Enemies {
public:
    Enemies(Filemap _filemap);
    void draw_enemies(int offset, Window* wid);
    void update_all_enemies(int offset);
    void render_map();
private:
    std::vector<Gomba> gomba_info;
    std::vector<Kompa> kompa_info;
    Filemap filemap;
};

#endif