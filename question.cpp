#include "question.h"

using namespace std;

Question::Question(Point _coordinate) : coordinate(_coordinate) { status = 0; }
void Question::draw_question (int offset, Window* wid) {
    // wid->draw_img(Q1 , Rectangle(coordinate.x - offset, coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    // wid->update_screen();
    // delay(DELAY/3);
    // wid->draw_img(Q2 , Rectangle(coordinate.x - offset, coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    // wid->update_screen();
    // delay(DELAY/3);
    // wid->draw_img(Q2 , Rectangle(coordinate.x - offset, coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    // wid->update_screen();
    //delay(DELAY/3);
    wid->draw_img(img_path[status], Rectangle(coordinate.x - offset, coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    status == 2 ? status = 0 : status++;
}

Questions::Questions(Filemap _filemap) : filemap(_filemap) {}
void Questions::draw_questions(int offset, Window* wid) {
    for (int i = 0; i < question_info.size(); i++)
        question_info[i].draw_question(offset, wid);
}
void Questions::render_map() {
    for (int i = 0; i < filemap.size(); i++) 
        for (int j = 0; j < filemap[i].size(); j++){
            if ( filemap[i][j] == '?')
                question_info.push_back( Question(Point(j*BLOCK_SIZE, i*BLOCK_SIZE + 200)) );
            if ( filemap[i][j] == 'm')
                question_info.push_back( Question(Point(j*BLOCK_SIZE, i*BLOCK_SIZE + 200)) );
            if ( filemap[i][j] == 'h')
                question_info.push_back( Question(Point(j*BLOCK_SIZE, i*BLOCK_SIZE + 200)) );
        }
}
