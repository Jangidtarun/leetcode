#include <bits/stdc++.h>
using namespace std;

// vector<string> fullJustify(vector<string> &words, int maxWidth)
// {
//     vector<string> res;
//     int n = words.size();
//     int i = 0;
//     while (i < n)
//     {
//         int j = i + 1;
//         int c = words[i].size();
//         int wc = words[i].size();
//         while (j < n && c + words[j].size() + 1 <= maxWidth)
//         {
//             c += words[j].size() + 1;
//             wc += words[j].length();
//             j++;
//         }
//         if (j == n || (j - i) == 1)
//         {
//             string s = "";
//             for (int p = i; p < j; p++)
//             {
//                 s += words[p];
//                 if (p != j - 1)
//                     s += ' ';
//             }
//             int ts = maxWidth - s.size();
//             for (int k = 0; k < ts; k++)
//             {
//                 s += ' ';
//             }
//             res.push_back(s);
//             i = j - 1;
//         }
//         else
//         {
//             int tw = j - i;
//             int ts = maxWidth - wc;
//             int es = ts / (tw - 1);
//             int extra = ts % (tw - 1);
//             string s = "";
//             for (int p = i; p < j; p++)
//             {
//                 s += words[p];
//                 if (extra > 0)
//                 {
//                     s += ' ';
//                     extra--;
//                 }
//                 if (p != j - 1)
//                 {
//                     for (int k = 0; k < es; k++)
//                     {
//                         s += ' ';
//                     }
//                 }
//             }
//             res.push_back(s);
//             i = j - 1;
//         }
//         i++;
//     }
//     return res;
// }

// vector<string> fullJustify(vector<string> &words, int maxWidth)
// {
// }

int main()
{
    vector<string> v = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxw = 20;

    // vector<string> ans = fullJustify(v, maxw);

    int totalchar = 0;
    for (auto &word : v)
        totalchar += word.length();
    // cout << word.length() << endl;

    cout << totalchar / maxw << endl;
}