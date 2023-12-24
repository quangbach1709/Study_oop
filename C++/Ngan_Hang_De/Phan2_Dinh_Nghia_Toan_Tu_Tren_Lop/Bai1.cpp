#include<iostream>
#include<math.h>

using namespace std;

class Point
{
    private:
        float x,y;
    public:
        Point(){};
        ~Point()
        {
            cout<<"Da huy Point."<<endl;
        }
        friend istream& operator>>(istream& is,Point &tmp)
        {
            cout<<"Nhap x: ";is>>tmp.x;
            cout<<"Nhap y: ";is>>tmp.y;
            return is;
            
        }
        friend ostream& operator<<(ostream& os, Point &tmp)
        {
            os<<"x= "<<tmp.x<<endl;
            os<<"y= "<<tmp.y<<endl;
            return os;
        }  
        float khoangCach(Point &a,Point &b)
        {
            return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2));
        }    
};
class DaGiac
{
    private:
        Point a[100];
        
};