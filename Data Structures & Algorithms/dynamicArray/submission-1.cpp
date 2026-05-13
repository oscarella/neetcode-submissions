class DynamicArray {
public:
    int *arr;
    int capacity, len;

    DynamicArray(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        len = 0;
    }

    int get(int i) { // O(1)
        // Assuming i is valid
        return arr[i];
    }

    void set(int i, int n) {
        // Assume i is valid
        arr[i] = n;
    }

    void pushback(int n) {
        // push to end of array
        if (len == capacity) resize();
        arr[len++] = n;
    }

    int popback() {
        // pops and returns end
        int retval = arr[len - 1];
        --len;
        return retval;
    }

    void resize() {
        if (len == capacity) {
            capacity *= 2;
            int *newarr = new int[capacity];
            for (int i = 0; i < len; ++i)
                newarr[i] = arr[i];
            delete[] arr;
            arr = newarr;
        }
    }

    int getSize() {
        return len;
    }

    int getCapacity() {
        return capacity;
    }
};
