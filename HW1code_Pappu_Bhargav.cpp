#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

template<typename K, typename V>
void print_map(unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

bool cmpSingle(pair<char, int> &a, pair<char, int> &b)
{
    return a.second < b.second;
}

void sortSingleMap(unordered_map<char, int>& m)
{
    vector<pair<char, int> > a(m.begin(), m.end());
    sort(a.begin(), a.end(), cmpSingle);
    m.clear();
    for(auto& pair : a)
        m[pair.first] = pair.second;
}

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}

void sortMap(unordered_map<string, int>& m)
{
    vector<pair<string, int> > a(m.begin(), m.end());
    sort(a.begin(), a.end(), cmp);
    m.clear();
    for(auto& pair : a)
        m[pair.first] = pair.second;
}



void singleLetter(string filename)
{
    ifstream fp;
    fp.open(filename);
    unordered_map<char, int> m;
    string curLine;
    string s;
    while(!fp.eof())
    {
       getline(fp, curLine);
       s += curLine;
    }
    for(char c : s)
    {
        if(m.find(c) == m.end() && (c >= 97 && c <= 122))
            m[c] = 1;
        else if(m.find(c) != m.end())
            m[c]++;
    }
    sortSingleMap(m);
    print_map(m);
    cout << "\n- End of Single Letter Frequencies -\n\n";
    fp.close();
}

void bigram(string filename)
{
    ifstream fp;
    fp.open(filename);
    unordered_map<string, int> m;
    string temp;
    while(!fp.eof())
    {
        fp >> temp;
        string k;
        if(temp.size() == 2)
        {
            if(m.find(temp) == m.end())
                m[temp] = 1;
            else
                m[temp]++;
            continue;
        }
        for(int i = 0; i <= temp.size() - 1; i++)
        {
            if(k.size() == 2)
                k.erase(0, 1);
            k.push_back(temp[i]);
            if(k.size() == 2 && m.find(k) == m.end())
                m[k] = 1;
            else if(k.size() == 2 && m.find(k) != m.end())
                m[k]++;
        }
    }
    sortMap(m);
    print_map(m);
    cout << "\n- End of Bigram Frequencies -\n\n";
    fp.close();

}

void trigram(string filename)
{
    ifstream fp;
    fp.open(filename);
    unordered_map<string, int> m;
    string temp;
    while(!fp.eof())
    {
        fp >> temp;
        string k;
        if(temp.size() == 3)
        {
            if(m.find(temp) == m.end())
                m[temp] = 1;
            else
                m[temp]++;
            continue;
        }
        for(int i = 0; i <= temp.size() - 1; i++)
        {
            if(k.size() == 3)
                k.erase(0, 1);
            k.push_back(temp[i]);
            if(k.size() == 3 && m.find(k) == m.end())
                m[k] = 1;
            else if(k.size() == 3 && m.find(k) != m.end())
                m[k]++;
        }
    }
    sortMap(m);
    print_map(m);
    cout << "\n- End of Trigram Frequencies -\n\n";
    fp.close();
}

int main(int argc, char *argv[])
{
    string filename = argv[1];
    singleLetter(filename);
    bigram(filename);
    trigram(filename);
    return 1;
}