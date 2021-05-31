#include "pipe.h"

using namespace std;

Pipe::Pipe(Point _upper_coordinate, Point _lower_coordinate) : upper_coordinate(_upper_coordinate),
                                                               lower_coordinate(_lower_coordinate) {}
void Pipe::draw_pipe(int offset, Window*wid) {
    wid->draw_img(PIPE_LEFT_HEAD, Rectangle ( upper_coordinate.x-offset,
                                              upper_coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    wid->draw_img(PIPE_RIGHT_HEAD, Rectangle ( upper_coordinate.x-offset+BLOCK_SIZE,
                                              upper_coordinate.y, BLOCK_SIZE, BLOCK_SIZE));
    //cout << "upper ( " << upper_coordinate.x << " , " << upper_coordinate.y << " )... lower ( " << lower_coordinate.x << " , " << lower_coordinate.y << " )" << endl;
    for (int i = upper_coordinate.y+BLOCK_SIZE; i <= lower_coordinate.y; i+=BLOCK_SIZE) {
        //cout << "yes" << endl;
        wid->draw_img(PIPE_LEFT_BODY, Rectangle ( upper_coordinate.x-offset,
                                                  i, BLOCK_SIZE, BLOCK_SIZE));
        wid->draw_img(PIPE_RIGHT_BODY, Rectangle ( upper_coordinate.x-offset+BLOCK_SIZE,
                                                   i, BLOCK_SIZE, BLOCK_SIZE));
    }
    //cout << "no" << endl;
}
 
Pipes::Pipes(Filemap _filemap) : filemap(_filemap) {}
void Pipes::render_map() {
    for (int i = 0; i < filemap.size(); i++) 
        for (int j = 0; j < filemap[i].size(); j++) 
            if ( filemap[i][j] == '|' && filemap[i-1][j] != '|' && filemap[i][j+1] == '|' ) {
                //cout <<"saw upper coor ( " << i <<", " << j <<" )" << endl;
                Point up( j*BLOCK_SIZE, i*BLOCK_SIZE + 200 );
                for (int k = i; k < filemap.size()-1; k++)
                    if( filemap[k+1][j] != '|' ) {
                        //cout << "saw lower coor ( " << k <<", " << j <<" )" << endl;
                        Point down( j*BLOCK_SIZE, k*BLOCK_SIZE + 200 );
                        pipe_info.push_back( Pipe(up, down) );
                        break;
                    }
            }
    //cout << "end of file rendering" <<endl;
    //cout << pipe_info.size() << endl;
}
void Pipes::draw_pipes(int offset, Window* wid) {
    for (int i = 0; i < pipe_info.size(); i++)
        pipe_info[i].draw_pipe(offset, wid);
    //cout << "end of the list" << endl;
}