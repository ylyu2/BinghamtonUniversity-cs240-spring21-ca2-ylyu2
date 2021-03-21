

#include <sstream>
#include <vector>
#include "song.h"

string command_list[7] = {"select","add","remove","show","clone","import","exit"};

int command_analysis(string command, vector<string> commandList)
{
	string tmp[10];
	string temp;
	int count = 0;
	int is_corect = 0;
	stringstream input;
	input << command;
	while (input >> temp)
	{
		tmp[count] = temp;
		commandList.push_back(temp);
		count++;
	}

	for (int i = 0; i < 7; i++)
	{
		if (tmp[0] == command_list[i])
		{
			is_corect = 1;
			break;
		}
	}
	return is_corect;

}

int main()
{
	string command;
	int code;
	Music music;

	cout << "please create a library" << endl;
	cout << "press e for exit, press add for add new song, press dis for display all information of songs" << endl;
	while (command != "exit")
	{
		getline(cin, command);
		if (command == "add")
		{
			Song temp;
			temp.Add();
			music.library_m.Add_song(temp);
		}
		else if (command == "dis")
		{
			music.library_m.Show_songs();
		}
		else
		{
			cout << "please input the correct command!" << endl;
		}
	}
	string name;
	PlayList tmp;
	cout << "please create a PlayList" << endl;
	cout << "press a name for PlayList:" << endl;
	cin >> name;
	tmp.name_m = name;
	music.Add_List(tmp);
	
	cout << "please create another PlayList" << endl;
	cout << "press a name for PlayList:" << endl;
	cin >> name;
	tmp.name_m = name;
	music.Add_List(tmp);

	command = "";
	vector<string> commandList;
	while (command != "exit")
	{
		cout << "please input your command: " << endl;
		getline(cin,command);
		code = command_analysis(command,commandList);
		if (code >= 0)
		{
			if (commandList[0] == "add")
			{
				if (commandList.size()>2&&commandList[1] == "playlist")//add to the playlist
				{
					int s1 = -1;
					for (int i = 0; i < music.size_m; ++i)
					{
						if (music.playlist_m[i].name_m == commandList[1])
						{
								s1 = i;
						}
					}
					if (s1 >= 0)
					{
						Song temp;
						temp.Add();
						music.playlist_m[s1].Add_song(temp);
					}
				}
				if (commandList.size() == 1||commandList[1] == "library")//add to the library
				{
					Song temp;
					temp.Add();
					music.library_m.Add_song(temp);
				}
			}
			else if (commandList[0] == "remove")
			{
				if (commandList.size() > 2 && commandList[1] == "playlist")//remove from the playlist
				{
					int s1 = -1;
					for (int i = 0; i < music.size_m; ++i)
					{
						if (music.playlist_m[i].name_m == commandList[1])
						{
							s1 = i;
						}
					}
					if (s1 >= 0)
					{
						Song temp;
						temp.name_m = commandList[2];
						music.playlist_m[s1].Remove_song(temp);
					}
				}
				if (commandList.size() >2 && commandList[1] == "library")//remove from the library
				{
					Song temp;
					temp.name_m = commandList[2];
					music.library_m.Remove_song(temp);
				}
				if (commandList.size() == 2 || commandList[1] != "library")//add to the library
				{
					Song temp;
					temp.name_m = commandList[1];
					music.library_m.Remove_song(temp);
				}
			}
			else if (commandList[0] == "clone")
			{
				if (commandList[1] != " "&&commandList[2] != " ")
				{
					int s1=-1;
					int s2 = -1;
					for (int i = 0; i < music.size_m; ++i)
					{
						if (music.playlist_m[i].name_m == commandList[1])
						{
							s1 = i;
						}
						if (music.playlist_m[i].name_m == commandList[2])
						{
							s2 = i;
						}
						if (s1 >= 0 && s2 >= 0)
						{
							if (s1 != s2)
							{
								music.playlist_m[s1] = music.playlist_m[s2];
							}
						}
					}
				}
			}
			else if (commandList[0] == "show")
			{
				if (commandList[1] == "library")
				{
					music.library_m.Show_songs();
				}
				else if (commandList[1] == "playlist")
				{
					if (commandList[2] != " ")
					{
						for (int i = 0; i < music.size_m; ++i)
						{
							if (music.playlist_m[i].name_m == commandList[2])
							{
								music.playlist_m[i].Show_songs();
							}
						}
					}
				}
			}
			else if (commandList[0] == "import")
			{
				int s1 = -1;
				for (int i = 0; i < music.size_m; ++i)
				{
					if (music.playlist_m[i].name_m == commandList[1])
					{
						s1 = i;
					}
				}
				if (s1 > 2)
				{
					for (unsigned int i = 2; i < commandList.size(); ++i)
					{
						int s2 = -1;
						for (int j = 0; j < music.size_m; ++j)
						{
							if (music.playlist_m[j].name_m == commandList[i])
							{
								s2 = j;
							}
							if (s2 >= 0)
							{
								music.playlist_m[s1] = music.playlist_m[s1] + music.playlist_m[s2];
							}
						}
					}
				}
			}
		}
		else
		{
			cout << "the command is error,please input correct command!" << endl;
		}

	}


	return 0;
}