#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int match(char *s)
{
    char *a = (char*)malloc(sizeof(s));
    if(s[1] == '\0')return 0;
    int top=-1, c=0;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i] == '{')a[++top] = s[i];
        if(s[i] == '[')a[++top] = s[i];
        if(s[i] == '(')a[++top] = s[i];
        if(s[i] == '}')
        {
            if(top != -1)
            {
                if(a[top] == '{')top--;
                else return 0;
            }
            else return 0;
        }
        if(s[i] == ']' )
        {
            if(top != -1)
            {
                if(a[top] == '[')top--;
                else return 0;
            }
            else return 0;
        }
        if(s[i] == ')')
        {
            if(top != -1)
            {
                if(a[top] == '(')top--;
                else return 0;
            }
            else return 0;

        }
        if(c != 0)return 0;
    }
    if(top == -1)return 1;
    else return 0;
}
int main()
{
    char s[25];
    printf("Enter String: ");
    scanf("%s",s);
    int res = match(s);
    if(res == 1) printf("Valid!");
    else printf("Invalid!");
    getch();
}
