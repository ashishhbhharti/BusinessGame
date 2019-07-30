/*
Developer: Ashish Bharti
Date: 20 Jul 2019
version: 1.0
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define jail_fine 150
#define treasure_amount 200
#define hotel_amount 200
#define hotel_rent 50

struct player
{
    char name[15];
    int current_amount;
    int hotel_a;
    int cell_position;
    int turns_left;
};
struct player ply,*hotel_array[45];

//BOARD OF THE GAME IN WHICH CELLS ARE MARKED AS E,J,T,H
char cells[]={'E','E','E','J','H','E','T','J','T','E','E','H','J','T','H','E','E','J','H','E','T','J','T','E','E','H','J','T','H','J','E','E','J','H','E','T','J','T','E','E','H','J','T','E','H','E'};

//JAIL FUNCTION
void jail(struct player *p)
{
    p->current_amount-=jail_fine;

}
//TREASURE FUNCTION
void treasure(struct player *p)
{
    p->current_amount+=treasure_amount;

}
//HOTEL FUNCTION
void hotel(struct player *p, int id)
{
    if(hotel_array[p->cell_position]==0)
    {
        if(p->current_amount<200)
        {
            printf("Not sufficient amount\n");
            return ;
        }
        p->current_amount-=hotel_amount;
        p->hotel_a+=hotel_amount;
        hotel_array[p->cell_position]=p;
    }
    else
    {
        hotel_array[p->cell_position]->current_amount+=hotel_rent;
        p->current_amount-=hotel_rent;
    }

}

void play(struct player *p,int id)
{
    int dice;
    srand(time(0));
    dice=3+(rand()%9);//TO GET OUTPUT OF DICE:(2,12)

    printf("Dice Value is %d\n",dice);

    p->cell_position=(p->cell_position+dice)%45;

    p->turns_left-=1;

    if(cells[p->cell_position]=='E')
        return;

    else if(cells[p->cell_position]=='J')
    {
        jail(p);
        return;
    }
    else if(cells[p->cell_position]=='T')
    {
        treasure(p);
        return;
    }
    else if(cells[p->cell_position]=='H')
    {
        hotel(p,id);
        return;
    }
}

void status(struct player *p)
{
    printf("Name:%s\tCurrent_Amount:%d\tCurrent_Position:%d\tTurns_Left:%d\n",p->name,p->current_amount,p->cell_position,p->turns_left);
}

int main()
{
    memset(hotel_array,0,45*sizeof(ply)); //ALL HOTELS ARE AVAILIABLE INITIALLY
    printf("\tWELCOME TO THE BUSINESS HOUSE GAME!!\n\n");
    int n;
    printf("Enter the number of player(MIN=2, MAX=10)\n ");
    scanf("%d",&n);
    if(!(n>1 && n<11))
        {
            printf("WRONG INPUT !! \n");
            exit(0);
        }

    struct player p[n]; //ARRAY OF STRUCTURE PLAYER
    //REGISTRATION OF PLAYERS
    printf("\nRegister the name of all players\n");
    for(int i=0;i<n;i++)
    {
         printf("\nEnter the name player %d:\n",i);
         scanf("%s",&(p[i].name));
         p[i].cell_position=0;p[i].turns_left=10;p[i].current_amount=1000,p[i].hotel_a=0;
    }
    printf("\n*****************Attention all Players Game is Starting*********************\n\n");
    //GAME WILL END AFTER 10 ROUNDS OF EACH PLAYER
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<n;j++)
        {
            int ch;
            printf("Enter the id of the player[0,10]:\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 0:
                {
                    printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                    break;

                }

            case 1:
                {
                   printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                     status(&p[j]);
                     break;
                }

            case 2:
                {
                    printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                     break;
                }
             case 3:
                {
                    printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                     break;
                }
             case 4:
                {
                    printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                     break;
                }
             case 5:
                {
                    printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                     break;
                }
             case 6:
                {
                    printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                     break;
                }

             case 7:
                {
                    printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                     break;
                }
             case 8:
                {
                   printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                     break;
                }
             case 9:
                {
                    printf("\n%s is playing:\n",p[ch].name);
                    play(&p[j],ch);
                    status(&p[j]);
                     break;
                }
            default:
                printf("WRONG ID PRESSED\n");

            }
            printf("\n");
        }

    }

        printf("\n");
        int amount[n];
        int maximum=0;
        int winner_id;
        for(int i=0;i<n;i++)
        {
            amount[i]=p[i].current_amount+p[i].hotel_a;
            if(maximum<amount[i])
            {
                maximum=amount[i];
                winner_id=i;
            }

        }
        for(int i=0;i<n;i++)
        {
            printf("\n%s has money:%d \n",p[i].name,amount[i]);
        }

        printf("\n\n************CONGRATULATIONS %s, YOU HAVE WON THE GAME!!******************\n\n",p[winner_id].name);
    return 0;
}
