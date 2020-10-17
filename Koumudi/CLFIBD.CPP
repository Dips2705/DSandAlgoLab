#include<stdio.h>
#include<conio.h>
#include<string.h>
int h = -1;
char dis[10];
void freq(char d[])
{
    int k[27], s = 0, f = 1;
    int i, j, c = 1, m = strlen(d);
    // counting frequencies
    for(i = 0; i < m; i++)
    {
        for(j = i + 1; j < m; j++)
        {
            if((d[i] == d[j]) && (d[i] != '*'))
            {
                c++;
                d[j] = '*';
            }
        }
        if(d[i] != '*')
        {
            k[s] = c;
            s++;
        }
        c = 1;
    }
    // sorting
    for(i = 0; i < s; i++)
    {
        m = i;
        for(j = i; j < s; j++)
        {
            if(k[m] > k[j])
                m = j;
        }
        c = k[i];
        k[i] = k[m];
        k[m] = c;
    }
    for(i = 0; i < s; i++)
    {
        printf("%d", k[i]);
    }
    printf("%d \n", s);
    if(s <= 2)
    {
        dis[++h] = 'y';
    }
    else
    {
        j = 2;
        i = 0;
        m = 1;
        while(j <= (s - 1))
        {
            if(k[j] != (k[i] + k[m]))
            {
                f = 0;
                break;
            }
            j++;
            m++;
            i++;
        }
        if(f != 0)
            dis[++h] = 'y';
        else
            dis[++h] = 'n';
    }
}
void main()
{
    clrscr();
    int a, i;
    char c[30];
    printf("Enter the no of testcases \n");
    scanf("%d", &a);
    printf("Enter the string \n");
    for(i = 0; i < a; i++)
    {
        fflush(stdin);
        gets(c);
        //c[]='\0';
        freq(c);
    }
    for(i = 0; i < a; i++)
    {
        if(dis[i] == 'y')
            printf("Dynamic \n");
        else if(dis[i] == 'n')
            printf("Not \n");
    }
    getch();
}