/*
S->aBa|bCb
B->bB|c
C->cC|d
*/

#include<stdio.h>
#include<stdlib.h>
int i=0;

int B(char str[10])
{
	switch(str[i])
	{
		case 'c':
		{
			i++;
			return 1;
		}
		case 'b':
		{
			i++;
			if(B(str) == 1) 
				return 1;
			else 
				return 0;
		}
		default:
		{
			return 0;
		}
	}
		
}
int C(char str[10])
{
	switch(str[i])
	{
		case 'd':
		{
			i++;
			return 1;
		}
		case 'c':
		{
			i++;
			if(C(str) == 1)
				return 1;
			else 
				return 0;
		}
		default:
		{
			return 0;
		}
	}

}
int S(char str[10])
{
	 int f2=0,f3=0;
	 switch(str[i])
	 {
	 	case 'a':
	 	{
	 		i++;
	 		f2=B(str);
	 		if(f2!=0)
				if(str[i] == 'a') 
	 				return 1;
				else 
					return 0;
	 		else
	 			return 0;
	 	}
	 	case 'b':
	 	{
	 		i++;
	 		f3=C(str);
	 		if(f3!=0)
			 	if(str[i] == 'b')
	 				return 1;
				else 
					return 0;
	 		else
	 			return 0;
	 	}
	 			
	 	default:
	 	{
	 		return 0;
	 	}	
	 }
}
int main()
{
	int f1=0;
	char str[30];
	printf("\n enter the string:");
	scanf("%s",str);
	f1=S(str);

	if(f1!=0)
	{
		printf("\n string is accepted..");
	}
	else
	{
		printf("\n string is rejected..");
	}
	return 0;
	
}
