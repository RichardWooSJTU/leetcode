#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    /*
    vector<ListNode*> pointerArr;
    int cnt = 0;
    
    while (head != NULL)
    {
        pointerArr.push_back(head);
        head = head->next;
        ++cnt;
    }
    if (n == 1)
    {
        if (cnt > 1)
        {
            pointerArr[cnt - 2]->next = NULL;
            return pointerArr[0];
        }
        else
            return NULL;
    }
    else if (n == cnt)
    {
        return pointerArr[1];
    }
    int location = cnt - n;
    pointerArr[location - 1]->next = pointerArr[location + 1];
    return pointerArr[0];
    */
    /////////////////////////////////////////////////////////
    /////////使用双指针first 和 second 减小内存占用//////////
    /////////////////////////////////////////////////////////
    ListNode* first = head; ListNode* second = head;
    int cnt = 0;
    while (first != NULL)
    {                 
        first = first->next;
        
        if (cnt > n)
            second = second->next;
        ++cnt;
    }
    if (cnt == 1)
        return NULL;
    else if (n == cnt)
    {
        return second->next;
    }
    second->next = second->next->next;
    return head;
}

int main(int argc, char** argv)
{
    ListNode* head = new ListNode(1);
    ListNode* pNode = head;
    
    for (int i = 1; i != 5; ++i)
    {
        pNode->next = new ListNode(i + 1);
        pNode = pNode->next;

    }
    ListNode* result = removeNthFromEnd(head, 2);
    while (result != NULL)
    {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}