#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

typedef std::vector<std::string> Filemap;

class Maapp {
public:
    Maapp(std::string _file_adress);
    void readmap();
    int map_hieght_getter();
    Filemap filemap_getter();
    void printmap();

private:
    Filemap filemap;
    std::string file_address;
};

#endif