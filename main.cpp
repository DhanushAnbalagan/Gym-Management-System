#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm> // Added for sorting
using namespace std;

// Class to store information about a gym membership
class GymMembership {
public:
    string name;
    int timing;

    // Constructor
    GymMembership(string n, int t) : name(n), timing(t) {}
};

// Function prototype for sorting
bool compareByTiming(const GymMembership& a, const GymMembership& b);

int main() {
    int choice;
    string name;
    int timing;
    vector<GymMembership> members; // Store all created memberships

    cout << "Welcome to the Gym Management System!" << endl;
    do {
        // Show menu
        cout << "-------------------------" << endl;
        cout << "1. Create a new membership" << endl;
        cout << "2. View existing memberships" << endl;
        cout << "3. Modify a membership" << endl;
        cout << "4. Cancel a membership" << endl;
        cout << "5. Search for a membership" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";

        // Input validation to handle non-numeric inputs
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            // Create a new membership
            cout << "Enter your name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << "Select timing (1 for morning, 2 for afternoon, 3 for evening): ";
            while (!(cin >> timing) || (timing < 1 || timing > 3)) {
                cout << "Invalid timing. Please enter 1, 2, or 3: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            members.push_back(GymMembership(name, timing)); // Add the new membership to the vector
            cout << "Membership created successfully!" << endl;
            break;

        case 2:
            // View existing memberships
            if (!members.empty()) {
                cout << "Existing memberships (in order of timing):" << endl;
                // Sort the memberships based on timing
                sort(members.begin(), members.end(), compareByTiming);
                for (size_t i = 0; i < members.size(); ++i) {
                    cout << "Membership " << i + 1 << ":" << endl;
                    cout << "Name: " << members[i].name << endl;
                    cout << "Timing: ";
                    switch (members[i].timing) {
                    case 1:
                        cout << "Morning";
                        break;
                    case 2:
                        cout << "Afternoon";
                        break;
                    case 3:
                        cout << "Evening";
                        break;
                    default:
                        cout << "Invalid timing";
                    }
                    cout << endl;
                }
            } else {
                cout << "No memberships found!" << endl;
            }
            break;

        case 3:
            // Modify a membership
            if (!members.empty()) {
                int index;
                cout << "Enter the membership number to modify: ";
                while (!(cin >> index) || (index < 1 || index > members.size())) {
                    cout << "Invalid membership number! Please enter a valid number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter new name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, members[index - 1].name);
                cout << "Select new timing (1 for morning, 2 for afternoon, 3 for evening): ";
                while (!(cin >> timing) || (timing < 1 || timing > 3)) {
                    cout << "Invalid timing. Please enter 1, 2, or 3: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                members[index - 1].timing = timing;
                cout << "Membership modified successfully!" << endl;
            } else {
                cout << "No memberships found!" << endl;
            }
            break;

        case 4:
            // Cancel a membership
            if (!members.empty()) {
                int index;
                cout << "Enter the membership number to cancel: ";
                while (!(cin >> index) || (index < 1 || index > members.size())) {
                    cout << "Invalid membership number! Please enter a valid number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                members.erase(members.begin() + index - 1);
                cout << "Membership canceled successfully!" << endl;
            } else {
                cout << "No memberships found!" << endl;
            }
            break;

        case 5:
            // Search for a membership
            if (!members.empty()) {
                string searchName;
                cout << "Enter the name to search: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, searchName);
                bool found = false;
                for (size_t i = 0; i < members.size(); ++i) {
                    if (members[i].name == searchName) {
                        found = true;
                        cout << "Membership found at index " << i + 1 << ":" << endl;
                        cout << "Name: " << members[i].name << endl;
                        cout << "Timing: ";
                        switch (members[i].timing) {
                        case 1:
                            cout << "Morning";
                            break;
                        case 2:
                            cout << "Afternoon";
                            break;
                        case 3:
                            cout << "Evening";
                            break;
                        default:
                            cout << "Invalid timing";
                        }
                        cout << endl;
                    }
                }
                if (!found) {
                    cout << "Membership not found for the given name." << endl;
                }
            } else {
                cout << "No memberships found!" << endl;
            }
            break;

        case 6:
            // Exit
            cout << "Thank you for using the Gym Management System!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

// Function definition for sorting
bool compareByTiming(const GymMembership& a, const GymMembership& b) {
    return a.timing < b.timing;
}
