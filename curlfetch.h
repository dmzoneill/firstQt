#ifndef CURLFETCH_H
#define CURLFETCH_H

#include <string>
#include <iostream>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>

using namespace std;

class CurlFetch
{
    private:
        char errorBuffer[CURL_ERROR_SIZE];
        string buffer;
        CURL *curl;
        CURLcode result;
        string m_result;

        static int writer(char *data, size_t size, size_t nmemb, std::string *buffer);

    public:
        CurlFetch();
        string getResult();
};

#endif // CURLFETCH_H
