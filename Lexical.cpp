#include <bits/stdc++.h>

using namespace std;
string s;
bool isKeyWord(string s)
{
    if (s == "if" or s == "else" or s == "while" or s == "do"
        or s == "for" or s == "switch" or s == "case" or s == "class"
        or s == "auto" or s == "break" or s == "continue" or s == "char"
        or s == "string" or s == "int" or s == "float" or s == "double"
        or s == "long" or s == "default" or s == "goto" or s == "friend")
        return true;
    else return false;
}
bool isOp(string s)
{
    if (s == "<" or s == ">" or s == "+" or
        s == "-" or s == "/" or s == "*" or
        s == "!=" or s == ">=" or s == "<="
        or s == "=")
            return true;
    else return false;
}
bool isPunc(string s)
{
    if (s == ";" or s == "," or s == "(" or s == ")"
        or s == "{" or s == "}" or s == "[" or s == "]")
            return true;
    else return false;
}
bool isNum(string s)
{
    if (isdigit(s[0])) return true;
    else return false;
}
vector<pair<string,string>>analyze(string s)
{
    vector<pair<string,string>>ans;
    string x = "";
    int l = 0;
    while (l <= s.size())
    {
        if (s[l] != ' ')
        {
            x += s[l];
            l++;
        }
        else
        {
            if (isPunc(x))
            {
                ans.emplace_back(make_pair(x,"punctuator"));
            }
            else if (isOp(x))
            {
                ans.emplace_back(make_pair(x,"operator"));
            }
            else if (isNum(x))
            {
                ans.emplace_back(make_pair(x,"number"));
            }
            else if (isKeyWord(x))
            {
                ans.emplace_back(make_pair(x,"key word"));
            }
            else
            {
                ans.emplace_back(make_pair(x,"identifier")) ;
            }

            x = "";
            l++;
        }
    }
            return ans;
        }



int main()
{
    s = "int x = 3 ; ";
    vector<pair<string,string>>vec = analyze(s);
    for (auto it:vec)
    {
        cout<<it.first<<": "<<it.second<<endl;
    }
}
