#ifndef QUESTION_H
#define QUESTION_H

#include "rsdl.hpp"
#include <vector>
#include <iostream>
#include <string>

// #define Q1 "assets/sprites/objects/bricks_blocks/question-1.png"
// #define Q2 "assets/sprites/objects/bricks_blocks/question-2.png"
// #define Q3 "assets/sprites/objects/bricks_blocks/question-3.png"
#define QE "assets/sprites/objects/bricks_blocks/question-empty.png"
#define MAP_SIZE 50
#define BLOCK_SIZE 35
#define WID_SIZE 1400
#define DELAY 50

const std::vector<std::string> img_path = {
    "assets/sprites/objects/bricks_blocks/question-1.png",
    "assets/sprites/objects/bricks_blocks/question-2.png",
    "assets/sprites/objects/bricks_blocks/question-3.png"
};

typedef std::vector<std::string> Filemap;

class Question {
public:
    Question (Point _coordinate);
    void draw_question(int offset, Window* wid);

private:
    Point coordinate;
    int status;
};

class Questions {
public:
    Questions(Filemap _filemap);
    void render_map();
    void draw_questions(int offset, Window* wid);
private:
    Filemap filemap;
    std::vector<Question> question_info;
};

#endif