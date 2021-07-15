template <typename T>
struct MaxQueue {
    deque<pair<T, int>> d;
    int ini = 1, fim = 0;
    T soma = 0;
    void push(T v) {
        while (!d.empty() && d.back().first + soma <= v) d.pop_back();
        d.push_back(pair<T, int>(v - soma, ++fim));
    }
    void pop() {
        if (!d.empty() && d.front().second == ini++) {
            d.pop_front();
        }
    }
    void add(T val) { soma += val; }
    T max() {
        if (d.empty()) return -(1LL << 62);
        return d.front().first + soma;
    }
    int size() { return fim - ini + 1; }
};