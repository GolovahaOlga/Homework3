# include <iostream>
# include <cmath>
using namespace std;
void input_vector(int n,char *x){
    for (int i=0; i<n; i++){
        cout<<"V["<<i<<"]: ";
        cin>>x[i];
    }
}
void print_vector(int n,char *x){
    for (int i=0; i<n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n1,n2,i1=0,i2=0,n,r;
    char *a,*b,*x;
    cout<<"Enter the number of letters in the first word: ";
    cin>>n1;
    cout<<"Enter the number of letters in the second word: ";
    cin>>n2;
    n=n1+n2;
    r=abs(n1-n2);
    a=(char*)malloc(n1*sizeof(char));
    b=(char*)malloc(n2*sizeof(char));
    x=(char*)malloc((n1+n2)*sizeof(char));
    cout<<"Vector A"<<endl;
    input_vector(n1,a);
    cout<<"Vector B"<<endl;
    input_vector(n2,b);
    for (int i=0;i<=(n-r);i=i+2){
        if (i1<n1 and i2<n2){
            x[i]=a[i1];
            x[i+1]=b[i2];
            i1=i1+1;
            i2=i2+1;
        }
    }
    if (r!=0){
            for (int i=n-r;i<n;i++){
            if (i1<n1){
                x[i]=a[i1];
                i1++;
            }
            if (i2<n2){
                x[i]=b[i2];
                i2++;
            }
        }
    }
    cout<<"Vector X: "<<endl;
    print_vector(n,x);
    return 0;
}