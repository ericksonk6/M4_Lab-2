#include <string>
#include <vector>
#include <iostream>

using namespace std;

// TODO: Write the partitioning algorithm - pick the middle element as the
//       pivot, compare the values using two index variables l and h (low and high),
//       initialized to the left and right sides of the current elements being sorted,
//       and determine if a swap is necessary
int Partition(vector<string> &userIDs, int i, int k) {

    //initialize variables
    bool done = false;
    int l = i;
    int h = k;
    string temp;
    //pick middle value as pivot
    int midpoint = i + (k - i) / 2;
    string pivot = userIDs[midpoint];


    while (!done) {

        //increment l while numbers[l] < pivot
        while (userIDs[l] < pivot) {
            ++l;
        }

        //Decrement h while pivot < numbers[h]
        while (pivot < userIDs[h]) {
            --h;
        }
//If there are zero or one items remaining, all numbers are partitioned. Return h
        if (l >= h) {
            done = true;
        } else {
            //Swap numbers[l] and numbers[h], update l and h
            temp = userIDs[l];
            userIDs[l] = userIDs[h];
            userIDs[h] = temp;

            ++l;
            --h;
        }
    }
    return h;
}

//sort the IDs in ascending order
// TODO: Write the quicksort algorithm that recursively sorts the low and
//       high partitions
void Quicksort(vector<string> &userIDs, int i, int k) {
    int j = 0;

    //Base case: If 1 or zero elements, partition is already sorted
    if (i >= k) {
        return;
    }

    //Partition the array. Value j is the location of last element in low partition.
    j = Partition(userIDs, i, k);

    // Recursively sort low and high partitions
    Quicksort(userIDs, i, j);
    Quicksort(userIDs, j + 1, k);
}

//output the sorted IDs one per line reads users IDs until -1
int main(int argc, char *argv[]) {
    vector<string> userIDList;
    string userID;
    cout << "Please enter IDs to be sorted (type -1 to end program)" << endl;
    cin >> userID;
    while (userID != "-1") {
        userIDList.push_back(userID);
        cin >> userID;
    }

    // Initial call to quicksort
    Quicksort(userIDList, 0, userIDList.size() - 1);

    for (size_t i = 0; i < userIDList.size(); ++i) {
        cout << userIDList.at(i) << endl;
    }

    return 0;
}