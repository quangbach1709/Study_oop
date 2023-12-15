#include<iostream>

using namespace std;

class Vector
{
    private:
        float *v;
        int n;

    public:
        Vector()
        {
            n = 0;
            v = new float[n];
            //nhap cac toa do cua vector
            
            cin>>v[0];
        }
        Vector(int n)
        {
            this->n = n;
            v = new float[n];
            //nhap cac toa do cua vector
            cout<<"Nhap cac toa do cua vector: ";
            for(int i = 0; i < n; i++)
            {
                cin>>v[i];
            }
        }
        // ham constructor 2 tham so n va cac toa do cua vector
        Vector(int n, float v[])
        {
            this->n = n;
            this->v = new float[n];
            for(int i = 0; i < n; i++)
            {
                this->v[i] = v[i];
            }
        }
        
};