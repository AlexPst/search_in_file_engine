#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

struct Entry
{
	size_t doc_id, count;
};

class ConverterJson {

public:
	ConverterJson() = default;

	void createConfJson();
	void createRequestDoc();
	map<string, string> GetRequests();
	map<int, vector<string>>requests;
	vector<string> getPaths();
	vector<string> GetTextDocuments();

	int GetResponsesLimit();

	

	//void putAnswers(vector<vector<pair<int, float>>> answers);

private:
	//vector<string> requests;
	vector<string>paths;
	
};