#include <stdio.h>
#include <math.h>

#define Eps 0.00001

int compare(double a, double b){
    return a==b;
}

int compareTwo(double a, double b){
    return fabs(a-b) < __DBL_EPSILON__;
}
int compareThree(double a, double b){
    return fabs(a-b) < Eps;
}

int compareFour(double a, double b){
    return fabs(a-b)<__DBL_EPSILON__ * fmax(fabs(a), fabs(b));
}

int compareFive(double a, double b){
    return fabs(a-b)< Eps* fmax(fabs(a), fabs(b));
}

int compareSix(double a, double b){
    return fabs(a-b)/fabs(a+b);

}

int compareSeven(double a, double b){
    return (a<b-Eps || b<a-Eps);
}
int compareEight(double a, double b){
     return (a<b-__DBL_EPSILON__ || b<a-__DBL_EPSILON__);
}

int main(){
    double a=0.00001;
    double b=0;

    for(int i=0; i<50;i++){
        b+=0.01;
    }
    printf("%.30lf ?== %.30lf", a,b);
    if(compare(a,b)){
        printf("True\n");
    }
    
    else {
        printf("\nFalse\n");
    }
    if(compareTwo(a,b)){
        printf("True\n");
    }
    else{
        printf("False");
    }
    if(compareThree(a,b)){
        printf("\nTrue");
    }
    else{
        printf("\nFalse\n");
    }
    if(compareFour(a,b)){
        printf("\nTrue");
    }
    else{
        printf("\nFalse\n");
    }
    if(compareFive(a,b)){
        printf("\nTrue");
    }
    else{
        printf("\nFalse\n");
    }
    if(compareSix(a,b)){
        printf("\nTrue");
    }
    else{
        printf("\nFalse\n");
    }
    if(compareSeven(a,b)){
        printf("\nTrue");
    }
    else{
        printf("\nFalse\n");
    }
    if(compareEight(a,b)){
        printf("\nTrue");
    }
    else{
        printf("\nFalse\n");
    }

    return 0;
}