#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char input[10];
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F();

int main()
{
	i=0;
	error=0;
	printf("enter arithmetic expression \n");
	gets(input);
	E();
	if(strlen(input)== i && error==0)
		printf("Accepted \n");
	else
		printf("rejected \n");
	return 0;
}

void E()
{
	T();
	Eprime();
}

void T()
{
	F();
	Tprime();
}

void F()
{
	if(isalpha(input[i]))
		i++;
	else if (input[i]=='(')
	{
		i++;
		E();
		if (input[i]==')')
			i++;
		else
			error=1;
	}
	else
		error=1;
}

void Eprime()
{
	if(input[i]=='+')
	{
		i++;
		T();
		Eprime();
	}
}

void Tprime()
{
	if(input[i]=='*')
	{
		i++;
		F();
		Tprime();
	}
}
