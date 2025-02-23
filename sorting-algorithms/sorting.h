#ifndef _SORTING_H
#define _SORTING_H

typedef float typeE;

void bubbleSort(typeE[], int, int);

void selectionSort(typeE[], int, int);

void insertionSort(typeE[], int, int);

void mergeSort(typeE[], typeE[], int, int);

void quickSort(typeE[], int, int);

void heapSort(typeE[], int, int);

int parallelizeSortingAlgorithm(typeE[], int, int, char *);

#endif