#include "renew.h"

#pragma warning(disable:4503)

using namespace std;

void tryDelete(string file, bool xml, int repeated = 0)
{
	if (repeated > 100)
	{
		if (xml)
		{
			WarningMessage(1009, file);
		}
		else
		{
			WarningMessage(1006);
		}
	}

	if (!boost::filesystem::remove(file))
	{
		tryDelete(file, xml, repeated + 1);
	}
}

bool DeleteFileFolder(string directory, string file, bool xml)
{
	if (boost::filesystem::is_directory(directory + file))
	{
		string tempbehavior = directory + file;
		vecstr filelist;
		read_directory(tempbehavior, filelist);
		tempbehavior.append("\\");

		for (auto& curfile : filelist)
		{
			DeleteFileFolder(tempbehavior, curfile, xml);
		}
	}

	tryDelete(directory + file, xml);
	return true;
}

void ClearTempBehaviors()
{
	vecstr filelist;
	string tempbehavior = "temp_behaviors";

	if (isFileExist(tempbehavior) && boost::filesystem::is_directory(tempbehavior))
	{
		read_directory(tempbehavior, filelist);
		tempbehavior.append("\\");

		for (auto& file : filelist)
		{
			if (!boost::iequals(file, "xml"))
			{
				DeleteFileFolder(tempbehavior, file, false);
			}
		}
	}
}

void ClearTempXml()
{
	vecstr filelist;
	string tempbehavior = "temp_behaviors\\xml";

	if (isFileExist(tempbehavior) && boost::filesystem::is_directory(tempbehavior))
	{
		read_directory(tempbehavior, filelist);
		tempbehavior.append("\\");

		for (auto& file : filelist)
		{
			DeleteFileFolder(tempbehavior, file, true);
		}
	}
}
