#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <thread>
#include <mutex>
using namespace std;

std::mutex print_mutex;  // protects g_i

class SumList
{
public:
    SumList(const vector<int>& list)
    {
        this->m_list = list;
    }

    SumList(const SumList& sl)
    {
        this->m_list = sl.m_list;
    }

    const int getSum() const {
        int sum = 0;
        for(auto v : m_list)
            sum += v;
        return sum;
    }

private:
    vector<int> m_list;
};

void computeSum(const SumList& sl){
    
    // look the mutex to ensure the print is atomic
    std::lock_guard<std::mutex> lock(print_mutex);

    cout<<sl.getSum()<<endl;

    // lock auto released after this function
}

int main(int argc, char** argv) {
    
    vector<thread*> threads;
    vector<SumList* sls;

    for(int i=1;i<=5;i++)
    {
        vector<int> list;
        for(int j=1;j<=i*i*i;j++)
            list.push_back(j);             

        // create the object on the heap
        SumList* sl = new SumList(list);

        sls.push_back(sl);

        // create the worker on the heap as well
        thread* worker = new thread(computeSum, *sl);

        threads.push_back(worker);
    }

    // wait for all thread to exit
    for(auto t : threads)
        t->join();

    // clean up
    for(auto t : threads)
        delete t;

    for(auto sl : sls)
        delete sl;

    return 0;
}