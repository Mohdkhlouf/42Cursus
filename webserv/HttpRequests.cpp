#include "HttpRequests.hpp"

/*
the request has 3 parts,
request line: is always same structure, the method, target, http version.
			there are 2 spaces seperating them always, and extra space is not correct.
			so it will bad request line if there are extra spaces.
			ex: <method> <path> <version>
request header: always same formate also like <Header-Name>: <Header-Value>
request body: start after an empty line at the end of the header, then
				and ex: {"name":"John","age":30}, and it must match the content type in the header.
(RFC 7230) is strict for more details.
				*/

HttpRequests::HttpRequests():requestString(""){
	
};
		// HttpRequests::HttpRequests(const HttpRequests &obj){};
		// HttpRequests HttpRequests::operator=(const HttpRequests &obj){};
HttpRequests::~HttpRequests(){};


HttpRequests &HttpRequests::httpParser(const std::vector<char> &request){
	// here i convert the vector to a string.
	std::string requestString(request.begin(),request.end()) ;	
	std::cout<<"String from vector:\n"<<requestString<<std::endl;


	//extracting the request line:
	size_t pos;
	pos = requestString.find("\r\n");
	requestLine = requestString.substr(0,pos);
	requestString.erase(0,pos+2);
	std::cout<< requestLine<< std::endl;
	std::cout<< "########################"<< std::endl;
	std::cout<< requestString<< std::endl;

return(*this);

}