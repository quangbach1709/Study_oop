#include<iostream>
#include<string>

using namespace std;

class KH
{
    private:
        int makh,count=10000,sdt;
        bool loaikh;
        string namekh,diachi;
    public:
        void input()
        {
            makh=count;
            cout<<"Ma Khanh Hang: "<<makh<<endl;
            count++;
            cout<<"Nhap Ho Ten KH: ";
            getline(cin,namekh);
            cout<<"Nhap Dia Chi: ";
            getline(cin,diachi);
            cout<<"Nhap SDT: ";
            cin>>sdt;
            cin.ignore();

        }

        string getNameKH()
        {
            return namekh;
        }
};

class MH
{
    private:
        int mah,count=1000,gia,solung;
        string nameh,nhomh;
    public:
        void input()
        {
            mah=count;
            cout<<"Ma Hang: "<<mah<<endl;
            count++;
            cout<<"Nhap Ten Hang: ";
            getline(cin,nameh);
            cout<<"Nhap Nhom Hang: ";
            getline(cin,nhomh);
            cout<<"Nhap Gia: ";
            cin>>gia;
            cin.ignore();
            cout<<"Nhap so luong: ";
            cin>>solung;
            cin.ignore();
        }
        int getSoluongHang()
        {
            return solung;
        }
        string getNameHang()
        {
            return nameh;
        }
};

class BDS
{
    private:
        KH human;
        MH hang[10];
    public:
        void input()
        {
            human.input();
            int dem=0;
            string tmp;
            while (dem<=10)
            {
                cout<<"Ban co muon mua hang khong? (y/n): ";
                getline(cin,tmp);
                if (tmp=="y")
                {
                    MH tmp;
                    tmp.input();
                    for (int i = 0; i < dem; i++)
                    {
                        if (tmp.getNameHang()==hang[i].getNameHang() || tmp.getSoluongHang()>10)
                        {
                            cout<<"Hay nhap lai"<<endl;
                            tmp.input();
                            //i=-1;
                        }
                        
                    }
                    hang[dem]=tmp;
                    dem++;
                    
                }
                else
                {
                    break;
                }
                
            }
            
        }
};
int main()
{
    //dung vector nhap danh sach khach hang

    


}