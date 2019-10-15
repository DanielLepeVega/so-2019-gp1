#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int key = 27; // numero usado para generar el id del bloque de memoria
    int shmid = shmget(key,100,IPC_CREAT); // crear bloque de memoria generico
    char *word;

    word = (char *)shmat(shmid, NULL, 0); // casting del tipo de valor del bloque, porque era generico
    //word = "Hello world"; //Apuntador, reemplaza el apuntador
    sprintf(word, "Hello world"); // word[0] = H ...
    while(word[0] == 'H'){
        sleep(1);
    }
    printf("Sali del ciclo: %s", word);
    return 0;
}