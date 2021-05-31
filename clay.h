#ifndef CLAY_H
#define CLAY_H

#include "rsdl.hpp"
#include <vector>
#include <iostream>
#include <string>

#define CLAY "assets/sprites/objects/bricks_blocks/clay.png"
#define BLOCK "assets/sprites/objects/bricks_blocks/block.png"
#define BRICK "assets/sprites/objects/bricks_blocks/brick.png"
#define MAP_SIZE 50
#define BLOCK_SIZE 35
#define WID_SIZE 1400

typedef std::vector<std::string> Filemap;

class Clay {
public:
    Clay(Point _coordinate);
    int what_is_benith_mario(Point _coordinate);
    int x_getter();
    int y_getter();
private:
    Point coordinate;
};

class Block {
public:
    Block(Point _coordinate);
    int what_is_benith_mario(Point _coordinate);
    int x_getter();
    int y_getter();
private:
    Point coordinate;
};

class Brick {
public:
    Brick(Point _coordinate);
    int what_is_benith_mario(Point _coordinate);
    int x_getter();
    int y_getter();
private:
    Point coordinate;
};

class Clays {
public:
    Clays(Filemap _filemap);
    int what_is_benith_mario(Point coordinate);
    void draw_clays(int offset, Window* wid);
    void draw_blocks(int offset, Window* wid);
    void draw_bricks(int offset, Window* wid);
    void render_map();

private:
    std::vector<Clay> clay_info;
    std::vector<Block> block_info;
    std::vector<Brick> brick_info;
    Filemap filemap;   
};

#endif