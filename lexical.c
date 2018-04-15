#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct ktab
{
	char key[10];
}ktab[10]={
			{"void"},
			{"main"},
			{"int"},
			{"printf"},
			{"return"}
};
struct symtab
{
	char sym[5];
}symtab[5];
struct litab
{
	char lit[5];
}litab[5];
struct UST
{
	char lexeme[10];
	char type[6];
	int token;
}UST[20];

int delim(char);
void parse(char*);
int keyword(char *);
int symbol(char*);
int literal(char*);
void display();
int operator(char);

FILE *fp;
int symptr=1,litptr=1,ustptr=1;
int main()
{
	char next,buf[10];
	int i=0,d=-1,flag=0,o=-1;
	fp=fopen("input.txt","r");
	while(!feof(fp))
	{
		next = fgetc(fp);
		if(flag==0)
		{
			if(next == ' '||next=='\n')
			{
				buf[i]='\0';
				parse(buf);
				i=0;
				memset(buf,'\0',sizeof(buf));
			}
			else if((d=delim(next))!=-1||(o=operator(next))!=-1)
			{
				buf[i]='\0';
				parse(buf);
				memset(buf,'\0',sizeof(buf));
				i=0;
				buf[i++]=next;
					//printf("PARSING %c TOKEN %d",next,d);
			}
			else if(isalnum(next))
			{
					buf[i]=next;
					i++;
			}
			else if(next=='"')
			{

					buf[i]='\0';
					parse(buf);
					memset(buf,'\0',sizeof(buf));
					i=0;
					flag=1;
			}
		}
		else
		{
			if(next!='"')
			{
				buf[i]=next;
				i++;
			}
			else
			{
				flag=0;
			}
			
		}
		

	}
	display();
	return 0;
}
int operator(char c)
{
	switch(c)
	{
		case '+' :	return 1;
					break;
		case '-' :  return 2;
					break;
		case '*' :  return 3;
					break;
		case '/' :  return 4;
					break;
		case '=' :  return 5;
					break;
		default  :  return -1;
	}
	return -1;	
}
int delim (char c)
{
	switch(c)
	{
		case '{' :	return 1;
					break;
		case '}' :  return 2;
					break;
		case '(' :  return 3;
					break;
		case ')' :  return 4;
					break;
		case ';' :  return 5;
					break;
		default  :  return -1;
	}
	return -1;
}
void parse(char buf[])
{
	int d,l,s,k,o;
	if(buf[0]!='\0')
	{
		printf("PARSING %s\n",buf );
		if((k=keyword(buf))!=-1)
		{
			strcpy(UST[ustptr].lexeme,buf);
			strcpy(UST[ustptr].type,"KWT");
			UST[ustptr++].token=k;
		}
		else if((s=symbol(buf))!=-1)
		{
				strcpy(UST[ustptr].lexeme,buf);
			strcpy(UST[ustptr].type,"SYM");
			UST[ustptr++].token=s;
		}
		else if((l=literal(buf))!=-1)
		{
					strcpy(UST[ustptr].lexeme,buf);
			strcpy(UST[ustptr].type,"LIT");
			UST[ustptr++].token=l;
		}
		else if((d=delim(buf[0]))!=-1)
		{
				strcpy(UST[ustptr].lexeme,buf);
			strcpy(UST[ustptr].type,"DLM");
			UST[ustptr++].token=d;
		}
		else if((o=operator(buf[0]))!=-1)
		{
			strcpy(UST[ustptr].lexeme,buf);
			strcpy(UST[ustptr].type,"OPR");
			UST[ustptr++].token=o;
		}
	}
	
}
int keyword(char buf[])
{
	int i=0;
	for (i = 0; i < 5; i++)
	{
		if(strcmp(buf,ktab[i].key)==0)
		{
			return i;
		}
	}
	return -1;
}
int symbol(char buf[])
{
	if(isalpha(buf[0]))
	{
		strcpy(symtab[symptr++].sym,buf);
		return symptr;
	}
	return -1;
}
int literal(char buf[])
{
	if(isdigit(buf[0]))
	{
		printf("PUTTING %s in ltab at index %d \n",buf,litptr);
		strcpy(litab[litptr].lit,buf);
		litptr++;
		return litptr;
	}
	return -1;
}
void display()
{
	int i;
	printf(" \n\tUNIFORM SYMBOL TABLE\n=========================================\nLEXEME\t|\tTYPE\t|\tTOKEN\t|\n");
	for(i=1;i<ustptr;i++)
	{
		printf("%s\t|\t%s\t|\t%d\t|\n",UST[i].lexeme,UST[i].type,UST[i].token );
	}
	printf("========================================\n");
	printf(" \n\tSYMBOL TABLE\n======================\nINDEX\t|\tSYMBOL\n");
	for(i=1;i<symptr;i++)
	{
		printf("%d\t|\t%s\n",i,symtab[i].sym );
	}
	printf("===========================\n");
		printf(" \n\tLITERAL TABLE\n======================\nINDEX\t|\tLITERAL\n");
	for(i=1;i<litptr;i++)
	{
		printf("%d\t|\t%s\n",i,litab[i].lit );
	}
	printf("===========================\n");
}
