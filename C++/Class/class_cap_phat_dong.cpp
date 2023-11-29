#include <iostream>
#include <string>

using namespace std;

class Sv
{
private:
    int msv;
    string name;
    string lop;

public:
    void input()
    {
        cout << "Nhap msv: ";
        cin >> msv;
        cin.ignore(); // xoa dau enter
        cout << "Nhap Hoten: ";
        getline(cin, name);
        cout << "Nhap lop: ";
        getline(cin, lop);
    }
    void output()
    {
        cout << msv << "\t" << name << "\t" << lop << endl;
    }

    friend void AddNewSv(int &count, Sv *&newsv);
};

void AddNewSv(int &count, Sv *&newsv)
{
    Sv tmpnew;
    cout << "Nhap vao sinh vien thu " << count + 1 << endl;
    tmpnew.input();

    int newcount = count + 1;
    Sv *tmpsv = new Sv[newcount];

    for (int i = 0; i < count; i++)
    {
        tmpsv[i] = newsv[i];
    }
    tmpsv[count] = tmpnew;

    delete[] newsv;
    newsv = tmpsv;
    count = newcount;

    cout << "Da them sinh vien thanh cong" << endl;
}

int main()
{
    Sv *newsv = nullptr;
    string continues;
    int count = 0;

    while (true)
    {
        cout << "Ban co muon continue input (n or stop de dung)" << endl;
        getline(cin, continues);
        if (continues == "n" || continues == "stop")
        {
            break;
        }
        else
        {
            if (count == 0)
            {
                newsv = new Sv[1];
            }
            else
            {
                Sv *tmp = new Sv[count + 1];
                for (int i = 0; i < count; ++i)
                {
                    tmp[i] = newsv[i];
                }
                delete[] newsv;
                newsv = tmp;
            }

            AddNewSv(count, newsv);
        }
    }

    cout << "Danh sach sinh vien" << endl;
    for (int i = 0; i < count; i++)
    {
        newsv[i].output();
    }

    delete[] newsv;
    return 0;
}
