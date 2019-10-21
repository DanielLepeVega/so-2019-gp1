#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int primo;
char menos3[10];

void checkPrimes(int numero) {
  if (numero % primo != 0) {
    char charnumero[10];
    sprintf(charnumero, "%d \n", numero);
    write(1, charnumero, sizeof(charnumero));
  }
}

int main(int argc, char **argv){
  char charprimo[10];
  sprintf(menos3, "-3"); // Menos 3 al terminar
  read(0, charprimo, sizeof(charprimo));
  primo = atoi(charprimo);
  if (primo == -3) {
    write(1, menos3, sizeof(menos3));
    return 0;
    }
    fprintf(stderr, "%s \n", charprimo);
    while(1){

      char charnum[10];
      read(0, charnum, sizeof(charnum));

      int intnumero = atoi(charnum);
      if (intnumero == -3) {
        write(1, menos3, sizeof(menos3));
        return 0;
      } else {
        checkPrimes(intnumero);
      }
    }
    return 0;
}