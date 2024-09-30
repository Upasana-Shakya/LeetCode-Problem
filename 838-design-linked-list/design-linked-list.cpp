class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    int len = 0;

    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        if(index < 0 || index >= len){
            return -1;
        }
        Node* temp = head;
        while(index--){
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        len++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* tail = head;
            while(tail->next){
                tail = tail->next;
            }
            tail->next = newNode;
        }
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == len){
            addAtTail(val);
            return;
        }
        else if(index == 0){
            addAtHead(val);
            return;
        }
        else if(index < len){
            Node* temp = head;
            for(int i=0 ; i<index-1 ; i++){
                temp = temp->next;
            }
            Node* next = temp->next;
            Node* newNode = new Node(val);
            newNode->next = next;
            temp->next = newNode;
            len++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(len == 0 || index >= len){
            return;
        }
        if(index == 0){
            head = head->next;
            len--;
            return;
        }
        Node* temp = head;
        for(int i=0; i < index-1; i++){
            temp = temp->next;
        }
        Node* curr = temp->next;
        temp->next = curr->next;
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */