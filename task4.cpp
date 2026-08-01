#include <iostream>
using namespace std;

class Car
{
protected:
    int car_number, age;
    string fullname, racing_team;
    float speed, capacity;
public:
void checkIn(Car arr[]){
    cout << "Enter car number (Note: must be unique)" << endl;
    cin >> car_number;
    //validate var number
    cout << "Enter car fullname" << endl;
    cin >> fullname;
    cout << "Enter age (must be positive)" << endl;
    do{
        cin >> age;
        cout << "Invalid age" << endl;

    }while(age<0);
    cout << "Enter racing team" << endl;
    cin >> racing_team;
    cout << "Enter speed (must be positive)" << endl;
    do{
        cin >> speed;
        cout << "Invalid speed" << endl;

    }while(speed<0);
    cout << "Enter capacity (must be positive)" << endl;
    do{
        cin >> capacity;
        cout << "Invalid capacity" << endl;

    }while(capacity<0);




}
virtual float calculatePerformance(){

}

};

class Racer : public Car
{
protected:
    int races, laps;
};

class SupportVehicle: public Car
{
protected:
    int crew_size, reliability_rating;
};



int main(){
    int choice;
    cout << "================Garage Management System================" << endl;
    cout << "1.Check In a Car" << endl << "View the Garage" << endl << "3.Tune-Up (Update a car)" << endl;
    cout << "4. Retire" << endl << "5.Find a Car" << endl << "6.Garage Report" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        /* code */
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