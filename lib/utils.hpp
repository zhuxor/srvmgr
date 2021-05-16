#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>
#include <vector>

// string-related
void Erase(std::string& str, char c);
bool EndsWith(const std::string& str, const std::string& suffix);
bool StartsWith(const std::string& str, const std::string& prefix);
std::string Format(const std::string format, ...);
std::vector<std::string> Explode(const std::string& what, const std::string& separator);
bool IsWhitespace(char what);
std::string TrimLeft(const std::string& what, bool (callback)(char) = IsWhitespace);
std::string TrimRight(const std::string& what, bool (callback)(char) = IsWhitespace);
std::string Trim(const std::string& what, bool (callback)(char) = IsWhitespace);
std::string ToLower(const std::string& what);
std::string ToUpper(const std::string& what);
unsigned long StrToInt(const std::string& what);
unsigned long HexToInt(const std::string& what);
float StrToFloat(const std::string& what);
bool StrToBool(const std::string& what);
bool CheckInt(const std::string& what);
bool CheckHex(const std::string& what);

bool CheckBool(const std::string& what);
bool CheckFloat(const std::string& what);
bool CheckIP(std::string addr);

// file related
bool FileExists(const std::string& file);
std::string Basename(const std::string& file);
std::string FixSlashes(const std::string& filename);
std::string TruncateSlashes(const std::string& filename);

// directory search
struct DirectoryEntry
{
    std::string name;
};

void _stdcall Printf(const char* format, ...);
std::vector<std::string> ParseSpaceDelimited(std::string message, bool comments = false);

#endif // UTILS_HPP_INCLUDED
