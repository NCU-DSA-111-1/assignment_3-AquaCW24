#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ITERATION_TIMES 20
#define MAX_STR_SIZE 300

void rand_str(char *, size_t);

int main(void) {


    for (int i = 1; i <= ITERATION_TIMES; i++) {
        char pathstr[100];
        sprintf(pathstr, "./GrepTextFile/File%d.txt", i);

        FILE *fp = fopen(pathstr, "w");

        srand(time(NULL) + i);
        char str[] = {[MAX_STR_SIZE + 1] = '\1'};  // make the last character non-zero so we can test based on it later
        rand_str(str, MAX_STR_SIZE);
        fprintf(fp, "%s",str);
        fclose(fp);
    }
}

void rand_str(char *dest, size_t length) {
    char charset[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index = (double)rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}
