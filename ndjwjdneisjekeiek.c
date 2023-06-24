/*
https://github.com/OpposedDeception - MIT License Copyrighted
This program was written by Koten okay!
*/

#include <iostream>
#include <cassert>
#include <thread>
#include <string.h>
#include <curl/curl.h>

static void get(const char* link, const char* useragent) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, link);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, useragent);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

static void loopchar(volatile unsigned int range) {
loop:
    static volatile unsigned int i;
    i++;
    printf("[Counting....] = %d\n", i);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (sizeof(range) >= 0) {
        goto loop;
    } else if (0 >= sizeof(range)) {
        std::cout << "An error has occured!" << std::endl;
        exit(-1);
    } else {
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    static void (*numcounter)(volatile unsigned int);
    char cutie[7] = "Wesley";
    int len = strlen(cutie);
    printf("%d\n", len);
    assert(len == 6);
    get("https://google.com/", "Windows10x64/1.0 (compatible; Windows NT 10.0; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.1234.56 Safari/537.36");
    numcounter = loopchar;
    numcounter(-4);
    return 0;
}
