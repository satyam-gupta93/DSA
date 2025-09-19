#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st; // (price, span)

    StockSpanner() {}

    int next(int price) {
        int span = 1; // current day counts at least 1
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second; // add previous span
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner ss;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    for(int p : prices) {
        cout << "Price: " << p << " -> Span: " << ss.next(p) << endl;
    }

    return 0;
}
