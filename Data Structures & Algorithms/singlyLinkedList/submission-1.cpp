class LinkedNode {
 public:
    int val;
    LinkedNode *next;
    // Ctors
    LinkedNode(int val): val{val}, next{nullptr} {}
    LinkedNode(int val, LinkedNode *next): val{val}, next{next} {}
};

class LinkedList {
private:
    LinkedNode *head;
    LinkedNode *tail;
public:
    LinkedList(): head{new LinkedNode{-1}}, tail{head} {}

    int get(int index) { // returns the i-th node
        LinkedNode *curr = head->next;
        int it = 0;
        while(curr != nullptr && it < index) {
            ++it;
            curr = curr->next;
        } 
        if (curr) return curr->val;
        else return -1;
    }

    void insertHead(int val) {
        LinkedNode *newNode = new LinkedNode{val, head->next};
        head->next = newNode;
        if (head == tail) tail = newNode;
    }
    
    void insertTail(int val) {
        LinkedNode *newNode = new LinkedNode{val};
        tail->next = newNode;
        tail = newNode;
    }

    bool remove(int index) {
        LinkedNode *curr = head;
        int it = 0;
        while (curr != nullptr && it < index) {
            curr = curr->next;
            ++it;
        }
        if (curr && curr->next) {
            if (!(curr->next->next)) tail = curr;
            LinkedNode *tmp = curr->next;
            curr->next = curr->next->next;
            delete(tmp);
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> retv;
        LinkedNode *curr = head->next;
        while (curr != nullptr) {
            retv.push_back(curr->val);
            curr = curr->next;
        }
        return retv;
    }
};
