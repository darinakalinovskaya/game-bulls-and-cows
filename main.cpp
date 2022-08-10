#include "std_lib_facilities.h"
#include <ctime>


void rand(vector<int> &savednum) {
   time_t current_time; // seconds
  // stores time in current_time
  time(&current_time);
  
  seed_randint(current_time*current_time); 
  int max  = 10;
  double sum = 0;
  double median=0;
  for (int i = 0; i < max; i++) {
    int ran = randint(9);
    savednum.push_back(ran);
    //cout<< savednum[i]<< endl;
    sum += savednum[i];
    }
    median = sum/max;
  cout << "Sum: "<< sum<< endl;
  cout << "Med "<< median<< endl;
}

void fill(vector<int> &num) {
  num.clear();
  for (int a = 0; a < 4; a++) {
    int temp;
    cin >> temp;
    num.push_back(temp);
  }

}

bool game(vector<int> &savednum, vector<int> &num) {
  int bull = 0;
  int cow = 0;

  for (int s = 0; s < 4; s++) {
    for (int n = 0; n < 4; n++) {
      // cout<<num[n]<<" "<<savednum[s]<<endl;
      if (savednum[s] == num[n]) {
        if (n == s) {
          bull++;
        } else {
          cow++;
        }
      }
    }
  }
  cout << bull << " bull" << endl;
  cout << cow << " cow" << endl;

  if (bull == 4) {
    cout << "You win! " << endl;
    return true;
  } else {
    cout << "You loose, try again :(" << endl;
    return false;
  }
}

void repeat() {
  vector<int> savednum;
  vector<int> num;
  cout << "New game! " << endl;
  rand(savednum);
  fill(num);
  while (!game(savednum, num)) {
    fill(num);
  }
}

int main() {
  time_t current_time; // seconds

  string ans;
  for (;;){
    cout << "Want to play a new game? " << endl;
    cin>> ans;
    if(ans== "yes"){
       repeat(); 
    }
   else{
     cout<<"Goodbye! "<< endl;
     break;
   }
  }
}
