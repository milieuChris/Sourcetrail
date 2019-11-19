#include "JavaPathDetectorWindows.h"

#include <QSettings>
#include <QSysInfo>

#include "FilePath.h"
#include "utilityApp.h"

JavaPathDetectorWindows::JavaPathDetectorWindows(const std::string javaVersion)
	: JavaPathDetector("Java " + javaVersion + " for Windows", javaVersion)
{
}

std::vector<FilePath> JavaPathDetectorWindows::getPaths() const
{
	QString key = "HKEY_LOCAL_MACHINE\\SOFTWARE\\";

	if (utility::getApplicationArchitectureType() == APPLICATION_ARCHITECTURE_X86_32)
	{
		key += "Wow6432Node\\";
	}

	key += ("JavaSoft\\Java Runtime Environment\\" + m_javaVersion).c_str();

	QSettings expressKey(
		key, QSettings::NativeFormat);	  // NativeFormat means from Registry on Windows.
	QString value = expressKey.value("RuntimeLib").toString();

	FilePath path(value.toStdWString());

	std::vector<FilePath> paths;
	if (path.exists())
	{
		paths.push_back(path);
	}
	return paths;
}
