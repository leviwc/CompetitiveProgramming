struct median {
    multiset<int> s1, s2;
    median() {}
    void balance() {
        if (s1.size() >= s2.size() + 2) {
            auto it = s1.end();
            it--;
            s2.insert(*it);
            s1.erase(it);
        } else if (s2.size() > s1.size()) {
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
    }
    void insert(int x) {
        if (s1.empty()) {
            s1.insert(x);
        } else {
            auto it = s1.end();
            it--;
            if (x <= *it) {
                s1.insert(x);
            } else {
                s2.insert(x);
            }
        }
        balance();
    }
    void remove(int x) {
        if (!s2.empty() and x >= *s2.begin()) {
            s2.erase(s2.find(x));
        } else {
            s1.erase(s1.find(x));
        }
        balance();
    }
    int med() {
        auto it = s1.end();
        it--;
        return *it;
    }
};