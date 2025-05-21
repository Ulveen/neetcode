#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

class MinStack
{
    stack<int> st;
    stack<int> mst;

    public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        mst.push(min(mst.top(), val));
    }

    void pop()
    {
        st.pop();
        mst.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mst.top();
    }
};

int main()
{
    vector<string> input = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<vector<int>> params = {{}, {-2}, {0}, {-3}, {}, {}, {}, {}};

    MinStack mst;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == "MinStack") {
            mst = MinStack();
        }
        else if(input[i] == "push") {
            mst.push(params[i][0]);
        }
        else if(input[i] == "getMin") {
            cout << "Min val: " << mst.getMin() << endl;
        }
        else if(input[i] == "pop") {
            mst.pop();
        }
        else if(input[i] == "top") {
            cout << "Top: " << mst.top() << endl;
        }
    }
}