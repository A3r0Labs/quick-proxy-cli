#include <cpr/cpr.h>
#include <iostream>
#include <string>

using namespace std;

/*
* Uses api.proxyscrape.com
*/

int main(int argc, char** argv) 
{
    // BASE URL
    string uri = "https://api.proxyscrape.com/v2/?request=getproxies";

    // CHECK ARGS
    if (argc < 2) {
        // SHOW USAGE THEN RETURN
        cout << "[quick-proxy-cli] Invalid arguments!" << endl
             << "Usage: quick-proxy-cli \"&protocol=http&timeout=9000&country=all&ssl=all&anonymity=all&simplified=true\"" << endl;
        return 1;
    }

    // CAST THE INPUT/BASE URL TO STRING THEN CAT WITH BASE URL
    string userQuery(argv[1]);
    uri += userQuery;
    cout << uri;

    // MAKE OUR REQUEST - CPP REQUESTS
    cpr::Response r = cpr::Get(cpr::Url{ uri });

    // PRINT THE PROXIES TO STDOUT
    cout << r.text;

    return 0;
}