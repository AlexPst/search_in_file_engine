#include "include/InvertedIndex.h"

using namespace std;
void InvertedIndex::accesToDocs()
{
	string path = "filesFS/file001.txt";
	ifstream file(path);
	//vector <string> v;
	string findWords;
	vector<string> words;
	for (auto& it : convJ.GetRequests()) 
	{
		words.push_back(it.second);
	}
	int pos = 0;
	int lenght = findWords.length();

	if (file.is_open())
	{
		cout << "file is open!" << endl;
		stringstream buffer;
		buffer << file.rdbuf();
		string text = buffer.str();
		cout << text << endl;
		string showRes;

		while ((pos = text.find(words[0], pos)) != string::npos)
		{
			for (int i = 0; i < words[0].length(); ++i)
			{
				showRes += text[pos + i];
			}
			//cout << pos << endl;
			//cout << showRes << endl;
			//showRes = "";
			pos += words[0].length();
		}
	}
	

	
}
