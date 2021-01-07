#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int strlen(char* str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i - 1;
}
int main()
{
    char** text;
    int lenght = 0;
    int chislo = 0;
    int j = 0, i, n, jn, jk, summ = 0, fl, p = 1;
    scanf_s("%d", &n);
    rewind(stdin);
    text = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
        *(text + i) = (char*)malloc(255 * sizeof(char));
    for (i = 0; i < n; i++)
    {
        rewind(stdin);
        while ((text[i][j++] = getchar()) != '\n')
        {
            text[i] = (char*)realloc(text[i], (j + 1) * sizeof(char*));
        }
        text[i][j - 1] = '\0';
        j = 0;
    }

    i = 0;
    j = 0;

    for (i = 0; i < n; i++)
    {
        j = 0;
        while (text[i][j] != '\n' && text[i][j] != '\0')
        {
            while (text[i][j] != '0' && text[i][j] != '1' && text[i][j] != '2'
                && text[i][j] != '3' && text[i][j] != '4' && text[i][j] != '5'
                && text[i][j] != '6' && text[i][j] != '7' && text[i][j] != '8'
                && text[i][j] != '9'
                && text[i][j] != '\0' && text[i][j] != '\n') j++;
            jn = j;
            while (text[i][j] >= '0' && text[i][j] <= '9' && text[i][j] != '\0' && text[i][j] != '\n') j++;
            jk = j - 1;
            fl = jk - jn;
            for (int counter = 0; counter < fl; counter++) p *= 10;
            for (int counter = 0; counter <= fl; counter++)
            {
                chislo += (text[i][jn + counter] - '0') * p;
                p /= 10;
            }
            summ += chislo;

            chislo = 0;
            p = 1;
        }
        lenght = strlen(text[i]);
        //printf("%d\n", summ);
        char* c;
        c = (char*)malloc(10 * sizeof(char));
        int v = 0;
        while (summ > 9)
        {
            c[v++] = (summ % 10) + '0';
            summ = summ / 10;
        }

        c[v++] = summ + '0';
        c[v] = '\0';
        char t;

        for (int i = 0; i < v / 2; i++)
        {
            t = c[i];
            c[i] = c[v - 1 - i];
            c[v - 1 - i] = t;
        }



        v = 0;
        while (c[v] != '\0')
        {
            lenght++;
            text[i][lenght] = c[v];
            text[i][lenght + 1] = '\0';
            v++;

        }
        free(c);
        text[i][lenght + 1] = '\0';
        summ = 0;

    }
    for (i = 0; i < n; i++)
        puts(text[i]);
    return 0;
}
