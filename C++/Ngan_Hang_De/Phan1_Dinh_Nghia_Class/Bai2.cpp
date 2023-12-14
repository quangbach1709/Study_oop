#include<iostream>
#include<math.h>

using namespace std;

class TamGiac
{
    private:
        float a,b,c;

    public:
        TamGiac()
        {
            a=0;b=0;c=0;
        }
        void input()
        {
            cout<<"Nhap 3 canh cua tam giac:";
            cin>>a>>b>>c;
            while (1)
            {
                if ((a+b>c || a+c>b || b+c>a )&& a>=0 && b>=0 && c>=0)
                {
                    break;
                }
                else
                {
                    cout<<"Nhap lai 3 canh cua tam giac:";
                    cin>>a>>b>>c;
                }
            }
        }

        float dien_tich()
        {
            float p=(a+b+c)/2;
            return sqrt(p*(p-a)*(p-b)*(p-c));
        }

        bool tamgiac_deu()
        {
            if (a==b && a==c && b==c)
            {
                return true;
            }
            return false;
        }

        bool tamgiac_vuong()
        {
            if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b)
            {
                return true;
            }
            return false;  
        }

        bool tamgiac_can()
        {
            if (a==b || a==c || b==c)
            {
                return true;
            }
            return false;
        }

        void kiem_tra()
        {
            if (tamgiac_deu())
            {
                cout<<"Day la tam giac deu"<<endl;
            }
            else
            {
                if (tamgiac_vuong() && tamgiac_can())
                {
                    cout<<"Day la tam giac vuong can"<<endl;
                }
                else if (tamgiac_vuong())
                {
                    cout<<"Day la tam giac vuong"<<endl;
                }
                else if (tamgiac_can())
                {
                    cout<<"Day la tam giac can"<<endl;
                }
                else
                {
                    cout<<"Day la tam giac thuong"<<endl;
                }
                                
            }
            
        }

        void output()
        {
            cout<<"Dien tich tam giac la: "<<dien_tich()<<endl;
            cout<<"Tinh chat cua tam giac la:"<<endl;
            kiem_tra();
        }
};

int main()
{
    TamGiac tmp;
    tmp.input();
    tmp.output();
    return 0;
}