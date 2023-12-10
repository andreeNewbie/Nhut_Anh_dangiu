#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int convertFile60CharsperLine(char input[], char output[])
{
    ifstream fin(input);
    ofstream fout(output);

    string line, temp = "";
    int count = 0;

    while (getline(fin, line) || temp != "") 
    {
        line = temp + line;
        if (count + line.length() < 3)
        {
            fout << line;
            count += line.length();
        }
        else if(count + line.length() > 3)
        {
            fout << line.substr(0, (3 - count)) << endl;
            temp = line.substr(3 - count);
            if (temp.length() > 3)
            {
		count = 0;
                if (fin.eof()) 
                    line = "";
                continue;
            }
            else if (temp.length() == 3)
            {
                fout << temp << endl;
                count = 0;
                temp = "";
            }
            else 
            {
                fout << temp;
                count = temp.length();
                temp = "";
            }
        }
        else
        {
            fout << line << endl;
            count = 0;
        }
    }

    fin.close();
    fout.close();
}

int main()
{
  return 0;
}

