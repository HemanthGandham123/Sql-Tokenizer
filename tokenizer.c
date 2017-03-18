#include <stdio.h>
#include <string.h>	//For the string functions.

//Follwing arrays are stored for pattern matching.
char *keywords[] = {"INSERT","DELETE","UPDATE","SET","CREATE" ,"TABLE","SELECT","INTO","WHERE","DROP",
	"COLUMN","ALTER","TABLE","ADD","VALUES","FROM","INTEGER","STRING","FRACTION"};
char *operators[] = {"=",">=","<=","<",">","<>","AND","OR"};
char *extra[] = {";","*",",","(",")"};

int main()
{
	// DATA TYPES USED: INTEGER,STRING and FRACTION	  		
	
	printf("\n");
	char input[200];		//input stored in this array
	gets(input);			
	int l = strlen(input);
	int x=10,i = 0,q=0,j=0;
	int shift = 0;
	int keyword_len = 19;							
	int operators_len = 8;													  						  //	
	int extra_len = 5;	
	int count=0;
	
	for(j=0;j<l;j++)
	{
		if(input[j]>96 && input[j]<123)
			input[j]-=32;
	}
	do {																          					  //
		//Skipping the spaces.	
		START:
		while(input[shift] == ' '){
			shift = shift + 1;
		}
		//input being matched with every keyword (data types are also handled in the same loop
		
		for(i=0;i<keyword_len;i++){

			while(input[shift] == ' ')
			{
			shift = shift + 1;
			}

			const char *pattern = keywords[i];
			char match[200];
			strncpy(match,input+shift,strlen(pattern));
			match[strlen(pattern)] = '\0';
			if(strcmp(pattern,match) == 0){

				if(i==16 ||i==17||i==18)
				printf("%s : data type\n\n",match);

				else
				printf("%s : keyword\n\n",match);

				shift = shift + strlen(pattern);
				//break;
				goto START;
			}

		}
		while(input[shift] == ' '){
			shift = shift + 1;
		}
		//input being matched with every operator
		for(i=0;i<operators_len;i++){

			while(input[shift] == ' ')
			{
			shift = shift + 1;
			}
			const char *pattern = operators[i];
			char match[200];
			strncpy(match,input+shift,strlen(pattern));
			match[strlen(pattern)] = '\0';
			if(strcmp(pattern,match) == 0){
				printf("%s : operator\n\n",match);	//Once the match found we print the appropriate token and break to the next part of input
				shift = shift + strlen(pattern);
				//break;
				goto START;
			}

		}
		while(input[shift] == ' '){
			shift = shift + 1;
		}
		//input being matched with every extra characters
		for(i=0;i<extra_len;i++){

			while(input[shift] == ' ')
			{
			shift = shift + 1;
			}

			const char *pattern = extra[i];
			char match[200];
			strncpy(match,input+shift,strlen(pattern));
			match[strlen(pattern)] = '\0';
			if(strcmp(pattern,match) == 0){
				printf("%s : terminating/non terminating symbol\n\n",match);
				shift = shift + strlen(pattern);
				//break;
				goto START;
			}

		}

		//========For matching numbers and fractions==========//
		while(input[shift]>47 && input[shift]<58)
		{
			x=1;
			printf("%c",input[shift]);
			if(input[shift+1]==46)
			{
				printf("%c",input[shift+1]);
				shift++;
				q=3;
				count++;
			}	
			shift++;
		}

		//===========Border case of the '_' being handled========//
		if(input[shift]=='_')
		{
			printf("Invalid Symbol\n\n");
			shift++;
			//break;
		}

		//=========For matching Identifiers=======================//
		while((input[shift]>64 && input[shift]<91)||(input[shift] >96 &&input[shift]<123)|| input[shift]=='_')
		{
			x=2;
			printf("%c",input[shift]);
			shift++;
		}

		//===Invalid Symbols taken care of=========================//
		if(x==10 && shift<l-1)
		{	
			printf("%c : Invalid symbol\n\n",input[shift]);
			shift++;
		}
		else if(x==1 && q==0)
			printf(" : number\n\n");
		else if(x==1 && q==3)
		{
			if(count>1)
			printf(" : fractional number provided in invalid format\n\n");
		}
		else if(x==2)
			printf(" : Identifier\n\n");
		q=0;
		x=10;
	}while (shift < l);
	printf("END OF FILE\n\n");		//We reached the EOF.
	return 0;
}

//===========END OF THE CODE=====================//
