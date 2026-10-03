#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void guessNumber();
void calculator();
void tellJoke();
void ticTacToe();
void removeNewline(char *str);
int containsAny(char *text, char *keywords[]);
void printBoard(char board[9]);
int checkWin(char board[9], char player);
void robotbody();
void showMenu();
void rps();

int main() {
    char input[100];
    char name[50] = "";
    int missCount = 0;

    robotbody();
    showMenu();
    printf("\n\033[38;5;226mRoBo:\033[0m");
    printf("what's your name?\n");
    printf("\033[38;5;46mYou: \033[0m");
    fgets(name,sizeof(name),stdin);

    removeNewline(name);
    printf("\033[38;5;226mRoBo:\033[0m");
    printf("~~Nice to meet you %s\n",name);

    removeNewline(name);
    printf("\033[38;5;226mRoBo:\033[0m");
    printf("Wanna Play games or something on your mind?\n");

    while(1){
        printf("\033[38;5;46mYou: \033[0m");
        fgets(input,sizeof(input),stdin);
        removeNewline(input);

        printf("\033[38;5;226mRoBo:\033[0m");


        char *greetWords[]     ={"hello", "hi", "hey", "yo", "helo", "hii", NULL};
        char *howAreWords[]    ={"how are you", "how r u", "how u doin", "how u doing",
                                   "how you doing", "hows it going", "how's it going", NULL};
        char *jokeWords[]      ={"joke", "fun", "laugh", NULL};
        char *laughWords[]     ={"haha","yes","sure", "lol", "lmao", "hehe", "hahaha", NULL};
        char *calcWords[]      ={"calculate", "calc", "math", "maths", NULL};
        char *rpsWords[]       ={"rps", "rock paper scissors", "rock", "paper", "scissors", NULL};
        char *tttWords[]       ={"tictactoe", "tic tac toe", "ttt", NULL};
        char *guessWords[]     ={"guess", "number game", NULL};
        char *byeWords[]       ={"bye", "goodbye", "exit", "quit", "see you", NULL};
        char *thanksWords[]    ={"thanks", "thank you", "thx", "ty", NULL};
        char *sorryWords[]     ={"sorry", "my bad", "apologize","ops", NULL};
        char *complimentWords[]={"cool", "awesome", "nice", "great","good", "amazing", "smart", "damn", "good job", "well done", NULL};

        if(containsAny(input, greetWords))
        {
            printf(" Hello there! What's your name?\n");

            missCount = 0;
        }
        else if(containsAny(input, howAreWords))
        {
            printf(" I'm doing great! Thanks for asking~~\n");
            missCount = 0;
        }
        else if(containsAny(input, thanksWords))
        {
            printf(" You're welcome! Happy to help.\n");
            missCount = 0;
        }
        else if(containsAny(input, sorryWords))
        {
            printf(" No worries at all!\n");
            missCount = 0;
        }
        else if(containsAny(input, complimentWords))
        {
            printf(" Aww, thank you! You're pretty cool yourself.\n");
            missCount = 0;
        }
        else if(containsAny(input, laughWords))
        {
            printf(" Glad that landed! Here's another:\n");
            tellJoke();
            missCount = 0;
        }
        else if(containsAny(input, jokeWords))
        {
            tellJoke();
            missCount = 0;
        }
        else if(containsAny(input, calcWords))
        {
            calculator();
            missCount = 0;
        }
        else if(containsAny(input, tttWords))
        {
            ticTacToe();
            missCount = 0;
        }
        else if(containsAny(input, guessWords))
        {
            guessNumber();
            missCount = 0;
        }
        else if(containsAny(input, rpsWords))
        {
            rps();
            missCount = 0;
        }
        else if(containsAny(input, byeWords))
        {
            printf(" Goodbye!\n");
            break;
        }
        else
        {
            missCount++;

            if(missCount == 1){
                printf(" Hmm, I didn't quite catch that. Try \"joke\", \"calc\", \"ttt\", or \"guess\"!\n");
            }
            else{
                printf(" Still stuck together, huh? Let me lighten the mood:\n");
                tellJoke();
                missCount = 0;
            }
        }
    }

    return 0;
}

void robotbody(){
    printf("          \033[38;5;208m+---------------+\033[0m\n");
    printf("          \033[38;5;226m|               |\033[0m\n");
    printf("          \033[38;5;226m|   <       O   |\033[0m\n");
    printf("          \033[38;5;201m+   ~   U   ~   +\033[0m\n");
    printf("          \033[38;5;226m|       =       |\033[0m\n");
    printf("          \033[38;5;208m+---------------+\033[0m\n");
    printf("          \n\033[38;5;196mRoBo :\033[0m");
    printf("\033[1;36mHello Human! I am RoBo Chat (developed by Maisha)\033[0m\n\n");
}

void showMenu(){
    printf(" Here's what I can do:\n");
    printf("   1. \"joke\" for a laugh\n");
    printf("   2. \"calc\" to do some simple math\n");
    printf("   3. \"rps\" to play rock paper scissors\n");
    printf("   4. \"ttt\" to play tic tac toe\n");
    printf("   5. \"guess\" to play a number guessing game\n");
    printf("   6. \"bye\" to END\n");
}

//remove trailing newline
void removeNewline(char *str){
    int len = strlen(str);
    if(len > 0 && str[len - 1] == '\n'){
        str[len - 1] = '\0';
    }
}

