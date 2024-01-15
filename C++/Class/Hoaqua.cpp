#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Hoaqua
{
    private:
        int ma;
        string name,xuatxu;
        long long gia,thanhtien;
    public:
        Hoaqua()
        {
            ma=0;
            name="";
            xuatxu="";
            gia=0;
            thanhtien=0;
        }
        Hoaqua(int ma,string ten,string xuat,long long gia)
        {
            this->ma=ma;
            name=ten;
            xuatxu=xuat;
            this->gia=gia;
            //this->thanhtien=thanhtien;
        }
        void setThanhTien(long long thanhtien)
        {
            this->thanhtien=thanhtien;
        }
        long long getThanhTien()
        {
            return thanhtien;
        }
        void setMaHoaQua(int ma)
        {
            this->ma=ma;
        }
        int getMaHoaQua()
        {
            return ma;
        }
        void setTenHoaQua(string ten)
        {
            name=ten;
        }
        string getTenHoaQua()
        {
            return name;
        }
        void setXuatXu(string xuat)
        {
            xuatxu=xuat;
        }
        string getXuatXu()
        {
            return xuatxu;
        }
        void getGia(long long gia)
        {
            this->gia=gia;
        }
        long long getGia()
        {
            return gia;
        }
        ~Hoaqua(){}
        virtual void input()
        {
            cout<<"Nhap ma hoa qua: ";
            cin>>ma;
            cin.ignore();
            cout<<"Ten hoa qua: ";
            getline(cin,name);
            cout<<"Nhap Xuat Xu: ";
            getline(cin,xuatxu);
            cout<<"Nhap gia: ";
            cin>>gia;
            cin.ignore();
        }
        virtual void output()
        {
            cout<<"Ma hoa qua: "<<ma<<endl;
            cout<<"Ten hoa qua: "<<name<<endl;
            cout<<"Xuat Xu: "<<xuatxu<<endl;
            cout<<"Gia: "<<gia<<endl;
        }
        long long  operator+(Hoaqua &a)
        {
            long long tong;
            tong=a.thanhtien+this->thanhtien;
            return tong;
        }
        
};
class Duahau :public Hoaqua
{
    private:
        long long kg;
    public:
        Duahau()
        {
            kg=0;
        }
        Duahau(long long kg,int ma,string ten,string xuat,long long gia):Hoaqua(ma,ten,xuat,gia)
        {
            this->kg=kg;
        }
        ~Duahau(){}
        void setKg(long long kg)
        {
            this->kg=kg;
        }
        long long getKg()
        {
            return kg;
        }
        void input()
        {
            Hoaqua::input();
            cout<<"Nhap so kg: ";
            cin>>kg;
            cin.ignore();
        }
        long long getThanhTien()
        {
            return getGia()*getKg();
        }
        void output()
        {
            Hoaqua::output();
            cout<<"So kg: "<<kg<<endl;
            cout<<"Thanh tien: "<<getThanhTien()<<endl;
        }
};
class Dua :public Hoaqua
{
    private:
        int soluong;
    public:
        Dua()
        {
            soluong=0;
        }
        Dua(int soluong,int ma,string ten,string xuat,long long gia):Hoaqua(ma,ten,xuat,gia)
        {
            this->soluong=soluong;
        }
        ~Dua(){}
        void setSoLuong(int soluong)
        {
            this->soluong=soluong;
        }
        int getSoLuong()
        {
            return soluong;
        }
        void input()
        {
            Hoaqua::input();
            cout<<"Nhap so luong: ";
            cin>>soluong;
            cin.ignore();
        }
        long long getThanhTien()
        {
            return getGia()*getSoLuong();
        }
        void output()
        {
            Hoaqua::output();
            cout<<"So luong: "<<soluong<<endl;
            cout<<"Thanh tien: "<<getThanhTien()<<endl;
        }
};
int main()
{
    int n;
    cout<<"Nhap n hoa qua: ";
    cin>>n;
    cin.ignore();
    Hoaqua *qua[n];
   for (int i = 0; i < n; i++)
   {
    int chon;
    do
    {
        cout<<"1. Dua hau"<<endl;
        cout<<"2. Dua"<<endl;
        cin>>chon;
        cin.ignore();

    } while (chon!=1 && chon !=2);
    
    if(chon==1)
    {
        qua[i]=new Duahau;
        qua[i]->input();
    }
    else
    {
        qua[i]=new Dua;
        qua[i]->input();
    }
   }
   cout<<"Danh sach hoa qua: "<<endl;
    for (int i = 0; i < n; i++)
    {
         qua[i]->output();
    }
    //tinh tong gia tri don hang banh nap trong toan tu
    long long tong=0;
    for (int i = 0; i < n; i++)
    {
        tong=tong+qua[i]->getThanhTien();
    }
    cout<<"Tong gia tri don hang: "<<tong<<endl;
   
}