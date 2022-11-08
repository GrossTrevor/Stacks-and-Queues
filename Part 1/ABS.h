#include <iostream>
using namespace std;
template <typename T>

class ABS {
    float scaleFactor = 2.0f;
    unsigned int capacity;
    unsigned int currentSize;
    T* data;

public:

    ABS() {
        capacity = 1;
        data = new T[capacity];
        currentSize = 0;
    }

    ABS(int cap) {
        capacity = cap;
        data = new T[capacity];
        currentSize = 0;
    }

    ABS(const ABS& d) {
        capacity = d.capacity;
        currentSize = d.currentSize;
        data = new T[capacity];
        for (unsigned int x = 0; x < d.currentSize; x++)
            data[x] = d.data[x];
    }

    ABS& operator=(const ABS& d) {
        ABS op;
        op.capacity = d.capacity;
        op.currentSize = d.currentSize;
        op.data = new T[capacity];
        for (unsigned int x = 0; x < d.currentSize; x++)
            op.data[x] = d.data[x];
        return *op;
    }

    ~ABS() {
        delete[] data;
    }

    void push(T dat) {
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

    T pop() {
        if (currentSize == 0)
            throw runtime_error("No elements in array");
        T element = data[currentSize - 1];
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
        return data[currentSize - 1];
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