#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ITERATION 20

int main(){
    char str[200];
    system("./obj/grepwordgen.o");
    puts("-----------Arithmetic Encoding-----------");
    for(int i = 1; i <= ITERATION; i++){
        strcpy(str, "\0");
        printf("Arithmetic Approach FILE-%d\n\n", i);
        sprintf(str, "./obj/arth.o -e ./GrepTextFile/File%d.txt ./IO/arith/arith_out", i);
        system(str);
        system("./obj/arth.o -d ./IO/arith/arith_out ./IO/arith/arith_back.txt");
        puts("------------------------------");
    }
    puts("\n-----------Huffman Encoding-----------");
    for(int i = 1; i <= ITERATION; i++){
        printf("Huffman Approach FILE-%d\n\n", i);
        strcpy(str, "\0");
        sprintf(str, "./obj/huff.o -e ./GrepTextFile/File%d.txt -b ./IO/huff/huff_booktable.txt -o ./IO/huff/huff_out.txt", i);
        system(str);
        system("./obj/huff.o -d ./IO/huff/huff_out -b ./IO/huff/huff_booktable.txt -o IO/huff/huff_back.txt");
        puts("------------------------------");
    }

}
