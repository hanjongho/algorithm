#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int student[101] = {0,};
	vector<int> photozone;
	int N, recommend, num;

	cin >> N >> recommend;
	for (int i = 0; i < recommend; i++)
	{
		cin >> num;
		if (photozone.size() < N)
		{
			int exist = 0;
			for (int j = 0; j < photozone.size(); j++)
			{
				if (photozone[j] == num)
				{
					student[photozone[j]]++;
					exist = 1;
					break;
				}
			}
			if (exist == 0)
			{
				photozone.push_back(num);
				student[num] = 1;
			}
		}
		else
		{
			int exist = 0;
			for (int j = 0; j < photozone.size(); j++)
			{
				if (photozone[j] == num)
				{
					student[photozone[j]]++;
					exist = 1;
					break;
				}
			}
			if (exist == 0)
			{
				int min = 2000;
				for (int j = 0; j < photozone.size(); j++) 
					if (min > student[photozone[j]])
						min = student[photozone[j]];

				for (int j = 0; j < photozone.size(); j++)
                {
                    if (min == student[photozone[j]])
                    {
                        student[photozone[j]] = 0;
                        photozone.erase(photozone.begin() + j);
                        break;
                    }
                }
				photozone.push_back(num);
				student[num] = 1;
			}
		}
	}	
	sort(photozone.begin(), photozone.end());
	for (int i = 0; i < photozone.size() - 1; i++)
		cout << photozone[i] << " ";
	cout << photozone[photozone.size() - 1];
    return (0);
}