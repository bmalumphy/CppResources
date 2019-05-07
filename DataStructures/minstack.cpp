class MinStack {
    private:
        struct myStack {
            int value;
            myStack *next;
        };
        int minVal;
        myStack *s;
    public:
        MinStack() {
            s = nullptr;
            minVal = INT_MAX;
        }

        void push(int x) {
            myStack *newNode = new myStack();
            newNode->value = x;
            newNode->next = s;
            s = newNode;
            minVal = min(minVal, x);
        }

        void pop() {
            if (minVal == s->value) {
                myStack *current = s->next;
                minVal = INT_MAX;
                while (current != nullptr) {
                    minVal = min(minVal, current->value);
                    current = current->next;
                }
            }
            s = s->next;
        }

        int top() {
            return s->value;
        }

        int getMin() {
            return minVal;
        }
};