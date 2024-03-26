ListNode *reverseList(ListNode *head)
{

    if (head == NULL)
        return NULL;
    ListNode *middle = head;
    ListNode *left = NULL;
    ListNode *right = middle->next;

    while (middle != NULL)
    {

        right = middle->next;
        middle->next = left;

        // move up
        left = middle;
        middle = right;
    }

    return left;
}
