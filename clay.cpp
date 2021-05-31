#include "clay.h"

using namespace std;

Clay::Clay(Point _coordinate) : coordinate(_coordinate) {}
int Clay::what_is_benith_mario(Point _coordinate) {
    if (coordinate.x <= _coordinate.x + BLOCK_SIZE/2 && _coordinate.x + BLOCK_SIZE/2 <= coordinate.x + BLOCK_SIZE)
        return coordinate.y;
    else
        return 99999;
}
int Clay::x_getter() { return coordinate.x; }
int Clay::y_getter() { return coordinate.y; }

Block::Block(Point _coordinate) : coordinate(_coordinate) {}
int Block::what_is_benith_mario(Point _coordinate) {
    if (coordinate.x <= _coordinate.x + BLOCK_SIZE/2 && _coordinate.x + BLOCK_SIZE/2 <= coordinate.x + BLOCK_SIZE)
        return coordinate.y;
    else
        return 99999;
}
int Block::x_getter() { return coordinate.x; }
int Block::y_getter() { return coordinate.y; }

Brick::Brick(Point _coordinate) : coordinate(_coordinate) {}
int Brick::what_is_benith_mario(Point _coordinate) {
    if (coordinate.x <= _coordinate.x + BLOCK_SIZE/2 && _coordinate.x + BLOCK_SIZE/2 <= coordinate.x + BLOCK_SIZE)
        return coordinate.y;
    else
        return 99999;
}
int Brick::x_getter() { return coordinate.x; }
int Brick::y_getter() { return coordinate.y; }

Clays::Clays(Filemap _filemap) : filemap(_filemap) {}
void Clays::render_map() {
    for (int i = 0; i < filemap.size(); i++)
        for (int j = 0; j < filemap[i].size(); j++) {
            if ( filemap[i][j] == '#' )
                clay_info.push_back( Clay( Point( j*BLOCK_SIZE, i*BLOCK_SIZE + 200 ) ) );
            if ( filemap[i][j] == '@' )
                block_info.push_back( Block( Point( j*BLOCK_SIZE, i*BLOCK_SIZE + 200 ) ) );
            if ( filemap[i][j] == 'b' )
                brick_info.push_back( Brick( Point( j*BLOCK_SIZE, i*BLOCK_SIZE + 200 ) ) );
        }
}
void Clays::draw_clays(int offset, Window* wid) {
    for (int i = 0; i < clay_info.size(); i++) {
        /*if ( clay_info[i].x_getter() >= offset && 
             clay_info[i].x_getter() + BLOCK_SIZE <= offset + WID_SIZE )*/
            wid->draw_img(CLAY,
                          Rectangle(clay_info[i].x_getter() - offset, clay_info[i].y_getter()
                          , BLOCK_SIZE, BLOCK_SIZE));
        //if( info[i].coordinate)
    }
}
void Clays::draw_blocks(int offset, Window* wid) {
    for (int i = 0; i < block_info.size(); i++) {
        /*if ( block_info[i].x_getter() >= offset && 
             block_info[i].x_getter() + BLOCK_SIZE <= offset + WID_SIZE )*/
            wid->draw_img(BLOCK,
                          Rectangle(block_info[i].x_getter() - offset, block_info[i].y_getter()
                          , BLOCK_SIZE, BLOCK_SIZE));
        //if( info[i].coordinate)
    }
}
void Clays::draw_bricks(int offset, Window* wid) {
    for (int i = 0; i < brick_info.size(); i++) {
        /*if ( block_info[i].x_getter() >= offset && 
             block_info[i].x_getter() + BLOCK_SIZE <= offset + WID_SIZE )*/
            wid->draw_img(BRICK,
                          Rectangle(brick_info[i].x_getter() - offset, brick_info[i].y_getter()
                          , BLOCK_SIZE, BLOCK_SIZE));
        //if( info[i].coordinate)
    }
}
int Clays::what_is_benith_mario(Point coordinate) {
    int max = 99999; 
    for (int i = 0; i < clay_info.size(); i++) {
        int cur = clay_info[i].what_is_benith_mario(coordinate);
        if ( cur < max )
            max = cur;
    }
    for (int i = 0; i < block_info.size(); i++) {
        int cur = block_info[i].what_is_benith_mario(coordinate);
        if ( cur < max )
            max = cur;
    }
    for (int i = 0; i < brick_info.size(); i++) {
        int cur = brick_info[i].what_is_benith_mario(coordinate);
        if ( cur < max )
            max = cur;
    }
    return max;
}