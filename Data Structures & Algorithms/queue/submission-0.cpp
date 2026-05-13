struct LinkNode {
    LinkNode *prev;
    int val;
    LinkNode *next;

    LinkNode(LinkNode *prev, int val, LinkNode *next): prev{prev}, val{val}, next{next} {}
};

class Deque {
    LinkNode *head;
    LinkNode *tail;
public:
    Deque(): head{new LinkNode{nullptr, -1, nullptr}}, tail{head} {}

    bool isEmpty() {
        return !(head->next);
    }

    void append(int value) {
        LinkNode *newNode = new LinkNode{tail, value, nullptr};
        tail->next = newNode;
        tail = newNode;
    }

    void appendleft(int value) {
        LinkNode *newNode = new LinkNode{head, value, head->next};
        head->next = newNode;
        if (head == tail) tail = newNode;
        else newNode->next->prev = newNode;
    }

    int pop() {
        if (isEmpty()) return -1;

        LinkNode *tmp = tail;
        int retval = tmp->val;
        tail = tail->prev;
        tail->next = nullptr;
        delete(tmp); // delete prev tail
        return retval;
    }

    int popleft() {
        if (isEmpty()) return -1;

        LinkNode *tmp = head->next;
        int retval = tmp->val;
        head->next = head->next->next;
        if (tmp->next) tmp->next->prev = head;
        else tail = head;
        delete(tmp);
        return retval;
    }
};
