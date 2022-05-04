#include<thread.h>
#include<iostream>
#include<array>
#include<iterator>
#include<vector>
#include<ranges>

int compute_high(int size, int ref) {
	if(ref>size) return ref;
	ref = compute_high(size, ref+1);
	return (ref+1)*size;
}
template<typename T>
concept rng = ((std::ranges::range<T>)==true) ;

template<class T>
void allocate_vector(T v) {
	std::vector<int> arr{std::ranges::range<std::vector<int>>};//new std::array<T, sizeof(T)>;
	std::ranges::begin(arr);
	for(int i=0;i<arr.size();i++) arr.push_back(compute_high(arr.at(i)));
}

//int main() {
//	
//	std::cout << compute_high(100);
//	allocate_vector<int>(compute_high(100));
//	return 0;
//}


