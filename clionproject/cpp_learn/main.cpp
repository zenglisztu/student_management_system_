#include <iostream>

using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Ĭ�Ϲ��캯���ĵ���" << endl;
    }
    Person(int age, int height)
    {
        cout << "�вι��캯���ĵ���" << endl;
        this->age = age;
        this->height = new int(height);
    }
    Person(const Person& p)
    {
        this->age = p.age;
        this->height = new int(*(p.height));
    }
    ~Person()
    {
        if (this->height != nullptr)
        {
            delete height;
            height = nullptr;
        }

        cout << "������������" << endl;
    }

    int *height;
    int age;
};

void Test01()
{
    Person p1(18, 165);
    cout << "p1 age is " << p1.age << endl;
    cout << "p1 height is " << *(p1.height) << endl;

    Person p2(p1);
    cout << "p2 age is " << p2.age << endl;
    cout << "p2 height is " << *(p2.height) << endl;
}

int main()
{
    Test01();

    system("pause");
    return 0;
}
