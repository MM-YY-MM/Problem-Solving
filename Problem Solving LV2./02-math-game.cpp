#include <iostream>
#include <cstdlib>

using namespace std;

enum enLevelQuiz { Easy = 1, Med = 2, Hard = 3, MixLvl = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixType = 5 };
enum enPassFail { Pass = 1, Fail = 2 };

struct stGameQuiz
{
    short NumberQuiz = 0;
    enLevelQuiz LevelQuiz = enLevelQuiz::Easy;
    enOperationType ChoiceOperationType = enOperationType::Add;
    char OpType = '0';
    short Number1 = 0;
    short Number2 = 0;
    short SumNum1Num2 = 0;
};

struct stGameResult
{
    short NumberOfQuestions = 0;
    enLevelQuiz QuestionsLevel = enLevelQuiz::Easy;
    enOperationType OperationType = enOperationType::Add;
    string  NameQuestionsLevel = "";
    string  NameOperationType = "";
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
};

void DisplyScreenColor(enPassFail PassFail)
{
    switch (PassFail)
    {
    case enPassFail::Pass:
        system("color 2F");
        break;
    default:
        system("color 4F");
        cout << "\a";
        break;
    }
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

short HowManyQuiz()
{
    short Quiz = 1;
    cout << "How Many Questions do you want to answer ?";
    cin >> Quiz;
    return Quiz;
}

enLevelQuiz ReadLevelQuiz()
{
    short LevelQuiz = 0;
    cout << "Enter Questions Level ";
    cout << "[1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
    cin >> LevelQuiz;
    return (enLevelQuiz)LevelQuiz;
}

enOperationType ReadOperationType()
{
    short OpType = 0;
    cout << "Enter Questions Level ";
    cout << "[1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
    cin >> OpType;
    return (enOperationType)OpType;
}

short QuestionsLevelMix()
{
    enLevelQuiz LevelQuizMix = enLevelQuiz::Easy;
    short Mix = 0;

    Mix = RandomNumber(1, 3);
    LevelQuizMix = (enLevelQuiz)Mix;

    switch (LevelQuizMix)
    {
    case enLevelQuiz::Easy:
        return RandomNumber(1, 10);
    case enLevelQuiz::Med:
        return RandomNumber(11, 50);
    case enLevelQuiz::Hard:
        return RandomNumber(51, 100);
    default:
        return 0;
    }
}

short QuestionsLevel(enLevelQuiz LevelQuiz)
{
    switch (LevelQuiz)
    {
    case enLevelQuiz::Easy:
        return RandomNumber(1, 10);
    case enLevelQuiz::Med:
        return RandomNumber(11, 50);
    case enLevelQuiz::Hard:
        return RandomNumber(51, 100);
    default:
        return QuestionsLevelMix();
    }
}

char OperationTypeMix()
{
    enOperationType OpType = enOperationType::Add;
    short Mix = 0;

    Mix = RandomNumber(1, 4);
    OpType = (enOperationType)Mix;

    switch (OpType)
    {
    case enOperationType::Add:
        return '+';
    case enOperationType::Sub:
        return '-';
    case enOperationType::Mul:
        return '*';
    case enOperationType::Div:
        return '/';
    default:
        return '+';
    }
}

char IsOperationType(enOperationType ChoiceOpType)
{
    switch (ChoiceOpType)
    {
    case enOperationType::Add:
        return '+';
    case enOperationType::Sub:
        return '-';
    case enOperationType::Mul:
        return '*';
    case enOperationType::Div:
        return '/';
    default:
        return OperationTypeMix();
    }
}

short SumOf2Number(char OpType, stGameQuiz GameQuiz)
{
    switch (OpType)
    {
    case '+':
        return GameQuiz.Number1 + GameQuiz.Number2;
    case '-':
        return GameQuiz.Number1 - GameQuiz.Number2;
    case '*':
        return GameQuiz.Number1 * GameQuiz.Number2;
    case '/':
        if (GameQuiz.Number2 == 0)
            return 0;
        return GameQuiz.Number1 / GameQuiz.Number2;
    default:
        return 0;
    }
}

void PrintQuestions(stGameQuiz GameQuiz, short HowManyQuiz)
{
    cout << "\nQuestions [" << GameQuiz.NumberQuiz << "/" << HowManyQuiz << "]\n\n";
    cout << GameQuiz.Number1 << "\n";
    cout << GameQuiz.Number2 << " " << GameQuiz.OpType;
    cout << "\n_________\n";
}

short ReadAnswerTheQuestionInTheUser()
{
    short Answer = 0;
    cin >> Answer;
    return Answer;
}

enPassFail IsCheckAnswerTheUser(short AnswerTheQuestion, stGameQuiz GameQuiz)
{
    if (AnswerTheQuestion == GameQuiz.SumNum1Num2)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintResultTheQuestion(stGameQuiz GameQuiz, short AnswerTheQuestion)
{
    enPassFail PassFail = IsCheckAnswerTheUser(AnswerTheQuestion, GameQuiz);
    if (PassFail == enPassFail::Pass)
    {
        cout << "\nRight Answer :-)\n\n";
    }
    else
    {
        cout << "\nWrong Answer :-(\n";
        cout << "The right answer is: " << GameQuiz.SumNum1Num2;
        cout << "\n\n";
    }
    DisplyScreenColor(PassFail);
}

void ReadInfoTheGame(stGameQuiz& GameQuiz)
{
    GameQuiz.LevelQuiz = ReadLevelQuiz();
    GameQuiz.ChoiceOperationType = ReadOperationType();
}

string NameQuestionsLevel(enLevelQuiz LevelQuiz)
{
    string NameQuestionsLevel[4] = { "Easy", "Med" , "Hard", "Mix" };
    return NameQuestionsLevel[LevelQuiz - 1];
}

string NameOperationType(enOperationType OperationType)
{
    string NameOperationType[5] = { "+", "-" , "*" , "/", "Mix" };
    return NameOperationType[OperationType - 1];
}

stGameResult FillGameResults(stGameQuiz GameQuiz, short HowManyQuiz, short NumberOfRightAnswers, short NumberOfWrongAnswers)
{
    stGameResult GameResult;
    GameResult.NumberOfQuestions = HowManyQuiz;
    GameResult.NameQuestionsLevel = NameQuestionsLevel(GameQuiz.LevelQuiz);
    GameResult.NameOperationType = NameOperationType(GameQuiz.ChoiceOperationType);
    GameResult.NumberOfRightAnswers = NumberOfRightAnswers;
    GameResult.NumberOfWrongAnswers = NumberOfWrongAnswers;

    return GameResult;
}

stGameResult PlayGame(short HowManyQuiz)
{
    stGameQuiz GameQuiz;
    short NumberOfRightAnswers = 0, NumberOfWrongAnswers = 0;
    short AnswerTheQuestion = 0;
    enPassFail PassFail = enPassFail::Pass;
    ReadInfoTheGame(GameQuiz);

    for (short Quiz = 1; Quiz <= HowManyQuiz; Quiz++)
    {
        GameQuiz.NumberQuiz = Quiz;
        GameQuiz.OpType = IsOperationType(GameQuiz.ChoiceOperationType);
        GameQuiz.Number1 = QuestionsLevel(GameQuiz.LevelQuiz);
        GameQuiz.Number2 = QuestionsLevel(GameQuiz.LevelQuiz);
        GameQuiz.SumNum1Num2 = SumOf2Number(GameQuiz.OpType, GameQuiz);

        PrintQuestions(GameQuiz, HowManyQuiz);
        AnswerTheQuestion = ReadAnswerTheQuestionInTheUser();
        PrintResultTheQuestion(GameQuiz, AnswerTheQuestion);

        PassFail = IsCheckAnswerTheUser(AnswerTheQuestion, GameQuiz);

        if (PassFail == enPassFail::Pass)
            NumberOfRightAnswers++;
        else
            NumberOfWrongAnswers++;
    }

    return FillGameResults(GameQuiz,HowManyQuiz, NumberOfRightAnswers, NumberOfWrongAnswers);
}

enPassFail IsGameResult(stGameResult GameResult)
{
    if (GameResult.NumberOfRightAnswers >= GameResult.NumberOfWrongAnswers)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

string ResultFinal(stGameResult GameResult)
{
    if (IsGameResult(GameResult))
        return "Pass :-(";
    else
        return "Fail :-)";
}

void ShowFinalResults(stGameResult GameResult)
{
    cout << "\n______________________________\n\n";
    cout << " Final Results is " << ResultFinal(GameResult);
    cout << "\n______________________________\n";
}

void PrintInfoGameFinalResult(stGameResult GameResult)
{
    DisplyScreenColor(IsGameResult(GameResult));
    cout << "\nNumber Of Questions: " << GameResult.NumberOfQuestions;
    cout << "\nQuestions Level    : " << GameResult.NameQuestionsLevel;
    cout << "\nOpType             : " << GameResult.NameOperationType;
    cout << "\nNumber Of Right Answers: " << GameResult.NumberOfRightAnswers;
    cout << "\nNumber Of Wrong Answers: " << GameResult.NumberOfWrongAnswers;
    cout << "\n______________________________\n\n";
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
        stGameResult GameResult = PlayGame(HowManyQuiz());
        ShowFinalResults(GameResult);
        PrintInfoGameFinalResult(GameResult);
        cout << "Do you want to play again? Y/N? ";
        cin >> Again;
    } while (Again == 'Y' || Again == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}