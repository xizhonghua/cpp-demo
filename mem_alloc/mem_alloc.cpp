#include <iostream>
#include <cstring>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char** argv) {
  if(argc < 2) {
    cout<<"Usage: "<<argv[0]<<" rate (MB/s) [last=10] [calls_per_sec=1000]"<<endl;
    return -1;
  }

  // byte / s
  int rate = std::stoi(argv[1]) * 1024 * 1024;  

  
  const int last = argc>2 ? std::stoi(argv[2]) : 10; // last for 30 s, by default
  const int alloc_per_sec = argc>3 ? std::stoi(argv[3]) : 1000; // 1000 times/sec  
  const int chunk_size = rate * 1.0 / alloc_per_sec; // byte/s
  const int max_sleep_time_us = 1e6 / alloc_per_sec;

  cout<<"allocate mem at "<<chunk_size<<" bytes/ms for "<<last<<" s @ " <<alloc_per_sec << " calls/s" <<endl;

  long long total_alloc = 0;
  for(int t=0; t<last; t++)
  {    
    for(int i=0;i<alloc_per_sec; ++i)
    {
      auto start_time = chrono::high_resolution_clock::now();
      char* buffer = new char[chunk_size];      
      memset(buffer, i, chunk_size);    
      total_alloc += chunk_size;
      auto end_time = chrono::high_resolution_clock::now();
      auto spent_us = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
      std::this_thread::sleep_for(std::chrono::microseconds{max_sleep_time_us - spent_us});
    }
    cout<<(t+1)<<" s"<<" total allocated = "<< (total_alloc)*1.0/1024/1024 << " MB"<<endl;
  }

  return 0;
}