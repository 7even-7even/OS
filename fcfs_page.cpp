#include <iostream>
#include <vector>
using namespace std;
int FIFO(int n, int p, const vector<int>& input) {
vector<int> frame(n);
int fault = 0;
int index = 0;
cout << "\nPage Replacement Process:\n";
for (int i = 0; i < p; i++) {
bool found = false;
// Check if the page is already in the frame
for (int j = 0; j < n; j++) {
if (frame[j] == input[i]) {
found = true;
break;
}
}
if (!found) {
if (index == n) {
index = 0;
}
frame[index] = input[i];
fault++;
index++;
cout << "Page " << input[i] << " replaced ";
if (index == n) {
cout << "Page " << frame[0] << endl;
index = 0;
} else if (i == 0) {
cout << "(initially empty frame)" << endl;
} else {
cout << "Page " << frame[index - 1] << endl;
}
} else {
cout << "Page " << input[i] << " already in frame" << endl;
}
cout << "Current Frame: ";
for (int j = 0; j < n; j++) {
cout << frame[j] << " ";
}
cout << endl;
}
return fault;
}
int main() {
int n, p;
cout << "Enter the size of the frame: ";
cin >> n;
cout << "Enter the No. of Input Pages: ";
cin >> p;
vector<int> input(p);
cout << "Enter the Input Pages: ";
for (int i = 0; i < p; i++) {
cin >> input[i];
}
int faults = FIFO(n, p, input);
cout << "\nThe No. of Page Faults is: " << faults << endl;
return 0;
}
