#include<stdio.h>
#include<stdlib.h>

struct stack
{
    struct stack *prev;
    char a;
    int b;
    struct stack *next;
};


// bor is going next but not board
void split(int r, int c, struct stack* bor[11][6], char w,int no,char pl)
{
    if (no==0)
    {
        // printf("split");
        bor[r][c]->next=(struct stack*)malloc(sizeof(struct stack));
        bor[r][c]->next->prev=bor[r][c];
        bor[r][c]=bor[r][c]->next;
        bor[r][c]->a=w;
        bor[r][c]->b=no+1;
        bor[r][c]->next=NULL;
        
        //while
        change(bor[r][c],w);
        
    }

    else if (no==1)
    {
        if (pl=='c')
        {
            if (r==0 && c==0)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }

                split(0,1,bor,w,bor[0][1]->b,'e');
                split(1,0,bor,w,bor[1][0]->b,'e');
            }

            else if (r==0 && c==5)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(1,5,bor,w,bor[1][5]->b,'e');
                split(0,4,bor,w,bor[0][4]->b,'e');
            }

            else if (r==10 && c==0)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(9,0,bor,w,bor[9][0]->b,'e');
                split(10,1,bor,w,bor[10][1]->b,'e');
            }

            else if (r==10 && c==5)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(10,4,bor,w,bor[10][4]->b,'e');
                split(9,5,bor,w,bor[9][5]->b,'e');
            }
        }
        
        else if (pl=='e')
        {
            bor[r][c]->next=(struct stack*)malloc(sizeof(struct stack));
            bor[r][c]->next->prev=bor[r][c];
            bor[r][c]=bor[r][c]->next;
            bor[r][c]->a=w;
            bor[r][c]->b=no+1;
            bor[r][c]->next=NULL;

            //while
            change(bor[r][c],w);
        }

        else if (pl=='s')
        {
            bor[r][c]->next=(struct stack*)malloc(sizeof(struct stack));
            bor[r][c]->next->prev=bor[r][c];
            bor[r][c]=bor[r][c]->next;
            bor[r][c]->a=w;
            bor[r][c]->b=no+1;
            bor[r][c]->next=NULL;
        }
    }

    else if (no==2)
    
    {        
        if (pl=='e')
        {
            if (r==0)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r,c+1,bor,w,bor[r][c+1]->b,'e');
                split(r,c-1,bor,w,bor[r][c-1]->b,'e');
                split(r+1,c,bor,w,bor[r+1][c]->b,'s');
            }

            else if (c==0)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r+1,c,bor,w,bor[r+1][c]->b,'e');
                split(r-1,c,bor,w,bor[r-1][c]->b,'e');
                split(r,c+1,bor,w,bor[r][c+1]->b,'s');
            }

            else if (r==10)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r,c+1,bor,w,bor[r][c+1]->b,'e');
                split(r,c-1,bor,w,bor[r][c-1]->b,'e');
                split(r-1,c,bor,w,bor[r-1][c]->b,'s');
            }

            else if (c==5)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r+1,c,bor,w,bor[r+1][c]->b,'e');
                split(r-1,c,bor,w,bor[r-1][c]->b,'e');
                split(r,c-1,bor,w,bor[r][c-1]->b,'s');
            }
        }

        else if (pl=='s')
        {
            bor[r][c]->next=(struct stack*)malloc(sizeof(struct stack));
            bor[r][c]->next->prev=bor[r][c];
            bor[r][c]=bor[r][c]->next;
            bor[r][c]->a=w;
            bor[r][c]->b=no+1;

            //while
            change(bor[r][c],w);
        }
    }

    else if (no==3)
    {
        if (pl=='s')
        {
            if (r==1)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r,c+1,bor,w,bor[r+1][c+1]->b,'e');
                split(r,c-1,bor,w,bor[r+1][c-1]->b,'e');
                split(r+1,c,bor,w,bor[r-1][c+1]->b,'e');
                split(r-1,c,bor,w,bor[r-1][c-1]->b,'e');
            }

            else if (c==9)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r,c+1,bor,w,bor[r+1][c+1]->b,'e');
                split(r,c-1,bor,w,bor[r+1][c-1]->b,'e');
                split(r+1,c,bor,w,bor[r-1][c+1]->b,'e');
                split(r-1,c,bor,w,bor[r-1][c-1]->b,'e');
            }

            else if (r==9)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r,c+1,bor,w,bor[r+1][c+1]->b,'e');
                split(r,c-1,bor,w,bor[r+1][c-1]->b,'e');
                split(r+1,c,bor,w,bor[r-1][c+1]->b,'e');
                split(r-1,c,bor,w,bor[r-1][c-1]->b,'e');
            }

            else if (c==1)
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r,c+1,bor,w,bor[r+1][c+1]->b,'e');
                split(r,c-1,bor,w,bor[r+1][c-1]->b,'e');
                split(r+1,c,bor,w,bor[r-1][c+1]->b,'e');
                split(r-1,c,bor,w,bor[r-1][c-1]->b,'e');
            }

            else 
            {
                //pop
                while (bor[r][c]->a!=' ')
                {
                    bor[r][c]->a=w;
                    bor[r][c]=bor[r][c]->prev;
                }
                
                split(r,c+1,bor,w,bor[r+1][c+1]->b,'s');
                split(r,c-1,bor,w,bor[r+1][c-1]->b,'s');
                split(r+1,c,bor,w,bor[r-1][c+1]->b,'s');
                split(r-1,c,bor,w,bor[r-1][c-1]->b,'s');
            }
        }
    }
}

