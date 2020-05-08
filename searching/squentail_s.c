#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sequential_search(char *item, int count, char key){
    register int t ;
    for(t = 0 ; t < count ; t++)
          if(key == item[t])
            return t;
    return -1;
}
int main(){
    char *str = "asdadasdsadqwe";
    int index = sequential_search(str,strlen(str),'e');
    printf("%d\n",index);
}