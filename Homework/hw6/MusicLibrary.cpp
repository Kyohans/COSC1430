#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MusicLibrary.h"

MusicLibrary::MusicLibrary(int maxsongs)
{
    maxSongs = maxsongs;
    mySongs = new Song[maxSongs];
    playList = &mySongs;
    numSongs = 0;
    numSongsPlayList = 0;
}
MusicLibrary::MusicLibrary(MusicLibrary &other)
{
    maxSongs = other.maxSongs;
    numSongs = other.numSongs;
    mySongs = other.mySongs;
    numSongsPlayList = other.numSongsPlayList;
    playList = other.playList;
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
    cout << numSongs << " Added " << mySongs[numSongs].getTitle() << endl;
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
    bool cont = true;

    if (input.is_open())
    {
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
            cout << title << endl;
            cont = addSong(title, artist, album, year, time);
        };
    }
    else
    {
        cout << "could not open file " << filename << endl;
    }
}

void MusicLibrary::playRandom()
{
    int i = 0;
    int j = numSongs - 1;
    while(i > j)
    {
        mySongs[i].Play();
        mySongs[j - i].Play();
        i++;
        j--;
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

    numSongsPlayList = numSongsPlayList + 1;
    *playList[numSongsPlayList] = mySongs[pos];
    return true;
}

void MusicLibrary::playPlaylist()
{
    for(int i = 0; i < numSongsPlayList; i++)
    {
        playList[i]->Play();
    }
}