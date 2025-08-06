#include <stdio.h>
#define MAX 100
typedef struct {

    int expo;
    int coeff;

}polynomial;


void addTwoPoly(polynomial poly1[],int n1,polynomial poly2[],int n2,polynomial result[],int *n3){
    int i=0,j=0,k=0;

    while(i<n1 && j<n2){

        if(poly1[i].expo == poly2[j].expo){
            result[k].coeff = poly1[i].coeff+poly2[j].coeff;
            result[k].expo = poly1[i].expo;
            i++,j++,k++;
        }
        
        else if(poly1[i].expo > poly2[j].expo){
            result[k++] = poly1[i++];
        }
        
        else{
            result[k++] = poly2[j++];
        }
    }

    while(i<n1){result[k++] = poly1[i++];}
    while(j<n2){result[k++] = poly2[j++];}

    *n3 = k;
}

void displayPoly(polynomial poly[],int n){
    for(int i=0; i<n; i++){
        printf("(%d , %d)",poly[i].expo,poly[i].coeff);
    }
}


int main(){

    int n1,n2,n3;

    polynomial poly1[MAX],poly2[MAX],result[MAX];

    printf("Enter the number of terms of polynomial 1: ");
    scanf("%d",&n1);
    printf("Enter the number of terms of polynomial 2: ");
    scanf("%d",&n2);

    printf("Enter the exponent and coefficient of polynomial in decenting order!");
    printf("\n*Enter the Polynomial 1*");
    for (int i=0; i<n1 ; i++){
        printf("\nEnter term(expo & coeff) %d: ",i+1);
        scanf("%d%d",&poly1[i].expo,&poly1[i].coeff);
    }
    printf("\n*Enter the Polynomial 2*");
    for (int j=0; j<n2 ; j++){
        printf("\nEnter term(expo & coeff) %d: ",j+1);
        scanf("%d%d",&poly2[j].expo,&poly2[j].coeff);
    }

    addTwoPoly(poly1,n1,poly2,n2,result,&n3);

    displayPoly(result,n3);

    return 0;
}