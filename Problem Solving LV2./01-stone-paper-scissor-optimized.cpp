#include <iostream>
#include <cstdlib>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice ChoicePlayer = enGameChoice::Scissors;
    enGameChoice ChoiceComputer = enGameChoice::Scissors;
    enWinner Winner = enWinner::Draw;
    string NameWinner = "";
};

struct stGameResult
{
    short GameRounds = 0;
    short PlayerWonTimes = 0;
    short ComputerWonTimes = 0;
    short Draw = 0;
    enWinner Winner = enWinner::Computer;
    string NameWinner = "";
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short HowManyRound()
{
    short Round = 1;
    do
    {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> Round;
    } while (Round < 1 || Round > 10);
    return Round;
}

string NameChoice(enGameChoice GameChoice)
{
    string NameChoice[3] = { "Stone","Paper","Scissors" };
    return NameChoice[GameChoice - 1];
}

void DisplyScreenColor(enWinner NameWinner)
{
    switch (NameWinner)
    {
    case enWinner::Player:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        cout << "\a";
        break;
    default:
        system("color 6F");

        break;
    }
}

void PrintResultTheRound(stRoundInfo RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player   Choice: " << NameChoice(RoundInfo.ChoicePlayer) << endl;
    cout << "Computer Choice: " << NameChoice(RoundInfo.ChoiceComputer) << endl;
    cout << "Round Winner   : [" << RoundInfo.NameWinner << "]\n";
    cout << "_________________________________________\n" << endl;

    DisplyScreenColor(RoundInfo.Winner);
}

string Tabs(short NumberOfTabs)
{
    string Tab = "";
    for (short i = 1; i <= NumberOfTabs; i++)
    {
        Tab += "\t";
    }
    return Tab;
}

void ShowGameOver()
{
    cout << "\n" << Tabs(3) << "__________________________________________________\n";
    cout << "\n" << Tabs(3) << "                 +++ Game Over +++ \n";
    cout  << Tabs(3) << "__________________________________________________\n\n";
}

void ShowResultTheGame(stGameResult GameResult)
{
    cout << Tabs(3) << "__________________ [Game Results] ________________\n\n";
    cout << Tabs(3) << "Game Rounds : " << GameResult.GameRounds << endl;
    cout << Tabs(3) << "Player Won times : " << GameResult.PlayerWonTimes << endl;
    cout << Tabs(3) << "Computer Won times : " << GameResult.ComputerWonTimes << endl;
    cout << Tabs(3) << "Draw times : " << GameResult.Draw << endl;
    cout << Tabs(3) << "Final Winner : " << GameResult.NameWinner << endl;
    cout << Tabs(3) << "__________________________________________________\n\n";

    DisplyScreenColor(GameResult.Winner);
}

enGameChoice ReadChoicePlayer()
{
    short Choice = 1;
    do
    {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

enGameChoice GetChoiceComputer()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner WonWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.ChoicePlayer == RoundInfo.ChoiceComputer)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.ChoicePlayer)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ChoiceComputer == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ChoiceComputer == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ChoiceComputer == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;
    }

    return enWinner::Player;
}

string NameWinner(enWinner Winner)
{
    string NameWinner[3] = { "Player","Computer","Draw" };
    return NameWinner[Winner - 1];
}

enWinner WonWonTheGame(stGameResult GameResult)
{
    if (GameResult.PlayerWonTimes > GameResult.ComputerWonTimes)
        return enWinner::Player;
    else if (GameResult.ComputerWonTimes > GameResult.PlayerWonTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResult FillGameResults(short Round, short PlayerWonTimes, short ComputerWonTimes, short Draw)
{
    stGameResult GameResult;

    GameResult.GameRounds = Round;
    GameResult.PlayerWonTimes = PlayerWonTimes ;
    GameResult.ComputerWonTimes = ComputerWonTimes;
    GameResult.Draw = Draw;
    GameResult.Winner = WonWonTheGame(GameResult);
    GameResult.NameWinner = NameWinner(GameResult.Winner);

    return GameResult;
}

stGameResult PlayGame(short HowManyRound)
{
    stRoundInfo RoundInfo;
    short PlayerWonTimes = 0, ComputerWonTimes = 0, Draw = 0;

    for (short GameRound = 1; GameRound <= HowManyRound; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.ChoicePlayer = ReadChoicePlayer();
        RoundInfo.ChoiceComputer = GetChoiceComputer();
        RoundInfo.Winner = WonWonTheRound(RoundInfo);
        RoundInfo.NameWinner = NameWinner(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Computer)
            ComputerWonTimes++;
        else if (RoundInfo.Winner == enWinner::Player)
            PlayerWonTimes++;
        else
            Draw++;

        PrintResultTheRound(RoundInfo);
    }

    return FillGameResults(HowManyRound, PlayerWonTimes, ComputerWonTimes, Draw);
}

void ResetScreen()
{
    system("cls");
    system("color 07");
}

void StartGame()
{
    char Again = 'Y';
    do
    {
        ResetScreen();
        stGameResult GameResult = PlayGame(HowManyRound());
        ShowGameOver();
        ShowResultTheGame(GameResult);
        cout << Tabs(3) << "Do you want to play again? Y/N? ";
        cin >> Again;
    } while (Again == 'Y' || Again == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
} 