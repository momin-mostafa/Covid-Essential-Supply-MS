#include <iostream>
#include <vector>
std::vector<std::string> split(std::string str, char delimiter)
{
	using namespace std;
	string word = "";
	vector<string> result;
	for (auto x : str)
	{
		if (x == delimiter)
		{
			result.push_back(word);
			word = "";
		}
		else
		{
			word += x;
		}
	}
	result.push_back(word);
	return result;
}
void vector_iterator(std::vector<std::string> list)
{
	using namespace std;
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl; // '\n'
	}

	cout << endl;
}