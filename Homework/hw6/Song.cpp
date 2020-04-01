#include <iostream>
#include "Song.h"

void Song::Play()
{
    cout << "Playing " << Title << " by " << Artist << " " << PlayTime << " seconds" << endl;
}

Song::Song()
{
    PlayTime = 0;
    Year = 0;
}

Song::Song(string title, string artist, string album, int year, int playTime)
{
    Title = title;
    Artist = artist;
    Album = album;
    Year = year;
    PlayTime = playTime;
}

void Song::setTitle(string title)
{
    Title = title;
}

string Song::getTitle()
{
    return Title;
}

void Song::setArtist(string artist)
{
    Artist = artist;
}

string Song::getArtist()
{
    return Artist;
}

void Song::setAlbum(string album)
{
    Album = album;
}

string Song::getAlbum()
{
    return Album;
}

void Song::setYear(int year)
{
    Year = year;
}

int Song::getYear()
{
    return Year;
}

void Song::setPlayTime(int playTime)
{
    PlayTime = playTime;
}

int Song::getPlayTime()
{
    return PlayTime;
}

bool Song::operator==(Song &rhs)
{
    return ((this->Title == rhs.Title) && (this->Artist == rhs.Artist) && (this->Album == rhs.Album));
}