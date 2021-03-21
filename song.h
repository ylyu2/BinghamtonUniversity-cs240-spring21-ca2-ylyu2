
#include <iostream>
#include <string>
using namespace std;

#define LIBRARY_SIZE 1000
#define PLAYLIST_SIZE 1000
#define LIST_SIZE 10

class Song
{

public:
	string name_m;
	string writer_m;
	int year_m;
	double period_m;
public:
	Song();
	void Add();
	void List();
	Song operator=(const Song &input)
	{
		name_m = input.name_m;
		writer_m = input.writer_m;
		year_m = input.year_m;
		period_m = input.period_m;
		return *this;
	}
	bool operator==(const Song &input)
	{
		if (name_m == input.name_m)
			return true;
		else
			return false;
	}
};


class PlayList
{
public:
	Song *array_m;
	string name_m;
	int size_m;
	int capacity_m;
public:
	PlayList();
	~PlayList();
	void Add_song(Song &input);
	void Remove_song(Song &input);
	void Show_songs();
	void Extend_capacity();
	PlayList operator=(const PlayList& input)
	{
		size_m = input.size_m;
		name_m = input.name_m;
		capacity_m = input.capacity_m;
		Song *array_new = new Song[capacity_m];
		
		for (int i = 0; i < size_m; ++i)
		{
			array_new[i] = input.array_m[i];
		}
		delete[]array_m;
		array_m = array_new;
		return *this;
	}
	PlayList& operator+(const PlayList &input)
	{
		capacity_m = capacity_m + input.capacity_m;
		Song *array_new = new Song[capacity_m];
		for (int i = 0; i < size_m; ++i)
		{
			array_new[i] = array_m[i];
		}
		for (int i = 0; i < input.size_m; ++i)
		{
			
			Add_song(input.array_m[i]);
		}
		delete[]array_m;
		array_m = array_new;
		return *this;
	}
	bool operator==(const PlayList &input)
	{
		if (name_m == input.name_m)
			return true;
		else
			return false;
	}

};

class Library
{
public:
	Song *array_m;
	int size_m;
	int capacity_m;
public:
	Library();
	~Library();
	void Add_song(Song &input);
	void Remove_song(Song &input);
	void Show_songs();
	void Extend_capacity();
};


class Music
{
public:
	Library library_m;
	PlayList *playlist_m;
	int capacity_m;
	int size_m;

public:
	Music();
	~Music();
	void Add_List(PlayList &input);
	void Remove_List(PlayList &input);
	void Show_playlist();
	void Extend_capacity();

};




