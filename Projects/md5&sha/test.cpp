#include <iostream>
#include "md5.h"
#include "md5.cpp"
#include "sha1.h"
#include "sha1.cpp"



int main()
{

    SHA1 sha1;

    char buffer[41];

    sha1.SHA_GO("a",buffer);

    printf("%s\n",buffer);

    //sha1调用
//===================================================
    //MD5调用
    std::string str = "abc";

    MD5 md5(str);

    std::string result = md5.md5();

    printf("%s",result.c_str());


    return 0;

}
