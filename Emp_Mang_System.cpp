#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Employee {
    int id;
    string name;
    string email;
    string contactNumber;
    string designation;
    int salary;
};
struct Node {
    Employee emp;
    Node* next;
};
class EmployeeManagementSystem {
private:
    Node* head;

public:
    EmployeeManagementSystem() {
        head = nullptr;
    }

   void loadEmployeesFromFile() {
    ifstream file("employees.txt");
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }

    Employee emp;
    while (file >> emp.id) {
        file.ignore(); 
        getline(file, emp.name);
        getline(file, emp.email);
        getline(file, emp.contactNumber);
        getline(file, emp.designation);
        file >> emp.salary;
        file.ignore();  

        Node* newNode = new Node();
        newNode->emp = emp;
        newNode->next = head;
        head = newNode;
    }

    file.close();
}

void saveEmployeesToFile() {
    ofstream file("employees.txt");
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        file << current->emp.id << endl;
        file << current->emp.name << endl;
        file << current->emp.email << endl;
        file << current->emp.contactNumber << endl;
        file << current->emp.designation << endl;
        file << current->emp.salary << endl;

        current = current->next;
    }

    file.close();
}

   void addEmployee() {
    Employee emp;
    cout << "Enter employee ID: ";
    cin >> emp.id;
    cin.ignore();  
    cout << "Enter employee name: ";
    getline(cin, emp.name);
    cout << "Enter employee email: ";
    getline(cin, emp.email);
    cout << "Enter employee contact number: ";
    getline(cin, emp. contactNumber);
    cout << "Enter employee designation: ";
    getline(cin, emp.designation);
    cout << "Enter employee salary: ";
    cin >> emp.salary;
    cin.ignore(); 

    Node* newNode = new Node();
    newNode->emp = emp;
    newNode->next = head;
    head = newNode;
}
 void displayEmployees() {
    Node* current = head;
    while (current != nullptr) {
        cout << "Employee ID: " << current->emp.id << endl;
        cout << "Employee Name: " << current->emp.name << endl;
        cout << "Employee Email: " << current->emp.email << endl;
        cout << "Employee Contact Number: " << current->emp.contactNumber << endl;
        cout << "Employee Designation: " << current->emp.designation << endl;
        cout << "Employee Salary: " << current->emp.salary << endl;
        cout << "-------------------------------------" << endl;  

        current = current->next;
    }
}
  void searchEmployee() {
    int id;
    cout << "Enter employee ID to search: ";
    cin >> id;

    Node* current = head;
    while (current != nullptr && current->emp.id != id) {
      current = current->next;
    }

    if (current == nullptr) {
      cout << "Employee with ID " << id << " not found." << endl;
    } else {
      cout << "Employee ID: " << current->emp.id << endl;
      cout << "Employee Name: " << current->emp.name << endl;
      cout << "Employee Email: " << current->emp.email << endl;
      cout << "Employee Contact Number: " << current->emp.contactNumber << endl;
      cout << "Employee Designation: " << current->emp.designation << endl;
      cout << "Employee Salary: " << current->emp.salary << endl;
    }
  }

  void updateEmployee() {
    int id;
    cout << "Enter employee ID to update: ";
    cin >> id;

    Node* current = head;
    while (current != nullptr && current->emp.id != id) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Employee with ID " << id << " not found." << endl;
    } else {
        cout << "Enter new employee name: ";
        cin.ignore();
        getline(cin, current->emp.name);
        cout << "Enter new employee email: ";
        getline(cin, current->emp.email);
        cout << "Enter new employee contact number: ";
        getline(cin, current->emp.contactNumber);
        cout << "Enter new employee designation: ";
        getline(cin, current->emp.designation);
        cout << "Enter new employee salary: ";
        cin >> current->emp.salary;
        cout << "Employee with ID " << id << " updated successfully." << endl;
        saveEmployeesToFile();
    }
}
  void deleteEmployee() {
    int id;
    cout << "Enter employee ID to delete: ";
    cin >> id;

    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr && current->emp.id != id) {
      previous = current;
      current = current->next;
    }

    if (current == nullptr) {
      cout << "Employee with ID " << id << " not found." << endl;
    } else {
      if (previous == nullptr) {
        head = current->next;
      } else {
        previous->next = current->next;
      }

      delete current;
      cout << "Employee with ID " << id << " deleted successfully." << endl;
    }
  }
};
int main() {
    EmployeeManagementSystem ems;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Load employees from file" << endl;
        cout << "2. Save employees to file" << endl;
        cout << "3. Add employee" << endl;
        cout << "4. Display employees" << endl;
        cout << "5. Search employee" << endl;
        cout << "6. Update employee" << endl;
        cout << "7. Delete employee" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                ems.loadEmployeesFromFile();
                break;
            case 2:
                ems.saveEmployeesToFile();
                break;
            case 3:
                ems.addEmployee();
                break;
            case 4:
                ems.displayEmployees();
                break;
            case 5:
                ems.searchEmployee();
                break;
            case 6:
                ems.updateEmployee();
                break;
            case 7:
                ems.deleteEmployee();
                break;
            case 8:
                exit(0);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
        cout << "-------------------------------------" << endl; 
    } while (choice != 8);

    return 0;
}
