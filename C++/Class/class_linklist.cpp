#include<iostream>
#include<string>

using namespace std;
//su dung linklist de cap nhat danh sach sinh vien
struct Node
{
    int msv;
    string name;
    string lop;
    Node *next;
};
struct List
{
    Node *hand;
};

class Sv
{
    private:
        Node sinhvien;
    public:
        void input()
        {
            cout << "Nhap msv: ";
            cin >> sinhvien.msv;
            cin.ignore(); // xoa dau enter
            cout << "Nhap Hoten: ";
            getline(cin, sinhvien.name);
            cout << "Nhap lop: ";
            getline(cin, sinhvien.lop);
        }
        void output()
        {
            cout << sinhvien.msv << "\t" << sinhvien.name << "\t" << sinhvien.lop << endl;
        }
              

};

void addNewSv(List &list)
{
    Node *newNode = new Node;
    Sv tmpnew;
    cout << "Nhap vao sinh vien thu " << endl;
    tmpnew.input();
    newNode->msv = tmpnew.msv;
    newNode->name = tmpnew.name;
    newNode->lop = tmpnew.lop;
    newNode->next = NULL;
    if(list.hand == NULL)
    {
        list.hand = newNode;
    }
    else
    {
        Node *tmp = list.hand;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    cout << "Da them sinh vien thanh cong" << endl;
}

void output(List &list)
{
    Node *tmp = list.hand;
    while(tmp != NULL)
    {
        cout << tmp->msv << "\t" << tmp->name << "\t" << tmp->lop << endl;
        tmp = tmp->next;
    }
}

int main()
{
    List list;
    list.hand = NULL;
    string continues;
    while (true)
    {
        cout<<"Nhap thong tin sinh vien: "<<endl;
        addNewSv(list);
        cout << "Ban co muon continue input (n or stop de dung)" << endl;
        getline(cin, continues);
        if (continues == "n" || continues == "stop")
        {
            break;
        }

    
    }
    cout << "Danh sach sinh vien: " << endl;
    output(list);
    return 0;
}



