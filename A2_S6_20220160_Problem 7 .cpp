// File: A2_S6_20220160_Problem 7 .cpp
// Purpose:that attempts to create a domino chain
// Author:seif eldin shady abdelsalam
// Section:S6
// ID:20220160
// TA:maya ahmed 
// Date: 5 Nov 2023
#include<iostream>
#include<vector>
using namespace std;

struct dominoT {
    int leftDots = 0;
    int rightDots = 0;
    void setleftdots(int l)
    {
        leftDots = l;
    }
    void setrightdots(int r)
    {
        rightDots = r;
    }
    int getleft()
    {
        return leftDots;
    }
    int getwright()
    {
        return rightDots;
    }

};
bool FormsDominoChain(vector<dominoT>& dominos);
void printdomia(vector<dominoT>& dominos);
int main()
{
    vector<dominoT>v;
    int n; cout << "Enter the number of dominos : "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "Enter left dots of the " << (i + 1) << " : "; cin >> x;
        cout << "Enter right dots of the " << (i + 1) << " : "; cin >> y;
        dominoT f;
        f.setleftdots(x);
        f.setrightdots(y);
        bool t = true;
        for (auto k : v)
        {
            if ((k.getleft() == f.getleft() && k.getwright() == f.getwright())
                || (k.getleft() == f.getwright() && k.getwright() == f.getleft())
                || x>6 || y >6 || x<0 || y<0)
                t = false;
        }
        if (t) v.push_back(f);
        else {
            cout << "Invalid !!!\n";

            break;
        }

    }
    if (FormsDominoChain(v)) {
        cout << "True" << endl;
        printdomia(v);
    }
    else cout << "False";




    return 0;
}

bool FormsDominoChain(vector<dominoT>& dominos)
{
    vector<dominoT>dominos2(dominos.size());
    for (int i = 0; i < dominos2.size(); i++)
    {
        dominos2[i] = dominos[i];
    }
    bool t = false;
    for (int i = 0; i < dominos2.size() - 1; i++)
    {
        t = false;
        for (int j = 0; j < dominos2.size(); j++)
        {
            if ((dominos2[i].getwright() == dominos2[j].getleft() && i != j))
            {
                t = true;
                dominos2[i].setrightdots(7);
                dominos2[j].setleftdots(7);
                break;
            }
            else t = false;
        }
    }
    if (t) return true;
    else return false;

}
void printdomia(vector<dominoT>& dominos)
{
    int size = dominos.size();
    vector<dominoT> dominos2(dominos);
    vector<dominoT> dominos3;
    vector<dominoT> ans;

    for (int i = 0; i < size; i++)
    {
        bool t = true;
        for (int j = 0; j < size; j++)
        {
            if ((dominos2[i].leftDots == dominos2[j].leftDots || dominos2[i].leftDots == dominos2[j].rightDots) && i != j)
            {
                t = false;
            }
        }
        if (t == true)
        {
            swap(dominos2[0], dominos2[i]);
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        bool t = true;
        for (int j = 0; j < size; j++)
        {
            if ((dominos2[i].rightDots == dominos2[j].leftDots || dominos2[i].rightDots == dominos2[j].rightDots) && i != j)
            {
                t = false;
            }
        }
        if (t == true)
        {
            swap(dominos2[size - 1], dominos2[i]);
            break;
        }
    }
    ans.push_back(dominos2[0]);
    for (int i = 0; i < size; i++)
    {
        bool t = false;
        dominos3.push_back(dominos2[i]);
        for (int j = i; j < size; j++)
        {
            if ((dominos3[0].rightDots == dominos2[j].leftDots || dominos3[0].rightDots == dominos2[j].leftDots) && i != j)
            {
                t = true;
                ans.push_back(dominos2[j]);
                if(i+1 <= size) swap(dominos2[i+1], dominos2[j]);
                break;
            }
            else if (dominos3[0].rightDots == dominos2[j].leftDots && i != j)
            {
                t = true;
                ans.push_back(dominos2[j]);
                if (i + 1 <= size) swap(dominos2[i+1], dominos2[j]);
                break;
            }
        }
        dominos3.pop_back();

    }


    for (int i = 0; i < size; i++)
    {
        cout << ans[i].getleft() << " | " << ans[i].getwright();
        if (i != size - 1) cout << " - ";
    }
}
