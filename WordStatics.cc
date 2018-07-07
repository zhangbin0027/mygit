#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;

struct Record
{
	string word;
	int cnt;
};
class WordStatics
{
public:
	void readFile(const string & filename)
	{
		ifstream ifs(filename.c_str());
		if(!ifs.good())
		{
			cout<<"ifstream open error!"<<endl;
			return;
		}
		string line;
		while(getline(ifs,line))
		{
			string word;
			istringstream iss(line);
			while(iss>>word)
			{
				vector<Record>::iterator it;
				for(it=_dict.begin();it != _dict.end();++it)
				{
					if(it->word==word)
					{
						++(it->cnt);
						break;	
					}
				}
				if(it == _dict.end())
				{
					Record record;
					record.word=word;
					record.cnt=1;
					_dict.push_back(record);
				}
			}
		}
		ifs.close();
	}
	void writeFile(const string &filename)
	{
		ofstream ofs(filename.c_str());
		if(!ofs.good())
		{
			cout<<"ofstream open error!"<<endl;
			return;
		}
		for(auto & elem: _dict)
		{
			ofs<<elem.word<<" "<<elem.cnt<<endl;
		}
		ofs.close();
	}
private:
		vector<Record> _dict;
};
int main(void)
{
	WordStatics ws;
	ws.readFile("The_Holy_Bible.txt");
	ws.writeFile("dict.txt");
	return 0;
}
