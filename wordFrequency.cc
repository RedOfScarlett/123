#include <funcc.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::map;
using std::vector;
class WordFrequency
{
public:
    WordFrequency();
    ~WordFrequency();
    void statistic(char *FILENAME);
    void print();
private:
    map<string,int> _word_cnt;//map在栈空间
};

WordFrequency::WordFrequency()
{};

WordFrequency::~WordFrequency()
{
    cout<<"~wordFrequency()"<<endl;
}

void WordFrequency::statistic(char *FILENAME)
{
    ifstream file;
    file.open(FILENAME);
    string word;
    while(file>>word)
    {
        while(1)
        {
            auto be=word.begin();
            if((*be<='/'&&*be>='!')||(*be>='['&&*be<='_')||(*be<='~'&&*be>='{')||(*be<='?'&&*be>=':'))
            {
                word.erase(be);
            }
            else 
                break;
        }
        while(1)
        {
            auto end=word.end()-1;//不能用rbegin()，erase()方法不支持尾后迭代器，个人理解erase()方法后迭代器会指向被删除的后一个元素，而rbegin()不能指向尾后
            if((*end<='/'&&*end>='!')||(*end>='['&&*end<='_')||(*end<='~'&&*end>='{')||(*end<='?'&&*end>=':'))
            {
                word.erase(end);
            }
            else 
                break;
        }
        ++_word_cnt.insert({word,1}).first->second;//C++ primer 练习11.21
    }
}

void WordFrequency::print()
{
    for(const auto &w:_word_cnt)
    {
        cout<<w.first<<" "<<w.second<<endl;
    }
}

int main(int argc ,char *argv[])
{
    ARGS_CHECK(argc,2);
    WordFrequency WF;
    WF.statistic(argv[1]);
    WF.print();
    return 0;
}

