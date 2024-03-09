#include <iostream>
#include <string>
using namespace std;

class MusicPlaylist
{
private:
    string tracks[20];
    string currentMusic;

public:
    MusicPlaylist()
    {
        for (int i = 0; i < 20; i++)
        {
            tracks[i] = "";
        }
        currentMusic = "";
    }

    void add(string musicName)
    {
        for (int i = 0; i < 20; i++)
        {
            if (tracks[i] == "")
            {
                tracks[i] = musicName;
                break;
            }
        }
    }

    void setCurrentTrack(int num)
    {
        currentMusic = tracks[num - 1];
    }

    string play()
    {
        return currentMusic;
    }
};

int main()
{
    MusicPlaylist mp;
    mp.add("Shape of You");
    mp.add("That's What I Like");
    mp.add("Humble");
    mp.setCurrentTrack(2);
    cout << mp.play() << endl; // แสดงเพลงลำดับที่ 1 คือ Shape of You
}