#ifndef QUADFUNCSOLVEHASHTABLE_H
#define QUADFUNCSOLVEHASHTABLE_H

#include <QVector>
class QFSHT
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
    int alt_hash(int key,int i)
    {
        return (hash(key)+0*i+1*i*i)%mod;
    }
    QFSHT(int tableSize)
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
        int ind=hash(key),i=0;

        while(table[ind].first!=-1&&i<mod)
        {
            ind=alt_hash(key,i);
            i++;
        }
        if(i==mod)
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
        int ind=hash(key),i=0;

        while(table[ind].first!=-1&&i<mod)
        {
            ind=alt_hash(key,i);
            i++;
        }
        if(i==mod)
        {
            throw "Element was not found";
        }

        table[ind].first=-1;
    }
    int get(int key)
    {
        int ind=hash(key),i=0;

        while(table[ind].first!=key&&i<mod)
        {
            ind=alt_hash(key,i);
            i++;
        }
        if(i==mod)
        {
            return 0;
        }

        return table[ind].second;
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
};

#endif // QUADFUNCSOLVEHASHTABLE_H
