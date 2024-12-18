#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

// i need to get a vector and than go through the vector get 0 and the use push back to put it at the end of the vector
int main(){
  
  vector<int> num = {0,1,0,3,12};
  int s = num.size();
  int index = 0;

  for(int i = 0; i < s; i++){
    if(num[i] != 0){
        num[index++] = num[i];
    }
  }
  while(index < s){
    num[index++] = 0;
  }
  for(int i = 0; i < s; i++){
    cout << num[i];
  }
    return 0;
  }