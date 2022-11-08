#include <iostream>
using namespace std;
template <typename T>

class ABQ {
    float scaleFactor = 2.0f;
    unsigned int capacity;
    unsigned int currentSize;
    T* data;

public:

    ABQ() {
        capacity = 1;
        data = new T[capacity];
        currentSize = 0;
    }

    ABQ(int cap) {
        capacity = cap;
        data = new T[capacity];
        currentSize = 0;
    }

    ABQ(const ABQ& d) {
        capacity = d.capacity;
        currentSize = d.currentSize;
        data = new T[capacity];
        for (unsigned int x = 0; x < d.currentSize; x++)
            data[x] = d.data[x];
    }

    ABQ& operator=(const ABQ& d) {
        ABQ op;
        op.capacity = d.capacity;
        op.currentSize = d.currentSize;
        op.data = new T[capacity];
        for (unsigned int x = 0; x < d.currentSize; x++)
            op.data[x] = d.data[x];
        return *op;
    }

    ~ABQ() {
        delete[] data;
    }

    void enqueue(T dat) {
        if (currentSize == capacity) {
            capacity *= scaleFactor;
            T* newData = new T[capacity];
            for (unsigned int x = 0; x < currentSize; x++)
                newData[x] = data[x];
            delete[] data;
            data = newData;
        }
        data[currentSize] = dat;
        currentSize++;
    }

    T dequeue() {
        if (currentSize == 0)
            throw runtime_error("No elements in array");
        T element = data[0];
        for (unsigned int x = 0; x < currentSize - 1; x++)
            data[x] = data[x + 1];
        currentSize--;
        if (((double)currentSize / (double)capacity) < (1.0 / scaleFactor)) {
            capacity /= scaleFactor;
            T* newData = new T[capacity];
            for (unsigned int x = 0; x < currentSize; x++)
                newData[x] = data[x];
            delete[] data;
            data = newData;
        }
        return element;
    }

    T peek() {
        if (currentSize == 0)
            throw runtime_error("No elements in array");
        return data[0];
    }

    unsigned int getSize() {
        return currentSize;
    }

    unsigned int getMaxCapacity() {
        return capacity;
    }

    T* getData() {
        return data;
    }
};