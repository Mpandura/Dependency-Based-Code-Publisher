#include"DependencyAnalyzer.h"
#include "./../Parser/ConfigureParser.h"
#include <vector>
#include <string>


bool DependencyAnalyzer::DependencyAnalyse(std::string fileSpec)
{
	pLookupTable = nullptr;//creating parser	
						   // First create a parser
	ConfigParseToConsole configure;
	Parser* pParser = configure.SecondPassBuilt(pMergedTable);

	try
	{
		if (pParser)
		{
			if (!configure.Attach(fileSpec))
			{
				std::cout << "\n  could not open file " << fileSpec << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "\n\n  Parser not built\n\n";
			return false;
		}
		// now that parser is built, use it
		while (pParser->next())
			pParser->parse();
		std::cout << "\n";
	}
	catch (std::exception& ex)
	{
		std::cout << "\n\n    " << ex.what() << "\n\n";
		return false;
	}


	//Type table is ready fro a file.
	//  getting type table.

	pLookupTable = configure.getDepPair();


	return true;

}