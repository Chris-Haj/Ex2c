#include <stdio.h>
#include <string.h>


void addBigNumbers(char first[], char second[], char result[]);

void sortBigNumbers(char *bigNumbers[], int N);


int main() {

    char test[] = "ih";

    char *p1 = &test[0];
    char *p2 = &test[1];

    char temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("%s\n", test);

    return 0;
}


void addBigNumbers(char first[], char second[], char result[]) {

    for (int i = 0; i < strlen(first); i++) {
        if (first[i] < '0' || first[i] > '9') {
            strcpy(result, "error");
            return;
        }
    }
    for (int j = 0; j < strlen(first); j++) {
        if (first[j] < '0' || first[j] > '9') {
            strcpy(result, "error");
            return;
        }
    }

    int asciiNumCodeDfrnce = 48;
    int carry = 0;

    int i = (int) strlen(first) - 1, j = (int) strlen(second) - 1, k = 0;

    int n1 = 0, n2 = 0, dgt_ttl = 0;

    while (i >= 0 && j >= 0) {

        n1 = first[i] - asciiNumCodeDfrnce;
        n2 = second[j] - asciiNumCodeDfrnce;

        dgt_ttl = n1 + n2 + carry;

        if (dgt_ttl < 9) {
            result[k] = (char) (dgt_ttl + asciiNumCodeDfrnce);
            carry = 0;
        } else {
            carry = dgt_ttl / 10;
            dgt_ttl %= 10;
            result[k] = (char) (dgt_ttl + asciiNumCodeDfrnce);
        }

        i--, j--, k++;
    }

    if (carry != 0)
        result[k++] = (char) (carry + asciiNumCodeDfrnce);

    while (i >= 0 && j < 0)
        result[k++] = first[i--];

    while (j >= 0 && i < 0)
        result[k++] = second[j--];


    result[k] = '\0';


    for (int c = 0; c < k / 2; c++) {
        char temp = result[c];
        result[c] = result[strlen(result) - c - 1];
        result[strlen(result) - c - 1] = temp;
    }


}

void sortBigNumbers(char *bigNumbers[], int N) {


}
