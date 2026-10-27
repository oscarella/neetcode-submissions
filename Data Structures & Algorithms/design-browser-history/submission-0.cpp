class BrowserHistory {

    struct BrowserNode {
        string url;
        BrowserNode *next;
        BrowserNode *prev;
        BrowserNode(const string &url, BrowserNode *next = nullptr, BrowserNode *prev = nullptr): url{url}, next{next}, prev{prev} {}
        ~BrowserNode() { delete next; }
    };

    BrowserNode *head; // Dummy node
    BrowserNode *curr;
public:
    BrowserHistory(string homepage): curr{new BrowserNode(homepage)} {
        head = new BrowserNode("");
        head->next = curr;
        curr->prev = head;
    }
    
    void visit(string url) {
        delete curr->next;
        BrowserNode *newCurr = new BrowserNode(url);
        curr->next = newCurr;
        newCurr->prev = curr;
        curr = newCurr;
    }
    
    string back(int steps) {
        while (curr->prev && curr->prev != head && steps) {
            curr = curr->prev;
            --steps;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while (curr->next && steps) {
            curr = curr->next;
            --steps;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */