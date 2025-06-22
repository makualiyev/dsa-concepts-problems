#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int capacity;
    int size;
} DynamicArray;

DynamicArray* createDynamicArray(int capacity) {
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    arr->data = (int *)malloc(sizeof(int) * capacity);
    arr->capacity = capacity;
    arr->size = 0;
    return arr;
}

void resizeArray(DynamicArray* arr, int newCapacity) {
    int *newData = (int *)malloc(newCapacity * sizeof(int));
    for (int i = 0; i < arr->size; i++) {
        newData[i] = arr->data[i];
    }
    free(arr->data);
    arr->data = newData;
    arr->capacity = newCapacity;
}

void insertElement(DynamicArray* arr, int element) {
    if (arr->size == arr->capacity) {
        resizeArray(arr, arr->capacity * 2);
    }
    arr->data[arr->size] = element;
    arr->size++;
}

int removeElement(DynamicArray* arr) {
    if (arr->size == 0) {
        printf("Error: Array is empty\n");
        return -1;
    }
    int element = arr->data[arr->size - 1];
    arr->size--;
    if (arr->size < arr->capacity / 4) {
        resizeArray(arr, arr->capacity / 2);
    }
    return element;
}

void freeDynamicArray(DynamicArray* arr) {
    free(arr->data);
    free(arr);
}

int main(int argc, char *argv[])
{
    DynamicArray *arr = createDynamicArray(2);

    insertElement(arr, 10);
    insertElement(arr, 20);
    insertElement(arr, 30);

    printf("Array elements: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");

    int removedElement = removeElement(arr);
    printf("Removed element: %d\n", removedElement);

    freeDynamicArray(arr);

    return 0;
}

