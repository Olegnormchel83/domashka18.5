#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	int Points;
	string Name;

public:
	Player() : Points(0), Name(" ")
	{}

	Player(string Name, int Points)
	{
		this->Points = Points;
		this->Name = Name;
	}

	void SetPoints(int Points)
	{
		this->Points = Points;
	}

	void SetName(string Name)
	{
		this->Name = Name;
	}

	int GetPoints()
	{
		return Points;
	}

	string GetName()
	{
		return Name;
	}

	void ShowInfo()
	{
		cout << "\nPlayer Name: " << Name << endl;
		cout << "     Points: " << Points << endl;
	}
};

void BubbleSort(Player* PlayersList, int size);

int main()
{
	cout << "Enter a number of players: ";
	int CountPlayers;
	cin >> CountPlayers;

	Player* Players = new Player[CountPlayers];

	for (int i = 0; i < CountPlayers; i++)
	{
		string UserInputName = "";
		int UserInputPoints = 0;

		cout << "Enter the " << i+1 << " player name: ";
		cin >> UserInputName;
		Players[i].SetName(UserInputName);

		cout << "Enter the " << i+1 << " player points: ";
		cin >> UserInputPoints;
		Players[i].SetPoints(UserInputPoints);
	}

	BubbleSort(Players, CountPlayers);

	cout << "Top players:\n";
	for (int i = 0; i < CountPlayers; i++)
	{
		Players[i].ShowInfo();
	}

	delete[] Players;
	Players = nullptr;
	return 0;
}

void BubbleSort(Player* PlayersList, int size)
{
	bool notSorted = true;

	while (notSorted)
	{
		notSorted = false;
		for (int i = 0; i + 1 < size; i++)
		{
			if (PlayersList[i + 1].GetPoints() > PlayersList[i].GetPoints())
			{
				swap(PlayersList[i], PlayersList[i + 1]);
				notSorted = true;
			}
		}
	}
}