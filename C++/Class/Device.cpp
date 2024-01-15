#include<iostream>
#include<string>

using namespace std;

struct Date{
	int day,month,year;
};

class Device{
	private:
		int id;
		string name,nhaCheTao;
		Date dateCheTao;
	public:
		Device()
		{
			id=0;
			name="";
			nhaCheTao="";
			dateCheTao.day=0;
			dateCheTao.month=0;
			dateCheTao.year=0;
		}
		Device(int id,string name,string nhaCheTao,Date date)
		{
			this->id=id;
			this->name=name;
			this->nhaCheTao=nhaCheTao;
			this->dateCheTao=date;
		}
		void setId(int id)
		{
			this->id=id;
		}
		int getId()
		{
			return id;
		}
		void setName(string name)
		{
			this->name=name;
		}
		string getName()
		{
			return name;
		}
		void setNhaCheTao(string nhaCheTao)
		{
			this->nhaCheTao=nhaCheTao;
		}
		string getNhaCheTao()
		{
			return nhaCheTao;
		}
		void setDateCheTao(Date date)
		{
			this->dateCheTao=date;
		}
		Date getDateCheTao()
		{
			return dateCheTao;
		}
		friend istream& operator>>(istream &is,Device &a)
		{
			cout<<"Nhap id: ";
			is>>a.id;
			is.ignore();
			cout<<"Nhap ten: ";
			getline(is,a.name);
			cout<<"Nhap nha che tao: ";
			getline(is,a.nhaCheTao);
			cout<<"Nhap ngay thang nam: ";
			is>>a.dateCheTao.day>>a.dateCheTao.month>>a.dateCheTao.year;
			is.ignore();

			return is;
		}
		friend ostream& operator<<(ostream &os,Device &a)
		{
			os<<"Id: "<<a.id<<endl;
			os<<"Ten: "<<a.name<<endl;
			os<<"Nha che tao: "<<a.nhaCheTao<<endl;
			os<<"Ngay thang nam: "<<a.dateCheTao.day<<"/"<<a.dateCheTao.month<<"/"<<a.dateCheTao.year<<endl;

			return os;
		}
		virtual bool HetHanSD()=0;
};

class Computer : public Device
{
	private:
		string cpu,ram;
	public:
		Computer()
		{
			cpu="";
			ram="";
		}
		Computer(string ram,string cpu,int id,string name,string nhaCheTao,Date date)
		:Device(id,name,nhaCheTao,date)
		{
			this->cpu=cpu;
			this->ram=ram;
			this->setDateCheTao(date);
			this->setId(id);
			this->setName(name);
			this->setNhaCheTao(nhaCheTao);
		}
		void setCpu(string)
		{
			this->cpu =cpu;
		}
		string getCpu()
		{
			return cpu;
		}
		void setRam(string ram)
		{
			this->ram=ram;
		}
		string getRam()
		{
			return ram;
		}
		friend istream& operator>>(istream &is,Computer &a)
		{
			is>>(Device&)a;
			cout<<"Nhap cpu: ";
			is>>a.cpu;
			cout<<"Nhap ram: ";
			is>>a.ram;
			return is;
		}
		friend ostream& operator<<(ostream &os,Computer &a)
		{
			os<<(Device&)a;
			os<<"Cpu: "<<a.cpu<<endl;
			os<<"Ram: "<<a.ram<<endl;
			return os;
		}

		bool HetHanSD()
		{
			if (ram=="8GB")
			{
				return true;
			}
			return false;
			
		}

};

class Monitor : public Device
{
	private:
		string size;
	public:
		Monitor()
		{
			size="";
		}
		Monitor(string size,int id,string name,string nhaCheTao,Date date)
		:Device(id,name,nhaCheTao,date)
		{
			this->size=size;
			this->setDateCheTao(date);
			this->setId(id);
			this->setName(name);
			this->setNhaCheTao(nhaCheTao);
		}
		void setSize(string size)
		{
			this->size=size;
		}
		string getSize()
		{
			return size;
		}
		friend istream& operator>>(istream &is,Monitor &a)
		{
			is>>(Device&)a;
			cout<<"Nhap size: ";
			is>>a.size;
			return is;
		}
		friend ostream& operator<<(ostream &os,Monitor &a)
		{
			os<<(Device&)a;
			os<<"Size: "<<a.size<<endl;
			return os;
		}

		bool HetHanSD()
		{
			if (size=="32inch")
			{
				return true;
			}
			return false;
			
		}
};
int main() {
    int n, m;
    cout << "Nhap so luong may tinh: ";
    cin >> n;
    cin.ignore();

    cout << "Nhap so luong Monitor: ";
    cin >> m;
    cin.ignore();

    // Tạo mảng list có đủ chỗ để lưu các con trỏ
    Device **list = new Device*[n + m];

    for (int i = 0; i < n; i++) {
        list[i] = new Computer;
        cout << "Nhap thong tin may tinh thu " << i + 1 << ":" << endl;
        Computer *n =dynamic_cast<Computer*>(list[i]);
		cin>>*n;  
    }

    for (int i = n; i < n + m; i++) {
        list[i] = new Monitor;
        cout << "Nhap thong tin Monitor thu " << i - n + 1 << ":" << endl;
        cin >> *dynamic_cast<Monitor*>(list[i]);
    }

    cout << "Danh sach may tinh la: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "May tinh thu " << i + 1 << ":" << endl;
        cout << (*list[i]);
    }

    cout << "Danh sach Monitor: " << endl;
    for (int i = n; i < n + m; i++) {
        cout << "Monitor thu " << i - n + 1 << ":" << endl;
        cout << (*list[i]);
    }

    cout<<"Danh sach May tinh het han su dung:"<<endl;
	for (int i = 0; i < n; i++)
	{
		if ((*list[i]).HetHanSD())
		{
			cout<<(*list[i]);
		}
		
	}
	cout<<"Danh sach Monitor het han la: "<<endl;
	for (int i = n; i < n+m; i++)
	{
		if ((*list[i]).HetHanSD())
		{
			cout<<(*list[i]);
		}
		
	}
    return 0;
}
