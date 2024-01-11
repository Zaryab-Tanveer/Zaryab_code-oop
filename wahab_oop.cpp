#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string phoneNumber;
    string cnic;

public:
    Person() {}

    void setInfo() {
        cout << "Enter phone number: ";
        getline(cin, phoneNumber);

        cout << "Enter CNIC number: ";
        getline(cin, cnic);
    }
};

class House;

class Owner : public Person {
public:
    vector<House*> houses; // Vector to store owned houses

    Owner() {}

    void setHouseInfo();

    void displayOwnerInfo() {
        cout << "Owner Information:" << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "CNIC: " << cnic << endl;
    }
};

class House {
public:
    string location;
    int numberOfRooms;
    int numberOfBaths;
    int numberOfKitchens;
    int fair;
    Owner* owner; // Reference to the owner

    House(Owner* o) : owner(o) {}

    void setHouseInfo();

    void displayHouseInfo() {
        cout << "House Information:" << endl;
        cout << "Location: " << location << endl;
        cout << "Rooms: " << numberOfRooms << endl;
        cout << "Baths: " << numberOfBaths << endl;
        cout << "Kitchens: " << numberOfKitchens << endl;
        cout << "House's rent is : " << fair << endl;
        owner->displayOwnerInfo();
    }
};

void Owner::setHouseInfo() {
    House* newHouse = new House(this);
    newHouse->setHouseInfo();
    houses.push_back(newHouse);
}

void House::setHouseInfo() {
    cout << "Enter rental house location: ";
    getline(cin, location);

    cout << "Enter number of rooms: ";
    cin >> numberOfRooms;

    cout << "Enter number of baths: ";
    cin >> numberOfBaths;

    cout << "Enter number of kitchens: ";
    cin >> numberOfKitchens;

    cout << "Enter the house fair: ";
    cin >> fair;

    // Clear input buffer
    cin.ignore();
}

class Customer : public Person {
private:
    int budget;

public:
    Customer() {}

    void setBudget() {
        cout << "Enter your budget: ";
        cin >> budget;

        // Clear input buffer
        cin.ignore();
    }

    vector<House*> searchHouses(const vector<Owner>& owners);

    void displayHouseInfo(House* house);
};

vector<House*> Customer::searchHouses(const vector<Owner>& owners) {
    vector<House*> affordableHouses;
    for (const Owner& owner : owners) {
        for (House* house : owner.houses) {
            if (budget >= house->fair) {
                affordableHouses.push_back(house);
            }
        }
    }
    return affordableHouses;
}

void Customer::displayHouseInfo(House* house) {
    if (house != nullptr) {
        house->displayHouseInfo();
    } else {
        cout << "Sorry, no affordable houses found." << endl;
    }
}

int main() {
system("color F0");
	cout<<"\n\n\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout<<"\n+++\t\t\t\t\t\t\t\t\t+++\n+++\t\t\t\t\t\t\t\t\t+++\n";
	cout<<"+++\t\t\t  HOUSE RENTAL SYSTEM \t\t\t\t+++\n+++\t\t\t\t\t\t\t\t\t+++\n";
	cout<<"+++\t\t\t\tProject By:\t\t\t\t+++\n+++\t\t\t\t\t\t\t\t\t+++\n";
	cout<<"+++\t\t\t\t\t\t\t\t\t+++\n+++\t\t\tBCPE223050  -  Wahab Tanveer\t\t\t+++\n";
	cout<<"+++\t\t\tBCPE223052  -  Anees Akbar\t\t\t+++\n";
    cout<<"+++\t\t\tBCPE223041  -  Muhammad Owais\t\t\t+++\n";

	cout<<"+++\t\t\t\t\t\t\t\t\t+++\n+++\t\t\t\t\t\t\t\t\t+++\n+++\t\t\t\t\t\t\t\t\t+++\n";
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
	cout<<"\n\n\n---------------------------------------------------------------------------\n\n";
	cout<<"\t\t\t*****Welcome*****\n";
	cout<<"\n\t\t      All your needs are Here2\n";
    vector<Owner> owners;
    vector<Customer> customers;

    int choice;

    do {
        cout <<endl<< "Menu:" << endl;
        cout << "1. You are the owner" << endl;
        cout << "2. You are the customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1, 2, or 3): ";

        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: {
                Owner newOwner;
                newOwner.setInfo();
                owners.push_back(newOwner);

                char addHouseChoice;
                do {
                    owners.back().setHouseInfo();
                    cout << "Do you want to add another house? (y/n): ";
                    cin >> addHouseChoice;
                    cin.ignore(); // Clear input buffer
                } while (addHouseChoice == 'y' || addHouseChoice == 'Y');

                break;
            }
            case 2: {
                if (!owners.empty()) {
                    Customer newCustomer;
                    newCustomer.setInfo();
                    newCustomer.setBudget();

                    vector<House*> affordableHouses = newCustomer.searchHouses(owners);

                    if (!affordableHouses.empty()) {
                        cout << "Affordable Houses:" << endl;
                        for (House* house : affordableHouses) {
                            newCustomer.displayHouseInfo(house);
                        }
                    }
                } else {
                    cout << "Sorry, no houses available. Owners need to add houses first." << endl;
                }

                break;
            }
            case 3: {
                cout << "Exiting the program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
                break;
            }
        }

    } while (choice != 3);

    // Clean up allocated memory
    for (Owner& owner : owners) {
        for (House* house : owner.houses) {
            delete house;
        }
    }

    return 0;
}