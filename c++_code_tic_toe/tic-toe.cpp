#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int val = 1;
int checkwin();
void board();
void validate(int, char);
int resetgame();
int main()
{
    int player = 1, i, choice, winner = 0;
    char mark;
    do
    {

        board();
        printf("\n\n            Player %d,  please select square :  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';
        validate(choice, mark);

        winner = checkwin();
        board();

        if (winner == 1)
        {
            printf("winner is  player %d \n\n", player);
            getch();
            winner = resetgame();
        }
        if (val == 0)
            player = (player == 2) ? 1 : 2;
        /*validation for  no one  win the game */
        if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
            square[4] != '4' && square[5] != '5' && square[6] != '6' &&
            square[7] != '7' && square[8] != '8' && square[9] != '9')
            winner = resetgame();

    } while (winner != 1);

    return 0;
}
void validate(int choice, char mark)
{
    val = 1;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 ||
        choice == 6 || choice == 7 || choice == 8 || choice == 9)
    {

        if (square[choice] == 'X' || square[choice] == 'O')
            printf("already selected");

        else if (square[choice] != 'X' && square[choice] != 'O')
        {
            val = 0;
            square[choice] = mark;
        }
    }
    else
    {
        printf("\n please select  between 1 to 9\n");
        getch();
        val = 1;
    }
}

void board()
{

    system("cls");
    printf("\n\n\t                              DIEGO  APP   \n\n");

    printf("--------------------------------Player 1 (X)  -  Player 2 (O)-------------------\n\n\n");

    printf("                                    |-----|-----|-----|\n");
    printf("                                    |  %c  |  %c  |  %c  | \n", square[1], square[2], square[3]);
    printf("                                    |_____|_____|_____|\n");
    printf("                                    |     |     |     | \n");
    printf("                                    |  %c  |  %c  |  %c  | \n", square[4], square[5], square[6]);
    printf("                                    |_____|_____|_____|\n");
    printf("                                    |     |     |     |\n");
    printf("                                    |  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);
    printf("                                    |-----|-----|-----|\n");
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    if (square[4] == square[5] && square[5] == square[6])
        return 1;
    if (square[7] == square[8] && square[8] == square[9])
        return 1;
    if (square[1] == square[4] && square[4] == square[7])
        return 1;
    if (square[2] == square[5] && square[5] == square[8])
        return 1;
    if (square[3] == square[6] && square[6] == square[9])
        return 1;
    if (square[1] == square[5] && square[5] == square[9])
        return 1;
    if (square[3] == square[5] && square[5] == square[7])
        return 1;

    return 0;
}

int resetgame()
{
    int flag = 0, i = 0;
    char reset = 'a';

    while (flag == 0)
    {
        printf("\n\n                  would like play a new game ? Y or N:  ");
        scanf("%c", &reset);
        if (reset == 'Y' || reset == 'y')
        {
            printf("\n\n                  converta:  ");
            for (i = 0; i < 10; i++)
                square[i] = i + '0';
            val = 1;
            flag = 1;
            return 0;
        }
        if (reset == 'N' || reset == 'n')
            return 1;
        if (reset != 'Y' || reset != 'y' || reset != 'N' || reset != 'n')
            printf("\n\n                  that caracter is not an option  ");
    }
    return 1;
}
/*********************************************/
