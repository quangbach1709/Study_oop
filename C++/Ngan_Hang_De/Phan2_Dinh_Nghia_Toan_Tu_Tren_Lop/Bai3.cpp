#include<iostream>

using namespace std;

class PhanSo
{
    private:
        int ts,ms;
    public:
        PhanSo()
        {
            this->ms=0;
        }
        void input()
        {
            cout<<"Nhap Tu So: ";
            cin>>ts;
            cout<<"Nhap Mau So: ";
            cin>>ms;
        }
        void output()
        {
            cout<<"Phan So la: "<<ts<<"/"<<ms<<endl;
        }
        ~PhanSo()
        {
            cout<<"Da huy phan so."<<endl;
        }
        //operator +
        PhanSo operator+(PhanSo tmp)
        {
            PhanSo sum;
            sum.ts=ts*tmp.ms+ms*tmp.ts;
            sum.ms=ts*tmp.ms;

            return sum;
        }
        PhanSo operator-(PhanSo tmp)
        {
            PhanSo tru;
            tru.ts=ts*tmp.ms-tmp.ts*ms;
            tru.ms=ts*tmp.ms;

            return tru;
        }
        PhanSo operator*(PhanSo tmp)
        {
            PhanSo nhan;
            nhan.ts=ts*tmp.ts;
            nhan.ms=ts*tmp.ms;

            return nhan;
        }
        //operator chia
        PhanSo operator/(PhanSo tmp)
        {
            PhanSo chia;
            chia.ts=ts*tmp.ms;
            chia.ms=ms*tmp.ts;

            return chia;
        }
        friend ostream& operator<<(ostream& os,const PhanSo &tmp)
        {
            os<<tmp.ts<<"/"<<tmp.ms<<endl;
            return os;
        }
        friend istream& operator>>(istream& is,PhanSo &tmp)
        {
            //dung void input() de nhap
            tmp.input();
            return is;
        }
        
};

int main()
{
    PhanSo a,b;
    cin>>a;
    cin>>b;
    cout<<a;
    cout<<b;
    cout<<"Tong: "<<a+b<<endl;
    cout<<"Hieu: "<<a-b<<endl;
    cout<<"Tich: "<<a*b<<endl;
    cout<<"Thuong: "<<a/b<<endl;
    
    return 0;
}