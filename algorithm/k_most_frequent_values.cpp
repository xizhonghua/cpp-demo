// run this program at http://ideone.com/XcNIT6
#include <iostream>
#include <unordered_map>
#include <queue>
#include <ctime>

using namespace std;

template<typename T>
vector<T> k_most_freq_elements(const vector<T>& input, const int k)
{
	unordered_map<T, int> m;
	for(const auto &v : input)
		m[v]++;
		
	priority_queue<pair<int,T>> q;
	
	for(auto& kv : m)
		q.push(make_pair(kv.second, kv.first));
	
	vector<T> result;
	for(int i=0;i<min(k, (int)m.size());i++)
	{
		result.push_back(q.top().second);
		q.pop();
	}
	
	return result;
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
		vector<int> output;
		output = k_most_freq_elements(input, k);
		for(auto o : output)
			cout<<o<<" ";
		cout<<endl;
		double cost = (clock() - s) * 1.0 / CLOCKS_PER_SEC;
		cout<<"n = "<<input.size()<<" k = "<<k<<" cost = "<<cost<<" s"<<endl;
	}
	
	return 0;
}
