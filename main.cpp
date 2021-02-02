#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<double> getDifferences(vector<double> x){
  double t;
  vector<double> stor;
  for (int i = 0; i < x.size()-1; i++){
    t = x[i+1]-x[i];
    stor.push_back(t);
  }
  return stor;
}

// This might not be needed
// bool checkEqual(vector<int> x){
//   bool isEqual = true;
//   int t = x[0];
//   for (int i = 1; i < x.size();i++){
//     if (t!=x[i]){isEqual = false;break;}
//   }
//   return isEqual;
// }

int main() {
  vector<double> seq;
  double temp;
  cout << "Welcome to the sequence guesser!" << endl;
  cout << "Enter 5 numbers and the sequence guesser will tell you what the next number will be. Integers only, please." << endl << endl;
  
  // Get the NUMBERS!
  cout << "Enter the 1st number :";
  cin >> temp;
  seq.push_back(temp);
  cout << "Enter the 2nd number :";
  cin >> temp;
  seq.push_back(temp);
  cout << "Enter the 3rd number :";
  cin >> temp;
  seq.push_back(temp);
  cout << "Enter the 4th number :";
  cin >> temp;
  seq.push_back(temp);
  cout << "Enter the 5th number :";
  cin >> temp;
  seq.push_back(temp);

  // Big-Brain the NUMBERS!
  vector<double> first;
  vector<double> second;
  vector<double> third;
  vector<double> fourth;
  
  // Fill first level with differences
  first = getDifferences(seq);
  second = getDifferences(first);
  third = getDifferences(second);
  fourth = getDifferences(third);

  // Print next number
  cout << endl;
  cout << "The next number is : ";
  cout << seq.back() + first.back() + second.back() + third.back() + fourth.back();
  cout << endl << endl;

  // Get interpolating function
  // Calculate coefficients
  double a=0,b=0,c=0,d=0,e=0;
  a = (seq[0]-4*seq[1]+6*seq[2]-4*seq[3]+seq[4])/24;
  b = (-7*seq[0]+26*seq[1]-36*seq[2]+22*seq[3]-5*seq[4])/12;
  c = (71*seq[0]-236*seq[1]+294*seq[2]-164*seq[3]+35*seq[4])/24;
  d = (-77*seq[0]+214*seq[1]-234*seq[2]+122*seq[3]-25*seq[4])/12;
  e = (5*seq[0]-10*seq[1]+10*seq[2]-5*seq[3]+seq[4])/1;
  //cout << a << " " << b << " " << c << " " << d << " " << e;
  cout << "Your polynomial is : y = ";
  if (a!=0){cout << a << "x^4+";}
  if (b!=0){cout << b << "x^3+";}
  if (c!=0){cout << c << "x^2+";}
  if (d!=0){cout << d << "x+";}
  if (e!=0){cout << e;}
}