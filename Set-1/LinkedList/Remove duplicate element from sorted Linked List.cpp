//Problem Name: Remove duplicate element from sorted Linked List
 //Source : GeeksForGeeks
 /****************************************/
Node *removeDuplicates(Node *head){
Node *curr = head;
while(curr && curr->next){
    if(curr->data == curr->next->data)
        curr->next = curr->next->next;
    else
        curr = curr->next;
}

return head;
}