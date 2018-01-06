#pragma once
#ifndef DEPENDENCY_ANALYZER
#define DEPENDENCY_ANALYZER
/////////////////////////////////////////////////////////////////////
//  DependencyAnalyzer.h -  To find the dependency between files   //
//  ver 1.0                                                        //
//  Language:      C++ Visual Studio 2015                          //
//  Application:    CSE687 Pr3                                     //
// Author:      Brahmachaitahnya Sadashiva, Syracuse University(CE)//
//              bsadashi@syr.edu                                   // 
/////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This Module helps to find the dependency between files

Public Interface:
=================
analyze()

Build Process:
==============
Required files
TypeTable.h,Typetable.cpp,DependencyAnalyzer.cpp
Build commands
- devenv DependencyAnalyzer.sln

Maintenance History:
====================
Version 1.0
April 5-2016
*/

#include <unordered_map>
#include <vector>		
#include <string>
#include "./../TypeTable/TypeTable.h"
#include"../Analyzer/TypeTable.h"

class DependencyAnalyzer {

public:

	std::pair<std::string, std::vector<std::string>>* pLookupTable = nullptr;
	TypeTable<TypeTableValue>* pMergedTable; //merged table
	DependencyAnalyzer(TypeTable<TypeTableValue>* pFinalTable) : pMergedTable(pFinalTable) {
		std::pair<std::string, std::vector<std::string>>* pLookupTable = nullptr;
		pLookupTable = new std::pair<std::string, std::vector<std::string>>; //lookup table with all types
	}
	bool DependencyAnalyse(std::string fileSpec);
};
#endif




