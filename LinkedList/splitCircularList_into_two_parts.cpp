
// void split(Node *head, Node **h1, Node **h2)
// {
//     Node *fast, *slow;
//     if (head == NULL || head->next == NULL)
//     {
//         *h1 = head;
//         *h2 = NULL;
//     }
//     else
//     {
//         slow = head;
//         fast = head->next;
//         while(fast)
//         {
//             fast = fast->next;
//             if(fast)
//             {
//                 slow = slow->next;
//                 fast = fast->next;
//             }

//         }
//         *h1 = head;
//         *h2 = slow->next;
//         slow->next = NULL;
//     }
    
// }

