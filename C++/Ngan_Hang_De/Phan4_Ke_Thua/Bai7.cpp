#include<iostream>
#include<string>
#include<vector>

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
        void input()
        {
            Human::input();
            cout<<"Nhap thong tin cua the doc "<<maCardRead<<endl;
            cout<<"Nhap so luong sach muon: ";
            cin>>soSachMuon;
            cin.ignore();
            cout<<"Nhap loai ban doc: ";
            getline(cin,loaiFriendRead);
            
        }
        void output()
        {
            Human::output();
            cout<<"Ma the doc la: "<<maCardRead<<endl;
            cout<<"So luong sach muon la: "<<soSachMuon<<endl;
            cout<<"Loai ban doc la: "<<loaiFriendRead<<endl;
        }

};
int FriendRead :: maCardRead=10000;
int main()
{
    Book *ptr;
    Human *ptr_fun;
    vector<Book>book;
    vector<FriendRead>fbook;
    int dem=0;
    bool check;
    do
    {
        cout<<"Nhap vao quyen sach thu "<<dem+1<<endl;
        Book tmpbook;
        ptr=&tmpbook;
        ptr->input();
        book.push_back(tmpbook);
        dem++;
        cout<<"Ban muon tiep tuc nhap ?(1:yes or 0 no) ";
        cin>>check;
        if (!check)
        {
            dem=0;
        }
        
    } while (check);

    do
    {
        cout<<"Nhap vao ban doc thu "<<dem+1<<endl;
        FriendRead tmpfbook;
        ptr_fun=&tmpfbook;
        ptr_fun->input();
        fbook.push_back(tmpfbook);
        dem++;
        cout<<"Ban muon tiep tuc nhap ?(1:yes or 0 no) ";
        cin>>check;
        if (!check)
        {
            dem=0;
        }
    } while (check);
    
    

}