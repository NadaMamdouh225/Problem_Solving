#include <stdio.h>
#include <malloc.h>

int *rotate (int *arr,int n,int k);

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int *ptr;
		int *arr;
		int n,k;
    	scanf("%d %d", &n,&k);  
		arr = (int*)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
		{
			scanf("%d ",&arr[i]);
		}
		ptr = rotate(arr,n,k);
		for(int i=0;i<n;i++)
		{
			printf("%d ",ptr[i]);
		}
		free(ptr);
		free(arr);
		printf("\n");
	}
	            	                
}

int *rotate (int *arr,int n,int k)
{
	int *newArr = (int*)malloc(sizeof(int)*n) ;
	for(int i = 0;i<n;i++)
	{
        int j = (i+k)%n;
		newArr[j] = arr[i];
	}
	return newArr;
}