// keyword check
int containsAny(char *text, char *keywords[]){
    int i = 0;
    while(keywords[i] != NULL){
        if(strstr(text, keywords[i]) != NULL){
            return 1;
        }
        i++;
    }
    return 0;
}

//Tell Joke
void tellJoke(){
    char *jokes[7] = {
        "Why did the robot go on a diet? Cause It had too many bytes!",
        "Why don't robots ever panic? Cause They have nerves of steel!",
        "Why was the computer cold? Cause It left its Windows open!",
        "Why do programmers prefer dark mode? Cause Because light attracts bugs!!",
        "Why was the robot bad at soccer? Cause It kept debugging the ball!",
        "There are 10 kinds of people: those who understand binary and those who don't.",
        "Why did the robot cross the road? It was programmed by the chicken!"
    };

    int index = rand() % 7;
    printf(" %s\n", jokes[index]);
}

// Calculator
void calculator(){

    char op;
    float num1, num2, res;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    while(getchar() != '\n'); /* clear leftover newline so it doesn't get read as the next chat line */

    switch(op) {
        case '+':
            res = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, res);
            break;

        case '-':
            res = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, res);
            break;

        case '*':
            res = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, res);
            break;

        case '/':
            if (num2 != 0) {
                res = num1/num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, res);
            } else {
                printf("!!ERROR!!\n");
            }
            break;

        default:
            printf("Invalid operator,Try Again.\n");
            break;
    }
}

//Tic Tac Toe
void printBoard(char board[9])
{
    printf("\n");

    for(int i = 0; i < 9; i++)
    {
        if(board[i] == 'X')
            printf(" \033[31m%c\033[0m ", board[i]);

        else if(board[i] == 'O')
            printf(" \033[38;5;201m%c\033[0m ", board[i]);

        else
            printf(" %c ", board[i]);

        if(i % 3 != 2)
        {
            printf("|");
        }
        else if(i != 8)
        {
            printf("\n---+---+---\n");
        }
    }

    printf("\n\n");
}
int checkWin(char board[9], char player){
    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},   // row
        {0,3,6}, {1,4,7}, {2,5,8},   // column
        {0,4,8}, {2,4,6}             // diagonal
    };
    for(int i = 0; i < 8; i++)
    {
        int count = 0;

        for(int j = 0; j < 3; j++)
        {
            if(board[wins[i][j]] == player)
            {
                count++;
            }
        }

        if(count == 3)
        {
            return 1;
        }
    }
    return 0;
}

void ticTacToe(){
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int movesLeft = 9;

    printf(" Let's play Tic Tac Toe! You're \n\033[38;5;196mX\033[0m, I'm \033[38;5;201mO\033[0m. Pick a spot 1-9.\n");
    printBoard(board);

    while(1){
        int pos;
        printf("You: ");
        scanf("%d", &pos);
        while(getchar() != '\n');


        if(pos < 1 || pos > 9 || board[pos - 1] == 'X' || board[pos - 1] == 'O'){
            printf("\033[38;5;226mRoBo:\033[0m That spot's not free, try another.\n");
            continue;
        }

        board[pos - 1] = 'X';
        movesLeft--;

        if(checkWin(board, 'X')){
            printBoard(board);
            printf("RoBo: You win! Nice game.\n");
            break;
        }
        if(movesLeft == 0){
            printBoard(board);
            printf("RoBo: It's a tie!\n");
            break;
        }
        if(checkWin(board, 'O')){
            printf("RoBo: I win! Better luck next time.\n");
            break;
        }
        if(movesLeft == 0){
            printf("RoBo: It's a tie!\n");
            break;
        }

        int r;
        do{
            r = rand() % 9;
        } while(board[r] == 'X' || board[r] == 'O');
        board[r] = 'O';
        movesLeft--;

        printBoard(board);

    }
}

//Guess Number
void guessNumber(){
    int secret = rand() % 10+1;
    int guess, tries = 0;

    printf(" I'm thinking of a number between 1 and 10. You've got 2 tries!\n");

    while(tries < 2){
        printf("You: ");
        scanf("%d", &guess);
        while(getchar() != '\n');
        tries++;

        if(guess == secret){
            printf("RoBo: Correct! You got it!\n");
            return;
        }
        else if(tries < 2){
            if(guess < secret){
                printf("RoBo: Too low! One more try.\n");
            } else {
                printf("RoBo: Too high! One more try.\n");
            }
        }
    }
    printf("RoBo: Out of tries! The number was %d.\n", secret);
}

//Rock paper scissors
void rps(){
    int user,bot;

    printf("---Rock,Paper,Scissors---\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Enter your choice (1-3): ");
    scanf("%d",&user);
    while(getchar() != '\n');


    if (user < 1 || user > 3) {
        printf("Invalid choice!Select 1, 2, or 3.\n");
        return;
    }
    bot = rand()%3+1;

    printf("RoBo chose: ");
    if (bot== 1) printf("Rock\n");
    else if (bot == 2) printf("Paper\n");
    else printf("Scissors\n");

    if (user== bot) {
        printf("\nIt's a tie! ~~\n");
    }
    else if ((user == 1 && bot== 3) ||
             (user == 2 && bot == 1) ||
             (user == 3 && bot == 2)) {
        printf("\n==> You won! :3 <==\n");
    }
    else {
        printf("\n==> I won! ^^ <==\n");
    }
}

