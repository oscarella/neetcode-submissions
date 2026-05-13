class LRUCache {
    // Representation of deque
    class Node {
     public:
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int key = -1, int value = -1): key{key}, value{value}, prev{nullptr}, next{nullptr} {}
    };
    int size;
    int capacity;
    Node *front;
    Node *back;
    unordered_map<int, Node*> m;
public:
    LRUCache(int capacity): size{0}, capacity{capacity}, front{new Node{}}, back{new Node{}} {
        front->next = back;
        back->prev = front;
    }

    ~LRUCache() {
        Node *curr = front;
        while(curr) {
            Node *tmp = curr;
            curr = curr->next;
            delete(tmp);
        }
    }
    
    int get(int key) {
        if (!m.count(key)) return -1;
        // else (MOVE TO BACK OF DEQUE)
        Node *curr = m[key];
        if (curr->next != back) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->prev = back->prev;
            curr->next = back;
            back->prev->next = curr;
            back->prev = curr;
        }
        return curr->value;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            Node *curr = m[key];
            if (curr->next != back) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->prev = back->prev;
                curr->next = back;
                back->prev->next = curr;
                back->prev = curr;
            }
            curr->value = value;
        } else {
            if (size >= capacity) { // Delete least frequently used node from hashmap and deque
                Node *delNode = front->next;
                m.erase(delNode->key); // Delete from hashmap
                // Delete from deque
                delNode->prev->next = delNode->next;
                delNode->next->prev = delNode->prev;
                delete(delNode);
                --size;
            }
            // Insert (key, value) at the back & in hashmap
            Node *newNode = new Node{key, value};
            m[key] = newNode; // Insert into hashmap
            // Insert into deque
            newNode->prev = back->prev;
            newNode->next = back;
            newNode->prev->next = newNode;
            back->prev = newNode;
            ++size;
        }
    }
};
