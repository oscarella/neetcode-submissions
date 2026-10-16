class DynamicArray {
    int *data;
    int size;
    int capacity;
public:

    DynamicArray(int capacity): data{new int[1]}, size{0}, capacity{1} {}

    int get(int i) {
        if (i >= size) throw;
        return data[i];
    }

    void set(int i, int n) {
        if (i >= size) throw;
        data[i] = n;
    }

    void pushback(int n) {
        if (size == capacity)
            resize();
        data[size++] = n;
    }

    int popback() {
        if (!size) throw;
        int lastElement = data[size - 1];
        --size;
        return lastElement;
    }

    void resize() {
        capacity *= 2;
        int *newData = new int[capacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
