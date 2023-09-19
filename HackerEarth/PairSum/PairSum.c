#include <stdio.h>
#include <stdbool.h>
typedef struct
{
	int num1;
	int num2;
}Result;

#define N_Size 1000000
bool Prime[N_Size+1];
void isPrime(void);
Result pairSum (int num);

int main(){
	int t;
	isPrime();
	scanf("%d",&t);
	while(t--)
	{
	int num;
	Result saveVal;
	scanf("%d", &num);              	                 
	saveVal = pairSum(num);
	if(saveVal.num1 != -1 && saveVal.num2 != -1 )
	{
		printf("%d %d",saveVal.num1,saveVal.num2);
		
	}
	else
	{
		printf("%d",saveVal.num1);
		
	}
	printf("\n");
	}
}
Result pairSum (int num)
{
	Result sol;
	sol.num1 = -1;
	sol.num2 = -1;
	for(int i =2;i<=num;i++)
	{
		if((i + num-i == num) && Prime[i] && Prime[num-i] )
		{  
			sol.num1 = i ;
	        sol.num2 = num-i ;
			return sol;	
		}
	}
	return sol;
}

void isPrime(void)
{
	memset(Prime,true,sizeof(Prime));
	Prime[0] = Prime[1] = false;
	// Sieve of Eratosthenes to calculate prime numbers
	for(int i =2;i*i<=N_Size;i++)
	{
		// if unmarked then it's a prime
		if(Prime[i])
		{
			// then mark all multiples of Prime[i]
		    for(int j = i*i; j <= N_Size; j+=i)
		   {
		    	Prime[j] = false;
	     	}
		}
	}
}