#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void speak() = 0;
};

class Cat:public Animal
{
public:
    void speak()
    {
        cout << "cat is speaking!" << endl;
    }
};

class Dog:public Animal
{
public:
    void speak()
    {
        cout << "dog is speaking!" << endl;
    }
};

void Test01();
void Speak(Animal& animal);
int main(int argc, char *argv[])
{
    Test01();

    system("pause");
    return 0;
}

void Speak(Animal& animal)
{
    animal.speak();
}

void Test01()
{
    Cat cat;
    Dog dog;
    Speak(cat);
    Speak(dog);
}