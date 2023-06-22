#include "include/ConverterJson.h"
#include "include/json.hpp"
#include <fstream>


using json = nlohmann::json;
using namespace std;



void ConverterJson::createConfJson()
{
	json configDoc =
	{
		{"config", {
			{"name", "SkillboxSearchEngine"},
			{"version", 0.1},
			{"max_responses", 5}
			}
		}
		
	};

	configDoc["files"] = { "../resources/file001.txt", "../resources/file002.txt", "../resources/file003.txt" };

	

	cout << setw(4) << configDoc << endl;

	

	for (auto& it : configDoc.at("files"))
	{
		paths.push_back(it);
	}
	for (auto& it : paths)
	{
		cout << it << endl;
	}
	string path = "config.json";
	

	FILE* checkFile;
	checkFile = fopen("config.json", "r");

	
	if (checkFile!=NULL) 
	{
		cout << "File exists" << endl;
	}
	else 
	{
		//file("config.json");
		cout << "creating file" << endl;
		ofstream file("config.json");
		file << setw(4) << configDoc << endl;
	}
	
	
	
}

void ConverterJson::createRequestDoc()
{
	cout << "Please input request: ";
	json reqDoc;
	string req;
	for (int i = 0; i < 5; ++i)
	{
		string id = "request00";
		getline(cin, req);
		id += to_string(i);
		reqDoc["requests"] += { {"id", id}, { "request", req }};
		

	};

	cout << setw(4) << reqDoc << endl;

	ofstream file("requests.json");


	file << reqDoc;

};

map<string, string> ConverterJson::GetRequests()
{

	ifstream requestFile("requests.json");
	vector<string>elems;
	map<string, string> requestsElems;
	string elem;
	
	if (requestFile.is_open()) 
	{
		json requestJson;
		try {
			
			requestFile >> requestJson;
			if (requestJson.is_object()) {
				for (auto& it : requestJson.at("requests"))
				{
					elem = it.at("request");
					elems.push_back(elem);
				}
			
			}
		}
		catch(exception const& ex)
		{
			cout << ex.what() << endl;
		}
		int count = 0;
		for (auto& it : requestsElems) 
		{
			//vector<string>itSecond;
			for (auto it2 : it.second) 
			{
				requests[count].push_back(it.second);
			}
			//cout << it.first<< " "<< it.second << endl;
			
		}

		/*for (auto& it : requests) 
		{
			for (auto& it2 : requests[it.first])
			{
				cout << it.first << " " << it2 << endl;
			}
		}*/
	}

	return requestsElems;
}

vector<string> ConverterJson::getPaths()
{
	return paths;
}
