//Implement k Queues in a Single Array

class kQueues {
  public:
    vector<vector<int>> kque; // store k queues
    int n, k;                 // total size and number of queues

    kQueues(int n, int k) {
        this->n = n;
        this->k = k;
        kque.resize(k);       // initialize k queues
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        kque[i].push_back(x);
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if (kque[i].empty())
            return -1;

        int front = kque[i][0];
        kque[i].erase(kque[i].begin()); // remove front of ith queue
        return front;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return kque[i].empty();
    }

    bool isFull() {
        // check if total elements == n
        int size = 0;
        for (int i = 0; i < k; i++) {
            size += kque[i].size();
        }
        return size == n;
    }
};
