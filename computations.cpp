#include<thread.h>
#include<ranges>
#include<functional>
#include<vector>
#include<cstdlib>

template<typename T>
struct F {
	using point = T*;
	using ref = T&;
	using iter = std::ranges::iterator_t<std::vector<int>>;

	F() = default;
	F(std::vector<int> &v);
	T rec(T base) {
		char *name_t = (char*)typeid(T).name();
		std::string *s = (std::string*)&name_t;
		(*s)._M_length(10);
		if(base>10)  return base;
		base =  rec(base+1)*2;
		return base-1;
	}
	void operator()(int &x) {
		T x_ = this->rec(x);
		x=x_;
	}
};

template<>
F<int>::F(std::vector<int> &v) { }

int main() {
	std::vector<int> v;
	struct F<int> f(v);
	//auto b = std::bind(f);
	int d=0;
	f(d);
	//int x = b(d);
	return 0;
}
