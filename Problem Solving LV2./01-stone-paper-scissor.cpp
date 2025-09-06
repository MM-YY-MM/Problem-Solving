#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enStonePaperScissors { Stone = 1, Paper = 2, Scissors = 3 };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadNumberInRange(string Message, int From, int To)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <From || Number > To);
    return Number;
}

string MessageChoice(enStonePaperScissors Choice)
{
    switch (Choice)
    {
    case enStonePaperScissors::Stone:
        return "Stone";
    case enStonePaperScissors::Paper:
        return "Paper";
    case enStonePaperScissors::Scissors:
        return "Scissors";
    }
}

short ReadDigitRounds()
{
    return ReadNumberInRange("How Many Rounds 1 to 10 ? ", 1, 10);
}
 
void PrintRoundBegin(int i)
{
    cout << "\n";
    cout << "Round [" << i << "] begins: \n\n";
    cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
}

void DisplyScreenColor(string MessageRoundWinner)
{
    if (MessageRoundWinner == "[Computer]")
    {
        cout << "\a";
        system("color 4F");
    }
    else if (MessageRoundWinner == "[Player]")
        system("color 2F");
    else
        system("color 6F");
}

string IsCheckWinnerRound(enStonePaperScissors Player, enStonePaperScissors Computer)
{
    if (Computer > Player)
        return "[Computer]";

    else if (Player > Computer)
    {
        if (Player == enStonePaperScissors::Stone && Computer == enStonePaperScissors::Scissors)
            return "[Player]";

        else if (Player == enStonePaperScissors::Scissors && Computer == enStonePaperScissors::Paper)
            return "[Player]";

        else if (Player == enStonePaperScissors::Paper && Computer == enStonePaperScissors::Stone)
            return "[Player]";
        else
            return "[Computer]";
    }

    return "[No Winner]";
}

void HeaderRound(int i, enStonePaperScissors Player, enStonePaperScissors Computer)
{
    cout << "\n____________Round [" << i << "]____________\n\n";
    cout << "Player    Choice: " << MessageChoice(Player) << endl;
    cout << "Computer  Choice: " << MessageChoice(Computer) << endl;
    cout << "Round Winner    : " << IsCheckWinnerRound(Player, Computer) << endl;
    DisplyScreenColor(IsCheckWinnerRound(Player, Computer));
    cout << "_________________________________\n\n";
}

string IsCheckWinnerFinal(short CountWonPlayer, short CountWonComputer)
{
    if (CountWonPlayer > CountWonComputer)
        return "[Player]";
    else if (CountWonComputer > CountWonPlayer)
        return "[Computer]";
    else
        return "[No Winner]";
}

void HeaderGameOver(short Round, short CountWonPlayer, short CountWonComputer, short CountDraw)
{
    cout << "\n\t\t__________________________________________________\n";
    cout << "\n\t\t\t\t +++ Game Over +++ \n";
    cout << "\t\t__________________________________________________\n\n";
    cout << "\t\t__________________ [Game Results] ________________\n\n";
    cout << "\t\tGame Rounds        : " << Round << endl;
    cout << "\t\tPlayer Won times   : " << CountWonPlayer << endl;
    cout << "\t\tComputer Won times : " << CountWonComputer << endl;
    cout << "\t\tDraw times         : " << CountDraw << endl;
    cout << "\t\tFinal Winner       : " << IsCheckWinnerFinal(CountWonPlayer, CountWonComputer) << endl;
    cout << "\t\t__________________________________________________\n\n";

}

void CountWon(short& CountWonPlayer, short& CountWonComputer, short& CountDraw, string MessageRoundWinner)
{
    if (MessageRoundWinner == "[Computer]")
        CountWonComputer++;
    else if (MessageRoundWinner == "[Player]")
        CountWonPlayer++;
    else
        CountDraw++;
}

void ReadChoice(enStonePaperScissors &Player, enStonePaperScissors &Computer)
{
    short c;
    cin >> c;
    Player = (enStonePaperScissors)c;
    Computer = (enStonePaperScissors)RandomNumber(1, 3);
}

void StartGame()
{
    enStonePaperScissors Player, Computer;
    short Round = ReadDigitRounds();
    short CountWonPlayer = 0, CountWonComputer = 0, CountDraw = 0;
    for (int i = 1; i <= Round; i++)
    {
        PrintRoundBegin(i);
        ReadChoice(Player, Computer);

        HeaderRound(i, Player, Computer);
        CountWon(CountWonPlayer, CountWonComputer, CountDraw, IsCheckWinnerRound(Player, Computer));
    }

    HeaderGameOver(Round, CountWonPlayer, CountWonComputer, CountDraw);
}

void ResetScreen()
{
    char Add = '0';
    
    do
    {

        cout << "\t\tDo You Wnat to Play Again? Y/N? ";
        cin >> Add;

        if ((Add == 'Y' || Add == 'y'))
        {
            system("cls");
            system("color 07");
            StartGame();
        }
        else
            cout << endl;

    } while ((Add == 'Y' || Add == 'y'));
    
}

int main()
{
    srand((unsigned)time(NULL));


    StartGame();
    ResetScreen();

    return 0;
}