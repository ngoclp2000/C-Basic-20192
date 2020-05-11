#include<stdio.h>
#include<stdlib.h>
int count = 0;
int count1 = 0;
int count2 = 0;
int binary_search(int list[], int target, int size){
    int mid,high,low;
    high = size-1; low = 0;
    while(low <= high){
        count ++;
        mid = (low + high ) / 2;
        if(list[mid] > target){
            high = mid - 1;
        }else if(list[mid] < target){
            low = mid +1;
        }else return mid;
    }
    printf("There are no match \n");
    return 0;
}
int binary_search_recurse(int list[], int target,int high,int low){
    count++;
    //printf("%d %d\n",high,low);
    if(low <= high){
        int mid = (high + low) /2 ;
        if (list[mid] > target)
            return binary_search_recurse(list,target,mid-1,low);
        else if(list[mid] < target)
            return binary_search_recurse(list,target,high,mid+1);
        return mid;
    }else{
        printf("There are no match\n");
        return 0;
    }
}
//Bubble Sort
void printArray(int arr[],int size){
    for(int i = 0 ; i <  size ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int sequentialSearch(int arr[],int size,int target){
    for(int i = 0 ; i <  size ; i++){
        count1++;
        if(arr[i] == target ) return target;
    }
    return -1;
}
int sentinelSearch(int arr[], int n, int target) 
{ 
  
    // Last element of the array 
    int last = arr[n - 1]; 
  
    // Element to be searched is 
    // placed at the last index 
    arr[n - 1] = target; 
    int i = 0; 
  
    while (arr[i] != target) 
    {
            count2++;
            i++;
    }
  
    // Put the last element back 
    arr[n - 1] = last; 
  
    if ((i < n - 1) || (target == arr[n - 1])) 
        return target; 
    else
       printf("Not Found!!!\n");
} 
int main(){
  int list [] = {0,1,2,3,4,5,6,7,8,9,12,13,15,18,32,67,78,79,81,85,92,102};
  int n = sizeof(list) / sizeof(int);
  //printArray(list,n);
  binary_search_recurse(list,102,n-1,0);
  sequentialSearch(list,n,102);
  sentinelSearch(list,n,102);
  //binary_search(list,21,n);
  printf("The number of comparasion times of Binary Search: %d\n",count);
  printf("The number of comparasion times of Sequential Search: %d\n",count1);
  printf("The number of comparasion times of Sentinel Search: %d\n",count2);
}