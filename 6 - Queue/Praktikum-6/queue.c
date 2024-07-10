#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)
{return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);}

boolean isFull(Queue q)
{return (length(q) == CAPACITY);}

int length(Queue q)
{
    if(isEmpty(q)) return 0;
    else return ((IDX_HEAD(q)<=IDX_TAIL(q))? IDX_TAIL(q)-IDX_HEAD(q)+1 : CAPACITY - (IDX_TAIL(q)-IDX_HEAD(q)-1));
}

void enqueue(Queue *q, ElType val)
{
    if(isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        if(IDX_TAIL(*q)==(CAPACITY-1))
        {
            int a = IDX_HEAD(*q);
            for(int i = a; i <= CAPACITY; i++)
            {
                (*q).buffer[i-a] = (*q).buffer[i]; 
            }
            IDX_HEAD(*q) -= a;
            IDX_TAIL(*q) -= (a-1);
        }
        else
        {
            IDX_TAIL(*q)++;
        }
    }
    (*q).buffer[IDX_TAIL(*q)] = val;
}

void dequeue(Queue *q, ElType *val)
{
    (*val) = (*q).buffer[IDX_HEAD(*q)];
    if(length(*q)==1)
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q)++;
    }
}

void displayQueue(Queue q)
{
    Queue output = q;
    printf("[");
    while (!isEmpty(output))
    {
        int cur; dequeue(&output, &cur);
        printf("%d", cur); if(!isEmpty(output)) printf(",");
    }
    printf("]\n");
}

