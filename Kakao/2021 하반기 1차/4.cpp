// 2021 KAKAO BLIND RECRUITMENT 합승 택시 요금

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct compare
{
  bool operator()(pair<int, int> a, pair<int, int> b)
  {
    return a.second > b.second;
  }
};

vector<pair<int, int>> graph[201];
int fare[3][201];

int getMin(int a, int b) { return a < b ? a : b; }

void dijk(int arrIdx, int from)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

  for (int i = 1; i <= 200; i++)
  {
    fare[arrIdx][i] = INT_MAX;
  }

  fare[arrIdx][from] = 0;
  pq.push(make_pair(from, 0));

  while (!pq.empty())
  {
    int curNode = pq.top().first;
    int curFare = pq.top().second;
    pq.pop();

    if (fare[arrIdx][curNode] < curFare)
    {
      continue;
    }

    fare[arrIdx][curNode] = curFare;
    int len = graph[curNode].size();

    for (int i = 0; i < len; i++)
    {
      int nextNode = graph[curNode][i].first;
      int nextFare = graph[curNode][i].second + curFare;

      if (nextFare < fare[arrIdx][nextNode])
      {
        pq.push(make_pair(nextNode, nextFare));
      }
    }
  }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
  int min = INT_MAX;
  int len = fares.size();

  for (int i = 0; i < len; i++)
  {
    int from = fares[i][0];
    int to = fares[i][1];
    int fare = fares[i][2];

    graph[from].push_back(make_pair(to, fare));
    graph[to].push_back(make_pair(from, fare));
  }

  dijk(0, s);
  dijk(1, a);
  dijk(2, b);

  for (int i = 1; i <= n; i++)
  {
    long long curFare = fare[0][i] + fare[1][i] + fare[2][i];
    // cout << "i : " << i << ", curFare: " << curFare << endl;
    min = getMin(min, curFare);
  }

  return min;
}