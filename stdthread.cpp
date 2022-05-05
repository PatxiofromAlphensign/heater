#include<thread>
#include<vector>
#include<functional>
#include<iostream>

template<typename T>
class thread {
	std::vector<std::jthread> threads;
	public:
	thread() = default;
	thread(int count, T f) {
		for(int i=0;i<count;i++) {
			threads.push_back(std::move(std::jthread(std::bind(f, count,1,1))));
		}
	}
	void join() {
		for(std::jthread &thread : threads ) if(thread.joinable()) thread.join();
	}
};

float compute(int size, float count=1, float count1=1)  {
	if(count>size) return count;
	for(int i=0;i<10;i++)
		count = compute(size, count+1);
	count1 = 1/count;
	std::cout << count;
	return count + ((count + count*2)/(count1 + count*2));
}

int main() {
	thread t(100000, compute);
	t.join();
}
