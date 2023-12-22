#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Meds
{
    private:
        int MaMeds;
        string NameMeds,hangMeds;
        float gia;
    public:
        Meds(){};
        Meds(int MaMeds,string NameMeds,string hangMeds,float gia)
        {
            this->MaMeds=MaMeds;
            this->NameMeds=NameMeds;
            this->hangMeds=hangMeds;
            this->gia=gia;
        }
        ~Meds()
        {
            cout<<"Da huy Thuoc."<<endl;
        }
        int getMaThuoc()
        {
            return MaMeds;
        }
        void setMaThuoc(int Mathuoc)
        {
            this->MaMeds=Mathuoc;
        }
        string getNameMeds()
        {
            return NameMeds;
        }
        void setNameThuoc(string nameThuoc)
        {
            this->NameMeds=nameThuoc;
        }
        string getHangMeds()
        {
            return hangMeds;
        }
        void setHangThuoc(string hangThuoc)
        {
            this->hangMeds=hangThuoc;
        }
        float getGia()
        {
            return gia;
        }
        void setGia(float gia)
        {
            this->gia=gia;
        }
        virtual void input()
        {
            cout<<"Nhap Ma thuoc: ";
            cin>>MaMeds;
            cin.ignore();
            cout<<"Nhap Ten Thuoc: ";
            getline(cin,NameMeds);
            cout<<"Nhap Hang Thuoc: ";
            getline(cin,hangMeds);
            cout<<"Nhap gia thuoc: ";
            cin>>gia;
            cin.ignore();
        }
        virtual void output()
        {
            cout<<"Ma thuoc la: "<<MaMeds<<endl;
            cout<<"Ten thuoc la: "<<NameMeds<<endl;
            cout<<"Hang thuoc la: "<<hangMeds<<endl;
            cout<<"Gia thuoc la: "<<gia<<endl; 
        }
        bool operator==(Meds tmp)
        {
            if (MaMeds==tmp.MaMeds)
            {
                return true;
            }
            return false;
            
        }

};


class ThuocBo :public Meds
{
    private:
        string congdung;
    public:
        ThuocBo(){};
        ThuocBo(int maMeds,string namethuoc,string hangthuoc,string congdung,float gia)
        {
            this->congdung=congdung;
            this->setMaThuoc(maMeds);
            this->setGia(gia);
            this->setHangThuoc(hangthuoc);
            this->setNameThuoc(namethuoc);
        }
        string getCongDung()
        {
            return congdung;
        }
        void setCongDung(string congdung)
        {
            this->congdung=congdung;
        }
        void input()
        {
            Meds::input();
            cout<<"Nhap Cong Dung: ";
            getline(cin,congdung);

        }
        void output()
        {
            Meds::output();
            cout<<"Cong dung thuoc la: "<<congdung<<endl;
        }

};

class KhangSinh: public Meds
{
    private:
        int hamLuongMeds;
    public:
        KhangSinh(){};
        KhangSinh(int maMeds,string namethuoc,string hangthuoc,int hamluong,float gia)
        {
            this->hamLuongMeds=hamluong;
            this->setGia(gia);
            this->setHangThuoc(hangthuoc);
            this->setMaThuoc(maMeds);
            this->setNameThuoc(namethuoc);
        }
        int getHamLuongThuoc()
        {
            return hamLuongMeds;
        }
        void setHamLuongThuoc(int hamluong)
        {
            this->hamLuongMeds=hamluong;
        }
        void input()
        {
            Meds::input();
            cout<<"Nhap ham luong thuoc: ";
            cin>>hamLuongMeds;

        }
        void output()
        {
            Meds::output();
            cout<<"Ham luong thuoc la: "<<hamLuongMeds<<endl;
        }
};

int main()
{
    Meds *ptr;
    vector<ThuocBo>TB;
    vector<KhangSinh>KS;
    int dem=0;
    int continues;
    while (dem<=10)
    {
        cout<<"Ban muon nhap thuoc nao?(1:Thuoc Bo,2:Thuoc khang sinh,0:exit)"<<endl;
        cin>>continues;
        if (continues==1)
        {
            ThuocBo tmp;
            ptr=&tmp;
            ptr->input();
            TB.push_back(tmp);
            dem++;
        }
        else if (continues==2)
        {
            KhangSinh tmp;
            ptr=&tmp;
            ptr->input();
            KS.push_back(tmp);
            dem++;
        }
        
        
    }
    cout<<"Danh sach thuoc la: "<<endl;
    cout<<"Danh sach thuoc bo: "<<endl;
    for (int i = 0; i < TB.size(); i++)
    {
        TB[i].output();
    }
    cout<<"Danh sach thuoc khanh sinh:"<<endl;
    for (int i = 0; i < KS.size(); i++)
    {
        KS[i].output();
    }

    ThuocBo tmpBo;
    KhangSinh tmpKS;
    while (1)
    {
        cout<<"Ban muon nhap thuoc nao?(1:Thuoc Bo,2:Thuoc khang sinh,0:exit)"<<endl;
        cin>>continues;
        if (continues==1)
        {
            ptr=&tmpBo;
            ptr->input();
        }
        else if (continues==2)
        {
            ptr=&tmpKS;
            ptr->input();
        }
        else
            break;
        
    }
    for (int i = 0; i < TB.size(); i++)
    {
        if (TB[i]==tmpBo)
        {
            cout<<"Co trong danh sach thuoc bo."<<endl;
            break;
        }
        
    }
    for (int i = 0; i < KS.size(); i++)
    {
        if (KS[i]==tmpKS)
        {
            cout<<"Co trong danh sach thuoc khang sinh."<<endl;
            break;
        }
        
    }
    
    
    
    
    
    
}
