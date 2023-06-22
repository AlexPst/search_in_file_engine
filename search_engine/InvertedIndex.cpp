#include "include/InvertedIndex.h"

using namespace std;

struct Datas
{
	int numStr;
	map<string, int>requests;
	int relev;

};



void InvertedIndex::accesToDocs()
{
	string path = "C:/src/search_engine/out/build/x64-debug/resourses/file001.txt";
	ifstream file(path);
	//vector <string> v;
	string findWords;
	//vector<string> words;
	/*for (auto& it : convJ.GetRequests()) 
	{
		words.push_back(it.second);
	}*/
	int pos = 0;
	int lenght = findWords.length();
	string word;
	if (file.is_open())
	{
		cout << "file is open!" << endl;
		//stringstream buffer;
		//buffer << file.rdbuf();
		//string text = buffer.str();
		//cout << text << endl;
		//string showRes;

		//while ((pos = text.find(words[0], pos)) != string::npos)
		//{
		//	for (int i = 0; i < words[0].length(); ++i)
		//	{
		//		showRes += text[pos + i];
		//	}
		//	//cout << pos << endl;
		//	//cout << showRes << endl;
		//	//showRes = "";
		//	pos += words[0].length();
		//}

		while (getline(file, word)) 
		{
			
				words.push_back(word);
			 
		}
		/*while (file >> word) 
		{
			if (word == "\n") 
			{
				string space = "\n";
				words.push_back(space);
			}
			words.push_back(word);
		}*/

		
	}
	else 
	{
		cout << "file is not open!"<<endl;
	}
	

	
}

void InvertedIndex::showWords()
{
	/*for (auto& it : words)
	{
		cout << it;
		
	}*/
	cout << endl;
	/*for (auto& it : cj.GetRequests()) 
	{
		cout << it.first<< " " << it.second << endl;
	}*/
	
	cout << words[0];
	//cout << count;
}


void InvertedIndex::createJsonReport() 
{
	string str;
	
	//json docReportJson;
	ofstream file("report.txt");
	for (auto& it : cj.GetRequests()) 
	{
		str += "Word " + it.second + " ";
	}
	cout << str << endl;
	//docReportJson = {"String ", str};

	//file << setw(4) << docReportJson << endl;
	//cout << setw(4) << docReportJson;
}

void InvertedIndex::compileData()
{
	vector <Datas> reports;
	vector <string> reqWords;
	int count = 0;
	int i = 0;
	ifstream reqFile("requests.json");
	json reqJson;
	string elem;
	if (reqFile.is_open())
	{
		try
		{
			reqFile >> reqJson;
			
				for (auto& it : reqJson.at("requests"))
				{
					elem = it.at("request");
					reqWords.push_back(elem);
				}
			
		}
		catch (exception const& ex)
		{
			cout << ex.what() << endl;
		};
	};
	for (auto& it : reqWords) 
	{
		cout << it << endl;
	}

	
	vector <Datas> datas;
	
	 
	for (int i = 0; i < reqWords.size(); ++i) 
	{
		Datas data;
		data.numStr = i;
		string s(reqWords[i]);
		boost::split(data.requests, s, boost::is_any_of(" "));
		
		for (auto& it : data.requests) 
		{

		}



		datas.push_back(data);
		
	}

}

