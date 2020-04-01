#pragma once

#include <string>
using namespace std;

class Song
{
private:
    string Title;
    string Artist;
    string Album;
    int Year;
    int PlayTime;

public:
    Song();
    Song(string title, string artist, string album, int year, int playTime);
    void setTitle(string title);
    string getTitle();
    void setArtist(string artist);
    string getArtist();
    void setAlbum(string album);
    string getAlbum();
    void setYear(int year);
    int getYear();
    void setPlayTime(int playTime);
    int getPlayTime();
    bool operator==(Song &rhs);
    void Play();
};