int place(int r, int c, struct stack* bor[11][6], char w)
{

    if ((bor[r][c]->a==w) || (bor[r][c]->a==' '))
    {
        // printf("if");
    }
    else
    {
        printf("Invalid position\n");
        return 1;
        // inp(bor,w);
    }
    
    if ((r==0 && c==0)||(r==0 && c==10)||(r==10 && c==0)||(r==10 && c==5))
    {    
        // printf("place");
        split(r,c,bor,w,bor[r][c]->b,'c');
    }
    
    else if ((r==0)||(r==10)||(c==0)||(c==5))
    {
        // printf("place");
        split(r,c,bor,w,bor[r][c]->b,'e');
    }
    
    else if ((r>0 || r<10) && (c>0 || c<5))
    {
        // printf("place");
        printf("\n%d\n",bor[r][c]->b);
        split(r,c,bor,w,bor[r][c]->b,'s');
    }

    else 
    {
        printf("Invalid position");
        
        // inp(bor,w);
    }
    return 0;
}

void inp(struct stack* bor[11][6], char w)
{
    int r,c;
    printf("\nEnter position for player %c ",w);
    scanf("%d%d",&r,&c);
    //bor[r][c]->a='P';
    // printf("inp");
    int joker=place(r,c,bor,w);
    if (joker)
    {
        inp(bor,w);
    }

}

struct stack * pop(struct stack *p)
{
    while(p->a!=' ')
    {
        p=p->prev;
        free(p->next);
    }
    return p;
}

void change(struct stack * p, char w)
{
    // printf("change");
    while (p->a!=' ')
    {
        p->a=w;
        p=p->prev;
    }
}

int winner(struct stack * bor[11][6], char w)
{
    for (int i=0; i<11; i++)
    {
        for (int j=0; j<6; j++)
        {
            if ((bor[i][j]->a==w) || (bor[i][j]->a==' '))
            {

            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

void main()
{
    struct stack* board[11][6];
 
    for (int i=0; i<11; i++)
    {
        
        for (int j=0; j<6; j++)
        {
            
            board[i][j]=(struct stack*)malloc(sizeof(struct stack));
            board[i][j]->prev=NULL;
            board[i][j]->a=' ';
            board[i][j]->b=0;
            board[i][j]->next=NULL;
            // printf("%d",board[i][j]->b);
        }
    }

    int win;

    for (int l=0; l<5; l++)
    {
        //player 1
        // printf("main");
        inp(board,'#'); 
        // printf("%c 44444444444444444444444444444444444444444444444",board[10][0]->a);

        for (int i=0; i<11; i++)
        {
            printf("|");
            for (int j=0; j<6; j++)
            {
                printf("%c%d",board[i][j]->a,board[i][j]->b);
                printf("|");
            }
            printf("\n");
        }
        if (l!=0)
        {
            win=winner(board,'#');
            if (win==1)
            {
                printf("# is the winner");
                break;
            }
        }

        inp(board,'@');
        for (int i=0; i<11; i++)
        {
            printf("|");
            for (int j=0; j<6; j++)
            {
                printf("%c%d",board[i][j]->a,board[i][j]->b);
                printf("|");
            }
            printf("\n");
            
        }

        if (l!=0)
        {
            win=winner(board,'@');
            if (win==1)
            {
                printf("@ is the winner");
                break;
            }
        }
        //pop
    }