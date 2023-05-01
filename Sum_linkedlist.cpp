#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    ListNode *next;
    int val;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = l1 != nullptr ? l1->val : 0;
            int val2 = l2 != nullptr ? l2->val : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;

        return result;
    }
};

// helper function to print a linked list
void printList(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // create two linked lists representing the numbers to add
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // create a Solution object and call the addTwoNumbers function
    Solution s;
    ListNode *result = s.addTwoNumbers(l1, l2);

    // print the result
    printList(result);

    // free memory
    delete l1;
    delete l2;
    ListNode *temp;
    while (result != nullptr)
    {
        temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
