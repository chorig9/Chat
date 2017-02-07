#pragma once
#include <string>

class HashGenerator
{
public:
	std::string generate_hash(const std::string& input, int work_factor = WORK_FACTOR);
	bool check_hash(const std::string& input, const std::string& hash);

private:
	const static int WORK_FACTOR = 14; // between 4 and 31
};