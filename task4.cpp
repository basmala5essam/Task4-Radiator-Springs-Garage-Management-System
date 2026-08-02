#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    int car_number, age;
    string fullname, racing_team;
    float speed, capacity;

public:
    void setCarNumber(int carNumber)
    {
        car_number = carNumber;
    }
    void setAge(int age)
    {
        if (age > 0)
        {
            this->age = age;
        }
        else
        {
            cout << "Invalid age" << endl;
            return;
        }
    }
    void setFullName(string fullName)
    {
        fullname = fullName;
    }

    void setRacingTeam(string RacingTeam)
    {
        racing_team = RacingTeam;
    }

    void setSpeed(float speed)
    {
        if (speed > 0)
        {
            this->speed = speed;
        }
        else
        {
            cout << "Invalid speed" << endl;
            return;
        }
    }

    void setCapacity(float capacity)
    {
        if (capacity > 0)
        {
            this->capacity = capacity;
        }
        else
        {
            cout << "Invalid capacity" << endl;
            return;
        }
    }

    int getCarNumber()
    {
        return car_number;
    }
    int getAge()
    {
        return age;
    }
    string getFullName()
    {
        return fullname;
    }
    string getRacingTeam()
    {
        return racing_team;
    }
    float getSpeed()
    {
        return speed;
    }
    float getCapacity()
    {
        return capacity;
    }

    virtual float calculatePerformance() = 0;
};

class Racer : public Car
{
protected:
    int races, laps;

public:
    float calculatePerformance() override
    {
        float s = getSpeed();
        float c = getCapacity();
        float score = (s * 10) + (c * 1);
        return score;
    }
};

class SupportVehicle : public Car
{
protected:
    int crew_size, reliability_rating;

public:
    float calculatePerformance() override
    {
        float s = getSpeed();
        float c = getCapacity();
        float score = (s * 5) + (c * 5);
        return score;
    }
};

void checkIn(Car *c)
{
    int age, carnumber;
    float speed, capacity;
    string fullName, racingTeam;
    cout << "Enter car number (Note: must be unique)" << endl;
    cin >> carnumber;
    c->setCarNumber(carnumber);
    cin.ignore();
    cout << "Enter car fullname" << endl;
    getline(cin, fullName);
    c->setFullName(fullName);
    cout << "Enter age (must be positive)" << endl;
    cin >> age;
    c->setAge(age);
    cin.ignore();
    cout << "Enter racing team" << endl;
    getline(cin, racingTeam);
    c->setRacingTeam(racingTeam);
    cout << "Enter speed (must be positive)" << endl;
    cin >> speed;
    c->setSpeed(speed);
    cout << "Enter capacity (must be positive)" << endl;
    cin >> capacity;
    c->setCapacity(capacity);

    float score = c->calculatePerformance();
    cout << "Car Checked In Successfully!" << endl;
    cout << "Performance Score: " << score << endl;
}

