#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Player
{
private:
    /** Attributes */
    string name;
    float average;
    string team;

    vector<Player> players;

public:
    /** Default constructor */
    Player();
    /** Overloading Constructor with args */
    Player(string name, float avg, string team);

    /** Member Methods */
    void showMenu();
    void clear();
    void input();
    void display();
    void change();

    /** Default destructor */
    ~Player();
};

#endif // PLAYER_H