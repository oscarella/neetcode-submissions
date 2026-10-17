class LinkedList {
    class Node {
        int val;
        Node *next;
      public:
        Node(int val, Node *next): val{val}, next{next} {}
        friend class LinkedList;
    };
    Node *head; // initialized as dummy
    Node *tail;
public:
    LinkedList(): head{new Node{-1, nullptr}}, tail{head} {}

    ~LinkedList() {
        Node *curr = head;
        while (curr) {
            Node *tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    int get(int index) {
        if (index < 0) throw;

        Node *curr = head->next;
        int counter = 0;
        while (curr && counter < index) {
            curr = curr->next;
            ++counter;
        }
        if (curr) return curr->val; 
        else return -1; 
    }

    void insertHead(int val) {
        Node *insert = new Node{val, head->next};
        head->next = insert;
        if (insert->next == nullptr) tail = insert;
    }
    
    void insertTail(int val) {
        tail->next = new Node{val, nullptr};
        tail = tail->next;
    }

    bool remove(int index) {
        Node *curr = head;
        int counter = 0;
        while (curr && counter < index) {
            curr = curr->next;
            ++counter;
        }
        if (!curr || !(curr->next)) return false;
        Node *tmp = curr->next;
        curr->next = tmp->next;
        tmp->next = nullptr;
        delete tmp;
        if (curr->next == nullptr) tail = curr;
        return true;
    }

    vector<int> getValues() {
        vector<int> retVec;
        Node *curr = head->next;
        while (curr) {
            retVec.push_back(curr->val);
            curr = curr->next;
        }
        return retVec;
    }
};
