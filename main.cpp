#include <iostream>

using namespace std;


long EuclidesGeneral(long a, long b, long* x, long* y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    long x1, y1;
    long gcd = EuclidesGeneral(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}


void inversoM(long a, long m){
    long x = 0, y = 0;
    long g = EuclidesGeneral(a, m, &x, &y);
    if (g != 1)
        cout << "No tiene inverso Multiplicativo";
    else{
        long res = (x % m + m) % m;
        cout << "El inverso multiplicativo es : "<< res;
    }
}

int main(){
    // ax ≡ 1 (mod n)
    long a , n;
    cout<<"Escriba el numero a: ";
    cin>>a;cout<<"Escriba el numero n: ";
    cin>>n;
    cout<<"\t  "<< a<<"* x"<<"= 1 ( mod"<< n <<")\n";
    inversoM(a,n);
    return 0;
}