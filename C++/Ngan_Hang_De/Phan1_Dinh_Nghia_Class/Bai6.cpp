#include<iostream>
#include<string>

using namespace std;

class ThiSinh
{
    private:
        int sbd;
        float diemToan, diemLy, diemHoa;
    public:
    void input()
    {
        cout<<"Nhap so bao danh: ";
        cin>>sbd;
        cout<<"Nhap diem toan: ";
        cin>>diemToan;
        cout<<"Nhap diem ly: ";
        cin>>diemLy;
        cout<<"Nhap diem hoa: ";
        cin>>diemHoa;
    }
    void output()
    {
        cout<<"So bao danh: "<<sbd<<endl;
        cout<<"Diem toan: "<<diemToan<<endl;
        cout<<"Diem ly: "<<diemLy<<endl;
        cout<<"Diem hoa: "<<diemHoa<<endl;
    }
};

class ListThiSinh
{
    private:
        ThiSinh TS[100];
        
    public:
        ListThiSinh(int n)
        {
            for(int i = 0; i < n; i++)
            {
                cout<<"Nhap thong tin thi sinh thu "<<i+1<<endl;
                TS[i].input();
            }
        }
        void output(int n)
        {
            for(int i = 0; i < n; i++)
            {
                cout<<"Thong tin thi sinh thu "<<i+1<<endl;
                TS[i].output();
            }
        }
        float tongDiem(ThiSinh ts)
        {
            return ts.diemToan + ts.diemLy + ts.diemHoa;
        }
        void sapXep()
        {
            for(int i = 0; i < n-1; i++)
            {
                for(int j = i+1; j < n; j++)
                {
                    if(tongDiem(TS[i]) < tongDiem(TS[j])
                    {
                        ThiSinh temp = TS[i];
                        TS[i] = TS[j];
                        TS[j] = temp;
                    }
                }
            }
        }
};

