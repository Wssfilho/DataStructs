#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArray(int array[], int n);
int maximo(int array[], int n);
int minimo(int array[], int n);

int main(void) {
  srand(time(NULL));
  int array[50];

  geraArray(array, 50);
  int maiorValor = maximo(array, 50);
  int menorValor = minimo(array, 50);

  int pontoMedio = (maiorValor + menorValor) / 2;

  int maioresMedio = 0, menoresMedio = 0;
    for (int i = 0; i < 50; i++) {
    if (array[i] > pontoMedio) {
      maioresMedio++;
    } else if (array[i] < pontoMedio) {
      menoresMedio++;
    }
  }

  printf("Ponto medio: %i\n", pontoMedio);
  printf("Menores que o ponto medio: %i\n", menoresMedio);
  printf("Maiores que o ponto medio: %i\n", maioresMedio);
}

void geraArray(int array[], int n) {
  for (int i = 0; i < n; i++)
    array[i] = rand() % 100;
}

int maximo(int array[], int n) {
  int max = 0;

  for (int i = 0; i < n; i++)
    if (array[i] > max)
      max = array[i];

  return max;
}

int minimo(int array[], int n) {
  int min = 100;

  for (int i = 0; i < n; i++)
    if (array[i] < min)
      min = array[i];

  return min;
}