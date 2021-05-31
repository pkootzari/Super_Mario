#include "game.h"

using namespace std;

Game::Game(Maapp* _map) : map(_map) {
     maapp = map->filemap_getter();
     int hieght = map->map_hieght_getter();
     base_blocks = 0;
     for(int i = 0; i < hieght; i++)
        if(maapp[i][0] == '#')
            base_blocks++;
     wid = new Window(WID_SIZE, hieght * BLOCK_SIZE + 200, "Super Mario");
     wid->draw_img(BACKGROUND, Rectangle(0, 0, WID_SIZE, hieght*BLOCK_SIZE + 200),
                   Rectangle(0, 0, WID_SIZE, 1000));
     wid->update_screen();
     game_running = true;
     offset = 0;
     mario = new Mario(maapp, this, hieght * BLOCK_SIZE + 200);
     mario->render_map();
     clays = new Clays(maapp);
     clays->render_map();
     questions = new Questions(maapp);
     questions->render_map();
     pipes = new Pipes(maapp);
     pipes->render_map();
     enemies = new Enemies(maapp);
     enemies->render_map();
     //cout << "render done " << endl;
}

void Game::run() {
    while(game_running) {
        draw_map();
        process_event();
        update_objects();
        delay(DELAY);
    }

}

void Game::process_event() {
    while(wid->has_pending_event()) {
        Event event = wid->poll_for_event();
        switch (event.get_type())
        {
            case Event::QUIT:
                game_running = false;
                break;
            case Event::KEY_PRESS:
                mario->handle_key_press(event.get_pressed_key());
                break;
            case Event::KEY_RELEASE:
                mario->handle_key_release(event.get_pressed_key()); 
        }
    }
}

void Game::draw_bg() {
    int hieght = map->map_hieght_getter();
    int x = offset % 1400;
    wid->draw_img(BACKGROUND, Rectangle(-x, 0, 1400, hieght * BLOCK_SIZE + 200));
    wid->draw_img(BACKGROUND, Rectangle(-x + 1400, 0, 1400, hieght * BLOCK_SIZE + 200));
    
}

void Game::draw_map() {
    wid->clear();
    draw_bg();
    clays->draw_clays(offset, wid);
    clays->draw_blocks(offset, wid);
    clays->draw_bricks(offset, wid);
    mario->draw_mario(offset, wid);
    pipes->draw_pipes(offset, wid);
    questions->draw_questions(offset, wid);
    //cout << " draew done" <<endl;
    enemies->draw_enemies(offset, wid);
    wid->update_screen();
}

void Game::update_objects() {
    mario->update(offset);
    if(mario->x_getter() - offset > WID_SIZE/2)
        offset += mario->x_getter()-offset-WID_SIZE/2;
    enemies->update_all_enemies(offset); 
}

//int Game::offset_getter() { return offset; }

int Game::what_is_benith_mario(Point mario_coordiante) {
    int max = 0;
    max = clays->what_is_benith_mario(mario_coordiante);
    return max;
}