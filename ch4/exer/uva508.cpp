/*
** use map to save morse dictionary
** use vector to save context and compare result
*/

# include <cstdio>
# include <map>
# include <vector>
# include <cstring>
# include <algorithm>
using namespace std;

# define MAXN 100
char key_buf[MAXN], value_buf[MAXN];

struct Context_Type {
	char word[MAXN], code[MAXN];
	int len;
};

struct Perfect_match{
	char word[MAXN];
	int len;
	bool operator < (const Perfect_match& b) const {
		return len < b.len;
	}
};

struct Prefix_match {
	char word[MAXN];
	int prefix;
	bool operator < (const Prefix_match& b) const{
		return prefix < b.prefix;
	}
};

struct Suffix_match {
	char word[MAXN];
	int suffix;
	bool operator < (const Suffix_match& b) const{
		return suffix < b.suffix;
	}
};



map <char, char[MAXN]> morse;
vector <Context_Type> context;
vector <Perfect_match> perfect;
vector <Prefix_match> prefix;
vector <Suffix_match> suffix;

int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	morse.clear();
	context.resize(0);
	while (scanf("%s", key_buf) && key_buf[0] != '*'){
		scanf("%s", value_buf);
		strcpy(morse[key_buf[0]], value_buf);
	}

	while(scanf("%s", key_buf) && key_buf[0] != '*') {
		Context_Type c;
		strcpy(c.word, key_buf);
		c.code[0] = '\0';
		for (int i = 0; i < strlen(c.word); i++)
			strcat(c.code, morse[c.word[i]]);
		c.len = strlen(c.code);
		context.push_back(c);
	}

	while(scanf("%s", key_buf) && key_buf[0] != '*'){
		perfect.resize(0);
		prefix.resize(0);
		suffix.resize(0);
		int length = strlen(key_buf);
		for (int i = 0; i < context.size(); i++) {
			if(context[i].len == length) {
				if (strcmp(key_buf, context[i].code) == 0) {
					Perfect_match p;
					strcpy(p.word, context[i].word);
					p.len = strlen(p.word);
					perfect.push_back(p);
				}
			}
			else if (context[i].len < length) {
				int ok = 1;
				for (int j = 0; j < context[i].len; j++) {
					if (context[i].code[j] != key_buf[j]) {
						ok = 0;
						break;
					}
				}
				if (ok) {
					Prefix_match px;
					strcpy(px.word, context[i].word);
					px.prefix = length - context[i].len;
					prefix.push_back(px);
				}
			}
			else if (context[i].len > length) {
				int ok = 1;
				for (int j = 0; j < length; j++) {
					if (context[i].code[j] != key_buf[j]) {
						ok = 0;
						break;
					}
				}
				if (ok) {
					Suffix_match sx;
					strcpy(sx.word, context[i].word);
					sx.suffix = context[i].len - length;
					suffix.push_back(sx);
				}
			}
		}
		// printf("%d %d %d\n", perfect.size(), prefix.size(), suffix.size());
		if (perfect.size() == 1)
			printf("%s\n", perfect[0].word);
		else if (perfect.size() > 1) {
			// sort(perfect.begin(), perfect.end());
			printf("%s!\n", perfect[0].word);
		}
		else {
			if (prefix.size() == 0){
				sort(suffix.begin(), suffix.end());
				printf("%s?\n", suffix[0].word);
			}
			else if (suffix.size() == 0) {
				sort(prefix.begin(), prefix.end());
				printf("%s?\n", prefix[0].word);
			}
			else {
				sort(prefix.begin(), prefix.end());
				sort(suffix.begin(), suffix.end());
				if (prefix[0].prefix < suffix[0].suffix)
					printf("%s?\n", prefix[0].word);
				else
					printf("%s?\n", suffix[0].word);
			}
		}
	}
	return 0;
}