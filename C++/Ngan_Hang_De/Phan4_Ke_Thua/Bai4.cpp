#include<iostream>
#include<string>

using namespace std;

class MonHoc
{
    private:
        string TenMon;
        int DiemTP,SoTC;
        float DiemThi;

    public:
        MonHoc(){};
        ~MonHoc()
        {
            cout<<"Da huy mon hoc."<<endl;
        }
        virtual void input()
        {
            cout<<"Nhap ten Mon: ";
            getline(cin,TenMon);
            cout<<"Nhap Diem TP: ";
            cin>>DiemTP;
            cout<<"Nhap so TC: ";
            cin>>SoTC;
            cout<<"Nhap deim thi: ";
            cin>>DiemThi;
        }
        virtual void output()
        {
            cout<<"Ten Mon la: "<<TenMon<<endl;
            cout<<"DiemTP la: "<<DiemTP<<endl;
            cout<<"SoTC la: "<<SoTC<<endl;
            cout<<"Diem Thi la: "<<DiemThi<<endl;
        }
        float DTB()
        {
            return DiemTP*0.3+DiemThi*0.7;
        }
        int getSoTC()
        {
            return SoTC;
        }

};

class SinhVien
{
    private:
        int MaSV,SoMH;
        string TenSV;
        MonHoc a[1000];
    public:
        SinhVien(){};
        ~SinhVien()
        {
            cout<<"Da huy Sinh vien."<<endl;
        }
        float DTK(int SoTC,float DiemTB)
        {
            return (DiemTB*SoTC)/SoTC;
        }
        
        void input()
        {
            cout<<"Nhap Ma SV: ";
            cin>>MaSV;
            cin.ignore();
            cout<<"Nhap Ten SV: ";
            getline(cin,TenSV);
            cout<<"Nhap So MH: ";
            cin>>SoMH;
            cin.ignore();
            for(int i=0;i<SoMH;i++)
            {
                cout<<"Nhap Mon hoc thu "<<i+1<<endl;
                a[i].input();
                
            }
        }
};