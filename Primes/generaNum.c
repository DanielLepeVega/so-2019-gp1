#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
    char char1 [10];
    char menos3[10];
    sprintf(menos3, "-3"); // Cuando terminas pones menos 3
    for (int i = 2; i < 101; i++){
        sprintf(char1, "%d \n" ,i);
        write(1,char1,sizeof(char1));
    }
    write(1, menos3, sizeof(menos3));
    return 0;
}