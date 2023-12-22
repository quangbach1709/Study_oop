#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Human
{
    private:
        string HoTen;
        int year;
    public:
        Human(){};
        Human(string HoTen,int year)
        {
            this->HoTen=HoTen;
            this->year=year;
        }

        string getHoTen()
        {
            return HoTen;
        }
        int getNamSinh()
        {
            return year;
        }

        void setHoTen(string HoTen)
        {
            this->HoTen=HoTen;
        }
        void setNamSinh(int year)
        {
            this->year=year;
        }
        virtual void input()
        {
            cout<<"Nhap Ho Ten: ";
            getline(cin,HoTen);
            cout<<"Nhap Nam Sinh: ";
            cin>>year;
            cin.ignore();
        }
        virtual void output()
        {
            cout<<"Ho Ten La: "<<HoTen<<endl;
            cout<<"Nam Sinh la: "<<year<<endl;
        }
};

class BenhNhan : public Human
{
    private:
        string NameBanhAn;
        int dayNamVien;
        float gia;
    public:
        BenhNhan(){};
        BenhNhan(string NameBanhAn,string HoTenBenhNhanh,int year,int dayNamVien)
        {
            this->NameBanhAn=NameBanhAn;
            this->dayNamVien=dayNamVien;
            this->setHoTen(HoTenBenhNhanh);
            this->setNamSinh(year);
        }
        void input()
        {
            Human::input();
            cout<<"Nhap Ten Benh An: ";
            getline(cin,NameBanhAn);
            cout<<"Nhap Ngay Nam Vien: ";
            cin>>dayNamVien;
            cin.ignore();
            cout<<"Nhap Gia: ";
            cin>>gia;
            cin.ignore();
        }
        void output()
        {
            Human::output();
            cout<<"Ten Benh An la: "<<NameBanhAn<<endl;
            cout<<"Ngay Nam Vien la: "<<dayNamVien<<endl;
            cout<<"Gia la: "<<gia<<endl;

        }
        int tinhTuoi()
        {
            return 2023-getNamSinh();
        }
        float vienPhi()
        {
            return dayNamVien*gia;
        }


};

class BacSi:public Human
{
    private:
        string MaBS;
        float dayword;
        float money;
    public:
        BacSi(){};
        BacSi(string HoTen,int year,string MaBS,float dayword)
        {
            this->MaBS=MaBS;
            this->dayword=dayword;
            this->setHoTen(HoTen);
            this->setNamSinh(year);
        }
        void input()
        {
            Human::input();
            cout<<"Nhap Ma BS: ";
            cin>>MaBS;
            cout<<"Nhap Ngay lam viec: ";
            cin>>dayword;
            cout<<"Nhap tien: ";
            cin>>money;
        }
        void output()
        {
            Human::output();
            cout<<"Ma BS la: "<<MaBS<<endl;
            cout<<"Ngay lam viec la: "<<dayword<<endl;
        }
        float tienCongThang()
        {
            return dayword*money;
        }
        float getNgayWord()
        {
            return dayword;
        }
};
int main()
{
    Human *ptr;
    int dem=0;
    vector<BenhNhan>BN;
    vector<BacSi>BS;
    int continues;
    while (dem<=100)
    {
        cout<<"Ban muon nhap Benh Nhanh hay Bac Si(1:Nhap Benh Mhan,2:Nhap Bac Si,0:Exit)"<<endl;
        cin>>continues;
        if (continues==1)
        {
            BenhNhan tmp;
            ptr=&tmp;
            ptr->input();
            BN.push_back(tmp);
            dem++;
        }
        else if (continues==2)
        {
            BacSi tmp;
            ptr=&tmp;
            ptr->input();
            BS.push_back(tmp);
            dem++;
        }
        else
            break;
        
        
    }

    cout<<"Xuat danh sach Human: "<<endl;
    cout<<"Danh sach Benh Nhanh: "<<endl;
    for (int i = 0; i < BN.size(); i++)
    {
        BN[i].output();
    }
    cout<<"Danh sach Bac Si: "<<endl;
    for (int i = 0; i < BS.size(); i++)
    {
        BS[i].output();
    }
    cout<<"Danh sach Benh Nhanh tuoi <=10 la: "<<endl;
    for (int i = 0; i < BN.size(); i++)
    {
        if (BN[i].getNamSinh()<=10)
        {
            BN[i].output();
        }
        
    }
    cout<<"Cac bac si lam nhieu ngay nhat la: "<<endl;
    float daywordmax=BS[0].getNgayWord();
    for (int i = 0; i < BS.size(); i++)
    {
        if (BS[i].getNgayWord()>daywordmax)
        {
            daywordmax=BS[i].getNgayWord();
        }
        
    }
    for (int i = 0; i < BS.size(); i++)
    {
        if (BS[i].getNgayWord()==daywordmax)
        {
            BS[i].output();
        }
        
    }  
}