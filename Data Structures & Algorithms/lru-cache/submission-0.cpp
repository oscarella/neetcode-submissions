class LRUCache {

    class Node {
     public:
        int key;
        Node *prev;
        Node *next;
        Node(int key = -1): key{key}, prev{nullptr}, next{nullptr} {}
    };

    int capacity; // >= 1
    int size;
    Node *front;
    Node *back;
    unordered_map<int, int> m;

public:

    void update(int key) { // invalid key set as -1
        Node *curr = front;
        while (curr->key != key) curr = curr->next;
        // curr points to correct key
        if (curr->next == back) return; // curr is already at back
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        curr->prev = back->prev;
        curr->next = back;
        back->prev->next = curr;
        back->prev = curr;
    }

    void insert(int key) {
        Node *newNode = new Node{key};
        newNode->prev = back->prev;
        newNode->next = back;
        back->prev->next = newNode;
        back->prev = newNode;
    }

    int remove() { // deletes least used node and returns its key
        Node *delNode = front->next;
        front->next = delNode->next;
        delNode->next->prev = delNode->prev;
        int retkey = delNode->key;
        delete(delNode);
        return retkey;
    }

    // Initialize size
    LRUCache(int capacity): capacity{capacity}, size{0}, front{new Node{}}, back{new Node{}} {
        front->next = back;
        back->prev = front;
    }

    ~LRUCache() {
        Node *curr = front;
        while (curr) {
            Node *tmp = curr;
            curr = curr->next;
            delete(tmp);
        }
    }
    
    int get(int key) { // O(1): return val of key; otherwise -1
        if (m.count(key)) {
            update(key);
            return m[key];
        }
        else return -1;
    }
    
    // O(1): updates value of key if exists, otherwise add
    // if new pair exceeds capacity, remove least recently used key*
    void put(int key, int value) {
        if (m.count(key)) {
            update(key);
            m[key] = value;
            return;
        }  // Key already exists
        // Add new [key, value]
        if (size >= capacity) {
            int remKey = remove();
            m.erase(remKey);
            --size;
        }
        insert(key);
        m[key] = value;
        ++size;
    }
};
