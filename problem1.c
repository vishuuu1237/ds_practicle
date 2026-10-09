
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int size;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));

    if (obj == NULL) return NULL;

    obj->capacity = 100;
    obj->front = 0;
    obj->size = 0;
    obj->data = malloc(obj->capacity * sizeof(int));

    if (obj->data == NULL) {
        free(obj);
        return NULL;
    }

    return obj;
}

void myStackPush(MyStack* obj, int x) {
    // Add the new element to the queue
    int index = (obj->front + obj->size) % obj->capacity;
    obj->data[index] = x;
    obj->size++;

    // Rotate older elements behind the new element
    for (int i = 0; i < obj->size - 1; i++) {
        int value = obj->data[obj->front];
        obj->front = (obj->front + 1) % obj->capacity;

        index = (obj->front + obj->size - 1) % obj->capacity;
        obj->data[index] = value;
    }
}

int myStackPop(MyStack* obj) {
    int value = obj->data[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;

    return value;
}

int myStackTop(MyStack* obj) {
    return obj->data[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    if (obj != NULL) {
        free(obj->data);
        free(obj);
    }
}