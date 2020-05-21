#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "book.h"
#include "main.h"
BookDB read_db(char *filename){
    FILE *fin = fopen(filename,"r");
    int n;
    fscanf(fin,"%d\n",&n);
}