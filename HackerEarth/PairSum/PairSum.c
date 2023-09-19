#include <stdio.h>
typedef struct
{
	int num1;
	int num2;
}Result;

int isPrime(int num);
Result pairSum (int num);

int main(){
	int num;
	Result saveVal;
	scanf("%d", &num);              	                  // Reading input from STDIN
	saveVal = pairSum(num);
	if(saveVal.num1 != -1 && saveVal.num2 != -1 && num > 2)
	{
		printf("%d %d",saveVal.num1,saveVal.num2);
	}
	else
	{
		printf("%d",saveVal.num1);
	}
}
Result pairSum (int num)
{
	Result sol;
	sol.num1 = -1;
	sol.num2 = -1;
	for(int i =2;i<num;i++)
	{
		for(int j =2;j<num;j++)
		{
			if( isPrime(i) && isPrime(j) )
			{
				if(i + j == num)
				{    
					sol.num1 = i ;
	                sol.num2 = j ;
				    return sol;	
				}
			}
		}
		
	}
	return sol;
}

int isPrime(int num)
{
	for(int i=2;i<num;i++)
	{
		if(num % i == 0)
		{
			return 0;      // not prime number
		}
	}
	return 1;  //  prime number
}