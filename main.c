#include <stdio.h>
#include <stdlib.h>

const long MAXIMUM_RAW_INPUT_LENGTH_NUMBER = 10;

long getInputArrayLength();
long* getInputArray(unsigned long length);
void printArray(const long* array, long length);
void swap(long* first, long* second);
void selectionSort(long* array, long length);

int main() {
    long inputArrayLength = getInputArrayLength();
    long* inputArray = getInputArray(inputArrayLength);

    printArray(inputArray, inputArrayLength);
    selectionSort(inputArray, inputArrayLength);
    printArray(inputArray, inputArrayLength);

    free(inputArray);

    return 0;
}

long getInputArrayLength() {
    long length = 0;

    while (length <= 0) {
        char* buffer = malloc(sizeof(char) * MAXIMUM_RAW_INPUT_LENGTH_NUMBER);
        scanf("%s", buffer);
        length = strtol(buffer, NULL, 10);
        free(buffer);
    }

    return length;
}

long* getInputArray(const unsigned long length) {
    long *array = malloc(sizeof(long) * length);

    for (long i = 0; i < length; i++) {
        char* buffer = malloc(sizeof(char) * MAXIMUM_RAW_INPUT_LENGTH_NUMBER);
        scanf("%s",  buffer);
        *(array + i) = strtol(buffer, NULL, 10);
        free(buffer);
    }

    return array;
}

void printArray(const long* array, const long length) {
    printf("Array (%ld) [", length);
    for (long i = 0; i < length; i++) {
        printf("%ld%s", *(array + i), i + 1 == length ? "" : ", ");
    }
    printf("]\n");
}

void swap(long* first, long* second) {
    const long tmp = *first;
    *first = *second;
    *second = tmp;
}

void selectionSort(long* array, long length) {
    for (long i = length - 1; i >= 0; i--) {
        long max = *(array + i);
        long maxIndex = i;

        for (long j = i - 1; j >= 0; j--) {
            if (*(array + j) > max) {
                max = *(array + j);
                maxIndex = j;
            }
        }

        swap(array + i, array + maxIndex);
    }
}
