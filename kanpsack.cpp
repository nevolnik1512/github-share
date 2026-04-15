#include <vector>
#include <iostream>
using namespace std;
std::vector<int> val=  {13,45,32,56,12,43};
std::vector<int> wt= {7,2,4,2,7,10};
int n = wt.size();
int W = 10;
vector<vector<int>> dp(n + 1, vector<int>(W + 1,0));

void print (){
  for (int i = 0; i < n; i ++){
    for (int j =0; j < W;j++){
      std::cout << dp[i][j] << ";\t";
    }
    std::cout << '\n';
  }
}

int main() {
  for (int i = 0; i < n; i ++){
    for (int j =0; j < W;j++){
      if (j==0 || i==0){
        //no elements or no space in knapsack
        dp[i][j]=0;

      }else{

        int pick = 0;
        if (wt[i-1]<=j){
          pick =val [i-1] + dp[i-1][j-wt[i-1]];
        }
        int notPick= dp[i-1][j];
        dp[i][j] =max(pick, notPick);

        print ();

        std::cout << i << ";"<< j <<'\n';
      }


    }
    std::cout << '\n';
  }


  return 0;
}
