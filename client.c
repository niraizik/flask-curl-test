#include <stdio.h>
#include <curl/curl.h>

int main() {
    // printf() displays the string inside quotation
    printf("Hello, World!\n");

    char* msg1 = "{\"aaaa\": 123}";
    char* msg2 = "{\"aaaa\": 456}";

    CURLcode res;
    int result;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL *curl = curl_easy_init();

    // build the https headers
    struct curl_slist *headers = 0;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL,  "http://localhost:3000/api/set-status?home=test" );
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 3000L);

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, msg1);
    res = curl_easy_perform(curl);
    result = res == CURLE_OK;
    if ( !result )
    {
        printf("discovery report to server failed");
    }

    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, msg2);
    res = curl_easy_perform(curl);
    result = res == CURLE_OK;
    if ( !result )
    {
        printf("discovery report to server failed");
    }

    return 0;
}
