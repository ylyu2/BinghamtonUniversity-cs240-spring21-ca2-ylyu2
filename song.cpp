
#include "song.h"

Song::Song()
{
	name_m = "no";
	writer_m = "no";
	year_m = 0;
	period_m = 0.0;
}

void Song::Add()
{
	cout << "name: ";
	cin >> name_m;
	cout << "writer: ";
	cin >> writer_m;
	cout << "year: ";
	cin >> year_m;
	cout << "period: ";
	cin >> period_m;
}

void Song::List()
{
	cout << "name: " << name_m << " writer: " << writer_m << " year: " << year_m << endl;
}


/////////////////////////////////////////////////////////////////////////////////////////
PlayList::PlayList()
{
	name_m = "no";
	array_m = new Song[PLAYLIST_SIZE];
	capacity_m = PLAYLIST_SIZE;
	size_m = 0;

}

PlayList::~PlayList()
{
	delete[]array_m;
	array_m = NULL;
}

void PlayList::Add_song(Song &input)
{
	for (int i = 0; i < size_m; ++i)
	{
		if (array_m[i].name_m == input.name_m)
		{
			cout << "the song has bee in the playlist!";
			return;
		}
	}
	if (size_m >= capacity_m)
	{
		Extend_capacity();
	}
	array_m[size_m]=input;
	size_m++;
}

void PlayList::Remove_song(Song &input)
{
	if (size_m < 1)
	{
		cout << "the playlist is empty!";
		return;
	}
	int k = -1;
	for (int i = 0; i < size_m; i++)
	{
		if (array_m[i].name_m==input.name_m)
		{
			k = i;
			break;
		}
	}
	if (k >= 0)
	{
		for (int i = k; i<size_m-1; i++)
			array_m[i] = array_m[i+1];

		array_m[size_m].name_m = "no";
		array_m[size_m].name_m = "no";
		array_m[size_m].writer_m = "no";
		array_m[size_m].year_m = 0;
		array_m[size_m].period_m = 0.0;
		size_m--;
	} 
	else
	{
		cout << "the song can not be found in the playlist!";
		return;
	}

}

void PlayList::Show_songs()
{
	for (int i = 0; i < size_m; i++)
	{
		array_m[i].List();
		cout << endl;
	}
}

void PlayList::Extend_capacity()
{
	capacity_m = 2 * capacity_m;
	Song *array_new = new Song[capacity_m];
	for (int i = 0; i < size_m; i++)
	{
		array_new[i] = array_m[i];
	}
	delete[]array_m;
	array_m = array_new;
}


////////////////////////////////////////////////////////////////////////////////////////
Library::Library()
{
	array_m = new Song[LIBRARY_SIZE];
	capacity_m = LIBRARY_SIZE;
	size_m = 0;
}

Library::~Library()
{
	delete[]array_m;
	array_m = NULL;
}

void Library::Add_song(Song &input)
{
	for (int i = 0; i < size_m; ++i)
	{
		if (array_m[i].name_m == input.name_m)
		{
			cout << "the song has bee in the Library!";
			return;
		}
	}
	if (size_m >= capacity_m)
	{
		Extend_capacity();
	}
	array_m[size_m] = input;
	size_m = size_m + 1;
}

void Library::Remove_song(Song &input)
{
	if (size_m < 1)
	{
		cout << "the Library is empty!";
		return;
	}
	int k = -1;
	for (int i = 0; i < size_m; i++)
	{
		if (array_m[i].name_m == input.name_m)
		{
			k = i;
			break;
		}
	}
	if (k >= 0)
	{
		for (int i = k; i<size_m - 1; i++)
			array_m[i] = array_m[i + 1];

		array_m[size_m].name_m = "no";
		array_m[size_m].name_m = "no";
		array_m[size_m].writer_m = "no";
		array_m[size_m].year_m = 0;
		array_m[size_m].period_m = 0.0;
		size_m--;
	}
	else
	{
		cout << "the song can not be found in the Library!";
		return;
	}
}

void Library::Show_songs()
{
	for (int i = 0; i < size_m; i++)
	{
		array_m[i].List();
		cout << endl;
	}
}

void Library::Extend_capacity()
{
	capacity_m = 2 * capacity_m;
	Song *array_new = new Song[capacity_m];
	for (int i = 0; i < size_m; i++)
	{
		array_new[i] = array_m[i];
	}
	delete []array_m;
	array_m = array_new;
}

///////////////////////////////////////////////////////////////////////////////
Music::Music()
{
	playlist_m = new PlayList[LIST_SIZE];
	capacity_m = LIST_SIZE;
	size_m = 0;
}

Music::~Music()
{
	delete []playlist_m;
	playlist_m = NULL;
}


void Music::Extend_capacity()
{
	capacity_m = 2 * capacity_m;
	PlayList *playlist_new = new PlayList[capacity_m];
	for (int i = 0; i < size_m; i++)
	{
		playlist_new[i] = playlist_m[i];
	}
	delete[]playlist_m;
	playlist_m = playlist_new;
}

void Music::Add_List(PlayList &input)
{
	for (int i = 0; i < size_m; ++i)
	{
		if (playlist_m[i].name_m == input.name_m)
		{
			cout << "the playList has bee in the List!";
			return;
		}
	}
	if (size_m >= capacity_m)
	{
		Extend_capacity();
	}
	playlist_m[size_m] = input;
	size_m = size_m + 1;
	cout << size_m << endl;
}

void Music::Remove_List(PlayList &input)
{
	if (size_m < 1)
	{
		cout << "the Play List is empty!";
		return;
	}
	int k = -1;
	for (int i = 0; i < size_m; i++)
	{
		if (playlist_m[i].name_m == playlist_m[i].name_m)
		{
			k = i;
			break;
		}
	}
	if (k >= 0)
	{
		for (int i = k; i<size_m - 1; i++)
			playlist_m[i] = playlist_m[i + 1];

		playlist_m[size_m].name_m = "no";
		playlist_m[size_m].capacity_m = PLAYLIST_SIZE;
		playlist_m[size_m].size_m = 0;
		Song *array_new = new Song[PLAYLIST_SIZE];
		delete[] playlist_m[size_m].array_m;
		playlist_m[size_m].array_m = array_new;
		size_m--;
	}
	else
	{
		cout << "the playlist can not be found in the List!";
		return;
	}
}

void Music::Show_playlist()
{
	for (int i = 0; i < size_m; i++)
	{
		cout << playlist_m[i].name_m << endl;;
	}
}