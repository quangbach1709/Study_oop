#include<iostream>
#include<string.h>

using namespace std;

class String
{
    private:
        string str;
    public:
        String()
        {
            str="Chua co chuoi";
        }
        String(string tmp);

        void input()
        {
            cout<<"Nhap chuoi: ";
            getline(cin,str);
        }

        void output()
        {
            cout<<"Chuoi vua nhap la: "<<str<<endl;
            cout<<"Do dai chuoi la: "<<str.length()<<endl;
        }

        void noi_chuoi(string tmp)
        {
            str=str+tmp;
        }

        //ham huy
        ~String()
        {
            cout<<"Da huy chuoi"<<endl;
        }
  
};

int main()
{
    String tmp;
    tmp.input();
    tmp.output();
    tmp.noi_chuoi("abc");
    tmp.output();
    return 0;
}
        