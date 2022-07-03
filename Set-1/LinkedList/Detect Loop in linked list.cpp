 //Problem Name:Detect Loop in linked list
 //Source : GeeksForGeeks
 /****************************************/
 bool detectLoop(Node* head)
    {
        if(head == NULL)
            return false;
        Node *slow = head;
        Node *fast = head->next;
        
        while(slow && slow->next && fast && fast->next && fast->next->next){
            if(slow ==  fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }