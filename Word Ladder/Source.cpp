// Word Ladder 
//   Author: flashhack
//   Update: 2015-01-07
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

//bi-direction bfs. only 75ms pass
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		if(start==end) return 1;
		int len=start.length();
		unordered_set<string> visited1,visited2;
		vector<string> q1, q2;
		q1.push_back(start);
		visited1.insert(start);
		q2.push_back(end);
		visited2.insert(end);
		int head1=0,tail1=0,head2=0,tail2=0,step1=1,step2=1,flag1=0,flag2=0;
		//trick here. need to record tail position as flag, indicating one level of bfs
		//then step here is actually bfs levels
		while(1)
		{
			if(q1.size()<=q2.size() && head1<=tail1)	//expand the smaller queue, q1
			{
				//expand whole level
				while(head1<=flag1)
				{
					string tmp="";
					for(int i=0;i<len;i++)
					{
						for(int j=0;j<26;j++)
						{
							if(q1[head1][i]!=('a'+j))
							{
								tmp=q1[head1];
								tmp[i]=('a'+j);
								if(visited2.find(tmp)!=visited2.end()) // got it!
								{
									return step1+step2;
								}
								else
								{
									if(dict.find(tmp)!=dict.end() && visited1.find(tmp)==visited1.end())
									{
										visited1.insert(tmp);
										q1.push_back(tmp);
										tail1++;
									}
								}
							}
						}
					}				
					head1++;
				}
				//next level flag
				flag1=tail1;
				step1++;
			}
			else
			{   //expand q2
				if(head2<=tail2)
				{
					while(head2<=flag2)
					{
						string tmp="";
						for(int i=0;i<len;i++)
						{
							for(int j=0;j<26;j++)
							{
								if(q2[head2][i]!=('a'+j))
								{
									tmp=q2[head2];
									tmp[i]=('a'+j);
									if(visited1.find(tmp)!=visited1.end()) // got it!
									{
										return step1+step2;
									}
									else
									{
										if(dict.find(tmp)!=dict.end() && visited2.find(tmp)==visited2.end())
										{
											visited2.insert(tmp);
											q2.push_back(tmp);
											tail2++;
										}
									}
								}
							}
						}					
						head2++;
					}
					flag2=tail2;
					step2++;
				}
				else // cannot expand anymore
					break;
			}
		}
		return 0;
    }
};

int main()
{
	Solution *s = new Solution();
	unordered_set<string> dict;
	string A[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	for(auto str:A) dict.insert(str);
	//dict.insert("hot");
	//dict.insert("dot");
	//dict.insert("dog");
	//dict.insert("lot");
	//dict.insert("log");
	//cout<<s->ladderLength("hit","cog",dict)<<endl;
	//cout<<s->ladderLength("hit","zzz",dict)<<endl;
	//cout<<s->ladderLength("hit","hot",dict)<<endl;
	cout<<s->ladderLength("qa","sq",dict)<<endl;
	system("pause");
	return 0;
}