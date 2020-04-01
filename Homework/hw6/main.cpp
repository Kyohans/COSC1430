#include <iostream>
#include <string>
#include "Song.h"
#include "MusicLibrary.h"

using namespace std;

int main()
{

    string filename;
    int numsongs;
    char mode;

    cout << "Enter number of Songs " << endl;
    cin >> numsongs;
    
    while(numsongs <= 0)
    {
        cout << "Invalid number. Try again: " << endl;
        cin >> numsongs;
    }
    MusicLibrary mylibrary(numsongs);

    cout << "Enter filename with information about the songs" << endl;
    cin >> filename;

    mylibrary.readSongsFromFile(filename);

    cout << "Enter mode of operation  (r: play Random, l: play PlayList, b: play both) " << endl;
    cin >> mode;
    
    while((mode != 'r') && (mode != 'l') && (mode != 'b'))
    {
        cout << "Invalid input. Try again: " << endl;
        cin >> mode;
    }

    if (mode == 'r' || mode == 'b')
    {
        mylibrary.playRandom();
    }
    
    if (mode == 'l' || mode == 'b')
    {
        for (int i = mylibrary.getnumSongs() - 1; i >= 0; i--)
        {
            mylibrary.addSongToPlayList(i);
        }
 
        mylibrary.playPlaylist();
    }

    return 0;
}