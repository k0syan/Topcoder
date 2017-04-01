#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Player {
  int skill;
  int victories = 0;
};

class PingPongQueue {
  public:
    vector <int> whoPlaysNext(vector <int> skills, int N, int K) {
      deque<Player> q;
      for (int i = 0; i < skills.size(); ++i) {
        Player p;
        p.skill = skills[i];
        q.push_back(p);
      }
      
      if (q.size() == 2) {
        if (q[0].skill > q[1].skill) {
          return {q[1].skill, q[0].skill};
        } else {
          return {q[0].skill, q[1].skill};
        }
      }
      
      Player first;
      Player second;
      
      for (int i = 0; i < K; ++i) {
        first = q[0];
        q.pop_front();
        second = q[0];
        q.pop_front();
        
        if (first.skill > second.skill) {
          // first is the winner
          
          // reset victories
          second.victories = 0;
          q.push_back(second);
          ++first.victories;
          
          if (first.victories == N) {
            // reset victories
            first.victories = 0;
            q.push_back(first);
          } else {
            q.push_front(first);
          }
        } else {
          // second is the winner
          
          // reset victories
          first.victories = 0;
          q.push_back(first);
          ++second.victories;
          
          if (second.victories == N) {
            // reset victories
            second.victories = 0;
            q.push_back(second);
          } else {
            q.push_front(second);
          }
        }
      }
      
      if (first.skill > second.skill) {
        return {second.skill, first.skill};
      } else {
        return {first.skill, second.skill};
      }
    }
};

int main() {
  PingPongQueue ppq;
  vector<int> answer = ppq.whoPlaysNext({30, 12}, 34, 80);
  for (int i = 0; i < answer.size(); ++i) {
    cout << answer[i] << " ";
  }
  cout << "\n";

  return 0;
}
