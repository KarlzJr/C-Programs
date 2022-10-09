#include "pq.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct PriorityQueue {
    uint32_t head;
    uint32_t tail;
    uint32_t size;
    uint32_t capacity;
    Node **items;
} PriorityQueue;

PriorityQueue *pq_create(uint32_t capacity) {
    PriorityQueue *p = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    if (p) {
        p->head = 0;
        p->tail = 0;
        p->size = 0;
        p->capacity = capacity;
        p->items = (Node **) calloc(capacity, sizeof(Node));
        if (!p->items) {
            free(p);
            p = NULL;
        }
    }
    return p;
}

void pq_delete(PriorityQueue **q) {
    if (*q && (*q)->items) {
        free(*q);
        free((*q)->items);
        *q = NULL;
    }
}

bool pq_empty(PriorityQueue *q) {
    return q->size == 0;
}

bool pq_full(PriorityQueue *q) {
    return q->size == q->capacity;
}

uint32_t pq_size(PriorityQueue *q) {
    return q->size;
}

//alot like what Dr.Long mention in lecture about finind the successor
uint64_t next(uint64_t position, uint64_t capacity) {
    return ((position + 1) % capacity);
}

bool enqueue(PriorityQueue *q, Node *n) {
    if (pq_full(q)) {
        return false;
    }
    q->items[q->tail] = n;
    uint32_t loc = q->tail;
    if (loc != q->head) {
        while (q->items[loc]->frequency < q->items[loc - 1]->frequency && loc != q->head) {
            q->items[loc] = q->items[loc - 1];
            q->items[loc - 1] = n;
            if (loc != 0) {
                loc -= 1;
            } else {
                loc = q->capacity - 1;
            }
        }
    }

    q->tail = next(q->tail, q->capacity);
    q->size += 1;
    return true;
}

bool dequeue(PriorityQueue *q, Node **n) {
    if (pq_empty(q)) {
        return false;
    }
    if (q->size == 1) {
        q->size -= 1;
        *n = q->items[0];
        return true;
    }
    *n = q->items[0];
    q->items[0] = q->items[q->size - 1];
    q->size -= 1;
    return true;
}
/*
void pq_print(PriorityQueue *q) {
    printf("[");
    if (pq_full(q)) {
        for (uint32_t i = 0; i < q->capacity; i += 1) {
            printf("Node Frequency: %lu", q->items[i]->frequency);
            if (i + 1 != q->capacity) {
                printf(", ");
            }
        }
    } else if (q->head < q->tail) {
        for (uint32_t i = q->head; i < q->tail; i += 1) {
            printf("Node Frequency: %lu", q->items[i]->frequency);
            if (i + 1 != q->tail) {
                printf(", ");
            }
        }

    } else {
        for (uint32_t i = q->tail; i < q->head; i += 1) {
            printf("Node Frequency: %lu", q->items[i]->frequency);
            if (i + 1 != q->head) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}*/
