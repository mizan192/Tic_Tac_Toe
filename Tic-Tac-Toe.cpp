#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
void dispGrid();
void interface();
void exitScr();
void howto();
void scr();
void init();
bool isValid();
ll fix_mod(ll a, ll b)
{
	return (a % b + b) % b;
}
void fastio()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
}
void scr()
{
	fflush(stdout);
	system("cls");
}
string p1, p2;
map<string, int> mp;
vector<string> v;
map <int, pair<int, int>> mp2;
char a[15][15] =
{
	{' ', ' ', '1', ' ', ' ', ' ', '2', ' ', ' ', ' ', '3', ' ', ' '},
	{' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
	{' ', '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-', ' '},
	{'4', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '5'},
	{' ', '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-', ' '},
	{' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
	{' ', ' ', '6', ' ', ' ', ' ', '7', ' ', ' ', ' ', '8', ' ', ' '}
}, b[15][15] = {
	{' ', ' ', '1', ' ', ' ', ' ', '2', ' ', ' ', ' ', '3', ' ', ' '},
	{' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
	{' ', '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-', ' '},
	{'4', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '5'},
	{' ', '-', '-', '-', '|', '-', '-', '-', '|', '-', '-', '-', ' '},
	{' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' '},
	{' ', ' ', '6', ' ', ' ', ' ', '7', ' ', ' ', ' ', '8', ' ', ' '}
};
void interface()
{
	scr();

	//welcome interface
	cout << "!........Welcome to Tic-Tac-Toe........!\n"
	     << "!             1. Play                  !\n"
	     << "!             2. How to Play?          !\n"
	     << "!             3. Exit                  !\n"
	     << "!......................................!\n\n"
	     << "Please enter your choice : ";
}
void init()
{
	mp2[0] = {4, 6};
	mp2[1] = {2, 2};
	mp2[2] = {2, 6};
	mp2[3] = {2, 10};
	mp2[4] = {4, 2};
	mp2[5] = {4, 10};
	mp2[6] = {6, 2};
	mp2[7] = {6, 6};
	mp2[8] = {6, 10};

}
void exitScr()
{
	scr();
	cout << "!........................................!\n"
	     << "!           Thanks for playing           !\n"
	     << "!........................................!\n\n";
	return;
}
void howto()
{
	scr();
	cout << "!........................................................!\n"
	     << "!           Just enter the cell number in                !\n"
	     << "!           which you want to place your                 !\n"
	     << "!           move. Enter 'r' key to return.               !\n"
	     << "!........................................................!\n\n";
	char c;
	cin >> c;
	if (c == 'r')
		interface();
	else
		howto();
}
void playerinfo()
{
	cout << "Enter the name of player 1 : ";
	cin >> p1;
	cout << "\nEnter the name of player 2 : ";
	cin >> p2;
	cout << "\n\nWelcome " << p1 << " & " << p2 << "!!!\n\nEnter 'c' to continue.\n";
	char c;
	cin >> c;
	v.pb(p1);
	v.pb(p2);
	if (c == 'c')
		return;
}
void dispGrid()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
	cout << "The middle cell is 0th.\n";
}
void init2()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
bool isValid(int x, int y, int z)
{
	return z >= 0 && z < 9 && a[x][y] != 'O' && a[x][y] != 'X';
}
bool win()
{
	if (a[2][2] == a[4][2] && a[4][2] == a[6][2] && a[2][2] != ' ')
		return 1;
	if (a[6][2] == a[6][6] && a[6][10] == a[6][6] && a[6][6] != ' ')
		return 1;
	if (a[2][2] == a[2][6] && a[2][10] == a[2][2] && a[2][2] != ' ')
		return 1;
	if (a[2][10] == a[4][10] && a[6][10] == a[4][10] && a[6][10] != ' ')
		return 1;
	if (a[2][10] == a[4][6] && a[6][2] == a[2][10] && a[2][10] != ' ')
		return 1;
	if (a[2][2] == a[4][6] && a[6][10] == a[2][2] && a[2][2] != ' ')
		return 1;
	if (a[4][2] == a[4][6] && a[4][6] == a[4][10] && a[4][10] != ' ')
		return 1;
	else
		return 0;
}
int main()
{
top:
	interface();
	init();
	int choice;
	cin >> choice;
	if (choice == 2)
	{
		howto();
	}
	if (choice == 3)
	{
		exitScr();
		return 0;
	}
	if (choice == 1)
	{
		scr();
		playerinfo();
		dispGrid();
		ll cnt = 0, num = -1;
		bool f = 0;
		while (cnt < 9 && f == 0)
		{
			int cell_no;
			if (cnt % 2 == 0)
			{
				scr();
				dispGrid();
				cout << endl << endl;
				cout << p1 << "'s move (O)\nEnter the cell number : ";
				cin >> cell_no;
				ll x = mp2[cell_no].ff;
				ll y = mp2[cell_no].ss;
				while (!isValid(x, y, cell_no))
				{
					cout << "Invalid move.\nEnter again : ";
					cin >> cell_no;
					x = mp2[cell_no].ff;
					y = mp2[cell_no].ss;
				}
				a[x][y] = 'O';
				if (cnt > 2)
				{

					f = win();
					num = 1;
				}
				cnt++;
				if (f == 0)
					num = -1;
			}
			else
			{
				scr();
				dispGrid();
				cout << endl << endl;
				cout << p2 << "'s move (X)\nEnter the cell number : ";
				cin >> cell_no;
				ll x = mp2[cell_no].ff;
				ll y = mp2[cell_no].ss;
				while (!isValid(x, y, cell_no))
				{
					cout << "Invalid move.\nEnter again : ";
					cin >> cell_no;
					x = mp2[cell_no].ff;
					y = mp2[cell_no].ss;
				}
				a[x][y] = 'X';
				if (cnt > 2)
				{

					f = win();
					num = 2;
				}
				cnt++;
				if (f == 0)
					num = -1;

			}

		}
		scr();
		if (num == 1)
			cout << "Congratulations " << p1 << "!!! You won.....!!" << endl;
		else if (num == 2)
			cout << "Congratulations " << p2 << "!!! You won.....!!" << endl;
		else
			cout << "Draw.\n";
		cout << endl << endl;
		dispGrid();
		cout << "\n\n\nEnter 'r' to return to main menu.\n\n";
		char ch;
		cin >> ch;
		init2();
		while (ch != 'r')
		{
			cout << "Please enter 'r' to return to main menu.\n\n";
			cin >> ch;
		}
		goto top;
	}
	else
	{
		cout << "\n\nPlease Enter a valid key.\nPress 'b' to go back.\n\n";
		char ch;
		while (ch != 'b')
		{
			cout << "Please Enter 'b'\n";
			cin >> ch;
		}
		goto top;
	}
}
