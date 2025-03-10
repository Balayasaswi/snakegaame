#include<iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;
const int width = 20;
const int height = 20;
int x = width / 2;
int y = height / 2;
int fruitx;
int fruity;
bool gameover = true;
void game()
{
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		cout << "$";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width + 2; j++)
		{
			if (j == 0 || j== width + 1)
			{
				cout << "$";
			}
			
			else if (i == y && j == x)
			{
				cout << "o";
			}
			else if (i == fruity && j == fruitx)
			{
				cout << "f";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
	{
		cout << "$";
	}
}
void food()
{
	fruitx =1+ rand() % (width - 2);
	fruity = 1+rand() % (height - 2);
}
int main()
{
	
	food();

	game();
	while (gameover)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a': 
				x--;
				break;
			case 'd':
				x++;
				break;
			case 'w':
				y--;
				break;
			case 's':
				y++;
				break;
			case 'x':
				gameover = false;
				break;
			 
			}
			if (x <= 0 || x >= width - 1 || y <= 0 || y >= height - 1)
			{
				gameover = false;
			}
			else if (x == fruitx && y == fruity)
			{
				food();
			}
			game();
		}
	}

}