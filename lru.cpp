#include<iostream>
#include<stdlib.h>
#include<unordered_map>
#include<deque>

#define QSIZE 4

using namespace std;

void printQueue(deque<int> q)
{
  while(!q.empty())
    {
      cout<<q.front()<<" ";
      q.pop_front();
    }
}

void Enqueue (deque<int>& q, unordered_map<int, deque<int>::iterator>& hash, int pageNumber)
{
  if(q.size() == QSIZE)
    {
      hash.erase(q.back());
      q.pop_back();
    }

  q.push_front(pageNumber);
  hash.insert(make_pair(pageNumber, q.begin()));
}

void ReferencePage(deque<int>& q, unordered_map<int, deque<int>::iterator>& hash, int pageNumber)
{
  if(hash.count(pageNumber) == 0)
    {
      Enqueue(q, hash, pageNumber);
    }
  else
    {
      deque<int>::iterator it = hash.at(pageNumber);
      if(it != q.begin())
	{
	  q.erase(it);
	  q.push_front(pageNumber);
	  hash.at(pageNumber) = q.begin();
	}
    }
}

int main()
{
  deque<int> q;

  unordered_map < int, deque<int>::iterator > hash;

  ReferencePage(q, hash, 1);
  ReferencePage(q, hash, 2);
  ReferencePage(q, hash, 3);
  ReferencePage(q, hash, 1);
  ReferencePage(q, hash, 4);
  ReferencePage(q, hash, 5);

  printQueue(q);

  return 0;
}
