#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    int values[] = {3, 2, 0, -4};
    int size = sizeof(values) / sizeof(int);

    if (size == 0)
    {
        cout << "False";
        return 0;
    }

    ListNode head = ListNode(values[0]);
    ListNode *curr = &head;

    for (int i = 1; i < size; i++)
    {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }

    bool result = Solution().hasCycle(&head);

    if (result)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}