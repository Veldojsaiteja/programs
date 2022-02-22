#include <stdio.h>
#include <string.h>

void search(char* txt, char* pat)
{
	int N = strlen(txt);
	int M = strlen(pat);
	int c = 0,x = 0,index = -1;
	int a[(int)(N/M)];
	for(int i=0;i<N/M;i++)a[i] = -1;

	for (int i = 0; i <= N - M; i++)
	{
		c = 0;
		for (int j = 0; j < M; j++)
		{
			if (txt[i + j] == pat[j])
			{
				if(c == 0) index = i+j;
				c++;
			}
		}
		if(c == M) a[x++] = index;
	}
	if(a[0] != -1)
	{
		printf("Pattern Matched at indexes : ");
		for(int i=0;i<N/M;i++)if(a[i] != -1) printf("%d ",a[i]);
	}
	else printf("No Pattern Matched in text!");
}

int main()
{
	char txt[100];
	char pat[25];
	printf("Enter Text :");
	scanf("%[^\n]%*c",txt);
	printf("Enter Pattern to search: ");
	scanf("%[^\n]%*c",pat);
	search(txt,pat);
	return 0;
}
