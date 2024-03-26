bool hasCycle(ListNode *head)
{

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        // collision overlap proves cycle
        if (fast == slow)
            return true;
    }

    // if we reached NULL, there is no cycle
    return false;
}
