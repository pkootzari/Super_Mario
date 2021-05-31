#include "rsdl.hpp"
#include "map.h"
#include "mario.h"
#include "game.h"
#include "clay.h"
#include "pipe.h"
#include "question.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    Maapp map(argv[1]);
    map.readmap();
    //map.printmap();
    Game game(&map);
    game.run();
    return 0;
}

