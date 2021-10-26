#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1


void addBigNumbers(char first[], char second[], char result[]);
void sortBigNumbers(char *bigNumbers[],int N);


int main(){




    char a[]="123",b[]="123",c[100];

    addBigNumbers(a,b,c);



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

    int i= strlen(first)-1, j= strlen(second)-1, k = 0;

    int n1=0,n2=0,dgt_ttl=0;

    while(i>=0&&j>=0){

        n1 = first[i] - asciiNumCodeDfrnce;
        n2 = second[j] - asciiNumCodeDfrnce;

        dgt_ttl = n1+n2+carry;

        if(dgt_ttl<9) {
            result[k] = (char) (dgt_ttl + asciiNumCodeDfrnce);
            carry=0;
        }

        else{
            carry = dgt_ttl/10;
            dgt_ttl%=10;
            result[k] = (char) (dgt_ttl + asciiNumCodeDfrnce);
        }

        i--;
        j--;
        k++;
    }

//    printf("%s",result);

  /*  for(int c=0;c<k/2;c++){
        char temp = result[c];
        result[c] = result[strlen(result)-c-1];
        result[strlen(result)-c-1]=temp;
    }*/


}

void sortBigNumbers(char *bigNumbers[],int N){



}