#include<stdio.h>
#include<stdlib.h>

typedef struct node{
 int data;
 struct node *next;
}Node;

Node* createLList(int n){

 int d;
 printf("Enter the data number 1  : ");
 scanf("%d",&d);
 Node *head=(Node*) malloc(sizeof(Node));
 if(head==NULL)
  printf("Element not created try again! ");
 else{
  head->next=NULL;
  head->data=d;
  Node *temp=head;
  int i;
  for(i=2;i<=n;i++){ 
   Node *newNode= (Node*)malloc(sizeof(Node));
   printf("Enter the data number %d  : ",i);
    scanf("%d",&d);
    newNode->next=NULL;
   newNode->data=d;
   temp->next=newNode;
   temp= temp->next;
  }
  
 }
 return head;
}



void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* deleteDuplicatesFromList(Node *head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* current = head;
    Node* nextNode;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            nextNode = current->next->next;
            free(current->next);
            current->next = nextNode;
        } else {
            current = current->next;
        }
    }
    return head;
}


int main(){
  Node* list=NULL;
 int n;
 printf("How many nodes you want in list 1? ");
 scanf("%d",&n);
  list=createLList(n);
  printf("The list after remove dublicates \n");
 printList(deleteDuplicatesFromList(list));
 
 return 0;
}