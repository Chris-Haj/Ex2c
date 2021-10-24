#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

void addBigNumbers(char first[], char second[], char result[]);
void sortBigNumbers(char *bigNumbers[],int N);


int main(){
/*
    char a[100]="abc", b[100]="133", c[200];


    addBigNumbers(a, b, c);

    printf("%s",c);*/

    char *bigNumbers[5] = {"32456", "7865549", "1198076", "5437", "345778"};

    sortBigNumbers(*bigNumbers,5);

    for(int i=0;i<5;i++){
        printf("%s",*bigNumbers[i]);
    }

    return 0;
}


void addBigNumbers(char first[], char second[], char result[]){

    for(int i=0;i< strlen(first);i++) {
        if(first[i]<'0'||first[i]>'9'){
            strcpy(result,"error");
            return;
        }
    }
    for (int j = 0; j < strlen(first); j++) {
        if(first[j]<'0'||first[j]>'9'){
            strcpy(result,"error");
            return;
        }
    }
    for(int i=0;i<200;i++) {
            result[i]='\0';
        }


    int asciiNumCodeDfrnce=48;
    int carry=0;

    int i= strlen(first)-1, j= strlen(second)-1, k= strlen(result);

    while(true){


        int n1 = (int)(first[i])-asciiNumCodeDfrnce;
        int n2 = (int)(second[j])-asciiNumCodeDfrnce;

        if(i<0){
            while(j>=0){
                n2 = (int)(second[j])-asciiNumCodeDfrnce;
                result[k++]=(char)(n2+asciiNumCodeDfrnce);
                j--;
            }
        }
        if(j<0){
            while(i>=0){
                n1 = (int)(first[i])-asciiNumCodeDfrnce;
                result[k++]=(char)(n1+asciiNumCodeDfrnce);
                i--;
            }
        }


        if(n1+n2+carry<10){

            result[k]=(n1+n2+carry+asciiNumCodeDfrnce);
        }
        else{
            result[k]=(n1+n2+carry)%10+asciiNumCodeDfrnce;
            carry=(n1+n2)/10;
        }
        k++;

        i--,j--;

        if(i<0&&j<0)
            break;

    }



    for(int c=0;c< strlen(result)/2;c++){
        char temp = result[c];
        result[c] = result[strlen(result)-c-1];
        result[strlen(result)-c-1]=temp;
    }
}

void sortBigNumbers(char *bigNumbers[],int N){

    char *temp = (char *) calloc(sizeof(char),200);

    for(int i=0;i< strlen(bigNumbers);i++){
        for(int j=i+1;j< strlen(*bigNumbers);j++) {
            if(strlen(*bigNumbers[i])> strlen(*bigNumbers[j])){
                strcpy(temp,*bigNumbers[i]);
                strcpy(*bigNumbers[i],*bigNumbers[j]);
                strcpy((*bigNumbers[j]),temp);
            }
        }
    }
    free(temp);
}