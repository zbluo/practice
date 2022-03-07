#include <iostream>
#include <vector>
#include <iomanip>
#include <openssl/obj_mac.h>
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/bn.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/x509.h>
#include <openssl/ossl_typ.h>
#include <openssl/pem.h>
#include <openssl/pkcs7.h>
#include <openssl/asn1.h>
#include <fstream>
//#include <boost/filesystem.hpp>
#include <queue>
#include <future>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>

#include "openssl_test.h"
#include "test1.h"

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <math.h>
#include <sys/mman.h>
using namespace std;
class Solution {
public:
    unordered_set<string> result;
    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return vector<string>(result.begin(), result.end());
    }

    void helper(string s, int pos) {
        if(pos == s.size()) {
            result.insert(s);
            return;
        }

        for(int i = pos; i < s.size(); i++) {
            helper(s, pos + 1);
            if(isLetter(s[i])) {
                s[i] = convert(s[i]);
                helper(s, pos + 1);
            }
        }
    }

    bool isLetter(char c) {
        return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
    }

    char convert(char c) {
        if((c >= 'a') && (c <= 'z'))
            return c + ('A' - 'a');
        return c + ('a' - 'A');
    }
};
int main( ) {
    Solution s;
    auto result = s.letterCasePermutation("NzbNMZD2");
    for(auto r : result)
        cout << r << endl;
}