#include <iostream>
#include <vector>
using namespace std;

#define SIZE 8

int ans = SIZE * SIZE + 100;
int N, M;
char office[8][8];
vector <pair<int, int> > camera;
int camera_x, camera_y;

void fill_east()
{
	int y = camera_y;
	while (y + 1 < M && (office[camera_x][y + 1] != '6'))
	{
		++y;
		if (office[camera_x][y] == '0')
			office[camera_x][y] = '#';
	}
}

void fill_south()
{
	int x = camera_x;
	while (x + 1 < N && (office[x + 1][camera_y] != '6'))
	{
		++x;
		if (office[x][camera_y] == '0')
			office[x][camera_y] = '#';
	}
}

void fill_west()
{
	int y = camera_y;
	while (y - 1 >= 0 && (office[camera_x][y - 1] != '6'))
	{
		--y;
		if (office[camera_x][y] == '0')
			office[camera_x][y] = '#';
	}
}

void fill_north()
{
	int x = camera_x;
	while (x - 1 >= 0 && (office[x - 1][camera_y] != '6'))
	{
		--x;
		if (office[x][camera_y] == '0')
			office[x][camera_y] = '#';
	}
}

void map_cpy(char desc[8][8], char src[8][8])
{
    for (int r = 0; r < N; ++r)
        for (int c = 0; c < M; ++c)
            desc[r][c] = src[r][c];
}

void dfs(int idx)
{
	if (idx == camera.size())
	{
		int tmp = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (office[i][j] == '0')
					tmp++;
		ans = min(ans, tmp);
		return ;
	}

	char save_office[8][8];
	camera_x = camera[idx].first;
	camera_y = camera[idx].second;
	char camera_num = office[camera_x][camera_y];

	if (camera_num == '1')
	{
		for (int i = 0; i < 4; i++)
		{
			map_cpy(save_office, office);
			if (i == 0)
				fill_east();
			else if (i == 1)
				fill_south();
			else if (i == 2)
				fill_west();
			else if (i == 3)
				fill_north();
			dfs(idx + 1);
			camera_x = camera[idx].first;
			camera_y = camera[idx].second;
			map_cpy(office, save_office);
		}
	}
	else if (camera_num == '2')
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				map_cpy(save_office, office);
				fill_east();
				fill_west();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
			else if (i == 1)
			{
				map_cpy(save_office, office);
				fill_north();
				fill_south();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
		}
	}
	else if (camera_num == '3')
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				map_cpy(save_office, office);
				fill_north();
				fill_east();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
			else if (i == 1)
			{
				map_cpy(save_office, office);
				fill_east();
				fill_south();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
			else if (i == 2)
			{
				map_cpy(save_office, office);
				fill_south();
				fill_west();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
			else if (i == 3)
			{
				map_cpy(save_office, office);
				fill_west();
				fill_north();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
		}
	}
	else if (camera_num == '4')
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				map_cpy(save_office, office);
				fill_west();
				fill_north();
				fill_east();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
			else if (i == 1)
			{
				map_cpy(save_office, office);
				fill_north();
				fill_east();
				fill_south();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
			else if (i == 2)
			{
				map_cpy(save_office, office);
				fill_east();
				fill_south();
				fill_west();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
			else if (i == 3)
			{
				map_cpy(save_office, office);
				fill_south();
				fill_west();
				fill_north();
				dfs(idx + 1);
				camera_x = camera[idx].first;
				camera_y = camera[idx].second;
				map_cpy(office, save_office);
			}
		}
	}
	else if (camera_num == '5')
	{
		map_cpy(save_office, office);
		fill_north();
		fill_east();
		fill_south();
		fill_west();
		dfs(idx + 1);
		camera_x = camera[idx].first;
		camera_y = camera[idx].second;
		map_cpy(office, save_office);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> office[i][j];
			if ('6' != office[i][j] && office[i][j] != '0')
				camera.push_back(make_pair(i, j));
		}
	}
	dfs(0);
	cout << ans;
	return (0);
}