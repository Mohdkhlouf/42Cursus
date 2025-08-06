#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>

class HttpRequests{
	private:
		std::unordered_map<std::string, std::string> header;
		std::string requestString;
		std::string requestLine;
		std::string requestHeader;
		std::string requestBody;

	public:
		HttpRequests();
		// HttpRequests(const HttpRequests &obj);
		// HttpRequests operator=(const HttpRequests &obj);
		~HttpRequests();
		HttpRequests &httpParser(const std::vector<char> &request);
};