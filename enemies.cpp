#include "enemies.h"

using namespace std;

Gomba::Gomba(Point _coordinate) : coordinate(_coordinate) { int status = 0; vx = 0; }
void Gomba::draw_gomba(int offset, Window* wid) {
    wid->draw_img(gomba_walking[1], Rectangle(coordinate.x-offset, coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    status == 1 ? status = 0 : status++;
}
void Gomba::update(int offset) {
    if (offset + WID_SIZE > coordinate.x)
        vx = MOVE_SPD;
    coordinate.x +=vx;
}

Kompa::Kompa(Point _coordinate) : coordinate(_coordinate) { int status = 0; vx = 0; }
void Kompa::draw_kompa(int offset, Window* wid) {
    wid->draw_img(kompa_walking_right[1], Rectangle(coordinate.x-offset, coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    status == 1 ? status = 0 : status++;
}
void Kompa::update(int offset) {
    if (offset + WID_SIZE > coordinate.x)
        vx = MOVE_SPD;
    coordinate.x +=vx;
}

Enemies::Enemies(Filemap _filemap) : filemap(_filemap) {}
void Enemies::draw_enemies(int offset, Window* wid) {
    for (int i = 0; i < gomba_info.size(); i++)
        gomba_info[i].draw_gomba(offset, wid);
    for (int i = 0; i < kompa_info.size(); i++)
        kompa_info[i].draw_kompa(offset, wid);
}
void Enemies::update_all_enemies(int offset) {
    for (int i = 0; i < gomba_info.size(); i++)
        gomba_info[i].update(offset);
    for (int i = 0; i < kompa_info.size(); i++)
        kompa_info[i].update(offset);
}
void Enemies::render_map() {
    for (int  i = 0; i < filemap.size(); i++)
        for (int  j = 0; j < filemap[i].size(); j++) {
            if (filemap[i][j] == 'l')
                gomba_info.push_back ( Gomba (Point(j*BLOCK_SIZE, i*BLOCK_SIZE + 200)) );
            if (filemap[i][j] == 'k')
                kompa_info.push_back ( Kompa (Point(j*BLOCK_SIZE, i*BLOCK_SIZE + 200)) );
        }
}