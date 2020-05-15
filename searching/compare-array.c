#include<stdio.h>
#include<stdlib.h>
int count = 0;
int count1 = 0;
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
    return -1;
}
int binary_search_recurse(int list[], int target,int high,int low){
    if(low <= high){
        count1++;
        int mid = (high + low) /2 ;
        if (list[mid] > target)
            return binary_search_recurse(list,target,mid-1,low);
        else if(list[mid] < target)
            return binary_search_recurse(list,target,high,mid+1);
        return mid;
    }else{
        return -1;
    }
}
void verification(int list1[],int list2[],int type,int size1,int size2){
    if(type == 1){
        for(int i = 0 ; i < size1 ; i++){
            if(binary_search_recurse(list2,list1[i],size2,0) == -1){
                printf("%d ",list1[i]);
            }
        }
        printf("\n");
    }else if(type == 2){
        for(int i = 0 ; i < size2 ; i++){
            if(binary_search_recurse(list1,list2[i],size1,0) == -1){
                printf("%d ",list2[i]);
            }
        }
        printf("\n");
    }else{
        for(int i = 0 ; i < size1 ; i++){
            if(binary_search_recurse(list2,list1[i],size2,0) != -1)
                printf("%d ",list1[i]);
        }
        printf("\n");
    }
}
int main(){
  int list1 [] = {0,1,2,3,4,5,6,7,8,9,12,13,15,18,32,67,78,79,81,85,92,102};
  int list2 [] = {0,3,6,7,8,9,11,13,14,17,18,24,25,27,45,56,56,78,81,21,23};
  int size1 = sizeof(list1) / sizeof(int);
  int size2 = sizeof(list2) / sizeof(int);
  verification(list1,list2,1,size1,size2);
  verification(list1,list2,2,size1,size2);
  verification(list1,list2,3,size1,size2);
}