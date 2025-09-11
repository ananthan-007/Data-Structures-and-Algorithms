#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node* link;
}

struct node* insert(struct node* head,int coeff, int expo){
    struct node* temp;
    struct node* new = malloc(sizeof(struct node));
    new->coeff = coeff;
    new->expo = expo;
    new->link = NULL;

    if(head ==NULL || expo > head->expo){
        new->link=head;
        head=new;
    }
    else{
        temp=head;
        while(temp!=NULL && head->link->expo >= expo){
            temp=temp->link;
        }
        new->link=temp->link;
        temp->link= new;
    }

    return head;
}

struct node* create(struct node* head){
    int n,i,coeff,expo;
    printf("Enter the number of terms in the Polynomial: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the coeff of term %d",i+1);
        scanf('%d',&coeff);
        printf("Enter the coeff of term %d",i+1);
        scanf('%d',expo);

        head = insert(head,coeff,expo);
    }
    return head;
}

struct node* addPoly(struct node* head1 ,struct node* head2){}

struct node* print(struct node* head){
    struct node* temp = head;
    if(head==NULL){
        printf("NO POLYNOMIAL");
    }
    while(temp!=NULL){
        print("%dX^%d",temp->coeff,temp->expo);
    }
}

int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* result = NULL;

    printf("Enter the Polynomials");

    head1 = create(head1);

    head2 = create(head2);

    result = addPoly(head1, head2);
    
}