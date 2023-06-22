#pragma once

#include "ConverterJson.h"

#include <iomanip>
#include <fstream>
#include <sstream>
#include <boost\algorithm\string.hpp>
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

class InvertedIndex 
{
public:




	ConverterJson cj;
	
	
	void createJsonReport();
	void accesToDocs();
	vector<string> words;
	//vector<int, vector<string>> result;
	void showWords();
	void compileData();
};