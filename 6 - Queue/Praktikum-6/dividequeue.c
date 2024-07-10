#include "dividequeue.h"

void divideQueue(Queue *queue, Queue *oddQueue, Queue *evenQueue)
{
    Queue odd; CreateQueue(&odd);
    Queue even; CreateQueue(&even);
    Queue input = *queue;
    while (!isEmpty(input))
    {
        int cur; dequeue(&input, &cur);
        if(cur%2) enqueue(&odd, cur);
        else enqueue(&even, cur);
    }
    *oddQueue = odd;
    *evenQueue = even;
}