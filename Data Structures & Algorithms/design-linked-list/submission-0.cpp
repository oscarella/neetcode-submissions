struct Node {
    int val;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(int val): val{val} {}
};

class MyLinkedList {
    Node *head;
    Node *tail;
    int size; // Does not count two dummy nodes
public:
    MyLinkedList(): head{new Node(-1)}, tail{new Node(-1)}, size{0} {
        head->next = tail;
        tail->prev = head;
    }

    ~MyLinkedList() {
        Node *curr = head;
        while (curr) {
            Node *tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }
    
    int get(int index) {
        // Invalid indices: index < 0 || index >= size
        if (index >= size || index < 0) return -1;

        Node *curr = head->next; // Initialized to starting node
        int counter = 0;
        while (counter < index) {
            curr = curr->next;
            ++counter;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        Node *insert = new Node(val);
        insert->next = head->next;
        insert->prev = head;
        head->next->prev = insert;
        head->next = insert;
        ++size;
    }
    
    void addAtTail(int val) {
        Node *insert = new Node(val);
        insert->next = tail;
        insert->prev = tail->prev;
        tail->prev->next = insert;
        tail->prev = insert;
        ++size;
    }

    // If index equals the length of linked list, appended at the end
    // If index > length, node will not be inserted
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node *prevNode = head;
        int counter = 0;
        while (counter < index) {
            prevNode = prevNode->next;
            ++counter;
        }
        Node *insert = new Node(val);
        insert->prev = prevNode;
        insert->next = prevNode->next;
        prevNode->next->prev = insert;
        prevNode->next = insert;
        ++size;
    }
    
    // Delete index-th node in the linked list if index is valid
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node *prevNode = head;
        int counter = 0;
        while (counter < index) {
            prevNode = prevNode->next;
            ++counter;
        }
        Node *del = prevNode->next;
        del->next->prev = prevNode;
        prevNode->next = del->next;
        delete del;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */