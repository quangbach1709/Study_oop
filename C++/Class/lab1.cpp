#include<iostream>
#include<string>

using namespace std;

class Oto
{
    private:
        int maxe,year;
        string namexe,hangxe,colorxe;
        float gia;
    public:
        Oto()
        {
            maxe=0;
            year=0;
            namexe='0';
            hangxe='0';
            colorxe='0';
            gia=0;
        }
        Oto(int ma,string name,int nam,string hang,float gia,string mau)
        {
            maxe=ma;
            year=nam;
            namexe=name;
            hangxe=hang;
            this->gia=gia;
            colorxe=mau;
        }
        void setMaXe(int ma)
        {
            maxe=ma;
        }
        int getMaXe()
        {
            return maxe;
        }
        void setYear(int nam)
        {
            year=nam;
        }
        int getYear()
        {
            return year;
        }
        void setHangXe(string hang)
        {
            hangxe=hang;
        }
        string getHangXe()
        {
            return hangxe;
        }
        void setGia(float gia)
        {
            this->gia=gia;
        }
        float getGia()
        {
            return gia;
        }
        void setColorXe(string mau)
        {
            colorxe=mau;
        }
        string getColorXe()
        {
            return colorxe;
        }
        void setNamXe(string name)
        {
            namexe=name;
        }
        string getNamXe()
        {
            return namexe;
        }
        void input()
        {
            cout<<"Nhap ma xe: ";
            cin>>maxe;
            cin.ignore();
            cout<<"Nhap ten xe: ";
            getline(cin,namexe);
            cout<<"Nhap nam san xuat: ";
            cin>>year;
            cin.ignore();
            cout<<"Nhap hang xe: ";
            getline(cin,hangxe);
            cout<<"Nhap gia xe: ";
            cin>>gia;
            cin.ignore();
            cout<<"Nhap mau xe: ";
            getline(cin,colorxe);
        }
        void output()
        {
            cout<<maxe<<"\t"<<namexe<<"\t"<<year<<"\t"<<hangxe<<"\t"<<gia<<"\t"<<colorxe<<endl;
        }
        long long PhiDangKy()
        {
            return (7.2*gia/100)+500000+340000+480000+2160000;
        }
        long long GiaLanBanh()
        {
            return gia*PhiDangKy();
        }
};
int main()
{
    int n;
    cout<<"Nhap so luong xe: ";
    cin>>n;
    cin.ignore();
    Oto *a=new Oto[n];
    for (int i=0;i<n;i++)
    {
        a[i].input();
    }
    cout<<"Ma xe\tTen xe\tNam SX\tHang xe\tGia xe\tMau xe"<<endl;
    for (int i=0;i<n;i++)
    {
        a[i].output();
    }
    cout<<"Xe sap xep the gia xe tang dan: "<<endl;
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i].getGia()>a[j].getGia())
            {
                Oto tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    cout<<"Ma xe\tTen xe\tNam SX\tHang xe\tGia xe\tMau xe"<<endl;
    for (int i=0;i<n;i++)
    {
        a[i].output();
        cout<<"Gia lan banh: "<<a[i].GiaLanBanh()<<endl;
        
    }
}