#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *fileName = argv[1];
    char *wordF = argv[2];
    char *newWord = argv[3];
    char *pwd = getcwd(NULL,0);
    char path1[strlen(fileName) + strlen(pwd) + 2];
    char word[100];
    char c;
    int fd = open(fileName, O_RDONLY);
    int tempFd = open("tmp.txt", O_WRONLY | O_CREAT, 0666);
    int index = 0;

    while(read(fd, &c, 1)){
        if(c != ' '){
            word[index++] = c;
        }else{
            word[index] = '\0';
            index = 0;
            //printf("La palabra es %s\n", word);
            if(!strcmp(word, wordF)){
                write(tempFd, newWord, strlen(newWord));
                write(tempFd, " ", 1);
            }else{
                write(tempFd, word, strlen(word));
                write(tempFd, " ", 1);
            }
        }
    }
    word[index] = '\0';
    //printf("La palabra es %s\n", word);
    if(!strcmp(word, wordF)){
        write(tempFd, newWord, strlen(newWord));
        write(tempFd, " ", 1);
    }else{
        write(tempFd, word, strlen(word));
        write(tempFd, " ", 1);
    }
    close(fd);
    close(tempFd);
    unlink(fileName);
    link("tmp.txt", fileName);
    unlink("tmp.txt");
    return 0;
}