#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Post {
  int tweetId;
  int tweetIdx;
  int userId;
  int postIdx;

  Post(int tweetId, int tweetIdx, int userId, int postIdx)
      : tweetId(tweetId), tweetIdx(tweetIdx), userId(userId), postIdx(postIdx) {
  }
};

class Compare {
public:
  bool operator()(Post a, Post b) { return a.tweetIdx < b.tweetIdx; }
};

class Twitter {
private:
  unordered_map<int, unordered_set<int>> followMapping;
  unordered_map<int, vector<Post>> posts;
  int postCount;

public:
  Twitter() { postCount = 0; }

  void postTweet(int userId, int tweetId) {
    Post post = Post(tweetId, postCount++, userId, posts[userId].size());
    posts[userId].push_back(post);
  }

  vector<int> getNewsFeed(int userId) {
    vector<int> feed;

    priority_queue<Post, vector<Post>, Compare> pq;
    unordered_set<int> followList = followMapping[userId];

    if (!posts[userId].empty()) {
      pq.push(posts[userId].back());
    }

    for (auto f : followList) {
      if (!posts[f].empty()) {
        pq.push(posts[f].back());
      }
    }

    while (feed.size() < 10 && !pq.empty()) {
      Post p = pq.top();
      feed.push_back(p.tweetId);
      pq.pop();

      if (p.postIdx > 0) {
        pq.push(posts[p.userId][p.postIdx - 1]);
      }
    }

    return feed;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    followMapping[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    followMapping[followerId].erase(followeeId);
  }
};

int main() {
  vector<string> input = {"Twitter",  "postTweet",  "getNewsFeed",
                          "follow",   "postTweet",  "getNewsFeed",
                          "unfollow", "getNewsFeed"};
  vector<vector<int>> params = {{},     {1, 5}, {1},    {1, 2},
                                {2, 6}, {1},    {1, 2}, {1}};
  Twitter twitter;
  for (int i = 0; i < input.size(); i++) {
    string op = input[i];
    vector<int> param = params[i];

    if (op == "Twitter") {
      twitter = Twitter();
    } else if (op == "postTweet") {
      twitter.postTweet(param[0], param[1]);
    } else if (op == "getNewsFeed") {
      vector<int> feed = twitter.getNewsFeed(param[0]);
      for (int f : feed) {
        printf("%d ", f);
      }
      puts("");
    } else if (op == "follow") {
      twitter.follow(param[0], param[1]);
    } else if (op == "unfollow") {
      twitter.unfollow(param[0], param[1]);
    }
  }
}
