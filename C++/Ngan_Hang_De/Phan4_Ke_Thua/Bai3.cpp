#include<iostream>
#include<string>

using namespace std;

class CanBo
{
    private:
        string HoTen;
        int NamSinh;
        bool GioiTinh;

    public:
        CanBo()
        {
            HoTen="Chua co ten";
            NamSinh=0;
            GioiTinh=0;
        }
        
        // ~CanBo()
        // {
        //     cout<<"Da huy Can Bo "<<HoTen<<endl;
        // }
        virtual void input()
        {
            cout<<"Nhap ho ten: ";

            getline(cin,HoTen);
            cout<<"Nhap nam sinh: ";
            cin>>NamSinh;
            cout<<"Nhap gioi tinh (1: Nam, 0: Nu): ";
            cin>>GioiTinh;
        }
        virtual void output()
        {
            cout<<"Ho ten: "<<HoTen<<endl;
            cout<<"Nam sinh: "<<NamSinh<<endl;
            if(GioiTinh==1)
                cout<<"Gioi tinh: Nam"<<endl;
            else
                cout<<"Gioi tinh: Nu"<<endl;
        }
        int tuoi()
        {
            return 2019-NamSinh;
        }
        virtual bool nghiHuu()
        {
            if(tuoi()>=60)
                return true;
            return false;
        }
        virtual float luong()
        {
            return 5000000;
        }
        
};

class BienChe:public CanBo
{
    private:
        string DonVi;
        float HeSoLuong;
    public:
        BienChe()
        {
            DonVi="Chua co don vi";
            HeSoLuong=0;
        }
        // ~BienChe()
        // {
        //     cout<<"Da huy Bien Che"<<endl;
        // }
        void input()
        {
            CanBo::input();
            cout<<"Nhap don vi: ";
            cin.ignore();
            getline(cin,DonVi);
            cout<<"Nhap he so luong: ";
            cin>>HeSoLuong;
            cin.ignore();
        }
        void output()
        {
            CanBo::output();
            cout<<"Don vi: "<<DonVi<<endl;
            cout<<"He so luong: "<<HeSoLuong<<endl;
        }
        bool NghiHuu()
        {
            if(tuoi()>=60)
                return true;
            return false;
        }
        float Luong()
        {
            if (NghiHuu())
                return (5000000/100)*70;
            else
                return HeSoLuong*1310000;
            
        }
};

class HopDong:public CanBo
{
    private:
        int NamCongTac,HeSoThamNien,MucLuong;
    public:
        HopDong()
        {
            NamCongTac=0;
            HeSoThamNien=0;
            MucLuong=0;
        }
        // ~HopDong()
        // {
        //     cout<<"Da huy Hop Dong"<<endl;
        // }
        void input()
        {
            CanBo::input();
            cout<<"Nhap nam cong tac: ";
            cin>>NamCongTac;
            cout<<"Nhap he so tham nien: ";
            cin>>HeSoThamNien;
            cout<<"Nhap muc luong: ";
            cin>>MucLuong;
        }
        void output()
        {
            CanBo::output();
            cout<<"Nam cong tac: "<<NamCongTac<<endl;
            cout<<"He so tham nien: "<<HeSoThamNien<<endl;
            cout<<"Muc luong: "<<MucLuong<<endl;
        }
        bool NghiHuu()
        {
            if(NamCongTac>=35)
                return true;
            return false;
        }
        float Luong()
        {
            if(NghiHuu()==false)
                return MucLuong*HeSoThamNien;
            else
                return 0;
        }
};

int main()
{
    CanBo *a;
    BienChe b;
    HopDong c;
    a=&b;
    a->input();
    a->output();
    cout<<"Luong: "<<a->luong()<<endl;
    if (a->nghiHuu())
        cout<<"Da nghi huu"<<endl;
    else
        cout<<"Chua nghi huu"<<endl;

    a=&c;
    a->input();
    a->output();
    cout<<"Luong: "<<a->luong()<<endl;
    if (a->nghiHuu())
        cout<<"Da nghi huu"<<endl;
    else
        cout<<"Chua nghi huu"<<endl;
    return 0;

}