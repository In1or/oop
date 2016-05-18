#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>

using namespace std;

template <class T, class Comp>
void Sort(vector<T> & arr, Comp const& comp)
{
	size_t n = arr.size();
	for (size_t i = 0; i < n - 1; i++)
	{
		for (size_t j = n - 1; i < j; j--)
		{
			if (comp(arr[j], arr[j - 1]))
			{
				swap(arr[j - 1], arr[j]);
			}
		}
	}
}


int main()
{
	vector<string> strings = {
		"nyash", "myash",
		"crimea", "is", "ours"
	};

	Sort(strings, [](const string& lhs, const string& rhs){
		return lhs.length() < rhs.length();
	});

	copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, " "));

	cout << endl;
	vector<int> numbers = { 1, 5, 2, -4, -6, 3, -5, 3, 8, 9, 4, 3 };
	Sort(numbers, [](int lhs, int rhs){

		bool lhsIsEven = (abs(lhs) % 2 == 0);	
		int result = (abs(lhs) % 2) - (abs(rhs) % 2);

		if (result != 0)
		{
			return result < 0;
		}
		else if (lhsIsEven) // right is even too
		{
			return lhs < rhs;
		}
		else // both are odd
		{
			return rhs < lhs;
		}
	});

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));

	cout << endl;

}