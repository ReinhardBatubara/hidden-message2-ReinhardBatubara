// 12S22001 - Winfrey Nainggolan
// 12s22012 - Reinhard Batubara

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nsisa(unsigned int input_len, unsigned int length, unsigned int *remainder);
void nkolombaris(unsigned int input_len, unsigned int length, unsigned int *remainder, unsigned int *n, unsigned int *k);

int main(int argc, char *argv[]) {

    unsigned int remainder;
    unsigned int length = atoi(argv[1]);

    unsigned char kalimat [101];
    unsigned char input[110];

    fgets(kalimat, 101, stdin);
    strcpy(input, kalimat);

    input[strcspn(input, "\n")] = '\0';

    unsigned int input_len = strlen(input)-1;

    nsisa(input_len, length, &remainder);

    unsigned int n, k;
    nkolombaris(input_len, length, &remainder, &n, &k);

    unsigned int sisa = 0;
    sisa = k - input_len;
    unsigned int l = input_len;
    for (unsigned int i = 0; i < sisa; i++)
    {
        input[l]='#';
        l= l+1;
    }
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < length; j++) {
            unsigned int index = i * length + j;
            printf("%c", input[index]);
        }
        if (i + 1 != n) {
            printf("\n");
        }
    }
    printf("\n");

    for (unsigned int i = 0; i < length; i++){
        for (unsigned int j = i; j <= k; j+=length)
        {
            if (input[j]=='\0')
            {
                continue;
            } else {
                printf("%c", input[j]);
            }
        }
    }

    printf("\n");

    return 0;
}

void nsisa(unsigned int input_len, unsigned int length, unsigned int *remainder){
    if (input_len % length == 0)
    {
        *remainder = 0;
    } else {
        *remainder = 1;
    }
}

void nkolombaris(unsigned int input_len, unsigned int length, unsigned int *remainder, unsigned int *n, unsigned int *k){
    *n = input_len / length + *remainder;
    *k = length * (*n);
}
