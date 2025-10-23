#include <iostream>
#include <fstream>
using namespace std;


struct SalesRecord {
    string month;
    float amount;
};

int main() {
    SalesRecord records[12];
    float totalSales = 0.0;


    cout << "Enter sales data for each month:\n";
    for (int i = 0; i < 12; i++) {
        cout << "Month " << i + 1 << " name: ";
        cin >> records[i].month;
        cout << "Sales amount for " << records[i].month << ": ";
        cin >> records[i].amount;
        totalSales += records[i].amount;
    }

    // Write data to text file
    ofstream outFile("sales_data.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing.\n";
        return 1;
    }

    for (int i = 0; i < 12; i++) {
        outFile << records[i].month << " " << records[i].amount << "\n";
    }
    outFile.close();

    // Read data back from the file
    SalesRecord fileRecords[12];
    ifstream inFile("sales_data.txt");
    if (!inFile) {
        cerr << "Error: Could not open file for reading.\n";
        return 1;
    }

    for (int i = 0; i < 12; i++) {
        inFile >> fileRecords[i].month >> fileRecords[i].amount;
    }
    inFile.close();

    // Calculate yearly average
    float average = totalSales / 12;
    cout << "\nYearly average sales: " << average << endl;

    // Display months above average
    cout << "\nMonths with sales above average:\n";
    for (int i = 0; i < 12; i++) {
        if (fileRecords[i].amount > average) {
            cout << fileRecords[i].month << " (" << fileRecords[i].amount << ")\n";
        }
    }

    return 0;
}
