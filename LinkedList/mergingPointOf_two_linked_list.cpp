//function

// int mergingPoint(Node *head1,Node *head2)
// {
//     int m = getLength(head1);
//     int n = getLength(head2);
//     int diff = m>n?(m-n):(n-m);
//     if(m>n)
//     {
//         while(diff--)
//         {
//             head1  = head1->next;
//         }
//     }
//     else
//     {
//         while(diff--)
//         {
//             head2  = head2->next;
//         }
//     }

//     while(head1 && head2)
//     {
//         if(head1->next==head2->next)
//         {
//             return head1->data;
//         }
//         head1 = head1->next;
//         head2 = head2->next;
//     }

//     return -1;
// }