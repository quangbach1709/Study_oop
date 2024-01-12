#include<iostream>
#include<string>

using namespace std;

class FriendRead
{
    private:
        static int maFriend;
        int sdt;
        string HoTen,DiaChi,loaiFriend;
    public:
        FriendRead();
        FriendRead(string hoten,string diachi,int sdt,string loai)
        {
            
            HoTen=hoten;
            DiaChi=diachi;
            this->sdt=sdt;
            loaiFriend=loai;
        }
        void setHoTen(string hoten)
        {
            HoTen=hoten;
        }
        void setDiaChi(string diachi)
        {
            DiaChi=diachi;
        }
        void setSDT(int sdt)
        {
            this->sdt=sdt;
        }
        void setLoaiFriend(string loai)
        {
            loaiFriend=loai;
        }
        string getHoTen()
        {
            return HoTen;
        }
        string getDiaChi()
        {
            return DiaChi;
        }
        int getSDT()
        {
            return sdt;
        }
        string getLoaiFriend()
        {
            return loaiFriend;
        }
        int getMaFriend()
        {
            return maFriend;
        }


};
int FriendRead:: maFriend=10000;

class Book
{
    private:
        static int maBook;
        string nameBook,tacGia,chuyenNganh;
        int year;
    public:
        Book();
        Book(string name,string tacgia,string nganh,int nam)
        {
            year=nam;
            nameBook=name;
            tacGia=tacgia;
            chuyenNganh=nganh;
        }
        void setNameBook(string name)
        {
            nameBook=name;
        }
        void setTacGia(string tacgia)
        {
            tacGia=tacgia;
        }
        void setChuyenNganh(string nganh)
        {
            chuyenNganh=nganh;
        }
        void setYear(int nam)
        {
            year=nam;
        }
        string getNameBook()
        {
            return nameBook;
        }
        string getTacGia()
        {
            return tacGia;
        }
        string getChuyenNganh()
        {
            return chuyenNganh;
        }
        int getYear()
        {
            return year;
        }
        int getMaBook()
        {
            return maBook;
        }


};
int Book::maBook=10000;

class TableQL
{
    private:
        
};