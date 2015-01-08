// Word Ladder II
//   Author: flashhack
//   Update: 2015-01-08
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

	unordered_set<string> visited;
	unordered_set<string> visited_now;
	unordered_set<string> Dict;
	vector<vector<string>> res;
	string now;
	int len_target;
	int len_word;
	string target;

	bool check(string a, string b) // check whether two strings can be transformed within one step
	{
		int cnt=0;
		for(int i=0;i<a.length();i++) 
		{
			if(a[i]!=b[i]) cnt++;
			if(cnt>1) return false;
		}
		return true;
	}

	void dfs(string &now)
	{
		visited.insert(now);
		
		int len = now.length();
		string word_now=now.substr(len-len_word);
		visited_now.insert(word_now);
		if(len==len_target*len_word)
		{
			vector<string> v;
			int i=0;
			while(i<len)
			{
				v.push_back(now.substr(i,len_word));
				i+=len_word;
			}
			res.push_back(v);
			return;
		}
		string tmp=word_now;
		if(len==(len_target-1)*len_word)	//last step must check target, wich could possibly out of dict. And no need to check dict
		{
			if(check(tmp,target))
			{
				now+=target;
				if(visited.find(now)==visited.end()) dfs(now);
				now=now.substr(0,now.length()-len_word);
				visited_now.erase(target);							
			}
		}
		else
		{
			for(string word:Dict)
			{
				if(check(tmp,word) && visited_now.find(word)==visited_now.end())
				{
					now+=word;
					if(visited.find(now)==visited.end()) dfs(now);
					now=now.substr(0,now.length()-len_word);
					visited_now.erase(word);					
				}
			}
		}
	}

	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		now=start;
		target = end;
		Dict=dict;
		len_target = ladderLength(start,end,dict);
		len_word = start.length();
		dfs(now);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();
	unordered_set<string> dict;
	
	//string A[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	//string A[] = {"hot","dot","dog","lot","log"};
	string A[] = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
	for(auto str:A) dict.insert(str);
	//cout<<s->ladderLength("hit","cog",dict)<<endl;
	//cout<<s->ladderLength("cet","ism",dict)<<endl;
	//vector<vector<string>> res=s->findLadders("qa","sq",dict);
	//vector<vector<string>> res=s->findLadders("hit","cog",dict);
	vector<vector<string>> res=s->findLadders("cet","ism",dict);
	for(auto it:res)
	{
		for(auto it2:it) cout<<it2<<",";
		cout<<endl;
	}
	//cout<<s->ladderLength("hit","zzz",dict)<<endl;
	//cout<<s->ladderLength("hit","hot",dict)<<endl;
	//cout<<s->ladderLength("qa","sq",dict)<<endl;
	system("pause");
	return 0;
}