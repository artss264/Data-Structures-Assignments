//fully bracketed operations using stack
#include<stdio.h>
#include<string.h>

char eval(char a,char op,char b)
	int x= b-'0';
	int y= a-'0';
	int z;
	if(op=='+') z=x+y;
	else if(op=='-') z=x-y;
	else if(op=='*') z=x*y;
	else z=x/y;
	return (char)(z+'0');
}

int main()
{
	char string[1000];
	top=0;
	int i,j,k,l;
	scanf("%s",string);
	k=strlen(string);
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]==')')
	{
		char v = eval(string[top-1], string[top-2], string[top-3]);
		top-=4;
		str[top++]=v;
	}
return 0;
}
