#include <iostream>

using namespace std;

class Field
{
    int field[3][3];
    bool draw = false;
public:
    Field()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                field[i][j] = 0;
    }

    void printField();
    void game ();
    bool checkForVictory();
};

bool Field::checkForVictory()
{
    bool allFieldIsBusy = true;
    for (int j = 0; j < 3; j++)
    {
        if (field[0][j] == field[1][j] &&
            field[1][j] == field[2][j] &&
            field[2][j] != 0)
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (field[i][0] == field[i][1] &&
            field[i][1] == field[i][2] &&
            field[i][2] != 0)
        return true;
    }

    for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++)
        {
            if (field[k][l] == 0)
            {
                allFieldIsBusy = false;
                break;
            }
        }

    if (allFieldIsBusy == true)
        draw = true;

    if (field[0][0] == field[1][1] &&
        field[1][1] == field[2][2] &&
        field[2][2] != 0)
        return true;

    if (field[0][2] == field[1][1] &&
        field[1][1] == field[2][0] &&
        field[2][0] != 0)
        return true;

    return false;
}

void Field::game ()
{
    cout << "So, let's start the game." << endl;
    int player = 1;
    while ( 1 )
    {
        int choice[2] = {0,0};
        int x = 0;
        int y = 0;
        if (player == 1)
            cout << "First player move (cross)." << endl;
        else
            cout << "Second player move (zero)." << endl;
        cout << "Enter number of row." << endl;
        cin >> x;
        cout << "Enter number of column." << endl;
        cin >> y;

        choice[0] = x - 1;
        choice[1] = y - 1;

        if (choice[0] != 0 && choice[0] != 1 && choice[0] != 2)
        {
            cout << "Incorrect value." << endl;
            continue;
        }

        if (choice[1] != 0 && choice[1] != 1 && choice[1] != 2)
        {
            cout << "Incorrect value." << endl;
            continue;
        }

        if (field[choice[0]][choice[1]] == 0)
        {
            if (player == 1)
                field[choice[0]][choice[1]] = 1;
            else
                field[choice[0]][choice[1]] = 2;
        }
        else
        {
            cout << "This place is busy." << endl;
            continue;
        }

        printField();

        if (checkForVictory() == true && player == 1)
        {
            cout << "First player (cross) won!" << '\n' << "Congratulations!" << endl;;
            break;
        }
        else if (checkForVictory() == true && player == 2)
        {
            cout << "Second player (zero) won!" << '\n' << "Congratulations!" << endl;;
            break;
        }
        else if (draw == true)
        {
            cout << "Draw." << endl;
            break;
        }
        if (player == 1)
            player = 2;
        else
            player = 1;
    }
}

void Field::printField()
{
     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 3; j++)
         {
             if (field[i][j] == 0)
                cout << ' ';
             else if (field[i][j] == 1)
                 cout << 'X';
             else if (field[i][j] == 2)
                 cout << 'O';

             if (j == 0 || j == 1)
                 cout << '|';

             if (j == 2)
             {
                cout << endl;
                if (i == 0 || i == 1)
                {
                    cout << "-----";
                    cout << endl;
                }
             }
         }
    }
}

int main()
{
    Field test;

    test.printField();
    test.game();

    return 0;
}
