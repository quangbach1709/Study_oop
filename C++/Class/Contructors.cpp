#include<iostream>
#include<string>

using namespace std;

class Sv
{
    private:
        string msv;
        string name;
        string lop;
    public:
        Sv(string msv, string name, string lop)
        {
            this->msv=msv;
            this->name=name;
            this->lop=lop;
        }
        void output()
        {
            cout<<msv<<"\t"<<name<<"\t"<<lop<<endl;
        }
};

int main()
{
    string msv,name,lop,tmp;
    int count=0;
    while (1)
    {
        cout<<"Nhap msv: ";
        getline(cin,msv);
        cout<<"Nhap ten sv: ";
        getline(cin,name);
        cout<<"Nhap lop: ";
        getline(cin,lop);
        Sv *newsv=new Sv(msv,name,lop);
        cout<<"Ban co muon nhap tiep khong? (y/n): ";
        getline(cin,tmp);
        if (tmp=="n")
        {
            break;
        }
        count++;

    }
    //in ra danh sach sinh vien
    cout<<"Danh sach sinh vien: "<<endl;
    for (int i = 0; i < count; i++)
    {
        newsv[i].output();
    }
    return 0;
    
}