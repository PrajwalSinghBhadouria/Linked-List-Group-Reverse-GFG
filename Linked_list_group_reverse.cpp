int count_(Node*head){
        int c=0;
        Node*temp = head;
        while(temp!=NULL){
            c++;
            temp = temp->next;
        }
        return c;
    }
    Node *reverseKGroup(Node *head1, int k) {
        // code here
        Node *head = NULL;
        Node *tail = NULL;
        Node *tail1 = NULL;
        Node *h = NULL;
        Node *temp = head1;
        int count=0 , p=1;
        while(temp!=NULL){
            if(count<k){
                Node *newnode = new Node(temp->data);
                if(h==NULL){
                    tail = newnode;
                    h = newnode;
                }
                else{
                    newnode->next  = h;
                    h = newnode;   
                }
            }
            count++;
            temp = temp->next;
            if(count==k){
                if(p==1){
                    head = h;
                    tail1 = tail;
                    p++;
                }
                else{
                    tail1->next = h;
                    tail1 = tail;
                }
                tail = NULL;
                h = NULL;
                count=0;
            }
        }
        int s=count_(head1);
        if(s<k){
            head = h;
            tail1 = tail;
        }
        else if(s%k!=0){
            tail1->next = h;
            tail1 = tail;
        }
        
        return head;
    }
