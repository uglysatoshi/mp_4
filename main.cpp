#include <iostream>
#include <string>

using namespace std;

class Venicle
{
    public:
        double AvgSpeed, AvgGas;
        string ModelName;
        int PassengerNumber;
        Venicle()
        {
        };

        void Read()
        {
            cout << "Введите среднюю скорость средства(км/ч): "; cin >> AvgSpeed;
            cout << "Введите название модели средства: "; cin >> ModelName;
            cout << "Введите максимальное количество пассажиров средства: "; cin >> PassengerNumber;
            cout << "Введите средний показатель потребления бензина(л/км): "; cin >> AvgGas; 
        }

        void Print()
        {
            cout << "Средняя скорость(км/ч): " << AvgSpeed << endl;
            cout << "Название модели: " << ModelName << endl;
            cout << "Максимальное количество пассажиров: " << PassengerNumber << endl;
            cout << "Средний показатель потребления бензина: " << AvgGas << endl;
        }

        void GasConsumption()
        {
            double distance;
            cout << "Введите расстояние для проверки: "; cin >> distance;

            cout << "Потребуется " << distance / GetGas() << " литров бензина для прохождения пути" << endl;
            cout << "<<-------------->>  " << endl;
        }

        void SpeedTime()
        {
            double distance;
            cout << "Введите расстояние для проверки: "; cin >> distance;

            cout << "Потребуется " << distance / GetSpeed() << " часов для прохождения пути" << endl;
            cout << "<<-------------->>  " << endl;
        }

        double GetSpeed()
        {
            return AvgSpeed;
        }

        double GetGas()
        {
            return AvgGas;
        }

        Venicle(const Venicle &v)
        {
            cout << "Конструктор копирования отработал для переменной " << this << endl;
        }

        ~Venicle()
        {
            cout << "Деструктор сработал для переменной " << this << endl;
        }
};

class Bike : public Venicle
{
    public:
        Bike()
        {

        };
};

class Car : public Venicle
{
    public:
        Car()
        {

        };
};

class Bus : public Venicle
{
    public:
        Bus()
        {

        };
    
};

void SwitchInsructions()
{
    cout << "1 - Ввести данные средств передвижения" << endl;
    cout << "2 - Вывести данные средств передвижения" << endl;
    cout << "3 - Узнать расход бензина и скорость прохождения на участке" << endl;
    cout << "0 - Выход" << endl;
    cout << "<<-------------->>  " << endl;
}

int main()
{
    int choice;
    Bike bike;
    Car car; 
    Bus bus; 
    Bike CBike = bike;
    Car CCar = car;
    Bus CBus = bus;
    SwitchInsructions();
    do 
    {  
        cin >> choice;
        switch(choice) 
        {
            case 1:
                cout << "Введите данные для велосипеда: " << endl;
                CBike.Read();
                cout << "<<-------------->>  " << endl;
                cout << "Введите данные для автомобиля: " << endl;
                CCar.Read();
                cout << "<<-------------->>  " << endl;
                cout << "Введите данные автобуса: " << endl;
                CBus.Read();
                cout << "<<-------------->>  " << endl;
                break;
            case 2:
                cout << "Данные велосипеда: " << endl;
                CBike.Print();
                cout << "<<-------------->>  " << endl;
                cout << "Данные автомобиля: " << endl;
                CCar.Print();
                cout << "Данные автобуса: " << endl;
                CBus.Print();
                break;
            case 3:
                CBike.GasConsumption();
                CBike.SpeedTime();
                CCar.GasConsumption();
                CCar.SpeedTime();
                CBus.GasConsumption();
                CBus.SpeedTime();
                break;
        }
    }
    while(choice != 0);
    return 0;
}