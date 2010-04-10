#include "curlfetch.h"

CurlFetch::CurlFetch()
{
    this->curl = curl_easy_init();

    if (this->curl)
    {
        curl_easy_setopt(this->curl, CURLOPT_ERRORBUFFER, errorBuffer);
        curl_easy_setopt(this->curl, CURLOPT_URL, "http://www.csis.ul.ie/" );
        curl_easy_setopt(this->curl, CURLOPT_HEADER, 0);
        curl_easy_setopt(this->curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, writer);
        curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &buffer);

        result = curl_easy_perform(this->curl);
        curl_easy_cleanup(this->curl);

        if (this->result == CURLE_OK)
        {
            this->m_result = this->m_result + buffer + "\n";
        }
        else
        {
            this->m_result = this->m_result + "Error: ";//[" + this->result + "] - " + errorBuffer;
        }
    }
}


int CurlFetch::writer(char *data, size_t size, size_t nmemb, std::string *buffer)
{

    int result = 0;

    if (buffer != NULL)
    {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }

    return result;
}


string CurlFetch::getResult()
{
    return this->m_result;
}
