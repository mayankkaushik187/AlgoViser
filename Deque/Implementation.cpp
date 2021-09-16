#include <bits/stdc++.h>
using namespace std;

struct Deque
{
    int *arr;
    int cap, size, front;
    Deque(int c)
    {
        arr = new int[c];
        cap = c;
        front = 0;
        size = 0;
    }

    void deleteFront()
    {
        if (isEmpty())
            return;

        front = (front + 1) % cap;
        size--;
    }

    void deleteRear()
    {
        if (isEmpty())
            return;

        size--;
    }

    void insertRear(int x)
    {
        if (isFull())
            return;
        int newRear = (front + size) % cap;
        arr[newRear] = x;
        size++;
    }

    void insertFront(int x)
    {
        if (isFull())
            return;

        front = (front + cap - 1) % cap;
        arr[front] = x;
        size++;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[size - 1];
    }
    int size()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return cap == size;
    }
};
