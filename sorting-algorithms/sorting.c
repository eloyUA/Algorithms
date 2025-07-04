#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void errorSorting(char msg[]) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void swap(typeE *x, typeE *y) {
    typeE aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void bubbleSort(typeE v[], int start, int end) {
    typeE aux;
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void selectionSort(typeE v[], int start, int end) {
    typeE aux;
    int pmin;
    for (int i = start; i < end; i++) {
        pmin = i + 1;
        for (int j = i + 1; j <= end; j++) {
            if (v[j] < v[pmin]) {
                pmin = j;
            }
        }

        if (v[pmin] < v[i]) {
            aux = v[i];
            v[i] = v[pmin];
            v[pmin] = aux;
        }
    }
}

void insertionSort(typeE v[], int start, int end) {
    int j;
    typeE aux;
    for (int i = start; i < end; i++) {
        j = i;
        aux = v[i + 1];
        while (j >= start && aux < v[j]) {
            v[j + 1] = v[j];
            j -= 1;
        }
        v[j + 1] = aux;
    }
}

// [start, end]
void mergeSort(typeE v_out[], typeE v[], int start, int end) {
    if (end - start == 0) {
        v_out[0] = v[start];
    }
    else if (end - start == 1) {
        if (v[start] <= v[end]) {
            v_out[0] = v[start];
            v_out[1] = v[end];
        }
        else {
            v_out[0] = v[end];
            v_out[1] = v[start];
        }
    }
    else {
        int h = (start + end) / 2;
        int sizeLeft = (h - start + 1);
        int sizeRight = (end - h);

        typeE *left = malloc(sizeLeft * sizeof(typeE));
        typeE *rigth = malloc(sizeRight * sizeof(typeE));
        if (left == NULL || rigth == NULL) 
            errorSorting("malloc");
        mergeSort(left, v, start, h);
        mergeSort(rigth, v, h + 1, end);
        
        int l = 0, r = 0, cont = 0;
        while (l < sizeLeft && r < sizeRight) {
            if (left[l] < rigth[r]) {
                v_out[cont] = left[l];
                l += 1;
                cont += 1;
            }
            else if (left[l] > rigth[r]) {
                v_out[cont] = rigth[r];
                r += 1;
                cont += 1;
            }
            else {
                v_out[cont] = left[l];
                v_out[cont + 1] = rigth[r];
                l += 1;
                r += 1;
                cont += 2;
            }
        }

        while (l < sizeLeft) {
            v_out[cont] = left[l];
            l += 1;
            cont += 1;
        }

        while (r < sizeRight) {
            v_out[cont] = rigth[r];
            r += 1;
            cont += 1;
        }
        free(left);
        free(rigth);
    }
}

void quickSort(typeE v[], int start, int end) {
    if (end - start <= 0) {
        return;
    }
    else if (end - start == 1) {
        if (v[start] > v[end]) {
            swap(&v[start], &v[end]);
        }
    }
    else {
        // Choose pibot
        int h = (start + end) / 2;
        if ((v[h] < v[start] && v[h] > v[end]) || 
            (v[h] > v[start] && v[h] < v[end])) {
            swap(&v[h], &v[start]);
        }
        else if ((v[end] < v[start] && v[end] > v[h]) ||
                (v[end] > v[start] && v[end] < v[h])) {
            swap(&v[end], &v[start]);
        }

        int leftBarPos = end, rightBarPos = end;
        while (leftBarPos > start) {
            if (v[leftBarPos] > v[start]) {
                if (leftBarPos < rightBarPos) {
                    swap(&v[leftBarPos], &v[rightBarPos]);
                }
                leftBarPos -= 1;
                rightBarPos -= 1;
            }
            else if (v[leftBarPos] <= v[start]) {
                leftBarPos -= 1;
            }
        }
        swap(&v[start], &v[rightBarPos]);
        
        quickSort(v, start, rightBarPos - 1);
        quickSort(v, rightBarPos + 1, end);
    }
}

void heapSort(typeE v[], int start, int end) {
    int minHeapPos = -1;
    typeE *minHeap = malloc((end - start + 1) * sizeof(typeE));
    if (minHeap == NULL)
        errorSorting("malloc");

    typeE auxE;
    int childPos, parentPos;
    minHeapPos += 1;
    minHeap[minHeapPos] = v[start];
    for (int i = start + 1; i <= end; i++) {
        minHeapPos += 1;
        minHeap[minHeapPos] = v[i];
        
        childPos = minHeapPos;
        parentPos = (childPos - 1) / 2;
        while (parentPos >= 0 && minHeap[childPos] < minHeap[parentPos]) {
            auxE = minHeap[parentPos];
            minHeap[parentPos] = minHeap[childPos];
            minHeap[childPos] = auxE;

            childPos = parentPos;
            parentPos = (childPos - 1) / 2;
        }
    }

    int childRightPos, childLeftPos, auxPos;
    for (int i = start; i < end; i++) {
        v[i] = minHeap[0];
        swap(&minHeap[0], &minHeap[minHeapPos]);
        minHeapPos -= 1;

        parentPos = 0;
        childLeftPos = 2*parentPos + 1;
        childRightPos = 2*parentPos + 2;
        while (childRightPos <= minHeapPos &&
                (minHeap[parentPos] > minHeap[childLeftPos] ||
                minHeap[parentPos] > minHeap[childRightPos])) {
                    
            if (minHeap[childLeftPos] > minHeap[childRightPos]) {
                auxPos = childRightPos;
            }
            else {
                auxPos = childLeftPos;
            }

            auxE = minHeap[auxPos];
            minHeap[auxPos] = minHeap[parentPos];
            minHeap[parentPos] = auxE;

            parentPos = auxPos;
            childLeftPos = 2*parentPos + 1;
            childRightPos = 2*parentPos + 2;
        }

        if (childRightPos > minHeapPos &&
            childLeftPos <= minHeapPos &&
            minHeap[parentPos] > minHeap[childLeftPos]) {
                
            auxE = minHeap[childLeftPos];
            minHeap[childLeftPos] = minHeap[parentPos];
            minHeap[parentPos] = auxE;
        }
    }
    v[end] = minHeap[0];
    free(minHeap);
}