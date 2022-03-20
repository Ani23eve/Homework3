#include <stdio.h>
#include <math.h>
#include <float.h>

#define Eps 0.001

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

int compareFSix(double a, double b){
    return fabs(a-b)/fabs(a+b);

}

int compareSeven(double a, double b){
    return (a<b-Eps || b<a-Eps);
}
int compareEight(double a, double b){
     return (a<b-__DBL_EPSILON__ || b<a-__DBL_EPSILON__);
}
int main(){
    double a[100], b[100];
   double small =0.00001;
   double big =1000000000;
    
     int count=0;
    
    for(int i=0; i<100; i++){
       a[i] = small + i * big;
        b[i] = i==0?small:(b[i-1]+big); 
      
         if(a[i]==b[i]){
           
            printf("Equals:%lf==%lf\n,", a[i], b[i]);
            count++;
        }
        else {
            printf("Not equals %lf and %lf\n", a[i], b[i]);
        }
    }
    return 0;
}