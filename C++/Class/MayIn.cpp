#include<iostream>
#include<string>

using namespace std;

class Mayin
{
    private:
        int ma;
        string hang;
    public:
        Mayin()
        {
            ma=0;
            hang="";
        }
        Mayin(int ma,string hang)
        {
            this->ma=ma;
            this->hang=hang;
        }
        void setMa(int ma)
        {
            this->ma=ma;
        }
        int getMa()
        {
            return ma;
        }
        void setHang(string hang)
        {
            this->hang=hang;
        }
        string getHang()
        {
            return hang;
        }
        virtual void input()
        {
            cout<<"Nhap ma: ";
            cin>>ma;
            cin.ignore();
            cout<<"Nhap hang: ";
            getline(cin,hang);
        }
        virtual void output()
        {
            cout<<"Ma: "<<ma<<endl;
            cout<<"Hang: "<<hang<<endl;
        }
        friend istream& operator>>(istream& is,Mayin& mayin)
        {
            mayin.input();
            return is;
        }
        friend ostream& operator<<(ostream& os,Mayin& mayin)
        {
            mayin.output();
            return os;
        }
        virtual bool Chatluongcao()=0;
};

class Mayinkim :public Mayin
{
    private:
        int sokim;
    public:
        Mayinkim()
        {
            sokim=0;
        }
        Mayinkim(int ma,string hang,int sokim):Mayin(ma,hang)
        
        {
            this->sokim=sokim;
        }
        void setSokim(int sokim)
        {
            this->sokim=sokim;
        }
        int getSokim()
        {
            return sokim;
        }
        void input()
        {
            Mayin::input();
            cout<<"Nhap so kim: ";
            cin>>sokim;
        }
        void output()
        {
            Mayin::output();
            cout<<"So kim: "<<sokim<<endl;
        }
        friend istream& operator>>(istream& is,Mayinkim& mayinkim)
        {
            mayinkim.input();
            return is;
        }
        friend ostream& operator<<(ostream& os,Mayinkim& mayinkim)
        {
            mayinkim.output();
            return os;
        }
        bool Chatluongcao()
        {
            if(sokim>=24)
                return true;
            return false;
        }
};
class Mayinlaser :public Mayin
{
    private:
        int dophangiai;
    public:
        Mayinlaser()
        {
            dophangiai=0;
        }
        Mayinlaser(int ma,string hang,int dophangiai):Mayin(ma,hang)
        {
            this->dophangiai=dophangiai;
        }
        void setDophangiai(int dophangiai)
        {
            this->dophangiai=dophangiai;
        }
        int getDophangiai()
        {
            return dophangiai;
        }
        void input()
        {
            Mayin::input();
            cout<<"Nhap do phan giai: ";
            cin>>dophangiai;
        }
        void output()
        {
            Mayin::output();
            cout<<"Do phan giai: "<<dophangiai<<"dpi"<<endl;
        }
        friend istream& operator>>(istream& is,Mayinlaser& mayinlaser)
        {
            mayinlaser.input();
            return is;
        }
        friend ostream& operator<<(ostream& os,Mayinlaser& mayinlaser)
        {
            mayinlaser.output();
            return os;
        }
        bool Chatluongcao()
        {
            if(dophangiai>=1200)
                return true;
            return false;
        }
};
int main()
{
    int dem=0;
    int tmp;
    Mayin **list=new Mayin*[10];
    while (dem<10)
    {
        cout<<"Nhap may in(1:may in kim 2:may in laser 0: thoat): ";
        cin>>tmp;
        cin.ignore();
        if(tmp==1)
        {
            list[dem]=new Mayinkim();
            cin>>(*list[dem]);
            dem++;
        }
        else if(tmp==2)
        {
            list[dem]=new Mayinlaser();
            cin>>(*list[dem]);
            dem++;
        }
        else
        {
            break;
        }
    }
    cout<<"Danh sach may in: "<<endl;
    for(int i=0;i<dem;i++)
    {
        cout<<"May in thu "<<i+1<<": "<<endl;
        cout<<(*list[i]);
    }
    
}