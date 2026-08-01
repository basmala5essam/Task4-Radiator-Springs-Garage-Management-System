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
        float s =getSpeed();
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
        float s =getSpeed();
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
    getline(cin,fullName);
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

    // calculate Perfomance Score
    cout << "Car Checked In Successfully!" << endl;
}

int main()
{
    int choice;
    cout << "================Garage Management System================" << endl;
    cout << "1.Check In a Car" << endl
         << "2.View the Garage" << endl
         << "3.Tune-Up (Update a car)" << endl;
    cout << "4. Retire" << endl
         << "5.Find a Car" << endl
         << "6.Garage Report" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        Car *c=nullptr;
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
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    default:
        break;
    }
}