#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;


vector<int> fillvec(int size) {
    vector<int> randomNumbers;

    // Populate the vector with numbers from 1 to size
    for (int i = 1; i <= size; ++i) {
        randomNumbers.push_back(i);
    }

    // Shuffle the vector to get random order
    random_device rd;
    mt19937 g(rd());
    shuffle(randomNumbers.begin(), randomNumbers.end(), g);

    cout << "Generated random numbers: ";
    for (int num : randomNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return randomNumbers;
}

bool isSorted(const vector<int>& vec) {
    return is_sorted(vec.begin(), vec.end());
}

int main() {
    cout << "BOGO SORT" << endl << endl;
    int size;
    char enter = 'y';
    while(enter == 'y'){
        cout << "Enter vector size : ";
        cin >> size;
        vector<int> randomNumbers = fillvec(size);
        int loopcount = 0;

        // Measure time before sorting
        auto start = high_resolution_clock::now();

        // Check if the vector is sorted, if not, shuffle until it is
        while (!isSorted(randomNumbers)) {
            random_device rd;
            mt19937 g(rd());
            shuffle(randomNumbers.begin(), randomNumbers.end(), g);
            loopcount++;
        }

        // Measure time after sorting
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Generated numbers: ";
        for (int num : randomNumbers) {
            cout << num << " ";
        }
        cout << endl;
        cout << "Shuffle count = " << loopcount << endl;

        // Output the time taken
        cout << "Time taken: " << duration.count() << " milliseconds" << endl;

        cout << endl << "Again? (y/n) :";
        cin >> enter;
    }

    

    getchar();
    return 0;
}

