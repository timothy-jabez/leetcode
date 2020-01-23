#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > transpose(vector<vector<int> >& A) {
   vector < vector <int> > res;
   for (int i = 0; i < A[0].size(); i++){ // A[0].size() gives the number of columns in A
      res.push_back(vector<int>());
      for (int j = 0; j < A.size(); j++){ // A.size() gives the number of rows in A
         res[i].push_back(A[j][i]);
      }
   }
   return res;
}

int main()
{
   vector<vector<int> > A { { 1, 2, 3 },  { 4, 5, 6 },   { 7, 8, 9 } }; 
   A = transpose( A );
   for (vector<int> row: A) {
		for (int val: row) {
			cout << val << " ";
		}
		cout << '\n';
	}
}

