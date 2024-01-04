#include<iostream>
#include<string>

using namespace std;

class VienChuc
{
    string HoTen;
    int year;
    int hsl;
public:

    VienChuc()
    {
        HoTen = "";
        year = 0;
        hsl = 0;
    }

    VienChuc(string HoTen, int year, int hsl)
    {
        this->HoTen = HoTen;
        this->year = year;
        this->hsl = hsl;
    }
    void setHoTen(string HoTen)
    {
        this->HoTen = HoTen;
    }
    string getHoTen()
    {
        return HoTen;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    int getYear()
    {
        return year;
    }
    void setHsl(int hsl)
    {
        this->hsl = hsl;
    }
    int getHsl()
    {
        return hsl;
    }
    virtual void input()
    {
        cout << "Nhap ho ten: ";
        getline(cin, HoTen);
        cout << "Nhap nam sinh: ";
        cin >> year;
        cout << "Nhap he so luong: ";
        cin >> hsl;
        cin.ignore();
    }
    virtual void output()
    {
        cout << "Ho ten: " << HoTen << endl;
        cout << "Nam sinh: " << year << endl;
        cout << "He so luong: " << hsl << endl;
    }
    
    virtual float  luong() = 0;

};

class CBHanhChinh : public VienChuc
{
    string chucVu;
    int phuCap;
public:
    CBHanhChinh()
    {
        chucVu = "";
        phuCap = 0;
    }
    CBHanhChinh(string HoTen, int year, int hsl, string chucVu, int phuCap) : VienChuc(HoTen, year, hsl)
    {
        this->chucVu = chucVu;
        this->phuCap = phuCap;
    }
    void setChucVu(string chucVu)
    {
        this->chucVu = chucVu;
    }
    string getChucVu()
    {
        return chucVu;
    }
    void setPhuCap(int phuCap)
    {
        this->phuCap = phuCap;
    }
    int getPhuCap()
    {
        return phuCap;
    }
    void input()
    {
        VienChuc::input();
        cout << "Nhap chuc vu: ";
        getline(cin, chucVu);
        cout << "Nhap phu cap: ";
        cin >> phuCap;
        cin.ignore();
    }
    void output()
    {
        VienChuc::output();
        cout << "Chuc vu: " << chucVu << endl;
        cout << "Phu cap: " << phuCap << endl;
    }

    float luong()
    {
        return getHsl() * 2000000 + phuCap;
    }
};

class Teacher :public VienChuc
{
    string monDay,trinhDo;
    int thamNien;
    public:
    Teacher()
    {
        monDay="";
        trinhDo="";
        thamNien=0;
    }
    Teacher(string HoTen, int year, int hsl, string monDay, string trinhDo, int thamNien) : VienChuc(HoTen, year, hsl)
    {
        this->monDay = monDay;
        this->trinhDo = trinhDo;
        this->thamNien = thamNien;
    }
    void setMonDay(string monDay)
    {
        this->monDay = monDay;
    }
    string getMonDay()
    {
        return monDay;
    }
    void setTrinhDo(string trinhDo)
    {
        this->trinhDo = trinhDo;
    }
    string getTrinhDo()
    {
        return trinhDo;
    }
    void setThamNien(int thamNien)
    {
        this->thamNien = thamNien;
    }
    int getThamNien()
    {
        return thamNien;
    }
    void input()
    {
        VienChuc::input();
        cout << "Nhap mon day: ";
        getline(cin, monDay);
        cout << "Nhap trinh do: ";
        getline(cin, trinhDo);
        cout << "Nhap tham nien: ";
        cin >> thamNien;
        cin.ignore();
    }
    void output()
    {
        VienChuc::output();
        cout << "Mon day: " << monDay << endl;
        cout << "Trinh do: " << trinhDo << endl;
        cout << "Tham nien: " << thamNien << endl;
    }
    float luong()
    {
        return getHsl() *2000000*(130+getThamNien())/100;
    }
};

int main()
{
    int n;
    cout<<"Nhap so luong vien chuc: ";
    cin>>n;
    cin.ignore();

    VienChuc *a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap thong tin vien chuc thu "<<i+1<<endl;
        int choice;
        cout<<"1. Nhap thong tin CB hanh chinh"<<endl;
        cout<<"2. Nhap thong tin giao vien"<<endl;
        cout<<"Nhap lua chon: ";
        cin>>choice;
        cin.ignore();
        if(choice==1)
        {
            a[i]=new CBHanhChinh();
            a[i]->input();
        }
        else if(choice==2)
        {
            a[i]=new Teacher();
            a[i]->input();
        }
    }
    cout<<"Danh sach vien chuc: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Vien chuc thu "<<i+1<<endl;
        a[i]->output();
        cout<<"Luong: "<<a[i]->luong()<<endl;
    }
    cout<<"Danh sach vien chuc co luong cao nhat: "<<endl;
    float max=a[0]->luong();
    for(int i=0;i<n;i++)
    {
        if(a[i]->luong()>max)
        {
            max=a[i]->luong();
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]->luong()==max)
        {
            a[i]->output();
            cout<<"Luong: "<<a[i]->luong()<<endl;
        }
    }
    return 0;
}
