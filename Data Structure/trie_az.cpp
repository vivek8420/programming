
class Trie {
private:
	typedef struct trie_node {
		trie_node* ptr[26];
		bool flag = false;
	}trie;
	
	trie* root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new trie();
	}
	
	/** Inserts a word into the trie. */
	void insert(string word) {
		trie* cur = root;
		for(char &c:word){
			int id = c -'a';
			if(!cur->ptr[id])
				cur->ptr[id] = new trie();
			cur = cur->ptr[id];
		}
		cur->flag = true;
	}
	
	/** Returns if the word is in the trie. */
	bool search(string word) {
		trie* cur = root;
		for(char &c:word){
			int id = c - 'a';
			if(!cur->ptr[id])
				return false;
			cur = cur->ptr[id];
		}
		return cur->flag;
	}
	
	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string word) {
		trie* cur = root;
		for(char &c:word){
			int id = c - 'a';
			if(!cur->ptr[id])
				return false;
			cur = cur->ptr[id];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */