#include <iostream>
using namespace std;

int LRU(int n, int p, int input[]) {
    int frame[n]; 
    int order[100]; // To keep track of the order of pages
    int orderIndex = 0; // To track the current index in the order array
    int fault = 0;

    // Initialize frames to -1 (empty)
    for (int i = 0; i < n; i++) {
        frame[i] = -1;
    }
    
    for (int i = 0; i < p; i++) {
        bool found = false;
        int index = -1;

        // Check if the page is already in the frame
        for (int j = 0; j < n; j++) {
            if (frame[j] == input[i]) {
                found = true;
                index = j;
                break;
            }
        }

        if (found) {
            // Move the found page to the front of the order
            for (int j = 0; j < orderIndex; j++) {
                if (order[j] == input[i]) {
                    // Shift pages to remove the found page
                    for (int k = j; k < orderIndex - 1; k++) {
                        order[k] = order[k + 1];
                    }
                    orderIndex--; // Decrease the order index
                    break;
                }
            }
            // Add the page to the front of the order
            order[orderIndex++] = input[i];
            cout << "Page " << input[i] << " already in frame (moved to front)" << endl;
        } else {
            // If the frame is full, replace the LRU page
            if (orderIndex == n) {
                int lruPage = order[0]; // The first page is the least recently used
                // Find the index of the LRU page in the frame
                for (int j = 0; j < n; j++) {
                    if (frame[j] == lruPage) {
                        index = j;
                        break;
                    }
                }
                cout << "Page " << lruPage << " replaced by ";
                // Shift the order array left
                for (int j = 0; j < orderIndex - 1; j++) {
                    order[j] = order[j + 1];
                }
                orderIndex--; // Decrease the order index
            } else {
                index = orderIndex; // New page can be added
            }
            frame[index] = input[i];
            order[orderIndex++] = input[i]; // Add new page to order
            fault++;
            cout << "Page " << input[i] << endl;
        }

        // Display current frame
        cout << "Current Frame: ";
        for (int j = 0; j < n; j++) {
            if (frame[j] != -1) {
                cout << frame[j] << " ";
            }
        }
        cout << endl;
    }

    return fault;
}

int main() {
    int n, p;

    cout << "\nEnter the size of the frame: ";
    cin >> n;

    cout << "\nEnter the No. of Input Pages: ";
    cin >> p;

    int input[p]; 

    cout << "\nEnter the Input Pages: ";
    for (int i = 0; i < p; i++) {
        cin >> input[i];
    }

    int faults = LRU(n, p, input);
    cout << "\nThe No. of Page Faults is: " << faults << endl;

    return 0;
}

