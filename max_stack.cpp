// Link : https://leetcode.com/problems/max-stack/

class DLL {
    public:
        int val;
        DLL* prev;
        DLL* next;
        
        DLL(int val) {
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

class MaxStack {
private:
    map<int, vector<DLL*> > maxs;
    DLL* head, * tail;
public:
    MaxStack() {
        head = new DLL(-1);
        tail = head;
    }
    
    void push(int x) {
        tail->next = new DLL(x);
        tail->next->prev = tail;
        tail = tail->next;
        maxs[x].push_back(tail);
    }
    
    int pop() {
        if (head == tail) {
            return 0;
        }
        DLL* top = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        maxs[top->val].pop_back();
        if (maxs[top->val].size() == 0) {
            maxs.erase(top->val);
        }
        return top->val;
    }
    
    int top() {
        return tail->val;
    }
    
    int peekMax() {
        if (maxs.empty()) {
            return 0;
        }
        return maxs.rbegin()->second.back()->val;
    }
    
    int popMax() {
        if (maxs.empty()) {
            return 0;
        }
        DLL* top =  maxs.rbegin()->second.back();
        maxs.rbegin()->second.pop_back();
        if (maxs.rbegin()->second.size() == 0) {
            maxs.erase(maxs.rbegin()->first);
        }
        DLL* itr = top->next;
        DLL* prev = top->prev;
        DLL* next = top->next;
        prev->next = next;
        if (next != nullptr) {
            next->prev = prev;
        } else {
            tail = prev;
        }
        return top->val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
