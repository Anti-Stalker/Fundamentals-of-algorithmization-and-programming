#ifndef LINESOLVEHASHTABLE_H
#define LINESOLVEHASHTABLE_H

#include <QVector>
class LSHT
{
private:
    int mod=3;
    QVector<std::pair<long long ,long long>>table;//1 - real key; 2 - value

    bool prime(int x)
    {
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
                return false;
        }
        return true;
    }
    void updMod()
    {
    do{
        mod++;
    }while(!prime(mod));
    }
public:
    int hash(int key)
    {
        return key%mod;
    }
    LSHT(int tableSize)
    {
        mod=tableSize;
        updMod();
        table.resize(mod);
        for(int i=0;i<mod;i++)
        {
            table[i]={-1,0};
        }
    }
    void insert(int key,int data)
    {
        int ind=hash(key),i=ind-1;

        while(table[ind].first!=-1&&ind!=i)
        {
            ind=(ind+1)%mod;
        }
        if(table[ind].first!=-1)
        {
            mod++;
            updMod();
            table.resize(mod);
            insert(key,data);
        }

        table[ind]={key,data};
    }
    void remove(int key)
    {
        int ind=hash(key),i=ind-1;

        while(table[ind].first!=key&&i!=ind)
        {
            ind=(ind+1)%mod;
        }
        if(table[ind].first!=-1)
        {
            return;
            //return;
        }
        table[ind]={-1,0};
    }
    int size()
    {
        return mod;
    }
    void clear()
    {
        for(int i=0;i<mod;i++)
        {
            table[i]={-1,0};
        }
    }
    QVector<std::pair<long long, long long> > getTable() const
    {
        return table;
    }
    int get(int key)
    {
        int ind=hash(key),i=ind-1;

        while(table[ind].first!=key&&i!=ind)
        {
            ind=(ind+1)%mod;
        }
        if(table[ind].first!=key)
        {
            //throw "Element not found";
            //throw "Element was not found";
            return -1;
        }
        return table[ind].second;
    }
};

#endif // LINESOLVEHASHTABLE_H
