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

Node* addEnd( Node *head, int d){
 Node *newNode= (Node*)malloc(sizeof(Node));
 newNode->data=d;
 newNode->next=NULL;
 if(head==NULL){// empty linked list
  head=newNode; 
  }
 else{// full linked list
  Node *temp=head;
  while(temp->next!=NULL)
  {temp=temp->next;} //move te the last node
  temp->next=newNode;
  }
 return head;

}
// reorder a list 
 Node* reorderList(Node *head)
{
Node *snode=head,*temp=head;int count=0;
if(head==NULL) return NULL;
 else{
 while(snode->next!=NULL){
  temp=snode->next;
    while(temp!=NULL)
    {
     if(snode->data > temp->data)
     {
     int swap=snode->data;
        snode->data=temp->data;
      temp->data=swap;  
     }
     temp=temp->next;
    }
   
 snode=snode->next;
  }
}
return head;
 }

Node* mergeTwoLists(Node *head1, Node*head2){
 if(head1==NULL)//empty
  return head2;
 if(head2==NULL)
  return head1;
  if(head1==NULL && head2==NULL) return NULL;
  else{
  Node *temp=head1;
  while(temp->next!=NULL){
    temp=temp->next;
   }
   temp->next=head2;
  }
  return reorderList(head1);  
 }

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main(){
  Node* list1=NULL,*list2=NULL;
 int n1,n2;
 printf("How many nodes you want in list 1? ");
 scanf("%d",&n1);
 printf("How many nodes you want in list 2?  ");
 scanf("%d",&n2);
  list1=createLList(n1);
  list2=createLList(n1);

  printf("The list after merge \n");
 printList(mergeTwoLists(list1,list2));
 return 0;
}