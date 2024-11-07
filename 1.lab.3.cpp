# include <iostream>
# include <cmath>
using namespace std;
void input_num_elenents(int *n){
    do{
        cout<<"\nNumber of elements : "<<endl;
        cin>>*n;
    }while(*n<=0);
}
int *allocate_memory(int n){
    return (int*)malloc(n*sizeof(int));
}
void input_vector(int n,int *x){
    for (int i=0; i<n; i++){
        cout<<"V["<<i<<"]: ";
        cin>>x[i];
    }
}
double arithmetic_mean(int n, int *x){
    double sr, s=0.0;
    for(int i=0;i<n;i++){
        s=x[i]+s;
    }
    sr=s/n;
    return sr;
}
int sum_of_the_vector_elements(int n,int *x){
    int s=0;
    for(int i=0;i<n;i++){
        s=x[i]+s;
    }
    return s;
}
int sum_of_the_elements_in_the_square_of_the_vector(int n,int *x){
    int s=0;
    for(int i=0;i<n;i++){
        s=pow(x[i],2)+s;
    }
    return s;
}
int sum_of_the_products_of_the_elements_of_the_vectors(int n,int *x,int *y){
    int s=0;
    for(int i=0;i<n;i++){
        s=x[i]*y[i]+s;
    }
    return s;
}
int main(){
    int *x,*y,n,y1,x1;
    double b1,b0,yr,error,l;
    input_num_elenents(&n);
    x=allocate_memory(n);
    y=allocate_memory(n);
    cout<<"\nX: "<<endl;
    input_vector(n,x);
    cout<<"\nY: "<<endl;
    input_vector(n,y);
    l=1.0/n;
    b1=(sum_of_the_products_of_the_elements_of_the_vectors(n,x,y)-n*arithmetic_mean(n,x)*arithmetic_mean(n,y))/(sum_of_the_elements_in_the_square_of_the_vector(n,x)-(l*pow(sum_of_the_vector_elements(n,x),2)));
    b0=arithmetic_mean(n,y)-b1*arithmetic_mean(n,x);
    cout<<"y= "<<b0<<"+"<<b1<<"*x"<<endl;
    cout<<"Enter x"<<endl;
    cin>>x1;
    cout<<"Enter y"<<endl;
    cin>>y1;
    yr=b0+b1*x1;
    error=abs(y1-yr);
    cout<<"the calculated value of y: "<<yr<<endl;
    cout<<"Error: "<<error<<endl;
    return 0;
}