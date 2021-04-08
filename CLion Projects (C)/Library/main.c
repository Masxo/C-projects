#include "dataStructures.h"

int comp(const void* a , const void *b) {
    return *((int *)&a)-*((int *)&b);
}

int main() {
    DoubleLinkedList dll = createDLL(DATA_TYPE_INTEGER);
    for(int i = 0; i < 5; i++) {
        dll = addDLLNode(&dll,(void *)i);
    }
}