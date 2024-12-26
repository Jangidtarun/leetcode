#include <bits/stdc++.h>
using namespace std;

string interpret(string command)
{
    set<string> hulle = {"G", "()", "(al)"};
    for (int i = 0; i < command.length(); i++)
    {
        string sub1 = command.substr(i, 1);
        string sub2 = command.substr(i, 2);
        string sub3 = command.substr(i, 4);
        if (hulle.find(sub1) != hulle.end())
            command.replace(i, 1, "G");
        else if (hulle.find(sub2) != hulle.end())
            command.replace(i, 2, "o");
        else if (hulle.find(sub3) != hulle.end())
        {
            command.replace(i, 4, "al");
            i++;
        }
    }
    return command;
}

int main()
{
    string cmd = "()G(al)";
    cmd = interpret(cmd);
    cout << "string: " << cmd << endl;
}