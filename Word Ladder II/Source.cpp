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


	void backfill(vector<vector<string>> &res, int head1, int head2)
	{
		vector<string> v;
		int p=head1;
		while(p!=-1) 
		{
			v.push_back(q1[p]);
			p=prev1[p];
		}
		reverse(v.begin(),v.end());
		p=head2;
		//if(v[v.size()-1]==q2[p])
		//	p=prev2[p]; 
		while(p!=-1)
		{
			v.push_back(q2[p]);
			p=prev2[p];
		}
		res.push_back(v);
	}

	vector<string> q1, q2;
	vector<int> prev1, prev2;	// for back-tracking
	//傻叉了，这个prev不能只是简单地记录int！而是要记录一个list，因为判重的原因，有些visited了就不添加进queue，但是其实在back-track的时候是一条可能的track通道
	//在判重的时候，实际是判断不能往前走，往后走的话，prev数组要相应增加
	//所以有了这个双层prev数组，此时才用dfs来back-fill所有可能的解

	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string>> res;

		int a=0;
		int len=start.length();
		unordered_map<string,int> visited1,visited2;	//here need to record the position in the queue
		q1.push_back(start);
		prev1.push_back(-1);
		visited1[start]=0;
		q2.push_back(end);
		prev2.push_back(-1);
		visited2[end]=0;
		int head1=0,tail1=0,head2=0,tail2=0,flag1=0,flag2=0;
		bool finished=false;
		//trick here. need to record tail position as flag, indicating one level of bfs
		//then step here is actually bfs levels
		while(1)
		{
			if(q1.size()<=q2.size() && head1<=tail1)	//expand the smaller queue, q1
			{
				//expand whole level
				while(head1<=flag1)
				{
					string tmp=q1[head1];
					if(tmp=="marry"||tmp=="merry")
						a=1;
					if(check(tmp,end))	
					{
						// got it. Stop at this level
						finished=true;
						// back track to fill result
						backfill(res,head1,visited2[end]);
					}
					for(string word:dict)
					{
						if(check(tmp,word))
						{
							if(visited2.find(word) != visited2.end())
							{
								finished=true;
								// back track to fill result
								backfill(res,head1,visited2[word]);
							}
							if(visited1.find(word)==visited1.end())
							{
								tail1++;
								visited1[word]=tail1;
								q1.push_back(word);
								prev1.push_back(head1);
							}
						}
					}
					head1++;
				}
				//big trick here!
				//if stop and finished. q1 stops, then q2 still need expand!!! cannot just break here. but can stop growth.
				//if not do next level, set flag
				if(finished) break;
				flag1=tail1;

			}
			else
			{   //expand q2
				if(head2<=tail2)
				{
					while(head2<=flag2)
					{
						string tmp=q2[head2];
						if(tmp=="marry"||tmp=="merry")
							a=1;

						if(check(tmp,start))	
						{
							// got it. Stop at this level
							finished=true;
							// back track to fill result
							backfill(res,visited1[start],head2);
						}
						for(string word:dict)
						{
							if(check(tmp,word))
							{
								if(visited1.find(word) != visited1.end())
								{
									finished=true;
									// back track to fill result
									backfill(res,visited1[word],head2);
								}
								if(visited2.find(word)==visited2.end())
								{
									tail2++;
									visited2[word]=tail2;
									q2.push_back(word);
									prev2.push_back(head2);
								}								
							}
						}	
						head2++;
					}
					if(finished) break;
					flag2=tail2;
				}
				else // cannot expand anymore
					break;
			}
		}
		//sort(res.begin(),res.end());
		//auto it=unique(res.begin(),res.end());
		//res.resize(distance(res.begin(),it));
		return res;
	}
};

int main()
{
	Solution *s = new Solution();
	unordered_set<string> dict;
	
	//string A[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	//string A[] = {"hot","dot","dog","lot","log"};
	//string A[] = {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
	string A[] = {"flail","halon","lexus","joint","pears","slabs","lorie","lapse","wroth","yalow","swear","cavil","piety","yogis","dhaka","laxer","tatum","provo","truss","tends","deana","dried","hutch","basho","flyby","miler","fries","floes","lingo","wider","scary","marks","perry","igloo","melts","lanny","satan","foamy","perks","denim","plugs","cloak","cyril","women","issue","rocky","marry","trash","merry","topic","hicks","dicky","prado","casio","lapel","diane","serer","paige","parry","elope","balds","dated","copra","earth","marty","slake","balms","daryl","loves","civet","sweat","daley","touch","maria","dacca","muggy","chore","felix","ogled","acids","terse","cults","darla","snubs","boats","recta","cohan","purse","joist","grosz","sheri","steam","manic","luisa","gluts","spits","boxer","abner","cooke","scowl","kenya","hasps","roger","edwin","black","terns","folks","demur","dingo","party","brian","numbs","forgo","gunny","waled","bucks","titan","ruffs","pizza","ravel","poole","suits","stoic","segre","white","lemur","belts","scums","parks","gusts","ozark","umped","heard","lorna","emile","orbit","onset","cruet","amiss","fumed","gelds","italy","rakes","loxed","kilts","mania","tombs","gaped","merge","molar","smith","tangs","misty","wefts","yawns","smile","scuff","width","paris","coded","sodom","shits","benny","pudgy","mayer","peary","curve","tulsa","ramos","thick","dogie","gourd","strop","ahmad","clove","tract","calyx","maris","wants","lipid","pearl","maybe","banjo","south","blend","diana","lanai","waged","shari","magic","duchy","decca","wried","maine","nutty","turns","satyr","holds","finks","twits","peaks","teems","peace","melon","czars","robby","tabby","shove","minty","marta","dregs","lacks","casts","aruba","stall","nurse","jewry","knuth"};
	for(auto str:A) dict.insert(str);
	//cout<<s->ladderLength("hit","cog",dict)<<endl;
	//cout<<s->ladderLength("cet","ism",dict)<<endl;
	//vector<vector<string>> res=s->findLadders("qa","sq",dict);
	//vector<vector<string>> res=s->findLadders("hit","hit",dict);
	//vector<vector<string>> res=s->findLadders("cet","ism",dict);
	vector<vector<string>> res=s->findLadders("magic","pearl",dict);
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