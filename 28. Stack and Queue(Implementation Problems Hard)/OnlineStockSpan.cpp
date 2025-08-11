//Design an algorithm that collects daily price quotes for some stock and returns the span of that
//stock's price for the current day.The span of the stock's price in one day is the maximum number
//of consecutive days (starting from that day and going backward) for which the stock price was 
//less than or equal to the price of that day.For example, if the prices of the stock in the last
//four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because
//starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
//Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock
//today is 8, then the span of today is 3 because starting from today, the price of the stock was
//less than or equal 8 for 3 consecutive days.Implement the StockSpanner class:
//StockSpanner() Initializes the object of the class.
//int next(int price) Returns the span of the stock's price given that today's price is price.
#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, index}
    int ind = -1;

    StockSpanner() { } // No need to re-declare ind

    int next(int price) {
        ind++;

        // Pop while current price is >= price on top of stack
        while (!st.empty() && st.top().first <= price)
            st.pop();

        // If stack empty → span is entire range so far
        int ans = ind - (st.empty() ? -1 : st.top().second);

        // Push current price with index
        st.push({price, ind});
        return ans;
    }
};

int main() {
    StockSpanner ss;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    for (int p : prices) {
        cout << ss.next(p) << " ";
    }
    return 0;
}
