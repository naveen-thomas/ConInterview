#include <iostream>
#include<fstream>
#include <string>
#include <cstring>
#include <curl/curl.h>

using namespace std;

int ProcessFunc(char* szInput, char* szOutput);

int main()
{
	/*---- curl object ----*/
    CURL* curl;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com/1234");

    /*---- Output the details to log file ----*/
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    FILE *logfile = fopen("dump.txt", "wb");

	curl_easy_setopt(curl, CURLOPT_STDERR, logfile);



    curl_easy_perform(curl);

	fclose(logfile);

	ifstream ifs;
	ifs.open("dump.txt");

	char *pTemp= NULL, *qTemp = NULL, *rTemp = NULL;

	 while(ifs.good())
	 {
	                string sFileLine;
	                getline(ifs,sFileLine);

	                if(string::npos != sFileLine.find("GET"))
	                {
	                        qTemp = strdup(sFileLine.c_str());
	                        r=q;
	                        pTemp = strchr(qTemp,'/');

	                        qTemp = pTemp+1;

	                        while(*pTemp != ' ')
	                        pTemp++;

	                        *pTemp = '\0';
	                }
	   }

	   ifs.close();

	 //cout << q << endl;

	 /*---- Process the number to get the actual return message ----*/

	     char szRetMsg[1024];
	     ProcessFunc(q,szRetMsg);

	        // cout << szRetMsg << endl;

	     char szUrl[2048];
	     memset(szUrl,0,2048);

	     sprintf(szUrl,"http://www.example.com/%s",szRetMsg);

	     logfile = fopen("dump.txt", "wb");

	     curl_easy_setopt(curl, CURLOPT_URL, szUrl);
	     curl_easy_setopt(curl, CURLOPT_STDERR, logfile);
	     curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
	     curl_easy_perform(curl);

	     fclose(logfile);
	     curl_easy_cleanup(curl);
	     curl_global_cleanup();

	     if(NULL != rTemp)
	     	free(rTemp);

	     return 0;
	 }
	 int ProcessFunc(char* szInput, char* szOutput)
	 {

	         /*---- Divisible by 7 ----*/

	         if(!(atoi(szInput) % 7))
	         {
	                 sprintf(szOutput,"{\"Answer\":\"%c\"}",'C');
	                 return 0;
	         }
	         /*---- Divisible by 9 ----*/
	         if(!(atoi(szInput) % 9))
	         {
	                 sprintf(szOutput,"{\"Answer\":\"%c\"}",'N');

	                 return 0;

	         }
			 /*---- Divisible by 7 & 9 ----*/
        	if(!(atoi(szInput) % 7) && !(atoi(szInput) % 9))
        	{
                sprintf(szOutput,"{\"Answer\":\"%c%c\"}",'C','N');

                return 0;

        	}
        	sprintf(szOutput,"{\"Answer\":\"%s\"}",szInput);

       		 return 0;

}