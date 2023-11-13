#include<iostream>

using namespace std;

class square
{
    private:
        float side_length;

    public://chuy xuat den du lieu trong private
    //setter
        void set_side_lenght(float _side_lenht)
        {
            side_length = _side_lenht;
        }

    //getter
    float get_side_length()
    {
        return side_length;
    }
};

int main()
{
    square s1;
    s1.set_side_lenght(1.3);
    cout<<"side length: "<<s1.get_side_length();
    return 0;
}