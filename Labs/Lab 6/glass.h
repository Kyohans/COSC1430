#ifndef GLASS_H
#define GLASS_H

#include <string>
using namespace std;

class Glass
{
public:
    Glass(bool isFull = false, string material = "glass", string content = " ");
    Glass(string material);
    Glass(string material, string content);
    bool checkFull(string content);
    void fill();
    void fill(string content);
    void empty();
    string getContent();
    string getMaterial();

private:
    string content;
    string material;
    bool isFull;
};

#endif