#include<iostream>
#include<string>
#include<vector>

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

        void output()
        {
            
            cout<<makh<<"\t"<<namekh<<"\t"<<diachi<<"\t"<<sdt<<endl;
        }
        string getNameKH()
        {
            return namekh;
        }
        friend void nhapKH(vector<KH> &listKH,int &dem);
        friend void xuatKH(vector<KH> &listKH);
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
        void output()
        {
            
            cout<<mah<<"\t"<<nameh<<"\t"<<nhomh<<"\t"<<gia<<"\t"<<solung<<endl;
        }

        int getSoluongHang()
        {
            return solung;
        }
        string getNameHang()
        {
            return nameh;
        }
        friend void nhapMH(vector<MH> &listMH,int &dem);
        friend void xuatMH(vector<MH> &listMH);
};

class BDS
{
    private:
        KH human;
        MH hang[10];
        int dem=0;
    public:
        void input()
        {
            human.input();
            
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
                            i=-1;
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

        void output()
        {
            human.output();
            cout<<"-------------------------"<<endl;
            for (int i = 0; i < dem; i++)
            {
                
                hang[i].output();
            }
            cout<<"-------------------------"<<endl;
            
        }
        friend void nhapBDS(vector<BDS> &listBDS,int &dem);
};

void nhapKH(vector<KH> &listKH,int &dem)
{
    KH tmp;
        tmp.input();
        listKH.push_back(tmp);
        dem++;
}

void xuatKH(vector<KH> &listKH)
{
    cout<<"Danh sach khach hang: "<<endl;
    cout<<"Ma Khanh Hang"<<"\t"<<"Ho Ten KH"<<"\t"<<"Dia Chi"<<"\t"<<"SDT"<<endl;
    for (int i = 0; i < listKH.size(); i++)
    {
        listKH[i].output();
    }
    
}

void nhapMH(vector<MH> &listMH,int &dem)
{
    MH tmp;
    tmp.input();
    listMH.push_back(tmp);
    dem++;
}

void xuatMH(vector<MH> &listMH)
{
    cout<<"Danh sach mat hang: "<<endl;
    cout<<"Ma Hang"<<"\t"<<"Ten Hang"<<"\t"<<"Nhom Hang"<<"\t"<<"Gia"<<"\t"<<"So Luong"<<endl;
    for (int i = 0; i < listMH.size(); i++)
    {
        listMH[i].output();
    }
    
}

void nhapBDS(vector<BDS> &listBDS,int &dem)
{
    BDS tmp;
    tmp.input();
    listBDS.push_back(tmp);
    dem++;
}
// xuat bang danh sach mua hang theo ten khach hang
void xuatBDS(vector<BDS> &listBDS)
{
    cout<<"Danh sach mua hang: "<<endl;
    cout<<"Ma Khanh Hang"<<"\t"<<"Ho Ten KH"<<"\t"<<"Dia Chi"<<"\t"<<"SDT"<<endl;
    for (int i = 0; i < listBDS.size(); i++)
    {
        listBDS[i].output();
    }
    
}

int main()
{
    vector<KH> listKH;
    vector<MH> listMH;
    vector<BDS> listBDS;
    //nhap thong tin khach hang khi khong biet so luong khach hang
    int dem=0;
    string tmp;
    // while (true)
    // {
    //     cout<<"Ban co muon nhap thong tin khach hang khong? (y/n): ";
    //     getline(cin,tmp);
    //     if (tmp=="y")
    //     {
    //         nhapKH(listKH,dem);
    //     }
    //     else
    //     {
    //         break;
    //     }
        
    // }
    // xuatKH(listKH);

    // while (1)
    // {
    //     cout<<"Ban co muon nhap thong tin mat hang khong? (y/n): ";
    //     getline(cin,tmp);
    //     if (tmp=="y")
    //     {
    //         nhapMH(listMH,dem);
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // xuatMH(listMH);

    while (1)
    {
        cout<<"Ban co muon nhap danh sach mua hang? (y/n): ";
        getline(cin,tmp);
        if (tmp=="y")
        {
            nhapBDS(listBDS,dem);
        }
        else
        {
            break;
        }
    }
    
    

    return 0;
    


}