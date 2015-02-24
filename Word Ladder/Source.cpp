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
class Solution_old {
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


//2nd pass
class Solution_2nd {
public:
    inline bool checkWord(string s1, string s2)
    {
        int count=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i]) count++;
            if(count>1) return false;
        }
        if(count==1) return true; else return false;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        vector<string> queue_now,queue_next;
        unordered_set<string> table(dict);
        int level=1;
        queue_now.push_back(start);
        while(!queue_now.empty())
        {
            for(string now:queue_now)
            {
                if(checkWord(now,end)) return level+1;    

				string tmp;
				for(int i=0;i<now.length();i++)
					for(char c='a';c<='z';c++)
					{
						if(now[i]!=c)
						{
							tmp=now;
							tmp[i]=c;
							if(table.count(tmp) != 0)
							{
		    					queue_next.push_back(tmp);
								table.erase(tmp);
							}
						}
					}
            }
            queue_now=queue_next;
            queue_next.clear();
            level++;
        }
        return 0;
    }
};

//3rd pass: 2015-02-22
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string,int>> q;
        q.push(make_pair(start,1));
		while(!q.empty())
        {
            auto head=q.front();
            q.pop();
			if(head.first==end) return head.second;
			for(int i=0;i<head.first.length();i++)
                for(char c='a';c<='z';c++) if(c!=head.first[i])
                {
					string tmp=head.first; tmp[i]=c;
					if(tmp==end) return head.second+1;
					if(dict.count(tmp)!=0) { q.push(make_pair(tmp,head.second+1)); dict.erase(tmp);}
                }
        }
        return 0;
    }
};

int main()
{
	Solution *s = new Solution();
	unordered_set<string> dict;
	//string A[] = {"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
	//for(auto str:A) dict.insert(str);
	//cout<<s->ladderLength("nape","mild",dict)<<endl;

	//string A[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	//for(auto str:A) dict.insert(str);
	//cout<<s->ladderLength("qa","sq",dict)<<endl;


	//dict.insert("hot");
	//dict.insert("dot");
	//dict.insert("dog");
	//dict.insert("lot");
	//dict.insert("log");
	//cout<<s->ladderLength("hit","cog",dict)<<endl;
	//cout<<s->ladderLength("hit","zzz",dict)<<endl;
	//cout<<s->ladderLength("hit","hot",dict)<<endl;
	system("pause");
	return 0;
}