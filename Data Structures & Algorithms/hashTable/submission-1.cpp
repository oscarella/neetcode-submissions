class HashTable { // Uses chaining method
 private:
    class Node {
     public:
        int key;
        int val;
        Node *next;
        Node(int key, int val, Node *next = nullptr): key{key}, val{val}, next{next} {}
    };
    int size;
    int capacity;
    vector<Node*> table;
 public:
    // Constructor
    HashTable(int capacity): size{0}, capacity{capacity} {
        for (int i = 0; i < capacity; ++i) table.push_back(new Node{-1, -1});
    }

    // SHOULD ADD DESTRUCTOR

    int hash(int key) {
        return key % capacity;
    }

    void insert(int key, int value) {
        int bucket = hash(key);
        // Either exists or doesn't
        Node *curr = table[bucket];
        while (curr->next && (curr->next)->key != key) curr = curr->next;
        if (!(curr->next)) {
            ++size;
            curr->next = new Node{key, value};
        } else {
            (curr->next)->val = value;
        }
        if (size * 2 >= capacity) resize();
    }

    int get(int key) {
        int bucket = hash(key);
        Node *curr = table[bucket];
        while (curr && curr->key != key) curr = curr->next;
        if (!curr) return -1;
        else return curr->val;
    }

    bool remove(int key) {
        int bucket = hash(key);
        Node *curr = table[bucket];
        while (curr->next && (curr->next)->key != key) curr = curr->next;
        if (!(curr->next)) return false;
        else { // Stitch
            Node *tmp = curr->next;
            curr->next = tmp->next;
            delete(tmp);
            --size;
            return true;
        }
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void resize() {
        capacity *= 2;
        vector<Node *> newTable(capacity);
        for (int i = 0; i < capacity; ++i) {
            newTable[i] = new Node{-1, -1};
        }
        for (int i = 0, n = table.size(); i < n; ++i) {
            Node *curr = (table[i])->next;
            if (curr) { // linked list is non-empty
                while (curr) {
                    Node *tmp = curr; // Move tmp node
                    tmp->next = nullptr;
                    int rehash = hash(tmp->key);
                    
                    Node *newCurr = newTable[rehash];
                    while (newCurr->next) {
                        newCurr = newCurr->next;
                    }
                    newCurr->next = tmp;

                    curr = curr->next;
                }
            }
        }
        table = newTable;
    }
};
