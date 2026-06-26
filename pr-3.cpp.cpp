#include <iostream>
#include <string>

using namespace std;


class Vehicle {
protected:
    string vehicleID, manufacturer, model;
    int year;
public:
    static int totalVehicles;
    Vehicle(string id, string man, string mod, int yr) 
        : vehicleID(id), manufacturer(man), model(mod), year(yr) { totalVehicles++; }
    virtual ~Vehicle() { totalVehicles--; }
    virtual void display() const {
        cout << "[" << vehicleID << "] " << manufacturer << " " << model << " (" << year << ")";
    }
    string getID() const { return vehicleID; }
};
int Vehicle::totalVehicles = 0;


class Car : public Vehicle {
public:
    string fuelType;
    Car(string id, string man, string mod, int yr, string ft) : Vehicle(id, man, mod, yr), fuelType(ft) {}
    void display() const override { Vehicle::display(); cout << " [Car, Fuel: " << fuelType << "]" << endl; }
};

class ElectricCar : public Car {
public:
    int batteryCapacity;
    ElectricCar(string id, string man, string mod, int yr, string ft, int batt) : Car(id, man, mod, yr, ft), batteryCapacity(batt) {}
    void display() const override { Vehicle::display(); cout << " [ElectricCar, Batt: " << batteryCapacity << "kWh]" << endl; }
};

class Aircraft {
protected:
    int flightRange;
public:
    Aircraft(int range) : flightRange(range) {}
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(string id, string man, string mod, int yr, string ft, int range) : Car(id, man, mod, yr, ft), Aircraft(range) {}
    void display() const override { Vehicle::display(); cout << " [FlyingCar, Range: " << flightRange << "km]" << endl; }
};

class Sportscar : public ElectricCar { 
public:
    int topSpeed;
    Sportscar(string id, string man, string mod, int yr, string ft, int batt, int ts) : ElectricCar(id, man, mod, yr, ft, batt), topSpeed(ts) {}
    void display() const override { Vehicle::display(); cout << " [Sportscar, Top Speed: " << topSpeed << "km/h]" << endl; }
};

class Sedan : public Car {
public:
    Sedan(string id, string man, string mod, int yr, string ft) : Car(id, man, mod, yr, ft) {}
    void display() const override { Vehicle::display(); cout << " [Sedan]" << endl; }
};

class SUV : public Car {
public:
    SUV(string id, string man, string mod, int yr, string ft) : Car(id, man, mod, yr, ft) {}
    void display() const override { Vehicle::display(); cout << " [SUV]" << endl; }
};


class VehicleRegistry {
private:
    static const int MAX = 10; 
    Vehicle* registry[MAX];
    int count;

public:
    VehicleRegistry() : count(0) {}

    void addVehicle() {
        if (count >= MAX) { cout << "Registry Full!\n"; return; }
        string id, m, mod, ft;
	    int yr, type;
        cout << "Enter ID:";cin >> id;
		cout<<"Manuf:";cin >> m;
		cout<<"Model:";cin >> mod;
		cout<<"Year:";cin >> yr;
		cout<<"Fuel:";cin >> ft;
        cout << "Type (1:Car, 2:Electric, 3:Flying, 4:Sport, 5:Sedan, 6:SUV): ";
        cin >> type;

        if (type == 1) registry[count] = new Car(id, m, mod, yr, ft);
        else if (type == 2) registry[count] = new ElectricCar(id, m, mod, yr, ft, 80);
        else if (type == 3) registry[count] = new FlyingCar(id, m, mod, yr, ft, 500);
        else if (type == 4) registry[count] = new Sportscar(id, m, mod, yr, ft, 100, 300);
        else if (type == 5) registry[count] = new Sedan(id, m, mod, yr, ft);
        else registry[count] = new SUV(id, m, mod, yr, ft);
        
        count++;
    }

    void displayAll() {
        for (int i = 0; i < count; i++) registry[i]->display();
    }

    void searchById(string id) {
        for (int i = 0; i < count; i++) {
            if (registry[i]->getID() == id) { registry[i]->display(); return; }
        }
        cout << "Not found.\n";
    }

    ~VehicleRegistry() { for (int i = 0; i < count; i++) delete registry[i]; }
};

int main() {
    VehicleRegistry sys;
    int choice;
    while (true) {
        cout << "\n1.Add \n2.Display \n3.Search \n4.Exit "<<endl;
		cout<<"enter choice:"; cin >> choice;
        if (choice == 1) sys.addVehicle();
        else if (choice == 2) sys.displayAll();
        else if (choice == 3) { string id; cout << "ID: "; cin >> id; sys.searchById(id); }
        else break;
    }

}
/*
1.Add
2.Display
3.Search
4.Exit
enter choice:1
Enter ID:101
Manuf:tata
 Model:maruti
Year:2002
 Fuel:diseal
Type (1:Car, 2:Electric, 3:Flying, 4:Sport, 5:Sedan, 6:SUV): 2

1.Add
2.Display
3.Search
4.Exit
enter choice:2
[101] tata maruti (2002) [ElectricCar, Batt: 80kWh]

1.Add
2.Display
3.Search
4.Exit
enter choice:3
ID: 101
[101] tata maruti (2002) [ElectricCar, Batt: 80kWh]

1.Add
2.Display
3.Search
4.Exit
enter choice:4
*/