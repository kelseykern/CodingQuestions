ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return head;
    ListNode *curr = head;

    // get size
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    curr = head;

    // find index of node to remove
    int ith = count - n;

    // remove ith node
    if (ith == 0)
        return head->next;
    for (int i = 0; curr->next != NULL; i++)
    {
        if (i == ith - 1)
        {
            // remove next node
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
