#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int(*nircmd)(char *cmd);

int main()
{
    LL:
    Sleep(500);
    HMODULE hdll;
    int x,y;
    char xc[5] , yc[5];
    char cmd[100];
    hdll = LoadLibrary("nircmd.dll");
    nircmd nir = (nircmd)GetProcAddress(hdll , "DoNirCmd");
    srand(time(0));
    x = rand() % 2000;
    y = rand() % 1000;

    FILE *fp;
    fp = fopen("rand.txt" , "w");
    fprintf(fp , "%d" , x);
    fclose(fp);
    fp = fopen("rand.txt" , "r");
    fscanf(fp , "%s" , xc);
    fclose(fp);

    fp = fopen("rand.txt" , "w");
    fprintf(fp , "%d" , y);
    fclose(fp);

    fp = fopen("rand.txt" , "r");
    fscanf(fp , "%s" , yc);
    fclose(fp);

    strcpy(cmd , "setcursor ");
    strcat(cmd , xc);
    strcat(cmd , " ");
    strcat(cmd , yc);
    nir(cmd);

    strcpy(cmd , "sendkeypress shift+alt");
    nir(cmd);

    strcpy(cmd , "speak text Error");
    nir(cmd);
    goto LL;
}