void displayGarage(Car *garage[], int size)
{
    cout << "================Garage================" << endl;
    for (int i = 0; i < size; i++)
    {
        Car *c = garage[i];
        cout << "Car Number: " << c->getCarNumber() << endl;
        cout << "Full Name: " << c->getFullName() << endl;
        cout << "Age: " << c->getAge() << endl;
        cout << "Racing Team: " << c->getRacingTeam() << endl;
        cout << "Speed: " << c->getSpeed() << endl;
        cout << "Capacity: " << c->getCapacity() << endl;
        cout << "Performance Score: " << c->calculatePerformance() << endl;
        cout << "-------------------------------------" << endl;
    }
}
void editCar(Car *c)
{
    cout << "Which attribute do you want to edit?" << endl;
    cout << "1. Car Number" << endl;
    cout << "2. Full Name" << endl;
    cout << "3. Age" << endl;
    cout << "4. Racing Team" << endl;
    cout << "5. Speed" << endl;
    cout << "6. Capacity" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int carnumber;
        cout << "Enter new car number: ";
        cin >> carnumber;
        c->setCarNumber(carnumber);
        break;
    }

    case 2:
    {
        string fullName;
        cin.ignore();
        cout << "Enter new full name: ";
        getline(cin, fullName);
        c->setFullName(fullName);
        break;
    }

    case 3:
    {
        int age;
        cout << "Enter new age: ";
        cin >> age;
        c->setAge(age);
        break;
    }

    case 4:
    {
        string racingTeam;
        cin.ignore();
        cout << "Enter new racing team: ";
        getline(cin, racingTeam);
        c->setRacingTeam(racingTeam);
        break;
    }

    case 5:
    {
        float speed;
        cout << "Enter new speed: ";
        cin >> speed;
        c->setSpeed(speed);
        break;
    }

    case 6:
    {
        float capacity;
        cout << "Enter new capacity: ";
        cin >> capacity;
        c->setCapacity(capacity);
        break;
    }

    default:
        cout << "Invalid choice" << endl;
    }
}
void tuneUp(Car *garage[], int size)
{
    int carNumber;
    cout << "Enter car number to tune-up: ";
    cin >> carNumber;
    for (int i = 0; i < size; i++)
    {
        Car *c = garage[i];
        if (c->getCarNumber() == carNumber)
        {
            editCar(c);
            cout << "Car Tuned-Up Successfully!" << endl;
            return;
        }
    }
    cout << "Car not found!" << endl;
}
void retire(Car *garage[], int &size)
{
    int carNumber;
    cout << "Enter car number to retire: ";
    cin >> carNumber;
    for (int i = 0; i < size; i++)
    {
        Car *c = garage[i];
        if (c->getCarNumber() == carNumber)
        {
            delete c;
            for (int j = i; j < size - 1; j++)
            {
                garage[j] = garage[j + 1];
            }
            size--;
            cout << "Car Retired Successfully!" << endl;
            return;
        }
    }
    cout << "Car not found!" << endl;
}
void findCar(Car *garage[], int size)
{
    cout << "Want to search cars by name or car number? (1 for name, 2 for car number): ";
    int searchChoice;
    cin >> searchChoice;
    if (searchChoice == 1)
    {
        string fullName;
        cin.ignore();
        cout << "Enter full name to find: ";
        getline(cin, fullName);
        for (int i = 0; i < size; i++)
        {
            Car *c = garage[i];
            if (c->getFullName() == fullName)
            {
                cout << "Car Found!" << endl;
                cout << "Car Number: " << c->getCarNumber() << endl;
                cout << "Full Name: " << c->getFullName() << endl;
                cout << "Age: " << c->getAge() << endl;
                cout << "Racing Team: " << c->getRacingTeam() << endl;
                cout << "Speed: " << c->getSpeed() << endl;
                cout << "Capacity: " << c->getCapacity() << endl;
                cout << "Performance Score: " << c->calculatePerformance() << endl;
                return;
            }
        }
    }
    else if (searchChoice == 2)
    {
        int carNumber;
        cout << "Enter car number to find: ";
        cin >> carNumber;
        for (int i = 0; i < size; i++)
        {
            Car *c = garage[i];
            if (c->getCarNumber() == carNumber)
            {
                cout << "Car Found!" << endl;
                cout << "Car Number: " << c->getCarNumber() << endl;
                cout << "Full Name: " << c->getFullName() << endl;
                cout << "Age: " << c->getAge() << endl;
                cout << "Racing Team: " << c->getRacingTeam() << endl;
                cout << "Speed: " << c->getSpeed() << endl;
                cout << "Capacity: " << c->getCapacity() << endl;
                cout << "Performance Score: " << c->calculatePerformance() << endl;
                return;
            }
        }
        cout << "Car not found!" << endl;
    }
}
void garageReport(Car *garage[],int size)
{
    int averagescore=0;
    cout << "================Garage Report================" << endl;
    cout << "Total Cars in Garage: " << size << endl;
    for (int i = 0; i < size; i++)
    {
        Car *c = garage[i];
        averagescore += c->calculatePerformance();
    }
    averagescore /= size;
    cout << "Average Performance Score: " << averagescore << endl;
}

int main()
{
    int i = 0;
    while (1)
    {
        Car *garage[100];
        int choice;
        cout << "================Garage Management System================" << endl;
        cout << "1.Check In a Car" << endl
             << "2.View the Garage" << endl
             << "3.Tune-Up (Update a car)" << endl;
        cout << "4. Retire" << endl
             << "5.Find a Car" << endl
             << "6.Garage Report" << endl;
        cout << "7.Quit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Car *c = nullptr;
            cout << "Enter the type of car (1 for Racer, 2 for Support Vehicle): ";
            int carType;
            cin >> carType;
            if (carType == 1)
            {
                c = new Racer();
            }
            else if (carType == 2)
            {
                c = new SupportVehicle();
            }
            else
            {
                cout << "Invalid car type" << endl;
                return 0;
            }
            checkIn(c);
            garage[i] = c;
            i++;
            break;
        case 2:
            displayGarage(garage, i);
            break;
        case 3:
            tuneUp(garage, i);
            break;
        case 4:
            retire(garage, i);
            break;
        case 5:
            findCar(garage, i);
            break;
        case 6:
            garageReport(garage, i);
            break;
        case 7:
            cout << "Quiting...Bye!" << endl;
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}