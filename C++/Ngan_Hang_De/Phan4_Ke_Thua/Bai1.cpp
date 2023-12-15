#include<iostream>
#include<string>

using namespace std;

class Color
{
    private:
        string name_color;
    public:
        Color()
        {
            name_color="Chua co mau";
        }
        Color(string name_color)
        {
            this->name_color=name_color;
        }
        ~Color()
        {
            cout<<"Da huy mau "<<name_color<<endl;
        }

        
        string getNameColor()
        {
            return name_color;
        }
        friend istream& operator>>(istream& is,Color& c);
        friend ostream& operator<<(ostream& os,Color& c);
        
};
istream& operator>>(istream& is,Color& c)
        {
            cout<<"Nhap mau: ";
            cin.ignore();
            getline(is,c.name_color);
            return is;
        }
ostream& operator<<(ostream& os,Color& c)
        {
            os<<"Mau: "<<c.name_color<<endl;
            return os;
        }

class Point
{
    private:
        int x,y;
    public:
        Point()
        {
            x=0;
            y=0;
        }
        Point(int x,int y)
        {
            this->x=x;
            this->y=y;
        }
        ~Point()
        {
            cout<<"Da huy toa do ("<<x<<","<<y<<")"<<endl;
        }

        
        int getX()
        {
            return x;
        }
        int getY()
        {
            return y;
        }
        bool CheoChinh()
        {
            if(x==y)
                return true;
            else
                return false;
        }
        friend istream& operator>>(istream& is,Point& p);
        friend ostream& operator<<(ostream& os,Point& p);
};
istream& operator>>(istream& is,Point& p)
        {
            cout<<"Nhap toa do: ";
            is>>p.x>>p.y;
            return is;
        }
ostream& operator<<(ostream& os,Point& p)
        {
            os<<"Toa do: ("<<p.x<<","<<p.y<<")"<<endl;
            return os;
        }

class Pixel:public Point, Color
{
    public:
        Pixel():Point(),Color()
        {

        }
        Pixel(int x,int y,string name_color):Point(x,y),Color(name_color)
        {

        }
        // ~Pixel()
        // {
        //     cout<<"Da huy Pixel"<<endl;
        // }

        
        bool mau_xanh()
        {
            if(getNameColor()=="xanh")
                return true;
            else
                return false;
        }

        bool KiemTra()
        {
            if(CheoChinh()==true && mau_xanh()==true)
                return true;
            else
                return false;
        }

        friend istream& operator>>(istream& is,Pixel& p);
        friend ostream& operator<<(ostream& os,Pixel& p);
};

istream& operator>>(istream& is,Pixel& p)
{
    is>>(Color&)p;
    is>>(Point&)p;
    return is;
}
ostream& operator<<(ostream& os,Pixel& p)
{
    os<<(Point&)p;
    os<<(Color&)p;
    return os;
}

int main()
{
    int n;
    cout<<"Nhap so luong Pixel: ";
    cin>>n;
    
    Pixel a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap Pixel thu "<<i+1<<endl;
        cin>>a[i];
    }
    cout<<"Cac Pixel co mau xanh va nam tren duong cheo chinh: "<<endl;
    for(int i=0;i<n;i++)
    {
        if(a[i].KiemTra()==true)
            cout<<a[i];
    }
}