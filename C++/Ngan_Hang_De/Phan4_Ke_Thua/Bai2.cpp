#include<iostream>
#include<string>

using namespace std;

class VeMayBay
{
    private:
        string TenChuyen;
        int NgayBay,GiaVe;
    public:
        VeMayBay()
        {
            TenChuyen="Chua co ten";
            NgayBay=0;
            GiaVe=0;
        }
        
        // ~VeMayBay()
        // {
        //     cout<<"Da huy ve "<<TenChuyen<<endl;
        // }
        void input()
        {
            cout<<"Nhap ten chuyen: ";
            getline(cin,TenChuyen);
            cout<<"Nhap ngay bay: ";
            cin>>NgayBay;
            cout<<"Nhap gia ve: ";
            cin>>GiaVe;
            cin.ignore();
        }
        void output()
        {
            cout<<"Ten chuyen: "<<TenChuyen<<endl;
            cout<<"Ngay bay: "<<NgayBay<<endl;
            cout<<"Gia ve: "<<GiaVe<<endl;
        }
        int getGiaVe()
        {
            return GiaVe;
        }
};

class Nguoi
{
    private:
        string HoTen;
        int Tuoi;
        bool GioiTinh;

    public:
        Nguoi()
        {
            HoTen="Chua co ten";
            Tuoi=0;
            GioiTinh=0;
        }
        
        // ~Nguoi()
        // {
        //     cout<<"Da huy Nguoi "<<HoTen<<endl;
        // }
        void input()
        {
            cout<<"Nhap ho ten: ";
            getline(cin,HoTen);
            cout<<"Nhap tuoi: ";
            cin>>Tuoi;
            cout<<"Nhap gioi tinh (1: Nam, 0: Nu): ";
            cin>>GioiTinh;
            cin.ignore();
        }
        void output()
        {
            cout<<"Ho ten: "<<HoTen<<endl;
            cout<<"Tuoi: "<<Tuoi<<endl;
            if(GioiTinh==1)
                cout<<"Gioi tinh: Nam"<<endl;
            else
                cout<<"Gioi tinh: Nu"<<endl;
        }
        
};

class HanhKach:public Nguoi
{
    private:
        VeMayBay ve[1000];
        int SoLuong;
    public:
        HanhKach()
        {
            SoLuong=0;
        }
        void input()
        {
            Nguoi::input();
            cout<<"Nhap so luong ve: ";
            cin>>SoLuong;
            cin.ignore();
            for(int i=0;i<SoLuong;i++)
            {
                cout<<"Nhap thong tin ve thu "<<i+1<<endl;
                ve[i].input();
            }
        }
        void output()
        {
            for(int i=0;i<SoLuong;i++)
            {
                cout<<"Thong tin ve thu "<<i+1<<endl;
                ve[i].output();
            }
        }
        int tongTien()
        {
            int tong=0;
            for(int i=0;i<SoLuong;i++)
            {
                tong+=ve[i].getGiaVe();
            }
            return tong;
        }
};

int main()
{
    int n;
    cout<<"Nhap so luong hanh khach: ";
    cin>>n;
    cin.ignore();
    HanhKach a[n+1];
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap thong tin hanh khach thu "<<i+1<<endl;
        a[i].input();
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Thong tin hanh khach thu "<<i+1<<endl;
        a[i].output();
        cout<<"Tong tien cua khach hang thu "<<i+1<<" la: "<<endl<<a[i].tongTien()<<endl;
    }
    return 0;
}
