// run this program at http://ideone.com/XcNIT6
#include <iostream>
#include <unordered_map>
#include <queue>
#include <ctime>

using namespace std;

/*
 * fin k most frequent values in input vector
 */
vector<int> most_k_integers(const vector<int>& input, const int k)
{
	unordered_map<int,int> m;
	for(auto num : input)
		m[num]++;
		
	priority_queue<pair<int,int>> q;
	
	////////////////////////////////////////////////////
	// option 1, use constructor ~ 0.38s
	////////////////////////////////////////////////////
	// vector<pair<int,int>> e;
	// for(auto& kv : m)
	// 	e.push_back(make_pair(kv.second, kv.first));
	
	// q = priority_queue<pair<int,int>>(e.begin(), e.end());
	
	////////////////////////////////////////////////////
	// option 2, directly push ~ 0.36s
	////////////////////////////////////////////////////
	for(auto& kv : m)
		q.push(make_pair(kv.second, kv.first));
	////////////////////////////////////////////////////
	
	vector<int> output;
	for(int i=0;i<min(k, (int)m.size());i++)
	{
		output.push_back(q.top().second);
		q.pop();
	}
	
	return output;
}

int main() {
	vector<int> input;
	
	for(int i=1;i<1000000;i++)
	{
		int key = i;
		int count = i%10+1;
		for(int j=0;j<count;j++)
			input.push_back(key);
	}
	
	for(int k=1;k<7;k++)
	{
		clock_t s = clock(); 	                     
		vector<int> output = most_k_integers(input, k);
		for(auto o : output)
			cout<<o<<" ";
		cout<<endl;
		double cost = (clock() - s) * 1.0 / CLOCKS_PER_SEC;
		cout<<"n = "<<input.size()<<" k = "<<k<<" cost = "<<cost<<" s"<<endl;
	}
	
	return 0;
}
