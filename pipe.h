#ifndef PIPE_H
#define PIPE_H

#include "rsdl.hpp"
#include <vector>
#include <string>
#include <iostream>

#define PIPE_LEFT_HEAD "assets/sprites/objects/pipe/head-left.png"
#define PIPE_LEFT_BODY "assets/sprites/objects/pipe/left.png"
#define PIPE_RIGHT_HEAD "assets/sprites/objects/pipe/head-right.png"
#define PIPE_RIGHT_BODY "assets/sprites/objects/pipe/right.png"
#define MAP_SIZE 50
#define BLOCK_SIZE 35
#define WID_SIZE 1400

typedef std::vector<std::string> Filemap;

class Pipe {
public: 
    Pipe(Point _upper_coordinate, Point _lower_coordinate);
    void draw_pipe(int offset, Window* wid);
private:
    Point upper_coordinate;
    Point lower_coordinate;
};

class Pipes {
public:
    Pipes(Filemap _filemap);
    void draw_pipes(int offset, Window* wid);
    void render_map();
private:
    std::vector<Pipe> pipe_info;
    Filemap filemap;
};

#endif 