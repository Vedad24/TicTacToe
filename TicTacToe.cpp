#include <iostream>
using namespace std;

void draw(char[]);
bool isWon(char[]);
void unosX(int&);
void unosO(int&);

int main()
{
	char polja[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	draw(polja);
	
	int i = 0;
	int pozicija = 0;

	do
	{
		do
		{
			unosX(pozicija);

			if (isdigit(int(polja[pozicija - 1])))
			{
				polja[pozicija - 1] = 'X';
				system("CLS");
				draw(polja);
				i++;
				break;
			}
		} while (!isdigit(pozicija));
		if (isWon(polja))
		{
			cout << "Winner is X" << endl;
			break;
		}
		do
		{
			unosO(pozicija);

			if (isdigit(int(polja[pozicija - 1])))
			{
				polja[pozicija - 1] = 'O';
				system("CLS");
				draw(polja);
				i++;
				break;
			}
		} while (!isdigit(pozicija));
		if (isWon(polja))
		{
			cout << "Winner is O" << endl;
			break;
		}
		
		if (i == 9)
		{
			cout << "Draw";
			break;
		}


	} while (i < 9);

	return 0;
}

void unosX(int& pozicija)
{
	do
	{
		cout << "Unesite poziciju za X: ";
		cin >> pozicija;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
		}

	} while (pozicija < 0 || pozicija > 9);
}

void unosO(int& pozicija)
{
	do
	{
		cout << "Unesite poziciju za O: ";
		cin >> pozicija;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
		}

	} while (pozicija < 0 || pozicija > 9);
}

bool isWon(char polja[])
{
	int win[8][3] = { {1,2,3,}, {4,5,6}, {7,8,9}, {1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7} };
	for (int i = 0; i < 8; i++)
	{
		if (polja[win[i][0] - 1] == polja[win[i][1] - 1] && polja[win[i][0] - 1] == polja[win[i][2] - 1])
			return true;
	}
	return false;
}

void draw(char polja[])
{
	cout << polja[0] << " | " << polja[1] << " | " << polja[2] << endl;
	cout << "--|---|--" << endl;
	cout << polja[3] << " | " << polja[4] << " | " << polja[5] << endl;
	cout << "--|---|--" << endl;
	cout << polja[6] << " | " << polja[7] << " | " << polja[8] << endl;

}
