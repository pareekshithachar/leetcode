class StockSpanner
{
public:
    vector<int> res;
    stack<int> st;

    int i = 0;
    StockSpanner()
    {
    }

    int next(int price)
    {

        res.push_back(price);
        while (!st.empty() && price >= res[st.top()])
        {
            st.pop();
        }

        int a = st.empty() ? -1 : st.top();
        st.push(i);
        i++;
        return i - a - 1;
    }
};