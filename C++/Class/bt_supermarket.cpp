#include<iostream>
#include<string>
#include<vector>

using namespace std;

class KH
{
    private:
        int makh,sdt;
        static int count;
        bool loaikh;
        string namekh,diachi;
    public:
        KH()
        {
            makh=count++;
        }
        void input()
        {
            
            cout<<"Ma Khanh Hang: "<<makh<<endl;
            
            cout<<"Nhap Ho Ten KH: ";
            getline(cin,namekh);
            cout<<"Nhap Dia Chi: ";
            getline(cin,diachi);
            cout<<"Nhap SDT: ";
            cin>>sdt;
            cin.ignore();

        }

        void output()
        {
            
            cout<<makh<<"\t"<<namekh<<"\t"<<diachi<<"\t"<<sdt;
        }
        string getNameKH()
        {
            return namekh;
        }

        friend void addkh(vector<KH> &listkh, int &dem);
        
};
int KH::count=1000;
class MH
{
    private:
        int mah,gia,solung;
        static int count;
        string nameh,nhomh;
    public:
        MH()
        {
            mah=count++;
        }
        
        void input()
        {
            
            cout<<"Ma Hang: "<<mah<<endl;
            
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
        void output()
        {
            
            cout<<mah<<"\t"<<nameh<<"\t"<<nhomh<<"\t"<<gia<<"\t"<<solung;
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
int MH::count=1000;

class BDS
{
    private:
        KH human;
        vector<MH> hang;
        int dem=0;
    public:
        void input()
        {
            human.input();
            
            string tmp;
            while (dem<10)
            {
                cout<<"Ban co muon mua hang khong? (y/n): ";
                getline(cin,tmp);
                if (tmp=="y")
                {
                    MH tmp;
                    tmp.input();
                    for (int i = 0; i < hang.size(); i++)
                    {
                        if (tmp.getNameHang()==hang[i].getNameHang() || tmp.getSoluongHang()>10)
                        {
                            cout<<"Hay nhap lai"<<endl;
                            tmp.input();
                            i=-1;
                        }
                        
                    }
                    hang.push_back(tmp);
                    dem++;
                    
                }
                else
                {
                    break;
                }
                
            }
            
        }

        void output()
        {
            cout<<"Thong tin khach hang:"<<endl;
            human.output();
            cout<<endl;
            cout<<"Thong tin mat hang:"<<endl;
            for (int i = 0; i < hang.size(); i++)
            {
                
                hang[i].output();
                cout<<endl;
            }
            
            
        }
        string getNameKH()
        {
            return human.getNameKH();
        }
        
};



void addkh(vector<KH> &listkh, int &dem)
{
    KH tmp;
    tmp.input();
    listkh.push_back(tmp);
    dem++;
}

void xuatlistkh(vector<KH> listkh)
{
    cout<<"Ma KH\tTen KH\tDia Chi\tSDT"<<endl;
    for (int i = 0; i < listkh.size(); i++)
    {
        listkh[i].output();
        cout<<endl;
    }
    
}

void addmh(vector<MH> &listmh, int &dem)
{
    MH tmp;
    tmp.input();
    listmh.push_back(tmp);
    dem++;
}

void xuatmh(vector<MH> listmh)
{
    cout<<"Ma Hang\tTen Hang\tNhom Hang\tGia\tSo Luong"<<endl;
    for (int i = 0; i < listmh.size(); i++)
    {
        listmh[i].output();
        cout<<endl;
    }
    
}

void addbds(vector<BDS> &listbds, int &dem)
{
    BDS tmp;
    tmp.input();
    listbds.push_back(tmp);
    dem++;
}

void xuatbds(vector<BDS> listbds)
{
    cout<<"Bang danh sach:"<<endl;
    for (int i = 0; i < listbds.size(); i++)
    {
        listbds[i].output();
        cout<<endl;
    }
    
}

void kiemtrabds(vector<BDS> listbds)
{
    //cung 1 mat hang va khach hang k duoc xuat hien 2 lan

    
    
}

int main()
{
    vector<KH> listkh;
    int dem=0;
    string tmp;
    while (1)
    {
        cout<<"Ban co muon nhap KH khong? (y/n): ";
        getline(cin,tmp);
        if (tmp=="n")
        {
            break;
        }
        else
        {
            addkh(listkh,dem);
        }
    }
    xuatlistkh(listkh);

    vector<MH> listmh;
    dem=0;
    while (1)
    {
        cout<<"Ban co muon nhap Mat Hang khong? (y/n): ";
        getline(cin,tmp);
        if (tmp=="n")
        {
            break;
        }
        else
        {
            addmh(listmh,dem);
        }
    }
    xuatmh(listmh);

    vector<BDS> listbds;
    dem=0;
    while (1)
    {
        cout<<"Ban co muon nhap bang danh sach khong? (y/n): ";
        getline(cin,tmp);
        if (tmp=="n")
        {
            break;
        }
        else
        {
            addbds(listbds,dem);
            for (int i = 0; i < listbds.size(); i++)
            {
                if (listbds[listbds.size()-1].getNameKH()==listbds[i].getNameKH() )              
                {
                    cout<<"Khong duoc trung ten khach hang"<<endl;
                    listbds.pop_back();
                    dem--;
                    cout<<"Nhap lai"<<endl;
                    addbds(listbds,dem);
                }
                
            }
            
        }
    }
    xuatbds(listbds);


    return 0;
    
}