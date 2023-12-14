#include<iostream>

using namespace std;

class Circle
{
    private:
        float r;
    public:

        Circle(){
            r=0;
        }
        void input()
        {
            cout<<"Nhap ban kinh r: ";
            cin>>r;
            while (r<=0)
            {
                cout<<"Ban kinh k phu hop hay nhap lai."<<endl;
                cout<<"r = ";
                cin>>r;
            }
            
        }
        float getban_kinh()
        {
            return r;
        }

        float dien_tich()
        {
            return 3.14*r*r;
        }

        friend float chu_vi(Circle &tmp);
};

float chu_vi(Circle &tmp)
{
    return 2*3.14*tmp.getban_kinh();
}

int main()
{
    Circle tmp;
    tmp.input();
    cout<<"Chu vi hinh tron la: "<<chu_vi(tmp)<<endl;
    cout<<"Dien tich hinh tron la: "<<tmp.dien_tich()<<endl;
    
    return 0;
}