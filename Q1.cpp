#include <iostream>

using namespace std;

struct Item {
    int id;
    string name;
    float cost;
};

int main() {
    Item items[8];
    float total_cost = 0.0;

    cout << "Enter details for 8 items (id name cost):\n";

    for (int i = 0; i < 8; i++) {
        cin >> items[i].id >> items[i].name >> items[i].cost;
        total_cost += items[i].cost;
    }


    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7 - i; j++) {
            if (items[j].cost < items[j + 1].cost) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    cout << "\nItems sorted in descending order of cost:\n";
    for (int i = 0; i < 8; i++) {
        cout << "ID: " << items[i].id << ", Name: " << items[i].name
             << ", Cost: " << items[i].cost << endl;
    }

    float avg_cost = total_cost / 8.0;
    cout << "\nAverage cost of all items: " << avg_cost << endl;

    return 0;
}
