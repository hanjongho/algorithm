#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
	int num, count = 0;
	cin >> num;
	while (num >= 5)
	{
		count += num / 5; 
		num /= 5;
	}
	cout << count;
	return 0;
}