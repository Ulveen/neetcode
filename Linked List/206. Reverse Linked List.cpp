#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head, *prev = nullptr;

        while (curr != nullptr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

ListNode *init(int nums[], int curr, int size)
{
    if (curr == size)
        return nullptr;
    return new ListNode(nums[curr], init(nums, curr + 1, size));
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(int);

    ListNode *head = init(nums, 0, n);
    ListNode *reversed = Solution().reverseList(head);
    ListNode *curr = reversed;

    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
}