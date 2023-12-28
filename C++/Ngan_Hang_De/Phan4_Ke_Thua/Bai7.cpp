#include<iostream>
#include<string>

using namespace std;

class Book
{
    private:
        static int  maBook;
        int yearXuatBan;
        string nameBook,chuyenNganh,tacGia;
    public:
        void input()
        {
            cout<<"Ma sach la: "<<maBook<<endl;
            cout<<"Nhap Ten sach: ";
            getline(cin,nameBook);
            cout<<"Nhap Tac gia: ";
            getline(cin,tacGia);
            cout<<"Nhap Chuyen nganh: ";
            getline(cin,chuyenNganh);
            cout<<"Nhap nam xuat ban: ";
            cin>>yearXuatBan;
            cin.ignore();
        }
        void output()
        {
            cout<<"Ma sach la: "<<maBook<<endl;
            cout<<"Ten sach la: "<<nameBook<<endl;
            cout<<"Tac gia la: "<<tacGia<<endl;
            cout<<"Chuyen nganh la: "<<chuyenNganh<<endl;
            cout<<"Nam xuat ban la: "<<yearXuatBan<<endl; 
        }

};

class Human
{
    private:
        string hoTen,diaChi;
        int sdt;
    public:
        virtual void input()
        {
            cout<<"Nhap Ho ten: ";
            getline(cin,hoTen);
            cout<<"Nhap Dia chi: ";
            getline(cin,diaChi);
            cout<<"Nhap SDT: ";
            cin>>sdt;

        }
        virtual void output()
        {
            cout<<"Ho ten la: "<<hoTen<<endl;
            cout<<"Dia chi la: "<<diaChi<<endl;
            cout<<"SDT la: "<<sdt<<endl;
        }

};

class FriendRead :public Human
{
    private:
        static int maCardRead;
        int soSachMuon;
        string loaiFriendRead;
    public:

};