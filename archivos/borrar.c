#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char *file1 = argv[1];
    char *pwd = getcwd(NULL,0);
    char path1[strlen(file1) + strlen(pwd) + 2];
    sprintf(path1, "%s/%s",pwd,file1);
    int filedeleted = unlink(path1);
    if(filedeleted == 0){
        printf("Archivo borrado exitosamente\n");
    }
    else{
        printf("Archivo NO borrado\n");
    }
}