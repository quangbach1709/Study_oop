#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Book
{
    private:
        int mabook;
        static int count;
        string namebook,tacgia,chuyennganh;
        int year;
    public:
        Book()
        {
            mabook=count++;
            namebook='0';
            tacgia='0';
            chuyennganh='0';
            year=0;
        }
        Book(string name,string tacgia,string nganh,int nam)
        {
            namebook=name;
            this->tacgia=tacgia;
            chuyennganh=nganh;
            year=nam;
        }
        void setNameBook(string name)
        {
            namebook=name;
        }
        string getNameBook()
        {
            return namebook;
        }
        void setTacGia(string tacgia)
        {
            this->tacgia=tacgia;
        }
        string getTacGia()
        {
            return tacgia;
        }
        void setChuyenNganh(string nganh)
        {
            chuyennganh=nganh;
        }
        string getChuyenNganh()
        {
            return chuyennganh;
        }
        void setYear(int nam)
        {
            year=nam;
        }
        int getYear()
        {
            return year;
        }
        void input()
        {
            cout<<"Nhap thong tin cho sach co ma: "<<mabook<<endl;
            cout<<"Nhap ten sach: ";
            getline(cin,namebook);
            cout<<"Nhap tac gia: ";
            getline(cin,tacgia);
            cout<<"Nhap chuyen nganh: ";
            getline(cin,chuyennganh);
            cout<<"Nhap nam xuat ban: ";
            cin>>year;
            cin.ignore();

        }
        void output()
        {
            cout<<"Ma sach: "<<mabook<<endl;
            cout<<"Ten sach: "<<namebook<<endl;
            cout<<"Tac gia: "<<tacgia<<endl;
            cout<<"Chuyen nganh: "<<chuyennganh<<endl;
            cout<<"Nam xuat ban: "<<year<<endl;
            cout<<"----------------------------"<<endl;
        }

};
int Book::count=10000;

class Human
{
    private:
        string hoten,diachi;
        int sdt;
    public:
        Human()
        {
            hoten='0';
            diachi='0';
            sdt=0;
        }
        Human(string ten,string diachi,int sdt)
        {
            hoten=ten;
            this->diachi=diachi;
            this->sdt=sdt;
        }
        void setHoTen(string ten)
        {
            hoten=ten;
        }
        string getHoTen()
        {
            return hoten;
        }
        void setDiaChi(string diachi)
        {
            this->diachi=diachi;
        }
        string getDiaChi()
        {
            return diachi;
        }
        void setSDT(int sdt)
        {
            this->sdt=sdt;
        }
        int getSDT()
        {
            return sdt;
        }
        virtual void input()
        {
            cout<<"Nhap ho ten: ";
            getline(cin,hoten);
            cout<<"Nhap dia chi: ";
            getline(cin,diachi);
            cout<<"Nhap sdt: ";
            cin>>sdt;
            cin.ignore();
        }
        virtual void output()
        {
            cout<<"Ho ten: "<<hoten<<endl;
            cout<<"Dia chi: "<<diachi<<endl;
            cout<<"SDT: "<<sdt<<endl;
        }
};

class FriendRead :public Human
{
    private:
        int ma;
        static int dem1;
        string loaifriend;
        int sobook;
        Book listbook[100];
    public:
        FriendRead()
        {
            ma=dem1++;
            loaifriend='0';
            sobook=0;
        }
        FriendRead(string loai,int so)//:Human(ten,diachi,sdt)
        {
            loaifriend=loai;
            sobook=so;

        }
        void setLoaiBanDoc(string loai)
        {
            loaifriend=loai;
        }
        string getLoaiBanDoc()
        {
            return loaifriend;
        }
        void setSoSach(int so)
        {
            sobook=so;
        }
        int getSoSach()
        {
            return sobook;
        }
        void input()
        {
            cout<<"Nhap thong tin cho ma ban doc: "<<ma<<endl;
            Human::input();
            cout<<"Nhap loai ban doc: ";
            getline(cin,loaifriend);
            cout<<"Nhap so sach muon: ";
            cin>>sobook;
            cin.ignore();
            cout<<"Nhap list sach muon: "<<endl;
            for (int i = 0; i < sobook; i++)
            {
                cout<<"Nhap sach thu "<<i+1<<endl;
                listbook[i].input();
            }
            
        }
        void output()
        {
            Human::output();
            cout<<"Ma ban doc: "<<ma<<endl;
            cout<<"Loai ban doc: "<<loaifriend<<endl;
            cout<<"So sach muon: "<<sobook<<endl;
            cout<<"List sach muon: "<<endl;
            for (int i = 0; i < getSoSach(); i++)
            {
                listbook[i].output();
            }
            cout<<"------------------------------"<<endl;
            
        }
};
int FriendRead::dem1 =10000;

int main()
{
    int dem=0;
    bool tmp;
    Book listBook[100];
    FriendRead FR[100];
    while (1)
    {
        cout<<"Nhap vao sach hien co(1 tiep tuc nhap 0 dung nhap): ";
        cin>>tmp;
        cin.ignore();
        if (tmp)
        {
            listBook[dem].input();
            dem++;
        }
        else
        {
            break;
            dem=0;
        }
        
    }
    while (1)
    {
        cout<<"Nhap danh sach ban doc(1 tiep tuc nhap 0 dung nhap): "<<endl;
        cin>>tmp;
        cin.ignore();
        if (tmp)
        {
            FR[dem].input();
            dem++;
        }
        else
        {
            break;
            dem=0;
        }
        
    }
    cout<<"Danh sach cuon sach hien co: "<<endl;
    for (int i = 0; i < 100; i++)
    {
        if (listBook[i].getYear()==0)
        {
            cout<<"Khong co sach."<<endl;
            break;
        }
        else
        {
            listBook[i].output();
        }
        
    }
    cout<<"Danh sach Ban doc: "<<endl;
    for (int i = 0; i < 100; i++)
    {
        if (FR[i].getSoSach()==0)
        {
            cout<<"Khong co ban doc nao."<<endl;
            break;
        }
        else
        {
            FR[i].output();
        }
        
    }
    
    
    
    
    
}