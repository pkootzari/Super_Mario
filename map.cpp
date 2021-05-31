#include "map.h"

using namespace std;

Maapp::Maapp(string _file_address) : file_address(_file_address) {}

void Maapp::readmap() {
    string temp;
    ifstream in;
    in.open(file_address);
    while(getline(in, temp))
        filemap.push_back(temp);
}

int Maapp::map_hieght_getter() { return filemap.size(); }

Filemap Maapp::filemap_getter() { return filemap; }

void Maapp::printmap() {
    for(int i = 0; i < filemap.size(); i++) {
        cout << filemap[i] << endl;
    }
}