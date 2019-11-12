#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    char *file1 = argv[1];
    char *file2 = argv[2];
    char *pwd = getcwd(NULL,0);
    char path1[strlen(file1) + strlen(pwd) + 2]; // por / y null char '\0'
    char path2[strlen(file2) + strlen(pwd) + 2];
    sprintf(path1, "%s/%s",pwd,file1);
    sprintf(path2, "%s/%s",pwd,file2);
    int filerenamed = link(path1, path2);
    if(filerenamed == 0){
        printf("Archivo renombrado exitosamente de: %s a: %s \n", path1, path2);
    }
    else{
        printf("Archivo NO renombrado\n");
    }
    int filedeleted = unlink(path1);
}