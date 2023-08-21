#include<iostream>
using namespace std;

void TOH(int n, char s, char a, char d) {
   static int count = 0;          //store number of counts
   if(n == 1) {
      count++;
      cout << count<< ". Move disk " << n << " from "<<s <<" to "<<d<<endl;
      return;      //base case, when only one disk
   }

   TOH(n-1, s, d, a);               //recursive call the function
   count++;
   cout << count<< ". Move disk " << n << " from "<<s <<" to"<<d<<endl;
   TOH(n-1, a, s, d);
}

int main() {
   int n;
   cout << "Enter the number of disks: ";
   cin >> n;
   TOH(n, 'A','B','C');
}
