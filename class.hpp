#include <iostream>
#include <cstring>
#include <math.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
#include <iterator>
#include<omp.h>
using namespace std;

int gcd(int a, int b) ;
class CFabricRat;   //uiyueeuyeurueryueyr
class CRat
{
public:
    string Name;
    vector<int> numerator;
    vector<int> denominator;
    int len;
    CRat() { SetZero(); }
    CRat(int len){this->len = len; }
    virtual ~CRat() { Clean(); }
    void SetZero() { len = 0; }
  /*  void CopyOnly(const CRat& b) { len = b.len;
	#pragma omp parallel for 
	for(int i=0;i<len;i++){numerator.push_back(b.numerator[i]);denominator.push_back(b.denominator[i]);} }*/

    void InPut(int a,int b){numerator.push_back(a); denominator.push_back(b); len = len + 1;}   
    void SetLen(int len){this->len=len;}
    virtual void Clean() { SetZero(); } 
 //   CRat(const CRat& b) { CopyOnly(b); }
 //   CRat& operator = (const CRat& b) { if (this != &b) { Clean(); CopyOnly(b); } return *this; }
   /* virtual*/ void Output(){cout<<"";}
    CRat operator +(const CRat& b);
    CRat operator-(const CRat& b);
    double operator*(const CRat& b);
	void SetName(string& name){Name=name;}
    void reduction();
    static void Input(string& filename, vector<CRat*> &rat,vector<CFabricRat*> &fab);
    friend ostream& operator <<(ostream& cout, const CRat& b);
    virtual void Output(string& filename);


	 CRat operator &(const CRat& b);
    CRat operator/(const CRat& b);
    double operator%(const CRat& b);
	void reduction1();

//	virtual ~CRat(){}
   };

class CRat1:public CRat{
public:
    CRat1() :CRat() {}
    CRat1(int len) :CRat(len) {}
    void Output(string &filename);
	~CRat1(){}
};
class CRat2:public CRat{
public:
    CRat2():CRat() {}
    CRat2(int len):CRat(len) {}
    void Output(string &filename);
	void Output(){Output(Name);}
	~CRat2(){}
};

class CFabricRat
{
public:
    virtual CRat* Create() = 0;
    virtual ~CFabricRat(){}; 

};

class CFabricRat1 :public CFabricRat
{
public:
    virtual CRat* Create() { return new CRat1; }
    ~CFabricRat1(){}
};

class CFabricRat2 :public CFabricRat
{
public:
    virtual CRat* Create() { return new CRat2; }
    ~CFabricRat2(){}
};

