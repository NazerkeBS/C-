#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int longestheads(const string& seq)
{
    int cnt;
    int max=-1;
    for(unsigned int i=0; i<seq.size(); i++)
    {

        if(seq[i]=='H')
        {
            cnt=0;
            while(seq[i]=='H')
            {
                cnt++;
                i++;
            }
            if(max< cnt)
            {
                max=cnt;
            }
        }

    }
    return max;
}
int repeated2heads(const string& seq)
{
    int cnt;
    int total=0;
    for(unsigned int i=0; i<seq.size(); i++)
    {

        if(seq[i]=='H')
        {
            cnt=0;
            while(seq[i]=='H')
            {
                cnt++;
                i++;
            }
            if(cnt==2)
            {
                total++;
            }
        }

    }
    return total;
}

char randmChoice()
{
    srand(time(0));
    char r = (rand() % 2) ? 'T' : 'H';
    return r;
}

void randm1000()
{
    srand(time(0));
    int tailCnt=0;
    int headCnt=0;
    float ratio;

    for(int i=0; i<1000; i++)
    {
        char r = (rand() % 2) ? 'T' : 'H';
        cout<< r;
        if(r=='H')
        {
            headCnt++;
        }
        else
        {
            tailCnt++;
        }
    }
    cout<< endl;
    ratio=float(headCnt)/float(tailCnt);
    cout << "Heads: "<<headCnt << endl;
    cout << "Tails: " << tailCnt
         << endl;
    cout << "Ratio: " << ratio << endl;
}

int main()
{
    srand(time(0));

    char input;
    cout << "Guess, (T) or (H)" << endl;
    cin>>input;
    if(randmChoice() == input)
    {
        cout << "Your guess is correct!!!" << endl;
    }
    else
    {
        cout << "Comp choice: "<<randmChoice() << endl;
    }
    randm1000();
    cout << repeated2heads("THHHHTTHHTHHHTHH") <<endl;
    cout << longestheads("THHHHTTHHTHHHTHH") << endl;
    return 0;
}
