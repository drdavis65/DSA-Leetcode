struct PageNode {
    string url;
    PageNode* next;
    PageNode* prev;
    PageNode(string url) : url(url), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
    PageNode* home;
    PageNode* curr;
public:
    BrowserHistory(string homepage) {
        home = new PageNode(homepage);
        curr = home;
    }
    
    void visit(string url) {
        PageNode* toClear = curr->next;
        PageNode* newPage = new PageNode(url);
        curr->next = newPage;
        newPage->prev = curr;
        curr = newPage;
        while(toClear) {
            PageNode* temp = toClear;
            toClear = toClear->next;
            delete temp;
        }
    }
    
    string back(int steps) {
        int i = 0;
        while(curr != home && i < steps) {
            curr = curr->prev;
            i++;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        int i = 0;
        while(curr->next && i < steps) {
            curr = curr->next;
            i++;
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
