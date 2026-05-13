class LinkedList {

private:
    struct Node {
        int val;
        Node *next;
    };
    Node *head;
    Node *tail;

public:
    // Initialize empty linked list
    LinkedList(): head{nullptr}, tail{nullptr} {}

    int get(int index) { // index >= 0
        Node *curr = head;
        int i = 0;
        while (curr != nullptr && i < index) {
            curr = curr->next;
            ++i;
        }
        if (!curr) return -1;
        else return curr->val;
    }

    void insertHead(int val) {
        if (head == nullptr) { // 0 Nodes
             tail = head = new Node{val, nullptr};
        } else { // At least 1 Node
            head = new Node{val, head};
        }
    }
    
    void insertTail(int val) {
        if (head == nullptr) {
            tail = head = new Node{val, nullptr};
        } else {
            tail->next = new Node{val, nullptr};
            tail = tail->next;
        }
    }

    bool remove(int index) { // index >= 0
        if (head == nullptr) return false; // Empty linked list
        // One Node is guranteed
        if (!index) { // Remove first Node
            if (head == tail) { // Result: Empty Linked List
                delete(head);
                head = tail = nullptr;
                return true;
            } else { // Result: Head is modified
                Node *tmp = head->next;
                delete(head);
                head = tmp;
                return true;
            }
        } else { // Remove non-first Node
            Node *curr = head;
            int it = 0;
            while (curr != nullptr && it < (index-1)) {
                curr = curr->next;
                ++it;
            }
            if (!curr || !(curr->next)) return false;
            if (!(curr->next->next)) { // Modify tail
                tail = curr;
            }
            Node *tmp = curr->next;
            curr->next = curr->next->next;
            delete(tmp);
            return true;
        }
    }

    vector<int> getValues() {
        vector<int> retv;
        Node *curr = head;
        while (curr != nullptr) {
            retv.push_back(curr->val);
            curr = curr->next;
        }
        return retv;
    }
};
