#include<iostream>
#include<math.h>

using namespace std;

class Point
{
    private:
        float x1,y1,x2,y2;

    public:
        Point()
        {
            x1=0;y1=0;x2=0;y2=0;
        }
        void input()
        {
            cout<<"Nhap toa do diem 1:";
            cin>>x1>>y1;
            cout<<"Nhap toa do diem 2:";
            cin>>x2>>y2;
        }

        float khoang_cach()
        {
            return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        }

        void output()
        {
            cout<<"Toa do diem 1: ("<<x1<<","<<y1<<")"<<endl;
            cout<<"Toa do diem 2: ("<<x2<<","<<y2<<")"<<endl;
            cout<<"Khoang cach giua 2 diem la: "<<khoang_cach()<<endl;
        }
        friend void max(Point tmp[],int n);
};

void max(Point tmp[],int n)
{
    float max=tmp[0].khoang_cach();
    
    for (int i=1;i<n;i++)
    {
        if (tmp[i].khoang_cach()>max)
        {
            max=tmp[i].khoang_cach();
            
        }
    }
    cout<<"Diem co khoang cach lon nhat la: "<<endl;
    cout<<max<<endl;
}

int main()
{
    int n;
    cout<<"Nhap so luong diem: ";
    cin>>n;
    Point tmp[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Nhap diem thu "<<i+1<<endl;
        tmp[i].input();
    }
    max(tmp,n);
    return 0;
}