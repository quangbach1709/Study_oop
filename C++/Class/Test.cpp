#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Mayin
{
    private:
        int mamayin;
        string hangsanxuat;
    public:
        Mayin(){};
        Mayin(int mamayin,string hangsanxuat)
        {
            this->mamayin=mamayin;
            this->hangsanxuat=hangsanxuat;
        }
        int getMamayin()
        {
            return mamayin;
        }
        string getHangsanxuat()
        {
            return hangsanxuat;
        }
        void setMamayin(int mamayin)
        {
            this->mamayin=mamayin;
        }
        void setHangsanxuat(string hangsanxuat)
        {
            this->hangsanxuat=hangsanxuat;
        }
        virtual void input()
        {
            cout<<"Nhap Ma may in: ";
            cin>>mamayin;
            cin.ignore();
            cout<<"Nhap Hang san xuat: ";
            getline(cin,hangsanxuat);
        }
        virtual void output()
        {
            cout<<"Ma may in la: "<<mamayin<<endl;
            cout<<"Hang san xuat: "<<hangsanxuat<<endl;
        }

        virtual bool chatLuongCao()=0;
};

class MayinKim:public Mayin
{
    private:
        int sokim;
    public:
        MayinKim(){};
        MayinKim(int sokim,int mamayin,string hangsanxuat)
        {
            this->sokim=sokim;
            this->setMamayin(mamayin);
            this->setHangsanxuat(hangsanxuat);
        }
        int getSokim()
        {
            return sokim;
        }
        void setSokim(int sokim)
        {
            this->sokim=sokim;
        }
        void input()
        {
            Mayin::input();
            cout<<"Nhap So Kim: ";
            cin>>sokim;
        }
        void output()
        {
            Mayin::output();
            cout<<"So kim la: "<<sokim<<endl;
        }
        bool chatLuongCao()
        {
            if (getSokim()>=24)
            {
                return 1;
            }
            return 0;
            
        }
};

class MayinLaser: public Mayin
{
    private:
        int dophangiai;
    public:
        MayinLaser(){};
        MayinLaser(int dophangiai,int mamayin,string hangsanxuat)
        {
            this->dophangiai=dophangiai;
            this->setMamayin(mamayin);
            this->setHangsanxuat(hangsanxuat);
        }
        int getDophangiai()
        {
            return dophangiai;
        }
        void setDophangiai(int dophangiai)
        {
            this->dophangiai=dophangiai;
        }
        void input()
        {
            Mayin::input();
            cout<<"Nhap Do phan giai: ";
            cin>>dophangiai;
        }
        void output()
        {
            Mayin::output();
            cout<<"Do phan giai la: "<<dophangiai<<endl;
        }
        bool chatLuongCao()
        {
            if (getDophangiai()>=1200)
            {
                return 1;
            }
            return 0;
            
        }
};
int main()
{
    vector<MayinKim>kim;
    vector<MayinLaser>laser;
    int dem=0;
    int check;
    Mayin *ptr;
    while (dem<=10)
    {
        cout<<"Ban muan nhap may in kim hay may in laser(1: May in kim,2:May in laser,0:Exit)"<<endl;
        cin>>check;
        if (check==1)
        {
            MayinKim kimtmp;
            ptr=&kimtmp;
            ptr->input();
            kim.push_back(kimtmp);
            dem++;
        }
        else if (check==2)
        {
            MayinLaser lasertmp;
            ptr=&lasertmp;
            ptr->input();
            laser.push_back(lasertmp);
            dem++;
        }
        else
            break;
        
        
    }

    cout<<"Danh sach May in:"<<endl;
    cout<<"May in kim:"<<endl;
    for (int i = 0; i < kim.size(); i++)
    {
        kim[i].output();
        cout<<"--------"<<endl;
    }
    cout<<"May in Laser"<<endl;
    for (int i = 0; i < laser.size(); i++)
    {
        laser[i].output();
        cout<<"--------"<<endl;
    }
    cout<<"May in chat luong cao:"<<endl;
    for (int i = 0; i < kim.size(); i++)
    {
        if (kim[i].chatLuongCao())
        {
            cout<<"So luong kim: "<<kim[i].getSokim()<<endl;
        }
        
    }
    for (int i = 0; i < laser.size(); i++)
    {
        if (laser[i].chatLuongCao())
        {
            cout<<"Do phan giai la: "<<laser[i].getDophangiai()<<endl;
        }
        
    }
    
    
    
}