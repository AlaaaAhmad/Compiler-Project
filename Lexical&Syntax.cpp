#include <bits/stdc++.h>

using namespace std;
string s;
bool isDataType(string &s)
{
    return (s == "int" or s == "double"
            or s == "string" or s == "char"
            or s == "long" or s == "short");
}
bool parseDecAssignment(vector<pair<string,string>>&leximes, int pos)
{
    //if (pos == leximes.size()) return true;
    // Rule: <type> <identifier> [= <expression>] ;
    if (isDataType(leximes[pos].first))
    {
        pos++;
        if (leximes[pos].second == "identifier")
        {
            pos++;
            if (leximes[pos].first == "=")
            {
               pos++;
               if (leximes[pos].second == "number")
               {
                   pos++;
                    if (leximes[pos].first == ";")
            {
                pos++;
                return true;
            }
            else
            {
                cout<<"Error: Expected ; at the end of the sentence"<<endl;
                return false;
            }
               }
               else
               {
                   cout<<"Error: Expected a number after assignment operator"<<endl;
                   return false;
               }
            }

        }
        else {
            cout<<"Error: Expected an identifier after the data type"<<endl;
            return false;
        }
    }
    else
    {
        cout<<"Error: Expected a valid data type"<<endl;
        return false;
    }

}
bool isKeyWord(string &s)
{
    if (s == "if" or s == "else" or s == "while" or s == "do"
        or s == "for" or s == "switch" or s == "case" or s == "class"
        or s == "auto" or s == "break" or s == "continue" or s == "char"
        or s == "string" or s == "int" or s == "float" or s == "double"
        or s == "long" or s == "default" or s == "goto" or s == "friend")
        return true;
    else return false;
}
bool isOp(string &s)
{
    if (s == "<" or s == ">" or s == "+" or
        s == "-" or s == "/" or s == "*" or
        s == "!=" or s == ">=" or s == "<="
        or s == "=")
            return true;
    else return false;
}
bool isPunc(string &s)
{
    if (s == ";" or s == "," or s == "(" or s == ")"
        or s == "{" or s == "}" or s == "[" or s == ";")
            return true;
    else return false;
}
bool isNum(string &s)
{
    if (isdigit(s[0])) return true;
    else return false;
}
vector<pair<string,string>>analyzeLexical(string &s)
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

bool analyzeSyntax(vector<pair<string,string>>&leximes)
{
    int pos = 0;
    return parseDecAssignment(leximes,pos);
}

int main()
{
    s = "in x = 4 ; ";

    // Performing Lexical Analysis
    vector<pair<string,string>>vec = analyzeLexical(s);
    for (auto it:vec)
    {
        cout<<it.first<<": "<<it.second<<endl;
    }

    // Performing Syntax Analysis
    if (analyzeSyntax(vec)) cout<<"Syntax Analysis Passed"<<endl;
    else cout<<"Syntax Analysis Failed"<<endl;
}
