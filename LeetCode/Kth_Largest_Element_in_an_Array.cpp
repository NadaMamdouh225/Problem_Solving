#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
     int findKthLargest(vector<int>& nums, int k) {
        int n =nums.size();
        mergeSort(nums,0,n-1);
        return nums[n-k];
    }
    void Merge(vector<int>& arr,int left,int mid,int right) // m = l+(r-l)/2 ;
{
    int i,j,k;
    int n1 = mid - left +1;   // size of first subarray
    int n2 = right - mid;     // size of second subarray
    int *l=new int[n1],*r=new int[n2];

    for(int i=0;i<n1;i++)
        l[i] = arr[left+i];
    for (int j=0;j<n2;j++)
        r[j] = arr[mid+1+j];

    i=j=0;
    k=left;
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k]=l[i];
            i++;
        }else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr,int l,int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        Merge(arr,l,m,r);

    }

}


};
