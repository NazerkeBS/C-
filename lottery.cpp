#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<int> userInput()
{
    int validcnt=0;
    int n;
    vector<int>vec;
    cout << "Enter 5 numbers in [1,90]" << endl;
    for(int i=0; i<5; i++)
    {
        cin>>n;
        if(n>0 && n<=90)
        {
            vec.push_back(n);
            validcnt++;
        }
    }
    if(validcnt!=5)
    {
        cout << "Invalid numbers" <<endl;
        exit(1);
    }
    else
    {
        for(int i=0; i<5; i++)
        {
            for(int j=i+1; j<5; j++)
            {
                if(vec[i] > vec[j])
                {
                    int temp= vec[i];
                    vec[i]=vec[j];
                    vec[j]=temp;
                }
            }
        }
    }
    return vec;
}

void printNumsAsc(const vector<int>& vec)
{
    cout << "Numbers in ascending order: ";
    for(int i=0; i<5; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

}

int matchCount(const vector<int>& vec1, const vector<int>& vec2)
{
    int cnt=0;
    for(unsigned int i=0; i<vec1.size(); i++)
    {
        for(unsigned int j=0; j<vec2.size(); j++)
        {
            if(vec1[i] == vec2[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ifstream file("lottery.txt");
    int nLines;
    int n1,n2,n3,n4,n5;
    vector<int> v;
    vector <int> vec2;
    file>>nLines;
    for(int i=0; i<nLines; i++)
    {
        file >> n1 >> n2 >> n3 >> n4 >> n5;
        v.push_back(n1);
        v.push_back(n2);
        v.push_back(n3);
        v.push_back(n4);
        v.push_back(n5);



        vec2.push_back(n1);
        vec2.push_back(n2);
        vec2.push_back(n3);
        vec2.push_back(n4);
        vec2.push_back(n5);


        vector<int> vecUsr=userInput();
        cout << "input: ";
        printNumsAsc(v);
        cout<< "User nums:";
        printNumsAsc(vecUsr);
        cout <<"matches: "<<matchCount(v, vecUsr) << endl;
        v.clear();
        vecUsr.clear();

    }
    file.close();

    sort(vec2.begin(), vec2.end());
    int max=0;
    int cnt=0;
    int repeated;
    for(unsigned int i=0; i<vec2.size()-1; i++)
    {
        if(vec2[i]==vec2[i+1])
        {
            cnt++;
            while(vec2[i]== vec2[i+1])
            {
                cnt++;
                i++;
            }
            if(max<cnt)
            {
                max=cnt;
                repeated=vec2[i];
            }
            cnt=0;

        }

    }

    cout << "The most frequent number with occurrences of "<< max  << " is "<< repeated << endl;

    return 0;
}


