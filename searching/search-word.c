#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Finding the string if it is the beginning of input string
int isMatch(char find_string[],char string_in_arr[]){
    for(int i = 0 ; i < strlen(find_string) ; i++){
        if(find_string[i] != string_in_arr[i])
            return 0;
    }
    return 1;
}
//Finding the string if it contain in input string
int _isMatch(char find_string[],char string_in_arr[]){
    int pos = 0;
    int flag = 1;
    while(pos + strlen(find_string) <= strlen(string_in_arr) && flag){
        for(int i = pos ; i < strlen(find_string) + pos ; i++){
            if(find_string[i-pos] != string_in_arr[i])
                    goto next;
        }
        flag = 0;
        next:
            pos++;
    }
    if(flag)
        return 0;
    else
        return 1;
}
int main(){
    printf("Enter the string finding\n");
    char finding_string[256];
    scanf("%s",finding_string);
    FILE *ptr = fopen("words.txt","r");
    int count = 0;
    char *arr = (char *) malloc(sizeof(char) *50);
    while(fgets(arr,50,ptr) != 0){
        arr = strtok(arr," ");
        if(isMatch(finding_string,arr))
                printf("%s\n",arr);
    }
}