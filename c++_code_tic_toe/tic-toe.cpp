#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int val = 1;
int checkwin();           //check the winning options  return  result
void board();             // draw  the   board game
void validate(int, char); // validate customer input  and  square  selected
int resetgame();          // reset the  board   and validate exit of game

int main()
{
    int player = 1, i, choice, winner = 0;
    char mark;
    do
    {

        board();
        printf("\n\n            user %d,  please select square :  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';
        validate(choice, mark);

        winner = checkwin();
        board();

        if (winner == 1)
        {
            printf("winner is  user %d \n\n", player);
            getch();
            winner = resetgame();
        }
        if (val == 0)
            player = (player == 2) ? 1 : 2;

        /*validation if no one  win the game */

        if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
            square[4] != '4' && square[5] != '5' && square[6] != '6' &&
            square[7] != '7' && square[8] != '8' && square[9] != '9')
            winner = resetgame();

    } while (winner != 1);

    return 0;
}
/* this funtion validate   info from customer and  the   square selected */
void validate(int choice, char mark)
{
    val = 1;

    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 ||
        choice == 6 || choice == 7 || choice == 8 || choice == 9)
    {

        if (square[choice] == 'X' || square[choice] == 'O')
        {
            printf("---------already selected please choose another one--------");
            getch();
        }

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
/* this funtion draw the board */
void board()
{

    system("cls");
    printf("\n\n\t                              DIEGO  APP   \n\n");

    printf("--------------------------------User 1 (X)  -  user 2 (O)-------------------\n\n\n");

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
/* this funtion  check  posible  winning options*/
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
/* this funtion wipe up   or exit  the game */
int resetgame()
{
    int flag = 0, i = 0;
    char reset;

    while (flag == 0)
    {
        printf("\n\n                  would like play a new game ? Y or N:  ");
        scanf("%c", &reset);

        if (reset == 'Y' || reset == 'y')
        {
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
