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

ListNode *init(int nums[], int curr, int size)
{
    if (curr == size)
        return nullptr;
    return new ListNode(nums[curr], init(nums, curr + 1, size));
}

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 && !list2)
        {
            return nullptr;
        }
        if (!list1)
        {
            return list2;
        }
        if (!list2)
        {
            return list1;
        }

        ListNode temp = ListNode(0), *curr = &temp;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                curr->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                curr->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            curr = curr->next;
        }

        while (list1)
        {
            curr->next = new ListNode(list1->val);
            list1 = list1->next;
            curr = curr->next;
        }

        while (list2)
        {
            curr->next = new ListNode(list2->val);
            list2 = list2->next;
            curr = curr->next;
        }

        return temp.next;
    }
};

int main()
{
    int a[] = {1, 2, 4}, b[] = {1, 3, 4};

    ListNode *list1 = init(a, 0, sizeof(a) / sizeof(int));
    ListNode *list2 = init(b, 0, sizeof(b) / sizeof(int));

    ListNode *result = Solution().mergeTwoLists(list1, list2);

    while (result)
    {
        cout << result->val;
        result = result->next;
    }
}