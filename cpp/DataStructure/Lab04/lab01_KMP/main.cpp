//STL
#include <iostream>
#include <string>
//C-Standard
#include <cstring>

void getFailure(const std::string & pattern, int * failure) {
    failure[0] = -1;
    /*
    std::size_t j;
    int k = -1;
    codes_in_the_book:_________________________________________
    while(j < pattern.length() - 1) {
        if(k == -1 || pattern[k] == pattern[j]) {
            ++j;
            ++k;
            failure[j] = k;
        } else {
            k = failure[k];
        }
    }
    ___________________________________________________________*/
    /*modified codes: */
    char tmp = pattern[0];
    for(int k = 1; k < int(pattern.length()); ++k) {
        if(failure[k] ==  k - 1 && pattern[k] != tmp) {
            failure[k-1] = -1;
            tmp = pattern[k];
        }
    }
}

/*void getNext(char * p, int * next) {
    int k;
    std::size_t j;
    next[0] = -1;
    j = 0;
    k = -1;
    while(j < strlen(p)-1)
    {
        if(k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            next[j] = k;
        } else {
            k=next[k];
        }
    }
}*/

/*int KMPMatch(char *s,char *p) {
    int next[100];
    std::size_t i = 0;
    int j = 0;
    getNext(p,next);
    while(i < strlen(s))
    {
        if(j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if(j == int(strlen(p)))
            return i - strlen(p);
    }
    return -1;
}*/

int kmp_findFirstPosition(const std::string & ob, const std::string & pattern, std::size_t p = 0) {
    int * f = new int[pattern.length()];
	getFailure(pattern, f);
	std::size_t i = p;
	int j = 0;
	while (i < ob.length() && j < int(pattern.length()) && int(pattern.length()) - j <= int(ob.length() - i))
    if (j == -1 || pattern[j] == ob[i])	{
		++i;
		++j;
    }else {
		j = f[j];
    }
    delete []f;
	if (j < int(pattern.length()))
        return -1;
	else
        return i - j;
}

/*SeqList<int> compute_prefix_function(const std::string & pattern) {
    int m = int(pattern.length());
    SeqList<int> next(m);
    next[0] = -1;
}
*/

/*void write(const std::string & str) {
	std::cout << str << std::endl;
}*/

int main()
{
	std::string ob("this is a string");
	std::string pattern("is");
	std::cout << "ob is: " << ob  << std::endl;
	std::cout << "pattern is: "  << pattern << std::endl;

	std::cout << std::endl << "Find the pattern from the beginning of ob: " ;
	std::cout << kmp_findFirstPosition(ob, pattern) << std::endl;

	std::cout << "Find the pattern from the 3rd position of ob: " ;
	std::cout << kmp_findFirstPosition(ob, pattern, 3) << std::endl;

	pattern = "string";
	std::cout << "Change the pattern as \"string\". Find the pattern from the beginning of ob: " ;
	std::cout << kmp_findFirstPosition(ob, pattern) << std::endl;

	pattern = "this";
	std::cout << "Change the pattern as\"this\". Find the pattern from the beginning of ob: " ;
	std::cout << kmp_findFirstPosition(ob, pattern) << std::endl;

	std::cout << "Change the pattern as\"this\". Find the pattern from the 1st position of ob: " ;
	std::cout << kmp_findFirstPosition(ob, pattern, 1) << std::endl;

	pattern = "that";
	std::cout << "Change the pattern as\"that\". Find the pattern from the beginning of ob: " ;
	std::cout << kmp_findFirstPosition(ob, pattern) << std::endl;

	pattern = "this is a string!";
	std::cout << "Change the pattern as\"this is a string!\". Find the pattern from the beginning of ob: " ;
	std::cout << kmp_findFirstPosition(ob, pattern) << std::endl;

	pattern = ob;
	std::cout << "Change the pattern as\"this is a string\". Find the pattern from the beginning of ob: " ;
	std::cout << kmp_findFirstPosition(ob, pattern) << std::endl;
    std::cout << std::endl;
    /*---------------------------------------------------------------------*/
    //test1:
    std::string ob1("aaaaaaabacbb");
    std::string pattern1("abac");
    std::cout << "Find " << pattern1 << " in " << ob1 << " : " << kmp_findFirstPosition(ob1, pattern1) << std::endl;
    //test2:
    std::string ob2("aaaaaaaaaaaaaa");
    std::string pattern2("aaaaaaab");
    std::cout << "Find " << pattern2 << " in " << ob2 << " : " << kmp_findFirstPosition(ob2, pattern2) << std::endl;
    //test3:
    std::string ob3("AAAAAAAAAAaaaaa");
    //if the pattern is "AAAaaa" kmp_find return -1,there is sth. wrong
    std::string pattern3("AAaaa");
    std::cout << "Find " << pattern3 << " in " << ob3 << " : " << kmp_findFirstPosition(ob3, pattern3) << std::endl;

    return 0;
}
