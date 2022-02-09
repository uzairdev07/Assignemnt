#include "Player.h"

/** Default Constructor */
Player::Player()
    : name{"untitled*"}, average{0}, team{"pakistan"}
{
    showMenu();
}

/** Overloading Constructor */
Player::Player(string name, float avg, string team)
    : name{name}, average{avg}, team{team}
{
}

/** Show Menu */
void Player::showMenu()
{
    int op{};
    cout << setw(50) << "*** Player Project ***" << endl
        << endl;
    cout << setw(20) << "Menu: " << endl;
    cout << setw(20) << "1 - Add Players" << endl;
    cout << setw(20) << "2 - Display Players" << endl;
    cout << setw(20) << "3 - Change Players Profile" << endl;
    cout << setw(20) << "4 - Exit" << endl;
    cout << "*** Select => ";
show:
    cin >> op;
    switch (op)
    {
    case 1:
        input();
        break;
    case 2:
        display();
        break;
    case 3:
        change();
        break;
    case 4:
        system("exit");
        break;
    default:
        cerr << "Invalid Input!" << endl;
        goto show;
    }
}

/** Input Player */
void Player::input()
{
    int size{};
    cout << "Enter no. of player => ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter average (0 -> 100): ";
        cin >> average;
        cout << "Enter team (Pakistan || India): ";
        cin >> team;
        cout << endl;
        Player temp(name, average, team);
        players.push_back(temp);
    }
    cout << "Entered Successfully" << endl;
    clear();
}

/** Display Player */
void Player::display()
{
    int m{};
    if (players.size() != 0)
    {
        cout << setw(15) << "Name"
            << setw(15) << "Avg"
            << setw(15) << "Team" << endl;
        for (auto each : players)
            cout << setw(15) << each.name
                << setw(15) << each.average
                << setw(15) << each.team << endl;
    }
    else
    {
        cerr << setw(50) << "No Contacts to Display!" << endl;
    again:
        cout << "Press 1 for Menu => ";
        cin >> m;
        if (m == 1)
        {
            clear();
            goto menu;
        }
        else
        {
            cerr << "Invalid Input!" << endl;
            goto again;
        }
    }
a:
    cout << "Press 1 for Menu => ";
    cin >> m;
    if (m == 1)
    {
        clear();
        goto menu;
    }
    else
    {
        cerr << "Invalid Input!" << endl;
        goto a;
    }
menu:
    showMenu();
}

/** Change Player Profile */
void Player::change()
{
    int option, index;
    string name, team;
    float avg;
    cout << setw(15) << "Name"
        << setw(15) << "Avg"
        << setw(15) << "Team" << endl;
    for (auto each : players)
        cout << setw(15) << each.name
            << setw(15) << each.average
            << setw(15) << each.team << endl;
    cout << "Enter positon: ";
    cin >> index;
    cout << setw(20) << "*** Select Options to Change Player Profile ***" << endl;
    cout << setw(20) << "1 - Name" << endl
        << setw(20) << "2 - Avergae" << endl
        << setw(20) << "3 - Team" << endl
        << setw(20) << "4 - All" << endl;
again:
    cout << " ** Select => ";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "Enter Name of the Player: ";
        cin >> name;
        players[index - 1].name = name;
        break;
    case 2:
        cout << "Enter Average of the Player: ";
        cin >> avg;
        players[index - 1].average = avg;
        break;
    case 3:
        cout << "Enter Team of the Player: ";
        cin >> team;
        players[index - 1].team = team;
        break;
    case 4:
        cout << "Enter Name of the Player: ";
        cin >> name;
        players[index - 1].name = name;
        cout << "Enter Average of the Player: ";
        cin >> avg;
        players[index - 1].average = avg;
        cout << "Enter Team of the Player: ";
        cin >> team;
        players[index - 1].team = team;
        break;
    default:
        cerr << "Invalid Input! input only 1, 2 or 3...";
        goto again;
    }
    clear();
}

/** Clear Screen */
void Player::clear()
{
    // If linux
    system("clear");
    // If window
    //    system("cls");
    showMenu();
}

/** Destructor */
Player::~Player()
{
}
