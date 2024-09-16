#include <iostream>
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;
void setcolorandbackground(int textc, int backg)
{ // with this we can set text color and background color
    WORD color = ((backg & 0x0F) << 4) + (textc & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

class welcome
{
public:
    void welpage()
    {
        cout << endl
             << endl;
        setcolorandbackground(2, 0);
        cout << "------------------------------------------------------" << endl;
        cout << "|=================== DISCLAIMER =====================|" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "|                                                    |" << endl;
        cout << "|                                                    |" << endl;
        cout << "|      2022 Hand Cricket All Rights Reserved         |" << endl;
        cout << "|                                                    |" << endl;
        cout << "|                                                    |" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << endl
             << endl;
        cout << "Press Enter To Continue ";
        getchar();
        system("CLS");
    }
};
class gamemenu
{
public:
    void menu()
    {

        setcolorandbackground(14, 0);
        cout << "------------------------------------------------------" << endl;
        cout << "|===================GameMenu===================|" << endl;
        setcolorandbackground(5, 0);
        cout << "------------------------------------------------------" << endl;
        cout << "|   1. Play Now                                      |" << endl;
        cout << "|   2. How To Play                                   |" << endl;
        cout << "|   3. Credits                                       |" << endl;
        cout << "|   4. Exit                                          |" << endl;
        cout << "|                                                    |" << endl;
        cout << "------------------------------------------------------" << endl;
        setcolorandbackground(15, 0);
    }
};
class PlayNow
{
public:
    void gamechoose()
    {
        setcolorandbackground(12, 0);
        cout << "------------------------------------------------------" << endl;
        cout << "|=============Choose Your GameMode===========|" << endl;
        setcolorandbackground(4, 0);
        cout << "------------------------------------------------------" << endl;
        cout << "|   1. PvE                                           |" << endl;
        cout << "|   2. Run Multiplier                                |" << endl;
        cout << "|   3. Back                                          |" << endl;
        cout << "|                                                    |" << endl;
        cout << "------------------------------------------------------" << endl;
    }
};
class pve
{
public:
    bool toss()
    { // returns if the player has won the toss or not
        char choice;
        int t, c;

        setcolorandbackground(12, 0);
        cout << "\n================================================="<<endl;
        cout << "|                                                 |"<<endl;
        cout << "|              It's Toss time!!                   |"<<endl;
        cout << "|                                                 |"<<endl;
        cout << "==================================================="<<endl;

        B:
        setcolorandbackground(6, 0);
        cout << "====================================================="<<endl;
        cout << "|                                                   |"<<endl;
        cout << "|    Choose your call:\t1. Heads or 2. Tails:       |"<<endl;
        cout << "|                                                   |"<<endl;
        cout << "====================================================="<<endl;
        cin >> choice;
        if ((choice == 'h' || choice == 'H' || choice == '1'))
            c = 1;
        else if ((choice == 't' || choice == 'T' || choice == '2'))
            c = 2;
        srand(time(0));
        t = rand() % 2 + 1;
        if ((t == 1 && c == 1) || (t == 2 && c == 2))
        {
            setcolorandbackground(2, 0);
            cout<<"\n";
            cout << "\n\n********************\tCongratulations!! :) You've won the Toss\t********************" << endl;
            cout<<"\n\n";
            return true;
        }
        else if((t == 1 && c == 2) || (t == 2 && c == 1))
        {
            setcolorandbackground(8, 0);
            cout<<"\n";
            cout << "\n\n\t********************\tSorry! :( You've lost the Toss\t********************" << endl;
            cout<<"\n\n";
            return false;
        }
        else{

            cout<<"Wrong input...."<<endl;
            goto B;
        }
    }

    int player()
    { // asks player to enter his score/choice
        int res;
        setcolorandbackground(6, 0);
        cout << "\n\tChoose a number between 1 and 6: ";
        while (1)
        {
            cin >> res;
            if (res > 6 || res < 1)
            {

                cout << "\tPlease select a number between 1 and 6: ";
                continue;
            }
            else
                break;
        }
        return res;
    }

    int comp()
    { // generates random number between 1 and 6
        int res;
        res = rand() % 6 + 1;
        setcolorandbackground(3, 0);
        cout << "\n\tYour opponent's choice is: " << res << endl;
        return res;
    }

    void start_game()
    {
        setcolorandbackground(6, 0);
        cout << "..........................................."<<endl;
        cout << "|              GAME STARTS!!!             |";
        cout << "\n..........................................."<<endl;
        int choice, overs, balls, player_score = 0, comp_score = 0, b = 0, t1, t2, first = 0, second = 0; // first is first innings score
        // second is second innings score; t1,t2 are scores scored for each ball
        string bat, bowl; // used to store which one is batting and who is bowling
        setcolorandbackground(3, 0);
        cout << "\n----------------------------------------------------"<<endl;
        cout << "|         Which format you would like to play?       |"<<endl;
        cout << "|1. 1 Over Match   2. 2 Over Match   3. 3 Over Match |"<<endl;
        cout << "------------------------------------------------------"<<endl;
        cout <<"\nEnter your choice:";
        cin >> overs;
        while (1)
        { // calculate total number of balls in an innings based on match format
            if (overs == 1)
            {
                balls = 6;
                break;
            }
            else if (overs == 2)
            {
                balls = 12;
                break;
            }
            else if (overs == 3)
            {
                balls = 18;
                break;
            }
            else
            {

                cout << "\n\tPlease select a valid format!";
                continue;
            }
        }
        bool tossres = toss(), out = false;
        if (tossres)
        { // based on toss result player gets to choose his choice
            cout << "\n\tSelect your choice:\n\t1.Batting\t\t2.Bowling\n\t\n";
            cin >> choice;
            if (choice == 1)
            {
                bat = "player";
                bowl = "comp";
            }
            else
            {
                bat = "comp";
                bowl = "player";
            }
        }
        else
        {
            choice = rand() % 2 + 1;
            if (choice == 1)
            {
                setcolorandbackground(5,0);
                cout<<"\n---------------------------------------------"<<endl;
                cout<<"|      Your opponent chose to Bat first!       |"<<endl;
                cout<<"---------------------------------------------"<<endl;
                bat = "comp";
                bowl = "player";
            }
            else
            {
                setcolorandbackground(9,0);
                cout<<"\n---------------------------------------------"<<endl;
                cout<<"|      Your opponent chose to Bowl first!     |";
                cout<<"\n---------------------------------------------"<<endl;
                bat = "player";
                bowl = "comp";
            }
        }

        cout << "\n\n\t\t\t\t";

        cout << "FIRST INNINGS";

        if (bat == "player"){
            setcolorandbackground(6,0);
            cout << "\n\n|---------------------------------You are Batting---------------------------------|";}
        else{
            setcolorandbackground(7,0);
            cout << "\n\n|---------------------------------You are Bowling---------------------------------|";}
        while ((!out) && (b < balls))
        { // First Innings
            t1 = player();
            t2 = comp();
            if (t1 == t2)
            {
                out = true;
                setcolorandbackground(4, 0);
                cout<<"\n\n";
                cout << "*********   *       *  **************   | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*********   *********        *          O" << endl;
            }
            else
            {
                if (bat == "player")
                    {player_score += t1;
                    setcolorandbackground(8,0);

                    cout<<"|     Your Score-"<<player_score<<"     |"<<endl;
                    }
                else
                    {comp_score += t2;
                    setcolorandbackground(6,0);

                    cout<<"|      Computer Score-"<<comp_score<<"   |"<<endl;

                    }
            }
            b++;
        }
        // Before second innings need to change bat and bowl
        if (bat == "player")
        {
            bat = "comp";
            bowl = "player";
            first = player_score;
            setcolorandbackground(8, 0);
            cout << "\n=========================================================================================="<<endl;

            cout << "                        First Innings Ended!!\n                                          "<<endl;

            cout << "                       Your Score is " << first <<"                                      ";

            cout << " \n==========================================================================================="<<endl;
            cout<<"\n\n";
            setcolorandbackground(4, 0);
            cout << " *******************************SECOND INNINGS**********************************************"<<endl;
            cout<<"\n\n";
            setcolorandbackground(6,0);
            cout << " ==========================================================================================="<<endl;
            cout << " |                            You are Bowling Now!!                                        |"<<endl;
            cout << " ==========================================================================================="<<endl;
        }
        else
        {
            bowl = "comp";
            bat = "player";
            first = comp_score;
            setcolorandbackground(5, 0);
            cout << "\n=========================================================================================="<<endl;
            setcolorandbackground(7,0);
            cout << "|                              First Innings Ended!!                                       |"<<endl;

            cout << "\n|                       Your Opponent's Score is " << first <<"                          |"<<endl;

            cout << "===========================================================================================|"<<endl;
            setcolorandbackground(9,0);
            cout<<"....................................................................................."<<endl;
            cout<<"|                                SECOND INNINGS                                     |"<<endl;
            cout<<"....................................................................................."<<endl;
            setcolorandbackground(4,0);
            cout<<"============================================================================================"<<endl;
            cout<<"|----------------------------------You are Batting Now-------------------------------------|"<<endl;
            cout<<"============================================================================================"<<endl;
        }
        out = false;
        b = 0;

        while ((!out) && (b < balls) && (second <= first))
        { // Second Innings
            t1 = player();
            t2 = comp();
            if (t1 == t2)
            {
                out = true;
                setcolorandbackground(4, 0);
                cout<<"\n\n";
                cout << "*********   *       *  **************   | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*********   *********        *          O" << endl;
            }
            else
            {
                if (bat == "player")
                {
                    player_score += t1;
                    second += t1;
                    setcolorandbackground(4,0);
                    cout<<"                           "<<endl;
                    cout<<"       Score-"<<second<<" "<<endl;

                }
                else
                {
                    comp_score += t2;
                    second += t2;
                    setcolorandbackground(7,0);
                    cout<<"                           "<<endl;
                    cout<<" computerScore-"<<second<<" "<<endl;

                }
            }
            b++;
        }
        if (bat == "player")
        {
            setcolorandbackground(5, 0);
            cout << "\n=========================================================================================="<<endl;

            cout << "|                        Second Innings Ended!!                                            |"<<endl;

            cout << "|                    Your Score is " << second <<"                                                    |"<<endl;
            cout << "============================================================================================"<<endl;


            cout << "\n\n";
            setcolorandbackground(10, 0);
            cout << "===================================="<<endl;
            cout << "|             RESULT               |"<<endl;
            cout << "=================================="<<endl;
            if (first > second)
            {
                setcolorandbackground(9, 0);
                cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
                cout<<"/                         You lost!!                                /"<<endl;
                cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
            }
            else if (first == second)
            {
                setcolorandbackground(1, 0);
                cout << "=============================================="<<endl;
                cout << "|                 Match Draw!!               |"<<endl;
                cout << "=============================================="<<endl;
            }
            else
            {

                setcolorandbackground(8, 0);
                cout << "++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout << "$                 You Won!!                    $"<<endl;
                cout << "++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

            }

            }

        else
        {
            setcolorandbackground(3,0);
            cout<<"::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":        Second Innings Ended!!      :"<<endl;
            cout<<"::::::::::::::::::::::::::::::::::::::"<<endl;
            setcolorandbackground(5,0);
            cout<<"::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":   Your Opponent's Score is "<<second<<"            :"<<endl;
            cout<<"::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"\n\n"<<endl;
            setcolorandbackground(2,0);
            cout<<"------------------------"<<endl;
            cout<<"|        RESULT        |"<<endl;
            cout<<"------------------------"<<endl;
            if (first > second)
            {
                setcolorandbackground(7, 0);
                cout << "++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout << "$                 You Won!!                    $"<<endl;
                cout << "++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            }
            else if (first == second)
            {
                setcolorandbackground(14, 0);
                cout << "=============================================="<<endl;
                cout << "|                 Match Draw!!               |"<<endl;
                cout << "=============================================="<<endl;
            }
            else
            {
                setcolorandbackground(12, 0);
                cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
                cout<<"/                         You lost!!                                /"<<endl;
                cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
            }
        }


        cout << "\n\n\t" << endl;

        getchar();
    }
};
class RunM
{
public:
    bool toss2()
    { // returns if the player has won the toss or not
        char choice;
        int t, c;
        setcolorandbackground(12, 0);
        cout << "\n==================================================="<<endl;
        cout << "|                                                 |"<<endl;
        cout << "|              It's Toss time!!                   |"<<endl;
        cout << "|                                                 |"<<endl;
        cout << "==================================================="<<endl;
        setcolorandbackground(6, 0);
        cout << "====================================================="<<endl;
        cout << "|                                                   |"<<endl;
        cout << "|    Choose your call:\t1. Heads or 2. Tails:       |"<<endl;
        cout << "|                                                   |"<<endl;
        cout << "====================================================="<<endl;
        cin >> choice;
        if ((choice == 'h' || choice == 'H' || choice == '1'))
            c = 1;
        else if ((choice == 't' || choice == 'T' || choice == '2'))
            c = 2;
        srand(time(0));
        t = rand() % 2 + 1;
        if ((t == 1 && c == 1) || (t == 2 && c == 2))
        {

            cout << "\n\n|*******************\tCongratulations!! :) You've won the Toss\t********************|" << endl;
            return true;
        }
        else
        {

            cout << "\n\n\t|********************\tSorry! :( You've lost the Toss\t********************|" << endl;
            return false;
        }
    }

    int player2()
    { // asks player to enter his score/choice
        int res;

        cout << "\n\tChoose a number between 1 and 10: ";
        while (1)
        {
            cin >> res;
            if (res > 10 || res < 1)
            {
                setcolorandbackground(4,0);
                cout << "\tPlease select a number between 1 and 10: ";
                continue;
            }
            else
                break;
        }
        return res;
    }

    int comp2()
    { // generates random number between 1 and 10
        int res;
        res = rand() % 10 + 1;
        setcolorandbackground(3,0);
        cout << "\n\tYour opponent's choice is: " << res << endl;
        return res;
    }

    void start_game2()
    {

        setcolorandbackground(2, 0);
        cout<<"==========================================================================================="<<endl;
        cout<<"|                                                                                         |"<<endl;
        cout<<"|                                      GAME STARTS!!                                      |"<<endl;
        cout<<"|                              WELCOME TO RUN MULTIPLIER GAME                             |"<<endl;
        cout<<"|                                                                                         |"<<endl;
        cout<< "=========================================================================================="<<endl;

        int choice, overs, balls, player_score = 0, comp_score = 0, b = 0, t1, t2, first = 0, second = 0; // first is first innings score
        // second is second innings score; t1,t2 are scores scored for each ball
        string bat, bowl; // used to store which one is batting and who is bowling
        setcolorandbackground(3, 0);
        cout << "\n----------------------------------------------------"<<endl;
        cout << "|         Which format you would like to play?       |"<<endl;
        cout << "|1. 1 Over Match   2. 2 Over Match   3. 3 Over Match |"<<endl;
        cout << "------------------------------------------------------"<<endl;
        cout <<"\nEnter your choice:";
        cin >> overs;
        cout << "======================================================"<<endl;
        while (1)
        { // calculate total number of balls in an innings based on match format
            if (overs == 1)
            {
                balls = 6;
                break;
            }
            else if (overs == 2)
            {
                balls = 12;
                break;
            }
            else if (overs == 3)
            {
                balls = 18;
                break;
            }
            else
            {
                setcolorandbackground(2, 0);
                cout << "\n\tPlease select a valid format!";
                continue;
            }
        }
        bool tossres2 = toss2(), out = false;
        if (tossres2)
        { // based on toss result player gets to choose his choice
            cout << "\n\tSelect your choice:\n\t1.Batting\t\t2.Bowling\n\t\n";
            cin >> choice;
            if (choice == 1)
            {
                bat = "player";
                bowl = "comp";
            }
            else
            {
                bat = "comp";
                bowl = "player";
            }
        }
        else
        {
            choice = rand() % 2 + 1;
            if (choice == 1)
            {
                setcolorandbackground(5,0);
                cout<<"\n---------------------------------------------"<<endl;
                cout<<"|      Your opponent chose to Bat first!       |";
                cout<<"\n---------------------------------------------"<<endl;
                bat = "comp";
                bowl = "player";
            }
            else
            {
                setcolorandbackground(5,0);
                cout<<"\n---------------------------------------------"<<endl;
                cout<<"|      Your opponent chose to Bowl first!      |";
                cout<<"\n---------------------------------------------"<<endl;
                bat = "player";
                bowl = "comp";
            }
        }

        cout << "\n\n\t\t\t\t";
        setcolorandbackground(3,0);
        cout << "******FIRST INNINGS********";

        if (bat == "player"){
            setcolorandbackground(11,0);
            cout << "\n\n|---------------------------------You are Batting---------------------------------|"<<endl;}
        else{
            setcolorandbackground(4,0);
            cout << "\n\n|---------------------------------You are Bowling---------------------------------|";}
        while ((!out) && (b < balls))
        { // First Innings
            t1 = player2();
            t2 = comp2();
            if (t1 == t2)
            {
                if (bat == "player")
                    {player_score += t1 * t1;
                    setcolorandbackground(9,0);

                    cout<<"| Your Score-"<<player_score<<" |"<<endl;

                    }
                else
                    {comp_score += t2 * t2;
                    setcolorandbackground(2,0);

                    cout<<"|Computer Score-"<<comp_score<<" |"<<endl;

                    }
            }
            else
            {
                if ((t1 - t2) == 1 || (t2 - t1) == 1)
                {
                    out = true;

                     setcolorandbackground(4, 0);

                cout << "*********   *       *  **************   | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*********   *********        *          O" << endl;
                }
                if (t1 == 10 && t2 == 1)
                {
                    out = true;

                    setcolorandbackground(4, 0);

                cout << "*********   *       *  **************   | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*********   *********        *          O" << endl;
                }
                if (t1 == 1 && t2 == 10)
                {
                    out = true;

                     setcolorandbackground(4, 0);

                cout << "*********   *       *  **************   | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*********   *********        *          O" << endl;
                }
                if (out == false)
                {
                    if (bat == "player")
                        {player_score += t1;
                        setcolorandbackground(2,0);

                    cout<<"|Your Score-"<<player_score<<" |"<<endl;

                        }
                    else
                        {comp_score += t2;
                        setcolorandbackground(6,0);
                    ;
                    cout<<"|Your Score-"<<comp_score<<"|"<<endl;

                    }
                }
            }
            b++;
        }
        // Before second innings need to change bat and bowl
        if (bat == "player")
        {
            bat = "comp";
            bowl = "player";
            first = player_score;
            setcolorandbackground(8,0);
            cout << "==========================================================================================="<<endl;
            cout << "|                             First Innings Ended!!                                       |"<<endl;
            cout << "|                           Your Score is " << first <<"                                              |"<<endl;
            cout << "==========================================================================================="<<endl;
            setcolorandbackground(4,0);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout << "~                       ~"<<endl;
            cout << "~     SECOND INNINGS    ~"<<endl;
            cout << "~                       ~"<<endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            setcolorandbackground(8,0);
            cout << "\n\n|---------------------------------You are Bowling Now!!---------------------------------|"<<endl;
        }
        else
        {
            bowl = "comp";
            bat = "player";
            first = comp_score;
            setcolorandbackground(11,0);
            cout << "==========================================================================================="<<endl;
            cout << "|                             First Innings Ended!!                                       |"<<endl;
            cout << "|                        OPPONENT'S Score is " << first <<"                                           |"<<endl;
            cout << "==========================================================================================="<<endl;

            cout << "\n\n";
            setcolorandbackground(4,0);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout << "~                       ~"<<endl;
            cout << "~     SECOND INNINGS    ~"<<endl;
            cout << "~                       ~"<<endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            setcolorandbackground(8,0);

            cout << "\n\n|---------------------------------You are Batting Now!!---------------------------------|"<<endl;
        }
        out = false;
        b = 0;

        while ((!out) && (b < balls)&&(second <= first))
        { // Second Innings
            t1 = player2();
            t2 = comp2();
            if (t1 == t2)
            {
                if (bat == "player")
                {
                    player_score += t1 * t1;
                    second += t1 * t1;
                    setcolorandbackground(7,0);

                    cout<<"|Your Score-"<<second<<" |"<<endl;

                }
                else
                {
                    comp_score += t2 * t2;
                    second += t2 * t2;
                    setcolorandbackground(9,0);

                    cout<<"|Computer Score-"<<second<<"|"<<endl;



                }
            }
            else
            {
                if ((t1 - t2) == 1 || (t2 - t1) == 1)
                {
                    out = true;

                     setcolorandbackground(4, 0);

                cout << "*********   *       *  **************   | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*********   *********        *          O" << endl;
                }
                if (t1 == 10 && t2 == 1)
                {
                    out = true;

                     setcolorandbackground(4, 0);

                cout << "*********   *       *  **************   | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*********   *********        *          O" << endl;
                }
                if (t1 == 1 && t2 == 10)
                {
                    out = true;

                     setcolorandbackground(4, 0);

                cout << "*********   *       *  **************   | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*       *   *       *        *          | " << endl;
                cout << "*       *   *       *        *          |" << endl;
                cout << "*********   *********        *          O" << endl;
                }
                if (out == false)
                {
                    if (bat == "player")
                    {
                        player_score += t1;
                        second += t1;
                        setcolorandbackground(5,0);

                    cout<<"|Your Score-"<<second<<"|"<<endl;


                    }
                    else
                    {
                        comp_score += t2;
                        second += t2;
                        setcolorandbackground(7,0);

                    cout<<"|Computer Score-"<<second<<"|"<<endl;


                    }
                }
            }
            b++;
        }
        if (bat == "player")
        {
            setcolorandbackground(3,0);
            cout<<"::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":        Second Innings Ended!!      :"<<endl;
            cout<<"::::::::::::::::::::::::::::::::::::::"<<endl;
            setcolorandbackground(5,0);
            cout<<"::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":   Your Score is "<<second<<"                        :"<<endl;
            cout<<"::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"\n\n"<<endl;
            setcolorandbackground(2,0);
            cout<<"-----------------------"<<endl;
            cout<<"|      RESULT         |"<<endl;
            cout<<"-----------------------"<<endl;

            if (first > second)
            {
                setcolorandbackground(12, 0);
                cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
                cout<<"/                       You lost!!                                 /"<<endl;
                cout<<"///////////////////////////////////////////////////////////////////"<<endl;

            }
            else if (first == second)
            {
                setcolorandbackground(14, 0);
                cout << "=============================================="<<endl;
                cout << "|                 Match Draw!!               |"<<endl;
                cout << "=============================================="<<endl;

            }
            else
            {
                setcolorandbackground(7, 0);
                cout << "++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout << "$                 You Won!!                    $"<<endl;
                cout << "++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

            }
        }
        else
        {
            setcolorandbackground(3,0);
            cout<<"::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":        Second Innings Ended!!      :"<<endl;
            cout<<"::::::::::::::::::::::::::::::::::::::"<<endl;
            setcolorandbackground(5,0);
            cout<<"::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<":   Your  Opponent Score is "<<second<<"            :"<<endl;
            cout<<"::::::::::::::::::::::::::::::::::::::::::::"<<endl;
            cout<<"\n\n"<<endl;
            setcolorandbackground(2,0);
            cout<<"-----------------------"<<endl;
            cout<<"|       RESULT        |"<<endl;
            cout<<"-----------------------"<<endl;

            if (first > second)
            {
                setcolorandbackground(7, 0);
                cout << "++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                cout << "$                 You Won!!                    $"<<endl;
                cout << "++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

            }
            else if (first == second)
            {
                setcolorandbackground(14, 0);
                cout << "=============================================="<<endl;
                cout << "|                 Match Draw!!               |"<<endl;
                cout << "=============================================="<<endl;
            }
            else
            {
                setcolorandbackground(12, 0);
                cout<<"/////////////////////////////////////////////////////////////////////"<<endl;
                cout<<"/                         You lost!!                                /"<<endl;
                cout<<"////////////////////////////////////////////////////////////////////"<<endl;

            }
        }

        cout << "\n\n======================================================================="<<endl;

        cout << "\n\n\tPress '0' to go back to main menu....";
        getchar();
    }
};

class HowToPlay
{

public:
    void how()
    {
        setcolorandbackground(4, 0);
        cout << "========PvE=======" << endl;
        setcolorandbackground(11, 0);
        cout << "-> Both The  player and computer will enter number between 1 to 6. " << endl;
        cout << "-> If batting Player enters number different than the computer, Then the number adds upto the score!" << endl;
        cout << "-> If both the numbers entered are same, then the batting player gets out!" << endl;
        cout << "-> If batting second, when your score reaches above the computer, You will win the game!  " << endl;
        cout << "-> Else you will lose the game! " << endl<<endl;

        setcolorandbackground(4, 0);
        cout << "========RUN MULTIPLIER=======" << endl;
          setcolorandbackground(11, 0);
        cout<<"The Game is almost same as PVE!"<<endl;
        cout<<"If the number entered by the batsman is equal to the bowler... Then the number gets multiplied by itslef and adds upto the score!"<<endl;
        cout<<"The batsman gets out when the difference in the number enetered by the both players is 1!"<<endl;
        setcolorandbackground(12,0);
        getchar();

    }
};
class Credits
{

public:
    void cred()
    {
        cout << "Coded and Tested by  " << endl;
        setcolorandbackground(14, 0);
        cout << " SAMAY THUSOO " << endl;
        getchar();

    }
};

int main()
{

    welcome w1;
    w1.welpage();

A:
    int choice;
    gamemenu w;
    w.menu();
    cin >> choice;
     system("CLS");
    if (choice == 1)

    {
        int c2;
        PlayNow p;

        p.gamechoose();
        cout << endl;
        cout << "Give Your Choice :  " << endl;
        cin >> c2;
         system("CLS");
        if (c2 == 1)
        {
            pve pl;
            pl.start_game();
            getchar();
              system("CLS");
            goto A;
        }
        else if (c2 == 2)
        {
            RunM r1;
            r1.start_game2();
            getchar();
            system("CLS");
            goto A;
        }
        else
        {
            goto A;
        }
    }

    else if (choice == 2)
    {
        HowToPlay h;
        h.how();

        getchar();
        system("CLS");

        goto A;
    }
    else if (choice == 3)
    {
        Credits c;
        c.cred();
        getchar();
          system("CLS");
        goto A;
    }
    else
    {
        setcolorandbackground(2, 0);
        cout << "Thanks for Playing! " << endl;
        exit(0);
    }

    return 0;
}
