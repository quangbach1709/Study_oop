#include<iostream>

using namespace std;

class PS
{
    private:
        int t,m;
    public:
        PS()
        {
            t=0;
            m=1;
        }
        
        PS(int tu,int mau)
        {
            t=tu;
            m=mau;
        }

        PS operator+(PS tmp)
        {
            PS tong;
            tong.t=this->t*tmp.m + this->m*tmp.t;
            tong.m=this->m*tmp.m;
            return tong;
        }

        PS operator-(PS tmp)
        {
            PS tru;
            tru.t=this->t*tmp.m - this->m*tmp.t;
            tru.m=this->m*tmp.m;
            return tru;
        }
        friend istream& operator>>(istream& is,PS& a);
        friend ostream& operator<<(ostream& os,const PS& a);
};

ostream& operator<<(ostream& os,const PS& a)
        {
            os<<a.t<<"/"<<a.m;
            return os;
        }       
istream& operator>>(istream& is,PS& a)
{
    cout<<"Nhap tu so: ";
    is>>a.t;
    cout<<"Nhap mau so: ";
    is>>a.m;
    return is;
}

int main()
{
    PS a;
    cin>>a;
    PS b;
    cin>>b;
    PS tong=a+b;
    PS tru=a-b;
    cout<<"Hieu: "<<tru<<endl;
    //in bang cach nap chong toan tu <<
    cout<<"Tong: "<<tong<<endl;
    
    return 0;
    
}
