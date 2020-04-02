#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MusicLibrary.h"

MusicLibrary::MusicLibrary(int maxsongs)
{
    maxSongs = maxsongs;
    numSongs = 0;
    numSongsPlayList = 0;
    mySongs = new Song[maxSongs];
    playList = new Song*[maxSongs];
}

MusicLibrary::MusicLibrary(const MusicLibrary &other)
{
    maxSongs = other.maxSongs;
    numSongs = other.numSongs;
    numSongsPlayList = other.numSongsPlayList;
    mySongs = new Song[maxSongs];
    playList = new Song *[maxSongs];
    
    for(int i = 0; i < numSongs; i++)
    {
        mySongs[i] = other.mySongs[i];
        playList[i] = &mySongs[i];
    }
}

MusicLibrary::~MusicLibrary()
{
    delete[] mySongs;
    delete[] playList;
}

int MusicLibrary::getnumSongs()
{
    return numSongs;
}
int MusicLibrary::getmaxSongs()
{
    return maxSongs;
}
int MusicLibrary::getnumSongsPlayList()
{
    return numSongsPlayList;
}

bool MusicLibrary::addSong(string title, string artist, string album, int year, int time)
{
    if (numSongs == maxSongs)
    {
        cout << "Could not add song to library. Library is full" << endl;
        return false;
    }
    mySongs[numSongs].setTitle(title);
    mySongs[numSongs].setArtist(artist);
    mySongs[numSongs].setAlbum(album);
    mySongs[numSongs].setYear(year);
    mySongs[numSongs].setPlayTime(time);
    numSongs++;
    return true;
}

bool MusicLibrary::addSong(Song &song)
{
    if (numSongs == maxSongs)
    {
        cout << "Could not add song to library. Library is full" << endl;
        return false;
    }
    mySongs[numSongs] = song;
    numSongs++;

    return true;
}

void MusicLibrary::readSongsFromFile(string filename)
{
    ifstream input;
    input.open(filename);
    if(input.fail())
    {
        cout << "ERROR: No such file!" << endl;
        exit(0);
    }
    bool cont = true;

    string line;
    while (getline(input, line) && cont)
    {
        string title, artist, album;
        string s_year, s_time;
        int year;
        int time;
        istringstream inSS(line);

        getline(inSS, title, ',');
        getline(inSS, artist, ',');
        getline(inSS, album, ',');
        getline(inSS, s_year, ',');
        getline(inSS, s_time);

        year = stoi(s_year);
        time = stoi(s_time);
        cont = addSong(title, artist, album, year, time);
    }
    input.close();
}

void MusicLibrary::playRandom()
{
    int i = 0;
    int j = numSongs - 1;
    while(i < j)
    {
        mySongs[i].Play();
        mySongs[j].Play();
        i++;
        j--;

        if(i == j)
        {
            mySongs[i].Play();
        }
    }
}

bool MusicLibrary::addSongToPlayList(int pos)
{
    if(numSongsPlayList == maxSongs)
    {
        cout << "Playlist is full" << endl;
        return false;
    }

    if((pos < 0) || (pos > numSongs))
    {
        cout << "Invalid song" << endl;
        return false;
    }

    playList[numSongsPlayList] = &mySongs[pos];
    numSongsPlayList++;
    return true;
}

void MusicLibrary::playPlaylist()
{
    for(int i = 0; i < numSongsPlayList; i++)
    {
        playList[i]->Play();
    }
}