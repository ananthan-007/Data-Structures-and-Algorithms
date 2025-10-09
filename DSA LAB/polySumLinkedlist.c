#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head,int coeff, int expo){
    struct node* temp;
    struct node* newP = malloc(sizeof(struct node));
    newP->coeff = coeff;
    newP->expo = expo;
    newP->link = NULL;

    if(head == NULL || expo > head->expo){
        newP->link=head;
        head=newP;
    }
    else{
        temp = head;
        while(temp->link!=NULL && temp->link->expo >= expo){
            temp = temp->link;
        }
        newP->link=temp->link;
        temp->link= newP;
    }

    return head;
}

struct node* create(struct node* head){
    int n,i,coeff,expo;
    printf("Enter the number of terms in the Polynomial: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the coeff of term %d: ",i+1);
        scanf("%d",&coeff);
        printf("Enter the expo of term %d: ",i+1);
        scanf("%d",&expo);
        head = insert(head,coeff,expo);
    } 
    
    return head;
}

struct node* addPoly(struct node* head1 ,struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->expo > ptr2->expo){
            head3 = insert(head3,ptr1->coeff,ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo){
            head3 = insert(head3,ptr2->coeff,ptr2->expo);
            ptr2 = ptr2->link;
        }
        else{
            head3 = insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
    }
    while(ptr1!=NULL){
            head3 = insert(head3,ptr1->coeff,ptr1->expo);
            ptr1 = ptr1->link;
        }
    while(ptr2!=NULL){
        head3 = insert(head3,ptr2->coeff,ptr2->expo);
        ptr2 = ptr2->link;
    }
    return head3;
}

void print(struct node* head){
    
    if(head==NULL){
        printf("NO POLYNOMIAL");
    }
    else{
        struct node* temp = head;
        while(temp!=NULL){
            printf("%dX^%d",temp->coeff,temp->expo);
            temp=temp->link;
            if (temp != NULL){
                printf(" + ");
            }
        }
        printf("\n");
    }
}
    

int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* result = NULL;

    printf("Enter the Polynomials\n");

    head1 = create(head1);
    printf("\nPolynomial 1: ");
    print(head1);
    head2 = create(head2);
    printf("\nPolynomial 2: ");
    print(head2);

    result = addPoly(head1, head2);

    printf("Sum of Polynomials: ");
    print(result);

    return 0;
}
