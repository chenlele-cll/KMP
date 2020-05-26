#include<iostream>
#include<vector>
#include<string>
using namespace std;
int IndexOfSubstrkmp(string raw_str, string sub_str)
{
	vector<int> next(sub_str.size(),0);
	int j = 0;
	int i = 1;
	next[0] = 0;
	while(i!=sub_str.size())
	{
		if (sub_str[i] == sub_str[j])
		{
			next[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j != 0)
				j = next[j - 1];
			else
			{
				next[i] = 0;
				i++;
			}
		}
	}
	for (int k = 0; k < sub_str.size(); k++)
	{
		cout << next[k] << " ";
	}
	i = 0;
	j = 0;
	while (i < raw_str.size() && j < sub_str.size())
	{
		if (raw_str[i] == sub_str[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
				j = next[j - 1];
			i++;
		}
	}
	if (j == sub_str.size())
	{
		return i - j;
	}
	else return -1;
}

int IndexOfSubstr(const char* const raw_str, const char* const sub_str)
{
	int sublength = 0;
	for (int i = 0; sub_str[i] != '\0'; i++)
	{
		sublength++;
	}
	vector<int> next(sublength, 0);
	int i = 1;
	int j = 0;
	while (sub_str[i] != '\0')
	{
		if (sub_str[i] == sub_str[j])
		{
			next[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = next[j - 1];
			}
			else
			{
				next[i] = 0;
				i++;
			}
		}
	}
	i = 0;
	j = 0;
	while (sub_str[j] != '\0'&&raw_str[i] != '0')
	{
		if (sub_str[j] == raw_str[i])
		{
			j++;
			i++;
		}
		else
		{
			if (j != 0)
				j = next[j - 1];
			else
				i++;
		}
	}
	if (sub_str[j] == '\0')
	{
		return i - j;
	}
	else
		return -1;
}
int main()
{
	//string substr = "tegri";
	//string str = "Integrity Procative Collaboration Innovation";
	const char *str= "Integrity Procative Collaboration Innovation";
	const char *substr = "Collaboration";
	int res = IndexOfSubstr(str, substr);
	cout << res << endl;
	system("pause");
	return 0;
}