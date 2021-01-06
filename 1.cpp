#include<stdio.h>
#include<malloc.h>
#include<math.h>
int main()
{
    char** text;

    int chislo = 0;
    int i, n, jn, jk, summ = 0, fl, p = 1;
    scanf_s("%d", &n);
    rewind(stdin);
    text = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
        *(text + i) = (char*)malloc(255 * sizeof(char));
    for (i = 0; i < n; i++)
        fgets(*(text + i), 255, stdin);
    i = 0;
    int j = 0;

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
    }
    printf("%d", summ);
}