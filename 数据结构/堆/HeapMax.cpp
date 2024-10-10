struct MaxHeap
{
    Etype *heap;
    int HeapSize;
    int MaxSize;
};

void MaxHeapInit(MaxHeap &H)
{
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
}

bool MaxHeapInsert(MaxHeap &H, Etype &x)
{
    if (H.HeapSize == H.MaxSize)
    {
        return false;
    }

    int = ++H.HeapSize;
    while (i != 1 && x > H.heap[i / 2])
    {
        H.heap[i] = H.heap[i / 2];
        i = i / 2;
    }

    H.heap[i] = x;

    return true;
}

void MaxHeapDelete(MaxHeap &H, Etype &x)
{
    if (H.HeapSize == 0)
    {
        return false;
    }

    x = H.heap[1];
    H.heap[0] = H.heap[H.HeapSize - 1];
    int index = 1;
    int son = index * 2;

    while (son < H.HeapSize && )
    {
        if (H.heap[son] > H.heap[son + 1])
        {
            H.heap[index] = H.heap[son];
            index = son;
            son = index * 2;
        }
        else
        {
            H.heap[index] = H.heap[son + 1];
            index = son + 1;
            son = index * 2;
        }
    }
}