#include "mario.h"

using namespace std;

Mario::Mario(Filemap _filemap, Game* _game, int _wid_hieght) : game(_game), filemap(_filemap), coordinate(Point(0,0)), wid_hieght(_wid_hieght) {
    vx = 0;
    vy = 0;
    ay = 0;
    ax = 0;
    status = 0;
    pre_act = RIGHT;
}

void Mario::render_map() {
    for (int i = 0; i < filemap.size(); i++)
        for (int j = 0; j < filemap[i].size(); j++)
            if( filemap[i][j] == 'M' ) {
                coordinate = Point ( j*BLOCK_SIZE, i*BLOCK_SIZE + 200 );
                break;
            }
    
}

void Mario::draw_mario(int offset, Window* wid) {
    if(vx == 0) {
        if(pre_act == RIGHT)
            wid->draw_img(NORMAL_MARIO_SR, Rectangle(coordinate.x - offset, 
                                           coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
        else
            wid->draw_img(NORMAL_MARIO_SL, Rectangle(coordinate.x - offset, 
                                           coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    }
    else {
        if(vx > 0) {
            if ( ax >= 0 )
                wid->draw_img(img_path_walking_right[status], Rectangle(coordinate.x - offset, 
                                               coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
            else 
                wid->draw_img(NORMAL_MARIO_SLICER, Rectangle(coordinate.x - offset, 
                                               coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
        }
        else { 
            if ( ax <= 0 )
                wid->draw_img(img_path_walking_left[status], Rectangle(coordinate.x - offset, 
                                              coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
            else
                wid->draw_img(NORMAL_MARIO_SLICEL, Rectangle(coordinate.x - offset, 
                                              coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
        }
        status == 2 ? status = 0 : status++;    
    }
}

void Mario::handle_key_press(char key) {
    switch(key) {
        case 'd':
            vx = INIT_MOVE_SPD;
            pre_act = RIGHT;
            // ax = INIT_ACC;
            // if (vx < INIT_MOVE_SPD)
            //     vx +=ax;
            break;
        case 'a':
            pre_act = LEFT;
            vx = -INIT_MOVE_SPD;
            // ax = -INIT_ACC;
            // if ( vx > -INIT_MOVE_SPD)
            //     vx += ax;
            break;
        case 'w':
            if(if_on_ground()) {
                vy = INIT_JUMP_SPD;
                ay = GRAVITY;
            }
            break; 
    }
    //cout << key <<" pressed " << endl;
}

void Mario::handle_key_release(char key) {
    switch (key) {
        case 'd':
            if ( vx > 0 ) vx = 0;
            //ax = -INIT_ACC;
            ax = 0;
            break;
        case 'a':
            if ( vx < 0 ) vx = 0;
            //ax = -INIT_ACC;
            ax = 0;
            break;
        case 'w':
            break;
    }
    //cout << key << " released " << endl;
}

void Mario::update(int offset) {
    if(coordinate.x + vx >= offset)
        coordinate.x += vx;
    else
        coordinate.x = offset;
    coordinate.y += vy;
    vy += ay;
    // if ( ax > 0 &&( vx == INIT_JUMP_SPD || vx == 0))
    //     ax = 0;
    // if ( ax < 0 &&( vx == -INIT_JUMP_SPD || vx == 0))
    //     ax = 0;
    // if ( vx * ax < 0)
    //     vx += ax;
    
    if_touches_ground();
    if ( coordinate.y > wid_hieght )
        lose();
    //cout << coordinate.y << endl;
}

int Mario::x_getter() { return coordinate.x; }

void Mario::if_touches_ground() {
    int y_pos = game->what_is_benith_mario(coordinate);
    //cout << y_pos - wid_hieght << endl;
    if ( coordinate.y + BLOCK_SIZE > y_pos && coordinate.y + BLOCK_SIZE - vy < y_pos) {
        coordinate.y = y_pos - BLOCK_SIZE;
        ay = 0;
        vy = 0;
    }
    else 
        ay = GRAVITY;
}

bool Mario::if_on_ground() {
    int y_pos = game->what_is_benith_mario(coordinate);
    if ( coordinate.y = y_pos - BLOCK_SIZE )
        return true;
    else
        return false;
}

void Mario::lose() {
    abort();
}